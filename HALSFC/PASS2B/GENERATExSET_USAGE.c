/*
  File GENERATExSET_USAGE.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExSET_USAGE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExSET_USAGE");
  // USAGE(R) = USAGE(R) | TRUE; (3495)
  {
    int32_t numberRHS = (int32_t)(xOR (
        COREHALFWORD (mUSAGE + 2 * COREHALFWORD (mGENERATExSET_USAGExR)), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mUSAGE + 2 * (COREHALFWORD (mGENERATExSET_USAGExR)), bitRHS);
    bitRHS->inUse = 0;
  }
  // R_CONTENTS(R) = RFORM; (3496)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExSET_USAGExRFORM);
    putBIT (8, mR_CONTENTS + 1 * (COREHALFWORD (mGENERATExSET_USAGExR)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // IF RFORM = LIT THEN (3497)
  if (1 & (xEQ (COREHALFWORD (mGENERATExSET_USAGExRFORM), BYTE0 (mLIT))))
    // DO; (3498)
    {
    rs1:;
      // R_CON(R) = RVAR; (3499)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mGENERATExSET_USAGExRVAR));
        putFIXED (mR_CON + 4 * (COREHALFWORD (mGENERATExSET_USAGExR)),
                  numberRHS);
      }
      // R_XCON(R) = RXCON; (3500)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mGENERATExSET_USAGExRXCON));
        putFIXED (mR_XCON + 4 * (COREHALFWORD (mGENERATExSET_USAGExR)),
                  numberRHS);
      }
    es1:;
    } // End of DO block
  // ELSE (3501)
  else
    // DO; (3502)
    {
    rs2:;
      // R_VAR(R) = RVAR; (3503)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mGENERATExSET_USAGExRVAR));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mR_VAR + 2 * (COREHALFWORD (mGENERATExSET_USAGExR)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // R_INX_CON(R) = RXCON; (3504)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mGENERATExSET_USAGExRXCON));
        putFIXED (mR_INX_CON + 4 * (COREHALFWORD (mGENERATExSET_USAGExR)),
                  numberRHS);
      }
      // R_INX(R) = RINX; (3505)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mGENERATExSET_USAGExRINX));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mR_INX + 2 * (COREHALFWORD (mGENERATExSET_USAGExR)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // R_CON(R) = 0; (3506)
      {
        int32_t numberRHS = (int32_t)(0);
        putFIXED (mR_CON + 4 * (COREHALFWORD (mGENERATExSET_USAGExR)),
                  numberRHS);
      }
    es2:;
    } // End of DO block
  // RXCON, RINX = 0; (3507)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mGENERATExSET_USAGExRXCON, numberRHS);
    putFIXED (mGENERATExSET_USAGExRINX, numberRHS);
  }
  // IF (R >= FR0) THEN (3508)
  if (1 & (xGE (COREHALFWORD (mGENERATExSET_USAGExR), BYTE0 (mFR0))))
    // DO; (3509)
    {
    rs3:;
      // IF (RFORM=VAC) THEN (3510)
      if (1 & (xEQ (COREHALFWORD (mGENERATExSET_USAGExRFORM), BYTE0 (mVAC))))
        // DO; (3511)
        {
        rs3s1:;
          // IF (OPMODE(R_TYPE(R))=4) THEN (3512)
          if (1
              & (xEQ (BYTE0 (mOPMODE
                             + 1
                                   * BYTE0 (mR_TYPE
                                            + 1
                                                  * COREHALFWORD (
                                                      mGENERATExSET_USAGExR))),
                      4)))
            // DOUBLE_TYPE(R) = R_TYPE(R); (3513)
            {
              descriptor_t *bitRHS = getBIT (
                  8, mR_TYPE + 1 * COREHALFWORD (mGENERATExSET_USAGExR));
              putBIT (
                  8, mDOUBLE_TYPE + 1 * (COREHALFWORD (mGENERATExSET_USAGExR)),
                  bitRHS);
              bitRHS->inUse = 0;
            }
        es3s1:;
        } // End of DO block
      // ELSE (3514)
      else
        // IF (RFORM=SYM) THEN (3515)
        if (1 & (xEQ (COREHALFWORD (mGENERATExSET_USAGExRFORM), BYTE0 (mSYM))))
          // DO; (3516)
          {
          rs3s2:;
            // IF (OPMODE(SYT_TYPE(RVAR))=4) THEN (3517)
            if (1
                & (xEQ (
                    BYTE0 (
                        mOPMODE
                        + 1
                              * BYTE0 (
                                  getFIXED (mSYM_TAB)
                                  + 34 * (getFIXED (mGENERATExSET_USAGExRVAR))
                                  + 32 + 1 * (0))),
                    4)))
              // DOUBLE_TYPE(R) = SYT_TYPE(RVAR); (3518)
              {
                descriptor_t *bitRHS = getBIT (
                    8, getFIXED (mSYM_TAB)
                           + 34 * (getFIXED (mGENERATExSET_USAGExRVAR)) + 32
                           + 1 * (0));
                putBIT (8,
                        mDOUBLE_TYPE
                            + 1 * (COREHALFWORD (mGENERATExSET_USAGExR)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
          es3s2:;
          } // End of DO block
    es3:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
