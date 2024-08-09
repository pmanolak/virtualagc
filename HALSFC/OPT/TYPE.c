/*
  File TYPE.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

descriptor_t *
TYPE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "TYPE");
  // RETURN SHR(CSE_WORD,16) &  15; (2179)
  {
    reentryGuard = 0;
    return fixedToBit (
        32, (int32_t)(xAND (SHR (getFIXED (mTYPExCSE_WORD), 16), 15)));
  }
}
