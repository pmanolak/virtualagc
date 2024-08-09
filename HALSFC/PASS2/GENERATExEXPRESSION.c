/*
  File GENERATExEXPRESSION.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExEXPRESSION (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExEXPRESSION");
  // IF COMMUTATIVE(OPCODE) THEN (6966)
  if (1
      & (bitToFixed (
          getBIT (8, mGENERATExCOMMUTATIVE
                         + 1 * COREHALFWORD (mGENERATExEXPRESSIONxOPCODE)))))
    // IF SHOULD_COMMUTE(OPCODE) THEN (6967)
    if (1
        & ((putBITp (16, mGENERATExSHOULD_COMMUTExOPCODE,
                     getBIT (16, mGENERATExEXPRESSIONxOPCODE)),
            GENERATExSHOULD_COMMUTE (0))))
      // DO; (6968)
      {
      rs1:;
        // CALL COMMUTEM; (6969)
        GENERATExCOMMUTEM (0);
        // IF OPCODE = XADD THEN (6970)
        if (1
            & (xEQ (COREHALFWORD (mGENERATExEXPRESSIONxOPCODE),
                    BYTE0 (mXADD))))
          // DO; (6971)
          {
          rs1s1:;
            // CONST(LEFTOP) = CONST(RIGHTOP); (6972)
            {
              int32_t numberRHS = (int32_t)(getFIXED (
                  getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRIGHTOP)) + 0
                  + 4 * (0)));
              putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                            + 0 + 4 * (0),
                        numberRHS);
            }
            // CONST(RIGHTOP) = 0; (6973)
            {
              int32_t numberRHS = (int32_t)(0);
              putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRIGHTOP))
                            + 0 + 4 * (0),
                        numberRHS);
            }
          es1s1:;
          } // End of DO block
      es1:;
      } // End of DO block
  // IF NEW_INSTRUCTIONS THEN (6974)
  if (1 & (bitToFixed (getBIT (1, mNEW_INSTRUCTIONS))))
    // IF OPMODE(OPTYPE) = 4 THEN (6975)
    if (1 & (xEQ (BYTE0 (mOPMODE + 1 * COREHALFWORD (mOPTYPE)), 4)))
      // IF ARITH_OP(OPCODE) = ARITH_OP(COMPARE) THEN (6976)
      if (1
          & (xEQ (
              COREHALFWORD (mGENERATExARITH_OP
                            + 2 * COREHALFWORD (mGENERATExEXPRESSIONxOPCODE)),
              COREHALFWORD (mGENERATExARITH_OP
                            + 2 * COREHALFWORD (mGENERATExCOMPARE)))))
        // OPCODE = MINUS; (6977)
        {
          descriptor_t *bitRHS = getBIT (8, mGENERATExMINUS);
          putBIT (16, mGENERATExEXPRESSIONxOPCODE, bitRHS);
          bitRHS->inUse = 0;
        }
  // TO_BE_INCORPORATED = ~ADDITIVE(OPCODE); (6978)
  {
    int32_t numberRHS = (int32_t)(xNOT (BYTE0 (
        mGENERATExADDITIVE + 1 * COREHALFWORD (mGENERATExEXPRESSIONxOPCODE))));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExTO_BE_INCORPORATED, bitRHS);
    bitRHS->inUse = 0;
  }
  // TO_BE_MODIFIED = DESTRUCTIVE(OPCODE); (6979)
  {
    descriptor_t *bitRHS
        = getBIT (8, mGENERATExDESTRUCTIVE
                         + 1 * COREHALFWORD (mGENERATExEXPRESSIONxOPCODE));
    putBIT (1, mGENERATExTO_BE_MODIFIED, bitRHS);
    bitRHS->inUse = 0;
  }
  // COMPARISON = CVTTYPE(OPTYPE) = 0 & ARITH_OP(OPCODE) = ARITH_OP(COMPARE) &
  // ~SELF_ALIGNING; (6980)
  {
    int32_t numberRHS = (int32_t)(xAND (
        xAND (xEQ (BYTE0 (mCVTTYPE + 1 * COREHALFWORD (mOPTYPE)), 0),
              xEQ (COREHALFWORD (
                       mGENERATExARITH_OP
                       + 2 * COREHALFWORD (mGENERATExEXPRESSIONxOPCODE)),
                   COREHALFWORD (mGENERATExARITH_OP
                                 + 2 * COREHALFWORD (mGENERATExCOMPARE)))),
        xNOT (BYTE0 (mSELF_ALIGNING))));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExEXPRESSIONxCOMPARISON, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL FORCE_ACCUMULATOR(LEFTOP, OPTYPE); (6981)
  {
    putBITp (16, mGENERATExFORCE_ACCUMULATORxOP, getBIT (16, mLEFTOP));
    putBITp (16, mGENERATExFORCE_ACCUMULATORxOPTYPE, getBIT (16, mOPTYPE));
    GENERATExFORCE_ACCUMULATOR (0);
  }
  // IF ARITH_OP(OPCODE)=ARITH_OP(XEXP) & POWER_OF_TWO(RIGHTOP)&INX_SHIFT(0)<=2
  // THEN (6982)
  if (1
      & (xAND (
          xAND (xEQ (COREHALFWORD (
                         mGENERATExARITH_OP
                         + 2 * COREHALFWORD (mGENERATExEXPRESSIONxOPCODE)),
                     COREHALFWORD (mGENERATExARITH_OP + 2 * BYTE0 (mXEXP))),
                bitToFixed ((putBITp (16, mGENERATExPOWER_OF_TWOxOP,
                                      getBIT (16, mRIGHTOP)),
                             GENERATExPOWER_OF_TWO (0)))),
          xLE (BYTE0 (getFIXED (mIND_STACK) + 73 * (0) + 64 + 1 * (0)), 2))))
    // DO WHILE INX_SHIFT(0) > 0; (6983)
    while (
        1 & (xGT (BYTE0 (getFIXED (mIND_STACK) + 73 * (0) + 64 + 1 * (0)), 0)))
      {
        // INX_SHIFT(0) = INX_SHIFT(0) - 1; (6984)
        {
          int32_t numberRHS = (int32_t)(xsubtract (
              BYTE0 (getFIXED (mIND_STACK) + 73 * (0) + 64 + 1 * (0)), 1));
          putBIT (8, getFIXED (mIND_STACK) + 73 * (0) + 64 + 1 * (0),
                  fixedToBit (8, numberRHS));
        }
        // CALL ARITH_BY_MODE(SUM, LEFTOP, LEFTOP, OPTYPE); (6985)
        {
          putBITp (16, mGENERATExARITH_BY_MODExOP, getBIT (8, mGENERATExSUM));
          putBITp (16, mGENERATExARITH_BY_MODExOP1, getBIT (16, mLEFTOP));
          putBITp (16, mGENERATExARITH_BY_MODExOP2, getBIT (16, mLEFTOP));
          putBITp (16, mGENERATExARITH_BY_MODExOPTYPE, getBIT (16, mOPTYPE));
          GENERATExARITH_BY_MODE (0);
        }
      } // End of DO WHILE block
  // ELSE (6986)
  else
    // DO; (6987)
    {
    rs3:;
      // MULTIPLICATION = ARITH_OP(OPCODE) = ARITH_OP(XEXP) & OPMODE(OPTYPE) ~=
      // 4 & ~REG(LEFTOP); (6988)
      {
        int32_t numberRHS = (int32_t)(xAND (
            xAND (xEQ (COREHALFWORD (
                           mGENERATExARITH_OP
                           + 2 * COREHALFWORD (mGENERATExEXPRESSIONxOPCODE)),
                       COREHALFWORD (mGENERATExARITH_OP + 2 * BYTE0 (mXEXP))),
                  xNEQ (BYTE0 (mOPMODE + 1 * COREHALFWORD (mOPTYPE)), 4)),
            xNOT (COREHALFWORD (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mLEFTOP)) + 46
                                + 2 * (0)))));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mGENERATExEXPRESSIONxMULTIPLICATION, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF MULTIPLICATION THEN (6989)
      if (1 & (bitToFixed (getBIT (1, mGENERATExEXPRESSIONxMULTIPLICATION))))
        // CALL CHECKPOINT_REG(REG(LEFTOP)+1); (6990)
        {
          putBITp (
              16, mGENERATExCHECKPOINT_REGxR,
              fixedToBit (32, (int32_t)(xadd (
                                  COREHALFWORD (getFIXED (mIND_STACK)
                                                + 73 * (COREHALFWORD (mLEFTOP))
                                                + 46 + 2 * (0)),
                                  1))));
          GENERATExCHECKPOINT_REG (0);
        }
      // NOT_THIS_REGISTER = REG(LEFTOP); (6991)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                              + 46 + 2 * (0));
        putBIT (16, mNOT_THIS_REGISTER, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF OPMODE(TYPE(RIGHTOP)) = OPMODE(OPTYPE) THEN (6992)
      if (1
          & (xEQ (BYTE0 (mOPMODE
                         + 1
                               * COREHALFWORD (getFIXED (mIND_STACK)
                                               + 73 * (COREHALFWORD (mRIGHTOP))
                                               + 50 + 2 * (0))),
                  BYTE0 (mOPMODE + 1 * COREHALFWORD (mOPTYPE)))))
        // DO; (6993)
        {
        rs3s1:;
          // IF ~COMPARISON THEN (6994)
          if (1 & (xNOT (BYTE0 (mGENERATExEXPRESSIONxCOMPARISON))))
            // IF SEARCH_REGS(RIGHTOP)>=0 THEN (6995)
            if (1
                & (xGE ((putBITp (16, mGENERATExSEARCH_REGSxOP,
                                  getBIT (16, mRIGHTOP)),
                         GENERATExSEARCH_REGS (0)),
                        0)))
              // GO TO FORCE_RIGHT; (6996)
              goto FORCE_RIGHT;
          // IF AVAILABLE_FROM_STORAGE(RIGHTOP, OPCODE) THEN (6997)
          if (1
              & ((putBITp (16, mGENERATExAVAILABLE_FROM_STORAGExOP,
                           getBIT (16, mRIGHTOP)),
                  putBITp (16, mGENERATExAVAILABLE_FROM_STORAGExOPCODE,
                           getBIT (16, mGENERATExEXPRESSIONxOPCODE)),
                  GENERATExAVAILABLE_FROM_STORAGE (0))))
            // CALL ARITH_BY_MODE(OPCODE, LEFTOP, RIGHTOP, OPTYPE); (6998)
            {
              putBITp (16, mGENERATExARITH_BY_MODExOP,
                       getBIT (16, mGENERATExEXPRESSIONxOPCODE));
              putBITp (16, mGENERATExARITH_BY_MODExOP1, getBIT (16, mLEFTOP));
              putBITp (16, mGENERATExARITH_BY_MODExOP2, getBIT (16, mRIGHTOP));
              putBITp (16, mGENERATExARITH_BY_MODExOPTYPE,
                       getBIT (16, mOPTYPE));
              GENERATExARITH_BY_MODE (0);
            }
          // ELSE (6999)
          else
            // DO; (7000)
            {
            rs3s1s1:;
            // FORCE_RIGHT: (7001)
            FORCE_RIGHT:
              // TR = TARGET_REGISTER; (7002)
              {
                descriptor_t *bitRHS = getBIT (16, mTARGET_REGISTER);
                putBIT (16, mGENERATExEXPRESSIONxTR, bitRHS);
                bitRHS->inUse = 0;
              }
              // TARGET_REGISTER = -1; (7003)
              {
                int32_t numberRHS = (int32_t)(-1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mTARGET_REGISTER, bitRHS);
                bitRHS->inUse = 0;
              }
              // CALL FORCE_ACCUMULATOR(RIGHTOP, OPTYPE); (7004)
              {
                putBITp (16, mGENERATExFORCE_ACCUMULATORxOP,
                         getBIT (16, mRIGHTOP));
                putBITp (16, mGENERATExFORCE_ACCUMULATORxOPTYPE,
                         getBIT (16, mOPTYPE));
                GENERATExFORCE_ACCUMULATOR (0);
              }
              // TARGET_REGISTER = TR; (7005)
              {
                descriptor_t *bitRHS = getBIT (16, mGENERATExEXPRESSIONxTR);
                putBIT (16, mTARGET_REGISTER, bitRHS);
                bitRHS->inUse = 0;
              }
              // IF COMPARISON THEN (7006)
              if (1
                  & (bitToFixed (getBIT (1, mGENERATExEXPRESSIONxCOMPARISON))))
                // CALL CHECKPOINT_REG(REG(RIGHTOP)); (7007)
                {
                  putBITp (16, mGENERATExCHECKPOINT_REGxR,
                           getBIT (16, getFIXED (mIND_STACK)
                                           + 73 * (COREHALFWORD (mRIGHTOP))
                                           + 46 + 2 * (0)));
                  GENERATExCHECKPOINT_REG (0);
                }
              // CALL ARITH_BY_MODE(OPCODE, LEFTOP, RIGHTOP, OPTYPE); (7008)
              {
                putBITp (16, mGENERATExARITH_BY_MODExOP,
                         getBIT (16, mGENERATExEXPRESSIONxOPCODE));
                putBITp (16, mGENERATExARITH_BY_MODExOP1,
                         getBIT (16, mLEFTOP));
                putBITp (16, mGENERATExARITH_BY_MODExOP2,
                         getBIT (16, mRIGHTOP));
                putBITp (16, mGENERATExARITH_BY_MODExOPTYPE,
                         getBIT (16, mOPTYPE));
                GENERATExARITH_BY_MODE (0);
              }
            es3s1s1:;
            } // End of DO block
        es3s1:;
        } // End of DO block
      // ELSE (7009)
      else
        // GO TO FORCE_RIGHT; (7010)
        goto FORCE_RIGHT;
      // NOT_THIS_REGISTER = -1; (7011)
      {
        int32_t numberRHS = (int32_t)(-1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mNOT_THIS_REGISTER, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF MULTIPLICATION THEN (7012)
      if (1 & (bitToFixed (getBIT (1, mGENERATExEXPRESSIONxMULTIPLICATION))))
        // CALL UNRECOGNIZABLE(REG(LEFTOP)+1); (7013)
        {
          putBITp (
              16, mGENERATExUNRECOGNIZABLExR,
              fixedToBit (32, (int32_t)(xadd (
                                  COREHALFWORD (getFIXED (mIND_STACK)
                                                + 73 * (COREHALFWORD (mLEFTOP))
                                                + 46 + 2 * (0)),
                                  1))));
          GENERATExUNRECOGNIZABLE (0);
        }
    es3:;
    } // End of DO block
  // CALL RETURN_STACK_ENTRY(RIGHTOP); (7014)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP, getBIT (16, mRIGHTOP));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  // IF PACKTYPE(OPTYPE) = BITS THEN (7015)
  if (1
      & (xEQ (BYTE0 (mPACKTYPE + 1 * COREHALFWORD (mOPTYPE)), BYTE0 (mBITS))))
    // SIZE(LEFTOP) = MAX(SIZE(LEFTOP), SIZE(RIGHTOP)); (7016)
    {
      int32_t numberRHS = (int32_t)((
          putFIXED (mMAXxVAL1, COREHALFWORD (getFIXED (mIND_STACK)
                                             + 73 * (COREHALFWORD (mLEFTOP))
                                             + 48 + 2 * (0))),
          putFIXED (mMAXxVAL2, COREHALFWORD (getFIXED (mIND_STACK)
                                             + 73 * (COREHALFWORD (mRIGHTOP))
                                             + 48 + 2 * (0))),
          MAX (0)));
      putBIT (16,
              getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP)) + 48
                  + 2 * (0),
              fixedToBit (16, numberRHS));
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
