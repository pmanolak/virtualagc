/*
  File POPCODE.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
POPCODE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "POPCODE");
  // RETURN OPR(CTR) &  65521; (969)
  {
    reentryGuard = 0;
    return xAND (getFIXED (getFIXED (mFOR_ATOMS)
                           + 4 * (COREHALFWORD (mPOPCODExCTR)) + 0 + 4 * (0)),
                 65521);
  }
}
