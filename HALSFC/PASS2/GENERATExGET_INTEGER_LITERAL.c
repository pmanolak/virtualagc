/*
  File GENERATExGET_INTEGER_LITERAL.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExGET_INTEGER_LITERAL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExGET_INTEGER_LITERAL");
  // PTR = GET_STACK_ENTRY; (3845)
  {
    int32_t numberRHS = (int32_t)(GENERATExGET_STACK_ENTRY (0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGET_INTEGER_LITERALxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // VAL(PTR) = VALUE; (3846)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (mGENERATExGET_INTEGER_LITERALxVALUE));
    putFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExGET_INTEGER_LITERALxPTR))
                  + 12 + 4 * (0),
              numberRHS);
  }
  // FORM(PTR) = LIT; (3847)
  {
    descriptor_t *bitRHS = getBIT (8, mLIT);
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGET_INTEGER_LITERALxPTR)) + 32
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // IF (VALUE > HALFMAX) | (VALUE < HALFMIN) THEN (3848)
  if (1
      & (xOR (xGT (getFIXED (mGENERATExGET_INTEGER_LITERALxVALUE),
                   getFIXED (mHALFMAX)),
              xLT (getFIXED (mGENERATExGET_INTEGER_LITERALxVALUE),
                   getFIXED (mHALFMIN)))))
    // TYPE(PTR) = DINTEGER; (3849)
    {
      descriptor_t *bitRHS = getBIT (8, mDINTEGER);
      putBIT (16,
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExGET_INTEGER_LITERALxPTR))
                  + 50 + 2 * (0),
              bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (3850)
  else
    // TYPE(PTR) = INTEGER; (3851)
    {
      descriptor_t *bitRHS = getBIT (8, mINTEGER);
      putBIT (16,
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExGET_INTEGER_LITERALxPTR))
                  + 50 + 2 * (0),
              bitRHS);
      bitRHS->inUse = 0;
    }
  // SIZE(PTR) = 1; (3852)
  {
    int32_t numberRHS = (int32_t)(1);
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGET_INTEGER_LITERALxPTR)) + 48
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // LOC(PTR) = -1; (3853)
  {
    int32_t numberRHS = (int32_t)(-1);
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGET_INTEGER_LITERALxPTR)) + 40
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // RETURN PTR; (3854)
  {
    reentryGuard = 0;
    return getBIT (16, mGENERATExGET_INTEGER_LITERALxPTR);
  }
}
