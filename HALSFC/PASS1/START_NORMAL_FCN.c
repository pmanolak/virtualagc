/*
  File START_NORMAL_FCN.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

descriptor_t *
START_NORMAL_FCN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "START_NORMAL_FCN");
  // PTR(MP)=PUSH_INDIRECT(1); (7957)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (16, mPUSH_INDIRECTxI, fixedToBit (32, (int32_t)(1))),
        PUSH_INDIRECT (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mPTR + 2 * (getFIXED (mMP)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IF FIXL(MP)>SYT_MAX THEN (7958)
  if (1
      & (xGT (getFIXED (mFIXL + 4 * getFIXED (mMP)), COREHALFWORD (mSYT_MAX))))
    // DO; (7959)
    {
    rs1:;
      // FIXL(MP)=FIXL(MP)-SYT_MAX; (7960)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            getFIXED (mFIXL + 4 * getFIXED (mMP)), COREHALFWORD (mSYT_MAX)));
        putFIXED (mFIXL + 4 * (getFIXED (mMP)), numberRHS);
      }
      // CALL SET_BI_XREF(FIXL(MP)); (7961)
      {
        putBITp (
            16, mSET_BI_XREFxLOC,
            fixedToBit (32, (int32_t)(getFIXED (mFIXL + 4 * getFIXED (mMP)))));
        SET_BI_XREF (0);
      }
      // PSEUDO_TYPE(PTR_TOP)=SHR(BI_INFO(FIXL(MP)),24); (7962)
      {
        int32_t numberRHS = (int32_t)(SHR (
            COREWORD (mBI_INFO + 4 * getFIXED (mFIXL + 4 * getFIXED (mMP))),
            24));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mPSEUDO_TYPE + 1 * (COREHALFWORD (mPTR_TOP)), bitRHS);
        bitRHS->inUse = 0;
      }
      // IF PSEUDO_TYPE(PTR_TOP)=IORS_TYPE THEN (7963)
      if (1 & (xEQ (BYTE0 (mPSEUDO_TYPE + 1 * COREHALFWORD (mPTR_TOP)), 8)))
        // PSEUDO_TYPE(PTR_TOP)=INT_TYPE; (7964)
        {
          int32_t numberRHS = (int32_t)(6);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (8, mPSEUDO_TYPE + 1 * (COREHALFWORD (mPTR_TOP)), bitRHS);
          bitRHS->inUse = 0;
        }
      // IF (BI_FLAGS(FIXL(MP))& 32)=0 THEN (7965)
      if (1
          & (xEQ (xAND (BYTE0 (mBI_FLAGS
                               + 1 * getFIXED (mFIXL + 4 * getFIXED (mMP))),
                        32),
                  0)))
        // MODE=1; (7966)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (8, mSTART_NORMAL_FCNxMODE, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (7967)
      else
        // MODE=4; (7968)
        {
          int32_t numberRHS = (int32_t)(4);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (8, mSTART_NORMAL_FCNxMODE, bitRHS);
          bitRHS->inUse = 0;
        }
      // LOC_P(PTR_TOP)=FIXL(MP); (7969)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mFIXL + 4 * getFIXED (mMP)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mLOC_P + 2 * (COREHALFWORD (mPTR_TOP)), bitRHS);
        bitRHS->inUse = 0;
      }
      // PSEUDO_FORM(PTR_TOP)=XSYT; (7970)
      {
        descriptor_t *bitRHS = getBIT (8, mXSYT);
        putBIT (8, mPSEUDO_FORM + 1 * (COREHALFWORD (mPTR_TOP)), bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (7971)
  else
    // DO; (7972)
    {
    rs2:;
      // IF (SYT_FLAGS(FIXL(MP)) & ACCESS_FLAG) ~= 0 THEN (7973)
      if (1
          & (xNEQ (
              xAND (getFIXED (getFIXED (mSYM_TAB)
                              + 34 * (getFIXED (mFIXL + 4 * getFIXED (mMP)))
                              + 8 + 4 * (0)),
                    65536),
              0)))
        // CALL ERROR(CLASS_PS,7,VAR(MP)); (7974)
        {
          putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_PS));
          putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(7)));
          putCHARACTERp (mERRORxTEXT,
                         getCHARACTER (mVAR + 4 * getFIXED (mMP)));
          ERROR (0);
        }
      // TEMP = FIXL(MP); (7975)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mFIXL + 4 * getFIXED (mMP)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSTART_NORMAL_FCNxTEMP, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF SYT_LINK1(TEMP) < 0 THEN (7976)
      if (1
          & (xLT (COREHALFWORD (getFIXED (mSYM_TAB)
                                + 34 * (COREHALFWORD (mSTART_NORMAL_FCNxTEMP))
                                + 24 + 2 * (0)),
                  0)))
        // DO; (7977)
        {
        rs2s1:;
          // IF DO_LEVEL<(-SYT_LINK1(TEMP)) THEN (7978)
          if (1
              & (xLT (COREHALFWORD (mDO_LEVEL),
                      xminus (COREHALFWORD (
                          getFIXED (mSYM_TAB)
                          + 34 * (COREHALFWORD (mSTART_NORMAL_FCNxTEMP)) + 24
                          + 2 * (0))))))
            // CALL ERROR(CLASS_PL,9,VAR(MP)); (7979)
            {
              putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_PL));
              putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(9)));
              putCHARACTERp (mERRORxTEXT,
                             getCHARACTER (mVAR + 4 * getFIXED (mMP)));
              ERROR (0);
            }
        es2s1:;
        } // End of DO block
      // ELSE (7980)
      else
        // IF SYT_LINK1(TEMP) = 0 THEN (7981)
        if (1
            & (xEQ (
                COREHALFWORD (getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mSTART_NORMAL_FCNxTEMP))
                              + 24 + 2 * (0)),
                0)))
          // SYT_LINK1(TEMP) = STMT_NUM; (7982)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mCOMM + 4 * 3));
            putBIT (16,
                    getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mSTART_NORMAL_FCNxTEMP)) + 24
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
      // MODE=0; (7983)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mSTART_NORMAL_FCNxMODE, bitRHS);
        bitRHS->inUse = 0;
      }
      // VAL_P(PTR_TOP)=0; (7984)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mVAL_P + 2 * (COREHALFWORD (mPTR_TOP)), bitRHS);
        bitRHS->inUse = 0;
      }
      // EXT_P(PTR_TOP)=STACK_PTR(MP); (7985)
      {
        descriptor_t *bitRHS = getBIT (16, mSTACK_PTR + 2 * getFIXED (mMP));
        putBIT (16, mEXT_P + 2 * (COREHALFWORD (mPTR_TOP)), bitRHS);
        bitRHS->inUse = 0;
      }
      // PSEUDO_TYPE(PTR_TOP)=SYT_TYPE(FIXL(MP)); (7986)
      {
        descriptor_t *bitRHS
            = getBIT (8, getFIXED (mSYM_TAB)
                             + 34 * (getFIXED (mFIXL + 4 * getFIXED (mMP)))
                             + 32 + 1 * (0));
        putBIT (8, mPSEUDO_TYPE + 1 * (COREHALFWORD (mPTR_TOP)), bitRHS);
        bitRHS->inUse = 0;
      }
      // PSEUDO_LENGTH(PTR_TOP)=VAR_LENGTH(FIXL(MP)); (7987)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mSYM_TAB)
                              + 34 * (getFIXED (mFIXL + 4 * getFIXED (mMP)))
                              + 18 + 2 * (0));
        putBIT (16, mPSEUDO_LENGTH + 2 * (COREHALFWORD (mPTR_TOP)), bitRHS);
        bitRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // IF PUSH_FCN_STACK(MODE) THEN (7988)
  if (1
      & ((putBITp (16, mPUSH_FCN_STACKxMODE,
                   getBIT (8, mSTART_NORMAL_FCNxMODE)),
          PUSH_FCN_STACK (0))))
    // DO; (7989)
    {
    rs3:;
      // FCN_LOC(FCN_LV)=FIXL(MP); (7990)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mFIXL + 4 * getFIXED (mMP)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mFCN_LOC + 2 * (COREHALFWORD (mFCN_LV)), bitRHS);
        bitRHS->inUse = 0;
      }
      // DO CASE MODE; (7991)
      {
      rs3s1:
        switch (BYTE0 (mSTART_NORMAL_FCNxMODE))
          {
          case 0:
            // IF INLINE_LEVEL=0 THEN (7993)
            if (1 & (xEQ (COREHALFWORD (mINLINE_LEVEL), 0)))
              {
              rs3s1s1:;
                // CALL SAVE_ARRAYNESS; (7994)
                SAVE_ARRAYNESS (0);
                // CALL HALMAT_POP(XXXST,1,XCO_N,FCN_LV); (7995)
                {
                  putBITp (16, mHALMAT_POPxPOPCODE, getBIT (16, mXXXST));
                  putBITp (8, mHALMAT_POPxPIPp, fixedToBit (32, (int32_t)(1)));
                  putBITp (8, mHALMAT_POPxCOPT, getBIT (8, mXCO_N));
                  putBITp (8, mHALMAT_POPxTAG, getBIT (16, mFCN_LV));
                  HALMAT_POP (0);
                }
                // CALL HALMAT_PIP(FIXL(MP),XSYT,0,0); (7996)
                {
                  putBITp (16, mHALMAT_PIPxOPERAND,
                           fixedToBit (32, (int32_t)(getFIXED (
                                               mFIXL + 4 * getFIXED (mMP)))));
                  putBITp (8, mHALMAT_PIPxQUAL, getBIT (8, mXSYT));
                  putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
                  putBITp (8, mHALMAT_PIPxTAG2, fixedToBit (32, (int32_t)(0)));
                  HALMAT_PIP (0);
                }
                // CALL UPDATE_BLOCK_CHECK(MP); (7997)
                {
                  putBITp (16, mUPDATE_BLOCK_CHECKxLOC,
                           fixedToBit (32, (int32_t)(getFIXED (mMP))));
                  UPDATE_BLOCK_CHECK (0);
                }
                // IF (SYT_FLAGS(FIXL(MP))&DEFINED_LABEL)=0 THEN (7998)
                if (1
                    & (xEQ (
                        xAND (
                            getFIXED (
                                getFIXED (mSYM_TAB)
                                + 34 * (getFIXED (mFIXL + 4 * getFIXED (mMP)))
                                + 8 + 4 * (0)),
                            64),
                        0)))
                  // FCN_ARG(FCN_LV)=-1; (7999)
                  {
                    int32_t numberRHS = (int32_t)(-1);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mFCN_ARG + 2 * (COREHALFWORD (mFCN_LV)),
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                // ELSE (8000)
                else
                  // IF (SYT_FLAGS2(FIXL(MP))&NONHAL_FLAG)~=0 THEN (8001)
                  if (1
                      & (xNEQ (
                          xAND (BYTE0 (getFIXED (mSYM_TAB)
                                       + 34
                                             * (getFIXED (
                                                 mFIXL + 4 * getFIXED (mMP)))
                                       + 33 + 1 * (0)),
                                1),
                          0)))
                    // FCN_ARG(FCN_LV)=-2; (8002)
                    {
                      int32_t numberRHS = (int32_t)(-2);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mFCN_ARG + 2 * (COREHALFWORD (mFCN_LV)),
                              bitRHS);
                      bitRHS->inUse = 0;
                    }
                // LOC_P(PTR_TOP)=FIXL(MP); (8003)
                {
                  int32_t numberRHS
                      = (int32_t)(getFIXED (mFIXL + 4 * getFIXED (mMP)));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mLOC_P + 2 * (COREHALFWORD (mPTR_TOP)), bitRHS);
                  bitRHS->inUse = 0;
                }
                // PSEUDO_FORM(PTR_TOP)=XSYT; (8004)
                {
                  descriptor_t *bitRHS = getBIT (8, mXSYT);
                  putBIT (8, mPSEUDO_FORM + 1 * (COREHALFWORD (mPTR_TOP)),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL STRUCTURE_FCN; (8005)
                STRUCTURE_FCN (0);
                // CALL SET_XREF_RORS(MP, 24576); (8006)
                {
                  putFIXED (mSET_XREF_RORSxI, getFIXED (mMP));
                  putFIXED (mSET_XREF_RORSxJ, 24576);
                  SET_XREF_RORS (0);
                }
              es3s1s1:;
              } // End of DO block
            else
              {
              rs3s1s2:;
                // CALL ERROR(CLASS_PP,8); (8009)
                {
                  putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_PP));
                  putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(8)));
                  ERROR (0);
                }
                // FCN_LV=FCN_LV-1; (8010)
                {
                  int32_t numberRHS
                      = (int32_t)(xsubtract (COREHALFWORD (mFCN_LV), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mFCN_LV, bitRHS);
                  bitRHS->inUse = 0;
                }
              es3s1s2:;
              } // End of DO block
            break;
          case 1:
              // ; (8012)
              ;
            break;
          case 2:
              // ; (8013)
              ;
            break;
          case 3:
              // ; (8014)
              ;
            break;
          case 4:
            // DO; (8015)
            {
            rs3s1s3:;
              // CALL SAVE_ARRAYNESS; (8015)
              SAVE_ARRAYNESS (0);
              // CALL HALMAT_POP(XSFST,0,XCO_N,FCN_LV); (8016)
              {
                putBITp (16, mHALMAT_POPxPOPCODE, getBIT (16, mXSFST));
                putBITp (8, mHALMAT_POPxPIPp, fixedToBit (32, (int32_t)(0)));
                putBITp (8, mHALMAT_POPxCOPT, getBIT (8, mXCO_N));
                putBITp (8, mHALMAT_POPxTAG, getBIT (16, mFCN_LV));
                HALMAT_POP (0);
              }
            es3s1s3:;
            } // End of DO block
            break;
          }
      } // End of DO CASE block
    es3:;
    } // End of DO block
  // RETURN MODE=0; (8017)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(xEQ (BYTE0 (mSTART_NORMAL_FCNxMODE), 0)));
  }
}