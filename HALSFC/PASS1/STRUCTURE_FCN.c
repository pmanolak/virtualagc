/*
  File STRUCTURE_FCN.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
STRUCTURE_FCN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "STRUCTURE_FCN");
  // IF SYT_TYPE(FIXL(MP))<MAJ_STRUC THEN (7900)
  if (1
      & (xLT (BYTE0 (getFIXED (mSYM_TAB)
                     + 34 * (getFIXED (mFIXL + 4 * getFIXED (mMP))) + 32
                     + 1 * (0)),
              10)))
    // RETURN; (7901)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF FIXV(MP)=0 THEN (7902)
  if (1 & (xEQ (getFIXED (mFIXV + 4 * getFIXED (mMP)), 0)))
    // FIXV(MP)=FIXL(MP); (7903)
    {
      int32_t numberRHS = (int32_t)(getFIXED (mFIXL + 4 * getFIXED (mMP)));
      putFIXED (mFIXV + 4 * (getFIXED (mMP)), numberRHS);
    }
  // FIXL(MP)=VAR_LENGTH(FIXL(MP)); (7904)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mSYM_TAB) + 34 * (getFIXED (mFIXL + 4 * getFIXED (mMP)))
                + 18 + 2 * (0));
    int32_t numberRHS;
    numberRHS = bitToFixed (bitRHS);
    putFIXED (mFIXL + 4 * (getFIXED (mMP)), numberRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
