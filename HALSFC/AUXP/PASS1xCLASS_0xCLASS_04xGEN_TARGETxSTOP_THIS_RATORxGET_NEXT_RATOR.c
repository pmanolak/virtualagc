/*
  File PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_THIS_RATORxGET_NEXT_RATOR.c
  generated by XCOM-I, 2024-08-09 12:39:13.
*/

#include "runtimeC.h"

descriptor_t *
PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_THIS_RATORxGET_NEXT_RATOR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (
      reentryGuard,
      "PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_THIS_RATORxGET_NEXT_RATOR");
  // TEMP_MAT = HALMAT(HALMAT_LINE); (2412)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        mHALMAT
        + 4
              * COREHALFWORD (
                  mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_THIS_RATORxGET_NEXT_RATORxHALMAT_LINE)));
    putFIXED (
        mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_THIS_RATORxGET_NEXT_RATORxTEMP_MAT,
        numberRHS);
  }
  // IF (TEMP_MAT & 1) = 1 THEN (2413)
  if (1
      & (xEQ (
          xAND (
              getFIXED (
                  mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_THIS_RATORxGET_NEXT_RATORxTEMP_MAT),
              1),
          1)))
    // TEMP_MAT = HALMAT(HALMAT_LINE - 1); (2414)
    {
      int32_t numberRHS = (int32_t)(getFIXED (
          mHALMAT
          + 4
                * xsubtract (
                    COREHALFWORD (
                        mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_THIS_RATORxGET_NEXT_RATORxHALMAT_LINE),
                    1)));
      putFIXED (
          mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_THIS_RATORxGET_NEXT_RATORxTEMP_MAT,
          numberRHS);
    }
  // RETURN SHR(TEMP_MAT, 4) &  4095; (2415)
  {
    reentryGuard = 0;
    return fixedToBit (
        32,
        (int32_t)(xAND (
            SHR (
                getFIXED (
                    mPASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_THIS_RATORxGET_NEXT_RATORxTEMP_MAT),
                4),
            4095)));
  }
}
