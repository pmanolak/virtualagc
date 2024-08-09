/*
  File EJECT_INVARS.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
EJECT_INVARS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "EJECT_INVARS");
  // TMP=0; (5329)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mEJECT_INVARSxTMP, numberRHS);
  }
  // NEW_NODE_BEGINNING = NODE2(NEW_NODE_PTR + 1); (5330)
  {
    descriptor_t *bitRHS
        = getBIT (16, mNODE2 + 2 * xadd (COREHALFWORD (mNEW_NODE_PTR), 1));
    putBIT (16, mEJECT_INVARSxNEW_NODE_BEGINNING, bitRHS);
    bitRHS->inUse = 0;
  }
  // ARRAYED_OPS = (NODE(NEW_NODE_BEGINNING) & AR_TAG) ~= 0; (5331)
  {
    int32_t numberRHS = (int32_t)(xNEQ (
        xAND (getFIXED (mNODE
                        + 4 * COREHALFWORD (mEJECT_INVARSxNEW_NODE_BEGINNING)),
              getFIXED (mAR_TAG)),
        0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mARRAYED_OPS, bitRHS);
    bitRHS->inUse = 0;
  }
  // PUT_ADLP = ARRAYED_OPS OR ~AR_INV AND STATEMENT_ARRAYNESS; (5332)
  {
    int32_t numberRHS = (int32_t)(xOR (
        BYTE0 (mARRAYED_OPS), xAND (xNOT (BYTE0 (mEJECT_INVARSxAR_INV)),
                                    BYTE0 (mSTATEMENT_ARRAYNESS))));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mEJECT_INVARSxPUT_ADLP, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF PUT_ADLP THEN (5333)
  if (1 & (bitToFixed (getBIT (8, mEJECT_INVARSxPUT_ADLP))))
    // AR_PTR = GET_ADLP(NODE(NEW_NODE_PTR) &  65535); (5334)
    {
      descriptor_t *bitRHS
          = (putBITp (
                 16, mGET_ADLPxPTR,
                 fixedToBit (
                     32,
                     (int32_t)(xAND (
                         getFIXED (mNODE + 4 * COREHALFWORD (mNEW_NODE_PTR)),
                         65535)))),
             GET_ADLP (0));
      putBIT (16, mAR_PTR, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF AR_PTR < 0 THEN (5335)
  if (1 & (xLT (COREHALFWORD (mAR_PTR), 0)))
    // PUT_ADLP = 0; (5336)
    {
      int32_t numberRHS = (int32_t)(0);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (8, mEJECT_INVARSxPUT_ADLP, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF (PUT_ADLP OR LOOPY_OPS) AND NOT_TSUB THEN (5337)
  if (1
      & (xAND (xOR (BYTE0 (mEJECT_INVARSxPUT_ADLP), BYTE0 (mLOOPY_OPS)),
               BYTE0 (mEJECT_INVARSxNOT_TSUB))))
    // DO; (5338)
    {
    rs1:;
      // IF PUT_ADLP THEN (5339)
      if (1 & (bitToFixed (getBIT (8, mEJECT_INVARSxPUT_ADLP))))
        // TEMP,OP# = NO_OPERANDS(AR_PTR) + 2; (5340)
        {
          int32_t numberRHS
              = (int32_t)(xadd (bitToFixed ((putBITp (16, mNO_OPERANDSxPTR,
                                                      getBIT (16, mAR_PTR)),
                                             NO_OPERANDS (0))),
                                2));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mEJECT_INVARSxTEMP, bitRHS);
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mEJECT_INVARSxOPp, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (5341)
      else
        // TEMP = 0; (5342)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mEJECT_INVARSxTEMP, bitRHS);
          bitRHS->inUse = 0;
        }
      // IF LOOPY_OPS THEN (5343)
      if (1 & (bitToFixed (getBIT (8, mLOOPY_OPS))))
        // TEMP = TEMP + 3; (5344)
        {
          int32_t numberRHS
              = (int32_t)(xadd (COREHALFWORD (mEJECT_INVARSxTEMP), 3));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mEJECT_INVARSxTEMP, bitRHS);
          bitRHS->inUse = 0;
        }
      // CALL PUSH_HALMAT(PULL_LOOP_HEAD(0),TEMP); (5345)
      {
        putBITp (16, mPUSH_HALMATxSTART,
                 getBIT (16, getFIXED (mLEVEL_STACK_VARS) + 11 * (0) + 4
                                 + 2 * (0)));
        putBITp (16, mPUSH_HALMATxDISP, getBIT (16, mEJECT_INVARSxTEMP));
        PUSH_HALMAT (0);
      }
      // TEMP,TEMP2,PULL_LOOP_HEAD(0) = PULL_LOOP_HEAD(0)-PUT_ADLP-LOOPY_OPS;
      // (5346)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            xsubtract (COREHALFWORD (getFIXED (mLEVEL_STACK_VARS) + 11 * (0)
                                     + 4 + 2 * (0)),
                       BYTE0 (mEJECT_INVARSxPUT_ADLP)),
            BYTE0 (mLOOPY_OPS)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mEJECT_INVARSxTEMP, bitRHS);
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mEJECT_INVARSxTEMP2, bitRHS);
        putBIT (16, getFIXED (mLEVEL_STACK_VARS) + 11 * (0) + 4 + 2 * (0),
                fixedToBit (16, numberRHS));
        bitRHS->inUse = 0;
      }
      // IF LOOPY_OPS THEN (5347)
      if (1 & (bitToFixed (getBIT (8, mLOOPY_OPS))))
        // DO; (5348)
        {
        rs1s1:;
          // TMP = TAG_BIT; (5349)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mTAG_BIT));
            putFIXED (mEJECT_INVARSxTMP, numberRHS);
          }
          // TEMP = TEMP - 2; (5350)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (COREHALFWORD (mEJECT_INVARSxTEMP), 2));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mEJECT_INVARSxTEMP, bitRHS);
            bitRHS->inUse = 0;
          }
          // OPR(TEMP) = VDLP; (5351)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mVDLP));
            putFIXED (mOPR + 4 * (COREHALFWORD (mEJECT_INVARSxTEMP)),
                      numberRHS);
          }
          // OPR(TEMP + 1) = IMD_0 | SHL(LOOP_DIMENSION,16) | VDLP_TAG |
          // OUTSIDE_REF_TAG; (5352)
          {
            int32_t numberRHS = (int32_t)(xOR (
                xOR (xOR (COREHALFWORD (mIMD_0),
                          SHL (COREHALFWORD (mLOOP_DIMENSION), 16)),
                     COREHALFWORD (mVDLP_TAG)),
                COREHALFWORD (mOUTSIDE_REF_TAG)));
            putFIXED (mOPR + 4 * (xadd (COREHALFWORD (mEJECT_INVARSxTEMP), 1)),
                      numberRHS);
          }
          // OPR(TEMP2) = VDLE; (5353)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mVDLE));
            putFIXED (mOPR + 4 * (COREHALFWORD (mEJECT_INVARSxTEMP2)),
                      numberRHS);
          }
          // TEMP2 = TEMP2 + 1; (5354)
          {
            int32_t numberRHS
                = (int32_t)(xadd (COREHALFWORD (mEJECT_INVARSxTEMP2), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mEJECT_INVARSxTEMP2, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
      // ELSE (5355)
      else
        // TMP = 0; (5356)
        {
          int32_t numberRHS = (int32_t)(0);
          putFIXED (mEJECT_INVARSxTMP, numberRHS);
        }
      // IF PUT_ADLP THEN (5357)
      if (1 & (bitToFixed (getBIT (8, mEJECT_INVARSxPUT_ADLP))))
        // DO; (5358)
        {
        rs1s2:;
          // TMP = TMP | OUT_OF_ARRAY_TAG; (5359)
          {
            int32_t numberRHS
                = (int32_t)(xOR (getFIXED (mEJECT_INVARSxTMP),
                                 COREHALFWORD (mOUT_OF_ARRAY_TAG)));
            putFIXED (mEJECT_INVARSxTMP, numberRHS);
          }
          // TEMP = TEMP - OP# + 1; (5360)
          {
            int32_t numberRHS
                = (int32_t)(xadd (xsubtract (COREHALFWORD (mEJECT_INVARSxTEMP),
                                             COREHALFWORD (mEJECT_INVARSxOPp)),
                                  1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mEJECT_INVARSxTEMP, bitRHS);
            bitRHS->inUse = 0;
          }
          // DO FOR K = 0 TO OP# - 2; (5361)
          {
            int32_t from119, to119, by119;
            from119 = 0;
            to119 = xsubtract (COREHALFWORD (mEJECT_INVARSxOPp), 2);
            by119 = 1;
            for (putBIT (16, mEJECT_INVARSxK, fixedToBit (16, from119));
                 bitToFixed (getBIT (16, mEJECT_INVARSxK)) <= to119; putBIT (
                     16, mEJECT_INVARSxK,
                     fixedToBit (16, bitToFixed (getBIT (16, mEJECT_INVARSxK))
                                         + by119)))
              {
                // OPR(TEMP + K) = OPR(AR_PTR + K); (5362)
                {
                  int32_t numberRHS = (int32_t)(getFIXED (
                      mOPR
                      + 4
                            * xadd (COREHALFWORD (mAR_PTR),
                                    COREHALFWORD (mEJECT_INVARSxK))));
                  putFIXED (
                      mOPR
                          + 4
                                * (xadd (COREHALFWORD (mEJECT_INVARSxTEMP),
                                         COREHALFWORD (mEJECT_INVARSxK))),
                      numberRHS);
                }
              }
          } // End of DO for-loop block
          // OPR(TEMP + OP# - 2) = OPR(TEMP + OP# - 2) | OUTSIDE_REF_TAG;
          // (5363)
          {
            int32_t numberRHS = (int32_t)(xOR (
                getFIXED (
                    mOPR
                    + 4
                          * xsubtract (xadd (COREHALFWORD (mEJECT_INVARSxTEMP),
                                             COREHALFWORD (mEJECT_INVARSxOPp)),
                                       2)),
                COREHALFWORD (mOUTSIDE_REF_TAG)));
            putFIXED (mOPR
                          + 4
                                * (xsubtract (
                                    xadd (COREHALFWORD (mEJECT_INVARSxTEMP),
                                          COREHALFWORD (mEJECT_INVARSxOPp)),
                                    2)),
                      numberRHS);
          }
          // OPR(TEMP) = OPR(TEMP) &  16777215; (5364)
          {
            int32_t numberRHS = (int32_t)(xAND (
                getFIXED (mOPR + 4 * COREHALFWORD (mEJECT_INVARSxTEMP)),
                16777215));
            putFIXED (mOPR + 4 * (COREHALFWORD (mEJECT_INVARSxTEMP)),
                      numberRHS);
          }
          // OPR(TEMP2) = DLPE_WORD; (5365)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mDLPE_WORD));
            putFIXED (mOPR + 4 * (COREHALFWORD (mEJECT_INVARSxTEMP2)),
                      numberRHS);
          }
        es1s2:;
        } // End of DO block
    es1:;
    } // End of DO block
  // TEMP = LAST_OPERAND(GROUP_CSE(NEW_NODE_PTR)); (5366)
  {
    descriptor_t *bitRHS
        = (putBITp (
               16, mLAST_OPERANDxPTR,
               fixedToBit (32, (int32_t)((putBITp (16, mGROUP_CSExINX,
                                                   getBIT (16, mNEW_NODE_PTR)),
                                          GROUP_CSE (0))))),
           LAST_OPERAND (0));
    putBIT (16, mEJECT_INVARSxTEMP, bitRHS);
    bitRHS->inUse = 0;
  }
  // TEMP2 = NODE(NEW_NODE_PTR) &  65535; (5367)
  {
    int32_t numberRHS = (int32_t)(xAND (
        getFIXED (mNODE + 4 * COREHALFWORD (mNEW_NODE_PTR)), 65535));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mEJECT_INVARSxTEMP2, bitRHS);
    bitRHS->inUse = 0;
  }
  // OPR(TEMP2) = OPR(TEMP2) | TMP; (5368)
  {
    int32_t numberRHS = (int32_t)(xOR (
        getFIXED (mOPR + 4 * COREHALFWORD (mEJECT_INVARSxTEMP2)),
        getFIXED (mEJECT_INVARSxTMP)));
    putFIXED (mOPR + 4 * (COREHALFWORD (mEJECT_INVARSxTEMP2)), numberRHS);
  }
  // TEMP2 = PULL_LOOP_HEAD(0); (5369)
  {
    descriptor_t *bitRHS
        = getBIT (16, getFIXED (mLEVEL_STACK_VARS) + 11 * (0) + 4 + 2 * (0));
    putBIT (16, mEJECT_INVARSxTEMP2, bitRHS);
    bitRHS->inUse = 0;
  }
  // HIGH = BOTTOM(HALMAT_NODE_START,PULL_LOOP_HEAD(0)); (5370)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (16, mBOTTOMxPTR, getBIT (16, mHALMAT_NODE_START)),
        putBITp (16, mBOTTOMxORIG,
                 getBIT (16, getFIXED (mLEVEL_STACK_VARS) + 11 * (0) + 4
                                 + 2 * (0))),
        BOTTOM (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mEJECT_INVARSxHIGH, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL MOVE_LIMB(PULL_LOOP_HEAD(0),HIGH,  TEMP - HIGH + 1); (5371)
  {
    putBITp (
        16, mMOVE_LIMBxLOW,
        getBIT (16, getFIXED (mLEVEL_STACK_VARS) + 11 * (0) + 4 + 2 * (0)));
    putBITp (16, mMOVE_LIMBxHIGH, getBIT (16, mEJECT_INVARSxHIGH));
    putBITp (16, mMOVE_LIMBxBIG,
             fixedToBit (32, (int32_t)(xadd (
                                 xsubtract (COREHALFWORD (mEJECT_INVARSxTEMP),
                                            COREHALFWORD (mEJECT_INVARSxHIGH)),
                                 1))));
    MOVE_LIMB (0);
  }
  // IF WATCH THEN (5372)
  if (1 & (bitToFixed (getBIT (8, mWATCH))))
    // CALL PRINT_SENTENCE(TEMP2); (5373)
    {
      putBITp (16, mPRINT_SENTENCExPTR, getBIT (16, mEJECT_INVARSxTEMP2));
      PRINT_SENTENCE (0);
    }
  // RETURN NEW_NODE_BEGINNING; (5374)
  {
    reentryGuard = 0;
    return COREHALFWORD (mEJECT_INVARSxNEW_NODE_BEGINNING);
  }
}
