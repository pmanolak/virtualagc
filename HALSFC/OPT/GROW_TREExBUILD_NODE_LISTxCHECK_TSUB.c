/*
  File GROW_TREExBUILD_NODE_LISTxCHECK_TSUB.c generated by XCOM-I, 2024-08-09
  12:38:53.
*/

#include "runtimeC.h"

int32_t
GROW_TREExBUILD_NODE_LISTxCHECK_TSUB (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GROW_TREExBUILD_NODE_LISTxCHECK_TSUB");
  // PTR = SHR(OPR(PTR),16); (4879)
  {
    int32_t numberRHS = (int32_t)(SHR (
        getFIXED (
            mOPR
            + 4 * COREHALFWORD (mGROW_TREExBUILD_NODE_LISTxCHECK_TSUBxPTR)),
        16));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGROW_TREExBUILD_NODE_LISTxCHECK_TSUBxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF XHALMAT_QUAL(PTR + 1) = XVAC THEN (4880)
  if (1
      & (xEQ (
          bitToFixed (
              (putBITp (
                   16, mXHALMAT_QUALxPTR,
                   fixedToBit (
                       32, (int32_t)(xadd (
                               COREHALFWORD (
                                   mGROW_TREExBUILD_NODE_LISTxCHECK_TSUBxPTR),
                               1)))),
               XHALMAT_QUAL (0))),
          COREHALFWORD (mXVAC))))
    // CALL BUMP_D_N(SHR(OPR(PTR+1), 16)); (4881)
    {
      putBITp (
          16, mBUMP_D_NxPTR,
          fixedToBit (
              32,
              (int32_t)(SHR (
                  getFIXED (
                      mOPR
                      + 4
                            * xadd (
                                COREHALFWORD (
                                    mGROW_TREExBUILD_NODE_LISTxCHECK_TSUBxPTR),
                                1)),
                  16))));
      BUMP_D_N (0);
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
