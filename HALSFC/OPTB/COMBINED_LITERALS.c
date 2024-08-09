/*
  File COMBINED_LITERALS.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
COMBINED_LITERALS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "COMBINED_LITERALS");
  // OPT=(OPTYPE &  15)-11; (1069)
  {
    int32_t numberRHS
        = (int32_t)(xsubtract (xAND (COREHALFWORD (mOPTYPE), 15), 11));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCOMBINED_LITERALSxOPT, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF OPT~=0 THEN (1070)
  if (1 & (xNEQ (COREHALFWORD (mCOMBINED_LITERALSxOPT), 0)))
    // CSE_BASE= 1091567616; (1071)
    {
      int32_t numberRHS = (int32_t)(1091567616);
      putFIXED (mCOMBINED_LITERALSxCSE_BASE, numberRHS);
    }
  // ELSE (1072)
  else
    // CSE_BASE= 0; (1073)
    {
      int32_t numberRHS = (int32_t)(0);
      putFIXED (mCOMBINED_LITERALSxCSE_BASE, numberRHS);
    }
  // DW(0) = CSE_BASE; (1074)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mCOMBINED_LITERALSxCSE_BASE));
    putFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0 + 4 * (0), numberRHS);
  }
  // DW(1) = 0; (1075)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (getFIXED (mFOR_DW) + 4 * (1) + 0 + 4 * (0), numberRHS);
  }
  // DO FOR INX=1 TO CSE_FOUND_INX-1; (1076)
  {
    int32_t from23, to23, by23;
    from23 = 1;
    to23 = xsubtract (COREHALFWORD (mCSE_FOUND_INX), 1);
    by23 = 1;
    for (putBIT (16, mCOMBINED_LITERALSxINX, fixedToBit (16, from23));
         bitToFixed (getBIT (16, mCOMBINED_LITERALSxINX)) <= to23; putBIT (
             16, mCOMBINED_LITERALSxINX,
             fixedToBit (16, bitToFixed (getBIT (16, mCOMBINED_LITERALSxINX))
                                 + by23)))
      {
        // LIT_PTR=CSE2(INX); (1077)
        {
          descriptor_t *bitRHS
              = getBIT (16, mCSE2 + 2 * COREHALFWORD (mCOMBINED_LITERALSxINX));
          putBIT (16, mCOMBINED_LITERALSxLIT_PTR, bitRHS);
          bitRHS->inUse = 0;
        }
        // CALL FILL_DW(LIT_PTR); (1078)
        {
          putBITp (16, mFILL_DWxLOC, getBIT (16, mCOMBINED_LITERALSxLIT_PTR));
          FILL_DW (0);
        }
        // IF WATCH THEN (1079)
        if (1 & (bitToFixed (getBIT (8, mWATCH))))
          // OUTPUT = 'LIT(' || LIT_PTR || '):  '|| HEX(DW(2),8)||HEX(DW(3),8);
          // (1080)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                xsCAT (
                    xsCAT (xsCAT (cToDescriptor (NULL, "LIT("),
                                  bitToCharacter (getBIT (
                                      16, mCOMBINED_LITERALSxLIT_PTR))),
                           cToDescriptor (NULL, "):  ")),
                    (putFIXED (mHEXxHVAL, getFIXED (getFIXED (mFOR_DW)
                                                    + 4 * (2) + 0 + 4 * (0))),
                     putFIXED (mHEXxN, 8), HEX (0))),
                (putFIXED (mHEXxHVAL, getFIXED (getFIXED (mFOR_DW) + 4 * (3)
                                                + 0 + 4 * (0))),
                 putFIXED (mHEXxN, 8), HEX (0)));
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
        // IF OPT~=0 THEN (1081)
        if (1 & (xNEQ (COREHALFWORD (mCOMBINED_LITERALSxOPT), 0)))
          // MODE=3; (1082)
          {
            int32_t numberRHS = (int32_t)(3);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mCOMBINED_LITERALSxMODE, bitRHS);
            bitRHS->inUse = 0;
          }
        // ELSE (1083)
        else
          // MODE=1; (1084)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mCOMBINED_LITERALSxMODE, bitRHS);
            bitRHS->inUse = 0;
          }
        // CNTL_BIT=(SHR(CSE(INX),20) &  1); (1085)
        {
          int32_t numberRHS = (int32_t)(xAND (
              SHR (getFIXED (mCSE + 4 * COREHALFWORD (mCOMBINED_LITERALSxINX)),
                   20),
              1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (8, mCOMBINED_LITERALSxCNTL_BIT, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF (~FLAG & CNTL_BIT~=0) THEN (1086)
        if (1
            & (xAND (xNOT (BYTE0 (mCOMBINED_LITERALSxFLAG)),
                     xNEQ (BYTE0 (mCOMBINED_LITERALSxCNTL_BIT), 0))))
          // MODE=MODE+1; (1087)
          {
            int32_t numberRHS
                = (int32_t)(xadd (COREHALFWORD (mCOMBINED_LITERALSxMODE), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mCOMBINED_LITERALSxMODE, bitRHS);
            bitRHS->inUse = 0;
          }
        // IF LIT_ARITHMETIC(MODE) THEN (1088)
        if (1
            & (bitToFixed ((putBITp (16, mLIT_ARITHMETICxMODE,
                                     getBIT (16, mCOMBINED_LITERALSxMODE)),
                            LIT_ARITHMETIC (0)))))
          // DO; (1089)
          {
          rs1s1:;
            // PTR=0; (1090)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mCOMBINED_LITERALSxPTR, bitRHS);
              bitRHS->inUse = 0;
            }
            // CALL ERRORS (CLASS_BI, 304); (1091)
            {
              putBITp (16, mERRORSxCLASS, getBIT (16, mCLASS_BI));
              putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(304)));
              ERRORS (0);
            }
            // RETURN PTR; (1092)
            {
              reentryGuard = 0;
              return COREHALFWORD (mCOMBINED_LITERALSxPTR);
            }
          es1s1:;
          } // End of DO block
        // IF CSE(INX+1)=END_OF_NODE THEN (1093)
        if (1
            & (xEQ (getFIXED (
                        mCSE
                        + 4 * xadd (COREHALFWORD (mCOMBINED_LITERALSxINX), 1)),
                    getFIXED (mEND_OF_NODE))))
          // DO; (1094)
          {
          rs1s2:;
            // PTR=SAVE_LITERAL(0,1,LIT_PTR,0,1); (1095)
            {
              descriptor_t *bitRHS
                  = (putBITp (16, mSAVE_LITERALxN,
                              fixedToBit (32, (int32_t)(0))),
                     putBITp (16, mSAVE_LITERALxM,
                              fixedToBit (32, (int32_t)(1))),
                     putBITp (16, mSAVE_LITERALxPTR,
                              getBIT (16, mCOMBINED_LITERALSxLIT_PTR)),
                     putBITp (8, mSAVE_LITERALxFLAG,
                              fixedToBit (32, (int32_t)(0))),
                     putFIXED (mSAVE_LITERALxL1, 1), SAVE_LITERAL (0));
              putBIT (16, mCOMBINED_LITERALSxPTR, bitRHS);
              bitRHS->inUse = 0;
            }
            // IF WATCH THEN (1096)
            if (1 & (bitToFixed (getBIT (8, mWATCH))))
              // DO; (1097)
              {
              rs1s2s1:;
                // TEMP = GET_LITERAL(PTR); (1098)
                {
                  int32_t numberRHS = (int32_t)((
                      putFIXED (mGET_LITERALxPTR,
                                COREHALFWORD (mCOMBINED_LITERALSxPTR)),
                      GET_LITERAL (0)));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mTEMP, bitRHS);
                  bitRHS->inUse = 0;
                }
                // MSG1=MESSAGE_FORMAT(LIT2(TEMP)); (1099)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = (putFIXED (mMESSAGE_FORMATxWORD,
                                   getFIXED (getFIXED (mLIT_PG) + 1560 * (0)
                                             + 520
                                             + 4 * (COREHALFWORD (mTEMP)))),
                         MESSAGE_FORMAT (0));
                  putCHARACTER (mMSG1, stringRHS);
                  stringRHS->inUse = 0;
                }
                // MSG2=MESSAGE_FORMAT(LIT3(TEMP)); (1100)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = (putFIXED (mMESSAGE_FORMATxWORD,
                                   getFIXED (getFIXED (mLIT_PG) + 1560 * (0)
                                             + 1040
                                             + 4 * (COREHALFWORD (mTEMP)))),
                         MESSAGE_FORMAT (0));
                  putCHARACTER (mMSG2, stringRHS);
                  stringRHS->inUse = 0;
                }
                // OUTPUT='PTR TO LIT=' || PTR || ',LIT VALUE=' || MSG1 ||
                // MSG2; (1101)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (
                      xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "PTR TO LIT="),
                                           bitToCharacter (getBIT (
                                               16, mCOMBINED_LITERALSxPTR))),
                                    cToDescriptor (NULL, ",LIT VALUE=")),
                             getCHARACTER (mMSG1)),
                      getCHARACTER (mMSG2));
                  OUTPUT (0, stringRHS);
                  stringRHS->inUse = 0;
                }
              es1s2s1:;
              } // End of DO block
          es1s2:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // FLAG=FALSE; (1102)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mCOMBINED_LITERALSxFLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN PTR; (1103)
  {
    reentryGuard = 0;
    return COREHALFWORD (mCOMBINED_LITERALSxPTR);
  }
}
