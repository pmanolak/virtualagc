/*
  File REAL_LABEL.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

descriptor_t *
REAL_LABEL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "REAL_LABEL");
  // DO WHILE LOCATION(LBL) < 0; (14648)
  while (
      1
      & (xLT (getFIXED (getFIXED (mLAB_LOC)
                        + 8 * (COREHALFWORD (mREAL_LABELxLBL)) + 0 + 4 * (0)),
              0)))
    {
      // LBL = -LOCATION(LBL); (14649)
      {
        int32_t numberRHS = (int32_t)(xminus (
            getFIXED (getFIXED (mLAB_LOC)
                      + 8 * (COREHALFWORD (mREAL_LABELxLBL)) + 0 + 4 * (0))));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mREAL_LABELxLBL, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // RETURN LBL; (14650)
  {
    reentryGuard = 0;
    return getBIT (16, mREAL_LABELxLBL);
  }
}
