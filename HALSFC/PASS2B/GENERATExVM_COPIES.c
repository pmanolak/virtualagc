/*
  File GENERATExVM_COPIES.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExVM_COPIES (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExVM_COPIES");
  // IF PACKTYPE(TYPE(PTR)) = VECMAT THEN (6201)
  if (1
      & (xEQ (BYTE0 (mPACKTYPE
                     + 1
                           * COREHALFWORD (
                               getFIXED (mIND_STACK)
                               + 73 * (COREHALFWORD (mGENERATExVM_COPIESxPTR))
                               + 50 + 2 * (0))),
              BYTE0 (mVECMAT))))
    // IF VDLP_IN_EFFECT & DOFORM(CALL_LEVEL) = 0 THEN (6202)
    if (1
        & (xAND (BYTE0 (mVDLP_IN_EFFECT),
                 xEQ (COREHALFWORD (mGENERATExDOFORM
                                    + 2 * COREHALFWORD (mCALL_LEVEL)),
                      0))))
      // DO; (6203)
      {
      rs1:;
        // IF SHR(TAG2(N),1) THEN (6204)
        if (1
            & (SHR (COREHALFWORD (mTAG2
                                  + 2 * COREHALFWORD (mGENERATExVM_COPIESxN)),
                    1)))
          // DO; (6205)
          {
          rs1s1:;
            // IF TAG1 = VAC THEN (6206)
            if (1 & (xEQ (COREHALFWORD (mTAG1), BYTE0 (mVAC))))
              // VMCOPY(PTR) = VMCOPY(PTR) | OP1 < DOCTR(CALL_LEVEL); (6207)
              {
                int32_t numberRHS = (int32_t)(xOR (
                    BYTE0 (getFIXED (mIND_STACK)
                           + 73 * (COREHALFWORD (mGENERATExVM_COPIESxPTR)) + 67
                           + 1 * (0)),
                    xLT (COREHALFWORD (mOP1),
                         COREHALFWORD (mGENERATExDOCTR
                                       + 2 * COREHALFWORD (mCALL_LEVEL)))));
                putBIT (8,
                        getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExVM_COPIESxPTR))
                            + 67 + 1 * (0),
                        fixedToBit (8, numberRHS));
              }
            // ELSE (6208)
            else
              // VMCOPY(PTR) = 1; (6209)
              {
                int32_t numberRHS = (int32_t)(1);
                putBIT (8,
                        getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExVM_COPIESxPTR))
                            + 67 + 1 * (0),
                        fixedToBit (8, numberRHS));
              }
            // VDLP_ACTIVE = TRUE; (6210)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mVDLP_ACTIVE, bitRHS);
              bitRHS->inUse = 0;
            }
          es1s1:;
          } // End of DO block
        // ELSE (6211)
        else
          // VMCOPY(PTR) = 0; (6212)
          {
            int32_t numberRHS = (int32_t)(0);
            putBIT (8,
                    getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExVM_COPIESxPTR)) + 67
                        + 1 * (0),
                    fixedToBit (8, numberRHS));
          }
      es1:;
      } // End of DO block
    // ELSE (6213)
    else
      // VMCOPY(PTR) = 0; (6214)
      {
        int32_t numberRHS = (int32_t)(0);
        putBIT (8,
                getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExVM_COPIESxPTR)) + 67
                    + 1 * (0),
                fixedToBit (8, numberRHS));
      }
  {
    reentryGuard = 0;
    return 0;
  }
}
