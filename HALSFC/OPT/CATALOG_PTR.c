/*
  File CATALOG_PTR.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

descriptor_t *
CATALOG_PTR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CATALOG_PTR");
  // RETURN CATALOG_ARRAY(REL(PTR)); (955)
  {
    reentryGuard = 0;
    return getBIT (
        16, getFIXED (mPAR_SYM) + 2 * (COREHALFWORD (mLEVEL)) + 0
                + 2
                      * (COREHALFWORD (getFIXED (mSYM_SHRINK)
                                       + 2 * (COREHALFWORD (mCATALOG_PTRxPTR))
                                       + 0 + 2 * (0))));
  }
}
