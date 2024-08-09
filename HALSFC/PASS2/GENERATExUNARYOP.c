/*
  File GENERATExUNARYOP.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExUNARYOP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExUNARYOP");
  // TO_BE_MODIFIED = TRUE; (6960)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExTO_BE_MODIFIED, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL FORCE_ACCUMULATOR(LEFTOP); (6961)
  {
    putBITp (16, mGENERATExFORCE_ACCUMULATORxOP, getBIT (16, mLEFTOP));
    GENERATExFORCE_ACCUMULATOR (0);
  }
  // IF OPCODE = XNOT THEN (6962)
  if (1 & (xEQ (COREHALFWORD (mGENERATExUNARYOPxOPCODE), BYTE0 (mXNOT))))
    // CALL BIT_MASK(XNOT, LEFTOP, SIZE(LEFTOP)); (6963)
    {
      putBITp (16, mGENERATExBIT_MASKxOPCODE, getBIT (8, mXNOT));
      putBITp (16, mGENERATExBIT_MASKxOP, getBIT (16, mLEFTOP));
      putBITp (16, mGENERATExBIT_MASKxXSIZE,
               getBIT (16, getFIXED (mIND_STACK)
                               + 73 * (COREHALFWORD (mLEFTOP)) + 48
                               + 2 * (0)));
      GENERATExBIT_MASK (0);
    }
  // ELSE (6964)
  else
    // CALL ARITH_BY_MODE(OPCODE, LEFTOP, LEFTOP, OPTYPE); (6965)
    {
      putBITp (16, mGENERATExARITH_BY_MODExOP,
               getBIT (16, mGENERATExUNARYOPxOPCODE));
      putBITp (16, mGENERATExARITH_BY_MODExOP1, getBIT (16, mLEFTOP));
      putBITp (16, mGENERATExARITH_BY_MODExOP2, getBIT (16, mLEFTOP));
      putBITp (16, mGENERATExARITH_BY_MODExOPTYPE, getBIT (16, mOPTYPE));
      GENERATExARITH_BY_MODE (0);
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
