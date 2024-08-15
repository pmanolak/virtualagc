/*
  File GENERATExCTON.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExCTON (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExCTON");
  // D_RTL_SETUP = TRUE; (7722)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mD_RTL_SETUP, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF CHECK_REMOTE(OP) | COLUMN(OP) > 0 THEN (7723)
  if (1
      & (xOR (bitToFixed ((putBITp (16, mGENERATExCHECK_REMOTExOP,
                                    getBIT (16, mGENERATExCTONxOP)),
                           GENERATExCHECK_REMOTE (0))),
              xGT (COREHALFWORD (getFIXED (mIND_STACK)
                                 + 73 * (COREHALFWORD (mGENERATExCTONxOP)) + 24
                                 + 2 * (0)),
                   0))))
    // OP = CHAR_CONVERT(OP); (7724)
    {
      descriptor_t *bitRHS = (putBITp (16, mGENERATExCHAR_CONVERTxOP,
                                       getBIT (16, mGENERATExCTONxOP)),
                              GENERATExCHAR_CONVERT (0));
      putBIT (16, mGENERATExCTONxOP, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF DATA_REMOTE & (CSECT_TYPE(LOC(OP),OP)=LOCAL#D) THEN (7725)
  if (1
      & (xAND (
          BYTE0 (mDATA_REMOTE),
          xEQ (
              bitToFixed ((
                  putBITp (
                      16, mCSECT_TYPExPTR,
                      getBIT (16, getFIXED (mIND_STACK)
                                      + 73 * (COREHALFWORD (mGENERATExCTONxOP))
                                      + 40 + 2 * (0))),
                  putBITp (16, mCSECT_TYPExOP, getBIT (16, mGENERATExCTONxOP)),
                  CSECT_TYPE (0))),
              6))))
    // OP = CHAR_CONVERT(OP); (7726)
    {
      descriptor_t *bitRHS = (putBITp (16, mGENERATExCHAR_CONVERTxOP,
                                       getBIT (16, mGENERATExCTONxOP)),
                              GENERATExCHAR_CONVERT (0));
      putBIT (16, mGENERATExCTONxOP, bitRHS);
      bitRHS->inUse = 0;
    }
  // CALL DROPSAVE(OP); (7727)
  {
    putBITp (16, mGENERATExDROPSAVExENTRY, getBIT (16, mGENERATExCTONxOP));
    GENERATExDROPSAVE (0);
  }
  // CALL FORCE_ADDRESS(PTRARG1, OP); (7728)
  {
    putBITp (16, mGENERATExFORCE_ADDRESSxTR, getBIT (8, mPTRARG1));
    putBITp (16, mGENERATExFORCE_ADDRESSxOP, getBIT (16, mGENERATExCTONxOP));
    GENERATExFORCE_ADDRESS (0);
  }
  // CALL GENLIBCALL('CTO' || TYPES(CHARTYPE(OPTYPE)+TAG)); (7729)
  {
    putCHARACTERp (
        mGENERATExGENLIBCALLxNAME,
        xsCAT (
            cToDescriptor (NULL, "CTO"),
            getCHARACTER (
                mGENERATExTYPES
                + 4
                      * xadd (
                          BYTE0 (mCHARTYPE
                                 + 1 * COREHALFWORD (mGENERATExCTONxOPTYPE)),
                          COREHALFWORD (mGENERATExCTONxTAG)))));
    GENERATExGENLIBCALL (0);
  }
  // CALL RETURN_STACK_ENTRY(OP); (7730)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
             getBIT (16, mGENERATExCTONxOP));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  // PTR = GET_STACK_ENTRY; (7731)
  {
    int32_t numberRHS = (int32_t)(GENERATExGET_STACK_ENTRY (0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExCTONxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL SET_RESULT_REG(PTR, OPTYPE); (7732)
  {
    putBITp (16, mGENERATExSET_RESULT_REGxOP, getBIT (16, mGENERATExCTONxPTR));
    putBITp (16, mGENERATExSET_RESULT_REGxOPTYPE,
             getBIT (16, mGENERATExCTONxOPTYPE));
    GENERATExSET_RESULT_REG (0);
  }
  // TAG, LASTRESULT = 0; (7733)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExCTONxTAG, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mLASTRESULT, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN PTR; (7734)
  {
    reentryGuard = 0;
    return getBIT (16, mGENERATExCTONxPTR);
  }
}