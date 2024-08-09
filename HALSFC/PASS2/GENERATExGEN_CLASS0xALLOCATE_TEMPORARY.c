/*
  File GENERATExGEN_CLASS0xALLOCATE_TEMPORARY.c generated by XCOM-I, 2024-08-09
  12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xALLOCATE_TEMPORARY (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS0xALLOCATE_TEMPORARY");
  // IF DOTEMP(DOLEVEL) ~= 0 THEN (12199)
  if (1
      & (xNEQ (COREHALFWORD (mGENERATExDOTEMP + 2 * COREHALFWORD (mDOLEVEL)),
               0)))
    // RETURN; (12200)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF INREG THEN (12201)
  if (1
      & (bitToFixed (
          getBIT (1, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxINREG))))
    // DO; (12202)
    {
    rs1:;
      // INREG = FALSE; (12203)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxINREG, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF LAST_ASSIGN_LINE(PTR) = LINE# THEN (12204)
      if (1
          & (xEQ (
              bitToFixed ((
                  putBITp (
                      16,
                      mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINExPTR,
                      getBIT (16,
                              mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR)),
                  GENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINE (
                      0))),
              getFIXED (mLINEp))))
        // DO; (12205)
        {
        rs1s1:;
          // SYT_BASE(PTR) = TEMPBASE; (12206)
          {
            descriptor_t *bitRHS = getBIT (8, mTEMPBASE);
            putBIT (16,
                    getFIXED (mP2SYMS)
                        + 12
                              * (COREHALFWORD (
                                  mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                        + 4 + 2 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // SYT_DISP(PTR) = 0; (12207)
          {
            int32_t numberRHS = (int32_t)(0);
            putBIT (16,
                    getFIXED (mP2SYMS)
                        + 12
                              * (COREHALFWORD (
                                  mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                        + 6 + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
          // PTR = SYT_LINK1(PTR); (12208)
          {
            descriptor_t *bitRHS = getBIT (
                16, getFIXED (mSYM_TAB)
                        + 34
                              * (COREHALFWORD (
                                  mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                        + 24 + 2 * (0));
            putBIT (16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR, bitRHS);
            bitRHS->inUse = 0;
          }
          // DOTEMP(DOLEVEL) = -1; (12209)
          {
            int32_t numberRHS = (int32_t)(-1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGENERATExDOTEMP + 2 * (COREHALFWORD (mDOLEVEL)),
                    bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
    es1:;
    } // End of DO block
  // DO WHILE PTR ~= 0; (12210)
  while (
      1
      & (xNEQ (COREHALFWORD (mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR), 0)))
    {
      // IF SYT_DISP(PTR) >= 0 THEN (12211)
      if (1
          & (xGE (COREHALFWORD (
                      getFIXED (mP2SYMS)
                      + 12
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                      + 6 + 2 * (0)),
                  0)))
        // DO; (12212)
        {
        rs2s1:;
          // TYP = SYT_TYPE(PTR); (12213)
          {
            descriptor_t *bitRHS = getBIT (
                8, getFIXED (mSYM_TAB)
                       + 34
                             * (COREHALFWORD (
                                 mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                       + 32 + 1 * (0));
            putBIT (16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTYP, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF (SYT_FLAGS(PTR)&NAME_FLAG) ~= 0 THEN (12214)
          if (1
              & (xNEQ (
                  xAND (
                      getFIXED (
                          getFIXED (mSYM_TAB)
                          + 34
                                * (COREHALFWORD (
                                    mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                          + 8 + 4 * (0)),
                      getFIXED (mNAME_FLAG)),
                  0)))
            // DO; (12215)
            {
            rs2s1s1:;
              // IF (SYT_FLAGS(PTR)&REMOTE_FLAG) ~= 0 THEN (12216)
              if (1
                  & (xNEQ (
                      xAND (
                          getFIXED (
                              getFIXED (mSYM_TAB)
                              + 34
                                    * (COREHALFWORD (
                                        mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                              + 8 + 4 * (0)),
                          getFIXED (mREMOTE_FLAG)),
                      0)))
                // TEMP = GETFREESPACE(DINTEGER,1); (12217)
                {
                  int32_t numberRHS = (int32_t)((
                      putFIXED (mGENERATExGETFREESPACExOPTYPE,
                                BYTE0 (mDINTEGER)),
                      putFIXED (mGENERATExGETFREESPACExTEMPSPACE, 1),
                      GENERATExGETFREESPACE (0)));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP,
                          bitRHS);
                  bitRHS->inUse = 0;
                }
              // ELSE (12218)
              else
                // TEMP = GETFREESPACE(INTEGER, 1); (12219)
                {
                  int32_t numberRHS = (int32_t)((
                      putFIXED (mGENERATExGETFREESPACExOPTYPE,
                                BYTE0 (mINTEGER)),
                      putFIXED (mGENERATExGETFREESPACExTEMPSPACE, 1),
                      GENERATExGETFREESPACE (0)));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP,
                          bitRHS);
                  bitRHS->inUse = 0;
                }
            es2s1s1:;
            } // End of DO block
          // ELSE (12220)
          else
            // IF TYP = STRUCTURE THEN (12221)
            if (1
                & (xEQ (
                    COREHALFWORD (mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTYP),
                    BYTE0 (mSTRUCTURE))))
              // TEMP = GETFREESPACE(STRUCTURE, EXTENT(PTR)); (12222)
              {
                int32_t numberRHS = (int32_t)((
                    putFIXED (mGENERATExGETFREESPACExOPTYPE,
                              BYTE0 (mSTRUCTURE)),
                    putFIXED (
                        mGENERATExGETFREESPACExTEMPSPACE,
                        getFIXED (
                            getFIXED (mSYM_TAB)
                            + 34
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                            + 12 + 4 * (0))),
                    GENERATExGETFREESPACE (0)));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP,
                        bitRHS);
                bitRHS->inUse = 0;
              }
            // ELSE (12223)
            else
              // IF TYP = CHAR THEN (12224)
              if (1
                  & (xEQ (COREHALFWORD (
                              mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTYP),
                          BYTE0 (mCHAR))))
                // TEMP = GETFREESPACE(CHAR, LUMP_ARRAYSIZE(PTR) *
                // (CS(SYT_DIMS(PTR)+2)*2)); (12225)
                {
                  int32_t numberRHS = (int32_t)((
                      putFIXED (mGENERATExGETFREESPACExOPTYPE, BYTE0 (mCHAR)),
                      putFIXED (
                          mGENERATExGETFREESPACExTEMPSPACE,
                          xmultiply (
                              (putBITp (
                                   16, mGENERATExLUMP_ARRAYSIZExOP,
                                   getBIT (
                                       16,
                                       mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR)),
                               GENERATExLUMP_ARRAYSIZE (0)),
                              xmultiply (
                                  (putFIXED (
                                       mCSxLEN,
                                       xadd (
                                           COREHALFWORD (
                                               getFIXED (mSYM_TAB)
                                               + 34
                                                     * (COREHALFWORD (
                                                         mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                                               + 18 + 2 * (0)),
                                           2)),
                                   CS (0)),
                                  2))),
                      GENERATExGETFREESPACE (0)));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP,
                          bitRHS);
                  bitRHS->inUse = 0;
                }
              // ELSE (12226)
              else
                // TEMP = GETFREESPACE(TYP, LUMP_ARRAYSIZE(PTR) *
                // LUMP_TERMINALSIZE(PTR)); (12227)
                {
                  int32_t numberRHS = (int32_t)((
                      putFIXED (
                          mGENERATExGETFREESPACExOPTYPE,
                          COREHALFWORD (
                              mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTYP)),
                      putFIXED (
                          mGENERATExGETFREESPACExTEMPSPACE,
                          xmultiply (
                              (putBITp (
                                   16, mGENERATExLUMP_ARRAYSIZExOP,
                                   getBIT (
                                       16,
                                       mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR)),
                               GENERATExLUMP_ARRAYSIZE (0)),
                              (putBITp (
                                   16, mGENERATExLUMP_TERMINALSIZExOP,
                                   getBIT (
                                       16,
                                       mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR)),
                               GENERATExLUMP_TERMINALSIZE (0)))),
                      GENERATExGETFREESPACE (0)));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP,
                          bitRHS);
                  bitRHS->inUse = 0;
                }
          // IF PACKTYPE(TYP) = VECMAT THEN (12228)
          if (1
              & (xEQ (
                  BYTE0 (
                      mPACKTYPE
                      + 1
                            * COREHALFWORD (
                                mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTYP)),
                  BYTE0 (mVECMAT))))
            // IF ( (SYT_FLAGS(PTR) & TEMPORARY_FLAG) = 0 ) |  (
            // (SYT_FLAGS(PTR) & NAME_FLAG) = 0 )  THEN (12229)
            if (1
                & (xOR (
                    xEQ (
                        xAND (
                            getFIXED (
                                getFIXED (mSYM_TAB)
                                + 34
                                      * (COREHALFWORD (
                                          mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                                + 8 + 4 * (0)),
                            getFIXED (mTEMPORARY_FLAG)),
                        0),
                    xEQ (
                        xAND (
                            getFIXED (
                                getFIXED (mSYM_TAB)
                                + 34
                                      * (COREHALFWORD (
                                          mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                                + 8 + 4 * (0)),
                            getFIXED (mNAME_FLAG)),
                        0))))
              // DISP(TEMP) = DISP(TEMP) + BIGHTS(TYP); (12230)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    COREHALFWORD (
                        getFIXED (mIND_STACK)
                        + 73
                              * (COREHALFWORD (
                                  mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP))
                        + 30 + 2 * (0)),
                    BYTE0 (
                        mBIGHTS
                        + 1
                              * COREHALFWORD (
                                  mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTYP))));
                putBIT (
                    16,
                    getFIXED (mIND_STACK)
                        + 73
                              * (COREHALFWORD (
                                  mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP))
                        + 30 + 2 * (0),
                    fixedToBit (16, numberRHS));
              }
          // SYT_ADDR(PTR) = DISP(TEMP); (12231)
          {
            descriptor_t *bitRHS = getBIT (
                16,
                getFIXED (mIND_STACK)
                    + 73
                          * (COREHALFWORD (
                              mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP))
                    + 30 + 2 * (0));
            putFIXED (
                getFIXED (mSYM_TAB)
                    + 34
                          * (COREHALFWORD (
                              mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                    + 4 + 4 * (0),
                bitToFixed (bitRHS));
            bitRHS->inUse = 0;
          }
          // SYT_BASE(PTR) = BASE(TEMP); (12232)
          {
            descriptor_t *bitRHS = getBIT (
                16,
                getFIXED (mIND_STACK)
                    + 73
                          * (COREHALFWORD (
                              mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP))
                    + 22 + 2 * (0));
            putBIT (16,
                    getFIXED (mP2SYMS)
                        + 12
                              * (COREHALFWORD (
                                  mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                        + 4 + 2 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // IF ( (SYT_FLAGS(PTR) & TEMPORARY_FLAG) ~= 0 ) &  ( (SYT_FLAGS(PTR)
          // & NAME_FLAG) ~= 0 )  THEN (12233)
          if (1
              & (xAND (
                  xNEQ (
                      xAND (
                          getFIXED (
                              getFIXED (mSYM_TAB)
                              + 34
                                    * (COREHALFWORD (
                                        mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                              + 8 + 4 * (0)),
                          getFIXED (mTEMPORARY_FLAG)),
                      0),
                  xNEQ (
                      xAND (
                          getFIXED (
                              getFIXED (mSYM_TAB)
                              + 34
                                    * (COREHALFWORD (
                                        mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                              + 8 + 4 * (0)),
                          getFIXED (mNAME_FLAG)),
                      0))))
            // SYT_DISP(PTR) = DISP(TEMP); (12234)
            {
              descriptor_t *bitRHS = getBIT (
                  16,
                  getFIXED (mIND_STACK)
                      + 73
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP))
                      + 30 + 2 * (0));
              putBIT (
                  16,
                  getFIXED (mP2SYMS)
                      + 12
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                      + 6 + 2 * (0),
                  bitRHS);
              bitRHS->inUse = 0;
            }
          // ELSE (12235)
          else
            // SYT_DISP(PTR) = DISP(TEMP) + SYT_CONST(PTR); (12236)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  COREHALFWORD (
                      getFIXED (mIND_STACK)
                      + 73
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP))
                      + 30 + 2 * (0)),
                  getFIXED (
                      getFIXED (mP2SYMS)
                      + 12
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                      + 0 + 4 * (0))));
              putBIT (
                  16,
                  getFIXED (mP2SYMS)
                      + 12
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                      + 6 + 2 * (0),
                  fixedToBit (16, numberRHS));
            }
          // IF SYT_DISP(PTR) < 0 THEN (12237)
          if (1
              & (xLT (
                  COREHALFWORD (
                      getFIXED (mP2SYMS)
                      + 12
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                      + 6 + 2 * (0)),
                  0)))
            // CALL ERRORS(CLASS_BS,117,SYT_NAME(PTR)); (12238)
            {
              putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BS));
              putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(117)));
              putCHARACTERp (
                  mERRORSxTEXT,
                  getCHARACTER (
                      getFIXED (mSYM_TAB)
                      + 34
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                      + 0 + 4 * (0)));
              ERRORS (0);
            }
          // CALL SET_AUTO_IMPLIED(PTR); (12239)
          {
            putBITp (16, mGENERATExGEN_CLASS0xSET_AUTO_IMPLIEDxCPTR,
                     getBIT (16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR));
            GENERATExGEN_CLASS0xSET_AUTO_IMPLIED (0);
          }
          // ARRAYPOINT(LOC(TEMP)) = DOTEMP(DOLEVEL); (12240)
          {
            descriptor_t *bitRHS
                = getBIT (16, mGENERATExDOTEMP + 2 * COREHALFWORD (mDOLEVEL));
            putBIT (
                16,
                mARRAYPOINT
                    + 2
                          * (COREHALFWORD (
                              getFIXED (mIND_STACK)
                              + 73
                                    * (COREHALFWORD (
                                        mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP))
                              + 40 + 2 * (0))),
                bitRHS);
            bitRHS->inUse = 0;
          }
          // DOTEMP(DOLEVEL) = LOC(TEMP); (12241)
          {
            descriptor_t *bitRHS = getBIT (
                16,
                getFIXED (mIND_STACK)
                    + 73
                          * (COREHALFWORD (
                              mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP))
                    + 40 + 2 * (0));
            putBIT (16, mGENERATExDOTEMP + 2 * (COREHALFWORD (mDOLEVEL)),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL RETURN_STACK_ENTRY(TEMP); (12242)
          {
            putBITp (
                16, mGENERATExRETURN_STACK_ENTRYxP,
                getBIT (16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxTEMP));
            GENERATExRETURN_STACK_ENTRY (0);
          }
        es2s1:;
        } // End of DO block
      // PTR = SYT_LINK1(PTR); (12243)
      {
        descriptor_t *bitRHS = getBIT (
            16, getFIXED (mSYM_TAB)
                    + 34
                          * (COREHALFWORD (
                              mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR))
                    + 24 + 2 * (0));
        putBIT (16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxPTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
