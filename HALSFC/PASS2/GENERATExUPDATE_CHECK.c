/*
  File GENERATExUPDATE_CHECK.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExUPDATE_CHECK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExUPDATE_CHECK");
  // IF UPDATING > 0 THEN (6048)
  if (1 & (xGT (COREHALFWORD (mUPDATING), 0)))
    // IF (SYT_FLAGS(OP) & LOCK_BITS) ~= 0 THEN (6049)
    if (1
        & (xNEQ (
            xAND (getFIXED (getFIXED (mSYM_TAB)
                            + 34 * (COREHALFWORD (mGENERATExUPDATE_CHECKxOP))
                            + 8 + 4 * (0)),
                  getFIXED (mLOCK_BITS)),
            0)))
      // DO; (6050)
      {
      rs1:;
        // OP = SYT_LOCK#(OP); (6051)
        {
          descriptor_t *bitRHS = getBIT (
              8, getFIXED (mSYM_TAB)
                     + 34 * (COREHALFWORD (mGENERATExUPDATE_CHECKxOP)) + 31
                     + 1 * (0));
          putBIT (16, mGENERATExUPDATE_CHECKxOP, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF OP = 255 THEN (6052)
        if (1 & (xEQ (COREHALFWORD (mGENERATExUPDATE_CHECKxOP), 255)))
          // UPDATE_FLAGS =  32767 | UPDATE_FLAGS; (6053)
          {
            int32_t numberRHS = (int32_t)(xOR (
                32767,
                getFIXED (getFIXED (mP2SYMS) + 12 * (COREHALFWORD (mUPDATING))
                          + 0 + 4 * (0))));
            putFIXED (getFIXED (mP2SYMS) + 12 * (COREHALFWORD (mUPDATING)) + 0
                          + 4 * (0),
                      numberRHS);
          }
        // ELSE (6054)
        else
          // UPDATE_FLAGS = SHL(1, OP-1) | UPDATE_FLAGS; (6055)
          {
            int32_t numberRHS = (int32_t)(xOR (
                SHL (1,
                     xsubtract (COREHALFWORD (mGENERATExUPDATE_CHECKxOP), 1)),
                getFIXED (getFIXED (mP2SYMS) + 12 * (COREHALFWORD (mUPDATING))
                          + 0 + 4 * (0))));
            putFIXED (getFIXED (mP2SYMS) + 12 * (COREHALFWORD (mUPDATING)) + 0
                          + 4 * (0),
                      numberRHS);
          }
      es1:;
      } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
