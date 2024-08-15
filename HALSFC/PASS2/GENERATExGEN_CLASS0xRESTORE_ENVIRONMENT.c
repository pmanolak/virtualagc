/*
  File GENERATExGEN_CLASS0xRESTORE_ENVIRONMENT.c generated by XCOM-I,
  2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xRESTORE_ENVIRONMENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS0xRESTORE_ENVIRONMENT");
  // IF ENV_LBL(ENV_PTR) = LBL THEN (12731)
  if (1
      & (xEQ (COREHALFWORD (mENV_LBL + 2 * COREHALFWORD (mENV_PTR)),
              COREHALFWORD (mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxLBL))))
    // DO; (12732)
    {
    rs1:;
      // DO I = 0 TO REG_NUM; (12733)
      {
        int32_t from124, to124, by124;
        from124 = 0;
        to124 = 15;
        by124 = 1;
        for (putBIT (16, mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI,
                     fixedToBit (16, from124));
             bitToFixed (
                 getBIT (16, mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI))
             <= to124;
             putBIT (
                 16, mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI,
                 fixedToBit (
                     16, bitToFixed (getBIT (
                             16, mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI))
                             + by124)))
          {
            // IF LBL2 > 0 THEN (12734)
            if (1
                & (xGT (COREHALFWORD (
                            mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxLBL2),
                        0)))
              // CALL SWAP_REG_INFO(ENV_BASE(ENV_PTR) + I, I,
              // USAGE(ENV_BASE(ENV_PTR) + I)); (12735)
              {
                putBITp (
                    16, mGENERATExSWAP_REG_INFOxRF,
                    fixedToBit (
                        32,
                        (int32_t)(xadd (
                            COREHALFWORD (mENV_BASE
                                          + 2 * COREHALFWORD (mENV_PTR)),
                            COREHALFWORD (
                                mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI)))));
                putBITp (
                    16, mGENERATExSWAP_REG_INFOxRT,
                    getBIT (16, mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI));
                putBITp (
                    16, mGENERATExSWAP_REG_INFOxUSG,
                    getBIT (
                        16,
                        mUSAGE
                            + 2
                                  * xadd (
                                      COREHALFWORD (
                                          mENV_BASE
                                          + 2 * COREHALFWORD (mENV_PTR)),
                                      COREHALFWORD (
                                          mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI))));
                GENERATExSWAP_REG_INFO (0);
              }
            // ELSE (12736)
            else
              // CALL COPY_REG_INFO(ENV_BASE(ENV_PTR) + I, I,
              // USAGE(ENV_BASE(ENV_PTR) + I)); (12737)
              {
                putBITp (
                    16, mGENERATExCOPY_REG_INFOxRF,
                    fixedToBit (
                        32,
                        (int32_t)(xadd (
                            COREHALFWORD (mENV_BASE
                                          + 2 * COREHALFWORD (mENV_PTR)),
                            COREHALFWORD (
                                mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI)))));
                putBITp (
                    16, mGENERATExCOPY_REG_INFOxRT,
                    getBIT (16, mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI));
                putBITp (
                    16, mGENERATExCOPY_REG_INFOxUSG,
                    getBIT (
                        16,
                        mUSAGE
                            + 2
                                  * xadd (
                                      COREHALFWORD (
                                          mENV_BASE
                                          + 2 * COREHALFWORD (mENV_PTR)),
                                      COREHALFWORD (
                                          mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI))));
                GENERATExCOPY_REG_INFO (0);
              }
            // IF USAGE(I) THEN (12738)
            if (1
                & (bitToFixed (getBIT (
                    16,
                    mUSAGE
                        + 2
                              * COREHALFWORD (
                                  mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI)))))
              // DO; (12739)
              {
              rs1s1s1:;
                // PTR = AUX_SEARCH(I, 1); (12740)
                {
                  int32_t numberRHS = (int32_t)((
                      putBITp (
                          16, mGENERATExAUX_SEARCHxR,
                          getBIT (16,
                                  mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI)),
                      putBITp (16, mGENERATExAUX_SEARCHxCODE,
                               fixedToBit (32, (int32_t)(1))),
                      GENERATExAUX_SEARCH (0)));
                  putFIXED (mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxPTR,
                            numberRHS);
                }
                // IF PTR >= 0 THEN (12741)
                if (1
                    & (xGE (getFIXED (
                                mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxPTR),
                            0)))
                  // DO; (12742)
                  {
                  rs1s1s1s1:;
                    // CALL AUX_DECODE(PTR); (12743)
                    {
                      putFIXED (
                          mGENERATExAUX_DECODExCTR,
                          getFIXED (
                              mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxPTR));
                      GENERATExAUX_DECODE (0);
                    }
                    // USAGE_LINE(I) = AUX_NEXT; (12744)
                    {
                      descriptor_t *bitRHS = getBIT (16, mGENERATExAUX_NEXT);
                      putBIT (
                          16,
                          mUSAGE_LINE
                              + 2
                                    * (COREHALFWORD (
                                        mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI)),
                          bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // IF AUX_NEXT > 0 THEN (12745)
                    if (1 & (xGT (COREHALFWORD (mGENERATExAUX_NEXT), 0)))
                      // IF R_CONTENTS(I) = VAC THEN (12746)
                      if (1
                          & (xEQ (
                              BYTE0 (
                                  mR_CONTENTS
                                  + 1
                                        * COREHALFWORD (
                                            mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxI)),
                              BYTE0 (mVAC))))
                        // STACK_PTR(FETCH_VAC(AUX_LOC,-1)) = -1; (12747)
                        {
                          int32_t numberRHS = (int32_t)(-1);
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (
                              16,
                              mSTACK_PTR
                                  + 2
                                        * (bitToFixed ((
                                            putBITp (
                                                16, mGENERATExFETCH_VACxOP,
                                                getBIT (16,
                                                        mGENERATExAUX_LOC)),
                                            putBITp (16, mGENERATExFETCH_VACxN,
                                                     fixedToBit (
                                                         32, (int32_t)(-1))),
                                            GENERATExFETCH_VAC (0)))),
                              bitRHS);
                          bitRHS->inUse = 0;
                        }
                  es1s1s1s1:;
                  } // End of DO block
              es1s1s1:;
              } // End of DO block
          }
      } // End of DO for-loop block
      // IF LBL2 > 0 THEN (12748)
      if (1
          & (xGT (COREHALFWORD (mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxLBL2),
                  0)))
        // ENV_LBL(ENV_PTR) = LBL2; (12749)
        {
          descriptor_t *bitRHS
              = getBIT (16, mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxLBL2);
          putBIT (16, mENV_LBL + 2 * (COREHALFWORD (mENV_PTR)), bitRHS);
          bitRHS->inUse = 0;
        }
    es1:;
    } // End of DO block
  // ELSE (12750)
  else
    // CALL CLEAR_REGS; (12751)
    CLEAR_REGS (0);
  // LBL2 = 0; (12752)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGEN_CLASS0xRESTORE_ENVIRONMENTxLBL2, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}