/*
  File GENERATExGEN_CLASS0xDEFINE_LABEL.c generated by XCOM-I, 2024-08-09
  12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xDEFINE_LABEL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS0xDEFINE_LABEL");
  // IF FORM(PTR) = LBL THEN (10779)
  if (1
      & (xEQ (COREHALFWORD (
                  getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xDEFINE_LABELxPTR))
                  + 32 + 2 * (0)),
              BYTE0 (mLBL))))
    // IF SYT_TYPE(LOC(PTR)) = STMT_LABEL THEN (10780)
    if (1
        & (xEQ (
            BYTE0 (getFIXED (mSYM_TAB)
                   + 34
                         * (COREHALFWORD (
                             getFIXED (mIND_STACK)
                             + 73
                                   * (COREHALFWORD (
                                       mGENERATExGEN_CLASS0xDEFINE_LABELxPTR))
                             + 40 + 2 * (0)))
                   + 32 + 1 * (0)),
            BYTE0 (mSTMT_LABEL))))
      // FLAG = SYT_DIMS(LOC(PTR)) > 3 | SYT_DIMS(LOC(PTR)) < 1; (10781)
      {
        int32_t numberRHS = (int32_t)(xOR (
            xGT (
                COREHALFWORD (
                    getFIXED (mSYM_TAB)
                    + 34
                          * (COREHALFWORD (
                              getFIXED (mIND_STACK)
                              + 73
                                    * (COREHALFWORD (
                                        mGENERATExGEN_CLASS0xDEFINE_LABELxPTR))
                              + 40 + 2 * (0)))
                    + 18 + 2 * (0)),
                3),
            xLT (
                COREHALFWORD (
                    getFIXED (mSYM_TAB)
                    + 34
                          * (COREHALFWORD (
                              getFIXED (mIND_STACK)
                              + 73
                                    * (COREHALFWORD (
                                        mGENERATExGEN_CLASS0xDEFINE_LABELxPTR))
                              + 40 + 2 * (0)))
                    + 18 + 2 * (0)),
                1)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mGENERATExGEN_CLASS0xDEFINE_LABELxFLAG, bitRHS);
        bitRHS->inUse = 0;
      }
  // CALL SET_LABEL(VAL(PTR), FLAG, 1); (10782)
  {
    putBITp (
        16, mGENERATExSET_LABELxSTMTNO,
        fixedToBit (
            32,
            (int32_t)(getFIXED (
                getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xDEFINE_LABELxPTR))
                + 12 + 4 * (0)))));
    putBITp (1, mGENERATExSET_LABELxFLAG1,
             getBIT (1, mGENERATExGEN_CLASS0xDEFINE_LABELxFLAG));
    putBITp (1, mGENERATExSET_LABELxFLAG2, fixedToBit (32, (int32_t)(1)));
    GENERATExSET_LABEL (0);
  }
  // CODE = ULBL + FORM(PTR) - LBL; (10783)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        xadd (BYTE0 (mULBL),
              COREHALFWORD (
                  getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xDEFINE_LABELxPTR))
                  + 32 + 2 * (0))),
        BYTE0 (mLBL)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGEN_CLASS0xDEFINE_LABELxCODE, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF ASSEMBLER_CODE THEN (10784)
  if (1 & (bitToFixed (getBIT (1, mASSEMBLER_CODE))))
    // DO; (10785)
    {
    rs1:;
      // IF CODE = ULBL THEN (10786)
      if (1
          & (xEQ (COREHALFWORD (mGENERATExGEN_CLASS0xDEFINE_LABELxCODE),
                  BYTE0 (mULBL))))
        // CHARSTRING = SYT_NAME(LOC(PTR)); (10787)
        {
          descriptor_t *stringRHS;
          stringRHS = getCHARACTER (
              getFIXED (mSYM_TAB)
              + 34
                    * (COREHALFWORD (
                        getFIXED (mIND_STACK)
                        + 73
                              * (COREHALFWORD (
                                  mGENERATExGEN_CLASS0xDEFINE_LABELxPTR))
                        + 40 + 2 * (0)))
              + 0 + 4 * (0));
          putCHARACTER (mCHARSTRING, stringRHS);
          stringRHS->inUse = 0;
        }
      // ELSE (10788)
      else
        // CHARSTRING = 'L#' || LOC(PTR); (10789)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              cToDescriptor (NULL, "L#"),
              bitToCharacter (getBIT (
                  16, getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExGEN_CLASS0xDEFINE_LABELxPTR))
                          + 40 + 2 * (0))));
          putCHARACTER (mCHARSTRING, stringRHS);
          stringRHS->inUse = 0;
        }
      // OUTPUT = HEX_LOCCTR||CHARSTRING||' EQU *'; (10790)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (xsCAT (HEX_LOCCTR (0), getCHARACTER (mCHARSTRING)),
                           cToDescriptor (NULL, " EQU *"));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // CALL EMITC(CODE, LOC(PTR)); (10791)
  {
    putBITp (16, mEMITCxTYPE,
             getBIT (16, mGENERATExGEN_CLASS0xDEFINE_LABELxCODE));
    putBITp (16, mEMITCxINST,
             getBIT (16, getFIXED (mIND_STACK)
                             + 73
                                   * (COREHALFWORD (
                                       mGENERATExGEN_CLASS0xDEFINE_LABELxPTR))
                             + 40 + 2 * (0)));
    EMITC (0);
  }
  // CALL RETURN_STACK_ENTRY(PTR); (10792)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
             getBIT (16, mGENERATExGEN_CLASS0xDEFINE_LABELxPTR));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  // LAST_FLOW_BLK = CURCBLK; (10793)
  {
    descriptor_t *bitRHS = getBIT (8, mCURCBLK);
    putBIT (16, mLAST_FLOW_BLK, bitRHS);
    bitRHS->inUse = 0;
  }
  // LAST_FLOW_CTR = CTR; (10794)
  {
    descriptor_t *bitRHS = getBIT (16, mCTR);
    putBIT (16, mLAST_FLOW_CTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // FLAG = FALSE; (10795)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExGEN_CLASS0xDEFINE_LABELxFLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
