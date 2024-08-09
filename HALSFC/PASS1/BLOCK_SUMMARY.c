/*
  File BLOCK_SUMMARY.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
BLOCK_SUMMARY (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "BLOCK_SUMMARY");
  // CALL COMPRESS_OUTER_REF; (4723)
  COMPRESS_OUTER_REF (0);
  // FIRST_TIME = TRUE; (4724)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mBLOCK_SUMMARYxFIRST_TIME, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO I = 0 TO MAX_SUM; (4725)
  {
    int32_t from85, to85, by85;
    from85 = 0;
    to85 = 17;
    by85 = 1;
    for (putBIT (16, mBLOCK_SUMMARYxI, fixedToBit (16, from85));
         bitToFixed (getBIT (16, mBLOCK_SUMMARYxI)) <= to85;
         putBIT (16, mBLOCK_SUMMARYxI,
                 fixedToBit (16, bitToFixed (getBIT (16, mBLOCK_SUMMARYxI))
                                     + by85)))
      {
        // C = ''; (4726)
        {
          descriptor_t *stringRHS;
          stringRHS = cToDescriptor (NULL, "");
          putCHARACTER (mC, stringRHS);
          stringRHS->inUse = 0;
        }
        // C(1) = X4; (4727)
        {
          descriptor_t *stringRHS;
          stringRHS = getCHARACTER (mX4);
          putCHARACTER (mC + 4 * (1), stringRHS);
          stringRHS->inUse = 0;
        }
        // HEADER_ISSUED = FALSE; (4728)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (1, mBLOCK_SUMMARYxHEADER_ISSUED, bitRHS);
          bitRHS->inUse = 0;
        }
        // CALL OUT_BLOCK_SUMMARY; (4729)
        BLOCK_SUMMARYxOUT_BLOCK_SUMMARY (0);
        // IF LENGTH(C) ~= 0 THEN (4730)
        if (1 & (xNEQ (LENGTH (getCHARACTER (mC)), 0)))
          // OUTPUT = C; (4731)
          {
            descriptor_t *stringRHS;
            stringRHS = getCHARACTER (mC);
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
      }
  } // End of DO for-loop block
  // IF (SYT_FLAGS(BLOCK_SYTREF(NEST)) & EXTERNAL_FLAG) = 0 THEN (4732)
  if (1
      & (xEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                              + 34
                                    * (COREHALFWORD (mBLOCK_SYTREF
                                                     + 2 * getFIXED (mNEST)))
                              + 8 + 4 * (0)),
                    1048576),
              0)))
    // DO; (4733)
    {
    rs2:;
      // LINE_MAX = 0; (4734)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mLINE_MAX, bitRHS);
        bitRHS->inUse = 0;
      }
      // PAGE_THROWN=TRUE; (4735)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mPAGE_THROWN, bitRHS);
        bitRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
