/*
  File DOWNGRADE_SUMMARY.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
DOWNGRADE_SUMMARY (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "DOWNGRADE_SUMMARY");
  // END_OF_LIST = 0; (1184)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mDOWNGRADE_SUMMARYxEND_OF_LIST, bitRHS);
    bitRHS->inUse = 0;
  }
  // NOT_DOWNGRADED = 0; (1185)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mNOT_DOWNGRADED, bitRHS);
    bitRHS->inUse = 0;
  }
  // DOWN_COUNT = 1; (1186)
  {
    int32_t numberRHS = (int32_t)(1);
    putFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT, numberRHS);
  }
  // IF RECORD_TOP(DOWN_INFO) >= 1 THEN (1187)
  if (1
      & (xGE (xsubtract (COREWORD (xadd (
                             ADDR ("DOWN_INFO", 0x80000000, NULL, 0), 12)),
                         1),
              1)))
    // DO; (1188)
    {
    rs1:;
      // OUTPUT = ' '; (1189)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, " ");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = ' '; (1190)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, " ");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = ' '; (1191)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, " ");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = ' **********  DOWNGRADE SUMMARY   *********************';
      // (1192)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (
            NULL, " **********  DOWNGRADE SUMMARY   *********************");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = ' '; (1193)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, " ");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = ' '; (1194)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, " ");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // DO WHILE END_OF_LIST = 0 & DOWN_COUNT < = RECORD_TOP(DOWN_INFO);
      // (1195)
      while (
          1
          & (xAND (xEQ (BYTE0 (mDOWNGRADE_SUMMARYxEND_OF_LIST), 0),
                   xLE (getFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT),
                        xsubtract (
                            COREWORD (xadd (
                                ADDR ("DOWN_INFO", 0x80000000, NULL, 0), 12)),
                            1)))))
        {
          // IF DWN_ERR(DOWN_COUNT) > ' ' THEN (1196)
          if (1
              & (xsGT (getCHARACTER (
                           getFIXED (mDOWN_INFO)
                           + 20 * (getFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT))
                           + 4 + 4 * (0)),
                       cToDescriptor (NULL, " "))))
            // DO; (1197)
            {
            rs1s1s1:;
              // IF DWN_VER(DOWN_COUNT) = 1 THEN (1198)
              if (1
                  & (xsEQ (
                      getCHARACTER (
                          getFIXED (mDOWN_INFO)
                          + 20 * (getFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT))
                          + 16 + 4 * (0)),
                      fixedToCharacter (1))))
                // DO; (1199)
                {
                rs1s1s1s1:;
                  // SEARCH_FOR_CLS = 1; (1200)
                  {
                    int32_t numberRHS = (int32_t)(1);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (1, mDOWNGRADE_SUMMARYxSEARCH_FOR_CLS, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // COUNT = 0; (1201)
                  {
                    int32_t numberRHS = (int32_t)(0);
                    putFIXED (mDOWNGRADE_SUMMARYxCOUNT, numberRHS);
                  }
                  // DO WHILE SEARCH_FOR_CLS = 1; (1202)
                  while (
                      1 & (xEQ (BYTE0 (mDOWNGRADE_SUMMARYxSEARCH_FOR_CLS), 1)))
                    {
                      // IF DWN_CLS(DOWN_COUNT) = ERR_VALUE(COUNT) THEN (1203)
                      if (1
                          & (xsEQ (
                              getCHARACTER (
                                  getFIXED (mDOWN_INFO)
                                  + 20
                                        * (getFIXED (
                                            mDOWNGRADE_SUMMARYxDOWN_COUNT))
                                  + 8 + 4 * (0)),
                              fixedToCharacter (getFIXED (
                                  mERR_VALUE
                                  + 4
                                        * getFIXED (
                                            mDOWNGRADE_SUMMARYxCOUNT))))))
                        // DO; (1204)
                        {
                        rs1s1s1s1s1s1:;
                          // TEMP_CLS = SUBSTR(ERROR_INDEX(COUNT),6,2); (1205)
                          {
                            descriptor_t *stringRHS;
                            stringRHS = SUBSTR (
                                getCHARACTER (
                                    mERROR_INDEX
                                    + 4 * getFIXED (mDOWNGRADE_SUMMARYxCOUNT)),
                                6, 2);
                            putCHARACTER (mDOWNGRADE_SUMMARYxTEMP_CLS,
                                          stringRHS);
                            stringRHS->inUse = 0;
                          }
                          // SEARCH_FOR_CLS = 0; (1206)
                          {
                            int32_t numberRHS = (int32_t)(0);
                            descriptor_t *bitRHS;
                            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                            putBIT (1, mDOWNGRADE_SUMMARYxSEARCH_FOR_CLS,
                                    bitRHS);
                            bitRHS->inUse = 0;
                          }
                        es1s1s1s1s1s1:;
                        } // End of DO block
                      // ELSE (1207)
                      else
                        // DO; (1208)
                        {
                        rs1s1s1s1s1s2:;
                          // COUNT = COUNT + 1; (1209)
                          {
                            int32_t numberRHS = (int32_t)(xadd (
                                getFIXED (mDOWNGRADE_SUMMARYxCOUNT), 1));
                            putFIXED (mDOWNGRADE_SUMMARYxCOUNT, numberRHS);
                          }
                        es1s1s1s1s1s2:;
                        } // End of DO block
                    }     // End of DO WHILE block
                  // TEMP1 = SUBSTR(TEMP_CLS,0,1); (1210)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = SUBSTR (
                        getCHARACTER (mDOWNGRADE_SUMMARYxTEMP_CLS), 0, 1);
                    putCHARACTER (mDOWNGRADE_SUMMARYxTEMP1, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // TEMP2 = SUBSTR(TEMP_CLS,1,1); (1211)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = SUBSTR (
                        getCHARACTER (mDOWNGRADE_SUMMARYxTEMP_CLS), 1, 1);
                    putCHARACTER (mDOWNGRADE_SUMMARYxTEMP2, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // IF TEMP2 = ' ' THEN (1212)
                  if (1
                      & (xsEQ (getCHARACTER (mDOWNGRADE_SUMMARYxTEMP2),
                               cToDescriptor (NULL, " "))))
                    // TEMP3 = TEMP1 || DWN_ERR(DOWN_COUNT); (1213)
                    {
                      descriptor_t *stringRHS;
                      stringRHS = xsCAT (
                          getCHARACTER (mDOWNGRADE_SUMMARYxTEMP1),
                          getCHARACTER (
                              getFIXED (mDOWN_INFO)
                              + 20 * (getFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT))
                              + 4 + 4 * (0)));
                      putCHARACTER (mDOWNGRADE_SUMMARYxTEMP3, stringRHS);
                      stringRHS->inUse = 0;
                    }
                  // ELSE (1214)
                  else
                    // TEMP3 = TEMP_CLS || DWN_ERR(DOWN_COUNT); (1215)
                    {
                      descriptor_t *stringRHS;
                      stringRHS = xsCAT (
                          getCHARACTER (mDOWNGRADE_SUMMARYxTEMP_CLS),
                          getCHARACTER (
                              getFIXED (mDOWN_INFO)
                              + 20 * (getFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT))
                              + 4 + 4 * (0)));
                      putCHARACTER (mDOWNGRADE_SUMMARYxTEMP3, stringRHS);
                      stringRHS->inUse = 0;
                    }
                  // OUTPUT = '*** ERROR NUMBER ' || TEMP3||' AT STATEMENT
                  // NUMBER '|| DWN_STMT(DOWN_COUNT) || ' ***'; (1216)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = xsCAT (
                        xsCAT (
                            xsCAT (
                                xsCAT (
                                    cToDescriptor (NULL, "*** ERROR NUMBER "),
                                    getCHARACTER (mDOWNGRADE_SUMMARYxTEMP3)),
                                cToDescriptor (NULL, " AT STATEMENT NUMBER ")),
                            getCHARACTER (
                                getFIXED (mDOWN_INFO)
                                + 20
                                      * (getFIXED (
                                          mDOWNGRADE_SUMMARYxDOWN_COUNT))
                                + 0 + 4 * (0))),
                        cToDescriptor (NULL, " ***"));
                    OUTPUT (0, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // OUTPUT = '*** WAS DOWNGRADED FROM A SEVERITY ONE ERROR TO'
                  // || ' A SEVERITY ZERO ERROR MESSAGE ***'; (1217)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = cToDescriptor (
                        NULL, "*** WAS DOWNGRADED FROM A SEVERITY ONE ERROR "
                              "TO A SEVERITY ZERO ERROR MESSAGE ***");
                    OUTPUT (0, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // OUTPUT = '  '; (1218)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = cToDescriptor (NULL, "  ");
                    OUTPUT (0, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // OUTPUT = '  '; (1219)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = cToDescriptor (NULL, "  ");
                    OUTPUT (0, stringRHS);
                    stringRHS->inUse = 0;
                  }
                es1s1s1s1:;
                } // End of DO block
              // ELSE (1220)
              else
                // NOT_DOWNGRADED = 1; (1221)
                {
                  int32_t numberRHS = (int32_t)(1);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (1, mNOT_DOWNGRADED, bitRHS);
                  bitRHS->inUse = 0;
                }
            es1s1s1:;
            } // End of DO block
          // ELSE (1222)
          else
            // DO; (1223)
            {
            rs1s1s2:;
              // END_OF_LIST = 1; (1224)
              {
                int32_t numberRHS = (int32_t)(1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (1, mDOWNGRADE_SUMMARYxEND_OF_LIST, bitRHS);
                bitRHS->inUse = 0;
              }
            es1s1s2:;
            } // End of DO block
          // DOWN_COUNT = DOWN_COUNT + 1; (1225)
          {
            int32_t numberRHS = (int32_t)(xadd (
                getFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT), 1));
            putFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT, numberRHS);
          }
        } // End of DO WHILE block
      // IF NOT_DOWNGRADED THEN (1226)
      if (1 & (bitToFixed (getBIT (1, mNOT_DOWNGRADED))))
        // DO; (1227)
        {
        rs1s2:;
          // OUTPUT = '  '; (1228)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (NULL, "  ");
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
          // OUTPUT = '  '; (1229)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (NULL, "  ");
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
          // OUTPUT = '*****  DOWNGRADE DIRECTIVES THAT WERE NOT DOWNGRADED
          // *****'; (1230)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (
                NULL,
                "*****  DOWNGRADE DIRECTIVES THAT WERE NOT DOWNGRADED *****");
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
          // OUTPUT = '  '; (1231)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (NULL, "  ");
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
          // OUTPUT = '  '; (1232)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (NULL, "  ");
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
          // DO I = 1 TO RECORD_TOP(DOWN_INFO); (1233)
          {
            int32_t from25, to25, by25;
            from25 = 1;
            to25 = xsubtract (
                COREWORD (xadd (ADDR ("DOWN_INFO", 0x80000000, NULL, 0), 12)),
                1);
            by25 = 1;
            for (putFIXED (mDOWNGRADE_SUMMARYxI, from25);
                 getFIXED (mDOWNGRADE_SUMMARYxI) <= to25;
                 putFIXED (mDOWNGRADE_SUMMARYxI,
                           getFIXED (mDOWNGRADE_SUMMARYxI) + by25))
              {
                // IF DWN_VER(I) ~= 1 THEN (1234)
                if (1
                    & (xsNEQ (
                        getCHARACTER (getFIXED (mDOWN_INFO)
                                      + 20 * (getFIXED (mDOWNGRADE_SUMMARYxI))
                                      + 16 + 4 * (0)),
                        fixedToCharacter (1))))
                  // DO; (1235)
                  {
                  rs1s2s1s1:;
                    // DOWN_COUNT = I; (1236)
                    {
                      int32_t numberRHS
                          = (int32_t)(getFIXED (mDOWNGRADE_SUMMARYxI));
                      putFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT, numberRHS);
                    }
                    // SEARCH_FOR_CLS = 1; (1237)
                    {
                      int32_t numberRHS = (int32_t)(1);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (1, mDOWNGRADE_SUMMARYxSEARCH_FOR_CLS, bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // COUNT = 0; (1238)
                    {
                      int32_t numberRHS = (int32_t)(0);
                      putFIXED (mDOWNGRADE_SUMMARYxCOUNT, numberRHS);
                    }
                    // IF DWN_UNKN(I) ~= '' THEN (1239)
                    if (1
                        & (xsNEQ (getCHARACTER (
                                      getFIXED (mDOWN_INFO)
                                      + 20 * (getFIXED (mDOWNGRADE_SUMMARYxI))
                                      + 12 + 4 * (0)),
                                  cToDescriptor (NULL, ""))))
                      // DO; (1240)
                      {
                      rs1s2s1s1s1:;
                        // TEMP3 = DWN_UNKN(I); (1241)
                        {
                          descriptor_t *stringRHS;
                          stringRHS = getCHARACTER (
                              getFIXED (mDOWN_INFO)
                              + 20 * (getFIXED (mDOWNGRADE_SUMMARYxI)) + 12
                              + 4 * (0));
                          putCHARACTER (mDOWNGRADE_SUMMARYxTEMP3, stringRHS);
                          stringRHS->inUse = 0;
                        }
                        // GOTO PRINT_ERR_MSG; (1242)
                        goto PRINT_ERR_MSG;
                      es1s2s1s1s1:;
                      } // End of DO block
                    // ELSE (1243)
                    else
                      // DO WHILE SEARCH_FOR_CLS = 1; (1244)
                      while (1
                             & (xEQ (BYTE0 (mDOWNGRADE_SUMMARYxSEARCH_FOR_CLS),
                                     1)))
                        {
                          // IF DWN_CLS(DOWN_COUNT) = ERR_VALUE(COUNT) THEN
                          // (1245)
                          if (1
                              & (xsEQ (
                                  getCHARACTER (
                                      getFIXED (mDOWN_INFO)
                                      + 20
                                            * (getFIXED (
                                                mDOWNGRADE_SUMMARYxDOWN_COUNT))
                                      + 8 + 4 * (0)),
                                  fixedToCharacter (getFIXED (
                                      mERR_VALUE
                                      + 4
                                            * getFIXED (
                                                mDOWNGRADE_SUMMARYxCOUNT))))))
                            // DO; (1246)
                            {
                            rs1s2s1s1s2s1:;
                              // TEMP_CLS = SUBSTR(ERROR_INDEX(COUNT),6,2);
                              // (1247)
                              {
                                descriptor_t *stringRHS;
                                stringRHS = SUBSTR (
                                    getCHARACTER (
                                        mERROR_INDEX
                                        + 4
                                              * getFIXED (
                                                  mDOWNGRADE_SUMMARYxCOUNT)),
                                    6, 2);
                                putCHARACTER (mDOWNGRADE_SUMMARYxTEMP_CLS,
                                              stringRHS);
                                stringRHS->inUse = 0;
                              }
                              // SEARCH_FOR_CLS = 0; (1248)
                              {
                                int32_t numberRHS = (int32_t)(0);
                                descriptor_t *bitRHS;
                                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                                putBIT (1, mDOWNGRADE_SUMMARYxSEARCH_FOR_CLS,
                                        bitRHS);
                                bitRHS->inUse = 0;
                              }
                            es1s2s1s1s2s1:;
                            } // End of DO block
                          // ELSE (1249)
                          else
                            // DO; (1250)
                            {
                            rs1s2s1s1s2s2:;
                              // COUNT = COUNT + 1; (1251)
                              {
                                int32_t numberRHS = (int32_t)(xadd (
                                    getFIXED (mDOWNGRADE_SUMMARYxCOUNT), 1));
                                putFIXED (mDOWNGRADE_SUMMARYxCOUNT, numberRHS);
                              }
                            es1s2s1s1s2s2:;
                            } // End of DO block
                        }     // End of DO WHILE block
                    // TEMP1 = SUBSTR(TEMP_CLS,0,1); (1252)
                    {
                      descriptor_t *stringRHS;
                      stringRHS = SUBSTR (
                          getCHARACTER (mDOWNGRADE_SUMMARYxTEMP_CLS), 0, 1);
                      putCHARACTER (mDOWNGRADE_SUMMARYxTEMP1, stringRHS);
                      stringRHS->inUse = 0;
                    }
                    // TEMP2 = SUBSTR(TEMP_CLS,1,1); (1253)
                    {
                      descriptor_t *stringRHS;
                      stringRHS = SUBSTR (
                          getCHARACTER (mDOWNGRADE_SUMMARYxTEMP_CLS), 1, 1);
                      putCHARACTER (mDOWNGRADE_SUMMARYxTEMP2, stringRHS);
                      stringRHS->inUse = 0;
                    }
                    // IF TEMP2 = ' ' THEN (1254)
                    if (1
                        & (xsEQ (getCHARACTER (mDOWNGRADE_SUMMARYxTEMP2),
                                 cToDescriptor (NULL, " "))))
                      // TEMP3 = TEMP1 || DWN_ERR(DOWN_COUNT); (1255)
                      {
                        descriptor_t *stringRHS;
                        stringRHS = xsCAT (
                            getCHARACTER (mDOWNGRADE_SUMMARYxTEMP1),
                            getCHARACTER (
                                getFIXED (mDOWN_INFO)
                                + 20
                                      * (getFIXED (
                                          mDOWNGRADE_SUMMARYxDOWN_COUNT))
                                + 4 + 4 * (0)));
                        putCHARACTER (mDOWNGRADE_SUMMARYxTEMP3, stringRHS);
                        stringRHS->inUse = 0;
                      }
                    // ELSE (1256)
                    else
                      // TEMP3 = TEMP_CLS || DWN_ERR(DOWN_COUNT); (1257)
                      {
                        descriptor_t *stringRHS;
                        stringRHS = xsCAT (
                            getCHARACTER (mDOWNGRADE_SUMMARYxTEMP_CLS),
                            getCHARACTER (
                                getFIXED (mDOWN_INFO)
                                + 20
                                      * (getFIXED (
                                          mDOWNGRADE_SUMMARYxDOWN_COUNT))
                                + 4 + 4 * (0)));
                        putCHARACTER (mDOWNGRADE_SUMMARYxTEMP3, stringRHS);
                        stringRHS->inUse = 0;
                      }
                  // PRINT_ERR_MSG: (1258)
                  PRINT_ERR_MSG:
                    // OUTPUT = '*** ERROR NUMBER ' || TEMP3 || ' FOR STATEMENT
                    // NUMBER ' || DWN_STMT(DOWN_COUNT) || ' WAS NOT
                    // DOWNGRADED, REMOVE DOWNGRADE' || ' DIRECTIVE AND
                    // RECOMPILE *** '; (1259)
                    {
                      descriptor_t *stringRHS;
                      stringRHS = xsCAT (
                          xsCAT (
                              xsCAT (
                                  xsCAT (xsCAT (cToDescriptor (
                                                    NULL, "*** ERROR NUMBER "),
                                                getCHARACTER (
                                                    mDOWNGRADE_SUMMARYxTEMP3)),
                                         cToDescriptor (
                                             NULL, " FOR STATEMENT NUMBER ")),
                                  getCHARACTER (
                                      getFIXED (mDOWN_INFO)
                                      + 20
                                            * (getFIXED (
                                                mDOWNGRADE_SUMMARYxDOWN_COUNT))
                                      + 0 + 4 * (0))),
                              cToDescriptor (
                                  NULL,
                                  " WAS NOT DOWNGRADED, REMOVE DOWNGRADE")),
                          cToDescriptor (NULL,
                                         " DIRECTIVE AND RECOMPILE *** "));
                      OUTPUT (0, stringRHS);
                      stringRHS->inUse = 0;
                    }
                    // OUTPUT = '  '; (1260)
                    {
                      descriptor_t *stringRHS;
                      stringRHS = cToDescriptor (NULL, "  ");
                      OUTPUT (0, stringRHS);
                      stringRHS->inUse = 0;
                    }
                  es1s2s1s1:;
                  } // End of DO block
              }
          } // End of DO for-loop block
        es1s2:;
        } // End of DO block
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
