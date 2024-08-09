/*
  File SDF_PTR_LOCATE.c generated by XCOM-I, 2024-08-09 12:40:27.
*/

#include "runtimeC.h"

int32_t
SDF_PTR_LOCATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SDF_PTR_LOCATE");
  // PNTR,LOC_PTR = PTR; (830)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mSDF_PTR_LOCATExPTR));
    putFIXED (getFIXED (mCOMMTABL_FULLWORD) + 4 * (6), numberRHS);
    putFIXED (mLOC_PTR, numberRHS);
  }
  // ARG = SHL(FLAGS,28) + 5; (831)
  {
    int32_t numberRHS
        = (int32_t)(xadd (SHL (BYTE0 (mSDF_PTR_LOCATExFLAGS), 28), 5));
    putFIXED (mSDF_PTR_LOCATExARG, numberRHS);
  }
  // CALL MONITOR(22,ARG); (832)
  MONITOR22 (getFIXED (mSDF_PTR_LOCATExARG));
  // LOC_ADDR = ADDRESS; (833)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (getFIXED (mCOMMTABL_FULLWORD) + 4 * 7));
    putFIXED (mLOC_ADDR, numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
