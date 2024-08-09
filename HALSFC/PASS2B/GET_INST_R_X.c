/*
  File GET_INST_R_X.c generated by XCOM-I, 2024-08-09 12:41:33.
*/

#include "runtimeC.h"

descriptor_t *
GET_INST_R_X (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_INST_R_X");
  // R = SHR(RHS, 4) & RM; (14374)
  {
    int32_t numberRHS
        = (int32_t)(xAND (SHR (COREHALFWORD (mRHS), 4), getFIXED (mRM)));
    putFIXED (mR, numberRHS);
  }
  // IX = RHS & RM; (14375)
  {
    int32_t numberRHS = (int32_t)(xAND (COREHALFWORD (mRHS), getFIXED (mRM)));
    putFIXED (mIX, numberRHS);
  }
  // IA = SHR(RHS, 3) & 1; (14376)
  {
    int32_t numberRHS = (int32_t)(xAND (SHR (COREHALFWORD (mRHS), 3), 1));
    putFIXED (mIA, numberRHS);
  }
  // INST = SHR(RHS, 8) &  255; (14377)
  {
    int32_t numberRHS = (int32_t)(xAND (SHR (COREHALFWORD (mRHS), 8), 255));
    putFIXED (mINST, numberRHS);
  }
  // F = SHR(RHS, 7) & 1; (14378)
  {
    int32_t numberRHS = (int32_t)(xAND (SHR (COREHALFWORD (mRHS), 7), 1));
    putFIXED (mF, numberRHS);
  }
  // AM = 0; (14379)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mAM, numberRHS);
  }
  // RETURN AP101INST(INST); (14380)
  {
    reentryGuard = 0;
    return getBIT (16, mAP101INST + 2 * getFIXED (mINST));
  }
}
