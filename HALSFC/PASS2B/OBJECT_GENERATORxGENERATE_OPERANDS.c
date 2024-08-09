/*
  File OBJECT_GENERATORxGENERATE_OPERANDS.c generated by XCOM-I, 2024-08-09
  12:41:33.
*/

#include "runtimeC.h"

descriptor_t *
OBJECT_GENERATORxGENERATE_OPERANDS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "OBJECT_GENERATORxGENERATE_OPERANDS");
// CASE0001: (15107)
CASE0001:
  // DO CASE SHR(INST, 6); (15108)
  {
  rs1:
    switch (SHR (getFIXED (mINST), 6))
      {
      case 0:
        // DO; (15110)
        {
        rs1s1:;
          // IF INST = LFXI THEN (15110)
          if (1 & (xEQ (getFIXED (mINST), BYTE0 (mLFXI))))
            // T = 'R'||R||COMMA||IX-2; (15111)
            {
              descriptor_t *stringRHS;
              stringRHS
                  = xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "R"),
                                         fixedToCharacter (getFIXED (mR))),
                                  getCHARACTER (mCOMMA)),
                           fixedToCharacter (xsubtract (getFIXED (mIX), 2)));
              putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT, stringRHS);
              stringRHS->inUse = 0;
            }
          // ELSE (15112)
          else
            // IF INST = LFLI THEN (15113)
            if (1 & (xEQ (getFIXED (mINST), BYTE0 (mLFLI))))
              // T = 'F'||R||COMMA||IX; (15114)
              {
                descriptor_t *stringRHS;
                stringRHS
                    = xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "F"),
                                           fixedToCharacter (getFIXED (mR))),
                                    getCHARACTER (mCOMMA)),
                             fixedToCharacter (getFIXED (mIX)));
                putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                              stringRHS);
                stringRHS->inUse = 0;
              }
            // ELSE (15115)
            else
              // IF INST = BCR | INST = BCRE | INST = SRET  | INST = SPM THEN
              // (15116)
              if (1
                  & (xOR (xOR (xOR (xEQ (getFIXED (mINST), BYTE0 (mBCR)),
                                    xEQ (getFIXED (mINST), BYTE0 (mBCRE))),
                               xEQ (getFIXED (mINST), BYTE0 (mSRET))),
                          xEQ (getFIXED (mINST), BYTE0 (mSPM)))))
                // T = R||COMMA||'R'||IX; (15117)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = xsCAT (xsCAT (xsCAT (fixedToCharacter (getFIXED (mR)),
                                             getCHARACTER (mCOMMA)),
                                      cToDescriptor (NULL, "R")),
                               fixedToCharacter (getFIXED (mIX)));
                  putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                stringRHS);
                  stringRHS->inUse = 0;
                }
              // ELSE (15118)
              else
                // IF INST = CVFX THEN (15119)
                if (1 & (xEQ (getFIXED (mINST), BYTE0 (mCVFX))))
                  // T = 'R'||R||COMMA||'F'||IX; (15120)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = xsCAT (
                        xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "R"),
                                             fixedToCharacter (getFIXED (mR))),
                                      getCHARACTER (mCOMMA)),
                               cToDescriptor (NULL, "F")),
                        fixedToCharacter (getFIXED (mIX)));
                    putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                  stringRHS);
                    stringRHS->inUse = 0;
                  }
                // ELSE (15121)
                else
                  // IF INST = CVFL THEN (15122)
                  if (1 & (xEQ (getFIXED (mINST), BYTE0 (mCVFL))))
                    // T = 'F'||R||COMMA||'R'||IX; (15123)
                    {
                      descriptor_t *stringRHS;
                      stringRHS = xsCAT (
                          xsCAT (
                              xsCAT (xsCAT (cToDescriptor (NULL, "F"),
                                            fixedToCharacter (getFIXED (mR))),
                                     getCHARACTER (mCOMMA)),
                              cToDescriptor (NULL, "R")),
                          fixedToCharacter (getFIXED (mIX)));
                      putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                    stringRHS);
                      stringRHS->inUse = 0;
                    }
                  // ELSE (15124)
                  else
                    // IF INST > CVFX & INST < CVFL THEN (15125)
                    if (1
                        & (xAND (xGT (getFIXED (mINST), BYTE0 (mCVFX)),
                                 xLT (getFIXED (mINST), BYTE0 (mCVFL)))))
                      // T = 'F'||R||COMMA||'F'||IX; (15126)
                      {
                        descriptor_t *stringRHS;
                        stringRHS = xsCAT (
                            xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "F"),
                                                 fixedToCharacter (
                                                     getFIXED (mR))),
                                          getCHARACTER (mCOMMA)),
                                   cToDescriptor (NULL, "F")),
                            fixedToCharacter (getFIXED (mIX)));
                        putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                      stringRHS);
                        stringRHS->inUse = 0;
                      }
                    // ELSE (15127)
                    else
                      // T = 'R'||R||COMMA||'R'||IX; (15128)
                      {
                        descriptor_t *stringRHS;
                        stringRHS = xsCAT (
                            xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "R"),
                                                 fixedToCharacter (
                                                     getFIXED (mR))),
                                          getCHARACTER (mCOMMA)),
                                   cToDescriptor (NULL, "R")),
                            fixedToCharacter (getFIXED (mIX)));
                        putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                      stringRHS);
                        stringRHS->inUse = 0;
                      }
          // CALL EXECUTION_TIMES(0); (15129)
          {
            putBITp (4, mOBJECT_GENERATORxGENERATE_OPERANDSxEXECUTION_TIMESxM,
                     fixedToBit (32, (int32_t)(0)));
            OBJECT_GENERATORxGENERATE_OPERANDSxEXECUTION_TIMES (0);
          }
        es1s1:;
        } // End of DO block
        break;
      case 1:
      // CASE_RX: (15131)
      CASE_RX:
        {
        rs1s2:;
          // IF IX=0 THEN (15132)
          if (1 & (xEQ (getFIXED (mIX), 0)))
            // T = CHECK_NO_BASE_RS; (15133)
            {
              descriptor_t *stringRHS;
              stringRHS = OBJECT_GENERATORxCHECK_NO_BASE_RS (0);
              putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT, stringRHS);
              stringRHS->inUse = 0;
            }
          // ELSE (15134)
          else
            // T = LEFTBRACKET||'R'||IX||COMMA||'R'||B||RIGHTBRACKET; (15135)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  xsCAT (
                      xsCAT (xsCAT (xsCAT (xsCAT (getCHARACTER (mLEFTBRACKET),
                                                  cToDescriptor (NULL, "R")),
                                           fixedToCharacter (getFIXED (mIX))),
                                    getCHARACTER (mCOMMA)),
                             cToDescriptor (NULL, "R")),
                      fixedToCharacter (getFIXED (mB))),
                  getCHARACTER (mRIGHTBRACKET));
              putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT, stringRHS);
              stringRHS->inUse = 0;
            }
          // T = R||COMMA||D||T; (15136)
          {
            descriptor_t *stringRHS;
            stringRHS
                = xsCAT (xsCAT (xsCAT (fixedToCharacter (getFIXED (mR)),
                                       getCHARACTER (mCOMMA)),
                                fixedToCharacter (getFIXED (mD))),
                         getCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT));
            putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT, stringRHS);
            stringRHS->inUse = 0;
          }
          // IF INST >=  96 & INST <=  126 THEN (15137)
          if (1
              & (xAND (xGE (getFIXED (mINST), 96),
                       xLE (getFIXED (mINST), 126))))
            // T = 'F'||T; (15138)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  cToDescriptor (NULL, "F"),
                  getCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT));
              putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT, stringRHS);
              stringRHS->inUse = 0;
            }
          // ELSE (15139)
          else
            // IF INST ~= BC   & INST ~= BVC    THEN (15140)
            if (1
                & (xAND (xNEQ (getFIXED (mINST), BYTE0 (mBC)),
                         xNEQ (getFIXED (mINST), COREHALFWORD (mBVC)))))
              // T = 'R'||T; (15141)
              {
                descriptor_t *stringRHS;
                stringRHS = xsCAT (
                    cToDescriptor (NULL, "R"),
                    getCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT));
                putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                              stringRHS);
                stringRHS->inUse = 0;
              }
          // IF IX ~= 0 & D > 2047 THEN (15142)
          if (1 & (xAND (xNEQ (getFIXED (mIX), 0), xGT (getFIXED (mD), 2047))))
            // CALL ERRORS(CLASS_BI,512); (15143)
            {
              putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
              putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(512)));
              ERRORS (0);
            }
          // IF IX = 0 & D > 65535 THEN (15144)
          if (1 & (xAND (xEQ (getFIXED (mIX), 0), xGT (getFIXED (mD), 65535))))
            // CALL ERRORS(CLASS_BI,514); (15145)
            {
              putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
              putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(514)));
              ERRORS (0);
            }
          // IF LHS = SRSTYPE & D >= 56 THEN (15146)
          if (1
              & (xAND (xEQ (COREHALFWORD (mLHS), BYTE0 (mSRSTYPE)),
                       xGE (getFIXED (mD), 56))))
            // IF (INST >=  80 & INST <  128 & (SHR(D,1) >= 56)) |  ~(INST >=
            // 80 & INST <  128) THEN (15147)
            if (1
                & (xOR (xAND (xAND (xGE (getFIXED (mINST), 80),
                                    xLT (getFIXED (mINST), 128)),
                              xGE (SHR (getFIXED (mD), 1), 56)),
                        xNOT (xAND (xGE (getFIXED (mINST), 80),
                                    xLT (getFIXED (mINST), 128))))))
              // CALL ERRORS(CLASS_BI,515,'SRS'); (15148)
              {
                putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
                putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(515)));
                putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "SRS"));
                ERRORS (0);
              }
          // CALL EXECUTION_TIMES(1); (15149)
          {
            putBITp (4, mOBJECT_GENERATORxGENERATE_OPERANDSxEXECUTION_TIMESxM,
                     fixedToBit (32, (int32_t)(1)));
            OBJECT_GENERATORxGENERATE_OPERANDSxEXECUTION_TIMES (0);
          }
        es1s2:;
        } // End of DO block
        break;
      case 2:
        // DO; (15151)
        {
        rs1s3:;
          // IF INST >=  144 & INST <=  159 THEN (15151)
          if (1
              & (xAND (xGE (getFIXED (mINST), 144),
                       xLE (getFIXED (mINST), 159))))
            // DO; (15152)
            {
            rs1s3s1:;
              // IF IX = 0 THEN (15153)
              if (1 & (xEQ (getFIXED (mIX), 0)))
                // T = D||CHECK_NO_BASE_RS; (15154)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (fixedToCharacter (getFIXED (mD)),
                                     OBJECT_GENERATORxCHECK_NO_BASE_RS (0));
                  putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                stringRHS);
                  stringRHS->inUse = 0;
                }
              // ELSE (15155)
              else
                // T = D||LEFTBRACKET||'R'||IX||COMMA||'R'||B||RIGHTBRACKET;
                // (15156)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (
                      xsCAT (
                          xsCAT (
                              xsCAT (xsCAT (xsCAT (xsCAT (fixedToCharacter (
                                                              getFIXED (mD)),
                                                          getCHARACTER (
                                                              mLEFTBRACKET)),
                                                   cToDescriptor (NULL, "R")),
                                            fixedToCharacter (getFIXED (mIX))),
                                     getCHARACTER (mCOMMA)),
                              cToDescriptor (NULL, "R")),
                          fixedToCharacter (getFIXED (mB))),
                      getCHARACTER (mRIGHTBRACKET));
                  putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                stringRHS);
                  stringRHS->inUse = 0;
                }
              // IF IX ~= 0 & D > 2047 THEN (15157)
              if (1
                  & (xAND (xNEQ (getFIXED (mIX), 0),
                           xGT (getFIXED (mD), 2047))))
                // CALL ERRORS(CLASS_BI,512); (15158)
                {
                  putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
                  putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(512)));
                  ERRORS (0);
                }
            es1s3s1:;
            } // End of DO block
          // ELSE (15159)
          else
            // IF INST >=  176 & INST <=  191 THEN (15160)
            if (1
                & (xAND (xGE (getFIXED (mINST), 176),
                         xLE (getFIXED (mINST), 191))))
              // T=D||LEFTBRACKET||'R'||B||'),'||RHS(1); (15161)
              {
                descriptor_t *stringRHS;
                stringRHS = xsCAT (
                    xsCAT (
                        xsCAT (xsCAT (xsCAT (fixedToCharacter (getFIXED (mD)),
                                             getCHARACTER (mLEFTBRACKET)),
                                      cToDescriptor (NULL, "R")),
                               fixedToCharacter (getFIXED (mB))),
                        cToDescriptor (NULL, "),")),
                    bitToCharacter (getBIT (16, mRHS + 2 * 1)));
                putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                              stringRHS);
                stringRHS->inUse = 0;
              }
            // ELSE (15162)
            else
              // IF B = 0 THEN (15163)
              if (1 & (xEQ (getFIXED (mB), 0)))
                // T='R'||R||COMMA||D; (15164)
                {
                  descriptor_t *stringRHS;
                  stringRHS
                      = xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "R"),
                                             fixedToCharacter (getFIXED (mR))),
                                      getCHARACTER (mCOMMA)),
                               fixedToCharacter (getFIXED (mD)));
                  putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                stringRHS);
                  stringRHS->inUse = 0;
                }
              // ELSE (15165)
              else
                // IF INST = LHI THEN (15166)
                if (1 & (xEQ (getFIXED (mINST), BYTE0 (mLHI))))
                  // T='R'||R||COMMA||D||LEFTBRACKET||RIGHTBRACKET; (15167)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = xsCAT (
                        xsCAT (xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "R"),
                                                    fixedToCharacter (
                                                        getFIXED (mR))),
                                             getCHARACTER (mCOMMA)),
                                      fixedToCharacter (getFIXED (mD))),
                               getCHARACTER (mLEFTBRACKET)),
                        getCHARACTER (mRIGHTBRACKET));
                    putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                  stringRHS);
                    stringRHS->inUse = 0;
                  }
                // ELSE (15168)
                else
                  // IF INST <  128 | INST >  135 THEN (15169)
                  if (1
                      & (xOR (xLT (getFIXED (mINST), 128),
                              xGT (getFIXED (mINST), 135))))
                    // T='R'||R||COMMA||D||LEFTBRACKET||'R'||ABS(B)||RIGHTBRACKET;
                    // (15170)
                    {
                      descriptor_t *stringRHS;
                      stringRHS = xsCAT (
                          xsCAT (
                              xsCAT (
                                  xsCAT (
                                      xsCAT (xsCAT (xsCAT (cToDescriptor (NULL,
                                                                          "R"),
                                                           fixedToCharacter (
                                                               getFIXED (mR))),
                                                    getCHARACTER (mCOMMA)),
                                             fixedToCharacter (getFIXED (mD))),
                                      getCHARACTER (mLEFTBRACKET)),
                                  cToDescriptor (NULL, "R")),
                              fixedToCharacter (ABS (getFIXED (mB)))),
                          getCHARACTER (mRIGHTBRACKET));
                      putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                    stringRHS);
                      stringRHS->inUse = 0;
                    }
                  // ELSE (15171)
                  else
                    // DO; (15172)
                    {
                    rs1s3s2:;
                      // T = R||COMMA||'*'; (15173)
                      {
                        descriptor_t *stringRHS;
                        stringRHS
                            = xsCAT (xsCAT (fixedToCharacter (getFIXED (mR)),
                                            getCHARACTER (mCOMMA)),
                                     cToDescriptor (NULL, "*"));
                        putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                      stringRHS);
                        stringRHS->inUse = 0;
                      }
                      // IF (RHS & 2) = 0 | D = 0 THEN (15174)
                      if (1
                          & (xOR (xEQ (xAND (COREHALFWORD (mRHS), 2), 0),
                                  xEQ (getFIXED (mD), 0))))
                        // T = T || PLUS || D+1; (15175)
                        {
                          descriptor_t *stringRHS;
                          stringRHS = xsCAT (
                              xsCAT (
                                  getCHARACTER (
                                      mOBJECT_GENERATORxGENERATE_OPERANDSxT),
                                  getCHARACTER (mPLUS)),
                              fixedToCharacter (xadd (getFIXED (mD), 1)));
                          putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                        stringRHS);
                          stringRHS->inUse = 0;
                        }
                      // ELSE (15176)
                      else
                        // T = T || -D+1; (15177)
                        {
                          descriptor_t *stringRHS;
                          stringRHS = xsCAT (
                              getCHARACTER (
                                  mOBJECT_GENERATORxGENERATE_OPERANDSxT),
                              fixedToCharacter (
                                  xadd (xminus (getFIXED (mD)), 1)));
                          putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                        stringRHS);
                          stringRHS->inUse = 0;
                        }
                      // IF INST = BCTB THEN (15178)
                      if (1 & (xEQ (getFIXED (mINST), BYTE0 (mBCTB))))
                        // T = 'R'||T; (15179)
                        {
                          descriptor_t *stringRHS;
                          stringRHS = xsCAT (
                              cToDescriptor (NULL, "R"),
                              getCHARACTER (
                                  mOBJECT_GENERATORxGENERATE_OPERANDSxT));
                          putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                        stringRHS);
                          stringRHS->inUse = 0;
                        }
                    es1s3s2:;
                    } // End of DO block
          // IF IX = 0 & D > 65535 THEN (15180)
          if (1 & (xAND (xEQ (getFIXED (mIX), 0), xGT (getFIXED (mD), 65535))))
            // CALL ERRORS(CLASS_BI,514); (15181)
            {
              putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
              putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(514)));
              ERRORS (0);
            }
          // IF LHS = SRSTYPE & D >= 56 THEN (15182)
          if (1
              & (xAND (xEQ (COREHALFWORD (mLHS), BYTE0 (mSRSTYPE)),
                       xGE (getFIXED (mD), 56))))
            // CALL ERRORS(CLASS_BI,515,'SRS'); (15183)
            {
              putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
              putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(515)));
              putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "SRS"));
              ERRORS (0);
            }
          // IF LHS = SSTYPE & D >= 56 THEN (15184)
          if (1
              & (xAND (xEQ (COREHALFWORD (mLHS), BYTE0 (mSSTYPE)),
                       xGE (getFIXED (mD), 56))))
            // CALL ERRORS(CLASS_BI,515,'SI'); (15185)
            {
              putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
              putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(515)));
              putCHARACTERp (mERRORSxTEXT, cToDescriptor (NULL, "SI"));
              ERRORS (0);
            }
          // CALL EXECUTION_TIMES(2); (15186)
          {
            putBITp (4, mOBJECT_GENERATORxGENERATE_OPERANDSxEXECUTION_TIMESxM,
                     fixedToBit (32, (int32_t)(2)));
            OBJECT_GENERATORxGENERATE_OPERANDSxEXECUTION_TIMES (0);
          }
        es1s3:;
        } // End of DO block
        break;
      case 3:
        // DO; (15188)
        {
        rs1s4:;
          // IF (INST = LDM) THEN (15188)
          if (1 & (xEQ (getFIXED (mINST), BYTE0 (mLDM))))
            // DO; (15189)
            {
            rs1s4s1:;
              // IF IX = 0 THEN (15190)
              if (1 & (xEQ (getFIXED (mIX), 0)))
                // T = D||CHECK_NO_BASE_RS; (15191)
                {
                  descriptor_t *stringRHS;
                  stringRHS = xsCAT (fixedToCharacter (getFIXED (mD)),
                                     OBJECT_GENERATORxCHECK_NO_BASE_RS (0));
                  putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                stringRHS);
                  stringRHS->inUse = 0;
                }
              // ELSE (15192)
              else
                // DO; (15193)
                {
                rs1s4s1s1:;
                  // T = 'R'||IX||COMMA||'R'||B; (15194)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = xsCAT (
                        xsCAT (
                            xsCAT (xsCAT (cToDescriptor (NULL, "R"),
                                          fixedToCharacter (getFIXED (mIX))),
                                   getCHARACTER (mCOMMA)),
                            cToDescriptor (NULL, "R")),
                        fixedToCharacter (getFIXED (mB)));
                    putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                  stringRHS);
                    stringRHS->inUse = 0;
                  }
                  // T = D||LEFTBRACKET||T||RIGHTBRACKET; (15195)
                  {
                    descriptor_t *stringRHS;
                    stringRHS = xsCAT (
                        xsCAT (xsCAT (fixedToCharacter (getFIXED (mD)),
                                      getCHARACTER (mLEFTBRACKET)),
                               getCHARACTER (
                                   mOBJECT_GENERATORxGENERATE_OPERANDSxT)),
                        getCHARACTER (mRIGHTBRACKET));
                    putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                                  stringRHS);
                    stringRHS->inUse = 0;
                  }
                es1s4s1s1:;
                } // End of DO block
              // IF IX ~= 0 & D > 2047 THEN (15196)
              if (1
                  & (xAND (xNEQ (getFIXED (mIX), 0),
                           xGT (getFIXED (mD), 2047))))
                // CALL ERRORS(CLASS_BI,512); (15197)
                {
                  putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
                  putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(512)));
                  ERRORS (0);
                }
              // IF IX = 0 & D > 65535 THEN (15198)
              if (1
                  & (xAND (xEQ (getFIXED (mIX), 0),
                           xGT (getFIXED (mD), 65535))))
                // CALL ERRORS(CLASS_BI,514); (15199)
                {
                  putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
                  putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(514)));
                  ERRORS (0);
                }
            es1s4s1:;
            } // End of DO block
          // ELSE (15200)
          else
            // IF (INST = SRR) THEN (15201)
            if (1 & (xEQ (getFIXED (mINST), BYTE0 (mSRR))))
              // T='R'||R||COMMA||D; (15202)
              {
                descriptor_t *stringRHS;
                stringRHS
                    = xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "R"),
                                           fixedToCharacter (getFIXED (mR))),
                                    getCHARACTER (mCOMMA)),
                             fixedToCharacter (getFIXED (mD)));
                putCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT,
                              stringRHS);
                stringRHS->inUse = 0;
              }
            // ELSE (15203)
            else
              // GO TO CASE_RX; (15204)
              goto CASE_RX;
          // CALL EXECUTION_TIMES(3); (15205)
          {
            putBITp (4, mOBJECT_GENERATORxGENERATE_OPERANDSxEXECUTION_TIMESxM,
                     fixedToBit (32, (int32_t)(3)));
            OBJECT_GENERATORxGENERATE_OPERANDSxEXECUTION_TIMES (0);
          }
        es1s4:;
        } // End of DO block
        break;
      }
  } // End of DO CASE block
  // RETURN PAD(T, 20); (15206)
  {
    reentryGuard = 0;
    return (
        putCHARACTERp (mPADxSTRING,
                       getCHARACTER (mOBJECT_GENERATORxGENERATE_OPERANDSxT)),
        putFIXED (mPADxWIDTH, 20), PAD (0));
  }
}
