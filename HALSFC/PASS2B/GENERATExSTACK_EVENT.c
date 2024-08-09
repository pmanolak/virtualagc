/*
  File GENERATExSTACK_EVENT.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExSTACK_EVENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExSTACK_EVENT");
  // IF EV_EXPTR > EV_EXPTR_MAX THEN (8674)
  if (1 & (xGT (COREHALFWORD (mGENERATExEV_EXPTR), 15)))
    // CALL ERRORS(CLASS_E,100); (8675)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_E));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(100)));
      ERRORS (0);
    }
  // EV_EXP(EV_EXPTR) = TOKEN; (8676)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExSTACK_EVENTxTOKEN);
    putBIT (8, mGENERATExEV_EXP + 1 * (COREHALFWORD (mGENERATExEV_EXPTR)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // EV_EXPTR = EV_EXPTR + 1; (8677)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mGENERATExEV_EXPTR), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExEV_EXPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
