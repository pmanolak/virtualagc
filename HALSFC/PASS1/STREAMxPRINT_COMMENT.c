/*
  File STREAMxPRINT_COMMENT.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
STREAMxPRINT_COMMENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "STREAMxPRINT_COMMENT");
  // FORMAT_CHAR='|'; (3338)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "|");
    putCHARACTER (mSTREAMxPRINT_COMMENTxFORMAT_CHAR, stringRHS);
    stringRHS->inUse = 0;
  }
  // IF ~INCLUDE_LIST2 THEN (3339)
  if (1 & (xNOT (BYTE0 (mINCLUDE_LIST2))))
    // RETURN; (3340)
    {
      reentryGuard = 0;
      return 0;
    }
  // I = 1; (3341)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSTREAMxI, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF COMMENTING THEN (3342)
  if (1 & (bitToFixed (getBIT (1, mCOMMENTING))))
    // C = X1; (3343)
    {
      descriptor_t *stringRHS;
      stringRHS = getCHARACTER (mX1);
      putCHARACTER (mSTREAMxPRINT_COMMENTxC, stringRHS);
      stringRHS->inUse = 0;
    }
  // ELSE (3344)
  else
    // DO; (3345)
    {
    rs1:;
      // SQUEEZING = FALSE; (3346)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mSQUEEZING, bitRHS);
        bitRHS->inUse = 0;
      }
      // I = 2; (3347)
      {
        int32_t numberRHS = (int32_t)(2);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSTREAMxI, bitRHS);
        bitRHS->inUse = 0;
      }
      // C = DOUBLE; (3348)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mDOUBLE);
        putCHARACTER (mSTREAMxPRINT_COMMENTxC, stringRHS);
        stringRHS->inUse = 0;
      }
      // IF IF_FLAG THEN (3349)
      if (1 & (bitToFixed (getBIT (1, mIF_FLAG))))
        // DO; (3350)
        {
        rs1s1:;
          // STMT_NUM = STMT_NUM - 1; (3351)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (getFIXED (mCOMM + 4 * 3), 1));
            putFIXED (mCOMM + 4 * (3), numberRHS);
          }
          // SAVE_SRN2 = SRN(2); (3352)
          {
            descriptor_t *stringRHS;
            stringRHS = getCHARACTER (mSRN + 4 * 2);
            putCHARACTER (mSAVE_SRN2, stringRHS);
            stringRHS->inUse = 0;
          }
          // SRN(2) = SAVE_SRN1; (3353)
          {
            descriptor_t *stringRHS;
            stringRHS = getCHARACTER (mSAVE_SRN1);
            putCHARACTER (mSRN + 4 * (2), stringRHS);
            stringRHS->inUse = 0;
          }
          // SAVE_SRN_COUNT2 = SRN_COUNT(2); (3354)
          {
            descriptor_t *bitRHS = getBIT (16, mSRN_COUNT + 2 * 2);
            putBIT (16, mSAVE_SRN_COUNT2, bitRHS);
            bitRHS->inUse = 0;
          }
          // SRN_COUNT(2) = SAVE_SRN_COUNT1; (3355)
          {
            descriptor_t *bitRHS = getBIT (16, mSAVE_SRN_COUNT1);
            putBIT (16, mSRN_COUNT + 2 * (2), bitRHS);
            bitRHS->inUse = 0;
          }
          // IF_FLAG = FALSE; (3356)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mIF_FLAG, bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL OUTPUT_WRITER(SAVE1,SAVE2); (3357)
          {
            putBITp (16, mOUTPUT_WRITERxPTR_START,
                     fixedToBit (32, (int32_t)(getFIXED (mSAVE1))));
            putBITp (16, mOUTPUT_WRITERxPTR_END,
                     fixedToBit (32, (int32_t)(getFIXED (mSAVE2))));
            OUTPUT_WRITER (0);
          }
          // INDENT_LEVEL=INDENT_LEVEL+INDENT_INCR; (3358)
          {
            int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mINDENT_LEVEL),
                                                COREHALFWORD (mINDENT_INCR)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mINDENT_LEVEL, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF STMT_PTR > -1 THEN (3359)
          if (1 & (xGT (COREHALFWORD (mSTMT_PTR), -1)))
            // LAST_WRITE = SAVE2+1; (3360)
            {
              int32_t numberRHS = (int32_t)(xadd (getFIXED (mSAVE2), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mLAST_WRITE, bitRHS);
              bitRHS->inUse = 0;
            }
          // STMT_NUM = STMT_NUM + 1; (3361)
          {
            int32_t numberRHS = (int32_t)(xadd (getFIXED (mCOMM + 4 * 3), 1));
            putFIXED (mCOMM + 4 * (3), numberRHS);
          }
          // SRN(2) = SAVE_SRN2; (3362)
          {
            descriptor_t *stringRHS;
            stringRHS = getCHARACTER (mSAVE_SRN2);
            putCHARACTER (mSRN + 4 * (2), stringRHS);
            stringRHS->inUse = 0;
          }
          // SRN_COUNT(2) = SAVE_SRN_COUNT2; (3363)
          {
            descriptor_t *bitRHS = getBIT (16, mSAVE_SRN_COUNT2);
            putBIT (16, mSRN_COUNT + 2 * (2), bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
      // ELSE (3364)
      else
        // DO; (3365)
        {
        rs1s2:;
          // ELSE_FLAG = FALSE; (3366)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mELSE_FLAG, bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL OUTPUT_WRITER(LAST_WRITE, STMT_PTR); (3367)
          {
            putBITp (16, mOUTPUT_WRITERxPTR_START, getBIT (16, mLAST_WRITE));
            putBITp (16, mOUTPUT_WRITERxPTR_END, getBIT (16, mSTMT_PTR));
            OUTPUT_WRITER (0);
          }
        es1s2:;
        } // End of DO block
    es1:;
    } // End of DO block
  // S = CARD_COUNT + 1 - INCLUDE_OFFSET; (3368)
  {
    int32_t numberRHS = (int32_t)(xsubtract (xadd (getFIXED (mCARD_COUNT), 1),
                                             COREHALFWORD (mINCLUDE_OFFSET)));
    descriptor_t *stringRHS;
    stringRHS = fixedToCharacter (numberRHS);
    putCHARACTER (mS, stringRHS);
    stringRHS->inUse = 0;
  }
  // S = PAD(S, 4); (3369)
  {
    descriptor_t *stringRHS;
    stringRHS = (putCHARACTERp (mPADxSTRING, getCHARACTER (mS)),
                 putFIXED (mPADxWIDTH, 4), PAD (0));
    putCHARACTER (mS, stringRHS);
    stringRHS->inUse = 0;
  }
  // IF (CARD_TYPE(BYTE(CURRENT_CARD)) = CARD_TYPE(BYTE('D')))  & (CURRENT_DIR
  // = 'INCLUDE') THEN (3370)
  if (1
      & (xAND (xEQ (COREHALFWORD (mCARD_TYPE
                                  + 2 * BYTE1 (getCHARACTER (mCURRENT_CARD))),
                    COREHALFWORD (mCARD_TYPE
                                  + 2 * BYTE1 (cToDescriptor (NULL, "D")))),
               xsEQ (getCHARACTER (mSTREAMxPRINT_COMMENTxCURRENT_DIR),
                     cToDescriptor (NULL, "INCLUDE")))))
    // R = I_FORMAT(STMT_NUM,4); (3371)
    {
      descriptor_t *stringRHS;
      stringRHS = (putFIXED (mI_FORMATxNUMBER, getFIXED (mCOMM + 4 * 3)),
                   putFIXED (mI_FORMATxWIDTH, 4), I_FORMAT (0));
      putCHARACTER (mSTREAMxPRINT_COMMENTxR, stringRHS);
      stringRHS->inUse = 0;
    }
  // ELSE (3372)
  else
    // R = X4; (3373)
    {
      descriptor_t *stringRHS;
      stringRHS = getCHARACTER (mX4);
      putCHARACTER (mSTREAMxPRINT_COMMENTxR, stringRHS);
      stringRHS->inUse = 0;
    }
  // IF INCLUDING THEN (3374)
  if (1 & (bitToFixed (getBIT (1, mINCLUDING))))
    // DO; (3375)
    {
    rs2:;
      // INCLUDE_CHAR = PLUS; (3376)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mPLUS);
        putCHARACTER (mINCLUDE_CHAR, stringRHS);
        stringRHS->inUse = 0;
      }
      // T = PAD1; (3377)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mPAD1);
        putCHARACTER (mSTREAMxPRINT_COMMENTxT, stringRHS);
        stringRHS->inUse = 0;
      }
      // IF SRN_PRESENT THEN (3378)
      if (1 & (bitToFixed (getBIT (1, mSRN_PRESENT))))
        // R = PAD1; (3379)
        {
          descriptor_t *stringRHS;
          stringRHS = getCHARACTER (mPAD1);
          putCHARACTER (mSTREAMxPRINT_COMMENTxR, stringRHS);
          stringRHS->inUse = 0;
        }
    es2:;
    } // End of DO block
  // ELSE (3380)
  else
    // DO; (3381)
    {
    rs3:;
      // INCLUDE_CHAR = X1; (3382)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mX1);
        putCHARACTER (mINCLUDE_CHAR, stringRHS);
        stringRHS->inUse = 0;
      }
      // IF SRN_PRESENT THEN (3383)
      if (1 & (bitToFixed (getBIT (1, mSRN_PRESENT))))
        // R = PAD(SUBSTR(CURRENT_CARD, TEXT_LIMIT + 1, 6), 7)||R; (3384)
        {
          descriptor_t *stringRHS;
          stringRHS
              = xsCAT ((putCHARACTERp (
                            mPADxSTRING,
                            SUBSTR (getCHARACTER (mCURRENT_CARD),
                                    xadd (COREHALFWORD (mTEXT_LIMIT), 1), 6)),
                        putFIXED (mPADxWIDTH, 7), PAD (0)),
                       getCHARACTER (mSTREAMxPRINT_COMMENTxR));
          putCHARACTER (mSTREAMxPRINT_COMMENTxR, stringRHS);
          stringRHS->inUse = 0;
        }
      // IF SDL_OPTION THEN (3385)
      if (1 & (bitToFixed (getBIT (1, mSDL_OPTION))))
        // DO; (3386)
        {
        rs3s1:;
          // T = SUBSTR(CURRENT_CARD, TEXT_LIMIT + 7, 2); (3387)
          {
            descriptor_t *stringRHS;
            stringRHS = SUBSTR (getCHARACTER (mCURRENT_CARD),
                                xadd (COREHALFWORD (mTEXT_LIMIT), 7), 2);
            putCHARACTER (mSTREAMxPRINT_COMMENTxT, stringRHS);
            stringRHS->inUse = 0;
          }
          // IF LENGTH(CURRENT_CARD) >= TEXT_LIMIT + 17 THEN (3388)
          if (1
              & (xGE (LENGTH (getCHARACTER (mCURRENT_CARD)),
                      xadd (COREHALFWORD (mTEXT_LIMIT), 17))))
            // T = T || X1 || SUBSTR(CURRENT_CARD, TEXT_LIMIT + 9, 8); (3389)
            {
              descriptor_t *stringRHS;
              stringRHS
                  = xsCAT (xsCAT (getCHARACTER (mSTREAMxPRINT_COMMENTxT),
                                  getCHARACTER (mX1)),
                           SUBSTR (getCHARACTER (mCURRENT_CARD),
                                   xadd (COREHALFWORD (mTEXT_LIMIT), 9), 8));
              putCHARACTER (mSTREAMxPRINT_COMMENTxT, stringRHS);
              stringRHS->inUse = 0;
            }
          // ELSE (3390)
          else
            // T = T || SUBSTR(X70, 0, 9); (3391)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (getCHARACTER (mSTREAMxPRINT_COMMENTxT),
                                 SUBSTR (getCHARACTER (mX70), 0, 9));
              putCHARACTER (mSTREAMxPRINT_COMMENTxT, stringRHS);
              stringRHS->inUse = 0;
            }
        es3s1:;
        } // End of DO block
    es3:;
    } // End of DO block
  // IF LISTING2 THEN (3392)
  if (1 & (bitToFixed (getBIT (1, mLISTING2))))
    // CALL PRINT2(C || SUBSTR(X8, 1) || INCLUDE_CHAR || SUBSTR(CURRENT_CARD,
    // 0, 1) || VBAR || SUBSTR(CURRENT_CARD, 1) || VBAR || S || X1 ||
    // CURRENT_SCOPE, I); (3393)
    {
      putCHARACTERp (
          mPRINT2xLINE,
          xsCAT (
              xsCAT (
                  xsCAT (
                      xsCAT (
                          xsCAT (
                              xsCAT (
                                  xsCAT (
                                      xsCAT (
                                          xsCAT (
                                              getCHARACTER (
                                                  mSTREAMxPRINT_COMMENTxC),
                                              SUBSTR2 (getCHARACTER (mX8), 1)),
                                          getCHARACTER (mINCLUDE_CHAR)),
                                      SUBSTR (getCHARACTER (mCURRENT_CARD), 0,
                                              1)),
                                  getCHARACTER (mVBAR)),
                              SUBSTR2 (getCHARACTER (mCURRENT_CARD), 1)),
                          getCHARACTER (mVBAR)),
                      getCHARACTER (mS)),
                  getCHARACTER (mX1)),
              getCHARACTER (mCURRENT_SCOPE)));
      putBITp (16, mPRINT2xSPACE, getBIT (16, mSTREAMxI));
      PRINT2 (0);
    }
  // IF PRINT THEN (3394)
  if (1 & (bitToFixed (getBIT (1, mSTREAMxPRINT_COMMENTxPRINT))))
    // DO; (3395)
    {
    rs4:;
      // IF LINE_MAX = 0 THEN (3396)
      if (1 & (xEQ (COREHALFWORD (mLINE_MAX), 0)))
        // DO; (3397)
        {
        rs4s1:;
          // LINE_MAX = LINE_LIM; (3398)
          {
            descriptor_t *bitRHS = getBIT (16, mLINE_LIM);
            putBIT (16, mLINE_MAX, bitRHS);
            bitRHS->inUse = 0;
          }
          // C = PAGE; (3399)
          {
            descriptor_t *stringRHS;
            stringRHS = getCHARACTER (mPAGE);
            putCHARACTER (mSTREAMxPRINT_COMMENTxC, stringRHS);
            stringRHS->inUse = 0;
          }
        es4s1:;
        } // End of DO block
      // I=100-TEXT_LIMIT; (3400)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (100, COREHALFWORD (mTEXT_LIMIT)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSTREAMxI, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF SDL_OPTION THEN (3401)
      if (1 & (bitToFixed (getBIT (1, mSDL_OPTION))))
        // S=FORMAT_CHAR||SUBSTR(T,0,2)||FORMAT_CHAR||SAVE_SCOPE; (3402)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              xsCAT (xsCAT (getCHARACTER (mSTREAMxPRINT_COMMENTxFORMAT_CHAR),
                            SUBSTR (getCHARACTER (mSTREAMxPRINT_COMMENTxT), 0,
                                    2)),
                     getCHARACTER (mSTREAMxPRINT_COMMENTxFORMAT_CHAR)),
              getCHARACTER (mSAVE_SCOPE));
          putCHARACTER (mS, stringRHS);
          stringRHS->inUse = 0;
        }
      // ELSE (3403)
      else
        // S=FORMAT_CHAR||SAVE_SCOPE; (3404)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (getCHARACTER (mSTREAMxPRINT_COMMENTxFORMAT_CHAR),
                             getCHARACTER (mSAVE_SCOPE));
          putCHARACTER (mS, stringRHS);
          stringRHS->inUse = 0;
        }
      // S=SUBSTR(CURRENT_CARD,1,TEXT_LIMIT)||SUBSTR(X70,0,I)||S; (3405)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (SUBSTR (getCHARACTER (mCURRENT_CARD), 1,
                           COREHALFWORD (mTEXT_LIMIT)),
                   SUBSTR (getCHARACTER (mX70), 0, COREHALFWORD (mSTREAMxI))),
            getCHARACTER (mS));
        putCHARACTER (mS, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT(1)=C||R||INCLUDE_CHAR||SUBSTR(CURRENT_CARD,0,1)|| VBAR||S;
      // (3406)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (
                xsCAT (xsCAT (xsCAT (getCHARACTER (mSTREAMxPRINT_COMMENTxC),
                                     getCHARACTER (mSTREAMxPRINT_COMMENTxR)),
                              getCHARACTER (mINCLUDE_CHAR)),
                       SUBSTR (getCHARACTER (mCURRENT_CARD), 0, 1)),
                getCHARACTER (mVBAR)),
            getCHARACTER (mS));
        OUTPUT (1, stringRHS);
        stringRHS->inUse = 0;
      }
    es4:;
    } // End of DO block
  // NEXT_CC = ' '; (3407)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, " ");
    putCHARACTER (mNEXT_CC, stringRHS);
    stringRHS->inUse = 0;
  }
  // CURRENT_DIR = ''; (3408)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "");
    putCHARACTER (mSTREAMxPRINT_COMMENTxCURRENT_DIR, stringRHS);
    stringRHS->inUse = 0;
  }
  // PREV_ELINE = FALSE; (3409)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mPREV_ELINE, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
