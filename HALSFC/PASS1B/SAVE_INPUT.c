/*
  File SAVE_INPUT.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
SAVE_INPUT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SAVE_INPUT");
  // IF ~INCLUDE_LIST2 THEN (1121)
  if (1 & (xNOT (BYTE0 (mINCLUDE_LIST2))))
    // RETURN; (1122)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF CARD_TYPE(BYTE(SAVE_CARD)) >= 4 THEN (1123)
  if (1
      & (xGE (
          COREHALFWORD (mCARD_TYPE + 2 * BYTE1 (getCHARACTER (mSAVE_CARD))),
          4)))
    // IF NEXT < 0 THEN (1124)
    if (1 & (xLT (COREHALFWORD (mNEXT), 0)))
      // RETURN; (1125)
      {
        reentryGuard = 0;
        return 0;
      }
  // NEXT = NEXT + 1; (1126)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mNEXT), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mNEXT, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF NEXT > SAVE# THEN (1127)
  if (1 & (xGT (COREHALFWORD (mNEXT), 19)))
    // DO; (1128)
    {
    rs1:;
      // TOO_MANY_LINES = TRUE; (1129)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mTOO_MANY_LINES, bitRHS);
        bitRHS->inUse = 0;
      }
      // NEXT = SAVE#; (1130)
      {
        int32_t numberRHS = (int32_t)(19);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mNEXT, bitRHS);
        bitRHS->inUse = 0;
      }
      // RETURN; (1131)
      {
        reentryGuard = 0;
        return 0;
      }
    es1:;
    } // End of DO block
  // S = CARD_COUNT - INCLUDE_OFFSET; (1132)
  {
    int32_t numberRHS = (int32_t)(xsubtract (getFIXED (mCARD_COUNT),
                                             COREHALFWORD (mINCLUDE_OFFSET)));
    descriptor_t *stringRHS;
    stringRHS = fixedToCharacter (numberRHS);
    putCHARACTER (mS, stringRHS);
    stringRHS->inUse = 0;
  }
  // S = PAD(S, 4); (1133)
  {
    descriptor_t *stringRHS;
    stringRHS = (putCHARACTERp (mPADxSTRING, getCHARACTER (mS)),
                 putFIXED (mPADxWIDTH, 4), PAD (0));
    putCHARACTER (mS, stringRHS);
    stringRHS->inUse = 0;
  }
  // IF (INCLUDING | INCLUDE_END) THEN (1134)
  if (1 & (xOR (BYTE0 (mINCLUDING), BYTE0 (mINCLUDE_END))))
    // INCLUDE_CHAR = PLUS; (1135)
    {
      descriptor_t *stringRHS;
      stringRHS = getCHARACTER (mPLUS);
      putCHARACTER (mINCLUDE_CHAR, stringRHS);
      stringRHS->inUse = 0;
    }
  // ELSE (1136)
  else
    // INCLUDE_CHAR = X1; (1137)
    {
      descriptor_t *stringRHS;
      stringRHS = getCHARACTER (mX1);
      putCHARACTER (mINCLUDE_CHAR, stringRHS);
      stringRHS->inUse = 0;
    }
  // SAVE_GROUP(NEXT) = I_FORMAT(STMT_NUM, 7) || INCLUDE_CHAR ||
  // SUBSTR(SAVE_CARD, 0, 1) || VBAR || SUBSTR(SAVE_CARD, 1) || VBAR || S;
  // (1138)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (
        xsCAT (
            xsCAT (xsCAT (xsCAT (xsCAT ((putFIXED (mI_FORMATxNUMBER,
                                                   getFIXED (mCOMM + 4 * 3)),
                                         putFIXED (mI_FORMATxWIDTH, 7),
                                         I_FORMAT (0)),
                                        getCHARACTER (mINCLUDE_CHAR)),
                                 SUBSTR (getCHARACTER (mSAVE_CARD), 0, 1)),
                          getCHARACTER (mVBAR)),
                   SUBSTR2 (getCHARACTER (mSAVE_CARD), 1)),
            getCHARACTER (mVBAR)),
        getCHARACTER (mS));
    putCHARACTER (mSAVE_GROUP + 4 * (COREHALFWORD (mNEXT)), stringRHS);
    stringRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
