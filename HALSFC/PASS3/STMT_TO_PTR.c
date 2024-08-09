/*
  File STMT_TO_PTR.c generated by XCOM-I, 2024-08-09 12:40:16.
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
  // IF (STMT < FIRST_STMT) | (STMT > LAST_STMT) THEN (1068)
  if (1
      & (xOR (
          xLT (COREHALFWORD (mSTMT_TO_PTRxSTMT), getFIXED (mCOMM + 4 * 11)),
          xGT (COREHALFWORD (mSTMT_TO_PTRxSTMT), COREHALFWORD (mLAST_STMT)))))
    // DO; (1069)
    {
    rs1:;
      // OUTPUT = X1; (1070)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mX1);
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = P3ERR || 'BAD STMT # (' || STMT || ') DETECTED BY STMT_TO_PTR
      // ROUTINE ***'; (1071)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (xsCAT (getCHARACTER (mP3ERR),
                          cToDescriptor (NULL, "BAD STMT # (")),
                   bitToCharacter (getBIT (16, mSTMT_TO_PTRxSTMT))),
            cToDescriptor (NULL, ") DETECTED BY STMT_TO_PTR ROUTINE ***"));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // GO TO PHASE3_ERROR; (1072)
      {
        resetAllReentryGuards ();
        longjmp (jbPHASE3_ERROR, 1);
      }
    es1:;
    } // End of DO block
  // OFFSET = (STMT - FIRST_STMT)*STMT_NODE_SIZE + BASE_STMT_OFFSET; (1073)
  {
    int32_t numberRHS = (int32_t)(xadd (
        xmultiply (xsubtract (COREHALFWORD (mSTMT_TO_PTRxSTMT),
                              getFIXED (mCOMM + 4 * 11)),
                   COREHALFWORD (mSTMT_NODE_SIZE)),
        COREHALFWORD (mBASE_STMT_OFFSET)));
    putFIXED (mSTMT_TO_PTRxOFFSET, numberRHS);
  }
  // PAGE = BASE_STMT_PAGE; (1074)
  {
    descriptor_t *bitRHS = getBIT (16, mBASE_STMT_PAGE);
    putBIT (16, mSTMT_TO_PTRxPAGE, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF OFFSET >= PAGE_SIZE THEN (1075)
  if (1 & (xGE (getFIXED (mSTMT_TO_PTRxOFFSET), 1680)))
    // DO; (1076)
    {
    rs2:;
      // PAGE = PAGE + OFFSET/PAGE_SIZE; (1077)
      {
        int32_t numberRHS
            = (int32_t)(xadd (COREHALFWORD (mSTMT_TO_PTRxPAGE),
                              xdivide (getFIXED (mSTMT_TO_PTRxOFFSET), 1680)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSTMT_TO_PTRxPAGE, bitRHS);
        bitRHS->inUse = 0;
      }
      // OFFSET = OFFSET MOD PAGE_SIZE; (1078)
      {
        int32_t numberRHS
            = (int32_t)(xmod (getFIXED (mSTMT_TO_PTRxOFFSET), 1680));
        putFIXED (mSTMT_TO_PTRxOFFSET, numberRHS);
      }
    es2:;
    } // End of DO block
  // RETURN (SHL(PAGE,16) + OFFSET); (1079)
  {
    reentryGuard = 0;
    return xadd (SHL (COREHALFWORD (mSTMT_TO_PTRxPAGE), 16),
                 getFIXED (mSTMT_TO_PTRxOFFSET));
  }
}
