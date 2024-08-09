/*
  File SYT_DUMPxCHECK_AND_ENTER.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

descriptor_t *
SYT_DUMPxCHECK_AND_ENTER (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SYT_DUMPxCHECK_AND_ENTER");
  // I = SYT_XREF(LOC); (5899)
  {
    descriptor_t *bitRHS
        = getBIT (16, getFIXED (mSYM_TAB)
                          + 34 * (COREHALFWORD (mSYT_DUMPxCHECK_AND_ENTERxLOC))
                          + 16 + 2 * (0));
    int32_t numberRHS;
    numberRHS = bitToFixed (bitRHS);
    putFIXED (mSYT_DUMPxCHECK_AND_ENTERxI, numberRHS);
    bitRHS->inUse = 0;
  }
  // J = SYT_FLAGS(LOC); (5900)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mSYM_TAB)
        + 34 * (COREHALFWORD (mSYT_DUMPxCHECK_AND_ENTERxLOC)) + 8 + 4 * (0)));
    putFIXED (mSYT_DUMPxCHECK_AND_ENTERxJ, numberRHS);
  }
  // IF TOKEN = EOFILE THEN (5901)
  if (1 & (xEQ (getFIXED (mTOKEN), getFIXED (mEOFILE))))
    // DO; (5902)
    {
    rs1:;
      // IF (J & RIGID_FLAG) ~= 0 THEN (5903)
      if (1
          & (xNEQ (xAND (getFIXED (mSYT_DUMPxCHECK_AND_ENTERxJ), 2147483648),
                   0)))
        // SYT_FLAGS(LOC) = (J & (~RIGID_FLAG)) | DUPL_FLAG; (5904)
        {
          int32_t numberRHS = (int32_t)(xOR (
              xAND (getFIXED (mSYT_DUMPxCHECK_AND_ENTERxJ), 2147483647),
              67108864));
          putFIXED (getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mSYT_DUMPxCHECK_AND_ENTERxLOC))
                        + 8 + 4 * (0),
                    numberRHS);
        }
      // ELSE (5905)
      else
        // SYT_FLAGS(LOC) = J & (~DUPL_FLAG); (5906)
        {
          int32_t numberRHS = (int32_t)(xAND (
              getFIXED (mSYT_DUMPxCHECK_AND_ENTERxJ), 4227858431));
          putFIXED (getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mSYT_DUMPxCHECK_AND_ENTERxLOC))
                        + 8 + 4 * (0),
                    numberRHS);
        }
      // IF I > 0 THEN (5907)
      if (1 & (xGT (getFIXED (mSYT_DUMPxCHECK_AND_ENTERxI), 0)))
        // DO; (5908)
        {
        rs1s1:;
          // SYT_XREF(LOC) = SHR(XREF(I), 16); (5909)
          {
            int32_t numberRHS = (int32_t)(SHR (
                getFIXED (getFIXED (mCROSS_REF)
                          + 4 * (getFIXED (mSYT_DUMPxCHECK_AND_ENTERxI)) + 0
                          + 4 * (0)),
                16));
            putBIT (16,
                    getFIXED (mSYM_TAB)
                        + 34 * (COREHALFWORD (mSYT_DUMPxCHECK_AND_ENTERxLOC))
                        + 16 + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
          // XREF(I) = XREF(I) &  65535; (5910)
          {
            int32_t numberRHS = (int32_t)(xAND (
                getFIXED (getFIXED (mCROSS_REF)
                          + 4 * (getFIXED (mSYT_DUMPxCHECK_AND_ENTERxI)) + 0
                          + 4 * (0)),
                65535));
            putFIXED (getFIXED (mCROSS_REF)
                          + 4 * (getFIXED (mSYT_DUMPxCHECK_AND_ENTERxI)) + 0
                          + 4 * (0),
                      numberRHS);
          }
        es1s1:;
        } // End of DO block
      // ELSE (5911)
      else
        // SYT_XREF(LOC) = 0; (5912)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mSYM_TAB)
                      + 34 * (COREHALFWORD (mSYT_DUMPxCHECK_AND_ENTERxLOC))
                      + 16 + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
    es1:;
    } // End of DO block
  // IF ALWAYS THEN (5913)
  if (1 & (bitToFixed (getBIT (1, mSYT_DUMPxCHECK_AND_ENTERxALWAYS))))
    // DO; (5914)
    {
    rs2:;
      // CALL ENTER_SORT(LOC); (5915)
      {
        putBITp (16, mSYT_DUMPxENTER_SORTxLOC,
                 getBIT (16, mSYT_DUMPxCHECK_AND_ENTERxLOC));
        SYT_DUMPxENTER_SORT (0);
      }
      // ALWAYS = FALSE; (5916)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mSYT_DUMPxCHECK_AND_ENTERxALWAYS, bitRHS);
        bitRHS->inUse = 0;
      }
      // RETURN TRUE; (5917)
      {
        reentryGuard = 0;
        return fixedToBit (32, (int32_t)(1));
      }
    es2:;
    } // End of DO block
  // IF (XREF(I) & XREF_MASK) > FIRST_STMT THEN (5918)
  if (1
      & (xGT (xAND (getFIXED (getFIXED (mCROSS_REF)
                              + 4 * (getFIXED (mSYT_DUMPxCHECK_AND_ENTERxI))
                              + 0 + 4 * (0)),
                    getFIXED (mXREF_MASK)),
              getFIXED (mCOMM + 4 * 11))))
    // DO; (5919)
    {
    rs3:;
      // CALL ENTER_SORT(LOC); (5920)
      {
        putBITp (16, mSYT_DUMPxENTER_SORTxLOC,
                 getBIT (16, mSYT_DUMPxCHECK_AND_ENTERxLOC));
        SYT_DUMPxENTER_SORT (0);
      }
      // RETURN TRUE; (5921)
      {
        reentryGuard = 0;
        return fixedToBit (32, (int32_t)(1));
      }
    es3:;
    } // End of DO block
  // RETURN FALSE; (5922)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
