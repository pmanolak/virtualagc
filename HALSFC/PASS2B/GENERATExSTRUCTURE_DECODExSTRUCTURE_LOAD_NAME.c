/*
  File GENERATExSTRUCTURE_DECODExSTRUCTURE_LOAD_NAME.c generated by XCOM-I,
  2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExSTRUCTURE_DECODExSTRUCTURE_LOAD_NAME (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (
      reentryGuard, "GENERATExSTRUCTURE_DECODExSTRUCTURE_LOAD_NAME");
  // IF DECLMODE THEN (6232)
  if (1 & (bitToFixed (getBIT (1, mDECLMODE))))
    // CALL RESUME_LOCCTR(NARGINDEX); (6233)
    {
      putBITp (16, mGENERATExRESUME_LOCCTRxNEST, getBIT (16, mNARGINDEX));
      GENERATExRESUME_LOCCTR (0);
    }
  // INX_CON(PTR) = STRUCT_CON(PTR); (6234)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mIND_STACK)
        + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR)) + 8 + 4 * (0)));
    putFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR)) + 4
                  + 4 * (0),
              numberRHS);
  }
  // R = 0; (6235)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExSTRUCTURE_DECODExR, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF (FORM(PTR)=SYM) THEN (6236)
  if (1
      & (xEQ (
          COREHALFWORD (getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR))
                        + 32 + 2 * (0)),
          BYTE0 (mSYM))))
    // R = SYT_BASE(LOC(PTR)); (6237)
    {
      descriptor_t *bitRHS = getBIT (
          16,
          getFIXED (mP2SYMS)
              + 12
                    * (COREHALFWORD (
                        getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR))
                        + 40 + 2 * (0)))
              + 4 + 2 * (0));
      putBIT (16, mGENERATExSTRUCTURE_DECODExR, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF (R=REMOTE_BASE | NR_DEREF(PTR)) & (INX(PTR)=0) THEN (6238)
  if (1
      & (xAND (
          xOR (xEQ (COREHALFWORD (mGENERATExSTRUCTURE_DECODExR),
                    BYTE0 (mREMOTE_BASE)),
               BYTE0 (getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR))
                      + 60 + 1 * (0))),
          xEQ (COREHALFWORD (
                   getFIXED (mIND_STACK)
                   + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR)) + 34
                   + 2 * (0)),
               0))))
    // DO; (6239)
    {
    rs1:;
      // TEMP2 = TARGET_REGISTER; (6240)
      {
        descriptor_t *bitRHS = getBIT (16, mTARGET_REGISTER);
        int32_t numberRHS;
        numberRHS = bitToFixed (bitRHS);
        putFIXED (mTEMP2, numberRHS);
        bitRHS->inUse = 0;
      }
      // TARGET_REGISTER = -1; (6241)
      {
        int32_t numberRHS = (int32_t)(-1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mTARGET_REGISTER, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL SUBSCRIPT_RANGE_CHECK(PTR,1); (6242)
      {
        putBITp (16, mGENERATExSUBSCRIPT_RANGE_CHECKxOP,
                 getBIT (16, mGENERATExSTRUCTURE_DECODExPTR));
        putBITp (1, mGENERATExSUBSCRIPT_RANGE_CHECKxNEED_INDEXING,
                 fixedToBit (32, (int32_t)(1)));
        GENERATExSUBSCRIPT_RANGE_CHECK (0);
      }
      // TARGET_REGISTER = TEMP2; (6243)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mTEMP2));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mTARGET_REGISTER, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (6244)
  else
    // DO; (6245)
    {
    rs2:;
      // IF (HALMAT_OPCODE=85) | (HALMAT_OPCODE=86) | (HALMAT_OPCODE=87) |
      // ((HALMAT_OPCODE=90) &  (PMINDEX=3)) | ((HALMAT_OPCODE=90) &
      // (PMINDEX=6)) | ((HALMAT_OPCODE=25) & NAME_SUB)  THEN (6246)
      if (1
          & (xOR (xOR (xOR (xOR (xOR (xEQ (COREHALFWORD (mHALMAT_OPCODE), 85),
                                      xEQ (COREHALFWORD (mHALMAT_OPCODE), 86)),
                                 xEQ (COREHALFWORD (mHALMAT_OPCODE), 87)),
                            xAND (xEQ (COREHALFWORD (mHALMAT_OPCODE), 90),
                                  xEQ (COREHALFWORD (mPMINDEX), 3))),
                       xAND (xEQ (COREHALFWORD (mHALMAT_OPCODE), 90),
                             xEQ (COREHALFWORD (mPMINDEX), 6))),
                  xAND (xEQ (COREHALFWORD (mHALMAT_OPCODE), 25),
                        BYTE0 (mGENERATExNAME_SUB)))))
        // CALL FIX_STRUCT_INX(0,PTR); (6247)
        {
          putBITp (16, mGENERATExFIX_STRUCT_INXxIX,
                   fixedToBit (32, (int32_t)(0)));
          putBITp (16, mGENERATExFIX_STRUCT_INXxOP,
                   getBIT (16, mGENERATExSTRUCTURE_DECODExPTR));
          GENERATExFIX_STRUCT_INX (0);
        }
      // CALL SUBSCRIPT_RANGE_CHECK(PTR); (6248)
      {
        putBITp (16, mGENERATExSUBSCRIPT_RANGE_CHECKxOP,
                 getBIT (16, mGENERATExSTRUCTURE_DECODExPTR));
        GENERATExSUBSCRIPT_RANGE_CHECK (0);
      }
    es2:;
    } // End of DO block
  // IF POINTS_REMOTE(PTR) THEN (6249)
  if (1
      & (bitToFixed (
          getBIT (8, getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR))
                         + 68 + 1 * (0)))))
    // LIVES_REMOTE(PTR) = TRUE; (6250)
    {
      int32_t numberRHS = (int32_t)(1);
      putBIT (8,
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR)) + 69
                  + 1 * (0),
              fixedToBit (8, numberRHS));
    }
  // ELSE (6251)
  else
    // IF NAME_VAR(PTR) THEN (6252)
    if (1
        & (bitToFixed (getBIT (
            8, getFIXED (mIND_STACK)
                   + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR)) + 70
                   + 1 * (0)))))
      // LIVES_REMOTE(PTR) = FALSE; (6253)
      {
        int32_t numberRHS = (int32_t)(0);
        putBIT (8,
                getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR)) + 69
                    + 1 * (0),
                fixedToBit (8, numberRHS));
      }
  // IF (SYT_FLAGS(OP1) & NAME_OR_REMOTE) = NAME_OR_REMOTE THEN (6254)
  if (1
      & (xEQ (xAND (getFIXED (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1))
                              + 8 + 4 * (0)),
                    getFIXED (mNAME_OR_REMOTE)),
              getFIXED (mNAME_OR_REMOTE))))
    // POINTS_REMOTE(PTR) = TRUE; (6255)
    {
      int32_t numberRHS = (int32_t)(1);
      putBIT (8,
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR)) + 68
                  + 1 * (0),
              fixedToBit (8, numberRHS));
    }
  // ELSE (6256)
  else
    // POINTS_REMOTE(PTR) = FALSE; (6257)
    {
      int32_t numberRHS = (int32_t)(0);
      putBIT (8,
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR)) + 68
                  + 1 * (0),
              fixedToBit (8, numberRHS));
    }
  // IF (SYT_FLAGS(OP1) & NAME_FLAG) = NAME_FLAG THEN (6258)
  if (1
      & (xEQ (xAND (getFIXED (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1))
                              + 8 + 4 * (0)),
                    getFIXED (mNAME_FLAG)),
              getFIXED (mNAME_FLAG))))
    // NAME_VAR(PTR) = TRUE; (6259)
    {
      int32_t numberRHS = (int32_t)(1);
      putBIT (8,
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSTRUCTURE_DECODExPTR)) + 70
                  + 1 * (0),
              fixedToBit (8, numberRHS));
    }
  // CALL LOAD_NAME(PTR, TRUE); (6260)
  {
    putBITp (16, mGENERATExLOAD_NAMExPTR,
             getBIT (16, mGENERATExSTRUCTURE_DECODExPTR));
    putBITp (1, mGENERATExLOAD_NAMExWALK_STRUCT,
             fixedToBit (32, (int32_t)(1)));
    GENERATExLOAD_NAME (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}