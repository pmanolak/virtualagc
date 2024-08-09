/*
  File POPVAL.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

descriptor_t *
POPVAL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "POPVAL");
  // RETURN SHR(OPR(CTR),16); (1061)
  {
    reentryGuard = 0;
    return fixedToBit (
        32,
        (int32_t)(SHR (getFIXED (mOPR + 4 * COREHALFWORD (mPOPVALxCTR)), 16)));
  }
}
