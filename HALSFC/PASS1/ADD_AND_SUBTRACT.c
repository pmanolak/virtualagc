/*
  File ADD_AND_SUBTRACT.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
ADD_AND_SUBTRACT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ADD_AND_SUBTRACT");
  // IF ARITH_LITERAL(MP,SP) THEN (7573)
  if (1
      & (bitToFixed ((putBITp (16, mARITH_LITERALxLOC1,
                               fixedToBit (32, (int32_t)(getFIXED (mMP)))),
                      putBITp (16, mARITH_LITERALxLOC2,
                               fixedToBit (32, (int32_t)(getFIXED (mSP)))),
                      ARITH_LITERAL (0)))))
    // DO; (7574)
    {
    rs1:;
      // IF MONITOR(9,MODE+1) THEN (7575)
      if (1 & (MONITOR9 (xadd (COREHALFWORD (mADD_AND_SUBTRACTxMODE), 1))))
        // DO; (7576)
        {
        rs1s1:;
          // CALL ERROR(CLASS_VA,MODE+1); (7577)
          {
            putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_VA));
            putBITp (8, mERRORxNUM,
                     fixedToBit (
                         32, (int32_t)(xadd (
                                 COREHALFWORD (mADD_AND_SUBTRACTxMODE), 1))));
            ERROR (0);
          }
          // GO TO AS_FAIL; (7578)
          goto AS_FAIL;
        es1s1:;
        } // End of DO block
      // LOC_P(PTR(MP))=SAVE_LITERAL(1,DW_AD); (7579)
      {
        int32_t numberRHS = (int32_t)((
            putBITp (16, mSAVE_LITERALxTYPE, fixedToBit (32, (int32_t)(1))),
            putFIXED (mSAVE_LITERALxVAL, getFIXED (mDW_AD)),
            SAVE_LITERAL (0)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mLOC_P + 2 * (COREHALFWORD (mPTR + 2 * getFIXED (mMP))),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // PSEUDO_TYPE(PTR(MP))=LIT_RESULT_TYPE(MP,SP); (7580)
      {
        int32_t numberRHS
            = (int32_t)((putBITp (16, mLIT_RESULT_TYPExLOC1,
                                  fixedToBit (32, (int32_t)(getFIXED (mMP)))),
                         putBITp (16, mLIT_RESULT_TYPExLOC2,
                                  fixedToBit (32, (int32_t)(getFIXED (mSP)))),
                         LIT_RESULT_TYPE (0)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8,
                mPSEUDO_TYPE + 1 * (COREHALFWORD (mPTR + 2 * getFIXED (mMP))),
                bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (7581)
  else
    // DO; (7582)
    {
    rs2:;
    // AS_FAIL: (7583)
    AS_FAIL:
      // CALL MATCH_ARITH(MP,SP); (7584)
      {
        putBITp (16, mMATCH_ARITHxLOC1,
                 fixedToBit (32, (int32_t)(getFIXED (mMP))));
        putBITp (16, mMATCH_ARITHxLOC2,
                 fixedToBit (32, (int32_t)(getFIXED (mSP))));
        MATCH_ARITH (0);
      }
      // TEMP=PSEUDO_TYPE(PTR(MP)); (7585)
      {
        descriptor_t *bitRHS = getBIT (
            8, mPSEUDO_TYPE + 1 * COREHALFWORD (mPTR + 2 * getFIXED (mMP)));
        int32_t numberRHS;
        numberRHS = bitToFixed (bitRHS);
        putFIXED (mTEMP, numberRHS);
        bitRHS->inUse = 0;
      }
      // DO CASE MODE; (7586)
      {
      rs2s1:
        switch (COREHALFWORD (mADD_AND_SUBTRACTxMODE))
          {
          case 0:
            // MODE=XMADD(TEMP-MAT_TYPE); (7588)
            {
              descriptor_t *bitRHS
                  = getBIT (16, mXMADD + 2 * xsubtract (getFIXED (mTEMP), 3));
              putBIT (16, mADD_AND_SUBTRACTxMODE, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 1:
            // MODE=XMSUB(TEMP-MAT_TYPE); (7589)
            {
              descriptor_t *bitRHS
                  = getBIT (16, mXMSUB + 2 * xsubtract (getFIXED (mTEMP), 3));
              putBIT (16, mADD_AND_SUBTRACTxMODE, bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          }
      } // End of DO CASE block
      // CALL HALMAT_TUPLE(MODE,0,MP,SP,0); (7589)
      {
        putBITp (16, mHALMAT_TUPLExPOPCODE,
                 getBIT (16, mADD_AND_SUBTRACTxMODE));
        putBITp (8, mHALMAT_TUPLExCOPT, fixedToBit (32, (int32_t)(0)));
        putBITp (16, mHALMAT_TUPLExOP1,
                 fixedToBit (32, (int32_t)(getFIXED (mMP))));
        putBITp (16, mHALMAT_TUPLExOP2,
                 fixedToBit (32, (int32_t)(getFIXED (mSP))));
        putBITp (8, mHALMAT_TUPLExTAG, fixedToBit (32, (int32_t)(0)));
        HALMAT_TUPLE (0);
      }
      // CALL SETUP_VAC(MP,TEMP); (7590)
      {
        putBITp (16, mSETUP_VACxLOC,
                 fixedToBit (32, (int32_t)(getFIXED (mMP))));
        putBITp (16, mSETUP_VACxTYPE,
                 fixedToBit (32, (int32_t)(getFIXED (mTEMP))));
        SETUP_VAC (0);
      }
    es2:;
    } // End of DO block
  // PTR_TOP=PTR(MP); (7591)
  {
    descriptor_t *bitRHS = getBIT (16, mPTR + 2 * getFIXED (mMP));
    putBIT (16, mPTR_TOP, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
