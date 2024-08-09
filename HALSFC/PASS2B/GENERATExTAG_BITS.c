/*
  File GENERATExTAG_BITS.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExTAG_BITS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExTAG_BITS");
  // RETURN SHR(OPR(CTR+OP),4)& 15; (3519)
  {
    reentryGuard = 0;
    return fixedToBit (
        32, (int32_t)(xAND (
                SHR (getFIXED (
                         getFIXED (mFOR_ATOMS)
                         + 4
                               * (xadd (COREHALFWORD (mCTR),
                                        COREHALFWORD (mGENERATExTAG_BITSxOP)))
                         + 0 + 4 * (0)),
                     4),
                15)));
  }
}
