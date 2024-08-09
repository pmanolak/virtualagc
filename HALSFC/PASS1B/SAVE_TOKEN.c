/*
  File SAVE_TOKEN.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
SAVE_TOKEN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SAVE_TOKEN");
  // IF ~INCLUDE_LIST THEN (2555)
  if (1 & (xNOT (BYTE0 (mINCLUDE_LIST))))
    // DO; (2556)
    {
    rs1:;
      // COMMENT_COUNT, STACK_PTR(SP) = -1; (2557)
      {
        int32_t numberRHS = (int32_t)(-1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mCOMMENT_COUNT, bitRHS);
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSTACK_PTR + 2 * (getFIXED (mSP)), bitRHS);
        bitRHS->inUse = 0;
      }
      // RETURN; (2558)
      {
        reentryGuard = 0;
        return 0;
      }
    es1:;
    } // End of DO block
  // STMT_PTR = STMT_PTR + 1; (2559)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mSTMT_PTR), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSTMT_PTR, bitRHS);
    bitRHS->inUse = 0;
  }
// STMT_PTR_CHECK: (2560)
STMT_PTR_CHECK:
  // IF STMT_PTR > OUTPUT_STACK_MAX THEN (2561)
  if (1 & (xGT (COREHALFWORD (mSTMT_PTR), 1799)))
    // DO; (2562)
    {
    rs2:;
      // STMT_PTR = OUTPUT_STACK_MAX; (2563)
      {
        int32_t numberRHS = (int32_t)(1799);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSTMT_PTR, bitRHS);
        bitRHS->inUse = 0;
      }
      // SQUEEZING = TRUE; (2564)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mSQUEEZING, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL OUTPUT_STACK_RELOCATE; (2565)
      SAVE_TOKENxOUTPUT_STACK_RELOCATE (0);
      // IF ATTR_LOC > 0 THEN (2566)
      if (1 & (xGT (COREHALFWORD (mATTR_LOC), 0)))
        // ATTR_LOC = 0; (2567)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mATTR_LOC, bitRHS);
          bitRHS->inUse = 0;
        }
      // GO TO STMT_PTR_CHECK; (2568)
      goto STMT_PTR_CHECK;
    es2:;
    } // End of DO block
  // TOKEN_FLAGS(STMT_PTR) = TYPE; (2569)
  {
    descriptor_t *bitRHS = getBIT (16, mSAVE_TOKENxTYPE);
    putBIT (16, mTOKEN_FLAGS + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IF ~RESERVED_WORD THEN (2570)
  if (1 & (xNOT (BYTE0 (mRESERVED_WORD))))
    // IF PRINTING_ENABLED > 0 THEN (2571)
    if (1 & (xGT (COREHALFWORD (mPRINTING_ENABLED), 0)))
      // DO; (2572)
      {
      rs3:;
      // BCD_PTR_CHECK: (2573)
      BCD_PTR_CHECK:
        // BCD_PTR = BCD_PTR + 1; (2574)
        {
          int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mBCD_PTR), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mBCD_PTR, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF BCD_PTR > SAVE_BCD_MAX THEN (2575)
        if (1 & (xGT (COREHALFWORD (mBCD_PTR), 256)))
          // DO; (2576)
          {
          rs3s1:;
            // SQUEEZING = TRUE; (2577)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mSQUEEZING, bitRHS);
              bitRHS->inUse = 0;
            }
            // STMT_PTR = STMT_PTR - 1; (2578)
            {
              int32_t numberRHS
                  = (int32_t)(xsubtract (COREHALFWORD (mSTMT_PTR), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mSTMT_PTR, bitRHS);
              bitRHS->inUse = 0;
            }
            // CALL OUTPUT_STACK_RELOCATE; (2579)
            SAVE_TOKENxOUTPUT_STACK_RELOCATE (0);
            // IF ATTR_LOC > 0 THEN (2580)
            if (1 & (xGT (COREHALFWORD (mATTR_LOC), 0)))
              // ATTR_LOC = 0; (2581)
              {
                int32_t numberRHS = (int32_t)(0);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mATTR_LOC, bitRHS);
                bitRHS->inUse = 0;
              }
            // GO TO BCD_PTR_CHECK; (2582)
            goto BCD_PTR_CHECK;
          es3s1:;
          } // End of DO block
        // SAVE_BCD(BCD_PTR) = CHAR; (2583)
        {
          descriptor_t *stringRHS;
          stringRHS = getCHARACTER (mSAVE_TOKENxCHAR);
          putCHARACTER (mSAVE_BCD + 4 * (COREHALFWORD (mBCD_PTR)), stringRHS);
          stringRHS->inUse = 0;
        }
        // TOKEN_FLAGS(STMT_PTR) = TYPE | SHL(BCD_PTR, 6); (2584)
        {
          int32_t numberRHS
              = (int32_t)(xOR (COREHALFWORD (mSAVE_TOKENxTYPE),
                               SHL (COREHALFWORD (mBCD_PTR), 6)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mTOKEN_FLAGS + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
          bitRHS->inUse = 0;
        }
        // TOKEN_FLAGS(STMT_PTR) = TOKEN_FLAGS(STMT_PTR) | SHL(BCD_PTR, 6);
        // (2585)
        {
          int32_t numberRHS = (int32_t)(xOR (
              COREHALFWORD (mTOKEN_FLAGS + 2 * COREHALFWORD (mSTMT_PTR)),
              SHL (COREHALFWORD (mBCD_PTR), 6)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mTOKEN_FLAGS + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
          bitRHS->inUse = 0;
        }
      es3:;
      } // End of DO block
  // STMT_STACK(STMT_PTR) = TOKEN; (2586)
  {
    descriptor_t *bitRHS = getBIT (16, mSAVE_TOKENxTOKEN);
    putBIT (16, mSTMT_STACK + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IF ~INCLUDING THEN (2587)
  if (1 & (xNOT (BYTE0 (mINCLUDING))))
    // DO; (2588)
    {
    rs4:;
      // RVL_STACK1(STMT_PTR) = BYTE(RVL,0); (2589)
      {
        int32_t numberRHS = (int32_t)(BYTE (getCHARACTER (mRVL), 0));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mRVL_STACK1 + 1 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
        bitRHS->inUse = 0;
      }
      // RVL_STACK2(STMT_PTR) = BYTE(RVL,1); (2590)
      {
        int32_t numberRHS = (int32_t)(BYTE (getCHARACTER (mRVL), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mRVL_STACK2 + 1 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
        bitRHS->inUse = 0;
      }
      // RVL = NEXT_CHAR_RVL; (2591)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mNEXT_CHAR_RVL);
        putCHARACTER (mRVL, stringRHS);
        stringRHS->inUse = 0;
      }
    es4:;
    } // End of DO block
  // ERROR_PTR(STMT_PTR) = -1; (2592)
  {
    int32_t numberRHS = (int32_t)(-1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mERROR_PTR + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IF WAIT THEN (2593)
  if (1 & (bitToFixed (getBIT (1, mWAIT))))
    // DO; (2594)
    {
    rs5:;
      // WAIT = FALSE; (2595)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mWAIT, bitRHS);
        bitRHS->inUse = 0;
      }
      // ACTUAL_PRINTING_ENABLED = 0; (2596)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSAVE_TOKENxACTUAL_PRINTING_ENABLED, bitRHS);
        bitRHS->inUse = 0;
      }
    es5:;
    } // End of DO block
  // ELSE (2597)
  else
    // ACTUAL_PRINTING_ENABLED = PRINTING_ENABLED; (2598)
    {
      descriptor_t *bitRHS = getBIT (16, mPRINTING_ENABLED);
      putBIT (16, mSAVE_TOKENxACTUAL_PRINTING_ENABLED, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF SUPPRESS_THIS_TOKEN_ONLY THEN (2599)
  if (1 & (bitToFixed (getBIT (1, mSUPPRESS_THIS_TOKEN_ONLY))))
    // DO; (2600)
    {
    rs6:;
      // SUPPRESS_THIS_TOKEN_ONLY, GRAMMAR_FLAGS(STMT_PTR) = 0; (2601)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mSUPPRESS_THIS_TOKEN_ONLY, bitRHS);
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGRAMMAR_FLAGS + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
        bitRHS->inUse = 0;
      }
    es6:;
    } // End of DO block
  // ELSE (2602)
  else
    // GRAMMAR_FLAGS(STMT_PTR) = ACTUAL_PRINTING_ENABLED; (2603)
    {
      descriptor_t *bitRHS = getBIT (16, mSAVE_TOKENxACTUAL_PRINTING_ENABLED);
      putBIT (16, mGRAMMAR_FLAGS + 2 * (COREHALFWORD (mSTMT_PTR)), bitRHS);
      bitRHS->inUse = 0;
    }
  // IF TYPE ~= 7 THEN (2604)
  if (1 & (xNEQ (COREHALFWORD (mSAVE_TOKENxTYPE), 7)))
    // IF ~MACRO_ARG THEN (2605)
    if (1 & (xNOT (BYTE0 (mSAVE_TOKENxMACRO_ARG))))
      // STACK_PTR(SP) = STMT_PTR; (2606)
      {
        descriptor_t *bitRHS = getBIT (16, mSTMT_PTR);
        putBIT (16, mSTACK_PTR + 2 * (getFIXED (mSP)), bitRHS);
        bitRHS->inUse = 0;
      }
  // MACRO_ARG = FALSE; (2607)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mSAVE_TOKENxMACRO_ARG, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
