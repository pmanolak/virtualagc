/*
  File GENERATExMAJOR_STRUCTURE.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExMAJOR_STRUCTURE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExMAJOR_STRUCTURE");
  // IF TYPE(OP) = STRUCTURE THEN (4845)
  if (1
      & (xEQ (
          COREHALFWORD (getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExMAJOR_STRUCTURExOP))
                        + 50 + 2 * (0)),
          BYTE0 (mSTRUCTURE))))
    // IF SYT_DIMS(LOC(OP)) = LOC2(OP) THEN (4846)
    if (1
        & (xEQ (
            COREHALFWORD (
                getFIXED (mSYM_TAB)
                + 34
                      * (COREHALFWORD (
                          getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExMAJOR_STRUCTURExOP))
                          + 40 + 2 * (0)))
                + 18 + 2 * (0)),
            COREHALFWORD (getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExMAJOR_STRUCTURExOP))
                          + 42 + 2 * (0)))))
      // RETURN TRUE; (4847)
      {
        reentryGuard = 0;
        return fixedToBit (32, (int32_t)(1));
      }
  // RETURN FALSE; (4848)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
