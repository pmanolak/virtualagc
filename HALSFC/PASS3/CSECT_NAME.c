/*
  File CSECT_NAME.c generated by XCOM-I, 2024-08-09 12:40:16.
*/

#include "runtimeC.h"

descriptor_t *
CSECT_NAME (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CSECT_NAME");
  // TEMPSTRING = SYT_NAME(ENTRY); (1032)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mCSECT_NAMExENTRY)) + 0
                              + 4 * (0));
    putCHARACTER (mCSECT_NAMExTEMPSTRING, stringRHS);
    stringRHS->inUse = 0;
  }
  // WORK1 = CHAR_INDEX(TEMPSTRING,'_'); (1033)
  {
    descriptor_t *bitRHS
        = (putCHARACTERp (mCHAR_INDEXxSTRING1,
                          getCHARACTER (mCSECT_NAMExTEMPSTRING)),
           putCHARACTERp (mCHAR_INDEXxSTRING2, cToDescriptor (NULL, "_")),
           CHAR_INDEX (0));
    int32_t numberRHS;
    numberRHS = bitToFixed (bitRHS);
    putFIXED (mWORK1, numberRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE WORK1 > 0; (1034)
  while (1 & (xGT (getFIXED (mWORK1), 0)))
    {
      // TEMPSTRING=SUBSTR(TEMPSTRING,0,WORK1)||SUBSTR(TEMPSTRING,WORK1+1);
      // (1035)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (SUBSTR (getCHARACTER (mCSECT_NAMExTEMPSTRING), 0,
                                   getFIXED (mWORK1)),
                           SUBSTR2 (getCHARACTER (mCSECT_NAMExTEMPSTRING),
                                    xadd (getFIXED (mWORK1), 1)));
        putCHARACTER (mCSECT_NAMExTEMPSTRING, stringRHS);
        stringRHS->inUse = 0;
      }
      // WORK1 = CHAR_INDEX(TEMPSTRING,'_'); (1036)
      {
        descriptor_t *bitRHS
            = (putCHARACTERp (mCHAR_INDEXxSTRING1,
                              getCHARACTER (mCSECT_NAMExTEMPSTRING)),
               putCHARACTERp (mCHAR_INDEXxSTRING2, cToDescriptor (NULL, "_")),
               CHAR_INDEX (0));
        int32_t numberRHS;
        numberRHS = bitToFixed (bitRHS);
        putFIXED (mWORK1, numberRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // IX1 = LENGTH(TEMPSTRING); (1037)
  {
    int32_t numberRHS
        = (int32_t)(LENGTH (getCHARACTER (mCSECT_NAMExTEMPSTRING)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mIX1, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF IX1 >= 6 THEN (1038)
  if (1 & (xGE (COREHALFWORD (mIX1), 6)))
    // TEMPSTRING = SUBSTR(TEMPSTRING, 0, 6); (1039)
    {
      descriptor_t *stringRHS;
      stringRHS = SUBSTR (getCHARACTER (mCSECT_NAMExTEMPSTRING), 0, 6);
      putCHARACTER (mCSECT_NAMExTEMPSTRING, stringRHS);
      stringRHS->inUse = 0;
    }
  // ELSE (1040)
  else
    // TEMPSTRING = TEMPSTRING || SUBSTR(X10, 0, 6-IX1); (1041)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          getCHARACTER (mCSECT_NAMExTEMPSTRING),
          SUBSTR (getCHARACTER (mX10), 0, xsubtract (6, COREHALFWORD (mIX1))));
      putCHARACTER (mCSECT_NAMExTEMPSTRING, stringRHS);
      stringRHS->inUse = 0;
    }
  // IF TASK = 0 THEN (1042)
  if (1 & (xEQ (COREHALFWORD (mCSECT_NAMExTASK), 0)))
    // RETURN NAMETYPE(FLAG) || TEMPSTRING; (1043)
    {
      reentryGuard = 0;
      return xsCAT (getCHARACTER (mCSECT_NAMExNAMETYPE
                                  + 4 * COREHALFWORD (mCSECT_NAMExFLAG)),
                    getCHARACTER (mCSECT_NAMExTEMPSTRING));
    }
  // IF FLAG = 7 THEN (1044)
  if (1 & (xEQ (COREHALFWORD (mCSECT_NAMExFLAG), 7)))
    // DO; (1045)
    {
    rs2:;
      // TASK = TASK - SYT_SCOPE(SELFNAMELOC); (1046)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            COREHALFWORD (mCSECT_NAMExTASK),
            BYTE0 (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mSELFNAMELOC))
                   + 29 + 1 * (0))));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mCSECT_NAMExTASK, bitRHS);
        bitRHS->inUse = 0;
      }
      // IX1 = TASK / 10; (1047)
      {
        int32_t numberRHS
            = (int32_t)(xdivide (COREHALFWORD (mCSECT_NAMExTASK), 10));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mIX1, bitRHS);
        bitRHS->inUse = 0;
      }
      // IX2 = TASK MOD 10; (1048)
      {
        int32_t numberRHS
            = (int32_t)(xmod (COREHALFWORD (mCSECT_NAMExTASK), 10));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mIX2, bitRHS);
        bitRHS->inUse = 0;
      }
      // TASK = 0; (1049)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mCSECT_NAMExTASK, bitRHS);
        bitRHS->inUse = 0;
      }
      // RETURN SUBSTR(ALPHSEQ,IX1,1)||SUBSTR(NUMSEQ,IX2,1)||TEMPSTRING; (1050)
      {
        reentryGuard = 0;
        return xsCAT (xsCAT (SUBSTR (getCHARACTER (mCSECT_NAMExALPHSEQ),
                                     COREHALFWORD (mIX1), 1),
                             SUBSTR (getCHARACTER (mCSECT_NAMExNUMSEQ),
                                     COREHALFWORD (mIX2), 1)),
                      getCHARACTER (mCSECT_NAMExTEMPSTRING));
      }
    es2:;
    } // End of DO block
  // TEMPSTRING = SUBSTR(NAMETYPE(FLAG),0,1) || SUBSTR(NUMSEQ,TASK,1) ||
  // TEMPSTRING; (1051)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (
        xsCAT (SUBSTR (getCHARACTER (mCSECT_NAMExNAMETYPE
                                     + 4 * COREHALFWORD (mCSECT_NAMExFLAG)),
                       0, 1),
               SUBSTR (getCHARACTER (mCSECT_NAMExNUMSEQ),
                       COREHALFWORD (mCSECT_NAMExTASK), 1)),
        getCHARACTER (mCSECT_NAMExTEMPSTRING));
    putCHARACTER (mCSECT_NAMExTEMPSTRING, stringRHS);
    stringRHS->inUse = 0;
  }
  // TASK = 0; (1052)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCSECT_NAMExTASK, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN TEMPSTRING; (1053)
  {
    reentryGuard = 0;
    return getCHARACTER (mCSECT_NAMExTEMPSTRING);
  }
}
