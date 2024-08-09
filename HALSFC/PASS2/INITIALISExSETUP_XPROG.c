/*
  File INITIALISExSETUP_XPROG.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
INITIALISExSETUP_XPROG (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INITIALISExSETUP_XPROG");
  // DO WHILE XPROGLINK > 0; (2049)
  while (1 & (xGT (COREHALFWORD (mXPROGLINK), 0)))
    {
      // ESD_MAX = ESD_MAX + 1; (2050)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mESD_MAX), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mESD_MAX, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL ENTER_ESD(PROGNAME(XPROGLINK, 0), ESD_MAX, 2); (2051)
      {
        putCHARACTERp (
            mENTER_ESDxNAME,
            (putBITp (16, mPROGNAMExENTRY, getBIT (16, mXPROGLINK)),
             putBITp (16, mPROGNAMExFLAG, fixedToBit (32, (int32_t)(0))),
             PROGNAME (0)));
        putBITp (16, mENTER_ESDxPTR, getBIT (16, mESD_MAX));
        putBITp (16, mENTER_ESDxTYP, fixedToBit (32, (int32_t)(2)));
        ENTER_ESD (0);
      }
      // SYT_SCOPE(XPROGLINK) = ESD_MAX; (2052)
      {
        descriptor_t *bitRHS = getBIT (16, mESD_MAX);
        putBIT (8,
                getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mXPROGLINK)) + 29
                    + 1 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // XPROGLINK = SYT_LINK1(XPROGLINK); (2053)
      {
        descriptor_t *bitRHS = getBIT (
            16, getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mXPROGLINK)) + 24
                    + 2 * (0));
        putBIT (16, mXPROGLINK, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
