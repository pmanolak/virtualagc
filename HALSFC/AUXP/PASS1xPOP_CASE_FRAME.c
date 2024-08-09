/*
  File PASS1xPOP_CASE_FRAME.c generated by XCOM-I, 2024-08-09 12:39:13.
*/

#include "runtimeC.h"

int32_t
PASS1xPOP_CASE_FRAME (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PASS1xPOP_CASE_FRAME");
  // IF STACK_DUMP THEN (2057)
  if (1 & (bitToFixed (getBIT (1, mSTACK_DUMP))))
    // CALL DUMP_STACK; (2058)
    PASS1xDUMP_STACK (0);
  // CALL DECR_STACK_PTR; (2059)
  DECR_STACK_PTR (0);
  // FRAME_FLAGS(STACK_PTR) = FRAME_FLAGS(STACK_PTR) | (FRAME_FLAGS(STACK_PTR +
  // 1) & (IF_THEN_ELSE_MASK | ZAP_FLAG)); (2060)
  {
    int32_t numberRHS = (int32_t)(xOR (
        BYTE0 (getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 31
               + 1 * (0)),
        xAND (BYTE0 (getFIXED (mSTACK_FRAME)
                     + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1)) + 31
                     + 1 * (0)),
              49)));
    putBIT (8,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 31
                + 1 * (0),
            fixedToBit (8, numberRHS));
  }
  // IF FRAME_TYPE(STACK_PTR) ~= CB_TYPE THEN (2061)
  if (1
      & (xNEQ (BYTE0 (getFIXED (mSTACK_FRAME)
                      + 32 * (COREHALFWORD (mSTACK_PTR)) + 30 + 1 * (0)),
               2)))
    // CALL STACK_ERROR(POP_IND, FRAME_TYPE(STACK_PTR), 'PREVIOUS '); (2062)
    {
      putCHARACTERp (mPASS1xSTACK_ERRORxHALMAT_TYPE,
                     getCHARACTER (mPASS1xPOP_CASE_FRAMExPOP_IND));
      putBITp (16, mPASS1xSTACK_ERRORxFRM_TYPE,
               getBIT (8, getFIXED (mSTACK_FRAME)
                              + 32 * (COREHALFWORD (mSTACK_PTR)) + 30
                              + 1 * (0)));
      putCHARACTERp (mPASS1xSTACK_ERRORxWHICH_FRAME,
                     cToDescriptor (NULL, "PREVIOUS "));
      PASS1xSTACK_ERROR (0);
    }
  // FRAME_UVCS(STACK_PTR) = LIST(FRAME_UVCS(STACK_PTR + 1),
  // FRAME_UVCS(STACK_PTR)); (2063)
  {
    descriptor_t *bitRHS
        = (putBITp (
               16, mLISTxLIST1,
               getBIT (16, getFIXED (mSTACK_FRAME)
                               + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1)) + 6
                               + 2 * (0))),
           putBITp (16, mLISTxLIST2,
                    getBIT (16, getFIXED (mSTACK_FRAME)
                                    + 32 * (COREHALFWORD (mSTACK_PTR)) + 6
                                    + 2 * (0))),
           LIST (0));
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 6
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL PASS_BACK_SYT_REFS; (2064)
  PASS_BACK_SYT_REFS (0);
  // CALL PASS_BACK_VAC_REFS(0); (2065)
  {
    putBITp (16, mPASS_BACK_VAC_REFSxWHICH_START,
             fixedToBit (32, (int32_t)(0)));
    PASS_BACK_VAC_REFS (0);
  }
  // IF (FRAME_FLAGS(STACK_PTR + 1) & IF_THEN_ELSE_MASK) ~= 0 THEN (2066)
  if (1
      & (xNEQ (xAND (BYTE0 (getFIXED (mSTACK_FRAME)
                            + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1)) + 31
                            + 1 * (0)),
                     48),
               0)))
    // TEMP_PTR1 = HALMAT_PTR + HALRATOR_#RANDS + 1 - FRAME_START(STACK_PTR +
    // 1); (2067)
    {
      int32_t numberRHS = (int32_t)(xsubtract (
          xadd (xadd (COREHALFWORD (mHALMAT_PTR), BYTE0 (mHALRATOR_pRANDS)),
                1),
          COREHALFWORD (getFIXED (mSTACK_FRAME)
                        + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1)) + 4
                        + 2 * (0))));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mPASS1xPOP_CASE_FRAMExTEMP_PTR1, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (2068)
  else
    // TEMP_PTR1 = HALMAT_PTR - FRAME_START(STACK_PTR + 1); (2069)
    {
      int32_t numberRHS = (int32_t)(xsubtract (
          COREHALFWORD (mHALMAT_PTR),
          COREHALFWORD (getFIXED (mSTACK_FRAME)
                        + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1)) + 4
                        + 2 * (0))));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mPASS1xPOP_CASE_FRAMExTEMP_PTR1, bitRHS);
      bitRHS->inUse = 0;
    }
  // TEMP_PTR2 = TEMP_PTR1 + (FRAME_BUMP_FACTOR(STACK_PTR + 1) -
  // FRAME_BUMP_FACTOR(STACK_PTR)); (2070)
  {
    int32_t numberRHS = (int32_t)(xadd (
        COREHALFWORD (mPASS1xPOP_CASE_FRAMExTEMP_PTR1),
        xsubtract (COREHALFWORD (getFIXED (mSTACK_FRAME)
                                 + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1))
                                 + 18 + 2 * (0)),
                   COREHALFWORD (getFIXED (mSTACK_FRAME)
                                 + 32 * (COREHALFWORD (mSTACK_PTR)) + 18
                                 + 2 * (0)))));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mPASS1xPOP_CASE_FRAMExTEMP_PTR2, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF TEMP_PTR2 > MAX_CASE_LENGTH(STACK_PTR) THEN (2071)
  if (1
      & (xGT (COREHALFWORD (mPASS1xPOP_CASE_FRAMExTEMP_PTR2),
              COREHALFWORD (getFIXED (mSTACK_FRAME)
                            + 32 * (COREHALFWORD (mSTACK_PTR)) + 0
                            + 2 * (0)))))
    // MAX_CASE_LENGTH(STACK_PTR) = TEMP_PTR2; (2072)
    {
      descriptor_t *bitRHS = getBIT (16, mPASS1xPOP_CASE_FRAMExTEMP_PTR2);
      putBIT (16,
              getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 0
                  + 2 * (0),
              bitRHS);
      bitRHS->inUse = 0;
    }
  // FRAME_BUMP_FACTOR(STACK_PTR) = FRAME_BUMP_FACTOR(STACK_PTR) - TEMP_PTR1;
  // (2073)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        COREHALFWORD (getFIXED (mSTACK_FRAME)
                      + 32 * (COREHALFWORD (mSTACK_PTR)) + 18 + 2 * (0)),
        COREHALFWORD (mPASS1xPOP_CASE_FRAMExTEMP_PTR1)));
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 18
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // TEMP_PTR1 = GET_FREE_CELL; (2074)
  {
    descriptor_t *bitRHS = GET_FREE_CELL (0);
    putBIT (16, mPASS1xPOP_CASE_FRAMExTEMP_PTR1, bitRHS);
    bitRHS->inUse = 0;
  }
  // CELL1(TEMP_PTR1) = FRAME_START(STACK_PTR + 1); (2075)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mSTACK_FRAME)
                + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1)) + 4 + 2 * (0));
    putBIT (16,
            getFIXED (mLIST_STRUX)
                + 8 * (COREHALFWORD (mPASS1xPOP_CASE_FRAMExTEMP_PTR1)) + 0
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // CELL2(TEMP_PTR1) = FRAME_SYT_REF(STACK_PTR + 1); (2076)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mSTACK_FRAME)
                + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1)) + 10 + 2 * (0));
    putBIT (16,
            getFIXED (mLIST_STRUX)
                + 8 * (COREHALFWORD (mPASS1xPOP_CASE_FRAMExTEMP_PTR1)) + 2
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // TEMP_PTR2 = GET_FREE_CELL; (2077)
  {
    descriptor_t *bitRHS = GET_FREE_CELL (0);
    putBIT (16, mPASS1xPOP_CASE_FRAMExTEMP_PTR2, bitRHS);
    bitRHS->inUse = 0;
  }
  // CELL1(TEMP_PTR2) = FRAME_VAC_REF(STACK_PTR + 1); (2078)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mSTACK_FRAME)
                + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1)) + 12 + 2 * (0));
    putBIT (16,
            getFIXED (mLIST_STRUX)
                + 8 * (COREHALFWORD (mPASS1xPOP_CASE_FRAMExTEMP_PTR2)) + 0
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // CDR_CELL(TEMP_PTR1) = TEMP_PTR2; (2079)
  {
    descriptor_t *bitRHS = getBIT (16, mPASS1xPOP_CASE_FRAMExTEMP_PTR2);
    putBIT (16,
            getFIXED (mLIST_STRUX)
                + 8 * (COREHALFWORD (mPASS1xPOP_CASE_FRAMExTEMP_PTR1)) + 4
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // CDR_CELL(TEMP_PTR2) = FRAME_MAP_SAVE(STACK_PTR); (2080)
  {
    descriptor_t *bitRHS
        = getBIT (16, getFIXED (mSTACK_FRAME)
                          + 32 * (COREHALFWORD (mSTACK_PTR)) + 22 + 2 * (0));
    putBIT (16,
            getFIXED (mLIST_STRUX)
                + 8 * (COREHALFWORD (mPASS1xPOP_CASE_FRAMExTEMP_PTR2)) + 4
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // FRAME_MAP_SAVE(STACK_PTR) = TEMP_PTR1; (2081)
  {
    descriptor_t *bitRHS = getBIT (16, mPASS1xPOP_CASE_FRAMExTEMP_PTR1);
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 22
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // IF (FRAME_FLAGS(STACK_PTR + 1) & TRUE_CASE) ~= 0 THEN (2082)
  if (1
      & (xNEQ (xAND (BYTE0 (getFIXED (mSTACK_FRAME)
                            + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1)) + 31
                            + 1 * (0)),
                     16),
               0)))
    // DO; (2083)
    {
    rs1:;
      // TEMP_PTR1 = GET_FREE_CELL; (2084)
      {
        descriptor_t *bitRHS = GET_FREE_CELL (0);
        putBIT (16, mPASS1xPOP_CASE_FRAMExTEMP_PTR1, bitRHS);
        bitRHS->inUse = 0;
      }
      // CELL1(TEMP_PTR1) = FRAME_START(STACK_PTR + 1); (2085)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mSTACK_FRAME)
                              + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1)) + 4
                              + 2 * (0));
        putBIT (16,
                getFIXED (mLIST_STRUX)
                    + 8 * (COREHALFWORD (mPASS1xPOP_CASE_FRAMExTEMP_PTR1)) + 0
                    + 2 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // CDR_CELL(TEMP_PTR1) = CASE_LIST_PTRS(STACK_PTR + 1); (2086)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mSTACK_FRAME)
                              + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1)) + 28
                              + 2 * (0));
        putBIT (16,
                getFIXED (mLIST_STRUX)
                    + 8 * (COREHALFWORD (mPASS1xPOP_CASE_FRAMExTEMP_PTR1)) + 4
                    + 2 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // IF (FRAME_FLAGS(STACK_PTR + 1) & PREV_BLOCK_FLAG) = 0 THEN (2087)
      if (1
          & (xEQ (xAND (BYTE0 (getFIXED (mSTACK_FRAME)
                               + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1))
                               + 31 + 1 * (0)),
                        2),
                  0)))
        // TARGET(FRAME_START(STACK_PTR)) = FRAME_CB_NEST_LEVEL(STACK_PTR);
        // (2088)
        {
          descriptor_t *bitRHS = getBIT (
              16, getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR))
                      + 2 + 2 * (0));
          putBIT (16,
                  getFIXED (mWORK_VARS)
                      + 11
                            * (COREHALFWORD (getFIXED (mSTACK_FRAME)
                                             + 32 * (COREHALFWORD (mSTACK_PTR))
                                             + 4 + 2 * (0)))
                      + 6 + 2 * (0),
                  bitRHS);
          bitRHS->inUse = 0;
        }
    es1:;
    } // End of DO block
  // ELSE (2089)
  else
    // TEMP_PTR1 = CASE_LIST_PTRS(STACK_PTR + 1); (2090)
    {
      descriptor_t *bitRHS = getBIT (
          16, getFIXED (mSTACK_FRAME)
                  + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1)) + 28 + 2 * (0));
      putBIT (16, mPASS1xPOP_CASE_FRAMExTEMP_PTR1, bitRHS);
      bitRHS->inUse = 0;
    }
  // CASE_LIST_PTRS(STACK_PTR) = LIST(TEMP_PTR1, CASE_LIST_PTRS(STACK_PTR));
  // (2091)
  {
    descriptor_t *bitRHS
        = (putBITp (16, mLISTxLIST1,
                    getBIT (16, mPASS1xPOP_CASE_FRAMExTEMP_PTR1)),
           putBITp (16, mLISTxLIST2,
                    getBIT (16, getFIXED (mSTACK_FRAME)
                                    + 32 * (COREHALFWORD (mSTACK_PTR)) + 28
                                    + 2 * (0))),
           LIST (0));
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 28
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // IF AUXMAT_REQUESTED | PRETTY_PRINT_REQUESTED THEN (2092)
  if (1 & (xOR (BYTE0 (mAUXMAT_REQUESTED), BYTE0 (mPRETTY_PRINT_REQUESTED))))
    // DO; (2093)
    {
    rs2:;
      // OUTPUT = ''; (2094)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, "");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = TRACE_MSG('NEW BUMP_FACTOR =' ||
      // #RJUST(FRAME_BUMP_FACTOR(STACK_PTR), 6), HALMAT_PTR); (2095)
      {
        descriptor_t *stringRHS;
        stringRHS
            = (putCHARACTERp (
                   mTRACE_MSGxMSG,
                   xsCAT (
                       cToDescriptor (NULL, "NEW BUMP_FACTOR ="),
                       (putBITp (
                            16, mpRJUSTxNUMBER,
                            getBIT (16, getFIXED (mSTACK_FRAME)
                                            + 32 * (COREHALFWORD (mSTACK_PTR))
                                            + 18 + 2 * (0))),
                        putBITp (16, mpRJUSTxTOTAL_LENGTH,
                                 fixedToBit (32, (int32_t)(6))),
                        pRJUST (0)))),
               putBITp (16, mTRACE_MSGxHALMATp, getBIT (16, mHALMAT_PTR)),
               TRACE_MSG (0));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // IF STACK_DUMP THEN (2096)
  if (1 & (bitToFixed (getBIT (1, mSTACK_DUMP))))
    // CALL DUMP_STACK; (2097)
    PASS1xDUMP_STACK (0);
  {
    reentryGuard = 0;
    return 0;
  }
}
