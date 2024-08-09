/*
  File PRINTSUMMARYxALIGN_DUMP.c generated by XCOM-I, 2024-08-09 12:41:33.
*/

#include "runtimeC.h"

int32_t
PRINTSUMMARYxALIGN_DUMP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PRINTSUMMARYxALIGN_DUMP");
  // OUTPUT = ' '; (14207)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, " ");
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // M = SHR(SORT_COUNT, 1); (14208)
  {
    int32_t numberRHS
        = (int32_t)(SHR (COREHALFWORD (mPRINTSUMMARYxSORT_COUNT), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mPRINTSUMMARYxALIGN_DUMPxM, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE M > 0; (14209)
  while (1 & (xGT (COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxM), 0)))
    {
      // DO L = 1 TO SORT_COUNT - M; (14210)
      {
        int32_t from133, to133, by133;
        from133 = 1;
        to133 = xsubtract (COREHALFWORD (mPRINTSUMMARYxSORT_COUNT),
                           COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxM));
        by133 = 1;
        for (putBIT (16, mPRINTSUMMARYxALIGN_DUMPxL, fixedToBit (16, from133));
             bitToFixed (getBIT (16, mPRINTSUMMARYxALIGN_DUMPxL)) <= to133;
             putBIT (16, mPRINTSUMMARYxALIGN_DUMPxL,
                     fixedToBit (16, bitToFixed (getBIT (
                                         16, mPRINTSUMMARYxALIGN_DUMPxL))
                                         + by133)))
          {
            // I = L; (14211)
            {
              descriptor_t *bitRHS = getBIT (16, mPRINTSUMMARYxALIGN_DUMPxL);
              putBIT (16, mPRINTSUMMARYxALIGN_DUMPxI, bitRHS);
              bitRHS->inUse = 0;
            }
            // DO WHILE (SYT_ADDR(SORT1(I)) > SYT_ADDR(SORT1(I+M))); (14212)
            while (
                1
                & (xGT (
                    getFIXED (getFIXED (mSYM_TAB)
                              + 34
                                    * (COREHALFWORD (
                                        getFIXED (mPRINTSUMMARYxSORT_TAB)
                                        + 5
                                              * (COREHALFWORD (
                                                  mPRINTSUMMARYxALIGN_DUMPxI))
                                        + 0 + 2 * (0)))
                              + 4 + 4 * (0)),
                    getFIXED (
                        getFIXED (mSYM_TAB)
                        + 34
                              * (COREHALFWORD (
                                  getFIXED (mPRINTSUMMARYxSORT_TAB)
                                  + 5
                                        * (xadd (
                                            COREHALFWORD (
                                                mPRINTSUMMARYxALIGN_DUMPxI),
                                            COREHALFWORD (
                                                mPRINTSUMMARYxALIGN_DUMPxM)))
                                  + 0 + 2 * (0)))
                        + 4 + 4 * (0)))))
              {
                // L = SORT1(I); (14213)
                {
                  descriptor_t *bitRHS = getBIT (
                      16, getFIXED (mPRINTSUMMARYxSORT_TAB)
                              + 5 * (COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI))
                              + 0 + 2 * (0));
                  putBIT (16, mPRINTSUMMARYxALIGN_DUMPxL, bitRHS);
                  bitRHS->inUse = 0;
                }
                // SORT1(I) = SORT1(I + M); (14214)
                {
                  descriptor_t *bitRHS = getBIT (
                      16,
                      getFIXED (mPRINTSUMMARYxSORT_TAB)
                          + 5
                                * (xadd (
                                    COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI),
                                    COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxM)))
                          + 0 + 2 * (0));
                  putBIT (16,
                          getFIXED (mPRINTSUMMARYxSORT_TAB)
                              + 5 * (COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI))
                              + 0 + 2 * (0),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
                // SORT1(I + M) = L; (14215)
                {
                  descriptor_t *bitRHS
                      = getBIT (16, mPRINTSUMMARYxALIGN_DUMPxL);
                  putBIT (
                      16,
                      getFIXED (mPRINTSUMMARYxSORT_TAB)
                          + 5
                                * (xadd (
                                    COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI),
                                    COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxM)))
                          + 0 + 2 * (0),
                      bitRHS);
                  bitRHS->inUse = 0;
                }
                // L = HDR1(I); (14216)
                {
                  descriptor_t *bitRHS = getBIT (
                      4, getFIXED (mPRINTSUMMARYxSORT_TAB)
                             + 5 * (COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI))
                             + 2 + 1 * (0));
                  putBIT (16, mPRINTSUMMARYxALIGN_DUMPxL, bitRHS);
                  bitRHS->inUse = 0;
                }
                // HDR1(I) = HDR1(I + M); (14217)
                {
                  descriptor_t *bitRHS = getBIT (
                      4,
                      getFIXED (mPRINTSUMMARYxSORT_TAB)
                          + 5
                                * (xadd (
                                    COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI),
                                    COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxM)))
                          + 2 + 1 * (0));
                  putBIT (4,
                          getFIXED (mPRINTSUMMARYxSORT_TAB)
                              + 5 * (COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI))
                              + 2 + 1 * (0),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
                // HDR1(I + M) = L; (14218)
                {
                  descriptor_t *bitRHS
                      = getBIT (16, mPRINTSUMMARYxALIGN_DUMPxL);
                  putBIT (
                      4,
                      getFIXED (mPRINTSUMMARYxSORT_TAB)
                          + 5
                                * (xadd (
                                    COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI),
                                    COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxM)))
                          + 2 + 1 * (0),
                      bitRHS);
                  bitRHS->inUse = 0;
                }
                // I = I - M; (14219)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI),
                      COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxM)));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mPRINTSUMMARYxALIGN_DUMPxI, bitRHS);
                  bitRHS->inUse = 0;
                }
                // IF I < 1 THEN (14220)
                if (1 & (xLT (COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI), 1)))
                  // GO TO LM; (14221)
                  goto LM;
              } // End of DO WHILE block
          // LM: (14222)
          LM:;
          }
      } // End of DO for-loop block
      // M = SHR(M, 1); (14223)
      {
        int32_t numberRHS
            = (int32_t)(SHR (COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxM), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPRINTSUMMARYxALIGN_DUMPxM, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // TOTAL_GAP = 0; (14224)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mPRINTSUMMARYxALIGN_DUMPxTOTAL_GAP, numberRHS);
  }
  // S1 = PAD('NAME',BIGV)||'  LEN(DEC)  OFFSET(DEC)   B  DISP(HEX)  SCOPE';
  // (14225)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (
        (putCHARACTERp (mPADxSTRING, cToDescriptor (NULL, "NAME")),
         putFIXED (mPADxWIDTH, COREHALFWORD (mPRINTSUMMARYxBIGV)), PAD (0)),
        cToDescriptor (NULL, "  LEN(DEC)  OFFSET(DEC)   B  DISP(HEX)  SCOPE"));
    putCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '1'; (14226)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "1");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '0MEMORY MAP FOR DATA CSECT '||ESD_TABLE(DATABASE); (14227)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (
        cToDescriptor (NULL, "0MEMORY MAP FOR DATA CSECT "),
        (putBITp (16, mESD_TABLExPTR, getBIT (16, mDATABASE)), ESD_TABLE (0)));
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '0'||S1; (14228)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "0"),
                       getCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1));
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = ''; (14229)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '2'||S1; (14230)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "2"),
                       getCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1));
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // DO I = 1 TO SORT_COUNT; (14231)
  {
    int32_t from134, to134, by134;
    from134 = 1;
    to134 = bitToFixed (getBIT (16, mPRINTSUMMARYxSORT_COUNT));
    by134 = 1;
    for (putBIT (16, mPRINTSUMMARYxALIGN_DUMPxI, fixedToBit (16, from134));
         bitToFixed (getBIT (16, mPRINTSUMMARYxALIGN_DUMPxI)) <= to134;
         putBIT (16, mPRINTSUMMARYxALIGN_DUMPxI,
                 fixedToBit (
                     16, bitToFixed (getBIT (16, mPRINTSUMMARYxALIGN_DUMPxI))
                             + by134)))
      {
        // IF (SYT_FLAGS(SORT1(I)) & NAME_FLAG) ~= 0 THEN (14232)
        if (1
            & (xNEQ (xAND (getFIXED (
                               getFIXED (mSYM_TAB)
                               + 34
                                     * (COREHALFWORD (
                                         getFIXED (mPRINTSUMMARYxSORT_TAB)
                                         + 5
                                               * (COREHALFWORD (
                                                   mPRINTSUMMARYxALIGN_DUMPxI))
                                         + 0 + 2 * (0)))
                               + 8 + 4 * (0)),
                           getFIXED (mNAME_FLAG)),
                     0)))
          // DO; (14233)
          {
          rs2s1:;
            // IF (SYT_FLAGS(SORT1(I)) & REMOTE_FLAG) ~= 0 THEN (14234)
            if (1
                & (xNEQ (
                    xAND (getFIXED (
                              getFIXED (mSYM_TAB)
                              + 34
                                    * (COREHALFWORD (
                                        getFIXED (mPRINTSUMMARYxSORT_TAB)
                                        + 5
                                              * (COREHALFWORD (
                                                  mPRINTSUMMARYxALIGN_DUMPxI))
                                        + 0 + 2 * (0)))
                              + 8 + 4 * (0)),
                          getFIXED (mREMOTE_FLAG)),
                    0)))
              // LENGTHI = 2; (14235)
              {
                int32_t numberRHS = (int32_t)(2);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mPRINTSUMMARYxALIGN_DUMPxLENGTHI, bitRHS);
                bitRHS->inUse = 0;
              }
            // ELSE (14236)
            else
              // LENGTHI = 1; (14237)
              {
                int32_t numberRHS = (int32_t)(1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mPRINTSUMMARYxALIGN_DUMPxLENGTHI, bitRHS);
                bitRHS->inUse = 0;
              }
          es2s1:;
          } // End of DO block
        // ELSE (14238)
        else
          // LENGTHI = EXTENT(SORT1(I)); (14239)
          {
            int32_t numberRHS = (int32_t)(getFIXED (
                getFIXED (mSYM_TAB)
                + 34
                      * (COREHALFWORD (
                          getFIXED (mPRINTSUMMARYxSORT_TAB)
                          + 5 * (COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI)) + 0
                          + 2 * (0)))
                + 12 + 4 * (0)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mPRINTSUMMARYxALIGN_DUMPxLENGTHI, bitRHS);
            bitRHS->inUse = 0;
          }
        // IF HDR1(I)~=0 THEN (14240)
        if (1
            & (xNEQ (BYTE0 (getFIXED (mPRINTSUMMARYxSORT_TAB)
                            + 5 * (COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI))
                            + 2 + 1 * (0)),
                     0)))
          // DO; (14241)
          {
          rs2s2:;
            // S1 = PAD('**LOCAL BLOCK DATA**',BIGV)||X2; (14242)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  (putCHARACTERp (
                       mPADxSTRING,
                       cToDescriptor (NULL, "**LOCAL BLOCK DATA**")),
                   putFIXED (mPADxWIDTH, COREHALFWORD (mPRINTSUMMARYxBIGV)),
                   PAD (0)),
                  getCHARACTER (mX2));
              putCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1, stringRHS);
              stringRHS->inUse = 0;
            }
            // S1 = S1||FORMAT(HDR1(I),7)||X3; (14243)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  xsCAT (
                      getCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1),
                      (putFIXED (mFORMATxIVAL,
                                 BYTE0 (getFIXED (mPRINTSUMMARYxSORT_TAB)
                                        + 5
                                              * (COREHALFWORD (
                                                  mPRINTSUMMARYxALIGN_DUMPxI))
                                        + 2 + 1 * (0))),
                       putFIXED (mFORMATxN, 7), FORMAT (0))),
                  getCHARACTER (mX3));
              putCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1, stringRHS);
              stringRHS->inUse = 0;
            }
            // S1 = S1||FORMAT(SYT_ADDR(SORT1(I)),7)||PAD(X3,21); (14244)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  xsCAT (
                      getCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1),
                      (putFIXED (
                           mFORMATxIVAL,
                           getFIXED (
                               getFIXED (mSYM_TAB)
                               + 34
                                     * (COREHALFWORD (
                                         getFIXED (mPRINTSUMMARYxSORT_TAB)
                                         + 5
                                               * (COREHALFWORD (
                                                   mPRINTSUMMARYxALIGN_DUMPxI))
                                         + 0 + 2 * (0)))
                               + 4 + 4 * (0))),
                       putFIXED (mFORMATxN, 7), FORMAT (0))),
                  (putCHARACTERp (mPADxSTRING, getCHARACTER (mX3)),
                   putFIXED (mPADxWIDTH, 21), PAD (0)));
              putCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1, stringRHS);
              stringRHS->inUse = 0;
            }
            // S1 = S1||SYT_NAME(PROC_LEVEL(SYT_SCOPE(SORT1(I)))); (14245)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  getCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1),
                  getCHARACTER (
                      getFIXED (mSYM_TAB)
                      + 34
                            * (COREHALFWORD (
                                mPROC_LEVEL
                                + 2
                                      * BYTE0 (
                                          getFIXED (mSYM_TAB)
                                          + 34
                                                * (COREHALFWORD (
                                                    getFIXED (
                                                        mPRINTSUMMARYxSORT_TAB)
                                                    + 5
                                                          * (COREHALFWORD (
                                                              mPRINTSUMMARYxALIGN_DUMPxI))
                                                    + 0 + 2 * (0)))
                                          + 29 + 1 * (0))))
                      + 0 + 4 * (0)));
              putCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1, stringRHS);
              stringRHS->inUse = 0;
            }
          es2s2:;
          } // End of DO block
        // ELSE (14246)
        else
          // DO; (14247)
          {
          rs2s3:;
            // S1 = PAD(SYT_NAME(SORT1(I)),BIGV); (14248)
            {
              descriptor_t *stringRHS;
              stringRHS
                  = (putCHARACTERp (
                         mPADxSTRING,
                         getCHARACTER (
                             getFIXED (mSYM_TAB)
                             + 34
                                   * (COREHALFWORD (
                                       getFIXED (mPRINTSUMMARYxSORT_TAB)
                                       + 5
                                             * (COREHALFWORD (
                                                 mPRINTSUMMARYxALIGN_DUMPxI))
                                       + 0 + 2 * (0)))
                             + 0 + 4 * (0))),
                     putFIXED (mPADxWIDTH, COREHALFWORD (mPRINTSUMMARYxBIGV)),
                     PAD (0));
              putCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1, stringRHS);
              stringRHS->inUse = 0;
            }
            // S1 = S1||X2||FORMAT(LENGTHI,7)||X3; (14249)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  xsCAT (xsCAT (getCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1),
                                getCHARACTER (mX2)),
                         (putFIXED (
                              mFORMATxIVAL,
                              COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxLENGTHI)),
                          putFIXED (mFORMATxN, 7), FORMAT (0))),
                  getCHARACTER (mX3));
              putCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1, stringRHS);
              stringRHS->inUse = 0;
            }
            // S1 = S1||FORMAT(SYT_ADDR(SORT1(I)),7)||X2||X3; (14250)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  xsCAT (
                      xsCAT (
                          getCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1),
                          (putFIXED (
                               mFORMATxIVAL,
                               getFIXED (
                                   getFIXED (mSYM_TAB)
                                   + 34
                                         * (COREHALFWORD (
                                             getFIXED (mPRINTSUMMARYxSORT_TAB)
                                             + 5
                                                   * (COREHALFWORD (
                                                       mPRINTSUMMARYxALIGN_DUMPxI))
                                             + 0 + 2 * (0)))
                                   + 4 + 4 * (0))),
                           putFIXED (mFORMATxN, 7), FORMAT (0))),
                      getCHARACTER (mX2)),
                  getCHARACTER (mX3));
              putCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1, stringRHS);
              stringRHS->inUse = 0;
            }
            // S1 = S1||FORMAT(SYT_BASE(SORT1(I)),3)||X4; (14251)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  xsCAT (
                      getCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1),
                      (putFIXED (
                           mFORMATxIVAL,
                           COREHALFWORD (
                               getFIXED (mP2SYMS)
                               + 12
                                     * (COREHALFWORD (
                                         getFIXED (mPRINTSUMMARYxSORT_TAB)
                                         + 5
                                               * (COREHALFWORD (
                                                   mPRINTSUMMARYxALIGN_DUMPxI))
                                         + 0 + 2 * (0)))
                               + 4 + 2 * (0))),
                       putFIXED (mFORMATxN, 3), FORMAT (0))),
                  getCHARACTER (mX4));
              putCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1, stringRHS);
              stringRHS->inUse = 0;
            }
            // S1 = S1||HEX(SYT_DISP(SORT1(I)),4)||X3||X2; (14252)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  xsCAT (
                      xsCAT (
                          getCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1),
                          (putFIXED (
                               mHEXxHVAL,
                               COREHALFWORD (
                                   getFIXED (mP2SYMS)
                                   + 12
                                         * (COREHALFWORD (
                                             getFIXED (mPRINTSUMMARYxSORT_TAB)
                                             + 5
                                                   * (COREHALFWORD (
                                                       mPRINTSUMMARYxALIGN_DUMPxI))
                                             + 0 + 2 * (0)))
                                   + 6 + 2 * (0))),
                           putFIXED (mHEXxN, 4), HEX (0))),
                      getCHARACTER (mX3)),
                  getCHARACTER (mX2));
              putCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1, stringRHS);
              stringRHS->inUse = 0;
            }
            // S1 = S1||SYT_NAME(PROC_LEVEL(SYT_SCOPE(SORT1(I)))); (14253)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  getCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1),
                  getCHARACTER (
                      getFIXED (mSYM_TAB)
                      + 34
                            * (COREHALFWORD (
                                mPROC_LEVEL
                                + 2
                                      * BYTE0 (
                                          getFIXED (mSYM_TAB)
                                          + 34
                                                * (COREHALFWORD (
                                                    getFIXED (
                                                        mPRINTSUMMARYxSORT_TAB)
                                                    + 5
                                                          * (COREHALFWORD (
                                                              mPRINTSUMMARYxALIGN_DUMPxI))
                                                    + 0 + 2 * (0)))
                                          + 29 + 1 * (0))))
                      + 0 + 4 * (0)));
              putCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1, stringRHS);
              stringRHS->inUse = 0;
            }
          es2s3:;
          } // End of DO block
        // OUTPUT = S1; (14254)
        {
          descriptor_t *stringRHS;
          stringRHS = getCHARACTER (mPRINTSUMMARYxALIGN_DUMPxS1);
          OUTPUT (0, stringRHS);
          stringRHS->inUse = 0;
        }
        // IF I<SORT_COUNT THEN (14255)
        if (1
            & (xLT (COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI),
                    COREHALFWORD (mPRINTSUMMARYxSORT_COUNT))))
          // DO; (14256)
          {
          rs2s4:;
            // BEGIN_GAP=SYT_ADDR(SORT1(I))+LENGTHI+HDR1(I); (14257)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  xadd (getFIXED (
                            getFIXED (mSYM_TAB)
                            + 34
                                  * (COREHALFWORD (
                                      getFIXED (mPRINTSUMMARYxSORT_TAB)
                                      + 5
                                            * (COREHALFWORD (
                                                mPRINTSUMMARYxALIGN_DUMPxI))
                                      + 0 + 2 * (0)))
                            + 4 + 4 * (0)),
                        COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxLENGTHI)),
                  BYTE0 (getFIXED (mPRINTSUMMARYxSORT_TAB)
                         + 5 * (COREHALFWORD (mPRINTSUMMARYxALIGN_DUMPxI)) + 2
                         + 1 * (0))));
              putFIXED (mPRINTSUMMARYxALIGN_DUMPxBEGIN_GAP, numberRHS);
            }
            // GAP = SYT_ADDR(SORT1(I+1))-BEGIN_GAP; (14258)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  getFIXED (
                      getFIXED (mSYM_TAB)
                      + 34
                            * (COREHALFWORD (
                                getFIXED (mPRINTSUMMARYxSORT_TAB)
                                + 5
                                      * (xadd (COREHALFWORD (
                                                   mPRINTSUMMARYxALIGN_DUMPxI),
                                               1))
                                + 0 + 2 * (0)))
                      + 4 + 4 * (0)),
                  getFIXED (mPRINTSUMMARYxALIGN_DUMPxBEGIN_GAP)));
              putFIXED (mPRINTSUMMARYxALIGN_DUMPxGAP, numberRHS);
            }
            // IF GAP > 0 THEN (14259)
            if (1 & (xGT (getFIXED (mPRINTSUMMARYxALIGN_DUMPxGAP), 0)))
              // DO; (14260)
              {
              rs2s4s1:;
                // TOTAL_GAP = TOTAL_GAP + GAP; (14261)
                {
                  int32_t numberRHS = (int32_t)(xadd (
                      getFIXED (mPRINTSUMMARYxALIGN_DUMPxTOTAL_GAP),
                      getFIXED (mPRINTSUMMARYxALIGN_DUMPxGAP)));
                  putFIXED (mPRINTSUMMARYxALIGN_DUMPxTOTAL_GAP, numberRHS);
                }
                // OUTPUT = PAD('**ALIGNMENT
                // GAP**',BIGV)||X2||FORMAT(GAP,7)||X3 ||FORMAT(BEGIN_GAP,7);
                // (14262)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (
                      xsCAT (
                          xsCAT (xsCAT ((putCHARACTERp (
                                             mPADxSTRING,
                                             cToDescriptor (
                                                 NULL, "**ALIGNMENT GAP**")),
                                         putFIXED (mPADxWIDTH,
                                                   COREHALFWORD (
                                                       mPRINTSUMMARYxBIGV)),
                                         PAD (0)),
                                        getCHARACTER (mX2)),
                                 (putFIXED (
                                      mFORMATxIVAL,
                                      getFIXED (mPRINTSUMMARYxALIGN_DUMPxGAP)),
                                  putFIXED (mFORMATxN, 7), FORMAT (0))),
                          getCHARACTER (mX3)),
                      (putFIXED (
                           mFORMATxIVAL,
                           getFIXED (mPRINTSUMMARYxALIGN_DUMPxBEGIN_GAP)),
                       putFIXED (mFORMATxN, 7), FORMAT (0)));
                  OUTPUT (0, stringRHS);
                  stringRHS->inUse = 0;
                }
              es2s4s1:;
              } // End of DO block
          es2s4:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // OUTPUT = ''; (14263)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "");
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT ='TOTAL SIZE OF ALIGNMENT GAPS FOR CSECT: '||TOTAL_GAP||' HW';
  // (14264)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (
        xsCAT (
            cToDescriptor (NULL, "TOTAL SIZE OF ALIGNMENT GAPS FOR CSECT: "),
            fixedToCharacter (getFIXED (mPRINTSUMMARYxALIGN_DUMPxTOTAL_GAP))),
        cToDescriptor (NULL, " HW"));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = ''; (14265)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "");
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '2 '; (14266)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "2 ");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // RECORD_FREE(SORT_TAB); (14267)
  {
    putFIXED (m_RECORD_FREExDOPE,
              ADDR ("PRINTSUMMARYxSORT_TAB", 0x80000000, NULL, 0));
    _RECORD_FREE (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
