/*
  File PRETTY_PRINT_MATxTEST_FOR_SKIP.c generated by XCOM-I, 2024-08-09
  12:39:13.
*/

#include "runtimeC.h"

int32_t
PRETTY_PRINT_MATxTEST_FOR_SKIP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PRETTY_PRINT_MATxTEST_FOR_SKIP");
  // IF (TEMP_MAT & 1) = 0 THEN (776)
  if (1 & (xEQ (xAND (getFIXED (mTEMP_MAT), 1), 0)))
    // DO; (777)
    {
    rs1:;
      // OP_CODE = SHR(TEMP_MAT, 4) &  4095; (778)
      {
        int32_t numberRHS
            = (int32_t)(xAND (SHR (getFIXED (mTEMP_MAT), 4), 4095));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPRETTY_PRINT_MATxTEST_FOR_SKIPxOP_CODE, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF (OP_CODE <= 4) & (OP_CODE >= 2) THEN (779)
      if (1
          & (xAND (
              xLE (COREHALFWORD (mPRETTY_PRINT_MATxTEST_FOR_SKIPxOP_CODE), 4),
              xGE (COREHALFWORD (mPRETTY_PRINT_MATxTEST_FOR_SKIPxOP_CODE),
                   2))))
        // STMT_NO = TRUE; (780)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (1, mPRETTY_PRINT_MATxSTMT_NO, bitRHS);
          bitRHS->inUse = 0;
        }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
