/*
  File GENERATExBIT_PICK.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExBIT_PICK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExBIT_PICK");
  // IF CVTTYPE(TYPE(OP)) THEN (5451)
  if (1
      & (bitToFixed (getBIT (
          8, mCVTTYPE
                 + 1
                       * COREHALFWORD (
                           getFIXED (mIND_STACK)
                           + 73 * (COREHALFWORD (mGENERATExBIT_PICKxOP)) + 50
                           + 2 * (0))))))
    // RETURN COLUMN(OP); (5452)
    {
      reentryGuard = 0;
      return COREHALFWORD (getFIXED (mIND_STACK)
                           + 73 * (COREHALFWORD (mGENERATExBIT_PICKxOP)) + 24
                           + 2 * (0));
    }
  // RETURN 0; (5453)
  {
    reentryGuard = 0;
    return 0;
  }
}
