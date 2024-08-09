/*
  File GENERATExCHECK_LINKREG.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExCHECK_LINKREG (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExCHECK_LINKREG");
  // IF R = LINKREG THEN (2939)
  if (1 & (xEQ (COREHALFWORD (mGENERATExCHECK_LINKREGxR), BYTE0 (mLINKREG))))
    // CALL NEED_STACK(NARGINDEX); (2940)
    {
      putBITp (16, mNEED_STACKxIX, getBIT (16, mNARGINDEX));
      NEED_STACK (0);
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
