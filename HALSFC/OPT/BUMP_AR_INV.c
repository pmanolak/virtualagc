/*
  File BUMP_AR_INV.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
BUMP_AR_INV (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "BUMP_AR_INV");
  // AR_INX = AR_INX + 1; (2203)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mAR_INX), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mAR_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // AR_LIST(AR_INX) = PTR; (2204)
  {
    descriptor_t *bitRHS = getBIT (16, mBUMP_AR_INVxPTR);
    putBIT (16, mAR_LIST + 2 * (COREHALFWORD (mAR_INX)), bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
