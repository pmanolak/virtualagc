/*
  File GENERATExGETFREETEMP.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExGETFREETEMP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExGETFREETEMP");
  // IX1 = 1; (3880)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mIX1, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE UPPER(IX1) > 0; (3881)
  while (1 & (xGT (getFIXED (mUPPER + 4 * COREHALFWORD (mIX1)), 0)))
    {
      // IX1 = IX1 + 1; (3882)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mIX1), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mIX1, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // IF IX1 > LASTEMP THEN (3883)
  if (1 & (xGT (COREHALFWORD (mIX1), 100)))
    // CALL ERRORS(CLASS_BS, 112); (3884)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BS));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(112)));
      ERRORS (0);
    }
  // IF IX1 > FULLTEMP THEN (3885)
  if (1 & (xGT (COREHALFWORD (mIX1), COREHALFWORD (mFULLTEMP))))
    // FULLTEMP = IX1; (3886)
    {
      descriptor_t *bitRHS = getBIT (16, mIX1);
      putBIT (16, mFULLTEMP, bitRHS);
      bitRHS->inUse = 0;
    }
  // RETURN IX1; (3887)
  {
    reentryGuard = 0;
    return COREHALFWORD (mIX1);
  }
}
