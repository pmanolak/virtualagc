/*
  File UNSPEC.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
UNSPEC (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "UNSPEC");
  // RETURN F; (1513)
  {
    reentryGuard = 0;
    return getFIXED (mUNSPECxF);
  }
}