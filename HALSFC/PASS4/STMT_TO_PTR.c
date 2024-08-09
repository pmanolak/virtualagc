/*
  File STMT_TO_PTR.c generated by XCOM-I, 2024-08-09 12:40:27.
*/

#include "runtimeC.h"

int32_t
STMT_TO_PTR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "STMT_TO_PTR");
  // IF (STMT < FIRST_STMT) | (STMT > LAST_STMT) THEN (713)
  if (1
      & (xOR (
          xLT (COREHALFWORD (mSTMT_TO_PTRxSTMT), COREHALFWORD (mFIRST_STMT)),
          xGT (COREHALFWORD (mSTMT_TO_PTRxSTMT), COREHALFWORD (mLAST_STMT)))))
    // DO; (714)
    {
    rs1:;
      // OUTPUT = X1; (715)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mX1);
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = SDFLIST_ERR || 'BAD STMT # (' || STMT || ') DETECTED BY
      // STMT_TO_PTR ROUTINE ***'; (716)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (xsCAT (getCHARACTER (mSDFLIST_ERR),
                          cToDescriptor (NULL, "BAD STMT # (")),
                   bitToCharacter (getBIT (16, mSTMT_TO_PTRxSTMT))),
            cToDescriptor (NULL, ") DETECTED BY STMT_TO_PTR ROUTINE ***"));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // GO TO BAIL_OUT; (717)
      {
        resetAllReentryGuards ();
        longjmp (jbBAIL_OUT, 1);
      }
    es1:;
    } // End of DO block
  // OFFSET = (STMT - FIRST_STMT) * STMT_NODE_SIZE + BASE_STMT_OFFSET; (718)
  {
    int32_t numberRHS = (int32_t)(xadd (
        xmultiply (xsubtract (COREHALFWORD (mSTMT_TO_PTRxSTMT),
                              COREHALFWORD (mFIRST_STMT)),
                   COREHALFWORD (mSTMT_NODE_SIZE)),
        COREHALFWORD (mBASE_STMT_OFFSET)));
    putFIXED (mSTMT_TO_PTRxOFFSET, numberRHS);
  }
  // PAGE = BASE_STMT_PAGE; (719)
  {
    descriptor_t *bitRHS = getBIT (16, mBASE_STMT_PAGE);
    putBIT (16, mSTMT_TO_PTRxPAGE, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF OFFSET >= PAGE_SIZE THEN (720)
  if (1 & (xGE (getFIXED (mSTMT_TO_PTRxOFFSET), 1680)))
    // DO; (721)
    {
    rs2:;
      // PAGE = PAGE + OFFSET/PAGE_SIZE; (722)
      {
        int32_t numberRHS
            = (int32_t)(xadd (COREHALFWORD (mSTMT_TO_PTRxPAGE),
                              xdivide (getFIXED (mSTMT_TO_PTRxOFFSET), 1680)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSTMT_TO_PTRxPAGE, bitRHS);
        bitRHS->inUse = 0;
      }
      // OFFSET = OFFSET MOD PAGE_SIZE; (723)
      {
        int32_t numberRHS
            = (int32_t)(xmod (getFIXED (mSTMT_TO_PTRxOFFSET), 1680));
        putFIXED (mSTMT_TO_PTRxOFFSET, numberRHS);
      }
    es2:;
    } // End of DO block
  // RETURN (SHL(PAGE,16) + OFFSET); (724)
  {
    reentryGuard = 0;
    return xadd (SHL (COREHALFWORD (mSTMT_TO_PTRxPAGE), 16),
                 getFIXED (mSTMT_TO_PTRxOFFSET));
  }
}
