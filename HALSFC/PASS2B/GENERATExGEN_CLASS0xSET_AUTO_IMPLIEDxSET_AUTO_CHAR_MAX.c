/*
  File GENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_CHAR_MAX.c generated by
  XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_CHAR_MAX (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (
      reentryGuard, "GENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_CHAR_MAX");
  // RESULT = SET_OPERAND(PTR1); (11633)
  {
    descriptor_t *bitRHS
        = (putBITp (
               16, mGENERATExSET_OPERANDxOP,
               getBIT (
                   16,
                   mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_CHAR_MAXxPTR1)),
           GENERATExSET_OPERAND (0));
    putBIT (16, mRESULT, bitRHS);
    bitRHS->inUse = 0;
  }
  // SIZE(RESULT) = SYT_DIMS(PTR2); (11634)
  {
    descriptor_t *bitRHS = getBIT (
        16,
        getFIXED (mSYM_TAB)
            + 34
                  * (COREHALFWORD (
                      mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_CHAR_MAXxPTR2))
            + 18 + 2 * (0));
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 48
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // INX_CON(RESULT) = CON; (11635)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_CHAR_MAXxCON));
    putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 4
                  + 4 * (0),
              numberRHS);
  }
  // J = FINDAC(FIXED_ACC); (11636)
  {
    descriptor_t *bitRHS = (putBITp (16, mGENERATExFINDACxRCLASS,
                                     fixedToBit (32, (int32_t)(3))),
                            GENERATExFINDAC (0));
    putBIT (16, mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxJ, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL LOAD_NUM(J, SHL(SIZE(RESULT), 8)); (11637)
  {
    putBITp (16, mGENERATExLOAD_NUMxR,
             getBIT (16, mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxJ));
    putFIXED (
        mGENERATExLOAD_NUMxNUM,
        SHL (COREHALFWORD (getFIXED (mIND_STACK)
                           + 73 * (COREHALFWORD (mRESULT)) + 48 + 2 * (0)),
             8));
    GENERATExLOAD_NUM (0);
  }
  // I = LUMP_ARRAYSIZE(PTR2); (11638)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (
            16, mGENERATExLUMP_ARRAYSIZExOP,
            getBIT (
                16,
                mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxSET_AUTO_CHAR_MAXxPTR2)),
        GENERATExLUMP_ARRAYSIZE (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxI, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF I > 1 THEN (11639)
  if (1 & (xGT (COREHALFWORD (mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxI), 1)))
    // DO; (11640)
    {
    rs1:;
      // CALL FORCE_ADDRESS(-1, RESULT, 1); (11641)
      {
        putBITp (16, mGENERATExFORCE_ADDRESSxTR,
                 fixedToBit (32, (int32_t)(-1)));
        putBITp (16, mGENERATExFORCE_ADDRESSxOP, getBIT (16, mRESULT));
        putBITp (1, mGENERATExFORCE_ADDRESSxFLAG,
                 fixedToBit (32, (int32_t)(1)));
        GENERATExFORCE_ADDRESS (0);
      }
      // INDEX = FINDAC(INDEX_REG); (11642)
      {
        descriptor_t *bitRHS = (putBITp (16, mGENERATExFINDACxRCLASS,
                                         fixedToBit (32, (int32_t)(4))),
                                GENERATExFINDAC (0));
        putBIT (16, mINDEX, bitRHS);
        bitRHS->inUse = 0;
      }
      // BASE(RESULT) = REG(RESULT); (11643)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT))
                              + 46 + 2 * (0));
        putBIT (16,
                getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 22
                    + 2 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // DISP(RESULT), INX_CON(RESULT) = 0; (11644)
      {
        int32_t numberRHS = (int32_t)(0);
        putBIT (16,
                getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 30
                    + 2 * (0),
                fixedToBit (16, numberRHS));
        putFIXED (getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 4
                      + 4 * (0),
                  numberRHS);
      }
      // FORM(RESULT) = CSYM; (11645)
      {
        descriptor_t *bitRHS = getBIT (8, mCSYM);
        putBIT (16,
                getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRESULT)) + 32
                    + 2 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL LOAD_NUM(INDEX, I, 1); (11646)
      {
        putBITp (16, mGENERATExLOAD_NUMxR, getBIT (16, mINDEX));
        putFIXED (mGENERATExLOAD_NUMxNUM,
                  COREHALFWORD (mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxI));
        putBITp (1, mGENERATExLOAD_NUMxFLAG, fixedToBit (32, (int32_t)(1)));
        GENERATExLOAD_NUM (0);
      }
      // FIRSTLABEL = GETSTATNO; (11647)
      {
        descriptor_t *bitRHS = GETSTATNO (0);
        putBIT (16, mFIRSTLABEL, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL SET_LABEL(FIRSTLABEL, 1); (11648)
      {
        putBITp (16, mGENERATExSET_LABELxSTMTNO, getBIT (16, mFIRSTLABEL));
        putBITp (1, mGENERATExSET_LABELxFLAG1, fixedToBit (32, (int32_t)(1)));
        GENERATExSET_LABEL (0);
      }
      // CALL EMITOP(STH, J, RESULT); (11649)
      {
        putBITp (16, mGENERATExEMITOPxINST, getBIT (8, mSTH));
        putBITp (16, mGENERATExEMITOPxXREG,
                 getBIT (16, mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxJ));
        putBITp (16, mGENERATExEMITOPxOP, getBIT (16, mRESULT));
        GENERATExEMITOP (0);
      }
      // CALL EMITP(AHI, BASE(RESULT), 0, 0, CS(SIZE(RESULT) + 2)); (11650)
      {
        putBITp (16, mGENERATExEMITPxINST, getBIT (8, mAHI));
        putBITp (16, mGENERATExEMITPxXREG,
                 getBIT (16, getFIXED (mIND_STACK)
                                 + 73 * (COREHALFWORD (mRESULT)) + 22
                                 + 2 * (0)));
        putBITp (16, mGENERATExEMITPxINDEX, fixedToBit (32, (int32_t)(0)));
        putBITp (16, mGENERATExEMITPxFLAG, fixedToBit (32, (int32_t)(0)));
        putBITp (
            16, mGENERATExEMITPxPTR,
            fixedToBit (
                32,
                (int32_t)((putFIXED (mCSxLEN,
                                     xadd (COREHALFWORD (
                                               getFIXED (mIND_STACK)
                                               + 73 * (COREHALFWORD (mRESULT))
                                               + 48 + 2 * (0)),
                                           2)),
                           CS (0)))));
        GENERATExEMITP (0);
      }
      // CALL EMITPFW(BCT, INDEX, GETSTMTLBL(FIRSTLABEL)); (11651)
      {
        putBITp (16, mGENERATExEMITPFWxINST, getBIT (8, mBCT));
        putBITp (16, mGENERATExEMITPFWxXREG, getBIT (16, mINDEX));
        putBITp (16, mGENERATExEMITPFWxPTR,
                 (putFIXED (mGENERATExGETSTMTLBLxSTATNO,
                            COREHALFWORD (mFIRSTLABEL)),
                  GENERATExGETSTMTLBL (0)));
        GENERATExEMITPFW (0);
      }
      // USAGE(INDEX), USAGE(REG(RESULT)) = 0; (11652)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mUSAGE + 2 * (COREHALFWORD (mINDEX)), bitRHS);
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16,
                mUSAGE
                    + 2
                          * (COREHALFWORD (getFIXED (mIND_STACK)
                                           + 73 * (COREHALFWORD (mRESULT)) + 46
                                           + 2 * (0))),
                bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (11653)
  else
    // DO; (11654)
    {
    rs2:;
      // CALL GUARANTEE_ADDRESSABLE(RESULT, STH); (11655)
      {
        putBITp (16, mGENERATExGUARANTEE_ADDRESSABLExOP, getBIT (16, mRESULT));
        putBITp (16, mGENERATExGUARANTEE_ADDRESSABLExINST, getBIT (8, mSTH));
        GENERATExGUARANTEE_ADDRESSABLE (0);
      }
      // CALL EMITOP(STH, J, RESULT); (11656)
      {
        putBITp (16, mGENERATExEMITOPxINST, getBIT (8, mSTH));
        putBITp (16, mGENERATExEMITOPxXREG,
                 getBIT (16, mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxJ));
        putBITp (16, mGENERATExEMITOPxOP, getBIT (16, mRESULT));
        GENERATExEMITOP (0);
      }
    es2:;
    } // End of DO block
  // USAGE(J) = USAGE(J) - 2; (11657)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        COREHALFWORD (
            mUSAGE
            + 2 * COREHALFWORD (mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxJ)),
        2));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16,
            mUSAGE
                + 2 * (COREHALFWORD (mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxJ)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL RETURN_STACK_ENTRY(RESULT); (11658)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP, getBIT (16, mRESULT));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
