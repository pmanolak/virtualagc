/*
  File OBJECT_GENERATORxFORM_BDxCHECK_Z_LINKAGE.c generated by XCOM-I,
  2024-08-09 12:41:33.
*/

#include "runtimeC.h"

int32_t
OBJECT_GENERATORxFORM_BDxCHECK_Z_LINKAGE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard,
                               "OBJECT_GENERATORxFORM_BDxCHECK_Z_LINKAGE");
  // IF (ESD_NAME_LENGTH(PTR)& 128) ~= 0 THEN (15657)
  if (1
      & (xNEQ (
          xAND (
              BYTE0 (mESD_NAME_LENGTH
                     + 1
                           * COREHALFWORD (
                               mOBJECT_GENERATORxFORM_BDxCHECK_Z_LINKAGExPTR)),
              128),
          0)))
    // DO; (15658)
    {
    rs1:;
      // IX, IA, F = 1; (15659)
      {
        int32_t numberRHS = (int32_t)(1);
        putFIXED (mIX, numberRHS);
        putFIXED (mIA, numberRHS);
        putFIXED (mF, numberRHS);
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
