/*
  File DOWNGRADE_SUMMARY.c generated by XCOM-I, 2024-08-09 12:41:08.
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
  // END_OF_LIST = 0; (871)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mDOWNGRADE_SUMMARYxEND_OF_LIST, bitRHS);
    bitRHS->inUse = 0;
  }
  // NOT_DOWNGRADED = 0; (872)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mNOT_DOWNGRADED, bitRHS);
    bitRHS->inUse = 0;
  }
  // DOWN_COUNT = 1; (873)
  {
    int32_t numberRHS = (int32_t)(1);
    putFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT, numberRHS);
  }
  // IF RECORD_TOP(DOWN_INFO) >= 1 THEN (874)
  if (1
      & (xGE (xsubtract (COREWORD (xadd (
                             ADDR ("DOWN_INFO", 0x80000000, NULL, 0), 12)),
                         1),
              1)))
    // DO; (875)
    {
    rs1:;
      // OUTPUT = ' '; (876)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, " ");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = ' '; (877)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, " ");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = ' '; (878)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, " ");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = ' **********  DOWNGRADE SUMMARY   *********************';
      // (879)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (
            NULL, " **********  DOWNGRADE SUMMARY   *********************");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = ' '; (880)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, " ");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = ' '; (881)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, " ");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // DO WHILE END_OF_LIST = 0 & DOWN_COUNT < = RECORD_TOP(DOWN_INFO); (882)
      while (
          1
          & (xAND (xEQ (BYTE0 (mDOWNGRADE_SUMMARYxEND_OF_LIST), 0),
                   xLE (getFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT),
                        xsubtract (
                            COREWORD (xadd (
                                ADDR ("DOWN_INFO", 0x80000000, NULL, 0), 12)),
                            1)))))
        {
          // IF DWN_ERR(DOWN_COUNT) > ' ' THEN (883)
          if (1
              & (xsGT (getCHARACTER (
                           getFIXED (mDOWN_INFO)
                           + 20 * (getFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT))
                           + 4 + 4 * (0)),
                       cToDescriptor (NULL, " "))))
            // DO; (884)
            {
            rs1s1s1:;
              // IF DWN_VER(DOWN_COUNT) = 1 THEN (885)
              if (1
                  & (xsEQ (
                      getCHARACTER (
                          getFIXED (mDOWN_INFO)
                          + 20 * (getFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT))
                          + 16 + 4 * (0)),
                      fixedToCharacter (1))))
                // DO; (886)
                {
                rs1s1s1s1:;
                  // SEARCH_FOR_CLS = 1; (887)
                  {
                    int32_t numberRHS = (int32_t)(1);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (1, mDOWNGRADE_SUMMARYxSEARCH_FOR_CLS, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // COUNT = 0; (888)
                  {
                    int32_t numberRHS = (int32_t)(0);
                    putFIXED (mDOWNGRADE_SUMMARYxCOUNT, numberRHS);
                  }
                  // DO WHILE SEARCH_FOR_CLS = 1; (889)
                  while (
                      1 & (xEQ (BYTE0 (mDOWNGRADE_SUMMARYxSEARCH_FOR_CLS), 1)))
                    {
                      // IF DWN_CLS(DOWN_COUNT) = ERR_VALUE(COUNT) THEN (890)
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
                        // DO; (891)
                        {
                        rs1s1s1s1s1s1:;
                          // TEMP_CLS = SUBSTR(ERROR_INDEX(COUNT),6,2); (892)
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
                          // SEARCH_FOR_CLS = 0; (893)
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
                      // ELSE (894)
                      else
                        // DO; (895)
                        {
                        rs1s1s1s1s1s2:;
                          // COUNT = COUNT + 1; (896)
                          {
                            int32_t numberRHS = (int32_t)(xadd (
                                getFIXED (mDOWNGRADE_SUMMARYxCOUNT), 1));
                            putFIXED (mDOWNGRADE_SUMMARYxCOUNT, numberRHS);
                          }
                        es1s1s1s1s1s2:;
                        } // End of DO block
                    }     // End of DO WHILE block
                  // TEMP1 = SUBSTR(TEMP_CLS,0,1); (897)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = SUBSTR (
                        getCHARACTER (mDOWNGRADE_SUMMARYxTEMP_CLS), 0, 1);
                    putCHARACTER (mDOWNGRADE_SUMMARYxTEMP1, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // TEMP2 = SUBSTR(TEMP_CLS,1,1); (898)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = SUBSTR (
                        getCHARACTER (mDOWNGRADE_SUMMARYxTEMP_CLS), 1, 1);
                    putCHARACTER (mDOWNGRADE_SUMMARYxTEMP2, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // IF TEMP2 = ' ' THEN (899)
                  if (1
                      & (xsEQ (getCHARACTER (mDOWNGRADE_SUMMARYxTEMP2),
                               cToDescriptor (NULL, " "))))
                    // TEMP3 = TEMP1 || DWN_ERR(DOWN_COUNT); (900)
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
                  // ELSE (901)
                  else
                    // TEMP3 = TEMP_CLS || DWN_ERR(DOWN_COUNT); (902)
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
                  // NUMBER '|| DWN_STMT(DOWN_COUNT) || ' ***'; (903)
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
                  // || ' A SEVERITY ZERO ERROR MESSAGE ***'; (904)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = cToDescriptor (
                        NULL, "*** WAS DOWNGRADED FROM A SEVERITY ONE ERROR "
                              "TO A SEVERITY ZERO ERROR MESSAGE ***");
                    OUTPUT (0, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // OUTPUT = '  '; (905)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = cToDescriptor (NULL, "  ");
                    OUTPUT (0, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // OUTPUT = '  '; (906)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = cToDescriptor (NULL, "  ");
                    OUTPUT (0, stringRHS);
                    stringRHS->inUse = 0;
                  }
                es1s1s1s1:;
                } // End of DO block
              // ELSE (907)
              else
                // NOT_DOWNGRADED = 1; (908)
                {
                  int32_t numberRHS = (int32_t)(1);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (1, mNOT_DOWNGRADED, bitRHS);
                  bitRHS->inUse = 0;
                }
            es1s1s1:;
            } // End of DO block
          // ELSE (909)
          else
            // DO; (910)
            {
            rs1s1s2:;
              // END_OF_LIST = 1; (911)
              {
                int32_t numberRHS = (int32_t)(1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (1, mDOWNGRADE_SUMMARYxEND_OF_LIST, bitRHS);
                bitRHS->inUse = 0;
              }
            es1s1s2:;
            } // End of DO block
          // DOWN_COUNT = DOWN_COUNT + 1; (912)
          {
            int32_t numberRHS = (int32_t)(xadd (
                getFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT), 1));
            putFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT, numberRHS);
          }
        } // End of DO WHILE block
      // IF NOT_DOWNGRADED THEN (913)
      if (1 & (bitToFixed (getBIT (1, mNOT_DOWNGRADED))))
        // DO; (914)
        {
        rs1s2:;
          // OUTPUT = '  '; (915)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (NULL, "  ");
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
          // OUTPUT = '  '; (916)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (NULL, "  ");
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
          // OUTPUT = '*****  DOWNGRADE DIRECTIVES THAT WERE NOT DOWNGRADED
          // *****'; (917)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (
                NULL,
                "*****  DOWNGRADE DIRECTIVES THAT WERE NOT DOWNGRADED *****");
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
          // OUTPUT = '  '; (918)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (NULL, "  ");
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
          // OUTPUT = '  '; (919)
          {
            descriptor_t *stringRHS;
            stringRHS = cToDescriptor (NULL, "  ");
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
          // DO I = 1 TO RECORD_TOP(DOWN_INFO); (920)
          {
            int32_t from22, to22, by22;
            from22 = 1;
            to22 = xsubtract (
                COREWORD (xadd (ADDR ("DOWN_INFO", 0x80000000, NULL, 0), 12)),
                1);
            by22 = 1;
            for (putFIXED (mDOWNGRADE_SUMMARYxI, from22);
                 getFIXED (mDOWNGRADE_SUMMARYxI) <= to22;
                 putFIXED (mDOWNGRADE_SUMMARYxI,
                           getFIXED (mDOWNGRADE_SUMMARYxI) + by22))
              {
                // IF DWN_VER(I) ~= 1 THEN (921)
                if (1
                    & (xsNEQ (
                        getCHARACTER (getFIXED (mDOWN_INFO)
                                      + 20 * (getFIXED (mDOWNGRADE_SUMMARYxI))
                                      + 16 + 4 * (0)),
                        fixedToCharacter (1))))
                  // DO; (922)
                  {
                  rs1s2s1s1:;
                    // DOWN_COUNT = I; (923)
                    {
                      int32_t numberRHS
                          = (int32_t)(getFIXED (mDOWNGRADE_SUMMARYxI));
                      putFIXED (mDOWNGRADE_SUMMARYxDOWN_COUNT, numberRHS);
                    }
                    // SEARCH_FOR_CLS = 1; (924)
                    {
                      int32_t numberRHS = (int32_t)(1);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (1, mDOWNGRADE_SUMMARYxSEARCH_FOR_CLS, bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // COUNT = 0; (925)
                    {
                      int32_t numberRHS = (int32_t)(0);
                      putFIXED (mDOWNGRADE_SUMMARYxCOUNT, numberRHS);
                    }
                    // IF DWN_UNKN(I) ~= '' THEN (926)
                    if (1
                        & (xsNEQ (getCHARACTER (
                                      getFIXED (mDOWN_INFO)
                                      + 20 * (getFIXED (mDOWNGRADE_SUMMARYxI))
                                      + 12 + 4 * (0)),
                                  cToDescriptor (NULL, ""))))
                      // DO; (927)
                      {
                      rs1s2s1s1s1:;
                        // TEMP3 = DWN_UNKN(I); (928)
                        {
                          descriptor_t *stringRHS;
                          stringRHS = getCHARACTER (
                              getFIXED (mDOWN_INFO)
                              + 20 * (getFIXED (mDOWNGRADE_SUMMARYxI)) + 12
                              + 4 * (0));
                          putCHARACTER (mDOWNGRADE_SUMMARYxTEMP3, stringRHS);
                          stringRHS->inUse = 0;
                        }
                        // GOTO PRINT_ERR_MSG; (929)
                        goto PRINT_ERR_MSG;
                      es1s2s1s1s1:;
                      } // End of DO block
                    // ELSE (930)
                    else
                      // DO WHILE SEARCH_FOR_CLS = 1; (931)
                      while (1
                             & (xEQ (BYTE0 (mDOWNGRADE_SUMMARYxSEARCH_FOR_CLS),
                                     1)))
                        {
                          // IF DWN_CLS(DOWN_COUNT) = ERR_VALUE(COUNT) THEN
                          // (932)
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
                            // DO; (933)
                            {
                            rs1s2s1s1s2s1:;
                              // TEMP_CLS = SUBSTR(ERROR_INDEX(COUNT),6,2);
                              // (934)
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
                              // SEARCH_FOR_CLS = 0; (935)
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
                          // ELSE (936)
                          else
                            // DO; (937)
                            {
                            rs1s2s1s1s2s2:;
                              // COUNT = COUNT + 1; (938)
                              {
                                int32_t numberRHS = (int32_t)(xadd (
                                    getFIXED (mDOWNGRADE_SUMMARYxCOUNT), 1));
                                putFIXED (mDOWNGRADE_SUMMARYxCOUNT, numberRHS);
                              }
                            es1s2s1s1s2s2:;
                            } // End of DO block
                        }     // End of DO WHILE block
                    // TEMP1 = SUBSTR(TEMP_CLS,0,1); (939)
                    {
                      descriptor_t *stringRHS;
                      stringRHS = SUBSTR (
                          getCHARACTER (mDOWNGRADE_SUMMARYxTEMP_CLS), 0, 1);
                      putCHARACTER (mDOWNGRADE_SUMMARYxTEMP1, stringRHS);
                      stringRHS->inUse = 0;
                    }
                    // TEMP2 = SUBSTR(TEMP_CLS,1,1); (940)
                    {
                      descriptor_t *stringRHS;
                      stringRHS = SUBSTR (
                          getCHARACTER (mDOWNGRADE_SUMMARYxTEMP_CLS), 1, 1);
                      putCHARACTER (mDOWNGRADE_SUMMARYxTEMP2, stringRHS);
                      stringRHS->inUse = 0;
                    }
                    // IF TEMP2 = ' ' THEN (941)
                    if (1
                        & (xsEQ (getCHARACTER (mDOWNGRADE_SUMMARYxTEMP2),
                                 cToDescriptor (NULL, " "))))
                      // TEMP3 = TEMP1 || DWN_ERR(DOWN_COUNT); (942)
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
                    // ELSE (943)
                    else
                      // TEMP3 = TEMP_CLS || DWN_ERR(DOWN_COUNT); (944)
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
                  // PRINT_ERR_MSG: (945)
                  PRINT_ERR_MSG:
                    // OUTPUT = '*** ERROR NUMBER ' || TEMP3 || ' FOR STATEMENT
                    // NUMBER ' || DWN_STMT(DOWN_COUNT) || ' WAS NOT
                    // DOWNGRADED, REMOVE DOWNGRADE' || ' DIRECTIVE AND
                    // RECOMPILE *** '; (946)
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
                    // OUTPUT = '  '; (947)
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
