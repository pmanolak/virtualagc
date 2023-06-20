### FILE="Main.annotation"
## Copyright:	Public domain.
## Filename:	AVERAGE_G_INTEGRATOR.agc
## Purpose:	A section of Corona revision 261.
##		It is part of the source code for the Apollo Guidance Computer
##		(AGC) for AS-202. No original listings of this software are
##		available; instead, this file was created via disassembly of
##		the core rope modules actually flown on the mission.
## Assembler:	yaYUL
## Contact:	Ron Burkey <info@sandroid.org>.
## Website:	www.ibiblio.org/apollo/index.html
## Mod history:	2023-05-27 MAS  Created from Solarium 55.
## 		2023-06-17 MAS  Updated for Corona.


#	ROUTINE CALCRVG INTEGRATES THE EQUATIONS OF MOTION BY AVERAGING THE THRUST AND GRAVITATIONAL ACCELERA-
# TIONS OVER A TIME INTERVAL, DELTAT
#	FOR THE EARTH-CENTERED GRAVITATIONAL FIELD THE PERTURBATION DUE TO OBLATENESS IS COMPUTED TO THE FIRST
# HARMONIC COEFFICIENT J
#	ROUTINE NORMLISE MUST BE CALLED PRIOR TO THE FIRST ENTRY INTO CALCRVG. IT REQUIRES RN SCALED TO 2(+29)M
# IT LEAVES RN NORMALISED, SO THAT THE SCALED MAGNITUDE OF THE VECTOR CONTAINS ONE LEADING ZERO, BY SHIFTING THE
# VECTOR LEFT N BINARY PLACES
#	ROUTINE CALCRVG REQUIRES
#		1) THRUST ACCELERATION INCREMENTS IN DELV SCALED SAME AS PIPAX,Y,Z
#		2) VN SCALED AT 2(+7) M/CS
#		3) ADDRESS OF CALCGLUN OR CALCGEAR IN CALCG
#		4) DELTAT SCALED AT 2(+9) CS
#		5) PUSH-DOWN COUNTER SET TO ZERO
# IT LEAVES UPDATED RN, SCALED AT 2(29-N) M, VN, AND GRAVITY SCALED AT 2(-5) M/CS/CS


#	CONTINUE ON IN BANK 30.
## RSB &mdash; The original source code did not have the following BANK pseudo-op,
## but for some reason I haven't tracked down yet, yaYUL can't resolve the addresses
## without it.  Perhaps a bug in yaYUL.
		BANK	30

NORMLISE	ABVAL	3		# COUNT NUMBER OF LEADING ZEROS IN
		TSLC	INCR,1		# ABVAL (RN) AND STORE -N(=2-M) IN NSHIFT
		SXA,1	INCR,1		# RN MUST BE SCALED AT 2(+29)M
		SXA,1	ITA
			RN
			X1
			2
			NSHIFT		# SAVE C(X1)=-N
			14D
			XSHIFT		# SAVE C(X1) =14-N
			S2
		
		VMOVE	1
		VSLT*
			RN
			14D,1
		STORE	RN		# RN SCALED AT 2(29-N)METRES
		
		ITC	0
			CALCGRV1
		
		ITCI	0
			S2


CALCRVG		VXSC	0
			DELV
			KPIP		# DV TO PD SCALED AT 2(+4)M/CS
		
		VXSC	1
		LXA,1	BVSU
			GRAVITY
			DELTAT
			XSHIFT
			0		# (DV-(OLD GDT))/2 TO PD SCALED 2(+3)M/CS
		
		NOLOD	3
		VSRT	VAD
		VXSC	VSLT*
		VAD	ITA
			4
			VN
			DELTAT
			1,1
			RN
			S2
		STORE	RN1		# SCALED AT 2(29-N) METERS
		
		ITC	0
			CALCGRV1
		
		NOLOD	3
		VXSC	BVSU
		VAD	VSRT
		VAD
			DELTAT
			-		# (DV-(OLD GDT))/2
			-		# DV/2
			4
			VN
		STORE	VN1		# SCALED AT 2(+7) MET/CS
		
#  IN AVERAGE G, UP THE PHASE BITS BY 2 OF ACTIVE PROG BEFORE COPY CYCLE.

		EXIT	0
		
		INDEX	FIXLOC
		CS	S2		# SAVE NEG RETURN ADDRESS IN NON-VAC AREA.
CALCRVG2	TS	AVGRETRN	# SAVE NEGATIVE OF RETURN ADDRESS.

		CS	-PHASE1 +4	# PICK UP PHASES.
		AD	ONE		# INCREMENT BY 1.
		TC	NEWPHASE	# AND CALL ROUTINE TO CHANGE PHASE.
		OCT	00005
REFAZE6		INHINT
		CAF	ELEVEND
		TS	MPAC		# USE MPAC FOR LOOP COUNTER.
		INDEX	MPAC
		CS	RN1		# RN1 AND VN1 MUST BE IN ORDER.
		COM			# LEAVE RN1 ALONE  IN CASE OF RESTARTS.
		INDEX	MPAC		# SELECT THE RIGHT TERM.
		TS	RN		# ...AND GO THRU COPY CYCLE.
		
		CCS	MPAC		# ARE WE DONE..
		TC	REFAZE6 +2	# NO, NOT YET.
		CS	BIT2		# YES, MPAC = 0.
		MASK	TMMARKER
		AD	BIT2		# SET BIT 2 TO ONE IN TMMARKER.
		TS	TMMARKER
					# WHAT ABOUT GRAVITY FOR RESTART..
		RELINT
		CS	AVGRETRN	# NEG OF ADDRESS WAS STORED.
		TC	BANKJUMP



ELEVEND		DEC	11		# 11D  (ELEVEN DECIMAL, OF COURSE.)



CALCGRAV	LXA,1	0
			XSHIFT

CALCGRV1	NOLOD	1
		UNIT
		STORE	UNITR
		
		DMOVE	0
			30D
		STORE	RMAG		# SCALED AT 2(30-N)M
		
		TSLT	0
			28D
			3
		STORE	RMAGSQ		# SCALED AT 2(+50)M(+2)
		
		ITA	1
		XAD,1	ITCI
			27D
			NSHIFT
			CALCG

CALCGEAR	DOT	0
			UNITR
			UNITW
		STORE	25D
		
		NOLOD	2
		DSQ	DMP
		TSLT	BDSU
			DP(5/8)
			4
			DP2(-3)
		
		DDV	1
		TSLT*
			J(RE)SQ		# SCALED AT 2(+40) M(+2)
			RMAGSQ
			0,1
		STORE	23D		# J(RE/RN) SQ SCALED AT 2(-3)
		
		NOLOD	2
		DMP	VXSC
		VAD
			-
			UNITR
			UNITR
		
		DMP	1
		VXSC	VAD
			23D
			25D
			UNITW
		
		DMOVE	1
		ITC
			MUEARTH
			MU/RSQ

CALCGLUN	VMOVE	0
			UNITR
		
		DMOVE	1
		INCR,1
			MUMOON
			6
		
MU/RSQ		NOLOD	2
		DDV	TSLT*
		VXSC
			RMAGSQ		# C(X1)=14-2N  (EARTH)
			5,1		#      =20-2N  (MOON)
		STORE	GRAVITY		# SCALED AT 2(-5) M/CS/CS
		
		ITCI	0
			27D

KPIP		2DEC	0.59904
DP2(-3)		2DEC	0.125
DP(5/8)		2DEC	0.625
MUEARTH		2DEC	.009063188 	# SCALED AT 2(+42)M(+3)/CS(+2)
MUMOON		2DEC	0.007134481	# 4.90277800 E12	2(+36)M(+3)/CS(+2)
J(RE)SQ		2DEC	.06006663 	# SCALED AT 2(+40)M(+2)