/*
  File REVERSE_PARITY.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
REVERSE_PARITY (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "REVERSE_PARITY");
  // RETURN (WORD &  4293918719) | ~WORD &  1048576; (1666)
  {
    reentryGuard = 0;
    return xOR (xAND (getFIXED (mREVERSE_PARITYxWORD), 4293918719),
                xAND (xNOT (getFIXED (mREVERSE_PARITYxWORD)), 1048576));
  }
}
