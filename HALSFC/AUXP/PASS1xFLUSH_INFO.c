/*
  File PASS1xFLUSH_INFO.c generated by XCOM-I, 2024-08-09 12:39:13.
*/

#include "runtimeC.h"

int32_t
PASS1xFLUSH_INFO (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PASS1xFLUSH_INFO");
  // CALL ZAPPER(FLUSH_FLAG); (1653)
  {
    putBITp (8, mPASS1xZAPPERxZAP_TYPE, fixedToBit (32, (int32_t)(4)));
    PASS1xZAPPER (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
