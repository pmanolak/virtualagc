/*
  File OBJECT_CONDENSERxSHIFT_CONDENSE.c generated by XCOM-I, 2024-08-09
  12:41:33.
*/

#include "runtimeC.h"

int32_t
OBJECT_CONDENSERxSHIFT_CONDENSE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "OBJECT_CONDENSERxSHIFT_CONDENSE");
  // CALL NEXT_REC(1); (14580)
  {
    putBITp (16, mNEXT_RECxI, fixedToBit (32, (int32_t)(1)));
    NEXT_REC (0);
  }
  // IF LHS(1) ~= SHCOUNT THEN (14581)
  if (1 & (xNEQ (COREHALFWORD (mLHS + 2 * 1), BYTE0 (mSHCOUNT))))
    // DO; (14582)
    {
    rs1:;
      // CALL UPLOC(2); (14583)
      {
        putBITp (16, mOBJECT_CONDENSERxUPLOCxN, fixedToBit (32, (int32_t)(2)));
        OBJECT_CONDENSERxUPLOC (0);
      }
      // IF LHS(1) = CSYM THEN (14584)
      if (1 & (xEQ (COREHALFWORD (mLHS + 2 * 1), BYTE0 (mCSYM))))
        // CALL SKIP(1); (14585)
        {
          putBITp (16, mSKIPxN, fixedToBit (32, (int32_t)(1)));
          SKIP (0);
        }
    es1:;
    } // End of DO block
  // ELSE (14586)
  else
    // DO; (14587)
    {
    rs2:;
      // CALL GET_INST_R_X; (14588)
      GET_INST_R_X (0);
      // IF (INST ~= SRL & INST ~= SLL & INST ~= SRA) THEN (14589)
      if (1
          & (xAND (xAND (xNEQ (getFIXED (mINST), BYTE0 (mSRL)),
                         xNEQ (getFIXED (mINST), BYTE0 (mSLL))),
                   xNEQ (getFIXED (mINST), BYTE0 (mSRA)))))
        // CALL UPLOC(2); (14590)
        {
          putBITp (16, mOBJECT_CONDENSERxUPLOCxN,
                   fixedToBit (32, (int32_t)(2)));
          OBJECT_CONDENSERxUPLOC (0);
        }
      // ELSE (14591)
      else
        // DO; (14592)
        {
        rs2s1:;
          // NEXT_LINE = CODE_LINE; (14593)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mCODE_LINE));
            putFIXED (mOBJECT_CONDENSERxSHIFT_CONDENSExNEXT_LINE, numberRHS);
          }
          // CALL NEXT_REC(2); (14594)
          {
            putBITp (16, mNEXT_RECxI, fixedToBit (32, (int32_t)(2)));
            NEXT_REC (0);
          }
          // INST2 = SHR(RHS(2),8) &  255; (14595)
          {
            int32_t numberRHS
                = (int32_t)(xAND (SHR (COREHALFWORD (mRHS + 2 * 2), 8), 255));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mOBJECT_CONDENSERxSHIFT_CONDENSExINST2, bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL NEXT_REC(3); (14596)
          {
            putBITp (16, mNEXT_RECxI, fixedToBit (32, (int32_t)(3)));
            NEXT_REC (0);
          }
          // IF LHS(2) ~= SRSTYPE | LHS(3) ~= SHCOUNT THEN (14597)
          if (1
              & (xOR (xNEQ (COREHALFWORD (mLHS + 2 * 2), BYTE0 (mSRSTYPE)),
                      xNEQ (COREHALFWORD (mLHS + 2 * 3), BYTE0 (mSHCOUNT)))))
            // DO; (14598)
            {
            rs2s1s1:;
            // NORMAL_SRS: (14599)
            NORMAL_SRS:
              // CALL UPLOC(2); (14600)
              {
                putBITp (16, mOBJECT_CONDENSERxUPLOCxN,
                         fixedToBit (32, (int32_t)(2)));
                OBJECT_CONDENSERxUPLOC (0);
              }
              // CODE_LINE = NEXT_LINE; (14601)
              {
                int32_t numberRHS = (int32_t)(getFIXED (
                    mOBJECT_CONDENSERxSHIFT_CONDENSExNEXT_LINE));
                putFIXED (mCODE_LINE, numberRHS);
              }
              // RETURN; (14602)
              {
                reentryGuard = 0;
                return 0;
              }
            es2s1s1:;
            } // End of DO block
          // ELSE (14603)
          else
            // IF (RHS& 255) ~= (RHS(2)& 255) THEN (14604)
            if (1
                & (xNEQ (xAND (COREHALFWORD (mRHS), 255),
                         xAND (COREHALFWORD (mRHS + 2 * 2), 255))))
              // GO TO NORMAL_SRS; (14605)
              goto NORMAL_SRS;
            // ELSE (14606)
            else
              // IF INST2 ~= SLL & INST2 ~= SRL THEN (14607)
              if (1
                  & (xAND (xNEQ (COREHALFWORD (
                                     mOBJECT_CONDENSERxSHIFT_CONDENSExINST2),
                                 BYTE0 (mSLL)),
                           xNEQ (COREHALFWORD (
                                     mOBJECT_CONDENSERxSHIFT_CONDENSExINST2),
                                 BYTE0 (mSRL)))))
                // GO TO NORMAL_SRS; (14608)
                goto NORMAL_SRS;
              // ELSE (14609)
              else
                // IF INST2 = INST THEN (14610)
                if (1
                    & (xEQ (
                        COREHALFWORD (mOBJECT_CONDENSERxSHIFT_CONDENSExINST2),
                        getFIXED (mINST))))
                  // RHS(1) = RHS(1) + RHS(3); (14611)
                  {
                    int32_t numberRHS
                        = (int32_t)(xadd (COREHALFWORD (mRHS + 2 * 1),
                                          COREHALFWORD (mRHS + 2 * 3)));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mRHS + 2 * (1), bitRHS);
                    bitRHS->inUse = 0;
                  }
                // ELSE (14612)
                else
                  // IF INST = SRA & INST2 ~= SLL THEN (14613)
                  if (1
                      & (xAND (
                          xEQ (getFIXED (mINST), BYTE0 (mSRA)),
                          xNEQ (COREHALFWORD (
                                    mOBJECT_CONDENSERxSHIFT_CONDENSExINST2),
                                BYTE0 (mSLL)))))
                    // GO TO NORMAL_SRS; (14614)
                    goto NORMAL_SRS;
                  // ELSE (14615)
                  else
                    // IF INST = SLL & INST2 = SRL THEN (14616)
                    if (1
                        & (xAND (
                            xEQ (getFIXED (mINST), BYTE0 (mSLL)),
                            xEQ (COREHALFWORD (
                                     mOBJECT_CONDENSERxSHIFT_CONDENSExINST2),
                                 BYTE0 (mSRL)))))
                      // GO TO NORMAL_SRS; (14617)
                      goto NORMAL_SRS;
                    // ELSE (14618)
                    else
                      // IF RHS(1) > RHS(3) THEN (14619)
                      if (1
                          & (xGT (COREHALFWORD (mRHS + 2 * 1),
                                  COREHALFWORD (mRHS + 2 * 3))))
                        // RHS(1) = RHS(1) - RHS(3); (14620)
                        {
                          int32_t numberRHS = (int32_t)(xsubtract (
                              COREHALFWORD (mRHS + 2 * 1),
                              COREHALFWORD (mRHS + 2 * 3)));
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (16, mRHS + 2 * (1), bitRHS);
                          bitRHS->inUse = 0;
                        }
                      // ELSE (14621)
                      else
                        // DO; (14622)
                        {
                        rs2s1s2:;
                          // RHS(1) = RHS(3) - RHS(1); (14623)
                          {
                            int32_t numberRHS = (int32_t)(xsubtract (
                                COREHALFWORD (mRHS + 2 * 3),
                                COREHALFWORD (mRHS + 2 * 1)));
                            descriptor_t *bitRHS;
                            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                            putBIT (16, mRHS + 2 * (1), bitRHS);
                            bitRHS->inUse = 0;
                          }
                          // RHS = RHS(2); (14624)
                          {
                            descriptor_t *bitRHS = getBIT (16, mRHS + 2 * 2);
                            putBIT (16, mRHS, bitRHS);
                            bitRHS->inUse = 0;
                          }
                          // INST2 = INST; (14625)
                          {
                            int32_t numberRHS = (int32_t)(getFIXED (mINST));
                            descriptor_t *bitRHS;
                            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                            putBIT (16, mOBJECT_CONDENSERxSHIFT_CONDENSExINST2,
                                    bitRHS);
                            bitRHS->inUse = 0;
                          }
                        es2s1s2:;
                        } // End of DO block
          // INST = SHR(RHS,8) &  255; (14626)
          {
            int32_t numberRHS
                = (int32_t)(xAND (SHR (COREHALFWORD (mRHS), 8), 255));
            putFIXED (mINST, numberRHS);
          }
          // CODE(GET_CODE(CURRENT_LINE)) = SHL(NOP, 16); (14627)
          {
            int32_t numberRHS = (int32_t)(SHL (BYTE0 (mNOP), 16));
            putFIXED (
                mCODE
                    + 4
                          * ((putFIXED (
                                  mGET_CODExCTR,
                                  getFIXED (mOBJECT_CONDENSERxCURRENT_LINE)),
                              GET_CODE (0))),
                numberRHS);
          }
          // IF RHS(1) = 0 THEN (14628)
          if (1 & (xEQ (COREHALFWORD (mRHS + 2 * 1), 0)))
            // DO; (14629)
            {
            rs2s1s3:;
              // CODE(GET_CODE(NEXT_LINE)) = SHL(NOP, 16); (14630)
              {
                int32_t numberRHS = (int32_t)(SHL (BYTE0 (mNOP), 16));
                putFIXED (
                    mCODE
                        + 4
                              * ((putFIXED (
                                      mGET_CODExCTR,
                                      getFIXED (
                                          mOBJECT_CONDENSERxSHIFT_CONDENSExNEXT_LINE)),
                                  GET_CODE (0))),
                    numberRHS);
              }
              // CALL LABEL_UPDATE(2); (14631)
              {
                putBITp (16, mOBJECT_CONDENSERxLABEL_UPDATExLEN,
                         fixedToBit (32, (int32_t)(2)));
                OBJECT_CONDENSERxLABEL_UPDATE (0);
              }
            es2s1s3:;
            } // End of DO block
          // ELSE (14632)
          else
            // DO; (14633)
            {
            rs2s1s4:;
              // CALL UPLOC(2); (14634)
              {
                putBITp (16, mOBJECT_CONDENSERxUPLOCxN,
                         fixedToBit (32, (int32_t)(2)));
                OBJECT_CONDENSERxUPLOC (0);
              }
              // CODE(GET_CODE(NEXT_LINE)) = SHL(LHS,16) | (RHS& 65535);
              // (14635)
              {
                int32_t numberRHS
                    = (int32_t)(xOR (SHL (COREHALFWORD (mLHS), 16),
                                     xAND (COREHALFWORD (mRHS), 65535)));
                putFIXED (
                    mCODE
                        + 4
                              * ((putFIXED (
                                      mGET_CODExCTR,
                                      getFIXED (
                                          mOBJECT_CONDENSERxSHIFT_CONDENSExNEXT_LINE)),
                                  GET_CODE (0))),
                    numberRHS);
              }
              // CODE(GET_CODE(NEXT_LINE+1)) = SHL(LHS(1),16)| (RHS(1)& 65535);
              // (14636)
              {
                int32_t numberRHS = (int32_t)(xOR (
                    SHL (COREHALFWORD (mLHS + 2 * 1), 16),
                    xAND (COREHALFWORD (mRHS + 2 * 1), 65535)));
                putFIXED (
                    mCODE
                        + 4
                              * ((putFIXED (
                                      mGET_CODExCTR,
                                      xadd (
                                          getFIXED (
                                              mOBJECT_CONDENSERxSHIFT_CONDENSExNEXT_LINE),
                                          1)),
                                  GET_CODE (0))),
                    numberRHS);
              }
              // CALL LABEL_UPDATE(1); (14637)
              {
                putBITp (16, mOBJECT_CONDENSERxLABEL_UPDATExLEN,
                         fixedToBit (32, (int32_t)(1)));
                OBJECT_CONDENSERxLABEL_UPDATE (0);
              }
            es2s1s4:;
            } // End of DO block
        es2s1:;
        } // End of DO block
    es2:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
