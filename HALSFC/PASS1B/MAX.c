/*
  File MAX.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
MAX (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "MAX");
  // IF I>J THEN (1054)
  if (1 & (xGT (getFIXED (mMAXxI), getFIXED (mMAXxJ))))
    // RETURN I; (1055)
    {
      reentryGuard = 0;
      return getFIXED (mMAXxI);
    }
  // RETURN J; (1056)
  {
    reentryGuard = 0;
    return getFIXED (mMAXxJ);
  }
}
