/*
  File PASS1xADD_UVC.c generated by XCOM-I, 2024-08-09 12:39:13.
*/

#include "runtimeC.h"

int32_t
PASS1xADD_UVC (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PASS1xADD_UVC");
  // TEMP_PTR = STACK_PTR; (1292)
  {
    descriptor_t *bitRHS = getBIT (16, mSTACK_PTR);
    putBIT (16, mPASS1xADD_UVCxTEMP_PTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE TRUE; (1293)
  while (1 & (1))
    {
      // IF FRAME_TYPE(TEMP_PTR) = BLOCK_TYPE THEN (1294)
      if (1
          & (xEQ (BYTE0 (getFIXED (mSTACK_FRAME)
                         + 32 * (COREHALFWORD (mPASS1xADD_UVCxTEMP_PTR)) + 30
                         + 1 * (0)),
                  1)))
        // GO TO EXIT_SEARCH_LOOP; (1295)
        goto EXIT_SEARCH_LOOP;
      // IF FRAME_TYPE(TEMP_PTR) = CASE_TYPE THEN (1296)
      if (1
          & (xEQ (BYTE0 (getFIXED (mSTACK_FRAME)
                         + 32 * (COREHALFWORD (mPASS1xADD_UVCxTEMP_PTR)) + 30
                         + 1 * (0)),
                  3)))
        // GO TO EXIT_SEARCH_LOOP; (1297)
        goto EXIT_SEARCH_LOOP;
      // TEMP_PTR = TEMP_PTR - 1; (1298)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (COREHALFWORD (mPASS1xADD_UVCxTEMP_PTR), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPASS1xADD_UVCxTEMP_PTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
// EXIT_SEARCH_LOOP: (1299)
EXIT_SEARCH_LOOP:
  // TEMP_CELL = GET_FREE_CELL; (1300)
  {
    descriptor_t *bitRHS = GET_FREE_CELL (0);
    putBIT (16, mPASS1xADD_UVCxTEMP_CELL, bitRHS);
    bitRHS->inUse = 0;
  }
  // CELL1(TEMP_CELL) = RAND; (1301)
  {
    descriptor_t *bitRHS = getBIT (16, mPASS1xADD_UVCxRAND);
    putBIT (16,
            getFIXED (mLIST_STRUX)
                + 8 * (COREHALFWORD (mPASS1xADD_UVCxTEMP_CELL)) + 0 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // CELL2(TEMP_CELL) = HALMAT_LINE; (1302)
  {
    descriptor_t *bitRHS = getBIT (16, mPASS1xADD_UVCxHALMAT_LINE);
    putBIT (16,
            getFIXED (mLIST_STRUX)
                + 8 * (COREHALFWORD (mPASS1xADD_UVCxTEMP_CELL)) + 2 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // CELL1_FLAGS(TEMP_CELL) = RAND_TYPE &  63; (1303)
  {
    int32_t numberRHS = (int32_t)(xAND (BYTE0 (mPASS1xADD_UVCxRAND_TYPE), 63));
    putBIT (8,
            getFIXED (mLIST_STRUX)
                + 8 * (COREHALFWORD (mPASS1xADD_UVCxTEMP_CELL)) + 6 + 1 * (0),
            fixedToBit (8, numberRHS));
  }
  // CDR_CELL(TEMP_CELL) = FRAME_UVCS(TEMP_PTR); (1304)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mSTACK_FRAME)
                + 32 * (COREHALFWORD (mPASS1xADD_UVCxTEMP_PTR)) + 6 + 2 * (0));
    putBIT (16,
            getFIXED (mLIST_STRUX)
                + 8 * (COREHALFWORD (mPASS1xADD_UVCxTEMP_CELL)) + 4 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // FRAME_UVCS(TEMP_PTR) = TEMP_CELL; (1305)
  {
    descriptor_t *bitRHS = getBIT (16, mPASS1xADD_UVCxTEMP_CELL);
    putBIT (16,
            getFIXED (mSTACK_FRAME)
                + 32 * (COREHALFWORD (mPASS1xADD_UVCxTEMP_PTR)) + 6 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
