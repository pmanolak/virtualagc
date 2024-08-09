/*
  File PASS2xGEN_SNCS.c generated by XCOM-I, 2024-08-09 12:39:13.
*/

#include "runtimeC.h"

int32_t
PASS2xGEN_SNCS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PASS2xGEN_SNCS");
  // CALL GEN_AUXRATOR(HALMAT# MOD 1800, PTR_TYPE(HALMAT#), 0, NOOSE_OPCODE);
  // (2562)
  {
    putBITp (16, mPASS2xGEN_AUXRATORxHALMATp,
             fixedToBit (
                 32, (int32_t)(xmod (COREHALFWORD (mPASS2xTEMP_PTR), 1800))));
    putBITp (5, mPASS2xGEN_AUXRATORxPTR_TYPE_VALUE,
             getBIT (8, getFIXED (mWORK_VARS)
                            + 11 * (COREHALFWORD (mPASS2xTEMP_PTR)) + 9
                            + 1 * (0)));
    putBITp (6, mPASS2xGEN_AUXRATORxTAGS_VALUE, fixedToBit (32, (int32_t)(0)));
    putBITp (4, mPASS2xGEN_AUXRATORxOPCODE, fixedToBit (32, (int32_t)(1)));
    PASS2xGEN_AUXRATOR (0);
  }
  // CALL GEN_AUXRAND(NOOSE(HALMAT#), PTR(HALMAT#)); (2563)
  {
    putBITp (16, mPASS2xGEN_AUXRANDxNOOSE_VALUE,
             getBIT (16, getFIXED (mWORK_VARS)
                             + 11 * (COREHALFWORD (mPASS2xTEMP_PTR)) + 4
                             + 2 * (0)));
    putBITp (16, mPASS2xGEN_AUXRANDxPTR_VALUE,
             getBIT (16, getFIXED (mWORK_VARS)
                             + 11 * (COREHALFWORD (mPASS2xTEMP_PTR)) + 0
                             + 2 * (0)));
    PASS2xGEN_AUXRAND (0);
  }
  // CALL GEN_AUXRATOR(HALMAT# MOD 1800, VAC, 0, NOOSE_OPCODE); (2564)
  {
    putBITp (16, mPASS2xGEN_AUXRATORxHALMATp,
             fixedToBit (
                 32, (int32_t)(xmod (COREHALFWORD (mPASS2xTEMP_PTR), 1800))));
    putBITp (5, mPASS2xGEN_AUXRATORxPTR_TYPE_VALUE,
             fixedToBit (32, (int32_t)(3)));
    putBITp (6, mPASS2xGEN_AUXRATORxTAGS_VALUE, fixedToBit (32, (int32_t)(0)));
    putBITp (4, mPASS2xGEN_AUXRATORxOPCODE, fixedToBit (32, (int32_t)(1)));
    PASS2xGEN_AUXRATOR (0);
  }
  // CALL GEN_AUXRAND(CELL1(AUXMAT1(HALMAT#)), HALMAT# MOD 1800); (2565)
  {
    putBITp (16, mPASS2xGEN_AUXRANDxNOOSE_VALUE,
             getBIT (16, getFIXED (mLIST_STRUX)
                             + 8
                                   * (COREHALFWORD (
                                       getFIXED (mWORK_VARS)
                                       + 11 * (COREHALFWORD (mPASS2xTEMP_PTR))
                                       + 2 + 2 * (0)))
                             + 0 + 2 * (0)));
    putBITp (16, mPASS2xGEN_AUXRANDxPTR_VALUE,
             fixedToBit (
                 32, (int32_t)(xmod (COREHALFWORD (mPASS2xTEMP_PTR), 1800))));
    PASS2xGEN_AUXRAND (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
