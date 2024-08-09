/*
  File PASS1xPUSH_BLOCK_FRAME.c generated by XCOM-I, 2024-08-09 12:39:13.
*/

#include "runtimeC.h"

int32_t
PASS1xPUSH_BLOCK_FRAME (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PASS1xPUSH_BLOCK_FRAME");
  // IF STACK_DUMP THEN (1664)
  if (1 & (bitToFixed (getBIT (1, mSTACK_DUMP))))
    // CALL DUMP_STACK; (1665)
    PASS1xDUMP_STACK (0);
  // CALL INCR_STACK_PTR; (1666)
  INCR_STACK_PTR (0);
  // FRAME_BLOCK_PTR(STACK_PTR) = STACK_PTR; (1667)
  {
    descriptor_t *bitRHS = getBIT (16, mSTACK_PTR);
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 26
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // FRAME_START(STACK_PTR) = HALMAT_PTR; (1668)
  {
    descriptor_t *bitRHS = getBIT (16, mHALMAT_PTR);
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 4
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // FRAME_TYPE(STACK_PTR) = BLOCK_TYPE; (1669)
  {
    int32_t numberRHS = (int32_t)(1);
    putBIT (8,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 30
                + 1 * (0),
            fixedToBit (8, numberRHS));
  }
  // FRAME_FLAGS(STACK_PTR) = 0; (1670)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (8,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 31
                + 1 * (0),
            fixedToBit (8, numberRHS));
  }
  // FRAME_UVCS(STACK_PTR) = 0; (1671)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 6
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // CALL DECODE_HALRAND(1); (1672)
  {
    putBITp (16, mPASS1xDECODE_HALRANDxOP, fixedToBit (32, (int32_t)(1)));
    PASS1xDECODE_HALRAND (0);
  }
  // FRAME_INL(STACK_PTR) = HALRAND; (1673)
  {
    descriptor_t *bitRHS = getBIT (16, mHALRAND);
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 8
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // FRAME_SYT_REF(STACK_PTR) = NEW_ZERO_SYT_REF_FRAME; (1674)
  {
    descriptor_t *bitRHS = NEW_ZERO_SYT_REF_FRAME (0);
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 10
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // FRAME_VAC_REF(STACK_PTR) = NEW_ZERO_VAC_REF_FRAME; (1675)
  {
    descriptor_t *bitRHS = NEW_ZERO_VAC_REF_FRAME (0);
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 12
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // FRAME_SYT_PREV_REF(STACK_PTR) = 0; (1676)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 14
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // FRAME_VAC_PREV_REF(STACK_PTR) = 0; (1677)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 16
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // FRAME_BUMP_FACTOR(STACK_PTR) = FRAME_BUMP_FACTOR(STACK_PTR - 1); (1678)
  {
    descriptor_t *bitRHS
        = getBIT (16, getFIXED (mSTACK_FRAME)
                          + 32 * (xsubtract (COREHALFWORD (mSTACK_PTR), 1))
                          + 18 + 2 * (0));
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 18
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // FRAME_CASE_LIST(STACK_PTR) = 0; (1679)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 20
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // FRAME_MAP_SAVE(STACK_PTR) = 0; (1680)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 22
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // VAC_BOUNDS(STACK_PTR) = 0; (1681)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 24
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // CASE_LIST_PTRS(STACK_PTR) = 0; (1682)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16,
            getFIXED (mSTACK_FRAME) + 32 * (COREHALFWORD (mSTACK_PTR)) + 28
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // IF STACK_DUMP THEN (1683)
  if (1 & (bitToFixed (getBIT (1, mSTACK_DUMP))))
    // CALL DUMP_STACK; (1684)
    PASS1xDUMP_STACK (0);
  {
    reentryGuard = 0;
    return 0;
  }
}
