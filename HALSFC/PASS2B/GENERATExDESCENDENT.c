/*
  File GENERATExDESCENDENT.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExDESCENDENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExDESCENDENT");
  // IF SYT_TYPE(XLOC) = STRUCTURE THEN (7762)
  if (1
      & (xEQ (BYTE0 (getFIXED (mSYM_TAB)
                     + 34 * (COREHALFWORD (mGENERATExDESCENDENTxXLOC)) + 32
                     + 1 * (0)),
              BYTE0 (mSTRUCTURE))))
    // DO; (7763)
    {
    rs1:;
      // IF (SYT_FLAGS(XLOC) & EVIL_FLAGS) = EVIL_FLAGS THEN (7764)
      if (1
          & (xEQ (
              xAND (getFIXED (getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mGENERATExDESCENDENTxXLOC))
                              + 8 + 4 * (0)),
                    getFIXED (mEVIL_FLAGS)),
              getFIXED (mEVIL_FLAGS))))
        // CALL ERRORS(CLASS_DQ,100); (7765)
        {
          putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_DQ));
          putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(100)));
          ERRORS (0);
        }
      // IF (SYT_FLAGS(XLOC) & NAME_FLAG) ~= 0 THEN (7766)
      if (1
          & (xNEQ (
              xAND (getFIXED (getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mGENERATExDESCENDENTxXLOC))
                              + 8 + 4 * (0)),
                    getFIXED (mNAME_FLAG)),
              0)))
        // RETURN 0; (7767)
        {
          reentryGuard = 0;
          return fixedToBit (32, (int32_t)(0));
        }
      // KIN = SYT_LINK1(XLOC); (7768)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mGENERATExDESCENDENTxXLOC))
                              + 24 + 2 * (0));
        putBIT (16, mKIN, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF KIN > 0 THEN (7769)
      if (1 & (xGT (COREHALFWORD (mKIN), 0)))
        // RETURN KIN; (7770)
        {
          reentryGuard = 0;
          return getBIT (16, mKIN);
        }
      // KIN = SYT_DIMS(XLOC); (7771)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mGENERATExDESCENDENTxXLOC))
                              + 18 + 2 * (0));
        putBIT (16, mKIN, bitRHS);
        bitRHS->inUse = 0;
      }
      // DO CASE REF; (7772)
      {
      rs1s1:
        switch (COREHALFWORD (mGENERATExDESCENDENTxREF))
          {
          case 0:
            // SYT_LINK2(KIN) = XLOC; (7774)
            {
              descriptor_t *bitRHS = getBIT (16, mGENERATExDESCENDENTxXLOC);
              putBIT (16,
                      getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mKIN)) + 26
                          + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          case 1:
            // SYT_DIMS(KIN) = XLOC; (7775)
            {
              descriptor_t *bitRHS = getBIT (16, mGENERATExDESCENDENTxXLOC);
              putBIT (16,
                      getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mKIN)) + 18
                          + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            break;
          }
      } // End of DO CASE block
      // STRUCT_MOD(REF) = STRUCT_MOD(REF) + SYT_ADDR(XLOC); (7775)
      {
        int32_t numberRHS = (int32_t)(xadd (
            getFIXED (mGENERATExSTRUCT_MOD
                      + 4 * COREHALFWORD (mGENERATExDESCENDENTxREF)),
            getFIXED (getFIXED (mSYM_TAB)
                      + 34 * (COREHALFWORD (mGENERATExDESCENDENTxXLOC)) + 4
                      + 4 * (0))));
        putFIXED (mGENERATExSTRUCT_MOD
                      + 4 * (COREHALFWORD (mGENERATExDESCENDENTxREF)),
                  numberRHS);
      }
      // RETURN KIN; (7776)
      {
        reentryGuard = 0;
        return getBIT (16, mKIN);
      }
    es1:;
    } // End of DO block
  // RETURN 0; (7777)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
