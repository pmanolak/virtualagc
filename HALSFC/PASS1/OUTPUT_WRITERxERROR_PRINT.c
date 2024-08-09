/*
  File OUTPUT_WRITERxERROR_PRINT.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
OUTPUT_WRITERxERROR_PRINT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "OUTPUT_WRITERxERROR_PRINT");
  // DO I = LAST_ERROR_WRITTEN + 1 TO CURRENT_ERROR_PTR; (2120)
  {
    int32_t from44, to44, by44;
    from44 = xadd (COREHALFWORD (mOUTPUT_WRITERxLAST_ERROR_WRITTEN), 1);
    to44 = bitToFixed (getBIT (16, mOUTPUT_WRITERxCURRENT_ERROR_PTR));
    by44 = 1;
    for (putFIXED (mI, from44); getFIXED (mI) <= to44;
         putFIXED (mI, getFIXED (mI) + by44))
      {
        // ERRORS_PRINTED = TRUE; (2121)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (1, mOUTPUT_WRITERxERRORS_PRINTED, bitRHS);
          bitRHS->inUse = 0;
        }
        // ERROR_COUNT = ERROR_COUNT + 1; (2122)
        {
          int32_t numberRHS = (int32_t)(xadd (getFIXED (mERROR_COUNT), 1));
          putFIXED (mERROR_COUNT, numberRHS);
        }
        // SAVE_LINE_#(ERROR_COUNT) = STMT_NUM; (2123)
        {
          int32_t numberRHS = (int32_t)(getFIXED (mCOMM + 4 * 3));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mSAVE_LINE_p + 2 * (getFIXED (mERROR_COUNT)), bitRHS);
          bitRHS->inUse = 0;
        }
        // C = SAVE_ERROR_MESSAGE(I); (2124)
        {
          descriptor_t *stringRHS;
          stringRHS = getCHARACTER (mSAVE_ERROR_MESSAGE + 4 * getFIXED (mI));
          putCHARACTER (mOUTPUT_WRITERxERROR_PRINTxC, stringRHS);
          stringRHS->inUse = 0;
        }
        // ERRORCODE = SUBSTR(C, 0, 8); (2125)
        {
          descriptor_t *stringRHS;
          stringRHS
              = SUBSTR (getCHARACTER (mOUTPUT_WRITERxERROR_PRINTxC), 0, 8);
          putCHARACTER (mOUTPUT_WRITERxERRORCODE, stringRHS);
          stringRHS->inUse = 0;
        }
        // IF MONITOR(2, 5, ERRORCODE) THEN (2126)
        if (1 & (MONITOR2 (5, getCHARACTER (mOUTPUT_WRITERxERRORCODE))))
          // DO; (2127)
          {
          rs1s1:;
            // CALL ERRORS (CLASS_BI, 100, X1||ERRORCODE); (2128)
            {
              putBITp (16, mERRORSxCLASS, getBIT (16, mCLASS_BI));
              putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(100)));
              putCHARACTERp (mERRORSxTEXT,
                             xsCAT (getCHARACTER (mX1),
                                    getCHARACTER (mOUTPUT_WRITERxERRORCODE)));
              ERRORS (0);
            }
            // GO TO ERROR_PRINT_END; (2129)
            goto ERROR_PRINT_END;
          es1s1:;
          } // End of DO block
        // S = INPUT(5); (2130)
        {
          descriptor_t *stringRHS;
          stringRHS = INPUT (5);
          putCHARACTER (mS, stringRHS);
          stringRHS->inUse = 0;
        }
        // SEVERITY = BYTE(S) - BYTE('0'); (2131)
        {
          int32_t numberRHS = (int32_t)(xsubtract (
              BYTE1 (getCHARACTER (mS)), BYTE1 (cToDescriptor (NULL, "0"))));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mOUTPUT_WRITERxSEVERITY, bitRHS);
          bitRHS->inUse = 0;
        }
        // NEW_SEVERITY = CHECK_DOWN(ERRORCODE, SEVERITY); (2132)
        {
          int32_t numberRHS = (int32_t)((
              putCHARACTERp (mCHECK_DOWNxERRORCODE,
                             getCHARACTER (mOUTPUT_WRITERxERRORCODE)),
              putBITp (16, mCHECK_DOWNxSEVERITY,
                       getBIT (16, mOUTPUT_WRITERxSEVERITY)),
              CHECK_DOWN (0)));
          putFIXED (mOUTPUT_WRITERxERROR_PRINTxNEW_SEVERITY, numberRHS);
        }
        // SEVERITY = NEW_SEVERITY; (2133)
        {
          int32_t numberRHS
              = (int32_t)(getFIXED (mOUTPUT_WRITERxERROR_PRINTxNEW_SEVERITY));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mOUTPUT_WRITERxSEVERITY, bitRHS);
          bitRHS->inUse = 0;
        }
        // SAVE_SEVERITY(ERROR_COUNT) = SEVERITY; (2134)
        {
          descriptor_t *bitRHS = getBIT (16, mOUTPUT_WRITERxSEVERITY);
          putBIT (8, mSAVE_SEVERITY + 1 * (getFIXED (mERROR_COUNT)), bitRHS);
          bitRHS->inUse = 0;
        }
        // IF LENGTH(C) > 8 THEN (2135)
        if (1
            & (xGT (LENGTH (getCHARACTER (mOUTPUT_WRITERxERROR_PRINTxC)), 8)))
          // DO; (2136)
          {
          rs1s2:;
            // C = SUBSTR(C, 8); (2137)
            {
              descriptor_t *stringRHS;
              stringRHS
                  = SUBSTR2 (getCHARACTER (mOUTPUT_WRITERxERROR_PRINTxC), 8);
              putCHARACTER (mOUTPUT_WRITERxERROR_PRINTxC, stringRHS);
              stringRHS->inUse = 0;
            }
            // IMBEDDING = TRUE; (2138)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mOUTPUT_WRITERxIMBEDDING, bitRHS);
              bitRHS->inUse = 0;
            }
          es1s2:;
          } // End of DO block
        // IF ERROR_COUNT>=ERRLIM-3 THEN (2139)
        if (1 & (xGE (getFIXED (mERROR_COUNT), 99)))
          // DO; (2140)
          {
          rs1s3:;
            // MAX_SEVERITY = MAX(MAX_SEVERITY, 2); (2141)
            {
              int32_t numberRHS
                  = (int32_t)((putFIXED (mMAXxI, getFIXED (mMAX_SEVERITY)),
                               putFIXED (mMAXxJ, 2), MAX (0)));
              putFIXED (mMAX_SEVERITY, numberRHS);
            }
            // IF PRNTERRWARN THEN (2142)
            if (1 & (bitToFixed (getBIT (1, mOUTPUT_WRITERxPRNTERRWARN))))
              // DO; (2143)
              {
              rs1s3s1:;
                // PRNTERRWARN = FALSE; (2144)
                {
                  int32_t numberRHS = (int32_t)(0);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (1, mOUTPUT_WRITERxPRNTERRWARN, bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL ERRORS (CLASS_BI, 106); (2145)
                {
                  putBITp (16, mERRORSxCLASS, getBIT (16, mCLASS_BI));
                  putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(106)));
                  ERRORS (0);
                }
              es1s3s1:;
              } // End of DO block
            // IF COMPILING THEN (2146)
            if (1 & (bitToFixed (getBIT (1, mCOMPILING))))
              // COMPILING = FALSE; (2147)
              {
                int32_t numberRHS = (int32_t)(0);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (1, mCOMPILING, bitRHS);
                bitRHS->inUse = 0;
              }
            // ELSE (2148)
            else
              // GO TO OUTPUT_WRITER_DISASTER; (2149)
              {
                resetAllReentryGuards ();
                longjmp (jbOUTPUT_WRITER_DISASTER, 1);
              }
          es1s3:;
          } // End of DO block
        // OUTPUT(1) = '0***** ' || ERRORCODE || ' ERROR #' || ERROR_COUNT || '
        // OF SEVERITY ' || SEVERITY || '. *****'; (2150)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              xsCAT (
                  xsCAT (xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "0***** "),
                                              getCHARACTER (
                                                  mOUTPUT_WRITERxERRORCODE)),
                                       cToDescriptor (NULL, " ERROR #")),
                                fixedToCharacter (getFIXED (mERROR_COUNT))),
                         cToDescriptor (NULL, " OF SEVERITY ")),
                  bitToCharacter (getBIT (16, mOUTPUT_WRITERxSEVERITY))),
              cToDescriptor (NULL, ". *****"));
          OUTPUT (1, stringRHS);
          stringRHS->inUse = 0;
        }
        // IF SEVERITY > MAX_SEVERITY THEN (2151)
        if (1
            & (xGT (COREHALFWORD (mOUTPUT_WRITERxSEVERITY),
                    getFIXED (mMAX_SEVERITY))))
          // MAX_SEVERITY = SEVERITY; (2152)
          {
            descriptor_t *bitRHS = getBIT (16, mOUTPUT_WRITERxSEVERITY);
            int32_t numberRHS;
            numberRHS = bitToFixed (bitRHS);
            putFIXED (mMAX_SEVERITY, numberRHS);
            bitRHS->inUse = 0;
          }
        // IF SEVERITY > STATEMENT_SEVERITY THEN (2153)
        if (1
            & (xGT (COREHALFWORD (mOUTPUT_WRITERxSEVERITY),
                    getFIXED (mSTATEMENT_SEVERITY))))
          // STATEMENT_SEVERITY = SEVERITY; (2154)
          {
            descriptor_t *bitRHS = getBIT (16, mOUTPUT_WRITERxSEVERITY);
            int32_t numberRHS;
            numberRHS = bitToFixed (bitRHS);
            putFIXED (mSTATEMENT_SEVERITY, numberRHS);
            bitRHS->inUse = 0;
          }
        // S = INPUT(5); (2155)
        {
          descriptor_t *stringRHS;
          stringRHS = INPUT (5);
          putCHARACTER (mS, stringRHS);
          stringRHS->inUse = 0;
        }
        // DO WHILE LENGTH(S) > 0; (2156)
        while (1 & (xGT (LENGTH (getCHARACTER (mS)), 0)))
          {
            // IF IMBEDDING THEN (2157)
            if (1 & (bitToFixed (getBIT (1, mOUTPUT_WRITERxIMBEDDING))))
              // DO; (2158)
              {
              rs1s4s1:;
                // K = CHAR_INDEX(S, '??'); (2159)
                {
                  int32_t numberRHS = (int32_t)((
                      putCHARACTERp (mCHAR_INDEXxSTRING1, getCHARACTER (mS)),
                      putCHARACTERp (mCHAR_INDEXxSTRING2,
                                     cToDescriptor (NULL, "??")),
                      CHAR_INDEX (0)));
                  putFIXED (mK, numberRHS);
                }
                // IF K >= 0 THEN (2160)
                if (1 & (xGE (getFIXED (mK), 0)))
                  // DO; (2161)
                  {
                  rs1s4s1s1:;
                    // IF K = 0 THEN (2162)
                    if (1 & (xEQ (getFIXED (mK), 0)))
                      // S = C || SUBSTR(S, 2); (2163)
                      {
                        descriptor_t *stringRHS;
                        stringRHS = xsCAT (
                            getCHARACTER (mOUTPUT_WRITERxERROR_PRINTxC),
                            SUBSTR2 (getCHARACTER (mS), 2));
                        putCHARACTER (mS, stringRHS);
                        stringRHS->inUse = 0;
                      }
                    // ELSE (2164)
                    else
                      // S = SUBSTR(S, 0, K) || C || SUBSTR(S, K + 2); (2165)
                      {
                        descriptor_t *stringRHS;
                        stringRHS = xsCAT (
                            xsCAT (
                                SUBSTR (getCHARACTER (mS), 0, getFIXED (mK)),
                                getCHARACTER (mOUTPUT_WRITERxERROR_PRINTxC)),
                            SUBSTR2 (getCHARACTER (mS),
                                     xadd (getFIXED (mK), 2)));
                        putCHARACTER (mS, stringRHS);
                        stringRHS->inUse = 0;
                      }
                    // IMBEDDING = FALSE; (2166)
                    {
                      int32_t numberRHS = (int32_t)(0);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (1, mOUTPUT_WRITERxIMBEDDING, bitRHS);
                      bitRHS->inUse = 0;
                    }
                  es1s4s1s1:;
                  } // End of DO block
              es1s4s1:;
              } // End of DO block
            // OUTPUT = STARS || X1 || S; (2167)
            {
              descriptor_t *stringRHS;
              stringRHS
                  = xsCAT (xsCAT (getCHARACTER (mSTARS), getCHARACTER (mX1)),
                           getCHARACTER (mS));
              OUTPUT (0, stringRHS);
              stringRHS->inUse = 0;
            }
            // S = INPUT(5); (2168)
            {
              descriptor_t *stringRHS;
              stringRHS = INPUT (5);
              putCHARACTER (mS, stringRHS);
              stringRHS->inUse = 0;
            }
          } // End of DO WHILE block
      // ERROR_PRINT_END: (2169)
      ERROR_PRINT_END:;
      }
  } // End of DO for-loop block
  // LAST_ERROR_WRITTEN = CURRENT_ERROR_PTR; (2170)
  {
    descriptor_t *bitRHS = getBIT (16, mOUTPUT_WRITERxCURRENT_ERROR_PTR);
    putBIT (16, mOUTPUT_WRITERxLAST_ERROR_WRITTEN, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
