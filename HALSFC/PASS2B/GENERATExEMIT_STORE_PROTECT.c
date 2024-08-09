/*
  File GENERATExEMIT_STORE_PROTECT.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExEMIT_STORE_PROTECT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExEMIT_STORE_PROTECT");
  // CALL EMITC(SPSET, ON_OR_OFF); (9018)
  {
    putBITp (16, mEMITCxTYPE, getBIT (16, mSPSET));
    putBITp (16, mEMITCxINST,
             getBIT (1, mGENERATExEMIT_STORE_PROTECTxON_OR_OFF));
    EMITC (0);
  }
  // CURR_STORE_PROTECT = ON_OR_OFF; (9019)
  {
    descriptor_t *bitRHS = getBIT (1, mGENERATExEMIT_STORE_PROTECTxON_OR_OFF);
    putBIT (1, mCURR_STORE_PROTECT, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
