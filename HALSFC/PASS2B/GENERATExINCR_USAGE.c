/*
  File GENERATExINCR_USAGE.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExINCR_USAGE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExINCR_USAGE");
  // IF R > 0 THEN (3522)
  if (1 & (xGT (COREHALFWORD (mGENERATExINCR_USAGExR), 0)))
    // USAGE(R) = USAGE(R) + 2; (3523)
    {
      int32_t numberRHS = (int32_t)(xadd (
          COREHALFWORD (mUSAGE + 2 * COREHALFWORD (mGENERATExINCR_USAGExR)),
          2));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mUSAGE + 2 * (COREHALFWORD (mGENERATExINCR_USAGExR)),
              bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (3524)
  else
    // IF R < 0 THEN (3525)
    if (1 & (xLT (COREHALFWORD (mGENERATExINCR_USAGExR), 0)))
      // DO; (3526)
      {
      rs1:;
        // R = -R; (3527)
        {
          int32_t numberRHS
              = (int32_t)(xminus (COREHALFWORD (mGENERATExINCR_USAGExR)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mGENERATExINCR_USAGExR, bitRHS);
          bitRHS->inUse = 0;
        }
        // DEL(R) = DEL(R) + 2; (3528)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExINCR_USAGExR)) + 28
                            + 2 * (0)),
              2));
          putBIT (16,
                  getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExINCR_USAGExR)) + 28
                      + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
      es1:;
      } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
