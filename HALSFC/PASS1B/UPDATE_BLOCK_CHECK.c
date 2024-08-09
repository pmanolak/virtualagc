/*
  File UPDATE_BLOCK_CHECK.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
UPDATE_BLOCK_CHECK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "UPDATE_BLOCK_CHECK");
  // IF UPDATE_BLOCK_LEVEL>0 THEN (7512)
  if (1 & (xGT (COREHALFWORD (mUPDATE_BLOCK_LEVEL), 0)))
    // IF SYT_NEST(FIXL(LOC))<NEST THEN (7513)
    if (1
        & (xLT (BYTE0 (getFIXED (mSYM_TAB)
                       + 34
                             * (getFIXED (
                                 mFIXL
                                 + 4 * COREHALFWORD (mUPDATE_BLOCK_CHECKxLOC)))
                       + 28 + 1 * (0)),
                getFIXED (mNEST))))
      // CALL ERROR(CLASS_PU,3,VAR(LOC)); (7514)
      {
        putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_PU));
        putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(3)));
        putCHARACTERp (
            mERRORxTEXT,
            getCHARACTER (mVAR + 4 * COREHALFWORD (mUPDATE_BLOCK_CHECKxLOC)));
        ERROR (0);
      }
  {
    reentryGuard = 0;
    return 0;
  }
}
