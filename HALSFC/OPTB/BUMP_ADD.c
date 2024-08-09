/*
  File BUMP_ADD.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
BUMP_ADD (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "BUMP_ADD");
  // A_INX = A_INX + 1; (2025)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mA_INX), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mA_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // ADD(A_INX) = PTR; (2026)
  {
    descriptor_t *bitRHS = getBIT (16, mBUMP_ADDxPTR);
    putBIT (16, mADD + 2 * (COREHALFWORD (mA_INX)), bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
