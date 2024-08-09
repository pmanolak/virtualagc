/*
  File GENERATExSTRUCTFIX.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExSTRUCTFIX (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExSTRUCTFIX");
  // PTR = GET_STACK_ENTRY; (6140)
  {
    int32_t numberRHS = (int32_t)(GENERATExGET_STACK_ENTRY (0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExSTRUCTFIXxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // LOC(PTR) = OP; (6141)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExSTRUCTFIXxOP);
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExSTRUCTFIXxPTR)) + 40 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL UPDATE_CHECK(OP); (6142)
  {
    putBITp (16, mGENERATExUPDATE_CHECKxOP,
             getBIT (16, mGENERATExSTRUCTFIXxOP));
    GENERATExUPDATE_CHECK (0);
  }
  // TYPE(PTR) = SYT_TYPE(OP); (6143)
  {
    descriptor_t *bitRHS = getBIT (
        8, getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mGENERATExSTRUCTFIXxOP))
               + 32 + 1 * (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExSTRUCTFIXxPTR)) + 50 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // FORM(PTR) = SYM; (6144)
  {
    descriptor_t *bitRHS = getBIT (8, mSYM);
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExSTRUCTFIXxPTR)) + 32 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // OP2, LOC2(PTR) = SYT_DIMS(OP); (6145)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mGENERATExSTRUCTFIXxOP))
                + 18 + 2 * (0));
    putBIT (16, mOP2, bitRHS);
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExSTRUCTFIXxPTR)) + 42 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // IF (SYT_FLAGS(OP) & NAME_OR_REMOTE) = NAME_OR_REMOTE THEN (6146)
  if (1
      & (xEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mGENERATExSTRUCTFIXxOP))
                              + 8 + 4 * (0)),
                    getFIXED (mNAME_OR_REMOTE)),
              getFIXED (mNAME_OR_REMOTE))))
    // POINTS_REMOTE(PTR) = TRUE; (6147)
    {
      int32_t numberRHS = (int32_t)(1);
      putBIT (8,
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSTRUCTFIXxPTR)) + 68
                  + 1 * (0),
              fixedToBit (8, numberRHS));
    }
  // ELSE (6148)
  else
    // IF (SYT_FLAGS(OP) & REMOTE_FLAG) = REMOTE_FLAG THEN (6149)
    if (1
        & (xEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                + 34 * (COREHALFWORD (mGENERATExSTRUCTFIXxOP))
                                + 8 + 4 * (0)),
                      getFIXED (mREMOTE_FLAG)),
                getFIXED (mREMOTE_FLAG))))
      // LIVES_REMOTE(PTR) = TRUE; (6150)
      {
        int32_t numberRHS = (int32_t)(1);
        putBIT (8,
                getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExSTRUCTFIXxPTR)) + 69
                    + 1 * (0),
                fixedToBit (8, numberRHS));
      }
    // ELSE (6151)
    else
      // IF DATA_REMOTE & (CSECT_TYPE(LOC(PTR),PTR)=LOCAL#D) THEN (6152)
      if (1
          & (xAND (
              BYTE0 (mDATA_REMOTE),
              xEQ (bitToFixed (
                       (putBITp (
                            16, mCSECT_TYPExPTR,
                            getBIT (16, getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExSTRUCTFIXxPTR))
                                            + 40 + 2 * (0))),
                        putBITp (16, mCSECT_TYPExOP,
                                 getBIT (16, mGENERATExSTRUCTFIXxPTR)),
                        CSECT_TYPE (0))),
                   6))))
        // LIVES_REMOTE(PTR) = TRUE; (6153)
        {
          int32_t numberRHS = (int32_t)(1);
          putBIT (8,
                  getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExSTRUCTFIXxPTR)) + 69
                      + 1 * (0),
                  fixedToBit (8, numberRHS));
        }
  // IF (SYT_FLAGS(OP) & NAME_FLAG) = NAME_FLAG THEN (6154)
  if (1
      & (xEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mGENERATExSTRUCTFIXxOP))
                              + 8 + 4 * (0)),
                    getFIXED (mNAME_FLAG)),
              getFIXED (mNAME_FLAG))))
    // NAME_VAR(PTR) = TRUE; (6155)
    {
      int32_t numberRHS = (int32_t)(1);
      putBIT (8,
              getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExSTRUCTFIXxPTR)) + 70
                  + 1 * (0),
              fixedToBit (8, numberRHS));
    }
  // CALL SIZEFIX(PTR, OP2); (6156)
  {
    putBITp (16, mGENERATExSIZEFIXxPTR, getBIT (16, mGENERATExSTRUCTFIXxPTR));
    putBITp (16, mGENERATExSIZEFIXxOP1, getBIT (16, mOP2));
    GENERATExSIZEFIX (0);
  }
  // IF SYT_ARRAY(OP) ~= 0 THEN (6157)
  if (1
      & (xNEQ (COREHALFWORD (getFIXED (mSYM_TAB)
                             + 34 * (COREHALFWORD (mGENERATExSTRUCTFIXxOP))
                             + 20 + 2 * (0)),
               0)))
    // DO; (6158)
    {
    rs1:;
      // CALL SET_AREA(PTR); (6159)
      {
        putBITp (16, mGENERATExSET_AREAxPTR,
                 getBIT (16, mGENERATExSTRUCTFIXxPTR));
        GENERATExSET_AREA (0);
      }
      // XVAL(PTR), SUBLIMIT(STACK#) = AREASAVE; (6160)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mAREASAVE));
        putFIXED (getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExSTRUCTFIXxPTR)) + 16
                      + 4 * (0),
                  numberRHS);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATExSUBLIMIT + 2 * (COREHALFWORD (mSTACKp)), bitRHS);
        bitRHS->inUse = 0;
      }
      // COPY(PTR), STRUCT(PTR) = 1; (6161)
      {
        int32_t numberRHS = (int32_t)(1);
        putBIT (16,
                getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExSTRUCTFIXxPTR)) + 26
                    + 2 * (0),
                fixedToBit (16, numberRHS));
        putBIT (8,
                getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExSTRUCTFIXxPTR)) + 65
                    + 1 * (0),
                fixedToBit (8, numberRHS));
      }
      // DOPTR(CALL_LEVEL) = SDOPTR(CALL_LEVEL-DOPUSH(CALL_LEVEL)); (6162)
      {
        descriptor_t *bitRHS = getBIT (
            16,
            mGENERATExSDOPTR
                + 2
                      * xsubtract (COREHALFWORD (mCALL_LEVEL),
                                   BYTE0 (mGENERATExDOPUSH
                                          + 1 * COREHALFWORD (mCALL_LEVEL))));
        putBIT (16, mGENERATExDOPTR + 2 * (COREHALFWORD (mCALL_LEVEL)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // DOTOT(CALL_LEVEL) = DOPTR(CALL_LEVEL) + 1; (6163)
      {
        int32_t numberRHS = (int32_t)(xadd (
            COREHALFWORD (mGENERATExDOPTR + 2 * COREHALFWORD (mCALL_LEVEL)),
            1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATExDOTOT + 2 * (COREHALFWORD (mCALL_LEVEL)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // IF ~FLAG THEN (6164)
      if (1 & (xNOT (BYTE0 (mGENERATExSTRUCTFIXxFLAG))))
        // DO; (6165)
        {
        rs1s1:;
          // IF DOCOPY(CALL_LEVEL) > 0 THEN (6166)
          if (1
              & (xGT (COREHALFWORD (mDOCOPY + 2 * COREHALFWORD (mCALL_LEVEL)),
                      0)))
            // IF DOFORM(CALL_LEVEL) = 2 THEN (6167)
            if (1
                & (xEQ (COREHALFWORD (mGENERATExDOFORM
                                      + 2 * COREHALFWORD (mCALL_LEVEL)),
                        2)))
              // IF ~TAG2(1) THEN (6168)
              if (1 & (xNOT (COREHALFWORD (mTAG2 + 2 * 1))))
                // CALL EMIT_ARRAY_DO(CALL_LEVEL); (6169)
                {
                  putBITp (16, mGENERATExEMIT_ARRAY_DOxLEVEL,
                           getBIT (16, mCALL_LEVEL));
                  GENERATExEMIT_ARRAY_DO (0);
                }
          // CALL FREE_ARRAYNESS(PTR); (6170)
          {
            putBITp (16, mGENERATExFREE_ARRAYNESSxOP,
                     getBIT (16, mGENERATExSTRUCTFIXxPTR));
            GENERATExFREE_ARRAYNESS (0);
          }
          // ARRAY_FLAG = TRUE; (6171)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mARRAY_FLAG, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
    es1:;
    } // End of DO block
  // FLAG = FALSE; (6172)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExSTRUCTFIXxFLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN PTR; (6173)
  {
    reentryGuard = 0;
    return COREHALFWORD (mGENERATExSTRUCTFIXxPTR);
  }
}
