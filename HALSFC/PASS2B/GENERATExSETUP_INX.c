/*
  File GENERATExSETUP_INX.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExSETUP_INX (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExSETUP_INX");
  // IF CLASS > 0 THEN (8162)
  if (1 & (xGT (COREHALFWORD (mCLASS), 0)))
    // RETURN; (8163)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF LEFTOP ~= 0 THEN (8164)
  if (1 & (xNEQ (COREHALFWORD (mLEFTOP), 0)))
    // DO; (8165)
    {
    rs1:;
      // IF FORM(LEFTOP) ~= VAC THEN (8166)
      if (1
          & (xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                 + 73 * (COREHALFWORD (mLEFTOP)) + 32
                                 + 2 * (0)),
                   BYTE0 (mVAC))))
        // DO; (8167)
        {
        rs1s1:;
          // IF INX_MUL(LEFTOP) = 1 THEN (8168)
          if (1
              & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                    + 73 * (COREHALFWORD (mLEFTOP)) + 36
                                    + 2 * (0)),
                      1)))
            // CALL FORCE_ACCUMULATOR(LEFTOP, INTEGER, INDEX_REG); (8169)
            {
              putBITp (16, mGENERATExFORCE_ACCUMULATORxOP,
                       getBIT (16, mLEFTOP));
              putBITp (16, mGENERATExFORCE_ACCUMULATORxOPTYPE,
                       getBIT (8, mINTEGER));
              putBITp (16, mGENERATExFORCE_ACCUMULATORxACCLASS,
                       fixedToBit (32, (int32_t)(4)));
              GENERATExFORCE_ACCUMULATOR (0);
            }
          // ELSE (8170)
          else
            // DO; (8171)
            {
            rs1s1s1:;
              // RIGHTOP = GET_INTEGER_LITERAL(0); (8172)
              {
                descriptor_t *bitRHS
                    = (putFIXED (mGENERATExGET_INTEGER_LITERALxVALUE, 0),
                       GENERATExGET_INTEGER_LITERAL (0));
                putBIT (16, mRIGHTOP, bitRHS);
                bitRHS->inUse = 0;
              }
              // CALL SUBSCRIPT2_MULT(INX_MUL(LEFTOP)); (8173)
              {
                putBITp (16, mGENERATExSUBSCRIPT2_MULTxMULT,
                         getBIT (16, getFIXED (mIND_STACK)
                                         + 73 * (COREHALFWORD (mLEFTOP)) + 36
                                         + 2 * (0)));
                GENERATExSUBSCRIPT2_MULT (0);
              }
              // CALL RETURN_STACK_ENTRY(RIGHTOP); (8174)
              {
                putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                         getBIT (16, mRIGHTOP));
                GENERATExRETURN_STACK_ENTRY (0);
              }
            es1s1s1:;
            } // End of DO block
        es1s1:;
        } // End of DO block
      // IF REG(LEFTOP) = 0 THEN (8175)
      if (1
          & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mLEFTOP)) + 46
                                + 2 * (0)),
                  0)))
        // CALL NEW_REG(LEFTOP, 1); (8176)
        {
          putBITp (16, mGENERATExNEW_REGxPTR, getBIT (16, mLEFTOP));
          putBITp (1, mGENERATExNEW_REGxUSED, fixedToBit (32, (int32_t)(1)));
          GENERATExNEW_REG (0);
        }
      // CALL FIX_TERM_INX(ALCOP, LEFTOP); (8177)
      {
        putBITp (16, mGENERATExFIX_TERM_INXxOP, getBIT (16, mRESULT));
        putBITp (16, mGENERATExFIX_TERM_INXxPTR, getBIT (16, mLEFTOP));
        GENERATExFIX_TERM_INX (0);
      }
    es1:;
    } // End of DO block
  // CALL FIX_STRUCT_INX(LEFTOP, ALCOP); (8178)
  {
    putBITp (16, mGENERATExFIX_STRUCT_INXxIX, getBIT (16, mLEFTOP));
    putBITp (16, mGENERATExFIX_STRUCT_INXxOP, getBIT (16, mRESULT));
    GENERATExFIX_STRUCT_INX (0);
  }
  // TMP = BIGHTS(TYPE(ALCOP)); (8179)
  {
    descriptor_t *bitRHS
        = getBIT (8, mBIGHTS
                         + 1
                               * COREHALFWORD (getFIXED (mIND_STACK)
                                               + 73 * (COREHALFWORD (mRESULT))
                                               + 50 + 2 * (0)));
    int32_t numberRHS;
    numberRHS = bitToFixed (bitRHS);
    putFIXED (mTMP, numberRHS);
    bitRHS->inUse = 0;
  }
  // INX_CON(ALCOP) = INX_CON(ALCOP) * TMP + STRUCT_CON(ALCOP); (8180)
  {
    int32_t numberRHS = (int32_t)(xadd (
        xmultiply (getFIXED (getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mRESULT)) + 4 + 4 * (0)),
                   getFIXED (mTMP)),
        getFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 8
                  + 4 * (0))));
    putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 4
                  + 4 * (0),
              numberRHS);
  }
  // STRUCT_CON(ALCOP) = 0; (8181)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 8
                  + 4 * (0),
              numberRHS);
  }
  // STRUCT_INX(ALCOP) = 2; (8182)
  {
    int32_t numberRHS = (int32_t)(2);
    putBIT (8,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 66
                + 1 * (0),
            fixedToBit (8, numberRHS));
  }
  // SIMPLE_AIA_ADJUST=TRUE; (8183)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExSIMPLE_AIA_ADJUST, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF ~DECLMODE THEN (8184)
  if (1 & (xNOT (BYTE0 (mDECLMODE))))
    // CALL SUBSCRIPT_RANGE_CHECK(ALCOP); (8185)
    {
      putBITp (16, mGENERATExSUBSCRIPT_RANGE_CHECKxOP, getBIT (16, mRESULT));
      GENERATExSUBSCRIPT_RANGE_CHECK (0);
    }
  // SIMPLE_AIA_ADJUST=FALSE; (8186)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExSIMPLE_AIA_ADJUST, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
