/*
  File SET_FLAG.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
SET_FLAG (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SET_FLAG");
  // FLAG(PTR) = FLAG(PTR) | SHL(1,BIT#); (4141)
  {
    int32_t numberRHS
        = (int32_t)(xOR (BYTE0 (mFLAG + 1 * COREHALFWORD (mSET_FLAGxPTR)),
                         SHL (1, BYTE0 (mSET_FLAGxBITp))));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mFLAG + 1 * (COREHALFWORD (mSET_FLAGxPTR)), bitRHS);
    bitRHS->inUse = 0;
  }
  // BIT# = 0; (4142)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mSET_FLAGxBITp, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
