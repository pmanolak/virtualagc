/*
  File INITIALIZExINVALID_SYMBOL.c generated by XCOM-I, 2024-08-09 12:40:16.
*/

#include "runtimeC.h"

int32_t
INITIALIZExINVALID_SYMBOL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INITIALIZExINVALID_SYMBOL");
  // #DEL_SYMBOLS = #DEL_SYMBOLS + 1; (2409)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mpDEL_SYMBOLS), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mpDEL_SYMBOLS, bitRHS);
    bitRHS->inUse = 0;
  }
  // DEL_TAB(#DEL_SYMBOLS) = OP2; (2410)
  {
    descriptor_t *bitRHS = getBIT (16, mOP2);
    putBIT (16,
            getFIXED (mSORTING) + 12 * (COREHALFWORD (mpDEL_SYMBOLS)) + 8
                + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // PROC_TAB3(PROCPOINT) = PROC_TAB3(PROCPOINT) - 1; (2411)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        COREHALFWORD (mPROC_TAB3 + 2 * COREHALFWORD (mINITIALIZExPROCPOINT)),
        1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mPROC_TAB3 + 2 * (COREHALFWORD (mINITIALIZExPROCPOINT)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // SYT_NAME(OP1) = ''; (2412)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "");
    putCHARACTER (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1)) + 0
                      + 4 * (0),
                  stringRHS);
    stringRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
