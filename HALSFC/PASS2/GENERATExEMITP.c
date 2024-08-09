/*
  File GENERATExEMITP.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExEMITP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExEMITP");
  // IF FLAG < 0 THEN (3140)
  if (1 & (xLT (COREHALFWORD (mGENERATExEMITPxFLAG), 0)))
    // DO; (3141)
    {
    rs1:;
      // SWITCH = 1; (3142)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mGENERATExEMITPxSWITCH, bitRHS);
        bitRHS->inUse = 0;
      }
      // FLAG = -FLAG; (3143)
      {
        int32_t numberRHS
            = (int32_t)(xminus (COREHALFWORD (mGENERATExEMITPxFLAG)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATExEMITPxFLAG, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (3144)
  else
    // SWITCH = 0; (3145)
    {
      int32_t numberRHS = (int32_t)(0);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (1, mGENERATExEMITPxSWITCH, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF INDEX < 0 THEN (3146)
  if (1 & (xLT (COREHALFWORD (mGENERATExEMITPxINDEX), 0)))
    // CALL ERRORS(CLASS_BI,511,'INDEX'); (3147)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(511)));
      putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "INDEX"));
      ERRORS (0);
    }
  // IF XREG < 0 THEN (3148)
  if (1 & (xLT (COREHALFWORD (mGENERATExEMITPxXREG), 0)))
    // CALL ERRORS(CLASS_BI,511,'ACCUMULATOR'); (3149)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(511)));
      putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "ACCUMULATOR"));
      ERRORS (0);
    }
  // CALL OPSTAT(INST, XREG); (3150)
  {
    putBITp (16, mGENERATExOPSTATxINST, getBIT (16, mGENERATExEMITPxINST));
    putBITp (16, mGENERATExOPSTATxXREG, getBIT (16, mGENERATExEMITPxXREG));
    GENERATExOPSTAT (0);
  }
  // XREG = XREG & RM; (3151)
  {
    int32_t numberRHS = (int32_t)(xAND (COREHALFWORD (mGENERATExEMITPxXREG),
                                        getFIXED (mRM)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExEMITPxXREG, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF FLAG = SYM THEN (3152)
  if (1 & (xEQ (COREHALFWORD (mGENERATExEMITPxFLAG), BYTE0 (mSYM))))
    // IF (SYT_BASE(PTR) >= REMOTE_BASE)  | NRDEREF THEN (3153)
    if (1
        & (xOR (xGE (COREHALFWORD (getFIXED (mP2SYMS)
                                   + 12 * (COREHALFWORD (mGENERATExEMITPxPTR))
                                   + 4 + 2 * (0)),
                     BYTE0 (mREMOTE_BASE)),
                BYTE0 (mGENERATExEMITPxNRDEREF))))
      // DO; (3154)
      {
      rs2:;
        // IF ~NRDEREF THEN (3155)
        if (1 & (xNOT (BYTE0 (mGENERATExEMITPxNRDEREF))))
          // DO; (3156)
          {
          rs2s1:;
            // IF INSMOD ~= 0 THEN (3157)
            if (1 & (xNEQ (getFIXED (mINSMOD), 0)))
              // CALL ERRORS(CLASS_BS,123,'1'); (3158)
              {
                putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BS));
                putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(123)));
                putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "1"));
                ERRORS (0);
              }
            // ELSE (3159)
            else
              // IF SYT_BASE(PTR) = REMOTE_BASE THEN (3160)
              if (1
                  & (xEQ (
                      COREHALFWORD (getFIXED (mP2SYMS)
                                    + 12 * (COREHALFWORD (mGENERATExEMITPxPTR))
                                    + 4 + 2 * (0)),
                      BYTE0 (mREMOTE_BASE))))
                // DO; (3161)
                {
                rs2s1s1:;
                  // IF INDEX = 0 THEN (3162)
                  if (1 & (xEQ (COREHALFWORD (mGENERATExEMITPxINDEX), 0)))
                    // CALL ERRORS(CLASS_BS,123,'2'); (3163)
                    {
                      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BS));
                      putBITp (16, mERRORSxNUM,
                               fixedToBit (32, (int32_t)(123)));
                      putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "2"));
                      ERRORS (0);
                    }
                es2s1s1:;
                } // End of DO block
              // ELSE (3164)
              else
                // IF (INDEX ~= 0) & ~( ((SYT_FLAGS(PTR) & NAME_FLAG) ~= 0) &
                // (SYT_ARRAY(PTR) ~= 0) )  THEN (3165)
                if (1
                    & (xAND (
                        xNEQ (COREHALFWORD (mGENERATExEMITPxINDEX), 0),
                        xNOT (xAND (
                            xNEQ (
                                xAND (getFIXED (getFIXED (mSYM_TAB)
                                                + 34
                                                      * (COREHALFWORD (
                                                          mGENERATExEMITPxPTR))
                                                + 8 + 4 * (0)),
                                      getFIXED (mNAME_FLAG)),
                                0),
                            xNEQ (
                                COREHALFWORD (
                                    getFIXED (mSYM_TAB)
                                    + 34 * (COREHALFWORD (mGENERATExEMITPxPTR))
                                    + 20 + 2 * (0)),
                                0))))))
                  // CALL ERRORS(CLASS_BS,123,'3'); (3166)
                  {
                    putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BS));
                    putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(123)));
                    putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "3"));
                    ERRORS (0);
                  }
          es2s1:;
          } // End of DO block
        // IF INDEX = 0 THEN (3167)
        if (1 & (xEQ (COREHALFWORD (mGENERATExEMITPxINDEX), 0)))
          // INDEX = 1; (3168)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGENERATExEMITPxINDEX, bitRHS);
            bitRHS->inUse = 0;
          }
        // XREG = XREG | 8; (3169)
        {
          int32_t numberRHS
              = (int32_t)(xOR (COREHALFWORD (mGENERATExEMITPxXREG), 8));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mGENERATExEMITPxXREG, bitRHS);
          bitRHS->inUse = 0;
        }
        // INDEX = INDEX | 8; (3170)
        {
          int32_t numberRHS
              = (int32_t)(xOR (COREHALFWORD (mGENERATExEMITPxINDEX), 8));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mGENERATExEMITPxINDEX, bitRHS);
          bitRHS->inUse = 0;
        }
      es2:;
      } // End of DO block
  // IF ASSEMBLER_CODE THEN (3171)
  if (1 & (bitToFixed (getBIT (1, mASSEMBLER_CODE))))
    // DO; (3172)
    {
    rs3:;
      // CALL FORMAT_OPERANDS(FLAG, PTR); (3173)
      {
        putBITp (16, mGENERATExFORMAT_OPERANDSxFLAG,
                 getBIT (16, mGENERATExEMITPxFLAG));
        putBITp (16, mGENERATExFORMAT_OPERANDSxPTR,
                 getBIT (16, mGENERATExEMITPxPTR));
        GENERATExFORMAT_OPERANDS (0);
      }
      // IF (INDEX&RM) > 0 THEN (3174)
      if (1
          & (xGT (xAND (COREHALFWORD (mGENERATExEMITPxINDEX), getFIXED (mRM)),
                  0)))
        // CHARSTRING=CHARSTRING||LEFTBRACKET||(INDEX&RM)||RIGHTBRACKET; (3175)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (xsCAT (xsCAT (getCHARACTER (mCHARSTRING),
                                           getCHARACTER (mLEFTBRACKET)),
                                    fixedToCharacter (xAND (
                                        COREHALFWORD (mGENERATExEMITPxINDEX),
                                        getFIXED (mRM)))),
                             getCHARACTER (mRIGHTBRACKET));
          putCHARACTER (mCHARSTRING, stringRHS);
          stringRHS->inUse = 0;
        }
      // MESSAGE = INSTRUCTION(INST, SHR(INDEX,3)); (3176)
      {
        descriptor_t *stringRHS;
        stringRHS
            = (putBITp (16, mINSTRUCTIONxOPCODE,
                        getBIT (16, mGENERATExEMITPxINST)),
               putBITp (
                   16, mINSTRUCTIONxTAG,
                   fixedToBit (
                       32, (int32_t)(SHR (COREHALFWORD (mGENERATExEMITPxINDEX),
                                          3)))),
               INSTRUCTION (0));
        putCHARACTER (mMESSAGE, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT=HEX_LOCCTR||X3||MESSAGE||X3||(XREG&RM)||COMMA||CHARSTRING;
      // (3177)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (
                xsCAT (
                    xsCAT (xsCAT (xsCAT (HEX_LOCCTR (0), getCHARACTER (mX3)),
                                  getCHARACTER (mMESSAGE)),
                           getCHARACTER (mX3)),
                    fixedToCharacter (xAND (
                        COREHALFWORD (mGENERATExEMITPxXREG), getFIXED (mRM)))),
                getCHARACTER (mCOMMA)),
            getCHARACTER (mCHARSTRING));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es3:;
    } // End of DO block
  // IF INSTYPE = 0 THEN (3178)
  if (1 & (xEQ (COREHALFWORD (mGENERATExEMITPxINSTYPE), 0)))
    // IF FLAG = SYM THEN (3179)
    if (1 & (xEQ (COREHALFWORD (mGENERATExEMITPxFLAG), BYTE0 (mSYM))))
      // INSTYPE = CHECK_SRS(INST,INDEX,SYT_BASE(PTR),SYT_DISP(PTR)+INSMOD);
      // (3180)
      {
        descriptor_t *bitRHS
            = (putBITp (16, mCHECK_SRSxINST,
                        getBIT (16, mGENERATExEMITPxINST)),
               putBITp (16, mCHECK_SRSxIX, getBIT (16, mGENERATExEMITPxINDEX)),
               putBITp (
                   16, mCHECK_SRSxBASE,
                   getBIT (16, getFIXED (mP2SYMS)
                                   + 12 * (COREHALFWORD (mGENERATExEMITPxPTR))
                                   + 4 + 2 * (0))),
               putFIXED (mCHECK_SRSxDISP,
                         xadd (COREHALFWORD (
                                   getFIXED (mP2SYMS)
                                   + 12 * (COREHALFWORD (mGENERATExEMITPxPTR))
                                   + 6 + 2 * (0)),
                               getFIXED (mINSMOD))),
               CHECK_SRS (0));
        putBIT (16, mGENERATExEMITPxINSTYPE, bitRHS);
        bitRHS->inUse = 0;
      }
    // ELSE (3181)
    else
      // IF FLAG=LOCREL | FLAG=SHCOUNT | FLAG=IMD THEN (3182)
      if (1
          & (xOR (
              xOR (
                  xEQ (COREHALFWORD (mGENERATExEMITPxFLAG), BYTE0 (mLOCREL)),
                  xEQ (COREHALFWORD (mGENERATExEMITPxFLAG), BYTE0 (mSHCOUNT))),
              xEQ (COREHALFWORD (mGENERATExEMITPxFLAG), BYTE0 (mIMD)))))
        // INSTYPE = SRSTYPE; (3183)
        {
          descriptor_t *bitRHS = getBIT (8, mSRSTYPE);
          putBIT (16, mGENERATExEMITPxINSTYPE, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (3184)
      else
        // INSTYPE = RXTYPE; (3185)
        {
          descriptor_t *bitRHS = getBIT (8, mRXTYPE);
          putBIT (16, mGENERATExEMITPxINSTYPE, bitRHS);
          bitRHS->inUse = 0;
        }
  // IF DATA_REMOTE & (D_R1_CHANGE | D_R3_CHANGE) THEN (3186)
  if (1
      & (xAND (BYTE0 (mDATA_REMOTE),
               xOR (BYTE0 (mD_R1_CHANGE), BYTE0 (mD_R3_CHANGE)))))
    // DO; (3187)
    {
    rs4:;
      // IF (FLAG=SYM) THEN (3188)
      if (1 & (xEQ (COREHALFWORD (mGENERATExEMITPxFLAG), BYTE0 (mSYM))))
        // CALL CHECK_RESTORE_R1R3(INST,SYM,SYT_BASE(PTR),XREG,INSTYPE); (3189)
        {
          putBITp (16, mGENERATExCHECK_RESTORE_R1R3xINST,
                   getBIT (16, mGENERATExEMITPxINST));
          putBITp (16, mGENERATExCHECK_RESTORE_R1R3xFLAG, getBIT (8, mSYM));
          putBITp (16, mGENERATExCHECK_RESTORE_R1R3xXBASE,
                   getBIT (16, getFIXED (mP2SYMS)
                                   + 12 * (COREHALFWORD (mGENERATExEMITPxPTR))
                                   + 4 + 2 * (0)));
          putBITp (16, mGENERATExCHECK_RESTORE_R1R3xCOND,
                   getBIT (16, mGENERATExEMITPxXREG));
          putBITp (16, mGENERATExCHECK_RESTORE_R1R3xINSTYPE,
                   getBIT (16, mGENERATExEMITPxINSTYPE));
          GENERATExCHECK_RESTORE_R1R3 (0);
        }
      // ELSE (3190)
      else
        // CALL CHECK_RESTORE_R1R3(INST,FLAG,0,XREG,INSTYPE); (3191)
        {
          putBITp (16, mGENERATExCHECK_RESTORE_R1R3xINST,
                   getBIT (16, mGENERATExEMITPxINST));
          putBITp (16, mGENERATExCHECK_RESTORE_R1R3xFLAG,
                   getBIT (16, mGENERATExEMITPxFLAG));
          putBITp (16, mGENERATExCHECK_RESTORE_R1R3xXBASE,
                   fixedToBit (32, (int32_t)(0)));
          putBITp (16, mGENERATExCHECK_RESTORE_R1R3xCOND,
                   getBIT (16, mGENERATExEMITPxXREG));
          putBITp (16, mGENERATExCHECK_RESTORE_R1R3xINSTYPE,
                   getBIT (16, mGENERATExEMITPxINSTYPE));
          GENERATExCHECK_RESTORE_R1R3 (0);
        }
    es4:;
    } // End of DO block
  // CALL EMITC(INSTYPE, SHL(INST,8) | SHL(XREG,4) | INDEX); (3192)
  {
    putBITp (16, mEMITCxTYPE, getBIT (16, mGENERATExEMITPxINSTYPE));
    putBITp (
        16, mEMITCxINST,
        fixedToBit (32, (int32_t)(xOR (
                            xOR (SHL (COREHALFWORD (mGENERATExEMITPxINST), 8),
                                 SHL (COREHALFWORD (mGENERATExEMITPxXREG), 4)),
                            COREHALFWORD (mGENERATExEMITPxINDEX)))));
    EMITC (0);
  }
  // IF SWITCH THEN (3193)
  if (1 & (bitToFixed (getBIT (1, mGENERATExEMITPxSWITCH))))
    // CALL EMITC(FLAG, -PTR); (3194)
    {
      putBITp (16, mEMITCxTYPE, getBIT (16, mGENERATExEMITPxFLAG));
      putBITp (16, mEMITCxINST,
               fixedToBit (32, (int32_t)(xminus (
                                   COREHALFWORD (mGENERATExEMITPxPTR)))));
      EMITC (0);
    }
  // ELSE (3195)
  else
    // CALL EMITC(FLAG, PTR); (3196)
    {
      putBITp (16, mEMITCxTYPE, getBIT (16, mGENERATExEMITPxFLAG));
      putBITp (16, mEMITCxINST, getBIT (16, mGENERATExEMITPxPTR));
      EMITC (0);
    }
  // INSMOD, INSTYPE = 0; (3197)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mINSMOD, numberRHS);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExEMITPxINSTYPE, bitRHS);
    bitRHS->inUse = 0;
  }
  // NRDEREF=0; (3198)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExEMITPxNRDEREF, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
