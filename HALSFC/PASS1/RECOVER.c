/*
  File RECOVER.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
RECOVER (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "RECOVER");
  // DECLARING=FALSE; (13956)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mRECOVERxDECLARING, bitRHS);
    bitRHS->inUse = 0;
  }
  // RECOVERING = TRUE; (13957)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mRECOVERING, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF TOKEN ~= SEMI_COLON & TOKEN ~= EOFILE THEN (13958)
  if (1
      & (xAND (xNEQ (getFIXED (mTOKEN), getFIXED (mSEMI_COLON)),
               xNEQ (getFIXED (mTOKEN), getFIXED (mEOFILE)))))
    // GO TO TOKEN_LOOP_START; (13959)
    goto TOKEN_LOOP_START;
  // DO WHILE TOKEN~=SEMI_COLON&TOKEN~=EOFILE; (13960)
  while (1
         & (xAND (xNEQ (getFIXED (mTOKEN), getFIXED (mSEMI_COLON)),
                  xNEQ (getFIXED (mTOKEN), getFIXED (mEOFILE)))))
    {
      // IF TOKEN ~= 0 THEN (13961)
      if (1 & (xNEQ (getFIXED (mTOKEN), 0)))
        // CALL SAVE_TOKEN(TOKEN, BCD, IMPLIED_TYPE); (13962)
        {
          putBITp (16, mSAVE_TOKENxTOKEN,
                   fixedToBit (32, (int32_t)(getFIXED (mTOKEN))));
          putCHARACTERp (mSAVE_TOKENxCHAR, getCHARACTER (mBCD));
          putBITp (16, mSAVE_TOKENxTYPE, getBIT (16, mIMPLIED_TYPE));
          SAVE_TOKEN (0);
        }
      // ELSE (13963)
      else
        // CALL SAVE_TOKEN(ID_TOKEN, BCD, IMPLIED_TYPE); (13964)
        {
          putBITp (16, mSAVE_TOKENxTOKEN,
                   fixedToBit (32, (int32_t)(getFIXED (mID_TOKEN))));
          putCHARACTERp (mSAVE_TOKENxCHAR, getCHARACTER (mBCD));
          putBITp (16, mSAVE_TOKENxTYPE, getBIT (16, mIMPLIED_TYPE));
          SAVE_TOKEN (0);
        }
    // TOKEN_LOOP_START: (13965)
    TOKEN_LOOP_START:
      // TOKEN = 0; (13966)
      {
        int32_t numberRHS = (int32_t)(0);
        putFIXED (mTOKEN, numberRHS);
      }
      // CALL CALL_SCAN; (13967)
      CALL_SCAN (0);
    } // End of DO WHILE block
  // CONTEXT,TEMPORARY_IMPLIED=0; (13968)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mCONTEXT, numberRHS);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mTEMPORARY_IMPLIED, bitRHS);
    bitRHS->inUse = 0;
  }
  // NAME_IMPLIED,DELAY_CONTEXT_CHECK=FALSE; (13969)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mNAME_IMPLIED, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mDELAY_CONTEXT_CHECK, bitRHS);
    bitRHS->inUse = 0;
  }
  // ASSIGN_ARG_LIST=FALSE; (13970)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mASSIGN_ARG_LIST, bitRHS);
    bitRHS->inUse = 0;
  }
  // NAME_PSEUDOS=FALSE; (13971)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mNAME_PSEUDOS, bitRHS);
    bitRHS->inUse = 0;
  }
  // NAMING,FIXING,REFER_LOC=0; (13972)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mNAMING, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mFIXING, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mREFER_LOC, bitRHS);
    bitRHS->inUse = 0;
  }
  // PARMS_WATCH=FALSE; (13973)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mPARMS_WATCH, bitRHS);
    bitRHS->inUse = 0;
  }
  // QUALIFICATION=0; (13974)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mQUALIFICATION, bitRHS);
    bitRHS->inUse = 0;
  }
  // RECOVERING, DO_INIT = FALSE; (13975)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mRECOVERING, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mDO_INIT, bitRHS);
    bitRHS->inUse = 0;
  }
  // BI_FUNC_FLAG,INIT_EMISSION=FALSE; (13976)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mBI_FUNC_FLAG, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mINIT_EMISSION, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF (IC_FOUND & 1) ~= 0 THEN (13977)
  if (1 & (xNEQ (xAND (COREHALFWORD (mIC_FOUND), 1), 0)))
    // PTR_TOP = IC_PTR1 - 1; (13978)
    {
      int32_t numberRHS = (int32_t)(xsubtract (COREHALFWORD (mIC_PTR1), 1));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mPTR_TOP, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (13979)
  else
    // IF (IC_FOUND & 2) ~= 0 THEN (13980)
    if (1 & (xNEQ (xAND (COREHALFWORD (mIC_FOUND), 2), 0)))
      // PTR_TOP = IC_PTR2 - 1; (13981)
      {
        int32_t numberRHS = (int32_t)(xsubtract (COREHALFWORD (mIC_PTR2), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPTR_TOP, bitRHS);
        bitRHS->inUse = 0;
      }
  // IC_FOUND = 0; (13982)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mIC_FOUND, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF SUBSCRIPT_LEVEL>0 THEN (13983)
  if (1 & (xGT (COREHALFWORD (mSUBSCRIPT_LEVEL), 0)))
    // DO; (13984)
    {
    rs2:;
      // SUBSCRIPT_LEVEL=0; (13985)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSUBSCRIPT_LEVEL, bitRHS);
        bitRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // FCN_LV = 0; (13986)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mFCN_LV, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF REF_ID_LOC>0 THEN (13987)
  if (1 & (xGT (getFIXED (mREF_ID_LOC), 0)))
    // DO; (13988)
    {
    rs3:;
      // SYT_FLAGS(REF_ID_LOC)=SYT_FLAGS(REF_ID_LOC)|EVIL_FLAG; (13989)
      {
        int32_t numberRHS = (int32_t)(xOR (
            getFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mREF_ID_LOC)) + 8
                      + 4 * (0)),
            2097152));
        putFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mREF_ID_LOC)) + 8
                      + 4 * (0),
                  numberRHS);
      }
      // REF_ID_LOC=0; (13990)
      {
        int32_t numberRHS = (int32_t)(0);
        putFIXED (mREF_ID_LOC, numberRHS);
      }
    es3:;
    } // End of DO block
  // CALL CHECK_ARRAYNESS; (13991)
  CHECK_ARRAYNESS (0);
  // DO WHILE SP>0; (13992)
  while (1 & (xGT (getFIXED (mSP), 0)))
    {
      // STATE=CHECK_TOKEN(STATE_STACK(SP),LOOK_STACK(SP),TOKEN); (13993)
      {
        int32_t numberRHS = (int32_t)((
            putBITp (16, mCHECK_TOKENxNSTATE,
                     fixedToBit (32, (int32_t)(getFIXED (
                                         mSTATE_STACK + 4 * getFIXED (mSP))))),
            putBITp (16, mCHECK_TOKENxNLOOK,
                     getBIT (16, mLOOK_STACK + 2 * getFIXED (mSP))),
            putBITp (16, mCHECK_TOKENxNTOKEN,
                     fixedToBit (32, (int32_t)(getFIXED (mTOKEN)))),
            CHECK_TOKEN (0)));
        putFIXED (mSTATE, numberRHS);
      }
      // IF STATE>0 & STATE_NAME(STATE_STACK(SP))~=SUB_START_TOKEN THEN (13994)
      if (1
          & (xAND (
              xGT (getFIXED (mSTATE), 0),
              xNEQ (COREHALFWORD (
                        mSTATE_NAME
                        + 2 * getFIXED (mSTATE_STACK + 4 * getFIXED (mSP))),
                    getFIXED (mSUB_START_TOKEN)))))
        // DO; (13995)
        {
        rs4s1:;
          // SP=SP-1; (13996)
          {
            int32_t numberRHS = (int32_t)(xsubtract (getFIXED (mSP), 1));
            putFIXED (mSP, numberRHS);
          }
          // CALL STACK_DUMP; (13997)
          STACK_DUMP (0);
          // IF TOKEN~=EOFILE THEN (13998)
          if (1 & (xNEQ (getFIXED (mTOKEN), getFIXED (mEOFILE))))
            // DO; (13999)
            {
            rs4s1s1:;
              // IF SAVE_INDENT_LEVEL~=0 THEN (14000)
              if (1 & (xNEQ (COREHALFWORD (mSAVE_INDENT_LEVEL), 0)))
                // INDENT_LEVEL=SAVE_INDENT_LEVEL; (14001)
                {
                  descriptor_t *bitRHS = getBIT (16, mSAVE_INDENT_LEVEL);
                  putBIT (16, mINDENT_LEVEL, bitRHS);
                  bitRHS->inUse = 0;
                }
              // IF ~DECLARING THEN (14002)
              if (1 & (xNOT (BYTE0 (mRECOVERxDECLARING))))
                // RETURN; (14003)
                {
                  reentryGuard = 0;
                  return 0;
                }
              // CALL SAVE_TOKEN(TOKEN,BCD,IMPLIED_TYPE); (14004)
              {
                putBITp (16, mSAVE_TOKENxTOKEN,
                         fixedToBit (32, (int32_t)(getFIXED (mTOKEN))));
                putCHARACTERp (mSAVE_TOKENxCHAR, getCHARACTER (mBCD));
                putBITp (16, mSAVE_TOKENxTYPE, getBIT (16, mIMPLIED_TYPE));
                SAVE_TOKEN (0);
              }
              // CALL OUTPUT_WRITER(LAST_WRITE,STMT_PTR); (14005)
              {
                putBITp (16, mOUTPUT_WRITERxPTR_START,
                         getBIT (16, mLAST_WRITE));
                putBITp (16, mOUTPUT_WRITERxPTR_END, getBIT (16, mSTMT_PTR));
                OUTPUT_WRITER (0);
              }
              // CALL CALL_SCAN; (14006)
              CALL_SCAN (0);
              // CALL EMIT_SMRK; (14007)
              EMIT_SMRK (0);
              // FACTORING = TRUE; (14008)
              {
                int32_t numberRHS = (int32_t)(1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mFACTORING, bitRHS);
                bitRHS->inUse = 0;
              }
              // FACTOR_FOUND = FALSE; (14009)
              {
                int32_t numberRHS = (int32_t)(0);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (1, mFACTOR_FOUND, bitRHS);
                bitRHS->inUse = 0;
              }
              // DO I = 0 TO FACTOR_LIM; (14010)
              {
                int32_t from176, to176, by176;
                from176 = 0;
                to176 = 19;
                by176 = 1;
                for (putFIXED (mI, from176); getFIXED (mI) <= to176;
                     putFIXED (mI, getFIXED (mI) + by176))
                  {
                    // FACTORED_TYPE(I) = 0; (14011)
                    {
                      int32_t numberRHS = (int32_t)(0);
                      putFIXED (mFACTORED_TYPE + 4 * (getFIXED (mI)),
                                numberRHS);
                    }
                  }
              } // End of DO for-loop block
            es4s1s1:;
            } // End of DO block
          // ELSE (14012)
          else
            // GO TO BAD_BAD; (14013)
            goto BAD_BAD;
          // RETURN; (14014)
          {
            reentryGuard = 0;
            return 0;
          }
        es4s1:;
        } // End of DO block
      // I=STATE_NAME(STATE_STACK(SP)); (14015)
      {
        descriptor_t *bitRHS = getBIT (
            16,
            mSTATE_NAME + 2 * getFIXED (mSTATE_STACK + 4 * getFIXED (mSP)));
        int32_t numberRHS;
        numberRHS = bitToFixed (bitRHS);
        putFIXED (mI, numberRHS);
        bitRHS->inUse = 0;
      }
      // IF (I=DECLARE_TOKEN)|(I=REPLACE_TOKEN) THEN (14016)
      if (1
          & (xOR (xEQ (getFIXED (mI), getFIXED (mDECLARE_TOKEN)),
                  xEQ (getFIXED (mI), getFIXED (mREPLACE_TOKEN)))))
        // DECLARING=TRUE; (14017)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (1, mRECOVERxDECLARING, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (14018)
      else
        // IF I=STRUCTURE_WORD THEN (14019)
        if (1 & (xEQ (getFIXED (mI), getFIXED (mSTRUCTURE_WORD))))
          // DECLARING=TRUE; (14020)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mRECOVERxDECLARING, bitRHS);
            bitRHS->inUse = 0;
          }
      // SP=SP-1; (14021)
      {
        int32_t numberRHS = (int32_t)(xsubtract (getFIXED (mSP), 1));
        putFIXED (mSP, numberRHS);
      }
    } // End of DO WHILE block
// BAD_BAD: (14022)
BAD_BAD:
  // CALL OUTPUT_WRITER(LAST_WRITE,STMT_PTR); (14023)
  {
    putBITp (16, mOUTPUT_WRITERxPTR_START, getBIT (16, mLAST_WRITE));
    putBITp (16, mOUTPUT_WRITERxPTR_END, getBIT (16, mSTMT_PTR));
    OUTPUT_WRITER (0);
  }
  // DOUBLE_SPACE; (14024)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mDOUBLE);
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT='***** ERROR RECOVERY UNSUCCESSFUL.'; (14025)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "***** ERROR RECOVERY UNSUCCESSFUL.");
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // COMPILING=FALSE; (14026)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mCOMPILING, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN; (14027)
  {
    reentryGuard = 0;
    return 0;
  }
}
