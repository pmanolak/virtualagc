/*
  File GENERATExINTEGER_VALUE.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExINTEGER_VALUE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExINTEGER_VALUE");
  // IF FORM(PTR) ~= LIT THEN (5535)
  if (1
      & (xNEQ (
          COREHALFWORD (getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExINTEGER_VALUExPTR))
                        + 32 + 2 * (0)),
          BYTE0 (mLIT))))
    // RETURN NEGMAX; (5536)
    {
      reentryGuard = 0;
      return getFIXED (mNEGMAX);
    }
  // IF DATATYPE(TYPE(PTR)) = INTEGER THEN (5537)
  if (1
      & (xEQ (
          BYTE0 (mDATATYPE
                 + 1
                       * COREHALFWORD (
                           getFIXED (mIND_STACK)
                           + 73 * (COREHALFWORD (mGENERATExINTEGER_VALUExPTR))
                           + 50 + 2 * (0))),
          BYTE0 (mINTEGER))))
    // RETURN VAL(PTR); (5538)
    {
      reentryGuard = 0;
      return getFIXED (getFIXED (mIND_STACK)
                       + 73 * (COREHALFWORD (mGENERATExINTEGER_VALUExPTR)) + 12
                       + 4 * (0));
    }
  // DW(0) = VAL(PTR); (5539)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mIND_STACK)
        + 73 * (COREHALFWORD (mGENERATExINTEGER_VALUExPTR)) + 12 + 4 * (0)));
    putFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0 + 4 * (0), numberRHS);
  }
  // DW(1) = XVAL(PTR); (5540)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mIND_STACK)
        + 73 * (COREHALFWORD (mGENERATExINTEGER_VALUExPTR)) + 16 + 4 * (0)));
    putFIXED (getFIXED (mFOR_DW) + 4 * (1) + 0 + 4 * (0), numberRHS);
  }
  // IF INTEGERIZABLE THEN (5541)
  if (1 & (GENERATExINTEGERIZABLE (0)))
    // IF INTEGER_VALUED THEN (5542)
    if (1 & (GENERATExINTEGER_VALUED (0)))
      // RETURN DW(3); (5543)
      {
        reentryGuard = 0;
        return getFIXED (getFIXED (mFOR_DW) + 4 * (3) + 0 + 4 * (0));
      }
  // RETURN NEGMAX; (5544)
  {
    reentryGuard = 0;
    return getFIXED (mNEGMAX);
  }
}
