/*
  File DUMP_VALIDS.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
DUMP_VALIDS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "DUMP_VALIDS");
  // OUTPUT = ''; (1626)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "");
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'SYT# REL# CATALOG_PTR    VARIABLE NAME FOR VALID VARS, ' ||
  // 'LEVEL =' || LEVEL || ', BLOCK# =' || BLOCK#; (1627)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (
        xsCAT (xsCAT (cToDescriptor (NULL, "SYT# REL# CATALOG_PTR    VARIABLE "
                                           "NAME FOR VALID VARS, LEVEL ="),
                      bitToCharacter (getBIT (16, mLEVEL))),
               cToDescriptor (NULL, ", BLOCK# =")),
        bitToCharacter (getBIT (16, mBLOCKp)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // DO FOR K = 2 TO COMM(10); (1628)
  {
    int32_t from36, to36, by36;
    from36 = 2;
    to36 = getFIXED (mCOMM + 4 * 10);
    by36 = 1;
    for (putBIT (16, mDUMP_VALIDSxK, fixedToBit (16, from36));
         bitToFixed (getBIT (16, mDUMP_VALIDSxK)) <= to36; putBIT (
             16, mDUMP_VALIDSxK,
             fixedToBit (16, bitToFixed (getBIT (16, mDUMP_VALIDSxK)) + by36)))
      {
        // IF VALIDITY(K) THEN (1629)
        if (1
            & (bitToFixed (
                (putBITp (16, mVALIDITYxPTR, getBIT (16, mDUMP_VALIDSxK)),
                 VALIDITY (0)))))
          // OUTPUT = FORMAT(K,4) || FORMAT(REL(K),5) ||
          // FORMAT(CATALOG_PTR(K),12) || '    ' || SYT_NAME(K); (1630)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                xsCAT (
                    xsCAT (
                        xsCAT ((putFIXED (mFORMATxIVAL,
                                          COREHALFWORD (mDUMP_VALIDSxK)),
                                putFIXED (mFORMATxN, 4), FORMAT (0)),
                               (putFIXED (
                                    mFORMATxIVAL,
                                    COREHALFWORD (
                                        getFIXED (mSYM_SHRINK)
                                        + 2 * (COREHALFWORD (mDUMP_VALIDSxK))
                                        + 0 + 2 * (0))),
                                putFIXED (mFORMATxN, 5), FORMAT (0))),
                        (putFIXED (mFORMATxIVAL,
                                   bitToFixed (
                                       (putBITp (16, mCATALOG_PTRxPTR,
                                                 getBIT (16, mDUMP_VALIDSxK)),
                                        CATALOG_PTR (0)))),
                         putFIXED (mFORMATxN, 12), FORMAT (0))),
                    cToDescriptor (NULL, "    ")),
                getCHARACTER (getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mDUMP_VALIDSxK)) + 0
                              + 4 * (0)));
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
