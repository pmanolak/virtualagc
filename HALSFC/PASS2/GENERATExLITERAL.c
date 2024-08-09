/*
  File GENERATExLITERAL.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExLITERAL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExLITERAL");
  // IF PTR < 0 THEN (3704)
  if (1 & (xLT (COREHALFWORD (mGENERATExLITERALxPTR), 0)))
    // RETURN; (3705)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF LTYPE=CHAR THEN (3706)
  if (1 & (xEQ (COREHALFWORD (mGENERATExLITERALxLTYPE), BYTE0 (mCHAR))))
    // DO; (3707)
    {
    rs1:;
      // IF TAG1=VAC & ((TYPE(STACK) & 8)=8) THEN (3708)
      if (1
          & (xAND (
              xEQ (COREHALFWORD (mTAG1), BYTE0 (mVAC)),
              xEQ (xAND (COREHALFWORD (
                             getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK))
                             + 50 + 2 * (0)),
                         8),
                   8))))
        // DOUBLEFLAG = TRUE; (3709)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (1, mDOUBLEFLAG, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (3710)
      else
        // DOUBLEFLAG = FALSE; (3711)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (1, mDOUBLEFLAG, bitRHS);
          bitRHS->inUse = 0;
        }
    es1:;
    } // End of DO block
  // TYPE(STACK) = LTYPE; (3712)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExLITERALxLTYPE);
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK)) + 50 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // PTR=GET_LITERAL(PTR); (3713)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (mGET_LITERALxPTR, COREHALFWORD (mGENERATExLITERALxPTR)),
        GET_LITERAL (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExLITERALxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF LTYPE=CHAR THEN (3714)
  if (1 & (xEQ (COREHALFWORD (mGENERATExLITERALxLTYPE), BYTE0 (mCHAR))))
    // DO; (3715)
    {
    rs2:;
      // DO CASE (LIT1(PTR) &  3); (3716)
      {
      rs2s1:
        switch (xAND (getFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 0
                                + 4 * (COREHALFWORD (mGENERATExLITERALxPTR))),
                      3))
          {
          case 0:
            // DO; (3718)
            {
            rs2s1s1:;
              // VAL(STACK) = LIT2(PTR); (3718)
              {
                int32_t numberRHS = (int32_t)(getFIXED (
                    getFIXED (mLIT_PG) + 1560 * (0) + 520
                    + 4 * (COREHALFWORD (mGENERATExLITERALxPTR))));
                putFIXED (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK))
                              + 12 + 4 * (0),
                          numberRHS);
              }
            es2s1s1:;
            } // End of DO block
            break;
          case 1:
            // DO; (3720)
            {
            rs2s1s2:;
              // DW(0)=LIT2(PTR); (3720)
              {
                int32_t numberRHS = (int32_t)(getFIXED (
                    getFIXED (mLIT_PG) + 1560 * (0) + 520
                    + 4 * (COREHALFWORD (mGENERATExLITERALxPTR))));
                putFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0 + 4 * (0),
                          numberRHS);
              }
              // DW(1) = LIT3(PTR); (3721)
              {
                int32_t numberRHS = (int32_t)(getFIXED (
                    getFIXED (mLIT_PG) + 1560 * (0) + 1040
                    + 4 * (COREHALFWORD (mGENERATExLITERALxPTR))));
                putFIXED (getFIXED (mFOR_DW) + 4 * (1) + 0 + 4 * (0),
                          numberRHS);
              }
              // IF (CLASS = INTEGER) | (TAG3 = INTEGER) THEN (3722)
              if (1
                  & (xOR (xEQ (COREHALFWORD (mCLASS), BYTE0 (mINTEGER)),
                          xEQ (COREHALFWORD (mTAG3), BYTE0 (mINTEGER)))))
                // DO; (3723)
                {
                rs2s1s2s1:;
                  // IF ~INTEGERIZABLE THEN (3724)
                  if (1 & (xNOT (GENERATExINTEGERIZABLE (0))))
                    // GO TO SCALAR_CHAR; (3725)
                    goto SCALAR_CHAR;
                  // STR = DW(3); (3726)
                  {
                    int32_t numberRHS = (int32_t)(getFIXED (
                        getFIXED (mFOR_DW) + 4 * (3) + 0 + 4 * (0)));
                    descriptor_t *stringRHS;
                    stringRHS = fixedToCharacter (numberRHS);
                    putCHARACTER (mGENERATExLITERALxSTR, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // VAL(STACK) = ENTER_CHAR_LIT(STR); (3727)
                  {
                    int32_t numberRHS = (int32_t)((
                        putCHARACTERp (mGENERATExENTER_CHAR_LITxSTR,
                                       getCHARACTER (mGENERATExLITERALxSTR)),
                        GENERATExENTER_CHAR_LIT (0)));
                    putFIXED (
                        getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK))
                            + 12 + 4 * (0),
                        numberRHS);
                  }
                es2s1s2s1:;
                } // End of DO block
              // ELSE (3728)
              else
                // DO; (3729)
                {
                rs2s1s2s2:;
                // SCALAR_CHAR: (3730)
                SCALAR_CHAR:
                  // IF LIT1(PTR) = 5 THEN (3731)
                  if (1
                      & (xEQ (
                          getFIXED (
                              getFIXED (mLIT_PG) + 1560 * (0) + 0
                              + 4 * (COREHALFWORD (mGENERATExLITERALxPTR))),
                          5)))
                    // DOUBLEFLAG = TRUE; (3732)
                    {
                      int32_t numberRHS = (int32_t)(1);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (1, mDOUBLEFLAG, bitRHS);
                      bitRHS->inUse = 0;
                    }
                  // VAL(STACK) = ENTER_CHAR_LIT(MONITOR(12, DOUBLEFLAG));
                  // (3733)
                  {
                    int32_t numberRHS = (int32_t)((
                        putCHARACTERp (mGENERATExENTER_CHAR_LITxSTR,
                                       MONITOR12 (BYTE0 (mDOUBLEFLAG))),
                        GENERATExENTER_CHAR_LIT (0)));
                    putFIXED (
                        getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK))
                            + 12 + 4 * (0),
                        numberRHS);
                  }
                es2s1s2s2:;
                } // End of DO block
            es2s1s2:;
            } // End of DO block
            break;
          case 2:
            // GO TO UNIMPLEMENTED; (3735)
            {
              resetAllReentryGuards ();
              longjmp (jbUNIMPLEMENTED, 1);
            }
            break;
          }
      } // End of DO CASE block
      // SIZE(STACK) = LENGTH(DESC(VAL(STACK))); (3735)
      {
        int32_t numberRHS = (int32_t)(LENGTH (getCHARACTER (
            getFIXED (mIND_STACK)
            + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK)) + 12 + 4 * (0))));
        putBIT (16,
                getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK)) + 48
                    + 2 * (0),
                fixedToBit (16, numberRHS));
      }
      // RETURN; (3736)
      {
        reentryGuard = 0;
        return 0;
      }
    es2:;
    } // End of DO block
  // ELSE (3737)
  else
    // IF LIT1(PTR) = 2 THEN (3738)
    if (1
        & (xEQ (getFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 0
                          + 4 * (COREHALFWORD (mGENERATExLITERALxPTR))),
                2)))
      // DO; (3739)
      {
      rs3:;
        // VAL(STACK) = LIT2(PTR); (3740)
        {
          int32_t numberRHS = (int32_t)(getFIXED (
              getFIXED (mLIT_PG) + 1560 * (0) + 520
              + 4 * (COREHALFWORD (mGENERATExLITERALxPTR))));
          putFIXED (getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK)) + 12
                        + 4 * (0),
                    numberRHS);
        }
        // SIZE(STACK) = LIT3(PTR); (3741)
        {
          int32_t numberRHS = (int32_t)(getFIXED (
              getFIXED (mLIT_PG) + 1560 * (0) + 1040
              + 4 * (COREHALFWORD (mGENERATExLITERALxPTR))));
          putBIT (16,
                  getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK)) + 48
                      + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        // IF SIZE(STACK) > HALFWORDSIZE THEN (3742)
        if (1
            & (xGT (
                COREHALFWORD (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK))
                              + 48 + 2 * (0)),
                BYTE0 (mHALFWORDSIZE))))
          // TYPE(STACK) = FULLBIT; (3743)
          {
            descriptor_t *bitRHS = getBIT (8, mFULLBIT);
            putBIT (16,
                    getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK)) + 50
                        + 2 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
        // RETURN; (3744)
        {
          reentryGuard = 0;
          return 0;
        }
      es3:;
      } // End of DO block
  // DO CASE LTYPE &  7; (3745)
  {
  rs4:
    switch (xAND (COREHALFWORD (mGENERATExLITERALxLTYPE), 7))
      {
      case 0:
          // ; (3747)
          ;
        break;
      case 1:
        // GO TO INTEGER_LIT; (3748)
        goto INTEGER_LIT;
        break;
      case 2:
        // GO TO INTEGER_LIT; (3749)
        goto INTEGER_LIT;
        break;
      case 3:
        // GO TO SCALAR_LIT; (3750)
        goto SCALAR_LIT;
        break;
      case 4:
        // GO TO SCALAR_LIT; (3751)
        goto SCALAR_LIT;
        break;
      case 5:
        // DO; (3752)
        {
        rs4s1:;
        // SCALAR_LIT: (3752)
        SCALAR_LIT:
          // VAL(STACK) = LIT2(PTR); (3753)
          {
            int32_t numberRHS = (int32_t)(getFIXED (
                getFIXED (mLIT_PG) + 1560 * (0) + 520
                + 4 * (COREHALFWORD (mGENERATExLITERALxPTR))));
            putFIXED (getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK)) + 12
                          + 4 * (0),
                      numberRHS);
          }
          // XVAL(STACK) = LIT3(PTR); (3754)
          {
            int32_t numberRHS = (int32_t)(getFIXED (
                getFIXED (mLIT_PG) + 1560 * (0) + 1040
                + 4 * (COREHALFWORD (mGENERATExLITERALxPTR))));
            putFIXED (getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK)) + 16
                          + 4 * (0),
                      numberRHS);
          }
          // TYPE(STACK) = TYPE(STACK)&8 | SCALAR; (3755)
          {
            int32_t numberRHS = (int32_t)(xOR (
                xAND (COREHALFWORD (
                          getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK)) + 50
                          + 2 * (0)),
                      8),
                BYTE0 (mSCALAR)));
            putBIT (16,
                    getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK)) + 50
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
        es4s1:;
        } // End of DO block
        break;
      case 6:
        // DO; (3757)
        {
        rs4s2:;
        // INTEGER_LIT: (3757)
        INTEGER_LIT:
          // DW(0)=LIT2(PTR); (3758)
          {
            int32_t numberRHS = (int32_t)(getFIXED (
                getFIXED (mLIT_PG) + 1560 * (0) + 520
                + 4 * (COREHALFWORD (mGENERATExLITERALxPTR))));
            putFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0 + 4 * (0), numberRHS);
          }
          // IF LIT1(PTR) = 3 THEN (3759)
          if (1
              & (xEQ (getFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 0
                                + 4 * (COREHALFWORD (mGENERATExLITERALxPTR))),
                      3)))
            // DW(3)=EXTENT(DW(0))+ SYT_DISP(DW(0)); (3760)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  getFIXED (getFIXED (mSYM_TAB)
                            + 34
                                  * (getFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0
                                               + 4 * (0)))
                            + 12 + 4 * (0)),
                  COREHALFWORD (getFIXED (mP2SYMS)
                                + 12
                                      * (getFIXED (getFIXED (mFOR_DW) + 4 * (0)
                                                   + 0 + 4 * (0)))
                                + 6 + 2 * (0))));
              putFIXED (getFIXED (mFOR_DW) + 4 * (3) + 0 + 4 * (0), numberRHS);
            }
          // ELSE (3761)
          else
            // DO; (3762)
            {
            rs4s2s1:;
              // DW(1) = LIT3(PTR); (3763)
              {
                int32_t numberRHS = (int32_t)(getFIXED (
                    getFIXED (mLIT_PG) + 1560 * (0) + 1040
                    + 4 * (COREHALFWORD (mGENERATExLITERALxPTR))));
                putFIXED (getFIXED (mFOR_DW) + 4 * (1) + 0 + 4 * (0),
                          numberRHS);
              }
              // IF ~INTEGERIZABLE THEN (3764)
              if (1 & (xNOT (GENERATExINTEGERIZABLE (0))))
                // CALL ERRORS(CLASS_BS,108); (3765)
                {
                  putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BS));
                  putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(108)));
                  ERRORS (0);
                }
            es4s2s1:;
            } // End of DO block
          // VAL(STACK) = DW(3); (3766)
          {
            int32_t numberRHS = (int32_t)(getFIXED (getFIXED (mFOR_DW)
                                                    + 4 * (3) + 0 + 4 * (0)));
            putFIXED (getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK)) + 12
                          + 4 * (0),
                      numberRHS);
          }
          // IF (DW(3)>HALFMAX) | (DW(3)<HALFMIN) THEN (3767)
          if (1
              & (xOR (
                  xGT (getFIXED (getFIXED (mFOR_DW) + 4 * (3) + 0 + 4 * (0)),
                       getFIXED (mHALFMAX)),
                  xLT (getFIXED (getFIXED (mFOR_DW) + 4 * (3) + 0 + 4 * (0)),
                       getFIXED (mHALFMIN)))))
            // TYPE(STACK)=TYPE(STACK)|8; (3768)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  COREHALFWORD (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK))
                                + 50 + 2 * (0)),
                  8));
              putBIT (16,
                      getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExLITERALxSTACK)) + 50
                          + 2 * (0),
                      fixedToBit (16, numberRHS));
            }
        es4s2:;
        } // End of DO block
        break;
      }
  } // End of DO CASE block
  {
    reentryGuard = 0;
    return 0;
  }
}
