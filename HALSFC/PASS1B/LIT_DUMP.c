/*
  File LIT_DUMP.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
LIT_DUMP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "LIT_DUMP");
  // IF LIT_TOP = 0 THEN (5977)
  if (1 & (xEQ (getFIXED (mCOMM + 4 * 2), 0)))
    // RETURN; (5978)
    {
      reentryGuard = 0;
      return 0;
    }
  // OUTPUT(1) = '0L I T E R A L   T A B L E   D U M P:'; (5979)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "0L I T E R A L   T A B L E   D U M P:");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1)='0 LOC  TYPE          LITERAL'; (5980)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "0 LOC  TYPE          LITERAL");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = X1; (5981)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mX1);
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // DO I = 1 TO LIT_TOP; (5982)
  {
    int32_t from99, to99, by99;
    from99 = 1;
    to99 = getFIXED (mCOMM + 4 * 2);
    by99 = 1;
    for (putFIXED (mI, from99); getFIXED (mI) <= to99;
         putFIXED (mI, getFIXED (mI) + by99))
      {
        // TEMP = GET_LITERAL(I); (5983)
        {
          int32_t numberRHS = (int32_t)((
              putFIXED (mGET_LITERALxPTR, getFIXED (mI)), GET_LITERAL (0)));
          putFIXED (mLIT_DUMPxTEMP, numberRHS);
        }
        // DO CASE (LIT1(TEMP) &  3); (5984)
        {
        rs1s1:
          switch (xAND (getFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 0
                                  + 4 * (getFIXED (mLIT_DUMPxTEMP))),
                        3))
            {
            case 0:
              // DO; (5986)
              {
              rs1s1s1:;
                // S=STRING(LIT2(TEMP)); (5986)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = getCHARACTER (getFIXED (mLIT_PG) + 1560 * (0) + 520
                                      + 4 * (getFIXED (mLIT_DUMPxTEMP)));
                  putCHARACTER (mLIT_DUMPxS, stringRHS);
                  stringRHS->inUse = 0;
                }
                // IF LENGTH(S)>100 THEN (5987)
                if (1 & (xGT (LENGTH (getCHARACTER (mLIT_DUMPxS)), 100)))
                  // S=SUBSTR(S,0,100); (5988)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = SUBSTR (getCHARACTER (mLIT_DUMPxS), 0, 100);
                    putCHARACTER (mLIT_DUMPxS, stringRHS);
                    stringRHS->inUse = 0;
                  }
              es1s1s1:;
              } // End of DO block
              break;
            case 1:
              // DO; (5990)
              {
              rs1s1s2:;
                // S=HEX(LIT3(TEMP)); (5990)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = (putFIXED (
                             mHEXxNUM,
                             getFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 1040
                                       + 4 * (getFIXED (mLIT_DUMPxTEMP)))),
                         HEX (0));
                  putCHARACTER (mLIT_DUMPxS, stringRHS);
                  stringRHS->inUse = 0;
                }
                // IF LENGTH(S)<8 THEN (5991)
                if (1 & (xLT (LENGTH (getCHARACTER (mLIT_DUMPxS)), 8)))
                  // S=SUBSTR(ZEROS,LENGTH(S))||S; (5992)
                  {
                    descriptor_t *stringRHS;
                    stringRHS
                        = xsCAT (SUBSTR2 (getCHARACTER (mLIT_DUMPxZEROS),
                                          LENGTH (getCHARACTER (mLIT_DUMPxS))),
                                 getCHARACTER (mLIT_DUMPxS));
                    putCHARACTER (mLIT_DUMPxS, stringRHS);
                    stringRHS->inUse = 0;
                  }
                // S=HEX(LIT2(TEMP))||S; (5993)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (
                      (putFIXED (mHEXxNUM,
                                 getFIXED (getFIXED (mLIT_PG) + 1560 * (0)
                                           + 520
                                           + 4 * (getFIXED (mLIT_DUMPxTEMP)))),
                       HEX (0)),
                      getCHARACTER (mLIT_DUMPxS));
                  putCHARACTER (mLIT_DUMPxS, stringRHS);
                  stringRHS->inUse = 0;
                }
                // IF LENGTH(S)<16 THEN (5994)
                if (1 & (xLT (LENGTH (getCHARACTER (mLIT_DUMPxS)), 16)))
                  // S=SUBSTR(ZEROS,LENGTH(S)-8)||S; (5995)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = xsCAT (
                        SUBSTR2 (getCHARACTER (mLIT_DUMPxZEROS),
                                 xsubtract (
                                     LENGTH (getCHARACTER (mLIT_DUMPxS)), 8)),
                        getCHARACTER (mLIT_DUMPxS));
                    putCHARACTER (mLIT_DUMPxS, stringRHS);
                    stringRHS->inUse = 0;
                  }
              es1s1s2:;
              } // End of DO block
              break;
            case 2:
              // DO; (5997)
              {
              rs1s1s3:;
                // S=HEX(LIT2(TEMP)); (5997)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = (putFIXED (
                             mHEXxNUM,
                             getFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 520
                                       + 4 * (getFIXED (mLIT_DUMPxTEMP)))),
                         HEX (0));
                  putCHARACTER (mLIT_DUMPxS, stringRHS);
                  stringRHS->inUse = 0;
                }
                // IF LENGTH(S)<8 THEN (5998)
                if (1 & (xLT (LENGTH (getCHARACTER (mLIT_DUMPxS)), 8)))
                  // S=SUBSTR(ZEROS,LENGTH(S))||S; (5999)
                  {
                    descriptor_t *stringRHS;
                    stringRHS
                        = xsCAT (SUBSTR2 (getCHARACTER (mLIT_DUMPxZEROS),
                                          LENGTH (getCHARACTER (mLIT_DUMPxS))),
                                 getCHARACTER (mLIT_DUMPxS));
                    putCHARACTER (mLIT_DUMPxS, stringRHS);
                    stringRHS->inUse = 0;
                  }
                // S=S||' ('||LIT3(TEMP)||')'; (6000)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (
                      xsCAT (xsCAT (getCHARACTER (mLIT_DUMPxS),
                                    cToDescriptor (NULL, " (")),
                             fixedToCharacter (getFIXED (
                                 getFIXED (mLIT_PG) + 1560 * (0) + 1040
                                 + 4 * (getFIXED (mLIT_DUMPxTEMP))))),
                      cToDescriptor (NULL, ")"));
                  putCHARACTER (mLIT_DUMPxS, stringRHS);
                  stringRHS->inUse = 0;
                }
              es1s1s3:;
              } // End of DO block
              break;
            }
        } // End of DO CASE block
        // OUTPUT=I_FORMAT(I,4)||SUBSTR(T,SHL(LIT1(TEMP),3),8)||S; (6001)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              xsCAT ((putFIXED (mI_FORMATxNUMBER, getFIXED (mI)),
                      putFIXED (mI_FORMATxWIDTH, 4), I_FORMAT (0)),
                     SUBSTR (getCHARACTER (mLIT_DUMPxT),
                             SHL (getFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 0
                                            + 4 * (getFIXED (mLIT_DUMPxTEMP))),
                                  3),
                             8)),
              getCHARACTER (mLIT_DUMPxS));
          OUTPUT (0, stringRHS);
          stringRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  // DOUBLE_SPACE; (6002)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mDOUBLE);
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
