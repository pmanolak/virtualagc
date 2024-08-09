/*
  File MATCH_ARITH.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
MATCH_ARITH (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "MATCH_ARITH");
  // I=PSEUDO_TYPE(PTR(LOC1))-MAT_TYPE; (7566)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        BYTE0 (
            mPSEUDO_TYPE
            + 1 * COREHALFWORD (mPTR + 2 * COREHALFWORD (mMATCH_ARITHxLOC1))),
        3));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mMATCH_ARITHxI, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF (SHL(1,PSEUDO_TYPE(PTR(LOC2))-MAT_TYPE)&ARITH_VALID(I))=0 THEN (7567)
  if (1
      & (xEQ (
          xAND (SHL (1, xsubtract (
                            BYTE0 (mPSEUDO_TYPE
                                   + 1
                                         * COREHALFWORD (
                                             mPTR
                                             + 2
                                                   * COREHALFWORD (
                                                       mMATCH_ARITHxLOC2))),
                            3)),
                BYTE0 (mMATCH_ARITHxARITH_VALID
                       + 1 * COREHALFWORD (mMATCH_ARITHxI))),
          0)))
    // CALL ERROR(CLASS_E,6); (7568)
    {
      putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_E));
      putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(6)));
      ERROR (0);
    }
  // ELSE (7569)
  else
    // DO CASE I; (7570)
    {
    rs1:
      switch (COREHALFWORD (mMATCH_ARITHxI))
        {
        case 0:
          // CALL MATRIX_COMPARE(LOC1,LOC2,CLASS_EM,1); (7572)
          {
            putBITp (16, mMATRIX_COMPARExI, getBIT (16, mMATCH_ARITHxLOC1));
            putBITp (16, mMATRIX_COMPARExJ, getBIT (16, mMATCH_ARITHxLOC2));
            putBITp (16, mMATRIX_COMPARExCLASS, getBIT (16, mCLASS_EM));
            putBITp (16, mMATRIX_COMPARExNUM, fixedToBit (32, (int32_t)(1)));
            MATRIX_COMPARE (0);
          }
          break;
        case 1:
          // CALL VECTOR_COMPARE(LOC1,LOC2,CLASS_EV,1); (7573)
          {
            putBITp (16, mVECTOR_COMPARExI, getBIT (16, mMATCH_ARITHxLOC1));
            putBITp (16, mVECTOR_COMPARExJ, getBIT (16, mMATCH_ARITHxLOC2));
            putBITp (16, mVECTOR_COMPARExCLASS, getBIT (16, mCLASS_EV));
            putBITp (16, mVECTOR_COMPARExNUM, fixedToBit (32, (int32_t)(1)));
            VECTOR_COMPARE (0);
          }
          break;
        case 2:
          // CALL MATCH_SIMPLES(LOC1,LOC2); (7574)
          {
            putBITp (16, mMATCH_SIMPLESxLOC1, getBIT (16, mMATCH_ARITHxLOC1));
            putBITp (16, mMATCH_SIMPLESxLOC2, getBIT (16, mMATCH_ARITHxLOC2));
            MATCH_SIMPLES (0);
          }
          break;
        case 3:
          // CALL MATCH_SIMPLES(LOC1,LOC2); (7575)
          {
            putBITp (16, mMATCH_SIMPLESxLOC1, getBIT (16, mMATCH_ARITHxLOC1));
            putBITp (16, mMATCH_SIMPLESxLOC2, getBIT (16, mMATCH_ARITHxLOC2));
            MATCH_SIMPLES (0);
          }
          break;
        }
    } // End of DO CASE block
  {
    reentryGuard = 0;
    return 0;
  }
}
