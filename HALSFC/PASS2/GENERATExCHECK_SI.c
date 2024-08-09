/*
  File GENERATExCHECK_SI.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExCHECK_SI (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExCHECK_SI");
  // IF FORM(OP) = IMD THEN (5181)
  if (1
      & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP)) + 32
                            + 2 * (0)),
              BYTE0 (mIMD))))
    // RETURN TRUE; (5182)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(1));
    }
  // IF CHECK_REMOTE(OP) THEN (5183)
  if (1
      & (bitToFixed ((putBITp (16, mGENERATExCHECK_REMOTExOP,
                               getBIT (16, mGENERATExCHECK_SIxOP)),
                      GENERATExCHECK_REMOTE (0)))))
    // RETURN FALSE; (5184)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(0));
    }
  // IF FORM(OP) ~= EXTSYM THEN (5185)
  if (1
      & (xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP)) + 32
                             + 2 * (0)),
               BYTE0 (mEXTSYM))))
    // IF FORM(OP) ~= INL THEN (5186)
    if (1
        & (xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                               + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP))
                               + 32 + 2 * (0)),
                 BYTE0 (mINL))))
      // DO CASE PACKFORM(FORM(OP)); (5187)
      {
      rs1:
        switch (BYTE0 (
            mPACKFORM
            + 1
                  * COREHALFWORD (getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP))
                                  + 32 + 2 * (0))))
          {
          case 0:
            // IF CHECK_SRS(INST,INX(OP),SYT_BASE(LOC(OP)),
            // SYT_DISP(LOC(OP))+INX_CON(OP)) = SRSTYPE THEN (5189)
            if (1
                & (xEQ (
                    bitToFixed ((
                        putBITp (16, mCHECK_SRSxINST,
                                 getBIT (16, mGENERATExCHECK_SIxINST)),
                        putBITp (
                            16, mCHECK_SRSxIX,
                            getBIT (16, getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCHECK_SIxOP))
                                            + 34 + 2 * (0))),
                        putBITp (
                            16, mCHECK_SRSxBASE,
                            getBIT (
                                16,
                                getFIXED (mP2SYMS)
                                    + 12
                                          * (COREHALFWORD (
                                              getFIXED (mIND_STACK)
                                              + 73
                                                    * (COREHALFWORD (
                                                        mGENERATExCHECK_SIxOP))
                                              + 40 + 2 * (0)))
                                    + 4 + 2 * (0))),
                        putFIXED (
                            mCHECK_SRSxDISP,
                            xadd (
                                COREHALFWORD (
                                    getFIXED (mP2SYMS)
                                    + 12
                                          * (COREHALFWORD (
                                              getFIXED (mIND_STACK)
                                              + 73
                                                    * (COREHALFWORD (
                                                        mGENERATExCHECK_SIxOP))
                                              + 40 + 2 * (0)))
                                    + 6 + 2 * (0)),
                                getFIXED (getFIXED (mIND_STACK)
                                          + 73
                                                * (COREHALFWORD (
                                                    mGENERATExCHECK_SIxOP))
                                          + 4 + 4 * (0)))),
                        CHECK_SRS (0))),
                    BYTE0 (mSRSTYPE))))
              {
                reentryGuard = 0;
                return fixedToBit (32, (int32_t)(1));
              }
            break;
          case 1:
            // IF CHECK_SRS(INST,INX(OP),BASE(OP),DISP(OP)+INX_CON(OP)) =
            // SRSTYPE THEN (5191)
            if (1
                & (xEQ (
                    bitToFixed (
                        (putBITp (16, mCHECK_SRSxINST,
                                  getBIT (16, mGENERATExCHECK_SIxINST)),
                         putBITp (
                             16, mCHECK_SRSxIX,
                             getBIT (16, getFIXED (mIND_STACK)
                                             + 73
                                                   * (COREHALFWORD (
                                                       mGENERATExCHECK_SIxOP))
                                             + 34 + 2 * (0))),
                         putBITp (
                             16, mCHECK_SRSxBASE,
                             getBIT (16, getFIXED (mIND_STACK)
                                             + 73
                                                   * (COREHALFWORD (
                                                       mGENERATExCHECK_SIxOP))
                                             + 22 + 2 * (0))),
                         putFIXED (
                             mCHECK_SRSxDISP,
                             xadd (COREHALFWORD (
                                       getFIXED (mIND_STACK)
                                       + 73
                                             * (COREHALFWORD (
                                                 mGENERATExCHECK_SIxOP))
                                       + 30 + 2 * (0)),
                                   getFIXED (getFIXED (mIND_STACK)
                                             + 73
                                                   * (COREHALFWORD (
                                                       mGENERATExCHECK_SIxOP))
                                             + 4 + 4 * (0)))),
                         CHECK_SRS (0))),
                    BYTE0 (mSRSTYPE))))
              {
                reentryGuard = 0;
                return fixedToBit (32, (int32_t)(1));
              }
            break;
          case 2:
            // RETURN FALSE; (5193)
            {
              reentryGuard = 0;
              return fixedToBit (32, (int32_t)(0));
            }
            break;
          }
      } // End of DO CASE block
  // IF INST = TB THEN (5193)
  if (1 & (xEQ (COREHALFWORD (mGENERATExCHECK_SIxINST), BYTE0 (mTB))))
    // IF INX(OP) ~= 0 THEN (5194)
    if (1
        & (xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                               + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP))
                               + 34 + 2 * (0)),
                 0)))
      // RETURN FALSE; (5195)
      {
        reentryGuard = 0;
        return fixedToBit (32, (int32_t)(0));
      }
  // IF SHR(NOT_LEAF(INDEXNEST),1) THEN (5196)
  if (1 & (SHR (BYTE0 (mNOT_LEAF + 1 * COREHALFWORD (mINDEXNEST)), 1)))
    // BREG = PTRARG1; (5197)
    {
      descriptor_t *bitRHS = getBIT (8, mPTRARG1);
      putBIT (16, mGENERATExCHECK_SIxBREG, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (5198)
  else
    // IF USAGE(PTRARG1) > USAGE(R3) THEN (5199)
    if (1
        & (xGT (COREHALFWORD (mUSAGE + 2 * BYTE0 (mPTRARG1)),
                COREHALFWORD (mUSAGE + 2 * BYTE0 (mR3)))))
      // BREG = R3; (5200)
      {
        descriptor_t *bitRHS = getBIT (8, mR3);
        putBIT (16, mGENERATExCHECK_SIxBREG, bitRHS);
        bitRHS->inUse = 0;
      }
    // ELSE (5201)
    else
      // BREG = PTRARG1; (5202)
      {
        descriptor_t *bitRHS = getBIT (8, mPTRARG1);
        putBIT (16, mGENERATExCHECK_SIxBREG, bitRHS);
        bitRHS->inUse = 0;
      }
  // IF DATA_REMOTE THEN (5203)
  if (1 & (bitToFixed (getBIT (1, mDATA_REMOTE))))
    // BREG = REG_STAT(OP,BREG,LOADADDR); (5204)
    {
      descriptor_t *bitRHS = (putBITp (16, mGENERATExREG_STATxOP,
                                       getBIT (16, mGENERATExCHECK_SIxOP)),
                              putBITp (16, mGENERATExREG_STATxR,
                                       getBIT (16, mGENERATExCHECK_SIxBREG)),
                              putBITp (8, mGENERATExREG_STATxTYPE_LOAD,
                                       fixedToBit (32, (int32_t)(3))),
                              GENERATExREG_STAT (0));
      putBIT (16, mGENERATExCHECK_SIxBREG, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF USAGE(BREG) > 1 THEN (5205)
  if (1
      & (xGT (
          COREHALFWORD (mUSAGE + 2 * COREHALFWORD (mGENERATExCHECK_SIxBREG)),
          1)))
    // IF USAGE(PTRARG1) > 3 THEN (5206)
    if (1 & (xGT (COREHALFWORD (mUSAGE + 2 * BYTE0 (mPTRARG1)), 3)))
      // RETURN FALSE; (5207)
      {
        reentryGuard = 0;
        return fixedToBit (32, (int32_t)(0));
      }
    // ELSE (5208)
    else
      // IF FORM(OP) ~= CSYM THEN (5209)
      if (1
          & (xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                 + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP))
                                 + 32 + 2 * (0)),
                   BYTE0 (mCSYM))))
        // RETURN FALSE; (5210)
        {
          reentryGuard = 0;
          return fixedToBit (32, (int32_t)(0));
        }
      // ELSE (5211)
      else
        // IF BASE(OP) ~= BREG THEN (5212)
        if (1
            & (xNEQ (
                COREHALFWORD (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP))
                              + 22 + 2 * (0)),
                COREHALFWORD (mGENERATExCHECK_SIxBREG))))
          // RETURN FALSE; (5213)
          {
            reentryGuard = 0;
            return fixedToBit (32, (int32_t)(0));
          }
  // IF KNOWN_SYM(OP) THEN (5214)
  if (1
      & (bitToFixed ((putBITp (16, mGENERATExKNOWN_SYMxOP,
                               getBIT (16, mGENERATExCHECK_SIxOP)),
                      GENERATExKNOWN_SYM (0)))))
    // CALL NEW_USAGE(OP, INX(OP) ~= 0); (5215)
    {
      putBITp (16, mGENERATExNEW_USAGExOP, getBIT (16, mGENERATExCHECK_SIxOP));
      putBITp (
          16, mGENERATExNEW_USAGExFLAG,
          fixedToBit (32, (int32_t)(xNEQ (
                              COREHALFWORD (
                                  getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP))
                                  + 34 + 2 * (0)),
                              0))));
      GENERATExNEW_USAGE (0);
    }
  // CALL EMITC(PROLOG, 1); (5216)
  {
    putBITp (16, mEMITCxTYPE, getBIT (8, mPROLOG));
    putBITp (16, mEMITCxINST, fixedToBit (32, (int32_t)(1)));
    EMITC (0);
  }
  // CALL FORCE_ADDRESS(BREG, OP, 1); (5217)
  {
    putBITp (16, mGENERATExFORCE_ADDRESSxTR,
             getBIT (16, mGENERATExCHECK_SIxBREG));
    putBITp (16, mGENERATExFORCE_ADDRESSxOP,
             getBIT (16, mGENERATExCHECK_SIxOP));
    putBITp (1, mGENERATExFORCE_ADDRESSxFLAG, fixedToBit (32, (int32_t)(1)));
    GENERATExFORCE_ADDRESS (0);
  }
  // CALL EMITC(PROLOG, 0); (5218)
  {
    putBITp (16, mEMITCxTYPE, getBIT (8, mPROLOG));
    putBITp (16, mEMITCxINST, fixedToBit (32, (int32_t)(0)));
    EMITC (0);
  }
  // FORM(OP) = CSYM; (5219)
  {
    descriptor_t *bitRHS = getBIT (8, mCSYM);
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP))
                + 32 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // BASE(OP), BACKUP_REG(OP) = REG(OP); (5220)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP))
                + 46 + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP))
                + 22 + 2 * (0),
            bitRHS);
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP))
                + 20 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // INX(OP), DISP(OP) = 0; (5221)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP))
                + 34 + 2 * (0),
            fixedToBit (16, numberRHS));
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP))
                + 30 + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // STRUCT_CON(OP), INX_CON(OP) = 0; (5222)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP)) + 8 + 4 * (0),
              numberRHS);
    putFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExCHECK_SIxOP)) + 4 + 4 * (0),
              numberRHS);
  }
  // RETURN TRUE; (5223)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(1));
  }
}
