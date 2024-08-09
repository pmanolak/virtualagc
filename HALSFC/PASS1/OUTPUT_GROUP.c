/*
  File OUTPUT_GROUP.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
OUTPUT_GROUP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "OUTPUT_GROUP");
  // IF NEXT < 0 THEN (1147)
  if (1 & (xLT (COREHALFWORD (mNEXT), 0)))
    // RETURN; (1148)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF LISTING2_COUNT + NEXT + 2 > LINE_LIM THEN (1149)
  if (1
      & (xGT (
          xadd (xadd (COREHALFWORD (mLISTING2_COUNT), COREHALFWORD (mNEXT)),
                2),
          COREHALFWORD (mLINE_LIM))))
    // LISTING2_COUNT = LINE_LIM; (1150)
    {
      descriptor_t *bitRHS = getBIT (16, mLINE_LIM);
      putBIT (16, mLISTING2_COUNT, bitRHS);
      bitRHS->inUse = 0;
    }
  // CALL PRINT2(DOUBLE || SAVE_GROUP || X1 || CURRENT_SCOPE, 2); (1151)
  {
    putCHARACTERp (mPRINT2xLINE,
                   xsCAT (xsCAT (xsCAT (getCHARACTER (mDOUBLE),
                                        getCHARACTER (mSAVE_GROUP)),
                                 getCHARACTER (mX1)),
                          getCHARACTER (mCURRENT_SCOPE)));
    putBITp (16, mPRINT2xSPACE, fixedToBit (32, (int32_t)(2)));
    PRINT2 (0);
  }
  // DO I = 1 TO NEXT; (1152)
  {
    int32_t from22, to22, by22;
    from22 = 1;
    to22 = bitToFixed (getBIT (16, mNEXT));
    by22 = 1;
    for (putFIXED (mI, from22); getFIXED (mI) <= to22;
         putFIXED (mI, getFIXED (mI) + by22))
      {
        // CALL PRINT2(X1 || SAVE_GROUP(I) || X1 || CURRENT_SCOPE, 1); (1153)
        {
          putCHARACTERp (
              mPRINT2xLINE,
              xsCAT (xsCAT (xsCAT (getCHARACTER (mX1),
                                   getCHARACTER (mSAVE_GROUP
                                                 + 4 * getFIXED (mI))),
                            getCHARACTER (mX1)),
                     getCHARACTER (mCURRENT_SCOPE)));
          putBITp (16, mPRINT2xSPACE, fixedToBit (32, (int32_t)(1)));
          PRINT2 (0);
        }
      }
  } // End of DO for-loop block
  // IF TOO_MANY_LINES THEN (1154)
  if (1 & (bitToFixed (getBIT (1, mTOO_MANY_LINES))))
    // CALL PRINT2(' *** WARNING *** INPUT BUFFER FILLED; NOT ALL SOURCE LINES
    // ARE PRINTED.', 1); (1155)
    {
      putCHARACTERp (
          mPRINT2xLINE,
          cToDescriptor (NULL, " *** WARNING *** INPUT BUFFER FILLED; NOT ALL "
                               "SOURCE LINES ARE PRINTED."));
      putBITp (16, mPRINT2xSPACE, fixedToBit (32, (int32_t)(1)));
      PRINT2 (0);
    }
  // NEXT = -1; (1156)
  {
    int32_t numberRHS = (int32_t)(-1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mNEXT, bitRHS);
    bitRHS->inUse = 0;
  }
  // TOO_MANY_LINES = FALSE; (1157)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mTOO_MANY_LINES, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
