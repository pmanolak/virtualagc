/*
  File FORM_VAC.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
FORM_VAC (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "FORM_VAC");
  // TMP = TERMINAL_VAC | PTR | SHL(PARITY,20); (2000)
  {
    int32_t numberRHS = (int32_t)(xOR (
        xOR (getFIXED (mTERMINAL_VAC), COREHALFWORD (mFORM_VACxPTR)),
        SHL (BYTE0 (mFORM_VACxPARITY), 20)));
    putFIXED (mFORM_VACxTMP, numberRHS);
  }
  // PARITY = 0; (2001)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mFORM_VACxPARITY, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN TMP; (2002)
  {
    reentryGuard = 0;
    return getFIXED (mFORM_VACxTMP);
  }
}
