### FILE="Main.annotation"
## Copyright:	Public domain.
## Filename:	TVCDAPS.agc
## Purpose:	A section of Comanche revision 072.
##		It is part of the reconstructed source code for the first
##		release of the software for the Command Module's (CM) Apollo
##		Guidance Computer (AGC) for Apollo 13. No original listings
##		of this program are available; instead, this file was recreated
##		from a printout of Comanche 055, binary dumps of a set of
##		Comanche 067 rope modules, and changelogs between Comanche 067
##		and 072. It has been adapted such that the resulting bugger words
##		exactly match those specified for Comanche 072 in NASA drawing
##		2021153G, which gives relatively high confidence that the
##		reconstruction is correct.
## Assembler:	yaYUL
## Contact:	Ron Burkey <info@sandroid.org>.
## Website:	www.ibiblio.org/apollo/index.html
## Mod history:	2024-05-13 MAS	Created from Comanche 067.
##		2024-05-14 MAS	Implemented ACB-97, "Delete redundant line
##				inadvertently inserted in implementation of
##				PCR 810".

# PROGRAM NAME....TVCDAP, CONSISTING OF PITCHDAP, YAWDAP, ETC.
# LOG SECTION...TVCDAPS			SUBROUTINE...DAPCSM
# MODIFIED BY SCHLUNDT				21 OCTOBER 1968
#
# FUNCTIONAL DESCRIPTION....
#
#	SELF-PERPETUATING T5 TASKS WHICH GENERATE THE COMMAND SIGNALS
#	FOR THE PITCH AND YAW SPS GIMBAL ACTUATORS DURING TVC (SPS) BURNS,
#	IN RESPONSE TO BODY-AXIS RATE COMMANDS FROM CROSS-PRODUCT STEERING
#	(S40.8).  IF NO STEERING (IMPULSIVE BURNS) MAINTAINS ATTITUDE-HOLD
#	ABOUT THE REFERENCE (INITIAL) DIRECTIONS (ZERO RATE COMMANDS).
#
#	THE PITCH AND YAW LOOPS ARE SEPARATE, BUT STRUCTURED IDENTICALLY.
#	EACH ATTITUDE-RATE LOOP INCLUDES GIMBAL ANGLE RATE DERIVATION,
#	GIMBAL/BODY AXIS TRANSFORMATION, BODY-AXIS ATTITUDE ERROR
#	INTEGRATION WITH ERROR LIMITING, THE GENERALIZED 6TH-ORDER FILTER
#	FOR CSM OR CSM/LM OPERATION, A FILTER OUTPUT LIMITER,
#	CG-OFFSET TRACKER FILTER, AND THE CG-TRACKER MINOR LOOP.
#
#	THE DAPS ARE CYCLIC, CALLING EACH OTHER AT 1/2 THE DAP SAMPLE
#	TIME, AS DETERMINED BY T5TVCDT.  THE ACTUATOR COMMANDS ARE
#	REGENERATED AS ANALOG VOLTAGES BY THE OPTICS ERROR COUNTERS, WHICH
#	TRANSMIT THE SIGNAL TO THE ACTUATOR SERVOS WHEN THERE IS PROPER CDU
#	MODING.
#
# CALLING SEQUENCE.... (TYPICALLY)
#
#	T5 CALL OF TVCDAPON (TVCINITIALIZE) BY DOTVCON (P40)
#	T5 CALL OF DAPINIT (TVCDAPS) BY TVCINIT4 (TVCINITIALIZE)
#	T5 CALL OF PITCHDAP BY DAPINIT
#	T5 CALL OF YAWDAP BY PITCHDAP
#	T5 CALL OF PITCHDAP BY YAWDAP
#		ETC.
#	(AUTOMATIC SEQUENCING FROM TVCDAPON)
#
# NORMAL EXIT MODE....RESUME
#
# ALARM OR ABORT EXIT MODES....NONE
#
# SUBROUTINES CALLED....
#
#	HACK FOR STROKE TEST (V68) WAVEFORM GENERATION
#	PCOPY, YCOPY FOR COPY-CYCLES (USED ALSO BY TVC RESTART PACKAGE)
#	DAPINIT FOR INITIAL CDUS FOR RATE MEASUREMENTS
#	ERRORLIM, ACTLIM FOR INPUT (ATTITUDE-ERROR INTEGRATION) AND
#		OUTPUT (ACTUATOR COMMAND) LIMITING, COMMON TO PITCH AND
#		YAW DAPS
#	FWDFLTR (INCLUDING OPTVARK) AND PRECOMP, TO COMPUTE FILTER
#		OUTPUTS AND STORAGE VALUES
#	RESUME
#
# OTHER INTERFACES....
#
#	S40.8 CROSS-PRODUCT STEERING FOR BODY AXIS RATE COMMANDS OMEGAY,ZC
#	S40.15 FOR THE INITIAL DAP GAINS VARK AND 1/CONACC
#	TVCEXECUTIVE FOR DAP GAIN UPDATES AND TMC LOOP OPERATIONS
#	TVCRESTART PACKAGE FOR TVC RESTART PROTECTION.
#
# ERASABLE INITIALIZATION REQUIRED....
#
# 	PAD-LOAD ERASABLES (SEE ERASABLE ASSIGNMENTS)
#	CONFIGURATION BITS (14, 13) OF DAPDATR1 AS IN R03
#	ENGINE-ON BIT (11.13) FOR RESTARTS
#	TVCPHASE FOR RESTARTS (SEE DOTVCON, AND TVCINIT4)
#	T5 BITS (15,14 OF FLAGWRD6) FOR RESTARTS
#	MISCELLANEOUS VARIABLES SET UP OR COMPUTED BY TVCDAPON....TVCINIT4,
#		INCLUDING THE ZEROING OF TEMPORARIES BY MRCLEAN
#	CDUX,Y,Z AND SINCDUX.... COSCDUZ AS PREPARED BY QUICTRIG (WITH
#		UPDATES EVERY 1/2 SECOND)
#	ALSO G+N PRIMARY, TVC ENABLE, AND OPTICS ERROR COUNTER ENABLE
#		UNLESS BENCH-TESTING.
#
# OUTPUT....
#
#	TVCPITCH AND TVCYAW WITH COUNTER RELEASE (11.14 AND 11.13 INCREMEN-
#		TAL COMMANDS TO OPTICS ERROR COUNTERS), FILTER NODES, BODY-
#		AXIS ATTITUDE ERROR INTEGRATOR, TOTAL ACTUATOR COMMANDS,
#		OFFSET-TRACKER-FILTER OUTPUTS, ETC.
#
# DEBRIS....
#
#	MUCH, SHAREABLE WITH RCS/ENTRY, IN EBANK6 ONLY

		BANK	17
		SETLOC	DAPS2
		BANK

		EBANK=	BZERO
		
		COUNT*	$$/DAPS
		
# PITCH TVCDAP STARTS HERE....(INCORPORATES CSM/LEM DAP FILTER, MODOR DESIGN)

PITCHDAP	LXCH	BANKRUPT	# T5 ENTRY, NORMAL OR VIA DAPINIT
		EXTEND
		QXCH	QRUPT
		
		CAF	YAWT5		# SET UP T5 CALL FOR YAW AUTOPILOT (LOW-
		TS	T5LOC		#	ORDER PART OF 2CADR ALREADY THERE)
		CAE	T5TVCDT
		TS	TIME5
		
PSTROKER	CCS	STROKER		# (STRKFLG) CHECK FOR STROKE TEST
		TC	HACK		# TEST-START OR TEST-IN-PROGRESS
		TCF	+2		# NO-TEST
		TC	HACK		# TEST-IN-PROGRESS
		
PCDUDOTS	CAE	CDUY		# COMPUTE CDUYDOT (USED BY PITCH AND YAW)
		XCH	PCDUYPST
		EXTEND
		MSU	PCDUYPST
		TCR	RLIMTEST	#	RATE TEST
		TS	MCDUYDOT	#	(MINUS, SC.AT 1/2TVCDT REVS/SEC)
		
		CAE	CDUZ		# COMPUTE CDUZDOT (USED BY PITCH AND YAW)
		XCH	PCDUZPST
		EXTEND
		MSU	PCDUZPST
		TCR	RLIMTEST	#	RATE TEST
		TS	MCDUZDOT	#	(MINUS, SC.AT 1/2TVCDT REVS/SEC)
		TCF	PINTEGRL
		
RLIMTEST	TS	TTMP1		# TEST FOR EXCESSIVE CDU RATES (GREATER
		EXTEND			#	THAN 2.33 DEG IN ONE SAMPLE PERIOD)
		MP	1/RTLIM
		EXTEND
		BZF	+3
		CAF	ZERO
		TS	TTMP1
		CAE	TTMP1
		TC	Q
		
PINTEGRL	EXTEND			# COMPUTE INTEGRAL OF BODY-AXIS PITCH-RATE
		DCA	PERRB		#	ERROR, SC.AT B-1 REVS
		DXCH	ERRBTMP
		
		EXTEND
		DCA	OMEGAYC
		DAS	ERRBTMP
		
		CS	COSCDUZ		# PREPARE BODY-AXIS PITCH RATE, OMEGAYB
		EXTEND
		MP	COSCDUX
		DDOUBL
		EXTEND
		MP	MCDUYDOT
		DDOUBL
		DXCH	OMEGAYB
		
		CS	MCDUZDOT
		EXTEND
		MP	SINCDUX
		DDOUBL
		DAS	OMEGAYB		# (COMPLETED OMEGAYB, SC.AT 1/2TVCDT REVS)
		
		EXTEND			# PICK UP -OMEGAYB (SIGN CHNG, INTEGRATE)
		DCS	OMEGAYB
		DAS	ERRBTMP
		
PERORLIM	TCR	ERRORLIM	# PITCH BODY-AXIS-ERROR INPUT LIMITER

PFORWARD	EXTEND			# 	PREPARE THE FILTER STORAGE LOCATIONS
		DCA	PTMP1		#	FOR THE PITCH CHANNEL
		DXCH	TMP1
		EXTEND
		DCA	PTMP3
		DXCH	TMP3
		EXTEND
		DCA	PTMP5
		DXCH	TMP5
		
		TCR	FWDFLTR		# GO COMPUTE PRESENT OUTPUT
					# (INCLUDES VARIABLE GAIN PACKAGE)
					
POFFSET		EXTEND
		DCA	PDELOFF	
		DAS	CMDTMP		# NOW SCALED AT B+0 ASCREV
		
PACLIM		TCR	ACTLIM		# ROUND OFF & LIMIT PITCH ACTUATOR COMMAND

POUT		CS	PCMD		# INCREMENTAL PITCH COMMAND
		AD	CMDTMP
		ADS	TVCPITCH	# UPDATE THE ERROR COUNTER (NO RESTART-
					#	PROTECT, SINCE ERROR CNTR ZEROED)
					
		CAF	BIT11		# BIT FOR TVCPITCH COUNT RELEASE
		EXTEND
		WOR	CHAN14
		
PPRECOMP	EXTEND			#	PREPARE THE FILTER STORAGE FOR PITCH
		DCA	PTMP2
		DXCH	TMP2
		EXTEND
		DCA	PTMP4
		DXCH	TMP4
		EXTEND
		DCA	PTMP6
		DXCH	TMP6
		
		TCR	PRECOMP		#     TO THE FILTER FOR PRECOMPUTATION
		
DELBARP		CAE	DELPBAR +1	# UPDATE PITCH OFFSET-TRACKER-FILTER
		EXTEND
		MP	E(-AT)
		TS	DELBRTMP +1
		CAE	DELPBAR
		EXTEND
		MP	E(-AT)
		DAS	DELBRTMP
		CAE	CMDTMP
		EXTEND
		MP	1-E(-AT)
		DAS	DELBRTMP
		
PCOPYCYC	TCR	PCOPY		# PITCH COPYCYCLE

PDAPEND		TCF	RESUME		# PITCH DAP COMPLETED
# PITCH TVCDAP COPYCYCLE SUBROUTINE (CALLED VIA PITCH TVCDAP OR TVC RESTART PACKAGE)

PCOPY		INCR	TVCPHASE	# RESTART-PROTECT THE COPYCYCLE.	(1)
					#	NOTE POSSIBLE RE-ENTRY FROM RESTART
					#	PACKAGE, SHOULD A RESTART OCCUR
					#	DURING PITCH COPYCYCLE.
					
		EXTEND		
		DCA	TMP1	
		DXCH	PTMP1
		EXTEND
		DCA	TMP2
		DXCH	PTMP2
		EXTEND
		DCA	TMP3
		DXCH	PTMP3
		EXTEND	
		DCA	TMP4
		DXCH	PTMP4
		EXTEND
		DCA	TMP5
		DXCH	PTMP5
		EXTEND
		DCA	TMP6
		DXCH	PTMP6
		
PMISC		EXTEND			# MISC....PITCH-RATE-ERROR INTEGRATOR
		DCA	ERRBTMP
		TS	AK1		#	FOR PITCH NEEDLES, SC.AT B-1 REVS
		DXCH	PERRB
		
		CAE	CMDTMP		#	PITCH ACTUATOR COMMAND
		TS	PCMD
		
		EXTEND			# 	PITCH OFFSET-TRACKER-FILTER
		DCA	DELBRTMP
		DXCH	DELPBAR
		
		INCR	TVCPHASE	# PITCH COPYCYCLE COMPLETED		(2)
		
		TC	Q

# YAW TVCDAP STARTS HERE....(INCORPORATES CSM/LEM DAP FILTER, MODOR DESIGN)

YAWDAP		LXCH	BANKRUPT	# T5 ENTRY, NORMAL
		EXTEND
		QXCH	QRUPT
		
		CAF	PITCHT5		# SET UP T5 CALL FOR PITCH AUTOPILOT (LOW-
		TS	T5LOC		#	ORDER PART OF 2CADR ALREADY THERE)
		CAE	T5TVCDT
		TS	TIME5
		
YSTROKER	CCS	STROKER		# (STRKFLG) CHECK FOR STROKE TEST
		TC	HACK		# TEST-START OR TEST-IN-PROGRESS
		TCF	+2		# NO-TEST
		TC	HACK		# TEST-IN-PROGRESS
		
YCDUDOTS	CAE	CDUY		# COMPUTE CDUYDOT
		XCH	YCDUYPST
		EXTEND
		MSU	YCDUYPST
		TCR	RLIMTEST	#	RATE TEST
		TS	MCDUYDOT	#	(MINUS, SCALED 1/2TVCDT REV/SEC)

		CAE	CDUZ		# COMPUTE CDUZDOT
		XCH	YCDUZPST
		EXTEND
		MSU	YCDUZPST
		TCR	RLIMTEST	#	RATE TEST
		TS	MCDUZDOT	#	(MINUS, SCALED 1/2TVCDT REV/SEC)
					
YINTEGRL	EXTEND			# COMPUTE INTEGRAL OF BODY-AXIS YAW-RATE
		DCA	YERRB		# 	ERROR, SC.AT B-1 REVS
		DXCH	ERRBTMP
		
		EXTEND
		DCA	OMEGAZC
		DAS	ERRBTMP
		
		CAE	COSCDUZ		# PREPARE BODY-AXIS YAW-RATE, OMEGAZB
		EXTEND
		MP	SINCDUX
		DDOUBL
		EXTEND
		MP	MCDUYDOT
		DDOUBL
		DXCH	OMEGAZB
		
		CS	MCDUZDOT
		EXTEND
		MP	COSCDUX
		DDOUBL
		DAS	OMEGAZB		# (COMPLETED OMEGAZB, SC.AT 1/2TVCDT REVS)
		
		EXTEND			# PICK UP -OMEGAZB (SIGN CHNG, INTEGRATE)
		DCS	OMEGAZB
		DAS	ERRBTMP
		
YERORLIM	TCR	ERRORLIM	# YAW BODY-AXIS-ERROR INPUT LIMITER

YFORWARD	EXTEND			# 	PREPARE THE FILTER STORAGE LOCATIONS
		DCA	YTMP1		#	FOR THE YAW CHANNEL
		DXCH	TMP1
		EXTEND
		DCA	YTMP3
		DXCH	TMP3
		EXTEND
		DCA	YTMP5
		DXCH	TMP5
		
		TCR	FWDFLTR		# GO COMPUTE PRESENT OUTPUT
					# (INCLUDES VARIABLE GAIN PACKAGE)
					
YOFFSET		EXTEND
		DCA	YDELOFF
		DAS	CMDTMP		# NOW SCALED AT B+0 ASCREV

YACLIM		TCR	ACTLIM		# ROUND OFF & LIMIT YAW ACTUATOR COMMAND

YOUT		CS	YCMD		# INCREMENTAL YAW COMMAND
		AD	CMDTMP
		ADS	TVCYAW		# UPDATE THE ERROR COUNTER (NO RESTART-
					#	PROTECT, SINCE ERROR CNTR ZEROED)

		CAF	BIT12		# BIT FOR TVCYAW COUNT RELEASE
		EXTEND
		WOR	CHAN14
		
YPRECOMP	EXTEND			#	PREPARE THE FILTER STORAGE FOR YAW
		DCA	YTMP2
		DXCH	TMP2
		EXTEND
		DCA	YTMP4
		DXCH	TMP4
		EXTEND
		DCA	YTMP6
		DXCH	TMP6
		
		TCR	PRECOMP		#	TO THE FILTER FOR PRECOMPUTATION
		
DELBARY		CAE	DELYBAR +1	# UPDATE YAW OFFSET-TRACKER-FILTER
		EXTEND
		MP	E(-AT)
		TS	DELBRTMP +1
		CAE	DELYBAR
		EXTEND
		MP	E(-AT)
		DAS	DELBRTMP
		CAE	CMDTMP
		EXTEND
		MP	1-E(-AT)
		DAS	DELBRTMP
		
YCOPYCYC	TCR	YCOPY		# YAW COPYCYCLE

YDAPEND		TCF	RESUME		# YAW DAP COMPLETED

# YAW   TVCDAP COPYCYCLE SUBROUTINE (CALLED VIA YAW   TVCDAP OR TVC RESTART PACKAGE)

YCOPY		INCR	TVCPHASE	# RESTART-PROTECT THE COPYCYCLE.	(3)
					#	NOTE POSSIBLE RE-ENTRY FROM RESTART
					#	PACKAGE, SHOULD A RESTART OCCUR
					#	DURING YAW   COPYCYCLE.
					
		EXTEND		
		DCA	TMP1	
		DXCH	YTMP1
		EXTEND
		DCA	TMP2
		DXCH	YTMP2
		EXTEND
		DCA	TMP3
		DXCH	YTMP3	
		EXTEND	
		DCA	TMP4
		DXCH	YTMP4
		EXTEND
		DCA	TMP5
		DXCH	YTMP5
		EXTEND
		DCA	TMP6
		DXCH	YTMP6
		
YMISC		EXTEND			# MISC....YAW-RATE-ERROR INTEGRATOR
		DCA	ERRBTMP
		TS	AK2		#	FOR YAW   NEEDLES, SC.AT B-1 REVS
		DXCH	YERRB
		
		CAE	CMDTMP	
		TS	YCMD
		
		EXTEND		
		DCA	DELBRTMP
		DXCH	DELYBAR
		
		CAF	ZERO		# YAW   COPYCYCLE COMPLETED
		TS	TVCPHASE	#	RESET TVCPHASE
		
		TC	Q
		
# SUBROUTINES COMMON TO BOTH PITCH AND YAW DAPS....

# INITIALIZATION PACKAGE FOR CDURATES....

DAPINIT		LXCH	BANKRUPT	# T5 RUPT ENTRY (CALLED BY TVCINT4)

		CAF	NEGONE		# 	SET UP
		AD	T5TVCDT		#	T5 CALL FOR PITCHDAP IN TVCDT SECS
		AD	NEGMAX		#	(T5TVCDT = POSMAX - TVCDT/2 +1)
		AD	T5TVCDT
		TS	TIME5
		CAF	PITCHT5		#	(BBCON ALREADY THERE)
		TS	T5LOC
		
		CAE	CDUY		# READ AND STORE CDUS FOR DIFFERENTIATOR
		TS	PCDUYPST	#	PAST-VALUES
		TS	YCDUYPST
		CAE	CDUZ
		TS	PCDUZPST
		TS	YCDUZPST
		
		TCF	NOQRSM
		
# BODY-AXIS-ERROR   INPUT LIMITER PACKAGE....

ERRORLIM	CAE	ERRBTMP		# CHECK FOR INPUT-ERROR LIMIT
		EXTEND			#	CHECKS UPPER WORD ONLY
		MP	1/ERRLIM
		EXTEND
		BZF	+6
		CCS	ERRBTMP
		CAF	ERRLIM
		TCF	+2
		CS	ERRLIM
		TS	ERRBTMP		# LIMIT WRITES OVER UPPER WORD ONLY
		
		TC	Q
		
# ACTUATOR-COMMAND LIMITER PACKAGE....

ACTLIM		CAE	CMDTMP	+1	# ROUND UP FOR OUTPUT
		DOUBLE
		TS	L
		CAF	ZERO
		AD	CMDTMP
		
		EXTEND			# CHECK FOR ACTUATOR COMMAND LIMIT
		MP	1/ACTSAT
		EXTEND
		BZF	+6
		CCS	CMDTMP		# APPLY LIMITS
		CAF	ACTSAT
		TCF	+2
		CS	ACTSAT
		TS	CMDTMP		# LIMITS WRITE OVER CMDTMP
		
		TC	Q
		
# FILTER COMPUTATIONS FOR PRESENT OUTPUT................

FWDFLTR		CAF	ZERO
		TS	DAP1
		TS	DAP2
		TS	DAP3
		TS	CMDTMP
		
		TS	DELBRTMP

1DAPCAS		CAE	ERRBTMP +1	# FIRST DAP CASCADE
		EXTEND
		MP	N10		#	N10
		TS	DAP1	+1
		CA	ERRBTMP
		EXTEND
		MP	N10		#	N10
		DAS	DAP1
		DXCH	TMP1
		DAS	DAP1

2DAPCAS		CAE	DAP1	+1	# SECOND DAP CASCADE
		EXTEND
		MP	N10	+5	#	N20
		TS	DAP2	+1
		CA	DAP1
		EXTEND
		MP	N10	+5	#	N20
		DAS	DAP2
		DXCH	TMP3
		DAS	DAP2

		CAE	DAPDATR1	# TEST FOR LEM ON OR OFF
		MASK	BIT14
		CCS	A
		TCF	3DAPCAS		# LEM ON
		EXTEND			# LEM OFF
		DCA	DAP2
		DDOUBL
		DDOUBL
		DXCH	DAP3
		TCF	OPTVARK

3DAPCAS		CAE	DAP2	+1	# THIRD DAP CASCADE
		EXTEND
		MP	N10	+10D	#	N30
		TS	DAP3	+1
		CA	DAP2
		EXTEND
		MP	N10	+10D	#	N30
		DAS	DAP3
		DXCH	TMP5
		DAS	DAP3

## <b>Reconstruction:</b> The line "TS CMDTMP +1" below was accidentally
## duplicated during the implementation of PCR-810 in Comanche 67. This
## was corrected in Comanche 72 under ACB-97, "Delete redundant line
## inadvertently inserted in implementation of PCR 810".
OPTVARK		CS	DAP3	+1	# VARIABLE GAIN PACKAGE
		EXTEND			# (ALSO, SIGN CHANGE IN FORWARD LOOP)
		MP	VARK		#	SCALED (1.08 B+2)   CSM/LM
		TS	CMDTMP	+1	#	       (  "  B+4)   CSM
		CS	DAP3
		EXTEND
		MP	VARK
		DAS	CMDTMP
		
		DXCH	CMDTMP		# FIX UP SCALING - SCALED B+3 ASCREVS
		DDOUBL
		DXCH	CMDTMP		#		 - SCALED B+1 ASCREVS
					# NOTE - THERE IS AN INHERANT GAIN OF
					# (B+1 ASCREVS) ON THE OUTPUT DACS.
					
		TC	Q

# FILTER PRECOMPUTATIONS FOR NEXT PASS...................

PRECOMP		CAF	ZERO		# ***** FIRST CASCADE FILTER **********
		TS	TTMP1
		TS	TTMP2
		
		CA	ERRBTMP +1	# MULTIPLY INPUT BY
		EXTEND
		MP	N10	+1	#	N11/2
		TS	TTMP1	+1
		CA	ERRBTMP
		EXTEND
		MP	N10	+1	#	N11/2
		DAS	TTMP1
		
		CS	DAP1	+1	# MULTIPLY OUTPUT BY
		EXTEND
		MP	N10	+3	# 	D11/2
		TS	TTMP2	+1
		CS	DAP1
		
		EXTEND
		MP	N10	+3	#	D11/2
		DAS	TTMP2
		
		DXCH	TTMP2
		DAS	TTMP1
		DXCH	TTMP1
		DDOUBL
		DAS	TMP2
		
		DXCH	TMP2
		DXCH	TMP1
		
		CAF	ZERO
		TS	TTMP1
		TS	TMP2
		
		CA	ERRBTMP	+1	# MULTIPLY INPUT BY
		EXTEND			# SECOND-ORDER NUMERATOR COEFF.
		MP	N10	+2	#	N12
		TS	TTMP1	+1
		CA	ERRBTMP
		EXTEND
		MP	N10	+2	# 	N12
		DAS	TTMP1
		
		CS	DAP1	+1	# MULTIPLY OUTPUT BY
		EXTEND
		MP	N10	+4	# 	D12
		TS	TMP2	+1
		CS	DAP1
		EXTEND
		MP	N10	+4	#	D12
		DAS	TMP2
		
		DXCH	TTMP1
		DAS	TMP2
		
2CASFLTR	CAF	ZERO		# ***** SECOND CASCADE FILTER *****
		TS	TTMP1
		TS	TTMP2
		
		CA	DAP1	 +1	# MULTIPLY INPUT BY
		EXTEND
		MP	N10	+6	#	N21/2
		TS	TTMP1	+1
		CA	DAP1
		EXTEND
		MP	N10	+6	#	N21/2
		DAS	TTMP1
		
		CS	DAP2	+1	# MULTIPLY OUTPUT BY
		EXTEND
		MP	N10	+8D	# 	D21/2
		TS	TTMP2	+1
		CS	DAP2
		EXTEND
		MP	N10	+8D	#	D21/2
		DAS	TTMP2
		
		DXCH	TTMP2
		DAS	TTMP1
		DXCH	TTMP1
		DDOUBL
		DAS	TMP4
		
		DXCH	TMP4
		DXCH	TMP3
		
		CAF	ZERO
		TS	TTMP1
		TS	TMP4
		
		CA	DAP1	+1	# MULTIPLY INPUT BY
		EXTEND		
		MP	N10	+7	#	N22
		TS	TTMP1	+1
		CA	DAP1
		EXTEND
		MP	N10	+7	# 	N22
		DAS	TTMP1
		
		CS	DAP2	+1	# MULTIPLY OUTPUT BY
		EXTEND
		MP	N10	+9D	# 	D22
		TS	TMP4	+1
		CS	DAP2
		EXTEND
		MP	N10	+9D	#	D22
		DAS	TMP4
		
		DXCH	TTMP1
		DAS	TMP4
		
		CAE	DAPDATR1	# TEST FOR LEM ON OR OFF
		MASK	BIT13
		CCS	A
		TC	Q		# EXIT IF LEM OFF

3CASFLTR	CAF	ZERO		# ***** THIRD CASCADE FILTER *****
		TS	TTMP1
		TS	TTMP2
		
		CA	DAP2	 +1	# MULTIPLY INPUT BY (1/2)
		EXTEND
		MP	N10	+11D	#	N31/2
		TS	TTMP1	+1
		CA	DAP2
		EXTEND
		MP	N10	+11D	#	N31/2
		DAS	TTMP1
		
		CS	DAP3	+1
		EXTEND
		MP	N10	+13D	# 	D31/2
		TS	TTMP2	+1
		CS	DAP3
		EXTEND
		MP	N10	+13D	#	D31/2
		DAS	TTMP2
		
		DXCH	TTMP2
		DAS	TTMP1
		DXCH	TTMP1
		DDOUBL
		DAS	TMP6
		
		DXCH	TMP6
		DXCH	TMP5
		
		CAF	ZERO
		TS	TTMP1
		TS	TMP6
		
		CA	DAP2	+1	# MULTIPLY INPUT BY
		EXTEND		
		MP	N10	+12D	#	N32
		TS	TTMP1	+1
		CA	DAP2
		EXTEND
		MP	N10	+12D	# 	N32
		DAS	TTMP1
		
		CS	DAP3	+1
		EXTEND
		MP	N10	+14D	# 	D32
		TS	TMP6	+1
		CS	DAP3
		EXTEND
		MP	N10	+14D	#	D32
		DAS	TMP6
		
		DXCH	TTMP1
		DAS	TMP6
		
		TC	Q
		
# CONSTANTS FOR AUTOPILOTS

# NOTE....1 ASCREV (ACTUATOR CMD SCALING) = 85.41 ARCSEC/BIT OR 1.07975111 REVS (85.41X16384/3600/360)
#	  1 SPASCREV (SPECIAL ACTUATOR CMD SCALING) = 1.04620942 REVS

ACTSAT		DEC	253		# ACTUATOR LIMIT (6 DEG), SC.AT 1ASCREV
1/ACTSAT	DEC	.0039525692	# RECIPROCAL (1/253)

ERRLIM		EQUALS	BIT13		# FILTER INPUT LIMIT....B-3 REVS (45DEG),
1/ERRLIM	EQUALS	BIT3		# 	SC.AT B-1 REV, AND ITS RECIPROCAL

PITCHT5		GENADR	PITCHDAP	# UPPER WORDS OF T5 2CADRS, LOWER WORDS
DAPT5		GENADR	DAPINIT		#	(BBCON) ALREADY THERE.  ORDER IS
YAWT5		GENADR	YAWDAP		#	REQUIRED.

1/RTLIM		DEC	0.004715	# .004715(CDUDIF) = 0 IF CDUDIF < 2.33 DEG
1-E(-AT)	OCT	00243		# AT = .01SEC....EITHER(1/A=4SEC, T=40MS),
E(-AT)		OCT	37535		#		     OR(1/A=8SEC, T=80MS)

