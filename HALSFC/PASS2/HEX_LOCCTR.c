/*
  File HEX_LOCCTR.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

descriptor_t *
HEX_LOCCTR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "HEX_LOCCTR");
  // RETURN HEX(LOCCTR(INDEXNEST),6)||COLON; (968)
  {
    reentryGuard = 0;
    return xsCAT (
        (putFIXED (mHEXxHVAL,
                   getFIXED (mLOCCTR + 4 * COREHALFWORD (mINDEXNEST))),
         putFIXED (mHEXxN, 6), HEX (0)),
        getCHARACTER (mCOLON));
  }
}
