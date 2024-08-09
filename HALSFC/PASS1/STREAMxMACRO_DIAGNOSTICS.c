/*
  File STREAMxMACRO_DIAGNOSTICS.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
STREAMxMACRO_DIAGNOSTICS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "STREAMxMACRO_DIAGNOSTICS");
  // OUTPUT = 'AT '||WHERE||'  NEXT_CHAR='||NEXT_CHAR||'  MACRO_EXPAN_LEVEL='
  // ||MACRO_EXPAN_LEVEL||'  MACRO_TEXT('||MACRO_POINT||')='||
  // MACRO_TEXT(MACRO_POINT)||'  PARM_REPLACE_PTR('||PARM_EXPAN_LEVEL||
  // ')='||PARM_REPLACE_PTR(PARM_EXPAN_LEVEL); (4703)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (
        xsCAT (
            xsCAT (
                xsCAT (
                    xsCAT (
                        xsCAT (
                            xsCAT (
                                xsCAT (
                                    xsCAT (
                                        xsCAT (
                                            xsCAT (
                                                xsCAT (
                                                    xsCAT (
                                                        cToDescriptor (NULL,
                                                                       "AT "),
                                                        bitToCharacter (getBIT (
                                                            16,
                                                            mSTREAMxMACRO_DIAGNOSTICSxWHERE))),
                                                    cToDescriptor (
                                                        NULL, "  NEXT_CHAR=")),
                                                bitToCharacter (
                                                    getBIT (8, mNEXT_CHAR))),
                                            cToDescriptor (
                                                NULL, "  MACRO_EXPAN_LEVEL=")),
                                        bitToCharacter (
                                            getBIT (16, mMACRO_EXPAN_LEVEL))),
                                    cToDescriptor (NULL, "  MACRO_TEXT(")),
                                fixedToCharacter (getFIXED (mMACRO_POINT))),
                            cToDescriptor (NULL, ")=")),
                        bitToCharacter (
                            getBIT (8, getFIXED (mMACRO_TEXTS)
                                           + 1 * (getFIXED (mMACRO_POINT)) + 0
                                           + 1 * (0)))),
                    cToDescriptor (NULL, "  PARM_REPLACE_PTR(")),
                bitToCharacter (getBIT (16, mPARM_EXPAN_LEVEL))),
            cToDescriptor (NULL, ")=")),
        bitToCharacter (getBIT (
            16, mPARM_REPLACE_PTR + 2 * COREHALFWORD (mPARM_EXPAN_LEVEL))));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
