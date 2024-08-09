/*
  File OBJECT_GENERATORxEMIT_ESD_CARDS.c generated by XCOM-I, 2024-08-09
  12:39:31.
*/

#include "runtimeC.h"

int32_t
OBJECT_GENERATORxEMIT_ESD_CARDS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "OBJECT_GENERATORxEMIT_ESD_CARDS");
  // CALL EMIT_SYM_CARDS; (16094)
  OBJECT_GENERATORxEMIT_SYM_CARDS (0);
  // ESD# = 1; (16095)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp, bitRHS);
    bitRHS->inUse = 0;
  }
  // EMITTING_ESDS = TRUE; (16096)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mOBJECT_GENERATORxEMIT_ESD_CARDSxEMITTING_ESDS, bitRHS);
    bitRHS->inUse = 0;
  }
// DO_EMITTING_ESDS: (16097)
DO_EMITTING_ESDS:
  // DO WHILE EMITTING_ESDS; (16098)
  while (1
         & (bitToFixed (
             getBIT (1, mOBJECT_GENERATORxEMIT_ESD_CARDSxEMITTING_ESDS))))
    {
      // CALL EMIT_CARD; (16099)
      OBJECT_GENERATORxEMIT_CARD (0);
      // BYTES_REMAINING, CURRENT_SIZE = 48; (16100)
      {
        int32_t numberRHS = (int32_t)(48);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mOBJECT_GENERATORxBYTES_REMAINING, bitRHS);
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mOBJECT_GENERATORxCURRENT_SIZE, bitRHS);
        bitRHS->inUse = 0;
      }
      // CARDIMAGE, CARDIMAGE(1) = ESD_CARD; (16101)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mOBJECT_GENERATORxESD_CARD));
        putFIXED (mOBJECT_GENERATORxCARDIMAGE, numberRHS);
        putFIXED (mOBJECT_GENERATORxCARDIMAGE + 4 * (1), numberRHS);
      }
      // CARDIMAGE(4) =  1077936128 + ESD#; (16102)
      {
        int32_t numberRHS = (int32_t)(xadd (
            1077936128, COREHALFWORD (mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)));
        putFIXED (mOBJECT_GENERATORxCARDIMAGE + 4 * (4), numberRHS);
      }
    // DO_J: (16103)
    DO_J:
      // DO J = 5 TO 13 BY 4; (16104)
      {
        int32_t from158, to158, by158;
        from158 = 5;
        to158 = 13;
        by158 = 4;
        for (putBIT (16, mOBJECT_GENERATORxEMIT_ESD_CARDSxJ,
                     fixedToBit (16, from158));
             bitToFixed (getBIT (16, mOBJECT_GENERATORxEMIT_ESD_CARDSxJ))
             <= to158;
             putBIT (
                 16, mOBJECT_GENERATORxEMIT_ESD_CARDSxJ,
                 fixedToBit (16, bitToFixed (getBIT (
                                     16, mOBJECT_GENERATORxEMIT_ESD_CARDSxJ))
                                     + by158)))
          {
            // IF ESD# <= ESD_MAX THEN (16105)
            if (1
                & (xLE (COREHALFWORD (mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp),
                        COREHALFWORD (mESD_MAX))))
            // DO_ESD#: (16106)
            DO_ESDp:
            // DO; (16107)
            {
            rs1s1s1:;
              // BYTES_REMAINING=BYTES_REMAINING-16; (16108)
              {
                int32_t numberRHS = (int32_t)(xsubtract (
                    COREHALFWORD (mOBJECT_GENERATORxBYTES_REMAINING), 16));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mOBJECT_GENERATORxBYTES_REMAINING, bitRHS);
                bitRHS->inUse = 0;
              }
              // S1=PAD(ESD_TABLE(ESD#),10); (16109)
              {
                descriptor_t *stringRHS;
                stringRHS
                    = (putCHARACTERp (
                           mPADxSTRING,
                           (putBITp (
                                16, mESD_TABLExPTR,
                                getBIT (
                                    16,
                                    mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
                            ESD_TABLE (0))),
                       putFIXED (mPADxWIDTH, 10), PAD (0));
                putCHARACTER (mOBJECT_GENERATORxS1, stringRHS);
                stringRHS->inUse = 0;
              }
              // TEMP=ADDR(CARDIMAGE(J)); (16110)
              {
                int32_t numberRHS = (int32_t)(ADDR (
                    NULL, 0, "OBJECT_GENERATORxCARDIMAGE",
                    COREHALFWORD (mOBJECT_GENERATORxEMIT_ESD_CARDSxJ)));
                putFIXED (mOBJECT_GENERATORxEMIT_ESD_CARDSxTEMP, numberRHS);
              }
              {   // (68) CALL INLINE ( 88,2,0,S1);
                { /*
                   * File:      patch68p.c
                   * For:       OBJECT_GENERATORxEMIT_ESD_CARDS.c
                   * Notes:     1. Page references are from IBM "ESA/390
                   * Principles of Operation", SA22-7201-08, Ninth Edition,
                   * June 2003.
                   *            2. Labels are of the form p%d_%d, where the 1st
                   * number indicates the leading patch number of the block,
                   * and the 2nd is the byte offset of the instruction within
                   *               within the block.
                   *            3. Known-problematic translations are marked
                   * with the string  "* * * F I X M E * * *" (without spaces).
                   * History:   2024-07-18 RSB  Auto-generated by XCOM-I
                   * --guess=.... Inspected.
                   */

                  p68_0:;
              // (68)                   CALL INLINE ("58",2,0,S1);
              address360B = (mOBJECT_GENERATORxS1)&0xFFFFFF;
              // Type RX, p. 7-7:		L
              // 2,mOBJECT_GENERATORxS1(0,0)
              detailedInlineBefore (68, "L	2,mOBJECT_GENERATORxS1(0,0)");
              GR[2] = COREWORD (address360B);
              detailedInlineAfter ();

            p68_4:;
              // (69)                   CALL INLINE ("58",1,0,TEMP);
              address360B = (mOBJECT_GENERATORxEMIT_ESD_CARDSxTEMP)&0xFFFFFF;
              // Type RX, p. 7-7:		L
              // 1,mOBJECT_GENERATORxEMIT_ESD_CARDSxTEMP(0,0)
              detailedInlineBefore (
                  69, "L	1,mOBJECT_GENERATORxEMIT_ESD_CARDSxTEMP(0,0)");
              GR[1] = COREWORD (address360B);
              detailedInlineAfter ();

            p68_8:;
              // (70)                   CALL INLINE ("D2",0,7,1,0,2,0);
              address360A = (GR[1] + 0) & 0xFFFFFF;
              address360B = (GR[2] + 0) & 0xFFFFFF;
              // Type SS, p. 7-83:		MVC	0(7,1),0(2)
              detailedInlineBefore (70, "MVC	0(7,1),0(2)");
              mvc (address360A, address360B, 7);
              detailedInlineAfter ();

            p68_14:;
            }
          }; // (69) CALL INLINE ( 88,1,0,TEMP);
        ;    // (70) CALL INLINE ( 210,0,7,1,0,2,0);
        // IF ESD_TYPE(ESD#) = 2 THEN (16114)
        if (1
            & (xEQ (BYTE0 (mESD_TYPE
                           + 1
                                 * COREHALFWORD (
                                     mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
                    2)))
          // DO; (16115)
          {
          rs1s1s1s1:;
            // CARDIMAGE(J+2)= 33554432; (16116)
            {
              int32_t numberRHS = (int32_t)(33554432);
              putFIXED (
                  mOBJECT_GENERATORxCARDIMAGE
                      + 4
                            * (xadd (COREHALFWORD (
                                         mOBJECT_GENERATORxEMIT_ESD_CARDSxJ),
                                     2)),
                  numberRHS);
            }
            // IF ((SYT_FLAGS(PROC_LEVEL(ESD#)) & REMOTE_FLAG)~=0) &
            // (ESD_TABLE(ESD#) ~= THISPROGRAM)  THEN (16117)
            if (1
                & (xAND (
                    xNEQ (
                        xAND (
                            getFIXED (
                                getFIXED (mSYM_TAB)
                                + 34
                                      * (COREHALFWORD (
                                          mPROC_LEVEL
                                          + 2
                                                * COREHALFWORD (
                                                    mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)))
                                + 8 + 4 * (0)),
                            getFIXED (mREMOTE_FLAG)),
                        0),
                    xsNEQ (
                        (putBITp (
                             16, mESD_TABLExPTR,
                             getBIT (16,
                                     mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
                         ESD_TABLE (0)),
                        (putBITp (16, mESD_TABLExPTR, getBIT (16, mPROGPOINT)),
                         ESD_TABLE (0))))))
              // DO; (16118)
              {
              rs1s1s1s1s1:;
                // CARDIMAGE(J+3)= 20987968; (16119)
                {
                  int32_t numberRHS = (int32_t)(20987968);
                  putFIXED (
                      mOBJECT_GENERATORxCARDIMAGE
                          + 4
                                * (xadd (
                                    COREHALFWORD (
                                        mOBJECT_GENERATORxEMIT_ESD_CARDSxJ),
                                    3)),
                      numberRHS);
                }
                // IF SYT_TYPE(PROC_LEVEL(ESD#)) ~= COMPOOL_LABEL THEN (16120)
                if (1
                    & (xNEQ (
                        BYTE0 (
                            getFIXED (mSYM_TAB)
                            + 34
                                  * (COREHALFWORD (
                                      mPROC_LEVEL
                                      + 2
                                            * COREHALFWORD (
                                                mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)))
                            + 32 + 1 * (0)),
                        BYTE0 (mCOMPOOL_LABEL))))
                  // SYT_FLAGS(PROC_LEVEL(ESD#)) = SYT_FLAGS(PROC_LEVEL(ESD#))
                  // & ~REMOTE_FLAG; (16121)
                  {
                    int32_t numberRHS = (int32_t)(xAND (
                        getFIXED (
                            getFIXED (mSYM_TAB)
                            + 34
                                  * (COREHALFWORD (
                                      mPROC_LEVEL
                                      + 2
                                            * COREHALFWORD (
                                                mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)))
                            + 8 + 4 * (0)),
                        xNOT (getFIXED (mREMOTE_FLAG))));
                    putFIXED (
                        getFIXED (mSYM_TAB)
                            + 34
                                  * (COREHALFWORD (
                                      mPROC_LEVEL
                                      + 2
                                            * COREHALFWORD (
                                                mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)))
                            + 8 + 4 * (0),
                        numberRHS);
                  }
              es1s1s1s1s1:;
              } // End of DO block
            // ELSE (16122)
            else
              // CARDIMAGE(J+3)= 1077952576; (16123)
              {
                int32_t numberRHS = (int32_t)(1077952576);
                putFIXED (
                    mOBJECT_GENERATORxCARDIMAGE
                        + 4
                              * (xadd (COREHALFWORD (
                                           mOBJECT_GENERATORxEMIT_ESD_CARDSxJ),
                                       3)),
                    numberRHS);
              }
          es1s1s1s1:;
          } // End of DO block
        // ELSE (16124)
        else
          // IF ESD_TYPE(ESD#) = 1 THEN (16125)
          if (1
              & (xEQ (BYTE0 (mESD_TYPE
                             + 1
                                   * COREHALFWORD (
                                       mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
                      1)))
            // DO; (16126)
            {
            rs1s1s1s2:;
              // CARDIMAGE(J+2) =  16777216 + SHL(SYT_ADDR(ESD_LINK(ESD#)),1);
              // (16127)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    16777216,
                    SHL (
                        getFIXED (
                            getFIXED (mSYM_TAB)
                            + 34
                                  * (COREHALFWORD (
                                      mESD_LINK
                                      + 2
                                            * COREHALFWORD (
                                                mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)))
                            + 4 + 4 * (0)),
                        1)));
                putFIXED (
                    mOBJECT_GENERATORxCARDIMAGE
                        + 4
                              * (xadd (COREHALFWORD (
                                           mOBJECT_GENERATORxEMIT_ESD_CARDSxJ),
                                       2)),
                    numberRHS);
              }
              // CARDIMAGE(J+3) =  1073741824 + SYT_BASE(ESD_LINK(ESD#));
              // (16128)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    1073741824,
                    COREHALFWORD (
                        getFIXED (mP2SYMS)
                        + 12
                              * (COREHALFWORD (
                                  mESD_LINK
                                  + 2
                                        * COREHALFWORD (
                                            mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)))
                        + 4 + 2 * (0))));
                putFIXED (
                    mOBJECT_GENERATORxCARDIMAGE
                        + 4
                              * (xadd (COREHALFWORD (
                                           mOBJECT_GENERATORxEMIT_ESD_CARDSxJ),
                                       3)),
                    numberRHS);
              }
            es1s1s1s2:;
            } // End of DO block
          // ELSE (16129)
          else
            // DO; (16130)
            {
            rs1s1s1s3:;
              // CARDIMAGE(J+2)=SHL(ESD_TYPE(ESD#),24) + SHL(ORIGIN(ESD#),1);
              // (16131)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    SHL (BYTE0 (
                             mESD_TYPE
                             + 1
                                   * COREHALFWORD (
                                       mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
                         24),
                    SHL (getFIXED (
                             mORIGIN
                             + 4
                                   * COREHALFWORD (
                                       mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
                         1)));
                putFIXED (
                    mOBJECT_GENERATORxCARDIMAGE
                        + 4
                              * (xadd (COREHALFWORD (
                                           mOBJECT_GENERATORxEMIT_ESD_CARDSxJ),
                                       2)),
                    numberRHS);
              }
              // CARDIMAGE(J+3)= 1073741824 + SHL(LOCCTR(ESD#),1); (16132)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    1073741824,
                    SHL (getFIXED (
                             mLOCCTR
                             + 4
                                   * COREHALFWORD (
                                       mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
                         1)));
                putFIXED (
                    mOBJECT_GENERATORxCARDIMAGE
                        + 4
                              * (xadd (COREHALFWORD (
                                           mOBJECT_GENERATORxEMIT_ESD_CARDSxJ),
                                       3)),
                    numberRHS);
              }
              // IF DATA_REMOTE & (ESD# = PROGPOINT) THEN (16133)
              if (1
                  & (xAND (BYTE0 (mDATA_REMOTE),
                           xEQ (COREHALFWORD (
                                    mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp),
                                COREHALFWORD (mPROGPOINT)))))
                // CARDIMAGE(J+3)= 16777216 + SHL(LOCCTR(ESD#),1); (16134)
                {
                  int32_t numberRHS = (int32_t)(xadd (
                      16777216,
                      SHL (
                          getFIXED (
                              mLOCCTR
                              + 4
                                    * COREHALFWORD (
                                        mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
                          1)));
                  putFIXED (
                      mOBJECT_GENERATORxCARDIMAGE
                          + 4
                                * (xadd (
                                    COREHALFWORD (
                                        mOBJECT_GENERATORxEMIT_ESD_CARDSxJ),
                                    3)),
                      numberRHS);
                }
            es1s1s1s3:;
            } // End of DO block
        // IF CODE_LISTING_REQUESTED THEN (16135)
        if (1 & (bitToFixed (getBIT (1, mCODE_LISTING_REQUESTED))))
          // DO; (16136)
          {
          rs1s1s1s4:;
            // IF ESD# = 1 THEN (16137)
            if (1
                & (xEQ (COREHALFWORD (mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp),
                        1)))
              // DO; (16138)
              {
              rs1s1s1s4s1:;
                // CALL AHEADSET(1); (16139)
                {
                  putBITp (16, mOBJECT_GENERATORxAHEADSETxN,
                           fixedToBit (32, (int32_t)(1)));
                  OBJECT_GENERATORxAHEADSET (0);
                }
              es1s1s1s4s1:;
              } // End of DO block
            // S2 = LEFTHEX(SHL(ESD#,16),4); (16140)
            {
              descriptor_t *stringRHS;
              stringRHS
                  = (putFIXED (mOBJECT_GENERATORxLEFTHEXxF,
                               SHL (COREHALFWORD (
                                        mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp),
                                    16)),
                     putBITp (16, mOBJECT_GENERATORxLEFTHEXxN,
                              fixedToBit (32, (int32_t)(4))),
                     OBJECT_GENERATORxLEFTHEX (0));
              putCHARACTER (mOBJECT_GENERATORxS2, stringRHS);
              stringRHS->inUse = 0;
            }
            // S1 = BLANK || S1 || ESD_CHAR(ESD_TYPE(ESD#)); (16141)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  xsCAT (getCHARACTER (mBLANK),
                         getCHARACTER (mOBJECT_GENERATORxS1)),
                  getCHARACTER (
                      mOBJECT_GENERATORxESD_CHAR
                      + 4
                            * BYTE0 (
                                mESD_TYPE
                                + 1
                                      * COREHALFWORD (
                                          mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp))));
              putCHARACTER (mOBJECT_GENERATORxS1, stringRHS);
              stringRHS->inUse = 0;
            }
            // IF ESD_TYPE(ESD#) < 1 | ESD_TYPE(ESD#) > 2 THEN (16142)
            if (1
                & (xOR (
                    xLT (BYTE0 (
                             mESD_TYPE
                             + 1
                                   * COREHALFWORD (
                                       mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
                         1),
                    xGT (BYTE0 (
                             mESD_TYPE
                             + 1
                                   * COREHALFWORD (
                                       mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
                         2))))
              // DO; (16143)
              {
              rs1s1s1s4s2:;
                // S1 = S1 || S2; (16144)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (getCHARACTER (mOBJECT_GENERATORxS1),
                                     getCHARACTER (mOBJECT_GENERATORxS2));
                  putCHARACTER (mOBJECT_GENERATORxS1, stringRHS);
                  stringRHS->inUse = 0;
                }
                // S2 = LEFTHEX(SHL(ORIGIN(ESD#),8),6); (16145)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = (putFIXED (
                             mOBJECT_GENERATORxLEFTHEXxF,
                             SHL (
                                 getFIXED (
                                     mORIGIN
                                     + 4
                                           * COREHALFWORD (
                                               mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
                                 8)),
                         putBITp (16, mOBJECT_GENERATORxLEFTHEXxN,
                                  fixedToBit (32, (int32_t)(6))),
                         OBJECT_GENERATORxLEFTHEX (0));
                  putCHARACTER (mOBJECT_GENERATORxS2, stringRHS);
                  stringRHS->inUse = 0;
                }
                // S1 = S1 || S2; (16146)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (getCHARACTER (mOBJECT_GENERATORxS1),
                                     getCHARACTER (mOBJECT_GENERATORxS2));
                  putCHARACTER (mOBJECT_GENERATORxS1, stringRHS);
                  stringRHS->inUse = 0;
                }
                // S2=LEFTHEX(SHL(LOCCTR(ESD#),8),6); (16147)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = (putFIXED (
                             mOBJECT_GENERATORxLEFTHEXxF,
                             SHL (
                                 getFIXED (
                                     mLOCCTR
                                     + 4
                                           * COREHALFWORD (
                                               mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
                                 8)),
                         putBITp (16, mOBJECT_GENERATORxLEFTHEXxN,
                                  fixedToBit (32, (int32_t)(6))),
                         OBJECT_GENERATORxLEFTHEX (0));
                  putCHARACTER (mOBJECT_GENERATORxS2, stringRHS);
                  stringRHS->inUse = 0;
                }
                // S2=S2||'  '||FORMAT(LOCCTR(ESD#),10); (16148)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (
                      xsCAT (getCHARACTER (mOBJECT_GENERATORxS2),
                             cToDescriptor (NULL, "  ")),
                      (putFIXED (
                           mFORMATxIVAL,
                           getFIXED (
                               mLOCCTR
                               + 4
                                     * COREHALFWORD (
                                         mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp))),
                       putFIXED (mFORMATxN, 10), FORMAT (0)));
                  putCHARACTER (mOBJECT_GENERATORxS2, stringRHS);
                  stringRHS->inUse = 0;
                }
                // S1=S1 || S2; (16149)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (getCHARACTER (mOBJECT_GENERATORxS1),
                                     getCHARACTER (mOBJECT_GENERATORxS2));
                  putCHARACTER (mOBJECT_GENERATORxS1, stringRHS);
                  stringRHS->inUse = 0;
                }
              es1s1s1s4s2:;
              } // End of DO block
            // ELSE (16150)
            else
              // IF ESD_TYPE(ESD#) = 1 THEN (16151)
              if (1
                  & (xEQ (
                      BYTE0 (mESD_TYPE
                             + 1
                                   * COREHALFWORD (
                                       mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
                      1)))
                // DO; (16152)
                {
                rs1s1s1s4s3:;
                  // S2 = LEFTHEX(SHL(SYT_ADDR(ESD_LINK(ESD#)),8),6); (16153)
                  {
                    descriptor_t *stringRHS;
                    stringRHS
                        = (putFIXED (
                               mOBJECT_GENERATORxLEFTHEXxF,
                               SHL (
                                   getFIXED (
                                       getFIXED (mSYM_TAB)
                                       + 34
                                             * (COREHALFWORD (
                                                 mESD_LINK
                                                 + 2
                                                       * COREHALFWORD (
                                                           mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)))
                                       + 4 + 4 * (0)),
                                   8)),
                           putBITp (16, mOBJECT_GENERATORxLEFTHEXxN,
                                    fixedToBit (32, (int32_t)(6))),
                           OBJECT_GENERATORxLEFTHEX (0));
                    putCHARACTER (mOBJECT_GENERATORxS2, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // S1 = S1 || SUBSTR(X72, 67) || S2; (16154)
                  {
                    descriptor_t *stringRHS;
                    stringRHS
                        = xsCAT (xsCAT (getCHARACTER (mOBJECT_GENERATORxS1),
                                        SUBSTR2 (getCHARACTER (mX72), 67)),
                                 getCHARACTER (mOBJECT_GENERATORxS2));
                    putCHARACTER (mOBJECT_GENERATORxS1, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // S2 = LEFTHEX(SHL(SYT_BASE(ESD_LINK(ESD#)),16),4); (16155)
                  {
                    descriptor_t *stringRHS;
                    stringRHS
                        = (putFIXED (
                               mOBJECT_GENERATORxLEFTHEXxF,
                               SHL (
                                   COREHALFWORD (
                                       getFIXED (mP2SYMS)
                                       + 12
                                             * (COREHALFWORD (
                                                 mESD_LINK
                                                 + 2
                                                       * COREHALFWORD (
                                                           mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)))
                                       + 4 + 2 * (0)),
                                   16)),
                           putBITp (16, mOBJECT_GENERATORxLEFTHEXxN,
                                    fixedToBit (32, (int32_t)(4))),
                           OBJECT_GENERATORxLEFTHEX (0));
                    putCHARACTER (mOBJECT_GENERATORxS2, stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // S1 = S1 || SUBSTR(X72, 53) || S2; (16156)
                  {
                    descriptor_t *stringRHS;
                    stringRHS
                        = xsCAT (xsCAT (getCHARACTER (mOBJECT_GENERATORxS1),
                                        SUBSTR2 (getCHARACTER (mX72), 53)),
                                 getCHARACTER (mOBJECT_GENERATORxS2));
                    putCHARACTER (mOBJECT_GENERATORxS1, stringRHS);
                    stringRHS->inUse = 0;
                  }
                es1s1s1s4s3:;
                } // End of DO block
              // ELSE (16157)
              else
                // S1 = S1 || S2 || SUBSTR(X72, 46); (16158)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = xsCAT (xsCAT (getCHARACTER (mOBJECT_GENERATORxS1),
                                      getCHARACTER (mOBJECT_GENERATORxS2)),
                               SUBSTR2 (getCHARACTER (mX72), 46));
                  putCHARACTER (mOBJECT_GENERATORxS1, stringRHS);
                  stringRHS->inUse = 0;
                }
            // IF ESD# <= PROCLIMIT THEN (16159)
            if (1
                & (xLE (COREHALFWORD (mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp),
                        COREHALFWORD (mPROCLIMIT))))
              // S1 = S1 || SUBSTR(X72, 63) || SYT_NAME(PROC_LEVEL(ESD#));
              // (16160)
              {
                descriptor_t *stringRHS;
                stringRHS = xsCAT (
                    xsCAT (getCHARACTER (mOBJECT_GENERATORxS1),
                           SUBSTR2 (getCHARACTER (mX72), 63)),
                    getCHARACTER (
                        getFIXED (mSYM_TAB)
                        + 34
                              * (COREHALFWORD (
                                  mPROC_LEVEL
                                  + 2
                                        * COREHALFWORD (
                                            mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)))
                        + 0 + 4 * (0)));
                putCHARACTER (mOBJECT_GENERATORxS1, stringRHS);
                stringRHS->inUse = 0;
              }
            // CALL APRINT(S1); (16161)
            {
              putCHARACTERp (mOBJECT_GENERATORxAPRINTxLINE,
                             getCHARACTER (mOBJECT_GENERATORxS1));
              OBJECT_GENERATORxAPRINT (0);
            }
          es1s1s1s4:;
          } // End of DO block
        // ESD# = ESD# + 1; (16162)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREHALFWORD (mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp, bitRHS);
          bitRHS->inUse = 0;
        }
      es1s1s1:;
      } // End of DO block
      // ELSE (16163)
      else
          // IF ENTRYPOINT > 0 THEN (16164)
          if (1 & (xGT (COREHALFWORD (mENTRYPOINT), 0)))
      // DO; (16165)
      {
      rs1s1s2:;
        // ESD# = ESD# - 1; (16166)
        {
          int32_t numberRHS = (int32_t)(xsubtract (
              COREHALFWORD (mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp, bitRHS);
          bitRHS->inUse = 0;
        }
        // CALL ENTER_ESD(SYT_NAME(ENTRYPOINT), ESD#, 1); (16167)
        {
          putCHARACTERp (mENTER_ESDxNAME,
                         getCHARACTER (getFIXED (mSYM_TAB)
                                       + 34 * (COREHALFWORD (mENTRYPOINT)) + 0
                                       + 4 * (0)));
          putBITp (16, mENTER_ESDxPTR,
                   getBIT (16, mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp));
          putBITp (16, mENTER_ESDxTYP, fixedToBit (32, (int32_t)(1)));
          ENTER_ESD (0);
        }
        // ESD_LINK(ESD#) = ENTRYPOINT; (16168)
        {
          descriptor_t *bitRHS = getBIT (16, mENTRYPOINT);
          putBIT (
              16,
              mESD_LINK
                  + 2 * (COREHALFWORD (mOBJECT_GENERATORxEMIT_ESD_CARDSxESDp)),
              bitRHS);
          bitRHS->inUse = 0;
        }
        // ENTRYPOINT = SYT_LINK1(ENTRYPOINT); (16169)
        {
          descriptor_t *bitRHS = getBIT (
              16, getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mENTRYPOINT)) + 24
                      + 2 * (0));
          putBIT (16, mENTRYPOINT, bitRHS);
          bitRHS->inUse = 0;
        }
        // GO TO DO_ESD#; (16170)
        goto DO_ESDp;
      es1s1s2:;
      } // End of DO block
      // ELSE (16171)
      else
      // EMITTING_ESDS = FALSE; (16172)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mOBJECT_GENERATORxEMIT_ESD_CARDSxEMITTING_ESDS, bitRHS);
        bitRHS->inUse = 0;
      }
      if (0)
        {
        rs1s1:
          continue;
        es1s1:
          break;
        } // loop of block labeled DO_J
    }
} // End of DO for-loop block
if (0)
  {
  rs1:
    continue;
  es1:
    break;
  } // block labeled DO_EMITTING_ESDS
} // End of DO WHILE block
{
  reentryGuard = 0;
  return 0;
}
}
