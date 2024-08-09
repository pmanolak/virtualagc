/*
  File GENERATExSET_EVENT_OPERAND.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExSET_EVENT_OPERAND (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExSET_EVENT_OPERAND");
  // EV_PTR = EV_PTR + 1; (8678)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mGENERATExEV_PTR), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExEV_PTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF EV_PTR > EV_PTR_MAX THEN (8679)
  if (1 & (xGT (COREHALFWORD (mGENERATExEV_PTR), 5)))
    // CALL ERRORS(CLASS_E,101); (8680)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_E));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(101)));
      ERRORS (0);
    }
  // EV_OP(EV_PTR) = OP; (8681)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExSET_EVENT_OPERANDxOP);
    putBIT (16, mGENERATExEV_OP + 2 * (COREHALFWORD (mGENERATExEV_PTR)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL STACK_EVENT(0); (8682)
  {
    putBITp (16, mGENERATExSTACK_EVENTxTOKEN, fixedToBit (32, (int32_t)(0)));
    GENERATExSTACK_EVENT (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
