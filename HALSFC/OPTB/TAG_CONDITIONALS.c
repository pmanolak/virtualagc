/*
  File TAG_CONDITIONALS.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
TAG_CONDITIONALS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "TAG_CONDITIONALS");
  // NODES,A_INX = 0; (3551)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mTAG_CONDITIONALSxNODES, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mA_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // D_N_INX = 1; (3552)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mD_N_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // DIFF_NODE(1) = PTR; (3553)
  {
    descriptor_t *bitRHS = getBIT (16, mTAG_CONDITIONALSxPTR);
    putBIT (16, mDIFF_NODE + 2 * (1), bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE D_N_INX > 0; (3554)
  while (1 & (xGT (COREHALFWORD (mD_N_INX), 0)))
    {
      // DIFF_NODE = DIFF_NODE(D_N_INX); (3555)
      {
        descriptor_t *bitRHS
            = getBIT (16, mDIFF_NODE + 2 * COREHALFWORD (mD_N_INX));
        putBIT (16, mDIFF_NODE, bitRHS);
        bitRHS->inUse = 0;
      }
      // D_N_INX = D_N_INX - 1; (3556)
      {
        int32_t numberRHS = (int32_t)(xsubtract (COREHALFWORD (mD_N_INX), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mD_N_INX, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF NOT_TYPE(DIFF_NODE) THEN (3557)
      if (1
          & (bitToFixed ((putBITp (16, mNOT_TYPExPTR, getBIT (16, mDIFF_NODE)),
                          NOT_TYPE (0)))))
        // DO; (3558)
        {
        rs1s1:;
          // NODES = NODES + 1; (3559)
          {
            int32_t numberRHS
                = (int32_t)(xadd (COREHALFWORD (mTAG_CONDITIONALSxNODES), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mTAG_CONDITIONALSxNODES, bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL BUMP_D_N(SHR(OPR(DIFF_NODE + 1),16)); (3560)
          {
            putBITp (
                16, mBUMP_D_NxPTR,
                fixedToBit (
                    32,
                    (int32_t)(SHR (
                        getFIXED (mOPR
                                  + 4 * xadd (COREHALFWORD (mDIFF_NODE), 1)),
                        16))));
            BUMP_D_N (0);
          }
        es1s1:;
        } // End of DO block
      // ELSE (3561)
      else
        // IF ANDOR_TYPE(DIFF_NODE) THEN (3562)
        if (1
            & (bitToFixed (
                (putBITp (16, mANDOR_TYPExPTR, getBIT (16, mDIFF_NODE)),
                 ANDOR_TYPE (0)))))
          // DO; (3563)
          {
          rs1s2:;
            // CALL BUMP_ADD(DIFF_NODE); (3564)
            {
              putBITp (16, mBUMP_ADDxPTR, getBIT (16, mDIFF_NODE));
              BUMP_ADD (0);
            }
            // FLAGS,LAST_TAG = 0; (3565)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mTAG_CONDITIONALSxFLAGS, bitRHS);
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mTAG_CONDITIONALSxLAST_TAG, bitRHS);
              bitRHS->inUse = 0;
            }
            // OPTYPE = CLASSIFY(DIFF_NODE); (3566)
            {
              descriptor_t *bitRHS
                  = (putBITp (16, mCLASSIFYxPTR, getBIT (16, mDIFF_NODE)),
                     CLASSIFY (0));
              putBIT (16, mTAG_CONDITIONALSxOPTYPE, bitRHS);
              bitRHS->inUse = 0;
            }
            // NODES = NODES + 1; (3567)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  COREHALFWORD (mTAG_CONDITIONALSxNODES), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mTAG_CONDITIONALSxNODES, bitRHS);
              bitRHS->inUse = 0;
            }
            // DO WHILE A_INX > 0; (3568)
            while (1 & (xGT (COREHALFWORD (mA_INX), 0)))
              {
                // ADD = ADD(A_INX); (3569)
                {
                  descriptor_t *bitRHS
                      = getBIT (16, mADD + 2 * COREHALFWORD (mA_INX));
                  putBIT (16, mADD, bitRHS);
                  bitRHS->inUse = 0;
                }
                // A_INX = A_INX -1; (3570)
                {
                  int32_t numberRHS
                      = (int32_t)(xsubtract (COREHALFWORD (mA_INX), 1));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mA_INX, bitRHS);
                  bitRHS->inUse = 0;
                }
                // IF ANDOR_TYPE(ADD) THEN (3571)
                if (1
                    & (bitToFixed (
                        (putBITp (16, mANDOR_TYPExPTR, getBIT (16, mADD)),
                         ANDOR_TYPE (0)))))
                  // DO; (3572)
                  {
                  rs1s2s1s1:;
                    // IF OPTYPE ~= CLASSIFY(ADD) THEN (3573)
                    if (1
                        & (xNEQ (COREHALFWORD (mTAG_CONDITIONALSxOPTYPE),
                                 bitToFixed ((putBITp (16, mCLASSIFYxPTR,
                                                       getBIT (16, mADD)),
                                              CLASSIFY (0))))))
                      // DO; (3574)
                      {
                      rs1s2s1s1s1:;
                        // CALL BUMP_D_N(ADD); (3575)
                        {
                          putBITp (16, mBUMP_D_NxPTR, getBIT (16, mADD));
                          BUMP_D_N (0);
                        }
                        // IF ADD > LAST_TAG THEN (3576)
                        if (1
                            & (xGT (
                                COREHALFWORD (mADD),
                                COREHALFWORD (mTAG_CONDITIONALSxLAST_TAG))))
                          // LAST_TAG = ADD; (3577)
                          {
                            descriptor_t *bitRHS = getBIT (16, mADD);
                            putBIT (16, mTAG_CONDITIONALSxLAST_TAG, bitRHS);
                            bitRHS->inUse = 0;
                          }
                      es1s2s1s1s1:;
                      } // End of DO block
                    // ELSE (3578)
                    else
                      // DO FOR I = ADD + 1 TO ADD + NO_OPERANDS(ADD); (3579)
                      {
                        int32_t from88, to88, by88;
                        from88 = xadd (COREHALFWORD (mADD), 1);
                        to88
                            = xadd (COREHALFWORD (mADD),
                                    bitToFixed ((putBITp (16, mNO_OPERANDSxPTR,
                                                          getBIT (16, mADD)),
                                                 NO_OPERANDS (0))));
                        by88 = 1;
                        for (putBIT (16, mTAG_CONDITIONALSxI,
                                     fixedToBit (16, from88));
                             bitToFixed (getBIT (16, mTAG_CONDITIONALSxI))
                             <= to88;
                             putBIT (
                                 16, mTAG_CONDITIONALSxI,
                                 fixedToBit (16, bitToFixed (getBIT (
                                                     16, mTAG_CONDITIONALSxI))
                                                     + by88)))
                          {
                            // PTR = SHR(OPR(I),16); (3580)
                            {
                              int32_t numberRHS = (int32_t)(SHR (
                                  getFIXED (mOPR
                                            + 4
                                                  * COREHALFWORD (
                                                      mTAG_CONDITIONALSxI)),
                                  16));
                              descriptor_t *bitRHS;
                              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                              putBIT (16, mTAG_CONDITIONALSxPTR, bitRHS);
                              bitRHS->inUse = 0;
                            }
                            // IF COMPARE_TYPE(PTR) THEN (3581)
                            if (1
                                & (bitToFixed (
                                    (putBITp (
                                         16, mCOMPARE_TYPExPTR,
                                         getBIT (16, mTAG_CONDITIONALSxPTR)),
                                     COMPARE_TYPE (0)))))
                              // DO; (3582)
                              {
                              rs1s2s1s1s2s1:;
                                // CALL SET_TAG(PTR); (3583)
                                {
                                  putBITp (16, mTAG_CONDITIONALSxSET_TAGxPTR,
                                           getBIT (16, mTAG_CONDITIONALSxPTR));
                                  TAG_CONDITIONALSxSET_TAG (0);
                                }
                              es1s2s1s1s2s1:;
                              } // End of DO block
                            // ELSE (3584)
                            else
                              // CALL BUMP_ADD(PTR); (3585)
                              {
                                putBITp (16, mBUMP_ADDxPTR,
                                         getBIT (16, mTAG_CONDITIONALSxPTR));
                                BUMP_ADD (0);
                              }
                          }
                      } // End of DO for-loop block
                  es1s2s1s1:;
                  } // End of DO block
                // ELSE (3586)
                else
                  // IF NOT_TYPE(ADD) THEN (3587)
                  if (1
                      & (bitToFixed (
                          (putBITp (16, mNOT_TYPExPTR, getBIT (16, mADD)),
                           NOT_TYPE (0)))))
                    // CALL BUMP_D_N(SHR(OPR(ADD + 1),16)); (3588)
                    {
                      putBITp (
                          16, mBUMP_D_NxPTR,
                          fixedToBit (
                              32, (int32_t)(SHR (
                                      getFIXED (
                                          mOPR
                                          + 4 * xadd (COREHALFWORD (mADD), 1)),
                                      16))));
                      BUMP_D_N (0);
                    }
                  // ELSE (3589)
                  else
                    // IF COMPARE_TYPE(ADD) THEN (3590)
                    if (1
                        & (bitToFixed ((
                            putBITp (16, mCOMPARE_TYPExPTR, getBIT (16, mADD)),
                            COMPARE_TYPE (0)))))
                      // CALL SET_TAG(ADD); (3591)
                      {
                        putBITp (16, mTAG_CONDITIONALSxSET_TAGxPTR,
                                 getBIT (16, mADD));
                        TAG_CONDITIONALSxSET_TAG (0);
                      }
              } // End of DO WHILE block
            // IF FLAGS ~= 0 THEN (3592)
            if (1 & (xNEQ (COREHALFWORD (mTAG_CONDITIONALSxFLAGS), 0)))
              // IF (NODES ~= 1 | OPTYPE ~= CAND) THEN (3593)
              if (1
                  & (xOR (xNEQ (COREHALFWORD (mTAG_CONDITIONALSxNODES), 1),
                          xNEQ (COREHALFWORD (mTAG_CONDITIONALSxOPTYPE),
                                COREHALFWORD (mCAND)))))
                // IF COMPARE_TYPE(LAST_TAG) THEN (3594)
                if (1
                    & (bitToFixed (
                        (putBITp (16, mCOMPARE_TYPExPTR,
                                  getBIT (16, mTAG_CONDITIONALSxLAST_TAG)),
                         COMPARE_TYPE (0)))))
                  // DO; (3595)
                  {
                  rs1s2s2:;
                    // OPR(LAST_TAG) = OPR(LAST_TAG) - REGISTER_TAG; (3596)
                    {
                      int32_t numberRHS = (int32_t)(xsubtract (
                          getFIXED (
                              mOPR
                              + 4 * COREHALFWORD (mTAG_CONDITIONALSxLAST_TAG)),
                          getFIXED (mREGISTER_TAG)));
                      putFIXED (mOPR
                                    + 4
                                          * (COREHALFWORD (
                                              mTAG_CONDITIONALSxLAST_TAG)),
                                numberRHS);
                    }
                    // IF WATCH THEN (3597)
                    if (1 & (bitToFixed (getBIT (8, mWATCH))))
                      // OUTPUT = 'CONDITIONAL DETAG:  '||LAST_TAG; (3598)
                      {
                        descriptor_t *stringRHS;
                        stringRHS = xsCAT (
                            cToDescriptor (NULL, "CONDITIONAL DETAG:  "),
                            bitToCharacter (
                                getBIT (16, mTAG_CONDITIONALSxLAST_TAG)));
                        OUTPUT (0, stringRHS);
                        stringRHS->inUse = 0;
                      }
                  es1s2s2:;
                  } // End of DO block
          es1s2:;
          } // End of DO block
    }       // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
