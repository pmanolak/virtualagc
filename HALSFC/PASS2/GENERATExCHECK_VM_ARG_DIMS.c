/*
  File GENERATExCHECK_VM_ARG_DIMS.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExCHECK_VM_ARG_DIMS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExCHECK_VM_ARG_DIMS");
  // IF ROW(RIGHTOP) ~= (SHR(SYT_DIMS(ARGPOINT),8)& 255) | COLUMN(RIGHTOP) ~=
  // (SYT_DIMS(ARGPOINT)& 255) THEN (7932)
  if (1
      & (xOR (
          xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mRIGHTOP)) + 48 + 2 * (0)),
                xAND (SHR (COREHALFWORD (getFIXED (mSYM_TAB)
                                         + 34 * (COREHALFWORD (mARGPOINT)) + 18
                                         + 2 * (0)),
                           8),
                      255)),
          xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mRIGHTOP)) + 24 + 2 * (0)),
                xAND (COREHALFWORD (getFIXED (mSYM_TAB)
                                    + 34 * (COREHALFWORD (mARGPOINT)) + 18
                                    + 2 * (0)),
                      255)))))
    // IF CLASS=8 THEN (7933)
    if (1 & (xEQ (COREHALFWORD (mCLASS), 8)))
      // CALL ERRORS(CLASS_DI,110); (7934)
      {
        putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_DI));
        putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(110)));
        ERRORS (0);
      }
    // ELSE (7935)
    else
      // CALL ERRORS(CLASS_FD,101,''||ARGNO); (7936)
      {
        putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_FD));
        putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(101)));
        putCHARACTERp (mERRORSxTEXT,
                       xsCAT (cToDescriptor (NULL, ""),
                              bitToCharacter (getBIT (16, mARGNO))));
        ERRORS (0);
      }
  {
    reentryGuard = 0;
    return 0;
  }
}
