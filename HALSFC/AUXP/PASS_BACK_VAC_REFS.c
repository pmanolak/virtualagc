/*
  File PASS_BACK_VAC_REFS.c generated by XCOM-I, 2024-08-09 12:39:13.
*/

#include "runtimeC.h"

int32_t
PASS_BACK_VAC_REFS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PASS_BACK_VAC_REFS");
  // IF (FRAME_FLAGS(STACK_PTR) & PREV_BLOCK_FLAG) = 0 THEN (1082)
  if (1
      & (xEQ (xAND (BYTE0 (getFIXED (mSTACK_FRAME)
                           + 32 * (COREHALFWORD (mSTACK_PTR)) + 31 + 1 * (0)),
                    2),
              0)))
    // CALL MERGE_VAC_REF_FRAMES(FRAME_VAC_REF(STACK_PTR),
    // FRAME_VAC_REF(STACK_PTR + 1), FRAME_START(FRAME_BLOCK_PTR(STACK_PTR)),
    // FRAME_START(STACK_PTR + WHICH_START) ); (1083)
    {
      putBITp (16, mMERGE_VAC_REF_FRAMESxFRAME1,
               getBIT (16, getFIXED (mSTACK_FRAME)
                               + 32 * (COREHALFWORD (mSTACK_PTR)) + 12
                               + 2 * (0)));
      putBITp (16, mMERGE_VAC_REF_FRAMESxFRAME2,
               getBIT (16, getFIXED (mSTACK_FRAME)
                               + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1))
                               + 12 + 2 * (0)));
      putBITp (16, mMERGE_VAC_REF_FRAMESxFIRST_MERGE,
               getBIT (16, getFIXED (mSTACK_FRAME)
                               + 32
                                     * (COREHALFWORD (
                                         getFIXED (mSTACK_FRAME)
                                         + 32 * (COREHALFWORD (mSTACK_PTR))
                                         + 26 + 2 * (0)))
                               + 4 + 2 * (0)));
      putBITp (
          16, mMERGE_VAC_REF_FRAMESxLAST_MERGE,
          getBIT (16, getFIXED (mSTACK_FRAME)
                          + 32
                                * (xadd (COREHALFWORD (mSTACK_PTR),
                                         COREHALFWORD (
                                             mPASS_BACK_VAC_REFSxWHICH_START)))
                          + 4 + 2 * (0)));
      MERGE_VAC_REF_FRAMES (0);
    }
  // ELSE (1084)
  else
    // DO; (1085)
    {
    rs1:;
      // IF (FRAME_FLAGS(STACK_PTR + 1) & PREV_BLOCK_FLAG) = 0 THEN (1086)
      if (1
          & (xEQ (xAND (BYTE0 (getFIXED (mSTACK_FRAME)
                               + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1))
                               + 31 + 1 * (0)),
                        2),
                  0)))
        // DO; (1087)
        {
        rs1s1:;
        // CHECK_PASS_VAC: (1088)
        CHECK_PASS_VAC:
          // IF FRAME_VAC_REF(STACK_PTR) = 0 THEN (1089)
          if (1
              & (xEQ (COREHALFWORD (getFIXED (mSTACK_FRAME)
                                    + 32 * (COREHALFWORD (mSTACK_PTR)) + 12
                                    + 2 * (0)),
                      0)))
            // DO; (1090)
            {
            rs1s1s1:;
              // FRAME_VAC_REF(STACK_PTR) = FRAME_VAC_REF(STACK_PTR + 1);
              // (1091)
              {
                descriptor_t *bitRHS = getBIT (
                    16, getFIXED (mSTACK_FRAME)
                            + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1)) + 12
                            + 2 * (0));
                putBIT (16,
                        getFIXED (mSTACK_FRAME)
                            + 32 * (COREHALFWORD (mSTACK_PTR)) + 12 + 2 * (0),
                        bitRHS);
                bitRHS->inUse = 0;
              }
            es1s1s1:;
            } // End of DO block
          // ELSE (1092)
          else
            // CALL MERGE_VAC_REF_FRAMES(FRAME_VAC_REF(STACK_PTR),
            // FRAME_VAC_REF(STACK_PTR + 1),
            // FRAME_START(FRAME_BLOCK_PTR(STACK_PTR)), FRAME_START(STACK_PTR +
            // WHICH_START) ); (1093)
            {
              putBITp (16, mMERGE_VAC_REF_FRAMESxFRAME1,
                       getBIT (16, getFIXED (mSTACK_FRAME)
                                       + 32 * (COREHALFWORD (mSTACK_PTR)) + 12
                                       + 2 * (0)));
              putBITp (
                  16, mMERGE_VAC_REF_FRAMESxFRAME2,
                  getBIT (16, getFIXED (mSTACK_FRAME)
                                  + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1))
                                  + 12 + 2 * (0)));
              putBITp (
                  16, mMERGE_VAC_REF_FRAMESxFIRST_MERGE,
                  getBIT (16, getFIXED (mSTACK_FRAME)
                                  + 32
                                        * (COREHALFWORD (
                                            getFIXED (mSTACK_FRAME)
                                            + 32 * (COREHALFWORD (mSTACK_PTR))
                                            + 26 + 2 * (0)))
                                  + 4 + 2 * (0)));
              putBITp (
                  16, mMERGE_VAC_REF_FRAMESxLAST_MERGE,
                  getBIT (
                      16,
                      getFIXED (mSTACK_FRAME)
                          + 32
                                * (xadd (COREHALFWORD (mSTACK_PTR),
                                         COREHALFWORD (
                                             mPASS_BACK_VAC_REFSxWHICH_START)))
                          + 4 + 2 * (0)));
              MERGE_VAC_REF_FRAMES (0);
            }
        es1s1:;
        } // End of DO block
      // ELSE (1094)
      else
        // DO; (1095)
        {
        rs1s2:;
          // IF FRAME_VAC_REF(STACK_PTR + 1) = 0 THEN (1096)
          if (1
              & (xEQ (
                  COREHALFWORD (getFIXED (mSTACK_FRAME)
                                + 32 * (xadd (COREHALFWORD (mSTACK_PTR), 1))
                                + 12 + 2 * (0)),
                  0)))
            // DO; (1097)
            {
            rs1s2s1:;
              // IF FRAME_VAC_REF(STACK_PTR) = 0 THEN (1098)
              if (1
                  & (xEQ (COREHALFWORD (getFIXED (mSTACK_FRAME)
                                        + 32 * (COREHALFWORD (mSTACK_PTR)) + 12
                                        + 2 * (0)),
                          0)))
                // DO; (1099)
                {
                rs1s2s1s1:;
                  // FRAME_VAC_REF(STACK_PTR) = NEW_ZERO_VAC_REF_FRAME; (1100)
                  {
                    descriptor_t *bitRHS = NEW_ZERO_VAC_REF_FRAME (0);
                    putBIT (16,
                            getFIXED (mSTACK_FRAME)
                                + 32 * (COREHALFWORD (mSTACK_PTR)) + 12
                                + 2 * (0),
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                es1s2s1s1:;
                } // End of DO block
            es1s2s1:;
            } // End of DO block
          // ELSE (1101)
          else
            // GO TO CHECK_PASS_VAC; (1102)
            goto CHECK_PASS_VAC;
        es1s2:;
        } // End of DO block
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
