/*
  File OBJECT_GENERATORxEMIT_SYM_CARDS.c generated by XCOM-I, 2024-08-09
  12:39:31.
*/

#include "runtimeC.h"

int32_t
OBJECT_GENERATORxEMIT_SYM_CARDS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "OBJECT_GENERATORxEMIT_SYM_CARDS");
  // CALL EMIT_SYM_CARD; (16005)
  OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM_CARD (0);
  // DO I = 1 TO ESD_MAX; (16006)
  {
    int32_t from155, to155, by155;
    from155 = 1;
    to155 = bitToFixed (getBIT (16, mESD_MAX));
    by155 = 1;
    for (putBIT (16, mOBJECT_GENERATORxEMIT_SYM_CARDSxI,
                 fixedToBit (16, from155));
         bitToFixed (getBIT (16, mOBJECT_GENERATORxEMIT_SYM_CARDSxI)) <= to155;
         putBIT (16, mOBJECT_GENERATORxEMIT_SYM_CARDSxI,
                 fixedToBit (16, bitToFixed (getBIT (
                                     16, mOBJECT_GENERATORxEMIT_SYM_CARDSxI))
                                     + by155)))
      {
        // IF ESD_TYPE(I) < 1 | ESD_TYPE(I) > 2 THEN (16007)
        if (1
            & (xOR (xLT (BYTE0 (mESD_TYPE
                                + 1
                                      * COREHALFWORD (
                                          mOBJECT_GENERATORxEMIT_SYM_CARDSxI)),
                         1),
                    xGT (BYTE0 (mESD_TYPE
                                + 1
                                      * COREHALFWORD (
                                          mOBJECT_GENERATORxEMIT_SYM_CARDSxI)),
                         2))))
          // DO; (16008)
          {
          rs1s1:;
            // CALL EMIT_SYM(ESD_TABLE(I), 0,  16); (16009)
            {
              putCHARACTERp (
                  mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxNAME,
                  (putBITp (16, mESD_TABLExPTR,
                            getBIT (16, mOBJECT_GENERATORxEMIT_SYM_CARDSxI)),
                   ESD_TABLE (0)));
              putFIXED (mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxVAL, 0);
              putBITp (8, mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxFLAG,
                       fixedToBit (32, (int32_t)(16)));
              OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM (0);
            }
            // IF I = 1 THEN (16010)
            if (1
                & (xEQ (COREHALFWORD (mOBJECT_GENERATORxEMIT_SYM_CARDSxI), 1)))
              // IF ESD_TABLE(I) = 'START' THEN (16011)
              if (1
                  & (xsEQ (
                      (putBITp (
                           16, mESD_TABLExPTR,
                           getBIT (16, mOBJECT_GENERATORxEMIT_SYM_CARDSxI)),
                       ESD_TABLE (0)),
                      cToDescriptor (NULL, "START"))))
                // RETURN; (16012)
                {
                  reentryGuard = 0;
                  return 0;
                }
            // IF I <= SYMBREAK THEN (16013)
            if (1
                & (xLE (COREHALFWORD (mOBJECT_GENERATORxEMIT_SYM_CARDSxI),
                        COREHALFWORD (mSYMBREAK))))
              // DO; (16014)
              {
              rs1s1s1:;
                // CALL EMIT_SYM('STACK', 0,  32); (16015)
                {
                  putCHARACTERp (
                      mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxNAME,
                      cToDescriptor (NULL, "STACK"));
                  putFIXED (mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxVAL, 0);
                  putBITp (8, mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxFLAG,
                           fixedToBit (32, (int32_t)(32)));
                  OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM (0);
                }
                // CALL EMIT_SYM('STACKEND', MAXTEMP(I),  128); (16016)
                {
                  putCHARACTERp (
                      mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxNAME,
                      cToDescriptor (NULL, "STACKEND"));
                  putFIXED (
                      mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxVAL,
                      getFIXED (
                          mMAXTEMP
                          + 4
                                * COREHALFWORD (
                                    mOBJECT_GENERATORxEMIT_SYM_CARDSxI)));
                  putBITp (8, mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxFLAG,
                           fixedToBit (32, (int32_t)(128)));
                  OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM (0);
                }
                // CALL EMIT_SYM_DATA( 20, 1); (16017)
                {
                  putBITp (16,
                           mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM_DATAxTYP,
                           fixedToBit (32, (int32_t)(20)));
                  putBITp (16,
                           mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM_DATAxSIZ,
                           fixedToBit (32, (int32_t)(1)));
                  OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM_DATA (0);
                }
              es1s1s1:;
              } // End of DO block
            // IF I = PROGPOINT THEN (16018)
            if (1
                & (xEQ (COREHALFWORD (mOBJECT_GENERATORxEMIT_SYM_CARDSxI),
                        COREHALFWORD (mPROGPOINT))))
              // DO; (16019)
              {
              rs1s1s2:;
                // CALL EMIT_SYM('HALS/FC', SYT_LOCK#(SELFNAMELOC),  32);
                // (16020)
                {
                  putCHARACTERp (
                      mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxNAME,
                      cToDescriptor (NULL, "HALS/FC"));
                  putFIXED (mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxVAL,
                            BYTE0 (getFIXED (mSYM_TAB)
                                   + 34 * (COREHALFWORD (mSELFNAMELOC)) + 31
                                   + 1 * (0)));
                  putBITp (8, mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxFLAG,
                           fixedToBit (32, (int32_t)(32)));
                  OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM (0);
                }
                // DO B = 1 TO PROGPOINT - 1; (16021)
                {
                  int32_t from156, to156, by156;
                  from156 = 1;
                  to156 = xsubtract (COREHALFWORD (mPROGPOINT), 1);
                  by156 = 1;
                  for (putBIT (16, mOBJECT_GENERATORxEMIT_SYM_CARDSxB,
                               fixedToBit (16, from156));
                       bitToFixed (
                           getBIT (16, mOBJECT_GENERATORxEMIT_SYM_CARDSxB))
                       <= to156;
                       putBIT (
                           16, mOBJECT_GENERATORxEMIT_SYM_CARDSxB,
                           fixedToBit (
                               16, bitToFixed (getBIT (
                                       16, mOBJECT_GENERATORxEMIT_SYM_CARDSxB))
                                       + by156)))
                    {
                      // IF SYT_LOCK#(PROC_LEVEL(B)) ~= 0 THEN (16022)
                      if (1
                          & (xNEQ (
                              BYTE0 (
                                  getFIXED (mSYM_TAB)
                                  + 34
                                        * (COREHALFWORD (
                                            mPROC_LEVEL
                                            + 2
                                                  * COREHALFWORD (
                                                      mOBJECT_GENERATORxEMIT_SYM_CARDSxB)))
                                  + 31 + 1 * (0)),
                              0)))
                        // CALL EMIT_SYM(ESD_TABLE(B),
                        // SYT_LOCK#(PROC_LEVEL(B))); (16023)
                        {
                          putCHARACTERp (
                              mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxNAME,
                              (putBITp (
                                   16, mESD_TABLExPTR,
                                   getBIT (
                                       16,
                                       mOBJECT_GENERATORxEMIT_SYM_CARDSxB)),
                               ESD_TABLE (0)));
                          putFIXED (
                              mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxVAL,
                              BYTE0 (
                                  getFIXED (mSYM_TAB)
                                  + 34
                                        * (COREHALFWORD (
                                            mPROC_LEVEL
                                            + 2
                                                  * COREHALFWORD (
                                                      mOBJECT_GENERATORxEMIT_SYM_CARDSxB)))
                                  + 31 + 1 * (0)));
                          OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM (0);
                        }
                    }
                } // End of DO for-loop block
                // CALL EMIT_SYM('HALS/END', 0); (16024)
                {
                  putCHARACTERp (
                      mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxNAME,
                      cToDescriptor (NULL, "HALS/END"));
                  putFIXED (mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxVAL, 0);
                  OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM (0);
                }
                // CALL EMIT_SYM(ESD_TABLE(I), 0,  16); (16025)
                {
                  putCHARACTERp (
                      mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxNAME,
                      (putBITp (
                           16, mESD_TABLExPTR,
                           getBIT (16, mOBJECT_GENERATORxEMIT_SYM_CARDSxI)),
                       ESD_TABLE (0)));
                  putFIXED (mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxVAL, 0);
                  putBITp (8, mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxFLAG,
                           fixedToBit (32, (int32_t)(16)));
                  OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM (0);
                }
                // CALL EMIT_SYM('D'||SUBSTR(100000+DATE_OF_COMPILATION,1), 1,
                // 64); (16026)
                {
                  putCHARACTERp (
                      mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxNAME,
                      xsCAT (cToDescriptor (NULL, "D"),
                             SUBSTR2 (fixedToCharacter (xadd (
                                          100000, getFIXED (mCOMM + 4 * 13))),
                                      1)));
                  putFIXED (mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxVAL, 1);
                  putBITp (8, mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxFLAG,
                           fixedToBit (32, (int32_t)(64)));
                  OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM (0);
                }
                // CALL EMIT_SYM('T'||SUBSTR(10000000+TIME_OF_COMPILATION,1),
                // 1,  64); (16027)
                {
                  putCHARACTERp (
                      mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxNAME,
                      xsCAT (
                          cToDescriptor (NULL, "T"),
                          SUBSTR2 (fixedToCharacter (xadd (
                                       10000000, getFIXED (mCOMM + 4 * 12))),
                                   1)));
                  putFIXED (mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxVAL, 1);
                  putBITp (8, mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxFLAG,
                           fixedToBit (32, (int32_t)(64)));
                  OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM (0);
                }
              es1s1s2:;
              } // End of DO block
            // IF I > SYMBREAK THEN (16028)
            if (1
                & (xGT (COREHALFWORD (mOBJECT_GENERATORxEMIT_SYM_CARDSxI),
                        COREHALFWORD (mSYMBREAK))))
              // DO; (16029)
              {
              rs1s1s3:;
                // IF BYTES_REMAINING < 5 THEN (16030)
                if (1
                    & (xLT (COREHALFWORD (mOBJECT_GENERATORxBYTES_REMAINING),
                            5)))
                  // CALL EMIT_SYM_CARD; (16031)
                  OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM_CARD (0);
                // COLUMN(J) =  136; (16032)
                {
                  int32_t numberRHS = (int32_t)(136);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (8,
                          mOBJECT_GENERATORxCOLUMN
                              + 1
                                    * (COREHALFWORD (
                                        mOBJECT_GENERATORxEMIT_SYM_CARDSxJ)),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
                // COLUMN(J+1), COLUMN(J+2), COLUMN(J+3) = 0; (16033)
                {
                  int32_t numberRHS = (int32_t)(0);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (
                      8,
                      mOBJECT_GENERATORxCOLUMN
                          + 1
                                * (xadd (
                                    COREHALFWORD (
                                        mOBJECT_GENERATORxEMIT_SYM_CARDSxJ),
                                    1)),
                      bitRHS);
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (
                      8,
                      mOBJECT_GENERATORxCOLUMN
                          + 1
                                * (xadd (
                                    COREHALFWORD (
                                        mOBJECT_GENERATORxEMIT_SYM_CARDSxJ),
                                    2)),
                      bitRHS);
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (
                      8,
                      mOBJECT_GENERATORxCOLUMN
                          + 1
                                * (xadd (
                                    COREHALFWORD (
                                        mOBJECT_GENERATORxEMIT_SYM_CARDSxJ),
                                    3)),
                      bitRHS);
                  bitRHS->inUse = 0;
                }
                // COLUMN(J+4) =  132; (16034)
                {
                  int32_t numberRHS = (int32_t)(132);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (
                      8,
                      mOBJECT_GENERATORxCOLUMN
                          + 1
                                * (xadd (
                                    COREHALFWORD (
                                        mOBJECT_GENERATORxEMIT_SYM_CARDSxJ),
                                    4)),
                      bitRHS);
                  bitRHS->inUse = 0;
                }
                // BYTES_REMAINING = BYTES_REMAINING - 5; (16035)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      COREHALFWORD (mOBJECT_GENERATORxBYTES_REMAINING), 5));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mOBJECT_GENERATORxBYTES_REMAINING, bitRHS);
                  bitRHS->inUse = 0;
                }
                // J = J + 5; (16036)
                {
                  int32_t numberRHS = (int32_t)(xadd (
                      COREHALFWORD (mOBJECT_GENERATORxEMIT_SYM_CARDSxJ), 5));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mOBJECT_GENERATORxEMIT_SYM_CARDSxJ, bitRHS);
                  bitRHS->inUse = 0;
                }
                // IF (OPTION_BITS &  64) ~= 0 THEN (16037)
                if (1 & (xNEQ (xAND (getFIXED (mCOMM + 4 * 7), 64), 0)))
                  // IF I = DATABASE THEN (16038)
                  if (1
                      & (xEQ (
                          COREHALFWORD (mOBJECT_GENERATORxEMIT_SYM_CARDSxI),
                          COREHALFWORD (mDATABASE))))
                    // DO B = PROGPOINT TO PROCLIMIT; (16039)
                    {
                      int32_t from157, to157, by157;
                      from157 = bitToFixed (getBIT (16, mPROGPOINT));
                      to157 = bitToFixed (getBIT (16, mPROCLIMIT));
                      by157 = 1;
                      for (putBIT (16, mOBJECT_GENERATORxEMIT_SYM_CARDSxB,
                                   fixedToBit (16, from157));
                           bitToFixed (
                               getBIT (16, mOBJECT_GENERATORxEMIT_SYM_CARDSxB))
                           <= to157;
                           putBIT (
                               16, mOBJECT_GENERATORxEMIT_SYM_CARDSxB,
                               fixedToBit (
                                   16,
                                   bitToFixed (getBIT (
                                       16, mOBJECT_GENERATORxEMIT_SYM_CARDSxB))
                                       + by157)))
                        {
                          // P = PROC_LEVEL(B); (16040)
                          {
                            descriptor_t *bitRHS = getBIT (
                                16,
                                mPROC_LEVEL
                                    + 2
                                          * COREHALFWORD (
                                              mOBJECT_GENERATORxEMIT_SYM_CARDSxB));
                            putBIT (16, mOBJECT_GENERATORxEMIT_SYM_CARDSxP,
                                    bitRHS);
                            bitRHS->inUse = 0;
                          }
                          // DO WHILE P > 0; (16041)
                          while (
                              1
                              & (xGT (COREHALFWORD (
                                          mOBJECT_GENERATORxEMIT_SYM_CARDSxP),
                                      0)))
                            {
                              // IF SYT_BASE(P) ~= TEMPBASE THEN (16042)
                              if (1
                                  & (xNEQ (
                                      COREHALFWORD (
                                          getFIXED (mP2SYMS)
                                          + 12
                                                * (COREHALFWORD (
                                                    mOBJECT_GENERATORxEMIT_SYM_CARDSxP))
                                          + 4 + 2 * (0)),
                                      BYTE0 (mTEMPBASE))))
                                // DO; (16043)
                                {
                                rs1s1s3s1s1s1:;
                                  // CALL EMIT_SYM(SYT_NAME(P), SYT_ADDR(P),
                                  // 128); (16044)
                                  {
                                    putCHARACTERp (
                                        mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxNAME,
                                        getCHARACTER (
                                            getFIXED (mSYM_TAB)
                                            + 34
                                                  * (COREHALFWORD (
                                                      mOBJECT_GENERATORxEMIT_SYM_CARDSxP))
                                            + 0 + 4 * (0)));
                                    putFIXED (
                                        mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxVAL,
                                        getFIXED (
                                            getFIXED (mSYM_TAB)
                                            + 34
                                                  * (COREHALFWORD (
                                                      mOBJECT_GENERATORxEMIT_SYM_CARDSxP))
                                            + 4 + 4 * (0)));
                                    putBITp (
                                        8,
                                        mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYMxFLAG,
                                        fixedToBit (32, (int32_t)(128)));
                                    OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM (
                                        0);
                                  }
                                  // T = SYT_TYPE(P); (16045)
                                  {
                                    descriptor_t *bitRHS = getBIT (
                                        8,
                                        getFIXED (mSYM_TAB)
                                            + 34
                                                  * (COREHALFWORD (
                                                      mOBJECT_GENERATORxEMIT_SYM_CARDSxP))
                                            + 32 + 1 * (0));
                                    putBIT (16,
                                            mOBJECT_GENERATORxEMIT_SYM_CARDSxT,
                                            bitRHS);
                                    bitRHS->inUse = 0;
                                  }
                                  // IF (SYT_FLAGS(P) & NAME_FLAG) ~= 0 THEN
                                  // (16046)
                                  if (1
                                      & (xNEQ (
                                          xAND (
                                              getFIXED (
                                                  getFIXED (mSYM_TAB)
                                                  + 34
                                                        * (COREHALFWORD (
                                                            mOBJECT_GENERATORxEMIT_SYM_CARDSxP))
                                                  + 8 + 4 * (0)),
                                              getFIXED (mNAME_FLAG)),
                                          0)))
                                    // T = APOINTER; (16047)
                                    {
                                      descriptor_t *bitRHS
                                          = getBIT (8, mAPOINTER);
                                      putBIT (
                                          16,
                                          mOBJECT_GENERATORxEMIT_SYM_CARDSxT,
                                          bitRHS);
                                      bitRHS->inUse = 0;
                                    }
                                  // ELSE (16048)
                                  else
                                    // IF T >= ANY_LABEL THEN (16049)
                                    if (1
                                        & (xGE (
                                            COREHALFWORD (
                                                mOBJECT_GENERATORxEMIT_SYM_CARDSxT),
                                            BYTE0 (mANY_LABEL))))
                                      // T = INTEGER; (16050)
                                      {
                                        descriptor_t *bitRHS
                                            = getBIT (8, mINTEGER);
                                        putBIT (
                                            16,
                                            mOBJECT_GENERATORxEMIT_SYM_CARDSxT,
                                            bitRHS);
                                        bitRHS->inUse = 0;
                                      }
                                  // CALL EMIT_SYM_DATA(SYMCARD(T), BIGHTS(T));
                                  // (16051)
                                  {
                                    putBITp (
                                        16,
                                        mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM_DATAxTYP,
                                        getBIT (
                                            8,
                                            mOBJECT_GENERATORxSYMCARD
                                                + 1
                                                      * COREHALFWORD (
                                                          mOBJECT_GENERATORxEMIT_SYM_CARDSxT)));
                                    putBITp (
                                        16,
                                        mOBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM_DATAxSIZ,
                                        getBIT (
                                            8,
                                            mBIGHTS
                                                + 1
                                                      * COREHALFWORD (
                                                          mOBJECT_GENERATORxEMIT_SYM_CARDSxT)));
                                    OBJECT_GENERATORxEMIT_SYM_CARDSxEMIT_SYM_DATA (
                                        0);
                                  }
                                es1s1s3s1s1s1:;
                                } // End of DO block
                              // P = SYT_LEVEL(P); (16052)
                              {
                                descriptor_t *bitRHS = getBIT (
                                    16,
                                    getFIXED (mP2SYMS)
                                        + 12
                                              * (COREHALFWORD (
                                                  mOBJECT_GENERATORxEMIT_SYM_CARDSxP))
                                        + 10 + 2 * (0));
                                putBIT (16, mOBJECT_GENERATORxEMIT_SYM_CARDSxP,
                                        bitRHS);
                                bitRHS->inUse = 0;
                              }
                            } // End of DO WHILE block
                        }
                    } // End of DO for-loop block
              es1s1s3:;
              } // End of DO block
          es1s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
