/*
  File COLLAPSE_LITERALS.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
COLLAPSE_LITERALS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "COLLAPSE_LITERALS");
  // IF TRACE THEN (4641)
  if (1 & (bitToFixed (getBIT (8, mTRACE))))
    // DO; (4642)
    {
    rs1:;
      // OUTPUT = 'COLLAPSE_LITERALS:  '||VAC_INX; (4643)
      {
        descriptor_t *stringRHS;
        stringRHS
            = xsCAT (cToDescriptor (NULL, "COLLAPSE_LITERALS:  "),
                     bitToCharacter (getBIT (16, mCOLLAPSE_LITERALSxVAC_INX)));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // DO FOR TEMP = 1 TO CSE_FOUND_INX; (4644)
      {
        int32_t from109, to109, by109;
        from109 = 1;
        to109 = bitToFixed (getBIT (16, mCSE_FOUND_INX));
        by109 = 1;
        for (putBIT (16, mCOLLAPSE_LITERALSxTEMP, fixedToBit (16, from109));
             bitToFixed (getBIT (16, mCOLLAPSE_LITERALSxTEMP)) <= to109;
             putBIT (16, mCOLLAPSE_LITERALSxTEMP,
                     fixedToBit (
                         16, bitToFixed (getBIT (16, mCOLLAPSE_LITERALSxTEMP))
                                 + by109)))
          {
            // OUTPUT = CSE_WORD_FORMAT(CSE(TEMP)) || ', CSE2:  ' ||
            // CSE2(TEMP); (4645)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  xsCAT (
                      (putFIXED (
                           mCSE_WORD_FORMATxWORD,
                           getFIXED (
                               mCSE
                               + 4 * COREHALFWORD (mCOLLAPSE_LITERALSxTEMP))),
                       CSE_WORD_FORMAT (0)),
                      cToDescriptor (NULL, ", CSE2:  ")),
                  bitToCharacter (getBIT (
                      16,
                      mCSE2 + 2 * COREHALFWORD (mCOLLAPSE_LITERALSxTEMP))));
              OUTPUT (0, stringRHS);
              stringRHS->inUse = 0;
            }
          }
      } // End of DO for-loop block
    es1:;
    } // End of DO block
  // CSE_FOUND_INX = CSE_FOUND_INX + 1; (4646)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mCSE_FOUND_INX), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCSE_FOUND_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // CSE(CSE_FOUND_INX) = END_OF_NODE; (4647)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mEND_OF_NODE));
    putFIXED (mCSE + 4 * (COREHALFWORD (mCSE_FOUND_INX)), numberRHS);
  }
  // IF ~BIT_TYPE THEN (4648)
  if (1 & (xNOT (BYTE0 (mBIT_TYPE))))
    // NEW_LIT = COMBINED_LITERALS(MPARITY0# = 0); (4649)
    {
      int32_t numberRHS = (int32_t)((
          putBITp (
              8, mCOMBINED_LITERALSxFLAG,
              fixedToBit (32, (int32_t)(xEQ (COREHALFWORD (mMPARITY0p), 0)))),
          COMBINED_LITERALS (0)));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mCOLLAPSE_LITERALSxNEW_LIT, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (4650)
  else
    // NEW_LIT = 0; (4651)
    {
      int32_t numberRHS = (int32_t)(0);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mCOLLAPSE_LITERALSxNEW_LIT, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF NEW_LIT = 0 THEN (4652)
  if (1 & (xEQ (COREHALFWORD (mCOLLAPSE_LITERALSxNEW_LIT), 0)))
    // DO; (4653)
    {
    rs2:;
      // DO FOR TEMP = 1 TO CSE_FOUND_INX - 1; (4654)
      {
        int32_t from110, to110, by110;
        from110 = 1;
        to110 = xsubtract (COREHALFWORD (mCSE_FOUND_INX), 1);
        by110 = 1;
        for (putBIT (16, mCOLLAPSE_LITERALSxTEMP, fixedToBit (16, from110));
             bitToFixed (getBIT (16, mCOLLAPSE_LITERALSxTEMP)) <= to110;
             putBIT (16, mCOLLAPSE_LITERALSxTEMP,
                     fixedToBit (
                         16, bitToFixed (getBIT (16, mCOLLAPSE_LITERALSxTEMP))
                                 + by110)))
          {
            // NODE(N_INX) = CSE(TEMP); (4655)
            {
              int32_t numberRHS = (int32_t)(getFIXED (
                  mCSE + 4 * COREHALFWORD (mCOLLAPSE_LITERALSxTEMP)));
              putFIXED (mNODE + 4 * (COREHALFWORD (mN_INX)), numberRHS);
            }
            // NODE2(N_INX) = CSE2(TEMP); (4656)
            {
              descriptor_t *bitRHS = getBIT (
                  16, mCSE2 + 2 * COREHALFWORD (mCOLLAPSE_LITERALSxTEMP));
              putBIT (16, mNODE2 + 2 * (COREHALFWORD (mN_INX)), bitRHS);
              bitRHS->inUse = 0;
            }
            // N_INX = N_INX + 1; (4657)
            {
              int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mN_INX), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mN_INX, bitRHS);
              bitRHS->inUse = 0;
            }
          }
      } // End of DO for-loop block
      // N_INX = N_INX - 1; (4658)
      {
        int32_t numberRHS = (int32_t)(xsubtract (COREHALFWORD (mN_INX), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mN_INX, bitRHS);
        bitRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // ELSE (4659)
  else
    // DO; (4660)
    {
    rs3:;
      // FORWARD = 1; (4661)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mFORWARD, bitRHS);
        bitRHS->inUse = 0;
      }
      // REVERSE = 0; (4662)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mREVERSE, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL COLLECT_MATCHES(NODE(VAC_INX) &  65535,FNPARITY0#,FNPARITY1#);
      // (4663)
      {
        putBITp (
            16, mCOLLECT_MATCHESxH_PTR,
            fixedToBit (
                32,
                (int32_t)(xAND (
                    getFIXED (mNODE
                              + 4 * COREHALFWORD (mCOLLAPSE_LITERALSxVAC_INX)),
                    65535))));
        putBITp (16, mCOLLECT_MATCHESxNPARITY0p, getBIT (16, mFNPARITY0p));
        putBITp (16, mCOLLECT_MATCHESxNPARITY1p, getBIT (16, mFNPARITY1p));
        COLLECT_MATCHES (0);
      }
      // CALL PUT_NOP(HALMAT_PTR); (4664)
      {
        putBITp (16, mPUT_NOPxPTR, getBIT (16, mHALMAT_PTR));
        PUT_NOP (0);
      }
      // TEMP = REFERENCE(HALMAT_PTR); (4665)
      {
        descriptor_t *bitRHS
            = (putBITp (16, mREFERENCExPTR, getBIT (16, mHALMAT_PTR)),
               REFERENCE (0));
        putBIT (16, mCOLLAPSE_LITERALSxTEMP, bitRHS);
        bitRHS->inUse = 0;
      }
      // OPR(TEMP) = SHL(NEW_LIT,16) |  81; (4666)
      {
        int32_t numberRHS = (int32_t)(xOR (
            SHL (COREHALFWORD (mCOLLAPSE_LITERALSxNEW_LIT), 16), 81));
        putFIXED (mOPR + 4 * (COREHALFWORD (mCOLLAPSE_LITERALSxTEMP)),
                  numberRHS);
      }
      // NODE2(N_INX) = SHR(OPR(TEMP),16); (4667)
      {
        int32_t numberRHS = (int32_t)(SHR (
            getFIXED (mOPR + 4 * COREHALFWORD (mCOLLAPSE_LITERALSxTEMP)), 16));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mNODE2 + 2 * (COREHALFWORD (mN_INX)), bitRHS);
        bitRHS->inUse = 0;
      }
      // NODE(N_INX) = LITERAL | SHL(MPARITY0# = 0,20); (4668)
      {
        int32_t numberRHS
            = (int32_t)(xOR (getFIXED (mLITERAL),
                             SHL (xEQ (COREHALFWORD (mMPARITY0p), 0), 20)));
        putFIXED (mNODE + 4 * (COREHALFWORD (mN_INX)), numberRHS);
      }
      // IF WATCH THEN (4669)
      if (1 & (bitToFixed (getBIT (8, mWATCH))))
        // CALL PRINT_SENTENCE(HALMAT_NODE_START); (4670)
        {
          putBITp (16, mPRINT_SENTENCExPTR, getBIT (16, mHALMAT_NODE_START));
          PRINT_SENTENCE (0);
        }
      // LITERAL_FOLDS = LITERAL_FOLDS + 1; (4671)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mLITERAL_FOLDS), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mLITERAL_FOLDS, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF STATISTICS THEN (4672)
      if (1 & (bitToFixed (getBIT (16, mSTATISTICS))))
        // OUTPUT = 'LITERAL FOLD FOUND IN HAL/S STATEMENT ' || STT#; (4673)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              cToDescriptor (NULL, "LITERAL FOLD FOUND IN HAL/S STATEMENT "),
              bitToCharacter (getBIT (16, mSTTp)));
          OUTPUT (0, stringRHS);
          stringRHS->inUse = 0;
        }
    es3:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
