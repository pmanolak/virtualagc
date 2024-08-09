/*
  File GENERATExCHAR_CONVERT.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExCHAR_CONVERT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExCHAR_CONVERT");
  // IF SIZE(OP) < 0 THEN (7558)
  if (1
      & (xLT (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExCHAR_CONVERTxOP))
                            + 48 + 2 * (0)),
              0)))
    // SIZE(OP) = 255; (7559)
    {
      int32_t numberRHS = (int32_t)(255);
      putBIT (16,
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExCHAR_CONVERTxOP)) + 48
                  + 2 * (0),
              fixedToBit (16, numberRHS));
    }
  // PTR = GETFREESPACE(CHAR, SIZE(OP) + 2); (7560)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (mGENERATExGETFREESPACExOPTYPE, BYTE0 (mCHAR)),
        putFIXED (mGENERATExGETFREESPACExTEMPSPACE,
                  xadd (COREHALFWORD (
                            getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExCHAR_CONVERTxOP))
                            + 48 + 2 * (0)),
                        2)),
        GENERATExGETFREESPACE (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExCHAR_CONVERTxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL CHAR_CALL(XXASN, PTR, OP, 0); (7561)
  {
    putBITp (16, mGENERATExCHAR_CALLxOPCODE, getBIT (8, mXXASN));
    putBITp (16, mGENERATExCHAR_CALLxOP0,
             getBIT (16, mGENERATExCHAR_CONVERTxPTR));
    putBITp (16, mGENERATExCHAR_CALLxOP1,
             getBIT (16, mGENERATExCHAR_CONVERTxOP));
    putBITp (16, mGENERATExCHAR_CALLxOP2, fixedToBit (32, (int32_t)(0)));
    GENERATExCHAR_CALL (0);
  }
  // SIZE(PTR) = SIZE(OP); (7562)
  {
    descriptor_t *bitRHS
        = getBIT (16, getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExCHAR_CONVERTxOP))
                          + 48 + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExCHAR_CONVERTxPTR)) + 48
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL DROPSAVE(OP); (7563)
  {
    putBITp (16, mGENERATExDROPSAVExENTRY,
             getBIT (16, mGENERATExCHAR_CONVERTxOP));
    GENERATExDROPSAVE (0);
  }
  // CALL RETURN_STACK_ENTRY(OP); (7564)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
             getBIT (16, mGENERATExCHAR_CONVERTxOP));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  // RETURN PTR; (7565)
  {
    reentryGuard = 0;
    return getBIT (16, mGENERATExCHAR_CONVERTxPTR);
  }
}
