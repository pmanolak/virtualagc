/*
  File GENERATExGEN_CLASS0xPUSH_ENVIRONMENT.c generated by XCOM-I, 2024-08-09
  12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xPUSH_ENVIRONMENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS0xPUSH_ENVIRONMENT");
  // PTR = AUX_LOCATE(AUX_CTR, CTR, 7); (12692)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (mGENERATExAUX_LOCATExPTR, getFIXED (mAUX_CTR)),
        putFIXED (mGENERATExAUX_LOCATExLINE, COREHALFWORD (mCTR)),
        putFIXED (mGENERATExAUX_LOCATExOP, 7), GENERATExAUX_LOCATE (0)));
    putFIXED (mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxPTR, numberRHS);
  }
  // CALL CLEAR_STMT_REGS; (12693)
  GENERATExGEN_CLASS0xCLEAR_STMT_REGS (0);
  // ENV_PTR = (ENV_PTR + 1) MOD (ENV_NUM+1); (12694)
  {
    int32_t numberRHS = (int32_t)(xmod (xadd (COREHALFWORD (mENV_PTR), 1), 3));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mENV_PTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // ENV_LBL(ENV_PTR) = LBL; (12695)
  {
    descriptor_t *bitRHS
        = getBIT (16, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxLBL);
    putBIT (16, mENV_LBL + 2 * (COREHALFWORD (mENV_PTR)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IF PTR >= 0 THEN (12696)
  if (1 & (xGE (getFIXED (mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxPTR), 0)))
    // DO; (12697)
    {
    rs1:;
      // CALL AUX_DECODE(PTR); (12698)
      {
        putFIXED (mGENERATExAUX_DECODExCTR,
                  getFIXED (mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxPTR));
        GENERATExAUX_DECODE (0);
      }
      // NEST_OK = AUX_NEXT <= (ENV_NUM+1); (12699)
      {
        int32_t numberRHS
            = (int32_t)(xLE (COREHALFWORD (mGENERATExAUX_NEXT), 3));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxNEST_OK, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (12700)
  else
    // NEST_OK = FALSE; (12701)
    {
      int32_t numberRHS = (int32_t)(0);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (1, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxNEST_OK, bitRHS);
      bitRHS->inUse = 0;
    }
  // DO I = 0 TO REG_NUM; (12702)
  {
    int32_t from123, to123, by123;
    from123 = 0;
    to123 = 15;
    by123 = 1;
    for (putBIT (16, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI,
                 fixedToBit (16, from123));
         bitToFixed (getBIT (16, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI))
         <= to123;
         putBIT (
             16, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI,
             fixedToBit (16, bitToFixed (getBIT (
                                 16, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI))
                                 + by123)))
      {
        // DEFAULT = TRUE; (12703)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (1, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxDEFAULT, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF USAGE(I) THEN (12704)
        if (1
            & (bitToFixed (getBIT (
                16, mUSAGE
                        + 2
                              * COREHALFWORD (
                                  mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI)))))
          // DO; (12705)
          {
          rs2s1:;
            // PTR = AUX_SEARCH(I, 1); (12706)
            {
              int32_t numberRHS = (int32_t)((
                  putBITp (
                      16, mGENERATExAUX_SEARCHxR,
                      getBIT (16, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI)),
                  putBITp (16, mGENERATExAUX_SEARCHxCODE,
                           fixedToBit (32, (int32_t)(1))),
                  GENERATExAUX_SEARCH (0)));
              putFIXED (mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxPTR, numberRHS);
            }
            // IF PTR >= 0 THEN (12707)
            if (1
                & (xGE (getFIXED (mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxPTR),
                        0)))
              // DO; (12708)
              {
              rs2s1s1:;
                // CALL AUX_DECODE(PTR); (12709)
                {
                  putFIXED (
                      mGENERATExAUX_DECODExCTR,
                      getFIXED (mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxPTR));
                  GENERATExAUX_DECODE (0);
                }
                // IF USAGE(I)>1 & USAGE(I)<4 & R_CONTENTS(I)=VAC & FBRA &
                // ~SHR(AUX_TAG,1) THEN (12710)
                if (1
                    & (xAND (
                        xAND (
                            xAND (
                                xAND (
                                    xGT (
                                        COREHALFWORD (
                                            mUSAGE
                                            + 2
                                                  * COREHALFWORD (
                                                      mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI)),
                                        1),
                                    xLT (
                                        COREHALFWORD (
                                            mUSAGE
                                            + 2
                                                  * COREHALFWORD (
                                                      mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI)),
                                        4)),
                                xEQ (
                                    BYTE0 (
                                        mR_CONTENTS
                                        + 1
                                              * COREHALFWORD (
                                                  mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI)),
                                    BYTE0 (mVAC))),
                            BYTE0 (
                                mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxFBRA)),
                        xNOT (SHR (COREHALFWORD (mGENERATExAUX_TAG), 1)))))
                  // DO; (12711)
                  {
                  rs2s1s1s1:;
                    // IF AUX_TAG THEN (12712)
                    if (1 & (bitToFixed (getBIT (16, mGENERATExAUX_TAG))))
                      // DO; (12713)
                      {
                      rs2s1s1s1s1:;
                        // USAGE(ENV_BASE(ENV_PTR)+I) = 0; (12714)
                        {
                          int32_t numberRHS = (int32_t)(0);
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (
                              16,
                              mUSAGE
                                  + 2
                                        * (xadd (
                                            COREHALFWORD (
                                                mENV_BASE
                                                + 2 * COREHALFWORD (mENV_PTR)),
                                            COREHALFWORD (
                                                mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI))),
                              bitRHS);
                          bitRHS->inUse = 0;
                        }
                        // DEFAULT = FALSE; (12715)
                        {
                          int32_t numberRHS = (int32_t)(0);
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (
                              1, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxDEFAULT,
                              bitRHS);
                          bitRHS->inUse = 0;
                        }
                      es2s1s1s1s1:;
                      } // End of DO block
                    // ELSE (12716)
                    else
                      // IF AUX_NEXT = 0 & NEST_OK THEN (12717)
                      if (1
                          & (xAND (
                              xEQ (COREHALFWORD (mGENERATExAUX_NEXT), 0),
                              BYTE0 (
                                  mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxNEST_OK))))
                        // DO; (12718)
                        {
                        rs2s1s1s1s2:;
                          // CALL COPY_REG_INFO(I, ENV_BASE(ENV_PTR)+I,
                          // USAGE(I)); (12719)
                          {
                            putBITp (
                                16, mGENERATExCOPY_REG_INFOxRF,
                                getBIT (
                                    16,
                                    mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI));
                            putBITp (
                                16, mGENERATExCOPY_REG_INFOxRT,
                                fixedToBit (
                                    32,
                                    (int32_t)(xadd (
                                        COREHALFWORD (
                                            mENV_BASE
                                            + 2 * COREHALFWORD (mENV_PTR)),
                                        COREHALFWORD (
                                            mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI)))));
                            putBITp (
                                16, mGENERATExCOPY_REG_INFOxUSG,
                                getBIT (
                                    16,
                                    mUSAGE
                                        + 2
                                              * COREHALFWORD (
                                                  mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI)));
                            GENERATExCOPY_REG_INFO (0);
                          }
                          // USAGE(I) = 0; (12720)
                          {
                            int32_t numberRHS = (int32_t)(0);
                            descriptor_t *bitRHS;
                            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                            putBIT (
                                16,
                                mUSAGE
                                    + 2
                                          * (COREHALFWORD (
                                              mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI)),
                                bitRHS);
                            bitRHS->inUse = 0;
                          }
                          // DEFAULT = FALSE; (12721)
                          {
                            int32_t numberRHS = (int32_t)(0);
                            descriptor_t *bitRHS;
                            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                            putBIT (
                                1,
                                mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxDEFAULT,
                                bitRHS);
                            bitRHS->inUse = 0;
                          }
                          // STACK_PTR(FETCH_VAC(AUX_LOC,-1)) = 0; (12722)
                          {
                            int32_t numberRHS = (int32_t)(0);
                            descriptor_t *bitRHS;
                            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                            putBIT (
                                16,
                                mSTACK_PTR
                                    + 2
                                          * (bitToFixed (
                                              (putBITp (
                                                   16, mGENERATExFETCH_VACxOP,
                                                   getBIT (16,
                                                           mGENERATExAUX_LOC)),
                                               putBITp (
                                                   16, mGENERATExFETCH_VACxN,
                                                   fixedToBit (32,
                                                               (int32_t)(-1))),
                                               GENERATExFETCH_VAC (0)))),
                                bitRHS);
                            bitRHS->inUse = 0;
                          }
                        es2s1s1s1s2:;
                        } // End of DO block
                  es2s1s1s1:;
                  } // End of DO block
                // USAGE_LINE(I) = AUX_NEXT; (12723)
                {
                  descriptor_t *bitRHS = getBIT (16, mGENERATExAUX_NEXT);
                  putBIT (
                      16,
                      mUSAGE_LINE
                          + 2
                                * (COREHALFWORD (
                                    mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI)),
                      bitRHS);
                  bitRHS->inUse = 0;
                }
              es2s1s1:;
              } // End of DO block
          es2s1:;
          } // End of DO block
        // IF DEFAULT THEN (12724)
        if (1
            & (bitToFixed (
                getBIT (1, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxDEFAULT))))
          // DO; (12725)
          {
          rs2s2:;
            // CALL CHECKPOINT_REG(I, TRUE); (12726)
            {
              putBITp (16, mGENERATExCHECKPOINT_REGxR,
                       getBIT (16, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI));
              putBITp (1, mGENERATExCHECKPOINT_REGxSAVE,
                       fixedToBit (32, (int32_t)(1)));
              GENERATExCHECKPOINT_REG (0);
            }
            // CALL COPY_REG_INFO(I, ENV_BASE(ENV_PTR)+I, 0); (12727)
            {
              putBITp (16, mGENERATExCOPY_REG_INFOxRF,
                       getBIT (16, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI));
              putBITp (
                  16, mGENERATExCOPY_REG_INFOxRT,
                  fixedToBit (
                      32, (int32_t)(xadd (
                              COREHALFWORD (mENV_BASE
                                            + 2 * COREHALFWORD (mENV_PTR)),
                              COREHALFWORD (
                                  mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxI)))));
              putBITp (16, mGENERATExCOPY_REG_INFOxUSG,
                       fixedToBit (32, (int32_t)(0)));
              GENERATExCOPY_REG_INFO (0);
            }
          es2s2:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // LAST_FLOW_BLK = CURCBLK; (12728)
  {
    descriptor_t *bitRHS = getBIT (8, mCURCBLK);
    putBIT (16, mLAST_FLOW_BLK, bitRHS);
    bitRHS->inUse = 0;
  }
  // LAST_FLOW_CTR = CTR; (12729)
  {
    descriptor_t *bitRHS = getBIT (16, mCTR);
    putBIT (16, mLAST_FLOW_CTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // FBRA = FALSE; (12730)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExGEN_CLASS0xPUSH_ENVIRONMENTxFBRA, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
