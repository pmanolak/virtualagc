/*
  File ADD_INITIALIZED_NAME_VAR.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

int32_t
ADD_INITIALIZED_NAME_VAR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ADD_INITIALIZED_NAME_VAR");
  // INIT_NAME_HOLDER = SYT_NO; (1258)
  {
    descriptor_t *bitRHS = getBIT (16, mADD_INITIALIZED_NAME_VARxSYT_NO);
    putBIT (16, mINIT_NAME_HOLDER, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
