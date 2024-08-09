/*
  File STREAMxINCLUDE_SDFxENTER_SDF_TEMPLATE.c generated by XCOM-I, 2024-08-09
  12:38:15.
*/

#include "runtimeC.h"

int32_t
STREAMxINCLUDE_SDFxENTER_SDF_TEMPLATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "STREAMxINCLUDE_SDFxENTER_SDF_TEMPLATE");
  // IF DUPLICATE_NAME(BCD) THEN (3745)
  if (1
      & (bitToFixed ((putCHARACTERp (mSTREAMxINCLUDE_SDFxDUPLICATE_NAMExNAME,
                                     getCHARACTER (mBCD)),
                      STREAMxINCLUDE_SDFxDUPLICATE_NAME (0)))))
    // CALL ERROR(CLASS_PM, 2, SUBSTR(BCD,1)); (3746)
    {
      putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_PM));
      putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(2)));
      putCHARACTERp (mERRORxTEXT, SUBSTR2 (getCHARACTER (mBCD), 1));
      ERROR (0);
    }
  // REF_ID_LOC = ENTER(BCD, TEMPLATE_CLASS); (3747)
  {
    int32_t numberRHS = (int32_t)((
        putCHARACTERp (mENTERxNAME, getCHARACTER (mBCD)),
        putFIXED (mENTERxCLASS, BYTE0 (mTEMPLATE_CLASS)), ENTER (0)));
    putFIXED (mREF_ID_LOC, numberRHS);
  }
  // IF CONTROL( 3) THEN (3748)
  if (1 & (bitToFixed (getBIT (1, mCONTROL + 1 * 3))))
    // OUTPUT = 'ENTER_SDF_TEMPLATE: ID_LOC = ' || REF_ID_LOC || ', NAME = ' ||
    // BCD; (3749)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          xsCAT (xsCAT (cToDescriptor (NULL, "ENTER_SDF_TEMPLATE: ID_LOC = "),
                        fixedToCharacter (getFIXED (mREF_ID_LOC))),
                 cToDescriptor (NULL, ", NAME = ")),
          getCHARACTER (mBCD));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // SYT_TYPE(REF_ID_LOC) = TEMPL_NAME; (3750)
  {
    int32_t numberRHS = (int32_t)(62);
    putBIT (8,
            getFIXED (mSYM_TAB) + 34 * (getFIXED (mREF_ID_LOC)) + 32 + 1 * (0),
            fixedToBit (8, numberRHS));
  }
  // CALL SET_SYT_FLAGS(REF_ID_LOC); (3751)
  {
    putBITp (16, mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxNDX,
             fixedToBit (32, (int32_t)(getFIXED (mREF_ID_LOC))));
    STREAMxINCLUDE_SDFxSET_SYT_FLAGS (0);
  }
  // IF (SDF_SYMB_FLAGS & SDF_MISC_NAME_FLAG) ~= 0 THEN (3752)
  if (1
      & (xNEQ (
          xAND (getFIXED (getFIXED (mSTREAMxINCLUDE_SDFxSDF_F) + 4 * 2), 16),
          0)))
    // SYT_FLAGS(REF_ID_LOC) = SYT_FLAGS(REF_ID_LOC) | MISC_NAME_FLAG; (3753)
    {
      int32_t numberRHS = (int32_t)(xOR (
          getFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mREF_ID_LOC)) + 8
                    + 4 * (0)),
          1073741824));
      putFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mREF_ID_LOC)) + 8
                    + 4 * (0),
                numberRHS);
    }
  // STRUC_SIZE = 0; (3754)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mSTRUC_SIZE, numberRHS);
  }
  // BUILDING_TEMPLATE = TRUE; (3755)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mBUILDING_TEMPLATE, bitRHS);
    bitRHS->inUse = 0;
  }
  // LEVEL = 0; (3756)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL, bitRHS);
    bitRHS->inUse = 0;
  }
  // FATHER(0) = REF_ID_LOC; (3757)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mREF_ID_LOC));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExFATHER + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // SYT_LINK1(REF_ID_LOC) = REF_ID_LOC + 1; (3758)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mREF_ID_LOC), 1));
    putBIT (16,
            getFIXED (mSYM_TAB) + 34 * (getFIXED (mREF_ID_LOC)) + 24 + 2 * (0),
            fixedToBit (16, numberRHS));
  }
// WALK: (3759)
WALK:
  // DO UNTIL LEVEL < 0; (3760)
  do
    {
      // DO ; (3761)
      {
      rs1s1:;
        // COMMTABL_HALFWORD ( 9 ) = NEXT_SYMBOL ; (3762)
        {
          descriptor_t *bitRHS = getBIT (16, mSTREAMxINCLUDE_SDFxNEXT_SYMBOL);
          putBIT (16,
                  getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD) + 2 * (9),
                  bitRHS);
          bitRHS->inUse = 0;
        }
        // CALL MONITOR ( 22 , 9 ) ; (3763)
        MONITOR22 (9);
        // COREWORD ( ADDR ( SDF_B ) ) , COREWORD ( ADDR ( SDF_H ) ) , COREWORD
        // ( ADDR ( SDF_F ) ) = COMMTABL_FULLWORD(7) ; (3764)
        {
          int32_t numberRHS = (int32_t)(getFIXED (
              getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_FULLWORD) + 4 * 7));
          COREWORD2 (ADDR ("STREAMxINCLUDE_SDFxSDF_B", 0x80000000, NULL, 0),
                     numberRHS);
          COREWORD2 (ADDR ("STREAMxINCLUDE_SDFxSDF_H", 0x80000000, NULL, 0),
                     numberRHS);
          COREWORD2 (ADDR ("STREAMxINCLUDE_SDFxSDF_F", 0x80000000, NULL, 0),
                     numberRHS);
        }
        // ; (3765)
        ;
      es1s1:;
      } // End of DO block
      // ; (3766)
      ;
      // CUR_SYMBOL = NEXT_SYMBOL; (3767)
      {
        descriptor_t *bitRHS = getBIT (16, mSTREAMxINCLUDE_SDFxNEXT_SYMBOL);
        putBIT (16, mSTREAMxINCLUDE_SDFxCUR_SYMBOL, bitRHS);
        bitRHS->inUse = 0;
      }
      // NEXT_SYMBOL = SDF_SYMB_DECLARE_LINK; (3768)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mSTREAMxINCLUDE_SDFxSDF_H) + 2 * -5);
        putBIT (16, mSTREAMxINCLUDE_SDFxNEXT_SYMBOL, bitRHS);
        bitRHS->inUse = 0;
      }
      // BCD = NEW_STRING(SDFPKG_SYMBNAM); (3769)
      {
        descriptor_t *stringRHS;
        stringRHS = SUBSTR2 (
            xsCAT (
                getCHARACTER (mX1),
                getCHARACTERd (xadd (
                    xadd (
                        SHL (xsubtract (
                                 BYTE0 (getFIXED (
                                            mSTREAMxINCLUDE_SDFxCOMMTABL_BYTE)
                                        + 1 * 23),
                                 1),
                             24),
                        getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_ADDR)),
                    88))),
            1);
        putCHARACTER (mBCD, stringRHS);
        stringRHS->inUse = 0;
      }
      // CLASS = SDF_SYMB_CLASS; (3770)
      {
        descriptor_t *bitRHS
            = getBIT (8, getFIXED (mSTREAMxINCLUDE_SDFxSDF_B) + 1 * 6);
        putBIT (16, mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExCLASS, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF CLASS = 4 THEN (3771)
      if (1
          & (xEQ (COREHALFWORD (mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExCLASS),
                  4)))
        // CALL ENTER_SDF_VAR(TEMPLATE_CLASS); (3772)
        {
          putBITp (16, mSTREAMxINCLUDE_SDFxENTER_SDF_VARxCLASS,
                   getBIT (8, mTEMPLATE_CLASS));
          STREAMxINCLUDE_SDFxENTER_SDF_VAR (0);
        }
      // ELSE (3773)
      else
        // IF CLASS = 5 THEN (3774)
        if (1
            & (xEQ (
                COREHALFWORD (mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExCLASS),
                5)))
          // CALL ENTER_SDF_LABEL(TPL_LAB_CLASS); (3775)
          {
            putBITp (16, mSTREAMxINCLUDE_SDFxENTER_SDF_LABELxCLASS,
                     getBIT (8, mTPL_LAB_CLASS));
            STREAMxINCLUDE_SDFxENTER_SDF_LABEL (0);
          }
        // ELSE (3776)
        else
          // CALL ENTER_SDF_VAR(TPL_FUNC_CLASS); (3777)
          {
            putBITp (16, mSTREAMxINCLUDE_SDFxENTER_SDF_VARxCLASS,
                     getBIT (8, mTPL_FUNC_CLASS));
            STREAMxINCLUDE_SDFxENTER_SDF_VAR (0);
          }
      // IF SDF_SYMB_LINK1 ~= 0 THEN (3778)
      if (1
          & (xNEQ (
              COREHALFWORD (
                  getFIXED (mSTREAMxINCLUDE_SDFxSDF_H)
                  + 2
                        * xadd (xdivide (
                                    BYTE0 (getFIXED (mSTREAMxINCLUDE_SDFxSDF_B)
                                           + 1 * 5),
                                    2),
                                1)),
              0)))
        // DO; (3779)
        {
        rs1s2:;
          // IF SDF_SYMB_LINK2 < 0 THEN (3780)
          if (1
              & (xLT (
                  COREHALFWORD (
                      getFIXED (mSTREAMxINCLUDE_SDFxSDF_H)
                      + 2
                            * xadd (
                                xdivide (
                                    BYTE0 (getFIXED (mSTREAMxINCLUDE_SDFxSDF_B)
                                           + 1 * 5),
                                    2),
                                2)),
                  0)))
            // SYT_LINK2(ID_LOC) = -FATHER(LEVEL); (3781)
            {
              int32_t numberRHS = (int32_t)(xminus (COREHALFWORD (
                  mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExFATHER
                  + 2
                        * COREHALFWORD (
                            mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL))));
              putBIT (16,
                      getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 26
                          + 2 * (0),
                      fixedToBit (16, numberRHS));
            }
          // ELSE (3782)
          else
            // SYT_LINK2(ID_LOC) = 0; (3783)
            {
              int32_t numberRHS = (int32_t)(0);
              putBIT (16,
                      getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 26
                          + 2 * (0),
                      fixedToBit (16, numberRHS));
            }
          // LEVEL = LEVEL + 1; (3784)
          {
            int32_t numberRHS = (int32_t)(xadd (
                COREHALFWORD (mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL),
                1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL, bitRHS);
            bitRHS->inUse = 0;
          }
          // FATHER(LEVEL) = ID_LOC; (3785)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mID_LOC));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (
                16,
                mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExFATHER
                    + 2
                          * (COREHALFWORD (
                              mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL)),
                bitRHS);
            bitRHS->inUse = 0;
          }
          // SYT_LINK1(ID_LOC) = ID_LOC + 1; (3786)
          {
            int32_t numberRHS = (int32_t)(xadd (getFIXED (mID_LOC), 1));
            putBIT (16,
                    getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 24
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
        es1s2:;
        } // End of DO block
      // ELSE (3787)
      else
        // DO; (3788)
        {
        rs1s3:;
          // SYT_LINK1(ID_LOC) = 0; (3789)
          {
            int32_t numberRHS = (int32_t)(0);
            putBIT (16,
                    getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 24
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
          // IF SDF_SYMB_LINK2 > 0 THEN (3790)
          if (1
              & (xGT (
                  COREHALFWORD (
                      getFIXED (mSTREAMxINCLUDE_SDFxSDF_H)
                      + 2
                            * xadd (
                                xdivide (
                                    BYTE0 (getFIXED (mSTREAMxINCLUDE_SDFxSDF_B)
                                           + 1 * 5),
                                    2),
                                2)),
                  0)))
            // SYT_LINK2(ID_LOC) = ID_LOC + 1; (3791)
            {
              int32_t numberRHS = (int32_t)(xadd (getFIXED (mID_LOC), 1));
              putBIT (16,
                      getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 26
                          + 2 * (0),
                      fixedToBit (16, numberRHS));
            }
          // ELSE (3792)
          else
            // DO; (3793)
            {
            rs1s3s1:;
              // SYT_LINK2(ID_LOC) = -FATHER(LEVEL); (3794)
              {
                int32_t numberRHS = (int32_t)(xminus (COREHALFWORD (
                    mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExFATHER
                    + 2
                          * COREHALFWORD (
                              mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL))));
                putBIT (16,
                        getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 26
                            + 2 * (0),
                        fixedToBit (16, numberRHS));
              }
              // DO WHILE SYT_LINK2(FATHER(LEVEL)) < 0; (3795)
              while (
                  1
                  & (xLT (
                      COREHALFWORD (
                          getFIXED (mSYM_TAB)
                          + 34
                                * (COREHALFWORD (
                                    mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExFATHER
                                    + 2
                                          * COREHALFWORD (
                                              mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL)))
                          + 26 + 2 * (0)),
                      0)))
                {
                  // LEVEL = LEVEL - 1; (3796)
                  {
                    int32_t numberRHS = (int32_t)(xsubtract (
                        COREHALFWORD (
                            mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL),
                        1));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL,
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                } // End of DO WHILE block
              // IF LEVEL > 0 THEN (3797)
              if (1
                  & (xGT (COREHALFWORD (
                              mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL),
                          0)))
                // DO; (3798)
                {
                rs1s3s1s2:;
                  // SYT_LINK2(FATHER(LEVEL)) = ID_LOC + 1; (3799)
                  {
                    int32_t numberRHS
                        = (int32_t)(xadd (getFIXED (mID_LOC), 1));
                    putBIT (
                        16,
                        getFIXED (mSYM_TAB)
                            + 34
                                  * (COREHALFWORD (
                                      mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExFATHER
                                      + 2
                                            * COREHALFWORD (
                                                mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL)))
                            + 26 + 2 * (0),
                        fixedToBit (16, numberRHS));
                  }
                  // IF CONTROL( 3) THEN (3800)
                  if (1 & (bitToFixed (getBIT (1, mCONTROL + 1 * 3))))
                    // OUTPUT = 'ENTER_SDF_TEMPLATE: LINK2(' || FATHER(LEVEL)
                    // || ') = ' || ID_LOC + 1; (3801)
                    {
                      descriptor_t *stringRHS;
                      stringRHS = xsCAT (
                          xsCAT (
                              xsCAT (
                                  cToDescriptor (NULL,
                                                 "ENTER_SDF_TEMPLATE: LINK2("),
                                  bitToCharacter (getBIT (
                                      16,
                                      mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExFATHER
                                          + 2
                                                * COREHALFWORD (
                                                    mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL)))),
                              cToDescriptor (NULL, ") = ")),
                          fixedToCharacter (xadd (getFIXED (mID_LOC), 1)));
                      OUTPUT (0, stringRHS);
                      stringRHS->inUse = 0;
                    }
                es1s3s1s2:;
                } // End of DO block
              // LEVEL = LEVEL - 1; (3802)
              {
                int32_t numberRHS = (int32_t)(xsubtract (
                    COREHALFWORD (
                        mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL),
                    1));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL,
                        bitRHS);
                bitRHS->inUse = 0;
              }
            es1s3s1:;
            } // End of DO block
          // STRUC_SIZE = STRUC_SIZE + ICQ_TERM#(ID_LOC) * ICQ_ARRAY#(ID_LOC);
          // (3803)
          {
            int32_t numberRHS = (int32_t)(xadd (
                getFIXED (mSTRUC_SIZE),
                xmultiply (
                    (putFIXED (mICQ_TERMpxLOC, getFIXED (mID_LOC)),
                     ICQ_TERMp (0)),
                    (putBITp (16, mICQ_ARRAYpxLOC,
                              fixedToBit (32, (int32_t)(getFIXED (mID_LOC)))),
                     ICQ_ARRAYp (0)))));
            putFIXED (mSTRUC_SIZE, numberRHS);
          }
        es1s3:;
        } // End of DO block
      // IF CONTROL( 3) THEN (3804)
      if (1 & (bitToFixed (getBIT (1, mCONTROL + 1 * 3))))
        // OUTPUT = 'ENTER_SDF_TEMPLATE: LINK1 = ' || SYT_LINK1(ID_LOC) || ',
        // LINK2 = ' || SYT_LINK2(ID_LOC); (3805)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              xsCAT (
                  xsCAT (cToDescriptor (NULL, "ENTER_SDF_TEMPLATE: LINK1 = "),
                         bitToCharacter (
                             getBIT (16, getFIXED (mSYM_TAB)
                                             + 34 * (getFIXED (mID_LOC)) + 24
                                             + 2 * (0)))),
                  cToDescriptor (NULL, ", LINK2 = ")),
              bitToCharacter (getBIT (16, getFIXED (mSYM_TAB)
                                              + 34 * (getFIXED (mID_LOC)) + 26
                                              + 2 * (0))));
          OUTPUT (0, stringRHS);
          stringRHS->inUse = 0;
        }
      if (0)
        {
        rs1:
          continue;
        es1:
          break;
        } // block labeled WALK
    }
  while (!(1
           & (xLT (COREHALFWORD (mSTREAMxINCLUDE_SDFxENTER_SDF_TEMPLATExLEVEL),
                   0)))); // End of DO UNTIL block
  // BUILDING_TEMPLATE = FALSE; (3806)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mBUILDING_TEMPLATE, bitRHS);
    bitRHS->inUse = 0;
  }
  // SYT_ADDR(REF_ID_LOC) = STRUC_SIZE; (3807)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mSTRUC_SIZE));
    putFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mREF_ID_LOC)) + 4
                  + 4 * (0),
              numberRHS);
  }
  // RETURN; (3808)
  {
    reentryGuard = 0;
    return 0;
  }
}
