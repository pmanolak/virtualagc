/*
  File ZAP_BIT.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

descriptor_t *
ZAP_BIT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ZAP_BIT");
  // PTR = REL(PTR); (2312)
  {
    descriptor_t *bitRHS
        = getBIT (16, getFIXED (mSYM_SHRINK)
                          + 2 * (COREHALFWORD (mZAP_BITxPTR)) + 0 + 2 * (0));
    putBIT (16, mZAP_BITxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN(SHR(LOOP_ZAPS(SHR(PTR,5)),PTR &  31) | LOOP_ZAPS(0)) &  1; (2313)
  {
    reentryGuard = 0;
    return fixedToBit (
        32,
        (int32_t)(xAND (
            xOR (SHR (getFIXED (getFIXED (mOBPS)
                                + 4 * (COREHALFWORD (mLOOP_ZAPS_LEVEL)) + 0
                                + 4 * (SHR (COREHALFWORD (mZAP_BITxPTR), 5))),
                      xAND (COREHALFWORD (mZAP_BITxPTR), 31)),
                 getFIXED (getFIXED (mOBPS)
                           + 4 * (COREHALFWORD (mLOOP_ZAPS_LEVEL)) + 0
                           + 4 * (0))),
            1)));
  }
}
