/*
  File PASS2xPASS2_DISPATCHER.c generated by XCOM-I, 2024-08-09 12:39:13.
*/

#include "runtimeC.h"

int32_t
PASS2xPASS2_DISPATCHER (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PASS2xPASS2_DISPATCHER");
  // DO CASE GEN_CODE(TEMP_PTR); (2566)
  {
  rs1:
    switch (BYTE0 (getFIXED (mWORK_VARS)
                   + 11 * (COREHALFWORD (mPASS2xTEMP_PTR)) + 10 + 1 * (0)))
      {
      case 0:
        // RETURN; (2568)
        {
          reentryGuard = 0;
          return 0;
        }
        break;
      case 1:
        // CALL GEN_NOOSE; (2569)
        PASS2xGEN_NOOSE (0);
        break;
      case 2:
          // ; (2570)
          ;
        break;
      case 3:
        // CALL GEN_XREC; (2571)
        PASS2xGEN_XREC (0);
        break;
      case 4:
          // ; (2572)
          ;
        break;
      case 5:
          // ; (2573)
          ;
        break;
      case 6:
        // CALL GEN_AUXMAT_END; (2574)
        PASS2xGEN_AUXMAT_END (0);
        break;
      case 7:
        // CALL GEN_CASE_LIST(TEMP_PTR); (2575)
        {
          putBITp (16, mPASS2xGEN_CASE_LISTxHALMATp,
                   getBIT (16, mPASS2xTEMP_PTR));
          PASS2xGEN_CASE_LIST (0);
        }
        break;
      case 8:
        // CALL GEN_SNCS; (2576)
        PASS2xGEN_SNCS (0);
        break;
      }
  } // End of DO CASE block
  // IF (TAGS(TEMP_PTR) ~= 0) | (TARGET(TEMP_PTR) ~= 0) THEN (2576)
  if (1
      & (xOR (
          xNEQ (BYTE0 (getFIXED (mWORK_VARS)
                       + 11 * (COREHALFWORD (mPASS2xTEMP_PTR)) + 8 + 1 * (0)),
                0),
          xNEQ (COREHALFWORD (getFIXED (mWORK_VARS)
                              + 11 * (COREHALFWORD (mPASS2xTEMP_PTR)) + 6
                              + 2 * (0)),
                0))))
    // DO; (2577)
    {
    rs2:;
      // CALL GEN_TARGET; (2578)
      PASS2xGEN_TARGET (0);
      // TAGS(TEMP_PTR) = 0; (2579)
      {
        int32_t numberRHS = (int32_t)(0);
        putBIT (8,
                getFIXED (mWORK_VARS) + 11 * (COREHALFWORD (mPASS2xTEMP_PTR))
                    + 8 + 1 * (0),
                fixedToBit (8, numberRHS));
      }
      // TARGET(TEMP_PTR) = 0; (2580)
      {
        int32_t numberRHS = (int32_t)(0);
        putBIT (16,
                getFIXED (mWORK_VARS) + 11 * (COREHALFWORD (mPASS2xTEMP_PTR))
                    + 6 + 2 * (0),
                fixedToBit (16, numberRHS));
      }
    es2:;
    } // End of DO block
  // NOOSE(TEMP_PTR), AUXMAT1(TEMP_PTR), PTR(TEMP_PTR) = 0; (2581)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16,
            getFIXED (mWORK_VARS) + 11 * (COREHALFWORD (mPASS2xTEMP_PTR)) + 4
                + 2 * (0),
            fixedToBit (16, numberRHS));
    putBIT (16,
            getFIXED (mWORK_VARS) + 11 * (COREHALFWORD (mPASS2xTEMP_PTR)) + 2
                + 2 * (0),
            fixedToBit (16, numberRHS));
    putBIT (16,
            getFIXED (mWORK_VARS) + 11 * (COREHALFWORD (mPASS2xTEMP_PTR)) + 0
                + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // GEN_CODE(TEMP_PTR), PTR_TYPE(TEMP_PTR) = 0; (2582)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (8,
            getFIXED (mWORK_VARS) + 11 * (COREHALFWORD (mPASS2xTEMP_PTR)) + 10
                + 1 * (0),
            fixedToBit (8, numberRHS));
    putBIT (8,
            getFIXED (mWORK_VARS) + 11 * (COREHALFWORD (mPASS2xTEMP_PTR)) + 9
                + 1 * (0),
            fixedToBit (8, numberRHS));
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
