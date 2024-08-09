/*
  File STREAMxINCLUDE_SDFxSET_TYPE_AND_LEN.c generated by XCOM-I, 2024-08-09
  12:40:41.
*/

#include "runtimeC.h"

int32_t
STREAMxINCLUDE_SDFxSET_TYPE_AND_LEN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "STREAMxINCLUDE_SDFxSET_TYPE_AND_LEN");
  // SYT_TYPE(NDX), TYPE = P1_TYPE(SDF_SYMB_TYPE); (3636)
  {
    descriptor_t *bitRHS = getBIT (
        8, mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxP1_TYPE
               + 1 * BYTE0 (getFIXED (mSTREAMxINCLUDE_SDFxSDF_B) + 1 * 7));
    putBIT (
        8,
        getFIXED (mSYM_TAB)
            + 34 * (COREHALFWORD (mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxNDX))
            + 32 + 1 * (0),
        bitRHS);
    putBIT (16, mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxTYPE, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF (TYPE >=MAT_TYPE) & (TYPE<=INT_TYPE) THEN (3637)
  if (1
      & (xAND (
          xGE (COREHALFWORD (mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxTYPE), 3),
          xLE (COREHALFWORD (mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxTYPE), 6))))
    // DO; (3638)
    {
    rs1:;
      // IF SDF_SYMB_TYPE > 8 THEN (3639)
      if (1 & (xGT (BYTE0 (getFIXED (mSTREAMxINCLUDE_SDFxSDF_B) + 1 * 7), 8)))
        // SYT_FLAGS(NDX) = SYT_FLAGS(NDX) | DOUBLE_FLAG; (3640)
        {
          int32_t numberRHS = (int32_t)(xOR (
              getFIXED (getFIXED (mSYM_TAB)
                        + 34
                              * (COREHALFWORD (
                                  mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxNDX))
                        + 8 + 4 * (0)),
              4194304));
          putFIXED (getFIXED (mSYM_TAB)
                        + 34
                              * (COREHALFWORD (
                                  mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxNDX))
                        + 8 + 4 * (0),
                    numberRHS);
        }
      // ELSE (3641)
      else
        // SYT_FLAGS(NDX) = SYT_FLAGS(NDX) | SINGLE_FLAG; (3642)
        {
          int32_t numberRHS = (int32_t)(xOR (
              getFIXED (getFIXED (mSYM_TAB)
                        + 34
                              * (COREHALFWORD (
                                  mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxNDX))
                        + 8 + 4 * (0)),
              8388608));
          putFIXED (getFIXED (mSYM_TAB)
                        + 34
                              * (COREHALFWORD (
                                  mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxNDX))
                        + 8 + 4 * (0),
                    numberRHS);
        }
    es1:;
    } // End of DO block
  // IF (TYPE = CHAR_TYPE) | (TYPE = MAT_TYPE) THEN (3643)
  if (1
      & (xOR (
          xEQ (COREHALFWORD (mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxTYPE), 2),
          xEQ (COREHALFWORD (mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxTYPE), 3))))
    // VAR_LENGTH(NDX) = SDF_SYMB_VAR_LENGTH; (3644)
    {
      descriptor_t *bitRHS
          = getBIT (16, getFIXED (mSTREAMxINCLUDE_SDFxSDF_H) + 2 * 9);
      putBIT (
          16,
          getFIXED (mSYM_TAB)
              + 34 * (COREHALFWORD (mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxNDX))
              + 18 + 2 * (0),
          bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (3645)
  else
    // IF (TYPE = BIT_TYPE) | (TYPE = VEC_TYPE) THEN (3646)
    if (1
        & (xOR (
            xEQ (COREHALFWORD (mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxTYPE), 1),
            xEQ (COREHALFWORD (mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxTYPE),
                 4))))
      // VAR_LENGTH(NDX) = SDF_SYMB_VAR_LENGTH &  255; (3647)
      {
        int32_t numberRHS = (int32_t)(xAND (
            COREHALFWORD (getFIXED (mSTREAMxINCLUDE_SDFxSDF_H) + 2 * 9), 255));
        putBIT (16,
                getFIXED (mSYM_TAB)
                    + 34
                          * (COREHALFWORD (
                              mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxNDX))
                    + 18 + 2 * (0),
                fixedToBit (16, numberRHS));
      }
    // ELSE (3648)
    else
      // IF (TYPE = MAJ_STRUC) & (SDF_SYMB_VAR_LENGTH ~= 0) THEN (3649)
      if (1
          & (xAND (
              xEQ (COREHALFWORD (mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxTYPE),
                   10),
              xNEQ (
                  COREHALFWORD (getFIXED (mSTREAMxINCLUDE_SDFxSDF_H) + 2 * 9),
                  0))))
        // DO; (3650)
        {
        rs2:;
          // TEMP_PTR = SDFPKG_LOC_PTR; (3651)
          {
            int32_t numberRHS = (int32_t)(getFIXED (
                getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_FULLWORD) + 4 * 6));
            putFIXED (mSTREAMxINCLUDE_SDFxTEMP_PTR, numberRHS);
          }
          // DO ; (3652)
          {
          rs2s1:;
            // COMMTABL_HALFWORD ( 9 ) = SDF_H ( 9 ) ; (3653)
            {
              descriptor_t *bitRHS
                  = getBIT (16, getFIXED (mSTREAMxINCLUDE_SDFxSDF_H) + 2 * 9);
              putBIT (16,
                      getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_HALFWORD)
                          + 2 * (9),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // CALL MONITOR ( 22 , 9 ) ; (3654)
            MONITOR22 (9);
            // COREWORD ( ADDR ( SDF_B ) ) , COREWORD ( ADDR ( SDF_H ) ) ,
            // COREWORD ( ADDR ( SDF_F ) ) = COMMTABL_FULLWORD(7) ; (3655)
            {
              int32_t numberRHS = (int32_t)(getFIXED (
                  getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_FULLWORD) + 4 * 7));
              COREWORD2 (
                  ADDR ("STREAMxINCLUDE_SDFxSDF_B", 0x80000000, NULL, 0),
                  numberRHS);
              COREWORD2 (
                  ADDR ("STREAMxINCLUDE_SDFxSDF_H", 0x80000000, NULL, 0),
                  numberRHS);
              COREWORD2 (
                  ADDR ("STREAMxINCLUDE_SDFxSDF_F", 0x80000000, NULL, 0),
                  numberRHS);
            }
            // ; (3656)
            ;
          es2s1:;
          } // End of DO block
          // ; (3657)
          ;
          // STRUC_NAME = NEW_STRING(SDFPKG_SYMBNAM); (3658)
          {
            descriptor_t *stringRHS;
            stringRHS = SUBSTR2 (
                xsCAT (
                    getCHARACTER (mX1),
                    getCHARACTERd (xadd (
                        xadd (
                            SHL (xsubtract (
                                     BYTE0 (
                                         getFIXED (
                                             mSTREAMxINCLUDE_SDFxCOMMTABL_BYTE)
                                         + 1 * 23),
                                     1),
                                 24),
                            getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_ADDR)),
                        88))),
                1);
            putCHARACTER (mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxSTRUC_NAME,
                          stringRHS);
            stringRHS->inUse = 0;
          }
          // DO ; (3659)
          {
          rs2s2:;
            // COMMTABL_FULLWORD ( 6 ) = TEMP_PTR ; (3660)
            {
              int32_t numberRHS
                  = (int32_t)(getFIXED (mSTREAMxINCLUDE_SDFxTEMP_PTR));
              putFIXED (getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_FULLWORD)
                            + 4 * (6),
                        numberRHS);
            }
            // CALL MONITOR ( 22 , 5 ) ; (3661)
            MONITOR22 (5);
            // COREWORD ( ADDR ( SDF_B ) ) , COREWORD ( ADDR ( SDF_H ) ) ,
            // COREWORD ( ADDR ( SDF_F ) ) = COMMTABL_FULLWORD(7) ; (3662)
            {
              int32_t numberRHS = (int32_t)(getFIXED (
                  getFIXED (mSTREAMxINCLUDE_SDFxCOMMTABL_FULLWORD) + 4 * 7));
              COREWORD2 (
                  ADDR ("STREAMxINCLUDE_SDFxSDF_B", 0x80000000, NULL, 0),
                  numberRHS);
              COREWORD2 (
                  ADDR ("STREAMxINCLUDE_SDFxSDF_H", 0x80000000, NULL, 0),
                  numberRHS);
              COREWORD2 (
                  ADDR ("STREAMxINCLUDE_SDFxSDF_F", 0x80000000, NULL, 0),
                  numberRHS);
            }
            // ; (3663)
            ;
          es2s2:;
          } // End of DO block
          // ; (3664)
          ;
          // STRUC_PTR = FIND(STRUC_NAME); (3665)
          {
            descriptor_t *bitRHS
                = (putCHARACTERp (
                       mSTREAMxINCLUDE_SDFxFINDxNAME,
                       getCHARACTER (
                           mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxSTRUC_NAME)),
                   STREAMxINCLUDE_SDFxFIND (0));
            int32_t numberRHS;
            numberRHS = bitToFixed (bitRHS);
            putFIXED (mSTRUC_PTR, numberRHS);
            bitRHS->inUse = 0;
          }
          // IF STRUC_PTR = 0 THEN (3666)
          if (1 & (xEQ (getFIXED (mSTRUC_PTR), 0)))
            // DO; (3667)
            {
            rs2s3:;
              // CALL ERROR(CLASS_DU, 5, SUBSTR(STRUC_NAME,1)); (3668)
              {
                putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DU));
                putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(5)));
                putCHARACTERp (
                    mERRORxTEXT,
                    SUBSTR2 (
                        getCHARACTER (
                            mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxSTRUC_NAME),
                        1));
                ERROR (0);
              }
              // STRUC_PTR = ENTER(STRUC_NAME, TEMPLATE_CLASS); (3669)
              {
                int32_t numberRHS = (int32_t)((
                    putCHARACTERp (
                        mENTERxNAME,
                        getCHARACTER (
                            mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxSTRUC_NAME)),
                    putFIXED (mENTERxCLASS, BYTE0 (mTEMPLATE_CLASS)),
                    ENTER (0)));
                putFIXED (mSTRUC_PTR, numberRHS);
              }
              // SYT_TYPE(STRUC_PTR) = TEMPL_NAME; (3670)
              {
                int32_t numberRHS = (int32_t)(62);
                putBIT (8,
                        getFIXED (mSYM_TAB) + 34 * (getFIXED (mSTRUC_PTR)) + 32
                            + 1 * (0),
                        fixedToBit (8, numberRHS));
              }
              // SYT_FLAGS(STRUC_PTR) = EVIL_FLAG; (3671)
              {
                int32_t numberRHS = (int32_t)(2097152);
                putFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mSTRUC_PTR))
                              + 8 + 4 * (0),
                          numberRHS);
              }
              // IF BUILDING_TEMPLATE THEN (3672)
              if (1 & (bitToFixed (getBIT (1, mBUILDING_TEMPLATE))))
                // SYT_FLAGS(REF_ID_LOC) = SYT_FLAGS(REF_ID_LOC) | EVIL_FLAG;
                // (3673)
                {
                  int32_t numberRHS = (int32_t)(xOR (
                      getFIXED (getFIXED (mSYM_TAB)
                                + 34 * (getFIXED (mREF_ID_LOC)) + 8 + 4 * (0)),
                      2097152));
                  putFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mREF_ID_LOC))
                                + 8 + 4 * (0),
                            numberRHS);
                }
            es2s3:;
            } // End of DO block
          // STRUC_DIM = 0; (3674)
          {
            int32_t numberRHS = (int32_t)(0);
            putFIXED (mSTRUC_DIM, numberRHS);
          }
          // CALL CHECK_STRUC_CONFLICTS; (3675)
          CHECK_STRUC_CONFLICTS (0);
          // VAR_LENGTH(NDX) = STRUC_PTR; (3676)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mSTRUC_PTR));
            putBIT (16,
                    getFIXED (mSYM_TAB)
                        + 34
                              * (COREHALFWORD (
                                  mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxNDX))
                        + 18 + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
          // SYT_XREF(STRUC_PTR) = ENTER_XREF(SYT_XREF(STRUC_PTR), XREF_REF);
          // (3677)
          {
            descriptor_t *bitRHS
                = (putFIXED (mENTER_XREFxROOT,
                             COREHALFWORD (getFIXED (mSYM_TAB)
                                           + 34 * (getFIXED (mSTRUC_PTR)) + 16
                                           + 2 * (0))),
                   putFIXED (mENTER_XREFxFLAG, getFIXED (mXREF_REF)),
                   ENTER_XREF (0));
            putBIT (16,
                    getFIXED (mSYM_TAB) + 34 * (getFIXED (mSTRUC_PTR)) + 16
                        + 2 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
        es2:;
        } // End of DO block
  // IF CONTROL( 3) THEN (3678)
  if (1 & (bitToFixed (getBIT (1, mCONTROL + 1 * 3))))
    // OUTPUT = 'SET_TYPE_AND_LEN: TYPE = ' || TYPE || ', LENGTH = ' ||
    // VAR_LENGTH(NDX); (3679)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          xsCAT (xsCAT (cToDescriptor (NULL, "SET_TYPE_AND_LEN: TYPE = "),
                        bitToCharacter (getBIT (
                            16, mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxTYPE))),
                 cToDescriptor (NULL, ", LENGTH = ")),
          bitToCharacter (getBIT (
              16, getFIXED (mSYM_TAB)
                      + 34
                            * (COREHALFWORD (
                                mSTREAMxINCLUDE_SDFxSET_TYPE_AND_LENxNDX))
                      + 18 + 2 * (0))));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // RETURN; (3680)
  {
    reentryGuard = 0;
    return 0;
  }
}
