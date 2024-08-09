/*
  File OBJECT_CONDENSERxUPLOC.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
OBJECT_CONDENSERxUPLOC (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "OBJECT_CONDENSERxUPLOC");
  // N = SHR(N+1, 1); (14712)
  {
    int32_t numberRHS = (int32_t)(SHR (
        xadd (COREHALFWORD (mOBJECT_CONDENSERxUPLOCxN), 1), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOBJECT_CONDENSERxUPLOCxN, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF EMITTING THEN (14713)
  if (1 & (bitToFixed (getBIT (1, mEMITTING))))
    // CURRENT_ADDRESS = CURRENT_ADDRESS + N; (14714)
    {
      int32_t numberRHS = (int32_t)(xadd (
          getFIXED (mWORKSEG + 4 * getFIXED (mCURRENT_ESDID)),
          COREHALFWORD (mOBJECT_CONDENSERxUPLOCxN)));
      putFIXED (mWORKSEG + 4 * (getFIXED (mCURRENT_ESDID)), numberRHS);
    }
  // ELSE (14715)
  else
    // CALL LABEL_UPDATE(N); (14716)
    {
      putBITp (16, mOBJECT_CONDENSERxLABEL_UPDATExLEN,
               getBIT (16, mOBJECT_CONDENSERxUPLOCxN));
      OBJECT_CONDENSERxLABEL_UPDATE (0);
    }
  // DELTA = 0; (14717)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mOBJECT_CONDENSERxDELTA, numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
