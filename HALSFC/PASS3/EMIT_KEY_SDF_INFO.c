/*
  File EMIT_KEY_SDF_INFO.c generated by XCOM-I, 2024-08-09 12:40:16.
*/

#include "runtimeC.h"

int32_t
EMIT_KEY_SDF_INFO (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "EMIT_KEY_SDF_INFO");
  // CHAR_STRING = ' DEC   HEX  -HEX    PTR      BLOCK NAME '|| ' PTR    BLK#
  // SYMBOL NAME'; (1490)
  {
    descriptor_t *stringRHS;
    stringRHS
        = cToDescriptor (NULL, " DEC   HEX  -HEX    PTR      BLOCK NAME       "
                               "               PTR    BLK#    SYMBOL NAME");
    putCHARACTER (mEMIT_KEY_SDF_INFOxCHAR_STRING, stringRHS);
    stringRHS->inUse = 0;
  }
  // CHAR_STRING = CHAR_STRING || X20 || 'PTR      SRN   COUNT'; (1491)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (xsCAT (getCHARACTER (mEMIT_KEY_SDF_INFOxCHAR_STRING),
                              getCHARACTER (mX20)),
                       cToDescriptor (NULL, "PTR      SRN   COUNT"));
    putCHARACTER (mEMIT_KEY_SDF_INFOxCHAR_STRING, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '2'||CHAR_STRING; (1492)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "2"),
                       getCHARACTER (mEMIT_KEY_SDF_INFOxCHAR_STRING));
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = CHAR_STRING; (1493)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mEMIT_KEY_SDF_INFOxCHAR_STRING);
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = X1; (1494)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mX1);
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // KLIM = LAST_STMT; (1495)
  {
    descriptor_t *bitRHS = getBIT (16, mLAST_STMT);
    putBIT (16, mEMIT_KEY_SDF_INFOxKLIM, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF KLIM < #SYMBOLS THEN (1496)
  if (1
      & (xLT (COREHALFWORD (mEMIT_KEY_SDF_INFOxKLIM),
              COREHALFWORD (mpSYMBOLS))))
    // KLIM = #SYMBOLS; (1497)
    {
      descriptor_t *bitRHS = getBIT (16, mpSYMBOLS);
      putBIT (16, mEMIT_KEY_SDF_INFOxKLIM, bitRHS);
      bitRHS->inUse = 0;
    }
  // DO K = 1 TO KLIM; (1498)
  {
    int32_t from40, to40, by40;
    from40 = 1;
    to40 = bitToFixed (getBIT (16, mEMIT_KEY_SDF_INFOxKLIM));
    by40 = 1;
    for (putBIT (16, mEMIT_KEY_SDF_INFOxK, fixedToBit (16, from40));
         bitToFixed (getBIT (16, mEMIT_KEY_SDF_INFOxK)) <= to40;
         putBIT (16, mEMIT_KEY_SDF_INFOxK,
                 fixedToBit (16, bitToFixed (getBIT (16, mEMIT_KEY_SDF_INFOxK))
                                     + by40)))
      {
        // TS = FORMAT(K,4)||X2; (1499)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              (putFIXED (mFORMATxIVAL, COREHALFWORD (mEMIT_KEY_SDF_INFOxK)),
               putFIXED (mFORMATxN, 4), FORMAT (0)),
              getCHARACTER (mX2));
          putCHARACTER (mEMIT_KEY_SDF_INFOxTS, stringRHS);
          stringRHS->inUse = 0;
        }
        // TS(1) = HEX(K,4)||X2; (1500)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              (putFIXED (mHEXxHVAL, COREHALFWORD (mEMIT_KEY_SDF_INFOxK)),
               putFIXED (mHEXxN, 4), HEX (0)),
              getCHARACTER (mX2));
          putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (1), stringRHS);
          stringRHS->inUse = 0;
        }
        // TEMP = (-K) &  65535; (1501)
        {
          int32_t numberRHS = (int32_t)(xAND (
              xminus (COREHALFWORD (mEMIT_KEY_SDF_INFOxK)), 65535));
          putFIXED (mEMIT_KEY_SDF_INFOxTEMP, numberRHS);
        }
        // TS(10) = HEX(TEMP,4) || X2; (1502)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              (putFIXED (mHEXxHVAL, getFIXED (mEMIT_KEY_SDF_INFOxTEMP)),
               putFIXED (mHEXxN, 4), HEX (0)),
              getCHARACTER (mX2));
          putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (10), stringRHS);
          stringRHS->inUse = 0;
        }
        // IF #PROCS >= K THEN (1503)
        if (1
            & (xGE (COREHALFWORD (mpPROCS),
                    COREHALFWORD (mEMIT_KEY_SDF_INFOxK))))
          // DO; (1504)
          {
          rs1s1:;
            // PTR = BLOCK_TO_PTR(K); (1505)
            {
              int32_t numberRHS
                  = (int32_t)((putBITp (16, mBLOCK_TO_PTRxBLOCK,
                                        getBIT (16, mEMIT_KEY_SDF_INFOxK)),
                               BLOCK_TO_PTR (0)));
              putFIXED (mEMIT_KEY_SDF_INFOxPTR, numberRHS);
            }
            // TS(2) = HEX8(PTR)||X2; (1506)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  (putFIXED (mHEX8xHVAL, getFIXED (mEMIT_KEY_SDF_INFOxPTR)),
                   HEX8 (0)),
                  getCHARACTER (mX2));
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (2), stringRHS);
              stringRHS->inUse = 0;
            }
            // I = PROC_TAB8(PROC_TAB5(K)); (1507)
            {
              descriptor_t *bitRHS = getBIT (
                  16,
                  mPROC_TAB8
                      + 2
                            * COREHALFWORD (
                                mPROC_TAB5
                                + 2 * COREHALFWORD (mEMIT_KEY_SDF_INFOxK)));
              putBIT (16, mEMIT_KEY_SDF_INFOxI, bitRHS);
              bitRHS->inUse = 0;
            }
            // I = SYT_SORT2(PROC_TAB1(I)); (1508)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mSORTING)
                          + 12
                                * (COREHALFWORD (
                                    mPROC_TAB1
                                    + 2 * COREHALFWORD (mEMIT_KEY_SDF_INFOxI)))
                          + 2 + 2 * (0));
              putBIT (16, mEMIT_KEY_SDF_INFOxI, bitRHS);
              bitRHS->inUse = 0;
            }
            // TS(3) = SYT_NAME1(I)||X2; (1509)
            {
              descriptor_t *stringRHS;
              stringRHS
                  = xsCAT ((putFIXED (mSYT_NAME1xPTR,
                                      COREHALFWORD (mEMIT_KEY_SDF_INFOxI)),
                            SYT_NAME1 (0)),
                           getCHARACTER (mX2));
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (3), stringRHS);
              stringRHS->inUse = 0;
            }
          es1s1:;
          } // End of DO block
        // ELSE (1510)
        else
          // DO; (1511)
          {
          rs1s2:;
            // TS(2) = X10; (1512)
            {
              descriptor_t *stringRHS;
              stringRHS = getCHARACTER (mX10);
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (2), stringRHS);
              stringRHS->inUse = 0;
            }
            // TS(3) = X30; (1513)
            {
              descriptor_t *stringRHS;
              stringRHS = getCHARACTER (mX30);
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (3), stringRHS);
              stringRHS->inUse = 0;
            }
          es1s2:;
          } // End of DO block
        // IF #SYMBOLS >= K THEN (1514)
        if (1
            & (xGE (COREHALFWORD (mpSYMBOLS),
                    COREHALFWORD (mEMIT_KEY_SDF_INFOxK))))
          // DO; (1515)
          {
          rs1s3:;
            // PTR = SYMB_TO_PTR(K); (1516)
            {
              int32_t numberRHS
                  = (int32_t)((putBITp (16, mSYMB_TO_PTRxSYMB,
                                        getBIT (16, mEMIT_KEY_SDF_INFOxK)),
                               SYMB_TO_PTR (0)));
              putFIXED (mEMIT_KEY_SDF_INFOxPTR, numberRHS);
            }
            // TS(4) = HEX8(PTR)||X2; (1517)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  (putFIXED (mHEX8xHVAL, getFIXED (mEMIT_KEY_SDF_INFOxPTR)),
                   HEX8 (0)),
                  getCHARACTER (mX2));
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (4), stringRHS);
              stringRHS->inUse = 0;
            }
            // L = SYT_SCOPE(SYT_SORT2(K)); (1518)
            {
              descriptor_t *bitRHS = getBIT (
                  8, getFIXED (mSYM_TAB)
                         + 34
                               * (COREHALFWORD (
                                   getFIXED (mSORTING)
                                   + 12 * (COREHALFWORD (mEMIT_KEY_SDF_INFOxK))
                                   + 2 + 2 * (0)))
                         + 29 + 1 * (0));
              putBIT (16, mEMIT_KEY_SDF_INFOxL, bitRHS);
              bitRHS->inUse = 0;
            }
            // L = SYT_SORT2(PROC_TAB1(L)); (1519)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mSORTING)
                          + 12
                                * (COREHALFWORD (
                                    mPROC_TAB1
                                    + 2 * COREHALFWORD (mEMIT_KEY_SDF_INFOxL)))
                          + 2 + 2 * (0));
              putBIT (16, mEMIT_KEY_SDF_INFOxL, bitRHS);
              bitRHS->inUse = 0;
            }
            // TS(9) = HEX(SYT_SORT3(L),4)||X2; (1520)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  (putFIXED (mHEXxHVAL,
                             COREHALFWORD (
                                 getFIXED (mSORTING)
                                 + 12 * (COREHALFWORD (mEMIT_KEY_SDF_INFOxL))
                                 + 4 + 2 * (0))),
                   putFIXED (mHEXxN, 4), HEX (0)),
                  getCHARACTER (mX2));
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (9), stringRHS);
              stringRHS->inUse = 0;
            }
            // TS(5) = SYT_NAME1(SYT_SORT2(K))||X2; (1521)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  (putFIXED (mSYT_NAME1xPTR,
                             COREHALFWORD (
                                 getFIXED (mSORTING)
                                 + 12 * (COREHALFWORD (mEMIT_KEY_SDF_INFOxK))
                                 + 2 + 2 * (0))),
                   SYT_NAME1 (0)),
                  getCHARACTER (mX2));
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (5), stringRHS);
              stringRHS->inUse = 0;
            }
          es1s3:;
          } // End of DO block
        // ELSE (1522)
        else
          // DO; (1523)
          {
          rs1s4:;
            // TS(4) = X10; (1524)
            {
              descriptor_t *stringRHS;
              stringRHS = getCHARACTER (mX10);
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (4), stringRHS);
              stringRHS->inUse = 0;
            }
            // TS(9) = X6; (1525)
            {
              descriptor_t *stringRHS;
              stringRHS = getCHARACTER (mX6);
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (9), stringRHS);
              stringRHS->inUse = 0;
            }
            // TS(5) = X30; (1526)
            {
              descriptor_t *stringRHS;
              stringRHS = getCHARACTER (mX30);
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (5), stringRHS);
              stringRHS->inUse = 0;
            }
          es1s4:;
          } // End of DO block
        // IF (K >= FIRST_STMT) & (K <= LAST_STMT) THEN (1527)
        if (1
            & (xAND (xGE (COREHALFWORD (mEMIT_KEY_SDF_INFOxK),
                          getFIXED (mCOMM + 4 * 11)),
                     xLE (COREHALFWORD (mEMIT_KEY_SDF_INFOxK),
                          COREHALFWORD (mLAST_STMT)))))
          // DO; (1528)
          {
          rs1s5:;
            // PTR = STMT_TO_PTR(K); (1529)
            {
              int32_t numberRHS
                  = (int32_t)((putBITp (16, mSTMT_TO_PTRxSTMT,
                                        getBIT (16, mEMIT_KEY_SDF_INFOxK)),
                               STMT_TO_PTR (0)));
              putFIXED (mEMIT_KEY_SDF_INFOxPTR, numberRHS);
            }
            // TS(6) = HEX8(PTR)||X2; (1530)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  (putFIXED (mHEX8xHVAL, getFIXED (mEMIT_KEY_SDF_INFOxPTR)),
                   HEX8 (0)),
                  getCHARACTER (mX2));
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (6), stringRHS);
              stringRHS->inUse = 0;
            }
            // IF SRN_FLAG THEN (1531)
            if (1 & (bitToFixed (getBIT (1, mSRN_FLAG))))
              // DO; (1532)
              {
              rs1s5s1:;
                // CALL P3_LOCATE(PTR,ADDR(NODE_H),0); (1533)
                {
                  putFIXED (mP3_LOCATExPTR, getFIXED (mEMIT_KEY_SDF_INFOxPTR));
                  putFIXED (mP3_LOCATExBVAR, ADDR ("EMIT_KEY_SDF_INFOxNODE_H",
                                                   0x80000000, NULL, 0));
                  putBITp (8, mP3_LOCATExFLAGS, fixedToBit (32, (int32_t)(0)));
                  P3_LOCATE (0);
                }
                // COREWORD(ADDR(TS(7))) = LOC_ADDR +  83886080; (1534)
                {
                  int32_t numberRHS
                      = (int32_t)(xadd (getFIXED (mLOC_ADDR), 83886080));
                  COREWORD2 (ADDR (NULL, 0, "EMIT_KEY_SDF_INFOxTS", 7),
                             numberRHS);
                }
                // TS(7) = TS(7)||X1; (1535)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = xsCAT (getCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * 7),
                               getCHARACTER (mX1));
                  putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (7), stringRHS);
                  stringRHS->inUse = 0;
                }
                // TS(8) = FORMAT(NODE_H(3),5); (1536)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = (putFIXED (
                             mFORMATxIVAL,
                             COREHALFWORD (getFIXED (mEMIT_KEY_SDF_INFOxNODE_H)
                                           + 2 * 3)),
                         putFIXED (mFORMATxN, 5), FORMAT (0));
                  putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (8), stringRHS);
                  stringRHS->inUse = 0;
                }
              es1s5s1:;
              } // End of DO block
            // ELSE (1537)
            else
              // DO; (1538)
              {
              rs1s5s2:;
                // TS(7) = X7; (1539)
                {
                  descriptor_t *stringRHS;
                  stringRHS = getCHARACTER (mX7);
                  putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (7), stringRHS);
                  stringRHS->inUse = 0;
                }
                // TS(8) = X5; (1540)
                {
                  descriptor_t *stringRHS;
                  stringRHS = getCHARACTER (mX5);
                  putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (8), stringRHS);
                  stringRHS->inUse = 0;
                }
              es1s5s2:;
              } // End of DO block
          es1s5:;
          } // End of DO block
        // ELSE (1541)
        else
          // DO; (1542)
          {
          rs1s6:;
            // TS(6) = X10; (1543)
            {
              descriptor_t *stringRHS;
              stringRHS = getCHARACTER (mX10);
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (6), stringRHS);
              stringRHS->inUse = 0;
            }
            // TS(7) = X7; (1544)
            {
              descriptor_t *stringRHS;
              stringRHS = getCHARACTER (mX7);
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (7), stringRHS);
              stringRHS->inUse = 0;
            }
            // TS(8) = X5; (1545)
            {
              descriptor_t *stringRHS;
              stringRHS = getCHARACTER (mX5);
              putCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * (8), stringRHS);
              stringRHS->inUse = 0;
            }
          es1s6:;
          } // End of DO block
        // OUTPUT = TS||TS(1)||TS(10)|| TS(2)|| TS(3)||TS(4)||TS(9)||TS(5)
        // ||TS(6)||TS(7)||TS(8); (1546)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              xsCAT (
                  xsCAT (
                      xsCAT (
                          xsCAT (
                              xsCAT (
                                  xsCAT (
                                      xsCAT (
                                          xsCAT (
                                              xsCAT (
                                                  getCHARACTER (
                                                      mEMIT_KEY_SDF_INFOxTS),
                                                  getCHARACTER (
                                                      mEMIT_KEY_SDF_INFOxTS
                                                      + 4 * 1)),
                                              getCHARACTER (
                                                  mEMIT_KEY_SDF_INFOxTS
                                                  + 4 * 10)),
                                          getCHARACTER (mEMIT_KEY_SDF_INFOxTS
                                                        + 4 * 2)),
                                      getCHARACTER (mEMIT_KEY_SDF_INFOxTS
                                                    + 4 * 3)),
                                  getCHARACTER (mEMIT_KEY_SDF_INFOxTS
                                                + 4 * 4)),
                              getCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * 9)),
                          getCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * 5)),
                      getCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * 6)),
                  getCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * 7)),
              getCHARACTER (mEMIT_KEY_SDF_INFOxTS + 4 * 8));
          OUTPUT (0, stringRHS);
          stringRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
