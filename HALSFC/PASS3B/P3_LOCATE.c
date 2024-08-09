/*
  File P3_LOCATE.c generated by XCOM-I, 2024-08-09 12:42:16.
*/

#include "runtimeC.h"

int32_t
P3_LOCATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "P3_LOCATE");
  // CALL P3_PTR_LOCATE(PTR,FLAGS); (1221)
  {
    putFIXED (mP3_PTR_LOCATExPTR, getFIXED (mP3_LOCATExPTR));
    putBITp (8, mP3_PTR_LOCATExFLAGS, getBIT (8, mP3_LOCATExFLAGS));
    P3_PTR_LOCATE (0);
  }
  // COREWORD(BVAR) = LOC_ADDR; (1222)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mLOC_ADDR));
    COREWORD2 (getFIXED (mP3_LOCATExBVAR), numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
