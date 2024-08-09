/*
  File CATALOG.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
CATALOG (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CATALOG");
  // IF TRACE THEN (3203)
  if (1 & (bitToFixed (getBIT (8, mTRACE))))
    // DO; (3204)
    {
    rs1:;
      // OUTPUT = 'CATALOG:  SYT_POINT '||SYT_POINT||' NEW_OP '||NEW_OP; (3205)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (xsCAT (cToDescriptor (NULL, "CATALOG:  SYT_POINT "),
                          bitToCharacter (getBIT (16, mCATALOGxSYT_POINT))),
                   cToDescriptor (NULL, " NEW_OP ")),
            bitToCharacter (getBIT (16, mCATALOGxNEW_OP)));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // TEMP = GET_FREE_SPACE(CATALOG_ENTRY_SIZE); (3206)
  {
    descriptor_t *bitRHS
        = (putBITp (16, mGET_FREE_SPACExSPACE, fixedToBit (32, (int32_t)(3))),
           GET_FREE_SPACE (0));
    putBIT (16, mCATALOGxTEMP, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF NEW_OP = 0 THEN (3207)
  if (1 & (xEQ (COREHALFWORD (mCATALOGxNEW_OP), 0)))
    // DO; (3208)
    {
    rs2:;
      // CALL SET_CATALOG_PTR(SYT_POINT,TEMP); (3209)
      {
        putBITp (16, mSET_CATALOG_PTRxPTR, getBIT (16, mCATALOGxSYT_POINT));
        putBITp (16, mSET_CATALOG_PTRxVAL, getBIT (16, mCATALOGxTEMP));
        SET_CATALOG_PTR (0);
      }
      // CALL SET_VALIDITY(SYT_POINT,TRUE); (3210)
      {
        putBITp (16, mSET_VALIDITYxPTR, getBIT (16, mCATALOGxSYT_POINT));
        putBITp (8, mSET_VALIDITYxVAL, fixedToBit (32, (int32_t)(1)));
        SET_VALIDITY (0);
      }
      // CALL CATALOG_ENTRY(TEMP,NODE_BEGINNING); (3211)
      {
        putBITp (16, mCATALOG_ENTRYxTEMP, getBIT (16, mCATALOGxTEMP));
        putBITp (16, mCATALOG_ENTRYxNODE_BEGINNING,
                 getBIT (16, mNODE_BEGINNING));
        CATALOG_ENTRY (0);
      }
    es2:;
    } // End of DO block
  // ELSE (3212)
  else
    // DO; (3213)
    {
    rs3:;
      // NEW_OP = 0; (3214)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mCATALOGxNEW_OP, bitRHS);
        bitRHS->inUse = 0;
      }
      // CSE_TAB(CSE_INX + 2) = TEMP; (3215)
      {
        descriptor_t *bitRHS = getBIT (16, mCATALOGxTEMP);
        putBIT (16, mCSE_TAB + 2 * (xadd (COREHALFWORD (mCSE_INX), 2)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL CATALOG_ENTRY(TEMP,NODE_BEGINNING); (3216)
      {
        putBITp (16, mCATALOG_ENTRYxTEMP, getBIT (16, mCATALOGxTEMP));
        putBITp (16, mCATALOG_ENTRYxNODE_BEGINNING,
                 getBIT (16, mNODE_BEGINNING));
        CATALOG_ENTRY (0);
      }
    es3:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
