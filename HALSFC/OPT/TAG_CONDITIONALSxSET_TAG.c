/*
  File TAG_CONDITIONALSxSET_TAG.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
TAG_CONDITIONALSxSET_TAG (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "TAG_CONDITIONALSxSET_TAG");
  // FLAGS = FLAGS + 1; (3599)
  {
    int32_t numberRHS
        = (int32_t)(xadd (COREHALFWORD (mTAG_CONDITIONALSxFLAGS), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mTAG_CONDITIONALSxFLAGS, bitRHS);
    bitRHS->inUse = 0;
  }
  // OPR(PTR) = OPR(PTR) | REGISTER_TAG; (3600)
  {
    int32_t numberRHS = (int32_t)(xOR (
        getFIXED (mOPR + 4 * COREHALFWORD (mTAG_CONDITIONALSxSET_TAGxPTR)),
        getFIXED (mREGISTER_TAG)));
    putFIXED (mOPR + 4 * (COREHALFWORD (mTAG_CONDITIONALSxSET_TAGxPTR)),
              numberRHS);
  }
  // IF WATCH THEN (3601)
  if (1 & (bitToFixed (getBIT (8, mWATCH))))
    // OUTPUT = 'CONDITIONAL TAG:  '||PTR; (3602)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          cToDescriptor (NULL, "CONDITIONAL TAG:  "),
          bitToCharacter (getBIT (16, mTAG_CONDITIONALSxSET_TAGxPTR)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // IF PTR > LAST_TAG THEN (3603)
  if (1
      & (xGT (COREHALFWORD (mTAG_CONDITIONALSxSET_TAGxPTR),
              COREHALFWORD (mTAG_CONDITIONALSxLAST_TAG))))
    // LAST_TAG = PTR; (3604)
    {
      descriptor_t *bitRHS = getBIT (16, mTAG_CONDITIONALSxSET_TAGxPTR);
      putBIT (16, mTAG_CONDITIONALSxLAST_TAG, bitRHS);
      bitRHS->inUse = 0;
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
