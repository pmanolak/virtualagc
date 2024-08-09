/*
  File PUT_BFNC_TWIN.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
PUT_BFNC_TWIN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PUT_BFNC_TWIN");
  // OPR(PTR) = SINCOS + SHL((OPTYPE ~= SINOP),24); (4505)
  {
    int32_t numberRHS = (int32_t)(xadd (
        getFIXED (mSINCOS),
        SHL (xNEQ (COREHALFWORD (mOPTYPE), COREHALFWORD (mSINOP)), 24)));
    putFIXED (mOPR + 4 * (COREHALFWORD (mPUT_BFNC_TWINxPTR)), numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
