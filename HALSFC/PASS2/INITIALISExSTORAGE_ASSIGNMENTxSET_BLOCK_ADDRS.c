/*
  File INITIALISExSTORAGE_ASSIGNMENTxSET_BLOCK_ADDRS.c generated by XCOM-I,
  2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
INITIALISExSTORAGE_ASSIGNMENTxSET_BLOCK_ADDRS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (
      reentryGuard, "INITIALISExSTORAGE_ASSIGNMENTxSET_BLOCK_ADDRS");
  // IF Y > X THEN (2371)
  if (1
      & (xGT (getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxY),
              getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxX))))
    // DO; (2372)
    {
    rs1:;
      // IF X = -1 THEN (2373)
      if (1 & (xEQ (getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxX), -1)))
        // X = PROGPOINT-1; (2374)
        {
          int32_t numberRHS
              = (int32_t)(xsubtract (COREHALFWORD (mPROGPOINT), 1));
          putFIXED (mINITIALISExSTORAGE_ASSIGNMENTxX, numberRHS);
        }
      // IF Y < PROGPOINT THEN (2375)
      if (1
          & (xLT (getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxY),
                  COREHALFWORD (mPROGPOINT))))
        // Y = PROGPOINT; (2376)
        {
          descriptor_t *bitRHS = getBIT (16, mPROGPOINT);
          int32_t numberRHS;
          numberRHS = bitToFixed (bitRHS);
          putFIXED (mINITIALISExSTORAGE_ASSIGNMENTxY, numberRHS);
          bitRHS->inUse = 0;
        }
      // DO X = X+1 TO Y; (2377)
      {
        int32_t from37, to37, by37;
        from37 = xadd (getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxX), 1);
        to37 = getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxY);
        by37 = 1;
        for (putFIXED (mINITIALISExSTORAGE_ASSIGNMENTxX, from37);
             getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxX) <= to37;
             putFIXED (mINITIALISExSTORAGE_ASSIGNMENTxX,
                       getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxX) + by37))
          {
            // IF X = PROGPOINT THEN (2378)
            if (1
                & (xEQ (getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxX),
                        COREHALFWORD (mPROGPOINT))))
              // IF CALL#(X) ~= 2 THEN (2379)
              if (1
                  & (xNEQ (
                      BYTE0 (
                          mCALLp
                          + 1 * getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxX)),
                      2)))
                // DO; (2380)
                {
                rs1s1s1:;
                  // LASTREMOTE = FIRSTREMOTE; (2381)
                  {
                    descriptor_t *bitRHS = getBIT (16, mFIRSTREMOTE);
                    putBIT (16, mLASTREMOTE, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // DO WHILE LASTREMOTE > 0; (2382)
                  while (1 & (xGT (COREHALFWORD (mLASTREMOTE), 0)))
                    {
                      // IF SYMBOL_USED(LASTREMOTE) THEN (2383)
                      if (1
                          & (bitToFixed (
                              (putBITp (16, mINITIALISExSYMBOL_USEDxPTR,
                                        getBIT (16, mLASTREMOTE)),
                               INITIALISExSYMBOL_USED (0)))))
                        // DO; (2384)
                        {
                        rs1s1s1s1s1:;
                          // L = ADJUST(2,MAXTEMP(DATABASE)); (2385)
                          {
                            int32_t numberRHS = (int32_t)((
                                putBITp (16, mADJUSTxBIGHT,
                                         fixedToBit (32, (int32_t)(2))),
                                putFIXED (
                                    mADJUSTxADDRESS,
                                    getFIXED (mMAXTEMP
                                              + 4 * COREHALFWORD (mDATABASE))),
                                ADJUST (0)));
                            putFIXED (mINITIALISExL, numberRHS);
                          }
                          // SYT_LINK2(LASTREMOTE) = L; (2386)
                          {
                            int32_t numberRHS
                                = (int32_t)(getFIXED (mINITIALISExL));
                            putBIT (16,
                                    getFIXED (mSYM_TAB)
                                        + 34 * (COREHALFWORD (mLASTREMOTE))
                                        + 26 + 2 * (0),
                                    fixedToBit (16, numberRHS));
                          }
                          // MAXTEMP(DATABASE) = L + 2; (2387)
                          {
                            int32_t numberRHS = (int32_t)(xadd (
                                getFIXED (mINITIALISExL), 2));
                            putFIXED (mMAXTEMP
                                          + 4 * (COREHALFWORD (mDATABASE)),
                                      numberRHS);
                          }
                        es1s1s1s1s1:;
                        } // End of DO block
                      // ELSE (2388)
                      else
                        // SYT_LINK2(LASTREMOTE) = -1; (2389)
                        {
                          int32_t numberRHS = (int32_t)(-1);
                          putBIT (16,
                                  getFIXED (mSYM_TAB)
                                      + 34 * (COREHALFWORD (mLASTREMOTE)) + 26
                                      + 2 * (0),
                                  fixedToBit (16, numberRHS));
                        }
                      // LASTREMOTE = SYT_LINK1(LASTREMOTE); (2390)
                      {
                        descriptor_t *bitRHS = getBIT (
                            16, getFIXED (mSYM_TAB)
                                    + 34 * (COREHALFWORD (mLASTREMOTE)) + 24
                                    + 2 * (0));
                        putBIT (16, mLASTREMOTE, bitRHS);
                        bitRHS->inUse = 0;
                      }
                    } // End of DO WHILE block
                es1s1s1:;
                } // End of DO block
            // NO_SRS = FALSE; (2391)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mNO_SRS, bitRHS);
              bitRHS->inUse = 0;
            }
            // L = ADJUST(2, MAXTEMP(DATABASE)); (2392)
            {
              int32_t numberRHS = (int32_t)((
                  putBITp (16, mADJUSTxBIGHT, fixedToBit (32, (int32_t)(2))),
                  putFIXED (
                      mADJUSTxADDRESS,
                      getFIXED (mMAXTEMP + 4 * COREHALFWORD (mDATABASE))),
                  ADJUST (0)));
              putFIXED (mINITIALISExL, numberRHS);
            }
            // Q = 0; (2393)
            {
              int32_t numberRHS = (int32_t)(0);
              putFIXED (mINITIALISExSTORAGE_ASSIGNMENTxQ, numberRHS);
            }
            // IF CALL#(X) = 4 THEN (2394)
            if (1
                & (xEQ (
                    BYTE0 (mCALLp
                           + 1 * getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxX)),
                    4)))
              // Q = 5; (2395)
              {
                int32_t numberRHS = (int32_t)(5);
                putFIXED (mINITIALISExSTORAGE_ASSIGNMENTxQ, numberRHS);
              }
            // ELSE (2396)
            else
              // IF CALL#(X) ~= 2 THEN (2397)
              if (1
                  & (xNEQ (
                      BYTE0 (
                          mCALLp
                          + 1 * getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxX)),
                      2)))
                // Q = 2; (2398)
                {
                  int32_t numberRHS = (int32_t)(2);
                  putFIXED (mINITIALISExSTORAGE_ASSIGNMENTxQ, numberRHS);
                }
            // MAXTEMP(DATABASE) = L + Q; (2399)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  getFIXED (mINITIALISExL),
                  getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxQ)));
              putFIXED (mMAXTEMP + 4 * (COREHALFWORD (mDATABASE)), numberRHS);
            }
            // SYT_ADDR(PROC_LEVEL(X)) = L; (2400)
            {
              int32_t numberRHS = (int32_t)(getFIXED (mINITIALISExL));
              putFIXED (
                  getFIXED (mSYM_TAB)
                      + 34
                            * (COREHALFWORD (
                                mPROC_LEVEL
                                + 2
                                      * getFIXED (
                                          mINITIALISExSTORAGE_ASSIGNMENTxX)))
                      + 4 + 4 * (0),
                  numberRHS);
            }
          }
      } // End of DO for-loop block
      // X = Y; (2401)
      {
        int32_t numberRHS
            = (int32_t)(getFIXED (mINITIALISExSTORAGE_ASSIGNMENTxY));
        putFIXED (mINITIALISExSTORAGE_ASSIGNMENTxX, numberRHS);
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
