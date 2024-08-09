/*
  File ASSIGN_TYPE.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

descriptor_t *
ASSIGN_TYPE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ASSIGN_TYPE");
  // OP = SHR(OPR(PTR),4) &  4095; (1609)
  {
    int32_t numberRHS = (int32_t)(xAND (
        SHR (getFIXED (mOPR + 4 * COREHALFWORD (mASSIGN_TYPExPTR)), 4), 4095));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mASSIGN_TYPExOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF (OP &  3840) = 0 THEN (1610)
  if (1 & (xEQ (xAND (COREHALFWORD (mASSIGN_TYPExOP), 3840), 0)))
    // RETURN OP = TASN; (1611)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(xEQ (COREHALFWORD (mASSIGN_TYPExOP),
                                            COREHALFWORD (mTASN))));
    }
  // IF (OP &  255) ~=  1 THEN (1612)
  if (1 & (xNEQ (xAND (COREHALFWORD (mASSIGN_TYPExOP), 255), 1)))
    // RETURN FALSE; (1613)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(0));
    }
  // RETURN (OP &  3840) ~=  2048; (1614)
  {
    reentryGuard = 0;
    return fixedToBit (
        32,
        (int32_t)(xNEQ (xAND (COREHALFWORD (mASSIGN_TYPExOP), 3840), 2048)));
  }
}
