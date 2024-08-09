/*
  File MIN.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
MIN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "MIN");
  // IF I<J THEN (1051)
  if (1 & (xLT (getFIXED (mMINxI), getFIXED (mMINxJ))))
    // RETURN I; (1052)
    {
      reentryGuard = 0;
      return getFIXED (mMINxI);
    }
  // RETURN J; (1053)
  {
    reentryGuard = 0;
    return getFIXED (mMINxJ);
  }
}
