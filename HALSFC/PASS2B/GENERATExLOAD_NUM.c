/*
  File GENERATExLOAD_NUM.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExLOAD_NUM (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExLOAD_NUM");
  // LITOP = GET_INTEGER_LITERAL(NUM); (5005)
  {
    descriptor_t *bitRHS = (putFIXED (mGENERATExGET_INTEGER_LITERALxVALUE,
                                      getFIXED (mGENERATExLOAD_NUMxNUM)),
                            GENERATExGET_INTEGER_LITERAL (0));
    putBIT (16, mGENERATExLOAD_NUMxLITOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // TYPE(LITOP) = TYPE(LITOP) & (~8) | FLAG & 8; (5006)
  {
    int32_t numberRHS = (int32_t)(xOR (
        xAND (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExLOAD_NUMxLITOP))
                            + 50 + 2 * (0)),
              4294967287),
        xAND (BYTE0 (mGENERATExLOAD_NUMxFLAG), 8)));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExLOAD_NUMxLITOP)) + 50
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // RT = SEARCH_REGS(LITOP); (5007)
  {
    int32_t numberRHS
        = (int32_t)((putBITp (16, mGENERATExSEARCH_REGSxOP,
                              getBIT (16, mGENERATExLOAD_NUMxLITOP)),
                     GENERATExSEARCH_REGS (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExLOAD_NUMxRT, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF RT >= 0 THEN (5008)
  if (1 & (xGE (COREHALFWORD (mGENERATExLOAD_NUMxRT), 0)))
    // DO; (5009)
    {
    rs1:;
      // IF R<0 THEN (5010)
      if (1 & (xLT (COREHALFWORD (mGENERATExLOAD_NUMxR), 0)))
        // DO; (5011)
        {
        rs1s1:;
          // USAGE(RT) = USAGE(RT) + 2; (5012)
          {
            int32_t numberRHS = (int32_t)(xadd (
                COREHALFWORD (mUSAGE
                              + 2 * COREHALFWORD (mGENERATExLOAD_NUMxRT)),
                2));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mUSAGE + 2 * (COREHALFWORD (mGENERATExLOAD_NUMxRT)),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL RETURN_STACK_ENTRY(LITOP); (5013)
          {
            putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                     getBIT (16, mGENERATExLOAD_NUMxLITOP));
            GENERATExRETURN_STACK_ENTRY (0);
          }
          // FLAG = FALSE; (5014)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mGENERATExLOAD_NUMxFLAG, bitRHS);
            bitRHS->inUse = 0;
          }
          // RETURN RT; (5015)
          {
            reentryGuard = 0;
            return COREHALFWORD (mGENERATExLOAD_NUMxRT);
          }
        es1s1:;
        } // End of DO block
      // ELSE (5016)
      else
        // IF RT ~= R THEN (5017)
        if (1
            & (xNEQ (COREHALFWORD (mGENERATExLOAD_NUMxRT),
                     COREHALFWORD (mGENERATExLOAD_NUMxR))))
          // CALL EMITRR(LR, R, RT); (5018)
          {
            putBITp (16, mGENERATExEMITRRxINST, getBIT (8, mLR));
            putBITp (16, mGENERATExEMITRRxREG1,
                     getBIT (16, mGENERATExLOAD_NUMxR));
            putBITp (16, mGENERATExEMITRRxREG2,
                     getBIT (16, mGENERATExLOAD_NUMxRT));
            GENERATExEMITRR (0);
          }
    es1:;
    } // End of DO block
  // ELSE (5019)
  else
    // DO; (5020)
    {
    rs2:;
      // IF R<0 THEN (5021)
      if (1 & (xLT (COREHALFWORD (mGENERATExLOAD_NUMxR), 0)))
        // R = FINDAC(INDEX_REG); (5022)
        {
          descriptor_t *bitRHS = (putBITp (16, mGENERATExFINDACxRCLASS,
                                           fixedToBit (32, (int32_t)(4))),
                                  GENERATExFINDAC (0));
          putBIT (16, mGENERATExLOAD_NUMxR, bitRHS);
          bitRHS->inUse = 0;
        }
      // IF NUM = 0 THEN (5023)
      if (1 & (xEQ (getFIXED (mGENERATExLOAD_NUMxNUM), 0)))
        // CALL EMITRR(XR, R, R); (5024)
        {
          putBITp (16, mGENERATExEMITRRxINST, getBIT (8, mXR));
          putBITp (16, mGENERATExEMITRRxREG1,
                   getBIT (16, mGENERATExLOAD_NUMxR));
          putBITp (16, mGENERATExEMITRRxREG2,
                   getBIT (16, mGENERATExLOAD_NUMxR));
          GENERATExEMITRR (0);
        }
      // ELSE (5025)
      else
        // IF TYPE(LITOP) = INTEGER THEN (5026)
        if (1
            & (xEQ (
                COREHALFWORD (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExLOAD_NUMxLITOP))
                              + 50 + 2 * (0)),
                BYTE0 (mINTEGER))))
          // DO; (5027)
          {
          rs2s1:;
            // IF NUM >= -2 & NUM <= 13 & SELF_ALIGNING & COMPACT_CODE THEN
            // (5028)
            if (1
                & (xAND (
                    xAND (xAND (xGE (getFIXED (mGENERATExLOAD_NUMxNUM), -2),
                                xLE (getFIXED (mGENERATExLOAD_NUMxNUM), 13)),
                          BYTE0 (mSELF_ALIGNING)),
                    BYTE0 (mCOMPACT_CODE))))
              // CALL EMITRR(LFXI, R, NUM+2); (5029)
              {
                putBITp (16, mGENERATExEMITRRxINST, getBIT (8, mLFXI));
                putBITp (16, mGENERATExEMITRRxREG1,
                         getBIT (16, mGENERATExLOAD_NUMxR));
                putBITp (16, mGENERATExEMITRRxREG2,
                         fixedToBit (
                             32, (int32_t)(xadd (
                                     getFIXED (mGENERATExLOAD_NUMxNUM), 2))));
                GENERATExEMITRR (0);
              }
            // ELSE (5030)
            else
              // CALL EMITP(LHI, R, 0, 0, NUM); (5031)
              {
                putBITp (16, mGENERATExEMITPxINST, getBIT (8, mLHI));
                putBITp (16, mGENERATExEMITPxXREG,
                         getBIT (16, mGENERATExLOAD_NUMxR));
                putBITp (16, mGENERATExEMITPxINDEX,
                         fixedToBit (32, (int32_t)(0)));
                putBITp (16, mGENERATExEMITPxFLAG,
                         fixedToBit (32, (int32_t)(0)));
                putBITp (16, mGENERATExEMITPxPTR,
                         fixedToBit (32, (int32_t)(getFIXED (
                                             mGENERATExLOAD_NUMxNUM))));
                GENERATExEMITP (0);
              }
          es2s1:;
          } // End of DO block
        // ELSE (5032)
        else
          // DO; (5033)
          {
          rs2s2:;
            // CALL SAVE_LITERAL(LITOP, TYPE(LITOP)); (5034)
            {
              putBITp (16, mGENERATExSAVE_LITERALxOP,
                       getBIT (16, mGENERATExLOAD_NUMxLITOP));
              putBITp (
                  16, mGENERATExSAVE_LITERALxOPTYPE,
                  getBIT (16,
                          getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExLOAD_NUMxLITOP))
                              + 50 + 2 * (0)));
              GENERATExSAVE_LITERAL (0);
            }
            // CALL EMIT_BY_MODE(LOAD, R, LITOP, TYPE(LITOP)); (5035)
            {
              putBITp (16, mGENERATExEMIT_BY_MODExOP,
                       getBIT (16, mGENERATExLOAD));
              putBITp (16, mGENERATExEMIT_BY_MODExR,
                       getBIT (16, mGENERATExLOAD_NUMxR));
              putBITp (16, mGENERATExEMIT_BY_MODExOP2,
                       getBIT (16, mGENERATExLOAD_NUMxLITOP));
              putBITp (
                  16, mGENERATExEMIT_BY_MODExMODE,
                  getBIT (16,
                          getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExLOAD_NUMxLITOP))
                              + 50 + 2 * (0)));
              GENERATExEMIT_BY_MODE (0);
            }
          es2s2:;
          } // End of DO block
    es2:;
    } // End of DO block
  // IF ~FLAG THEN (5036)
  if (1 & (xNOT (BYTE0 (mGENERATExLOAD_NUMxFLAG))))
    // DO; (5037)
    {
    rs3:;
      // CALL SET_USAGE(R, LIT, NUM); (5038)
      {
        putBITp (16, mGENERATExSET_USAGExR, getBIT (16, mGENERATExLOAD_NUMxR));
        putBITp (16, mGENERATExSET_USAGExRFORM, getBIT (8, mLIT));
        putFIXED (mGENERATExSET_USAGExRVAR, getFIXED (mGENERATExLOAD_NUMxNUM));
        GENERATExSET_USAGE (0);
      }
      // R_TYPE(R) = TYPE(LITOP); (5039)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExLOAD_NUMxLITOP))
                              + 50 + 2 * (0));
        putBIT (8, mR_TYPE + 1 * (COREHALFWORD (mGENERATExLOAD_NUMxR)),
                bitRHS);
        bitRHS->inUse = 0;
      }
    es3:;
    } // End of DO block
  // FLAG = FALSE; (5040)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExLOAD_NUMxFLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL RETURN_STACK_ENTRY(LITOP); (5041)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
             getBIT (16, mGENERATExLOAD_NUMxLITOP));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  // CALL CHECK_LINKREG(R); (5042)
  {
    putBITp (16, mGENERATExCHECK_LINKREGxR, getBIT (16, mGENERATExLOAD_NUMxR));
    GENERATExCHECK_LINKREG (0);
  }
  // CALL CLEAR_INX(R); (5043)
  {
    putBITp (16, mGENERATExCLEAR_INXxR, getBIT (16, mGENERATExLOAD_NUMxR));
    GENERATExCLEAR_INX (0);
  }
  // RETURN R; (5044)
  {
    reentryGuard = 0;
    return COREHALFWORD (mGENERATExLOAD_NUMxR);
  }
}
