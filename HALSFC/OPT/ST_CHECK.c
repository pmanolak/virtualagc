/*
  File ST_CHECK.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
ST_CHECK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ST_CHECK");
  // IF SYTP(PTR+1) THEN (3136)
  if (1
      & ((putBITp (16, mSYTPxPTR,
                   fixedToBit (
                       32, (int32_t)(xadd (COREHALFWORD (mST_CHECKxPTR), 1)))),
          SYTP (0))))
    // RETURN TERM_CHECK(PTR, PTR+1); (3137)
    {
      reentryGuard = 0;
      return bitToFixed ((
          putBITp (16, mTERM_CHECKxPTR, getBIT (16, mST_CHECKxPTR)),
          putBITp (16, mTERM_CHECKxST_PTR,
                   fixedToBit (
                       32, (int32_t)(xadd (COREHALFWORD (mST_CHECKxPTR), 1)))),
          TERM_CHECK (0)));
    }
  // TSUB_PTR = SHR(OPR(PTR+1),16); (3138)
  {
    int32_t numberRHS = (int32_t)(SHR (
        getFIXED (mOPR + 4 * xadd (COREHALFWORD (mST_CHECKxPTR), 1)), 16));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mST_CHECKxTSUB_PTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF HALMAT_FLAG(PTR+1) THEN (3139)
  if (1
      & (bitToFixed ((
          putBITp (16, mHALMAT_FLAGxPTR,
                   fixedToBit (
                       32, (int32_t)(xadd (COREHALFWORD (mST_CHECKxPTR), 1)))),
          HALMAT_FLAG (0)))))
    // TSUB_PTR = NODE(TSUB_PTR) &  65535; (3140)
    {
      int32_t numberRHS = (int32_t)(xAND (
          getFIXED (mNODE + 4 * COREHALFWORD (mST_CHECKxTSUB_PTR)), 65535));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mST_CHECKxTSUB_PTR, bitRHS);
      bitRHS->inUse = 0;
    }
  // RETURN TERM_CHECK(PTR, TSUB_PTR + 1); (3141)
  {
    reentryGuard = 0;
    return bitToFixed (
        (putBITp (16, mTERM_CHECKxPTR, getBIT (16, mST_CHECKxPTR)),
         putBITp (16, mTERM_CHECKxST_PTR,
                  fixedToBit (32, (int32_t)(xadd (
                                      COREHALFWORD (mST_CHECKxTSUB_PTR), 1)))),
         TERM_CHECK (0)));
  }
}