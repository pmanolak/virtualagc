/*
  File HALMAT_FIX_POPTAG.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
HALMAT_FIX_POPTAG (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "HALMAT_FIX_POPTAG");
  // IF HALMAT_OK THEN (7231)
  if (1 & (bitToFixed (getBIT (1, mHALMAT_OK))))
    // ATOMS(POP_LOC)=(ATOMS(POP_LOC)& 16777215) |SHL(TAG& 255,24); (7232)
    {
      int32_t numberRHS = (int32_t)(xOR (
          xAND (getFIXED (getFIXED (mFOR_ATOMS)
                          + 4 * (getFIXED (mHALMAT_FIX_POPTAGxPOP_LOC)) + 0
                          + 4 * (0)),
                16777215),
          SHL (xAND (BYTE0 (mHALMAT_FIX_POPTAGxTAG), 255), 24)));
      putFIXED (getFIXED (mFOR_ATOMS)
                    + 4 * (getFIXED (mHALMAT_FIX_POPTAGxPOP_LOC)) + 0
                    + 4 * (0),
                numberRHS);
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
