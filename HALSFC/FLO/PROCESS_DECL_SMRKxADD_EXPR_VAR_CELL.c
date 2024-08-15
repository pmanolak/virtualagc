/*
  File PROCESS_DECL_SMRKxADD_EXPR_VAR_CELL.c generated by XCOM-I, 2024-08-09
  12:38:39.
*/

#include "runtimeC.h"

int32_t
PROCESS_DECL_SMRKxADD_EXPR_VAR_CELL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "PROCESS_DECL_SMRKxADD_EXPR_VAR_CELL");
  // IF NO_INIT_NAMES ~= 0 THEN (1233)
  if (1 & (xNEQ (COREHALFWORD (mPROCESS_DECL_SMRKxNO_INIT_NAMES), 0)))
    // DO; (1234)
    {
    rs1:;
      // CELLSIZE = (2*NO_INIT_NAMES)+EXPR_VAR_CELL_OVHD; (1235)
      {
        int32_t numberRHS = (int32_t)(xadd (
            xmultiply (2, COREHALFWORD (mPROCESS_DECL_SMRKxNO_INIT_NAMES)),
            4));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mCELLSIZE, bitRHS);
        bitRHS->inUse = 0;
      }
      // EXPR_VAR_CELL_PTR = GET_CELL(CELLSIZE,ADDR(EXPR_VAR_CELL),MODF);
      // (1236)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (mGET_CELLxCELL_SIZE, COREHALFWORD (mCELLSIZE)),
            putFIXED (mGET_CELLxBVAR, ADDR ("PROCESS_DECL_SMRKxEXPR_VAR_CELL",
                                            0x80000000, NULL, 0)),
            putBITp (8, mGET_CELLxFLAGS, getBIT (8, mMODF)), GET_CELL (0)));
        putFIXED (mPROCESS_DECL_SMRKxEXPR_VAR_CELL_PTR, numberRHS);
      }
      // EXPR_VAR_CELL.LENGTH = CELLSIZE; (1237)
      {
        descriptor_t *bitRHS = getBIT (16, mCELLSIZE);
        putBIT (16,
                getFIXED (mPROCESS_DECL_SMRKxEXPR_VAR_CELL) + 6 * (0) + 0
                    + 2 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // EXPR_VAR_CELL.NO_VAR_ENTRIES = NO_INIT_NAMES; (1238)
      {
        descriptor_t *bitRHS = getBIT (16, mPROCESS_DECL_SMRKxNO_INIT_NAMES);
        putBIT (16,
                getFIXED (mPROCESS_DECL_SMRKxEXPR_VAR_CELL) + 6 * (0) + 2
                    + 2 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // DO LOOP_TEMP = 1 TO NO_INIT_NAMES; (1239)
      {
        int32_t from25, to25, by25;
        from25 = 1;
        to25 = bitToFixed (getBIT (16, mPROCESS_DECL_SMRKxNO_INIT_NAMES));
        by25 = 1;
        for (putBIT (16, mPROCESS_DECL_SMRKxLOOP_TEMP,
                     fixedToBit (16, from25));
             bitToFixed (getBIT (16, mPROCESS_DECL_SMRKxLOOP_TEMP)) <= to25;
             putBIT (16, mPROCESS_DECL_SMRKxLOOP_TEMP,
                     fixedToBit (16, bitToFixed (getBIT (
                                         16, mPROCESS_DECL_SMRKxLOOP_TEMP))
                                         + by25)))
          {
            // EXPR_VAR_CELL.ENTRIES(LOOP_TEMP-1) = NAME_INITIALS(LOOP_TEMP);
            // (1240)
            {
              descriptor_t *bitRHS = getBIT (
                  16, mNAME_INITIALS
                          + 2 * COREHALFWORD (mPROCESS_DECL_SMRKxLOOP_TEMP));
              putBIT (
                  16,
                  getFIXED (mPROCESS_DECL_SMRKxEXPR_VAR_CELL) + 6 * (0) + 4
                      + 2
                            * (xsubtract (
                                COREHALFWORD (mPROCESS_DECL_SMRKxLOOP_TEMP),
                                1)),
                  bitRHS);
              bitRHS->inUse = 0;
            }
          }
      } // End of DO for-loop block
      // NO_INIT_NAMES = 0; (1241)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPROCESS_DECL_SMRKxNO_INIT_NAMES, bitRHS);
        bitRHS->inUse = 0;
      }
      // RETURN EXPR_VAR_CELL_PTR; (1242)
      {
        reentryGuard = 0;
        return getFIXED (mPROCESS_DECL_SMRKxEXPR_VAR_CELL_PTR);
      }
    es1:;
    } // End of DO block
  // ELSE (1243)
  else
    // RETURN NILL; (1244)
    {
      reentryGuard = 0;
      return -1;
    }
}