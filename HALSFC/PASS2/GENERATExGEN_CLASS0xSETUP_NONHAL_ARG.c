/*
  File GENERATExGEN_CLASS0xSETUP_NONHAL_ARG.c generated by XCOM-I, 2024-08-09
  12:39:31.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExGEN_CLASS0xSETUP_NONHAL_ARG (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS0xSETUP_NONHAL_ARG");
  // IF COPY(OP) = 0 THEN (11453)
  if (1
      & (xEQ (
          COREHALFWORD (
              getFIXED (mIND_STACK)
              + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
              + 26 + 2 * (0)),
          0)))
    // DO CASE PACKTYPE(TYPE(OP)); (11454)
    {
    rs1:
      switch (
          BYTE0 (mPACKTYPE
                 + 1
                       * COREHALFWORD (
                           getFIXED (mIND_STACK)
                           + 73
                                 * (COREHALFWORD (
                                     mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                           + 50 + 2 * (0))))
        {
        case 0:
          // DO; (11456)
          {
          rs1s1:;
            // IF CHECK_REMOTE(OP) | DEL(OP) > 0 THEN (11456)
            if (1
                & (xOR (
                    bitToFixed ((
                        putBITp (
                            16, mGENERATExCHECK_REMOTExOP,
                            getBIT (16,
                                    mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                        GENERATExCHECK_REMOTE (0))),
                    xGT (
                        COREHALFWORD (
                            getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                            + 28 + 2 * (0)),
                        0))))
              // OP = VECMAT_CONVERT(OP); (11457)
              {
                int32_t numberRHS = (int32_t)((
                    putBITp (
                        16, mGENERATExVECMAT_CONVERTxOP,
                        getBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                    GENERATExVECMAT_CONVERT (0)));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP, bitRHS);
                bitRHS->inUse = 0;
              }
            // IF DATA_REMOTE & (CSECT_TYPE(LOC(OP),OP)=LOCAL#D) THEN (11458)
            if (1
                & (xAND (
                    BYTE0 (mDATA_REMOTE),
                    xEQ (
                        bitToFixed ((
                            putBITp (
                                16, mCSECT_TYPExPTR,
                                getBIT (
                                    16,
                                    getFIXED (mIND_STACK)
                                        + 73
                                              * (COREHALFWORD (
                                                  mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                                        + 40 + 2 * (0))),
                            putBITp (
                                16, mCSECT_TYPExOP,
                                getBIT (
                                    16,
                                    mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                            CSECT_TYPE (0))),
                        6))))
              // OP = VECMAT_CONVERT(OP); (11459)
              {
                int32_t numberRHS = (int32_t)((
                    putBITp (
                        16, mGENERATExVECMAT_CONVERTxOP,
                        getBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                    GENERATExVECMAT_CONVERT (0)));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP, bitRHS);
                bitRHS->inUse = 0;
              }
            // INX_CON(OP) = INX_CON(OP) + BIGHTS(TYPE(OP)); (11460)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  getFIXED (
                      getFIXED (mIND_STACK)
                      + 73
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                      + 4 + 4 * (0)),
                  BYTE0 (
                      mBIGHTS
                      + 1
                            * COREHALFWORD (
                                getFIXED (mIND_STACK)
                                + 73
                                      * (COREHALFWORD (
                                          mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                                + 50 + 2 * (0)))));
              putFIXED (
                  getFIXED (mIND_STACK)
                      + 73
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                      + 4 + 4 * (0),
                  numberRHS);
            }
          es1s1:;
          } // End of DO block
          break;
        case 1:
          // IF COLUMN(OP)>0 | DEL(OP)~=0 | PACKFORM(FORM(OP))=2 THEN (11462)
          if (1
              & (xOR (
                  xOR (
                      xGT (
                          COREHALFWORD (
                              getFIXED (mIND_STACK)
                              + 73
                                    * (COREHALFWORD (
                                        mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                              + 24 + 2 * (0)),
                          0),
                      xNEQ (
                          COREHALFWORD (
                              getFIXED (mIND_STACK)
                              + 73
                                    * (COREHALFWORD (
                                        mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                              + 28 + 2 * (0)),
                          0)),
                  xEQ (
                      BYTE0 (
                          mPACKFORM
                          + 1
                                * COREHALFWORD (
                                    getFIXED (mIND_STACK)
                                    + 73
                                          * (COREHALFWORD (
                                              mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                                    + 32 + 2 * (0))),
                      2))))
            goto FORCE_NONHAL_TEMP;
          break;
        case 2:
          // IF CHECK_REMOTE(OP) | COLUMN(OP) > 0 THEN (11464)
          if (1
              & (xOR (
                  bitToFixed (
                      (putBITp (
                           16, mGENERATExCHECK_REMOTExOP,
                           getBIT (16,
                                   mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                       GENERATExCHECK_REMOTE (0))),
                  xGT (COREHALFWORD (
                           getFIXED (mIND_STACK)
                           + 73
                                 * (COREHALFWORD (
                                     mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                           + 24 + 2 * (0)),
                       0))))
            {
              descriptor_t *bitRHS
                  = (putBITp (
                         16, mGENERATExCHAR_CONVERTxOP,
                         getBIT (16,
                                 mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                     GENERATExCHAR_CONVERT (0));
              putBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP, bitRHS);
              bitRHS->inUse = 0;
            }
          else if (
              1
              & (xAND (
                  BYTE0 (mDATA_REMOTE),
                  xEQ (
                      bitToFixed ((
                          putBITp (
                              16, mCSECT_TYPExPTR,
                              getBIT (
                                  16,
                                  getFIXED (mIND_STACK)
                                      + 73
                                            * (COREHALFWORD (
                                                mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                                      + 40 + 2 * (0))),
                          putBITp (
                              16, mCSECT_TYPExOP,
                              getBIT (
                                  16,
                                  mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                          CSECT_TYPE (0))),
                      6))))
            {
              descriptor_t *bitRHS
                  = (putBITp (
                         16, mGENERATExCHAR_CONVERTxOP,
                         getBIT (16,
                                 mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP)),
                     GENERATExCHAR_CONVERT (0));
              putBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP, bitRHS);
              bitRHS->inUse = 0;
            }
          break;
        case 3:
          // IF CONST(OP) ~= 0 | PACKFORM(FORM(OP)) = 2 THEN (11469)
          if (1
              & (xOR (
                  xNEQ (
                      getFIXED (
                          getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                          + 0 + 4 * (0)),
                      0),
                  xEQ (
                      BYTE0 (
                          mPACKFORM
                          + 1
                                * COREHALFWORD (
                                    getFIXED (mIND_STACK)
                                    + 73
                                          * (COREHALFWORD (
                                              mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                                    + 32 + 2 * (0))),
                      2))))
            {
            rs1s2:;
            // FORCE_NONHAL_TEMP: (11470)
            FORCE_NONHAL_TEMP:
              // CALL FORCE_ACCUMULATOR(OP); (11471)
              {
                putBITp (
                    16, mGENERATExFORCE_ACCUMULATORxOP,
                    getBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP));
                GENERATExFORCE_ACCUMULATOR (0);
              }
              // CALL CHECKPOINT_REG(REG(OP), TRUE); (11472)
              {
                putBITp (
                    16, mGENERATExCHECKPOINT_REGxR,
                    getBIT (
                        16,
                        getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP))
                            + 46 + 2 * (0)));
                putBITp (1, mGENERATExCHECKPOINT_REGxSAVE,
                         fixedToBit (32, (int32_t)(1)));
                GENERATExCHECKPOINT_REG (0);
              }
            es1s2:;
            } // End of DO block
          break;
        case 4:
            // ; (11474)
            ;
          break;
        }
    } // End of DO CASE block
  // ELSE (11474)
  else
    // CALL TRUE_INX(OP); (11475)
    {
      putBITp (16, mGENERATExTRUE_INXxOP,
               getBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP));
      GENERATExTRUE_INX (0);
    }
  // RETURN OP; (11476)
  {
    reentryGuard = 0;
    return getBIT (16, mGENERATExGEN_CLASS0xSETUP_NONHAL_ARGxOP);
  }
}
