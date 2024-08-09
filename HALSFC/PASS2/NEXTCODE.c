/*
  File NEXTCODE.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
NEXTCODE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "NEXTCODE");
  // CTR=CTR+NUMOP+1; (1016)
  {
    int32_t numberRHS = (int32_t)(xadd (
        xadd (COREHALFWORD (mCTR), COREHALFWORD (mNUMOP)), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // PP=PP+1; (1017)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mPP), 1));
    putFIXED (mPP, numberRHS);
  }
  // CALL CHECK_OPR; (1018)
  NEXTCODExCHECK_OPR (0);
  // DO WHILE OPR(CTR); (1019)
  while (1
         & (getFIXED (getFIXED (mFOR_ATOMS) + 4 * (COREHALFWORD (mCTR)) + 0
                      + 4 * (0))))
    {
      // CTR = CTR + 1; (1020)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mCTR), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mCTR, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL CHECK_OPR; (1021)
      NEXTCODExCHECK_OPR (0);
    } // End of DO WHILE block
  // CALL AUX_SYNC(CTR); (1022)
  {
    putBITp (16, mAUX_SYNCxCTR, getBIT (16, mCTR));
    AUX_SYNC (0);
  }
  // CALL DECODEPOP(CTR); (1023)
  {
    putBITp (16, mDECODEPOPxCTR, getBIT (16, mCTR));
    DECODEPOP (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
