/*
  File GENERATExCHAR_CALL.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExCHAR_CALL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExCHAR_CALL");
  // D_RTL_SETUP = TRUE; (7331)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mD_RTL_SETUP, bitRHS);
    bitRHS->inUse = 0;
  }
  // COLUMN(0), FORM(0) = 0; (7332)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 24 + 2 * (0),
            fixedToBit (16, numberRHS));
    putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 32 + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // VACOP = FALSE; (7333)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExCHAR_CALLxVACOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // REMOTE_ADDRS = CHECK_REMOTE(OP0); (7334)
  {
    descriptor_t *bitRHS = (putBITp (16, mGENERATExCHECK_REMOTExOP,
                                     getBIT (16, mGENERATExCHAR_CALLxOP0)),
                            GENERATExCHECK_REMOTE (0));
    putBIT (1, mREMOTE_ADDRS, bitRHS);
    bitRHS->inUse = 0;
  }
  // REMOTE_ADDRS = CHECK_REMOTE(OP1) | REMOTE_ADDRS; (7335)
  {
    int32_t numberRHS = (int32_t)(xOR (
        bitToFixed ((putBITp (16, mGENERATExCHECK_REMOTExOP,
                              getBIT (16, mGENERATExCHAR_CALLxOP1)),
                     GENERATExCHECK_REMOTE (0))),
        BYTE0 (mREMOTE_ADDRS)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mREMOTE_ADDRS, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF DATA_REMOTE & ( ((OP0>0) & (CSECT_TYPE(LOC(OP0),OP0)=LOCAL#D)) |
  // ((OP1>0) & (CSECT_TYPE(LOC(OP1),OP1)=LOCAL#D)) ) THEN (7336)
  if (1
      & (xAND (
          BYTE0 (mDATA_REMOTE),
          xOR (
              xAND (
                  xGT (COREHALFWORD (mGENERATExCHAR_CALLxOP0), 0),
                  xEQ (bitToFixed (
                           (putBITp (
                                16, mCSECT_TYPExPTR,
                                getBIT (16,
                                        getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCHAR_CALLxOP0))
                                            + 40 + 2 * (0))),
                            putBITp (16, mCSECT_TYPExOP,
                                     getBIT (16, mGENERATExCHAR_CALLxOP0)),
                            CSECT_TYPE (0))),
                       6)),
              xAND (
                  xGT (COREHALFWORD (mGENERATExCHAR_CALLxOP1), 0),
                  xEQ (
                      bitToFixed ((
                          putBITp (
                              16, mCSECT_TYPExPTR,
                              getBIT (
                                  16,
                                  getFIXED (mIND_STACK)
                                      + 73 * (COREHALFWORD (mGENERATExCHAR_CALLxOP1))
                                      + 40 + 2 * (0))),
                          putBITp (16, mCSECT_TYPExOP,
                                   getBIT (16, mGENERATExCHAR_CALLxOP1)),
                          CSECT_TYPE (0))),
                      6))))))
    // REMOTE_ADDRS = TRUE; (7337)
    {
      int32_t numberRHS = (int32_t)(1);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (1, mREMOTE_ADDRS, bitRHS);
      bitRHS->inUse = 0;
    }
  // CPART = COLUMN(OP1) > 0; (7338)
  {
    int32_t numberRHS = (int32_t)(xGT (
        COREHALFWORD (getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExCHAR_CALLxOP1)) + 24
                      + 2 * (0)),
        0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExCHAR_CALLxCPART, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF COLUMN(OP0) > 0 THEN (7339)
  if (1
      & (xGT (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExCHAR_CALLxOP0))
                            + 24 + 2 * (0)),
              0)))
    // CPART = CPART + 2; (7340)
    {
      int32_t numberRHS
          = (int32_t)(xadd (BYTE0 (mGENERATExCHAR_CALLxCPART), 2));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (1, mGENERATExCHAR_CALLxCPART, bitRHS);
      bitRHS->inUse = 0;
    }
  // INTCALL = INTRINSIC(FORM_CHARNAME(OPCODE, CPART,  (FORM(OP0)=WORK) &
  // ~CHAR_ASNMNT) ) & ~REMOTE_ADDRS; (7341)
  {
    int32_t numberRHS = (int32_t)(xAND (
        bitToFixed (
            (putCHARACTERp (
                 mINTRINSICxNAME,
                 (putBITp (16, mGENERATExFORM_CHARNAMExOPCODE,
                           getBIT (16, mGENERATExCHAR_CALLxOPCODE)),
                  putBITp (16, mGENERATExFORM_CHARNAMExPART,
                           getBIT (1, mGENERATExCHAR_CALLxCPART)),
                  putBITp (
                      1, mGENERATExFORM_CHARNAMExVAC,
                      fixedToBit (
                          32, (int32_t)(xAND (
                                  xEQ (COREHALFWORD (
                                           getFIXED (mIND_STACK)
                                           + 73
                                                 * (COREHALFWORD (
                                                     mGENERATExCHAR_CALLxOP0))
                                           + 32 + 2 * (0)),
                                       BYTE0 (mWORK)),
                                  xNOT (BYTE0 (
                                      mGENERATExCHAR_CALLxCHAR_ASNMNT)))))),
                  GENERATExFORM_CHARNAME (0))),
             INTRINSIC (0))),
        xNOT (BYTE0 (mREMOTE_ADDRS))));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExINTCALL, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF OP3 > 0 THEN (7342)
  if (1 & (xGT (COREHALFWORD (mGENERATExCHAR_CALLxOP3), 0)))
    // DO; (7343)
    {
    rs1:;
      // TARGET_REGISTER = SYSARG2(INTCALL); (7344)
      {
        descriptor_t *bitRHS
            = getBIT (8, mSYSARG2 + 1 * COREHALFWORD (mGENERATExINTCALL));
        putBIT (16, mTARGET_REGISTER, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL FORCE_ACCUMULATOR(OP3, FULLBIT); (7345)
      {
        putBITp (16, mGENERATExFORCE_ACCUMULATORxOP,
                 getBIT (16, mGENERATExCHAR_CALLxOP3));
        putBITp (16, mGENERATExFORCE_ACCUMULATORxOPTYPE, getBIT (8, mFULLBIT));
        GENERATExFORCE_ACCUMULATOR (0);
      }
      // TARGET_REGISTER = -1; (7346)
      {
        int32_t numberRHS = (int32_t)(-1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mTARGET_REGISTER, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (7347)
  else
    // IF OP0 > 0 THEN (7348)
    if (1 & (xGT (COREHALFWORD (mGENERATExCHAR_CALLxOP0), 0)))
      // IF FORM(OP0) ~= VAC THEN (7349)
      if (1
          & (xNEQ (
              COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExCHAR_CALLxOP0))
                            + 32 + 2 * (0)),
              BYTE0 (mVAC))))
        // INTCALL = INTCALL + 2; (7350)
        {
          int32_t numberRHS
              = (int32_t)(xadd (COREHALFWORD (mGENERATExINTCALL), 2));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mGENERATExINTCALL, bitRHS);
          bitRHS->inUse = 0;
        }
  // IF OP2 > 0 THEN (7351)
  if (1 & (xGT (COREHALFWORD (mGENERATExCHAR_CALLxOP2), 0)))
    // CALL STACK_REG_PARM(FORCE_ADDRESS(SYSARG2(INTCALL), OP2, 1)); (7352)
    {
      putBITp (
          16, mGENERATExSTACK_REG_PARMxR,
          fixedToBit (
              32,
              (int32_t)((
                  putBITp (
                      16, mGENERATExFORCE_ADDRESSxTR,
                      getBIT (8, mSYSARG2
                                     + 1 * COREHALFWORD (mGENERATExINTCALL))),
                  putBITp (16, mGENERATExFORCE_ADDRESSxOP,
                           getBIT (16, mGENERATExCHAR_CALLxOP2)),
                  putBITp (1, mGENERATExFORCE_ADDRESSxFLAG,
                           fixedToBit (32, (int32_t)(1))),
                  GENERATExFORCE_ADDRESS (0)))));
      GENERATExSTACK_REG_PARM (0);
    }
  // CALL STACK_REG_PARM(FORCE_ADDRESS(SYSARG1(INTCALL), OP1, 1)); (7353)
  {
    putBITp (
        16, mGENERATExSTACK_REG_PARMxR,
        fixedToBit (
            32,
            (int32_t)((
                putBITp (
                    16, mGENERATExFORCE_ADDRESSxTR,
                    getBIT (8,
                            mSYSARG1 + 1 * COREHALFWORD (mGENERATExINTCALL))),
                putBITp (16, mGENERATExFORCE_ADDRESSxOP,
                         getBIT (16, mGENERATExCHAR_CALLxOP1)),
                putBITp (1, mGENERATExFORCE_ADDRESSxFLAG,
                         fixedToBit (32, (int32_t)(1))),
                GENERATExFORCE_ADDRESS (0)))));
    GENERATExSTACK_REG_PARM (0);
  }
  // IF OP0 > 0 THEN (7354)
  if (1 & (xGT (COREHALFWORD (mGENERATExCHAR_CALLxOP0), 0)))
    // IF FORM(OP0) ~= VAC THEN (7355)
    if (1
        & (xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                               + 73 * (COREHALFWORD (mGENERATExCHAR_CALLxOP0))
                               + 32 + 2 * (0)),
                 BYTE0 (mVAC))))
      // DO; (7356)
      {
      rs2:;
        // IF (FORM(OP0)=WORK) & ~CHAR_ASNMNT THEN (7357)
        if (1
            & (xAND (xEQ (COREHALFWORD (
                              getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExCHAR_CALLxOP0))
                              + 32 + 2 * (0)),
                          BYTE0 (mWORK)),
                     xNOT (BYTE0 (mGENERATExCHAR_CALLxCHAR_ASNMNT)))))
          // VACOP = TRUE; (7358)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mGENERATExCHAR_CALLxVACOP, bitRHS);
            bitRHS->inUse = 0;
          }
        // CALL STACK_REG_PARM(FORCE_ADDRESS(SYSARG0(INTCALL), OP0, 1)); (7359)
        {
          putBITp (
              16, mGENERATExSTACK_REG_PARMxR,
              fixedToBit (
                  32,
                  (int32_t)((
                      putBITp (
                          16, mGENERATExFORCE_ADDRESSxTR,
                          getBIT (8,
                                  mSYSARG0
                                      + 1 * COREHALFWORD (mGENERATExINTCALL))),
                      putBITp (16, mGENERATExFORCE_ADDRESSxOP,
                               getBIT (16, mGENERATExCHAR_CALLxOP0)),
                      putBITp (1, mGENERATExFORCE_ADDRESSxFLAG,
                               fixedToBit (32, (int32_t)(1))),
                      GENERATExFORCE_ADDRESS (0)))));
          GENERATExSTACK_REG_PARM (0);
        }
      es2:;
      } // End of DO block
  // IF COLUMN(OP1) > 0 THEN (7360)
  if (1
      & (xGT (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExCHAR_CALLxOP1))
                            + 24 + 2 * (0)),
              0)))
    // DO; (7361)
    {
    rs3:;
      // CALL SET_CHAR_DESC(OP1, FIXARG1, FIXARG2); (7362)
      {
        putBITp (16, mGENERATExSET_CHAR_DESCxOP,
                 getBIT (16, mGENERATExCHAR_CALLxOP1));
        putBITp (16, mGENERATExSET_CHAR_DESCxR1, getBIT (8, mFIXARG1));
        putBITp (16, mGENERATExSET_CHAR_DESCxR0, getBIT (8, mFIXARG2));
        GENERATExSET_CHAR_DESC (0);
      }
      // IF COLUMN(OP0) > 0 THEN (7363)
      if (1
          & (xGT (COREHALFWORD (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExCHAR_CALLxOP0))
                                + 24 + 2 * (0)),
                  0)))
        // DO; (7364)
        {
        rs3s1:;
          // IF OLD_LINKAGE & OP3 = 0 THEN (7365)
          if (1
              & (xAND (BYTE0 (mOLD_LINKAGE),
                       xEQ (COREHALFWORD (mGENERATExCHAR_CALLxOP3), 0))))
            // CALL SET_CHAR_DESC(OP0, SYSARG2, FIXARG3); (7366)
            {
              putBITp (16, mGENERATExSET_CHAR_DESCxOP,
                       getBIT (16, mGENERATExCHAR_CALLxOP0));
              putBITp (16, mGENERATExSET_CHAR_DESCxR1, getBIT (8, mSYSARG2));
              putBITp (16, mGENERATExSET_CHAR_DESCxR0, getBIT (8, mFIXARG3));
              GENERATExSET_CHAR_DESC (0);
            }
          // ELSE (7367)
          else
            // DO; (7368)
            {
            rs3s1s1:;
              // IF DEL(OP0) > 0 THEN (7369)
              if (1
                  & (xGT (COREHALFWORD (
                              getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExCHAR_CALLxOP0))
                              + 28 + 2 * (0)),
                          0)))
                // DO; (7370)
                {
                rs3s1s1s1:;
                  // IF FORM(DEL(OP0)) = LIT & FORM(COLUMN(OP0)) = LIT THEN
                  // (7371)
                  if (1
                      & (xAND (
                          xEQ (
                              COREHALFWORD (
                                  getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCHAR_CALLxOP0))
                                            + 28 + 2 * (0)))
                                  + 32 + 2 * (0)),
                              BYTE0 (mLIT)),
                          xEQ (
                              COREHALFWORD (
                                  getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCHAR_CALLxOP0))
                                            + 24 + 2 * (0)))
                                  + 32 + 2 * (0)),
                              BYTE0 (mLIT)))))
                    // CALL FORCE_NUM(FIXARG3,
                    // SHL(VAL(COLUMN(OP0)),16)+VAL(DEL(OP0)), 8); (7372)
                    {
                      putBITp (16, mGENERATExFORCE_NUMxR,
                               getBIT (8, mFIXARG3));
                      putFIXED (
                          mGENERATExFORCE_NUMxNUM,
                          xadd (
                              SHL (
                                  getFIXED (
                                      getFIXED (mIND_STACK)
                                      + 73
                                            * (COREHALFWORD (
                                                getFIXED (mIND_STACK)
                                                + 73
                                                      * (COREHALFWORD (
                                                          mGENERATExCHAR_CALLxOP0))
                                                + 24 + 2 * (0)))
                                      + 12 + 4 * (0)),
                                  16),
                              getFIXED (
                                  getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCHAR_CALLxOP0))
                                            + 28 + 2 * (0)))
                                  + 12 + 4 * (0))));
                      putBITp (1, mGENERATExFORCE_NUMxFLAG,
                               fixedToBit (32, (int32_t)(8)));
                      GENERATExFORCE_NUM (0);
                    }
                  // ELSE (7373)
                  else
                    // DO; (7374)
                    {
                    rs3s1s1s1s1:;
                      // TARGET_REGISTER = FIXARG3; (7375)
                      {
                        descriptor_t *bitRHS = getBIT (8, mFIXARG3);
                        putBIT (16, mTARGET_REGISTER, bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // CALL FORCE_ACCUMULATOR(DEL(OP0)); (7376)
                      {
                        putBITp (
                            16, mGENERATExFORCE_ACCUMULATORxOP,
                            getBIT (16, getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCHAR_CALLxOP0))
                                            + 28 + 2 * (0)));
                        GENERATExFORCE_ACCUMULATOR (0);
                      }
                      // CALL EMITP(SRL, FIXARG3, 0, SHCOUNT, 16); (7377)
                      {
                        putBITp (16, mGENERATExEMITPxINST, getBIT (8, mSRL));
                        putBITp (16, mGENERATExEMITPxXREG,
                                 getBIT (8, mFIXARG3));
                        putBITp (16, mGENERATExEMITPxINDEX,
                                 fixedToBit (32, (int32_t)(0)));
                        putBITp (16, mGENERATExEMITPxFLAG,
                                 getBIT (8, mSHCOUNT));
                        putBITp (16, mGENERATExEMITPxPTR,
                                 fixedToBit (32, (int32_t)(16)));
                        GENERATExEMITP (0);
                      }
                      // CALL ARITH_BY_MODE(SUM, DEL(OP0), COLUMN(OP0),
                      // INTEGER); (7378)
                      {
                        putBITp (16, mGENERATExARITH_BY_MODExOP,
                                 getBIT (8, mGENERATExSUM));
                        putBITp (
                            16, mGENERATExARITH_BY_MODExOP1,
                            getBIT (16, getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCHAR_CALLxOP0))
                                            + 28 + 2 * (0)));
                        putBITp (
                            16, mGENERATExARITH_BY_MODExOP2,
                            getBIT (16, getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCHAR_CALLxOP0))
                                            + 24 + 2 * (0)));
                        putBITp (16, mGENERATExARITH_BY_MODExOPTYPE,
                                 getBIT (8, mINTEGER));
                        GENERATExARITH_BY_MODE (0);
                      }
                      // CALL OFF_TARGET(DEL(OP0)); (7379)
                      {
                        putBITp (
                            16, mGENERATExOFF_TARGETxOP,
                            getBIT (16, getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCHAR_CALLxOP0))
                                            + 28 + 2 * (0)));
                        GENERATExOFF_TARGET (0);
                      }
                    es3s1s1s1s1:;
                    } // End of DO block
                es3s1s1s1:;
                } // End of DO block
              // ELSE (7380)
              else
                // DO; (7381)
                {
                rs3s1s1s2:;
                  // IF FORM(COLUMN(OP0)) = LIT THEN (7382)
                  if (1
                      & (xEQ (COREHALFWORD (
                                  getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCHAR_CALLxOP0))
                                            + 24 + 2 * (0)))
                                  + 32 + 2 * (0)),
                              BYTE0 (mLIT))))
                    // CALL FORCE_NUM(FIXARG3,
                    // SHL(VAL(COLUMN(OP0)),16)+VAL(COLUMN(OP0)), 8); (7383)
                    {
                      putBITp (16, mGENERATExFORCE_NUMxR,
                               getBIT (8, mFIXARG3));
                      putFIXED (
                          mGENERATExFORCE_NUMxNUM,
                          xadd (
                              SHL (
                                  getFIXED (
                                      getFIXED (mIND_STACK)
                                      + 73
                                            * (COREHALFWORD (
                                                getFIXED (mIND_STACK)
                                                + 73
                                                      * (COREHALFWORD (
                                                          mGENERATExCHAR_CALLxOP0))
                                                + 24 + 2 * (0)))
                                      + 12 + 4 * (0)),
                                  16),
                              getFIXED (
                                  getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCHAR_CALLxOP0))
                                            + 24 + 2 * (0)))
                                  + 12 + 4 * (0))));
                      putBITp (1, mGENERATExFORCE_NUMxFLAG,
                               fixedToBit (32, (int32_t)(8)));
                      GENERATExFORCE_NUM (0);
                    }
                  // ELSE (7384)
                  else
                    // DO; (7385)
                    {
                    rs3s1s1s2s1:;
                      // TARGET_REGISTER = FIXARG3; (7386)
                      {
                        descriptor_t *bitRHS = getBIT (8, mFIXARG3);
                        putBIT (16, mTARGET_REGISTER, bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // CALL FORCE_ACCUMULATOR(COLUMN(OP0)); (7387)
                      {
                        putBITp (
                            16, mGENERATExFORCE_ACCUMULATORxOP,
                            getBIT (16, getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCHAR_CALLxOP0))
                                            + 24 + 2 * (0)));
                        GENERATExFORCE_ACCUMULATOR (0);
                      }
                      // CALL OFF_TARGET(COLUMN(OP0)); (7388)
                      {
                        putBITp (
                            16, mGENERATExOFF_TARGETxOP,
                            getBIT (16, getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCHAR_CALLxOP0))
                                            + 24 + 2 * (0)));
                        GENERATExOFF_TARGET (0);
                      }
                    es3s1s1s2s1:;
                    } // End of DO block
                es3s1s1s2:;
                } // End of DO block
              // CALL RETURN_STACK_ENTRIES(COLUMN(OP0), DEL(OP0)); (7389)
              {
                putBITp (
                    16, mGENERATExRETURN_STACK_ENTRIESxPTR1,
                    getBIT (16,
                            getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExCHAR_CALLxOP0))
                                + 24 + 2 * (0)));
                putBITp (
                    16, mGENERATExRETURN_STACK_ENTRIESxPTR2,
                    getBIT (16,
                            getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExCHAR_CALLxOP0))
                                + 28 + 2 * (0)));
                GENERATExRETURN_STACK_ENTRIES (0);
              }
            es3s1s1:;
            } // End of DO block
        es3s1:;
        } // End of DO block
    es3:;
    } // End of DO block
  // ELSE (7390)
  else
    // IF COLUMN(OP0) > 0 THEN (7391)
    if (1
        & (xGT (COREHALFWORD (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExCHAR_CALLxOP0))
                              + 24 + 2 * (0)),
                0)))
      // DO; (7392)
      {
      rs4:;
        // CALL SET_CHAR_DESC(OP0, FIXARG1, FIXARG2); (7393)
        {
          putBITp (16, mGENERATExSET_CHAR_DESCxOP,
                   getBIT (16, mGENERATExCHAR_CALLxOP0));
          putBITp (16, mGENERATExSET_CHAR_DESCxR1, getBIT (8, mFIXARG1));
          putBITp (16, mGENERATExSET_CHAR_DESCxR0, getBIT (8, mFIXARG2));
          GENERATExSET_CHAR_DESC (0);
        }
      es4:;
      } // End of DO block
  // CALL DROP_PARM_STACK; (7394)
  GENERATExDROP_PARM_STACK (0);
  // IF OP3 > 0 THEN (7395)
  if (1 & (xGT (COREHALFWORD (mGENERATExCHAR_CALLxOP3), 0)))
    // DO; (7396)
    {
    rs5:;
      // CALL CHECK_VAC(OP3, SYSARG2(INTCALL)); (7397)
      {
        putBITp (16, mGENERATExCHECK_VACxOP,
                 getBIT (16, mGENERATExCHAR_CALLxOP3));
        putBITp (16, mGENERATExCHECK_VACxR,
                 getBIT (8, mSYSARG2 + 1 * COREHALFWORD (mGENERATExINTCALL)));
        GENERATExCHECK_VAC (0);
      }
      // CALL DROP_REG(OP3); (7398)
      {
        putBITp (16, mGENERATExDROP_REGxOP,
                 getBIT (16, mGENERATExCHAR_CALLxOP3));
        GENERATExDROP_REG (0);
      }
    es5:;
    } // End of DO block
  // IF REMOTE_ADDRS THEN (7399)
  if (1 & (bitToFixed (getBIT (1, mREMOTE_ADDRS))))
    // IF OPCODE = XXASN THEN (7400)
    if (1 & (xEQ (COREHALFWORD (mGENERATExCHAR_CALLxOPCODE), BYTE0 (mXXASN))))
      // OPCODE = 12; (7401)
      {
        int32_t numberRHS = (int32_t)(12);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATExCHAR_CALLxOPCODE, bitRHS);
        bitRHS->inUse = 0;
      }
  // CALL GENLIBCALL(FORM_CHARNAME(OPCODE, CPART, VACOP)); (7402)
  {
    putCHARACTERp (mGENERATExGENLIBCALLxNAME,
                   (putBITp (16, mGENERATExFORM_CHARNAMExOPCODE,
                             getBIT (16, mGENERATExCHAR_CALLxOPCODE)),
                    putBITp (16, mGENERATExFORM_CHARNAMExPART,
                             getBIT (1, mGENERATExCHAR_CALLxCPART)),
                    putBITp (1, mGENERATExFORM_CHARNAMExVAC,
                             getBIT (1, mGENERATExCHAR_CALLxVACOP)),
                    GENERATExFORM_CHARNAME (0)));
    GENERATExGENLIBCALL (0);
  }
  // LASTRESULT, OP3, REMOTE_ADDRS, CHAR_ASNMNT = 0; (7403)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mLASTRESULT, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExCHAR_CALLxOP3, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mREMOTE_ADDRS, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExCHAR_CALLxCHAR_ASNMNT, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
