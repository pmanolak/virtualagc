/*
  File INITIALIZExBUILD_BLOCK_TABLES.c generated by XCOM-I, 2024-08-09
  12:40:16.
*/

#include "runtimeC.h"

int32_t
INITIALIZExBUILD_BLOCK_TABLES (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INITIALIZExBUILD_BLOCK_TABLES");
  // #SYMBOLS, #PROCS, #COMPOOLS, #EXTERNALS = 0; (2483)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mpSYMBOLS, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mpPROCS, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mpCOMPOOLS, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mpEXTERNALS, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO OP2 = 1 TO NDECSY; (2484)
  {
    int32_t from78, to78, by78;
    from78 = 1;
    to78 = bitToFixed (getBIT (16, mINITIALIZExNDECSY));
    by78 = 1;
    for (putBIT (16, mOP2, fixedToBit (16, from78));
         bitToFixed (getBIT (16, mOP2)) <= to78; putBIT (
             16, mOP2, fixedToBit (16, bitToFixed (getBIT (16, mOP2)) + by78)))
      {
        // OP1 = SYT_SORT2(OP2); (2485)
        {
          descriptor_t *bitRHS
              = getBIT (16, getFIXED (mSORTING) + 12 * (COREHALFWORD (mOP2))
                                + 2 + 2 * (0));
          putBIT (16, mOP1, bitRHS);
          bitRHS->inUse = 0;
        }
        // PROCPOINT = SYT_SCOPE(OP1); (2486)
        {
          descriptor_t *bitRHS
              = getBIT (8, getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1))
                               + 29 + 1 * (0));
          putBIT (16, mINITIALIZExPROCPOINT, bitRHS);
          bitRHS->inUse = 0;
        }
        // DO CASE SYT_CLASS(OP1); (2487)
        {
        rs1s1:
          switch (BYTE0 (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mOP1)) + 30
                         + 1 * (0)))
            {
            case 0:
              // DO; (2489)
              {
              rs1s1s1:;
              es1s1s1:;
              } // End of DO block
              break;
            case 1:
              // DO; (2490)
              {
              rs1s1s2:;
                // CALL SYMB_SUB; (2490)
                INITIALIZExSYMB_SUB (0);
              es1s1s2:;
              } // End of DO block
              break;
            case 2:
              // DO; (2492)
              {
              rs1s1s3:;
                // DO CASE SYT_TYPE(OP1) &  15; (2492)
                {
                rs1s1s3s1:
                  switch (xAND (BYTE0 (getFIXED (mSYM_TAB)
                                       + 34 * (COREHALFWORD (mOP1)) + 32
                                       + 1 * (0)),
                                15))
                    {
                    case 0:
                      // DO; (2494)
                      {
                      rs1s1s3s1s1:;
                        // CALL SYMB_SUB; (2494)
                        INITIALIZExSYMB_SUB (0);
                      es1s1s3s1s1:;
                      } // End of DO block
                      break;
                    case 1:
                      // DO; (2496)
                      {
                      rs1s1s3s1s2:;
                        // CALL SYMB_SUB; (2496)
                        INITIALIZExSYMB_SUB (0);
                      es1s1s3s1s2:;
                      } // End of DO block
                      break;
                    case 2:
                      // DO; (2498)
                      {
                      rs1s1s3s1s3:;
                        // IF (SYT_DIMS(OP1) = 1)|(SYT_DIMS(OP1) = 2) THEN
                        // (2498)
                        if (1
                            & (xOR (
                                xEQ (COREHALFWORD (getFIXED (mSYM_TAB)
                                                   + 34 * (COREHALFWORD (mOP1))
                                                   + 18 + 2 * (0)),
                                     1),
                                xEQ (COREHALFWORD (getFIXED (mSYM_TAB)
                                                   + 34 * (COREHALFWORD (mOP1))
                                                   + 18 + 2 * (0)),
                                     2))))
                          // CALL BLOCK_SUB; (2499)
                          INITIALIZExBLOCK_SUB (0);
                        // ELSE (2500)
                        else
                          // CALL SYMB_SUB; (2501)
                          INITIALIZExSYMB_SUB (0);
                      es1s1s3s1s3:;
                      } // End of DO block
                      break;
                    case 3:
                      // DO; (2503)
                      {
                      rs1s1s3s1s4:;
                        // CALL SYMB_SUB; (2503)
                        INITIALIZExSYMB_SUB (0);
                      es1s1s3s1s4:;
                      } // End of DO block
                      break;
                    case 4:
                      // DO; (2505)
                      {
                      rs1s1s3s1s5:;
                        // CALL SYMB_SUB; (2505)
                        INITIALIZExSYMB_SUB (0);
                      es1s1s3s1s5:;
                      } // End of DO block
                      break;
                    case 5:
                      // DO; (2507)
                      {
                      rs1s1s3s1s6:;
                        // CALL SYMB_SUB; (2507)
                        INITIALIZExSYMB_SUB (0);
                      es1s1s3s1s6:;
                      } // End of DO block
                      break;
                    case 6:
                      // DO; (2509)
                      {
                      rs1s1s3s1s7:;
                        // CALL SYMB_SUB; (2509)
                        INITIALIZExSYMB_SUB (0);
                      es1s1s3s1s7:;
                      } // End of DO block
                      break;
                    case 7:
                      // DO; (2511)
                      {
                      rs1s1s3s1s8:;
                        // CALL BLOCK_SUB; (2511)
                        INITIALIZExBLOCK_SUB (0);
                      es1s1s3s1s8:;
                      } // End of DO block
                      break;
                    case 8:
                      // DO; (2513)
                      {
                      rs1s1s3s1s9:;
                        // CALL BLOCK_SUB; (2513)
                        INITIALIZExBLOCK_SUB (0);
                      es1s1s3s1s9:;
                      } // End of DO block
                      break;
                    case 9:
                      // DO; (2515)
                      {
                      rs1s1s3s1s10:;
                        // CALL BLOCK_SUB; (2515)
                        INITIALIZExBLOCK_SUB (0);
                      es1s1s3s1s10:;
                      } // End of DO block
                      break;
                    case 10:
                      // DO; (2517)
                      {
                      rs1s1s3s1s11:;
                        // CALL BLOCK_SUB; (2517)
                        INITIALIZExBLOCK_SUB (0);
                        // IF (SYT_FLAGS(OP1)&EXTERNAL_FLAG)~=0 THEN (2518)
                        if (1
                            & (xNEQ (
                                xAND (getFIXED (getFIXED (mSYM_TAB)
                                                + 34 * (COREHALFWORD (mOP1))
                                                + 8 + 4 * (0)),
                                      getFIXED (mEXTERNAL_FLAG)),
                                0)))
                          // #COMPOOLS = #COMPOOLS + 1; (2519)
                          {
                            int32_t numberRHS = (int32_t)(xadd (
                                COREHALFWORD (mpCOMPOOLS), 1));
                            descriptor_t *bitRHS;
                            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                            putBIT (16, mpCOMPOOLS, bitRHS);
                            bitRHS->inUse = 0;
                          }
                      es1s1s3s1s11:;
                      } // End of DO block
                      break;
                    case 11:
                      // DO; (2521)
                      {
                      rs1s1s3s1s12:;
                        // SYT_FLAGS(SYT_PTR(OP1)) = SYT_FLAGS(SYT_PTR(OP1))|
                        // EQUATE_FLAG; (2521)
                        {
                          int32_t numberRHS = (int32_t)(xOR (
                              getFIXED (getFIXED (mSYM_TAB)
                                        + 34
                                              * (COREHALFWORD (
                                                  getFIXED (mSYM_TAB)
                                                  + 34 * (COREHALFWORD (mOP1))
                                                  + 22 + 2 * (0)))
                                        + 8 + 4 * (0)),
                              getFIXED (mEQUATE_FLAG)));
                          putFIXED (getFIXED (mSYM_TAB)
                                        + 34
                                              * (COREHALFWORD (
                                                  getFIXED (mSYM_TAB)
                                                  + 34 * (COREHALFWORD (mOP1))
                                                  + 22 + 2 * (0)))
                                        + 8 + 4 * (0),
                                    numberRHS);
                        }
                        // CALL SYMB_SUB; (2522)
                        INITIALIZExSYMB_SUB (0);
                      es1s1s3s1s12:;
                      } // End of DO block
                      break;
                    }
                } // End of DO CASE block
              es1s1s3:;
              } // End of DO block
              break;
            case 3:
              // DO; (2524)
              {
              rs1s1s4:;
                // CALL BLOCK_SUB; (2524)
                INITIALIZExBLOCK_SUB (0);
              es1s1s4:;
              } // End of DO block
              break;
            case 4:
              // DO; (2526)
              {
              rs1s1s5:;
                // CALL SYMB_SUB; (2526)
                INITIALIZExSYMB_SUB (0);
              es1s1s5:;
              } // End of DO block
              break;
            case 5:
              // DO; (2528)
              {
              rs1s1s6:;
                // CALL SYMB_SUB; (2528)
                INITIALIZExSYMB_SUB (0);
              es1s1s6:;
              } // End of DO block
              break;
            case 6:
              // DO; (2530)
              {
              rs1s1s7:;
                // CALL SYMB_SUB; (2530)
                INITIALIZExSYMB_SUB (0);
                // IF FIRST_CALL THEN (2531)
                if (1
                    & (bitToFixed (getBIT (
                        16, mINITIALIZExBUILD_BLOCK_TABLESxFIRST_CALL))))
                  // IF (VAR_EXTENT(OP1) &  2147483648) ~= 0 THEN (2532)
                  if (1
                      & (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                               + 34 * (COREHALFWORD (mOP1))
                                               + 12 + 4 * (0)),
                                     2147483648),
                               0)))
                    // IF (XREF(SYT_XREF(OP1)) &  8191) >= REF_STMT | USED THEN
                    // (2533)
                    if (1
                        & (xOR (
                            xGE (xAND (
                                     getFIXED (
                                         getFIXED (mCROSS_REF)
                                         + 4
                                               * (COREHALFWORD (
                                                   getFIXED (mSYM_TAB)
                                                   + 34 * (COREHALFWORD (mOP1))
                                                   + 16 + 2 * (0)))
                                         + 0 + 4 * (0)),
                                     8191),
                                 COREHALFWORD (mREF_STMT)),
                            bitToFixed (INITIALIZExUSED (0)))))
                      // DO; (2534)
                      {
                      rs1s1s7s1:;
                        // PTR_TEMP = VAR_EXTENT(OP1) &  2147483647; (2535)
                        {
                          int32_t numberRHS = (int32_t)(xAND (
                              getFIXED (getFIXED (mSYM_TAB)
                                        + 34 * (COREHALFWORD (mOP1)) + 12
                                        + 4 * (0)),
                              2147483647));
                          putFIXED (mINITIALIZExPTR_TEMP, numberRHS);
                        }
                        // I = OP1 + 1; (2536)
                        {
                          int32_t numberRHS
                              = (int32_t)(xadd (COREHALFWORD (mOP1), 1));
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (16, mINITIALIZExI, bitRHS);
                          bitRHS->inUse = 0;
                        }
                        // IF SYT_CLASS(I) = REPL_ARG_CLASS THEN (2537)
                        if (1
                            & (xEQ (
                                BYTE0 (getFIXED (mSYM_TAB)
                                       + 34 * (COREHALFWORD (mINITIALIZExI))
                                       + 30 + 1 * (0)),
                                COREHALFWORD (mREPL_ARG_CLASS))))
                          // DO; (2538)
                          {
                          rs1s1s7s1s1:;
                            // J = 0; (2539)
                            {
                              int32_t numberRHS = (int32_t)(0);
                              descriptor_t *bitRHS;
                              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                              putBIT (16, mINITIALIZExJ, bitRHS);
                              bitRHS->inUse = 0;
                            }
                            // CELLSIZE = 12; (2540)
                            {
                              int32_t numberRHS = (int32_t)(12);
                              descriptor_t *bitRHS;
                              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                              putBIT (16, mINITIALIZExCELLSIZE, bitRHS);
                              bitRHS->inUse = 0;
                            }
                            // CALL PTR_LOCATE(PTR_TEMP,RESV); (2541)
                            {
                              putFIXED (mPTR_LOCATExPTR,
                                        getFIXED (mINITIALIZExPTR_TEMP));
                              putBITp (8, mPTR_LOCATExFLAGS,
                                       getBIT (8, mRESV));
                              PTR_LOCATE (0);
                            }
                            // ADDR_TEMP = VMEM_LOC_ADDR; (2542)
                            {
                              int32_t numberRHS
                                  = (int32_t)(getFIXED (mVMEM_LOC_ADDR));
                              putFIXED (mINITIALIZExADDR_TEMP, numberRHS);
                            }
                            // DO WHILE SYT_CLASS(I) = REPL_ARG_CLASS; (2543)
                            while (1
                                   & (xEQ (BYTE0 (getFIXED (mSYM_TAB)
                                                  + 34
                                                        * (COREHALFWORD (
                                                            mINITIALIZExI))
                                                  + 30 + 1 * (0)),
                                           COREHALFWORD (mREPL_ARG_CLASS))))
                              {
                                // J = J + 1; (2544)
                                {
                                  int32_t numberRHS = (int32_t)(xadd (
                                      COREHALFWORD (mINITIALIZExJ), 1));
                                  descriptor_t *bitRHS;
                                  bitRHS
                                      = fixedToBit (32, (int32_t)(numberRHS));
                                  putBIT (16, mINITIALIZExJ, bitRHS);
                                  bitRHS->inUse = 0;
                                }
                                // CELLSIZE = CELLSIZE+LENGTH(SYT_NAME(I))+4;
                                // (2545)
                                {
                                  int32_t numberRHS = (int32_t)(xadd (
                                      xadd (
                                          COREHALFWORD (mINITIALIZExCELLSIZE),
                                          LENGTH (getCHARACTER (
                                              getFIXED (mSYM_TAB)
                                              + 34
                                                    * (COREHALFWORD (
                                                        mINITIALIZExI))
                                              + 0 + 4 * (0)))),
                                      4));
                                  descriptor_t *bitRHS;
                                  bitRHS
                                      = fixedToBit (32, (int32_t)(numberRHS));
                                  putBIT (16, mINITIALIZExCELLSIZE, bitRHS);
                                  bitRHS->inUse = 0;
                                }
                                // I = I + 1; (2546)
                                {
                                  int32_t numberRHS = (int32_t)(xadd (
                                      COREHALFWORD (mINITIALIZExI), 1));
                                  descriptor_t *bitRHS;
                                  bitRHS
                                      = fixedToBit (32, (int32_t)(numberRHS));
                                  putBIT (16, mINITIALIZExI, bitRHS);
                                  bitRHS->inUse = 0;
                                }
                              } // End of DO WHILE block
                            // PTR = GET_CELL(CELLSIZE,ADDR(NODE_F),0); (2547)
                            {
                              int32_t numberRHS = (int32_t)((
                                  putFIXED (
                                      mGET_CELLxCELL_SIZE,
                                      COREHALFWORD (mINITIALIZExCELLSIZE)),
                                  putFIXED (mGET_CELLxBVAR,
                                            ADDR ("INITIALIZExNODE_F",
                                                  0x80000000, NULL, 0)),
                                  putBITp (8, mGET_CELLxFLAGS,
                                           fixedToBit (32, (int32_t)(0))),
                                  GET_CELL (0)));
                              putFIXED (mINITIALIZExPTR, numberRHS);
                            }
                            // CALL MOVE(8,ADDR_TEMP,VMEM_LOC_ADDR); (2548)
                            {
                              putBITp (16, mMOVExLEGNTH,
                                       fixedToBit (32, (int32_t)(8)));
                              putFIXED (mMOVExFROM,
                                        getFIXED (mINITIALIZExADDR_TEMP));
                              putFIXED (mMOVExINTO, getFIXED (mVMEM_LOC_ADDR));
                              MOVE (0);
                            }
                            // NODE_F(2) = CELLSIZE; (2549)
                            {
                              descriptor_t *bitRHS
                                  = getBIT (16, mINITIALIZExCELLSIZE);
                              int32_t numberRHS;
                              numberRHS = bitToFixed (bitRHS);
                              putFIXED (getFIXED (mINITIALIZExNODE_F)
                                            + 4 * (2),
                                        numberRHS);
                              bitRHS->inUse = 0;
                            }
                            // OFFSET = SHL(J+2,2); (2550)
                            {
                              int32_t numberRHS = (int32_t)(SHL (
                                  xadd (COREHALFWORD (mINITIALIZExJ), 2), 2));
                              descriptor_t *bitRHS;
                              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                              putBIT (16, mINITIALIZExOFFSET, bitRHS);
                              bitRHS->inUse = 0;
                            }
                            // DO I = OP1+1 TO OP1+J; (2551)
                            {
                              int32_t from79, to79, by79;
                              from79 = xadd (COREHALFWORD (mOP1), 1);
                              to79 = xadd (COREHALFWORD (mOP1),
                                           COREHALFWORD (mINITIALIZExJ));
                              by79 = 1;
                              for (putBIT (16, mINITIALIZExI,
                                           fixedToBit (16, from79));
                                   bitToFixed (getBIT (16, mINITIALIZExI))
                                   <= to79;
                                   putBIT (
                                       16, mINITIALIZExI,
                                       fixedToBit (16, bitToFixed (getBIT (
                                                           16, mINITIALIZExI))
                                                           + by79)))
                                {
                                  // LEN = LENGTH(SYT_NAME(I)); (2552)
                                  {
                                    int32_t numberRHS = (int32_t)(LENGTH (
                                        getCHARACTER (getFIXED (mSYM_TAB)
                                                      + 34
                                                            * (COREHALFWORD (
                                                                mINITIALIZExI))
                                                      + 0 + 4 * (0))));
                                    descriptor_t *bitRHS;
                                    bitRHS = fixedToBit (32,
                                                         (int32_t)(numberRHS));
                                    putBIT (16, mINITIALIZExLEN, bitRHS);
                                    bitRHS->inUse = 0;
                                  }
                                  // NODE_F(I-OP1+2)=SHL(LEN-1,24)+OFFSET;
                                  // (2553)
                                  {
                                    int32_t numberRHS = (int32_t)(xadd (
                                        SHL (xsubtract (COREHALFWORD (
                                                            mINITIALIZExLEN),
                                                        1),
                                             24),
                                        COREHALFWORD (mINITIALIZExOFFSET)));
                                    putFIXED (
                                        getFIXED (mINITIALIZExNODE_F)
                                            + 4
                                                  * (xadd (
                                                      xsubtract (
                                                          COREHALFWORD (
                                                              mINITIALIZExI),
                                                          COREHALFWORD (mOP1)),
                                                      2)),
                                        numberRHS);
                                  }
                                  // CALL
                                  // MOVE(LEN,SYT_NAME(I),VMEM_LOC_ADDR+OFFSET+4);
                                  // (2554)
                                  {
                                    putBITp (16, mMOVExLEGNTH,
                                             getBIT (16, mINITIALIZExLEN));
                                    putFIXED (
                                        mMOVExFROM,
                                        getFIXED (getFIXED (mSYM_TAB)
                                                  + 34
                                                        * (COREHALFWORD (
                                                            mINITIALIZExI))
                                                  + 0 + 4 * (0)));
                                    putFIXED (
                                        mMOVExINTO,
                                        xadd (xadd (getFIXED (mVMEM_LOC_ADDR),
                                                    COREHALFWORD (
                                                        mINITIALIZExOFFSET)),
                                              4));
                                    MOVE (0);
                                  }
                                  // OFFSET = OFFSET + LEN; (2555)
                                  {
                                    int32_t numberRHS = (int32_t)(xadd (
                                        COREHALFWORD (mINITIALIZExOFFSET),
                                        COREHALFWORD (mINITIALIZExLEN)));
                                    descriptor_t *bitRHS;
                                    bitRHS = fixedToBit (32,
                                                         (int32_t)(numberRHS));
                                    putBIT (16, mINITIALIZExOFFSET, bitRHS);
                                    bitRHS->inUse = 0;
                                  }
                                }
                            } // End of DO for-loop block
                            // COREWORD(ADDR(NODE_H)) = VMEM_LOC_ADDR; (2556)
                            {
                              int32_t numberRHS
                                  = (int32_t)(getFIXED (mVMEM_LOC_ADDR));
                              COREWORD2 (ADDR ("INITIALIZExNODE_H", 0x80000000,
                                               NULL, 0),
                                         numberRHS);
                            }
                            // NODE_H(2) = -(J+1); (2557)
                            {
                              int32_t numberRHS = (int32_t)(xminus (
                                  xadd (COREHALFWORD (mINITIALIZExJ), 1)));
                              descriptor_t *bitRHS;
                              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                              putBIT (16,
                                      getFIXED (mINITIALIZExNODE_H) + 2 * (2),
                                      bitRHS);
                              bitRHS->inUse = 0;
                            }
                            // CALL PTR_LOCATE(PTR_TEMP,RELS); (2558)
                            {
                              putFIXED (mPTR_LOCATExPTR,
                                        getFIXED (mINITIALIZExPTR_TEMP));
                              putBITp (8, mPTR_LOCATExFLAGS,
                                       getBIT (8, mRELS));
                              PTR_LOCATE (0);
                            }
                            // VAR_EXTENT(OP1) = PTR |  2147483648; (2559)
                            {
                              int32_t numberRHS = (int32_t)(xOR (
                                  getFIXED (mINITIALIZExPTR), 2147483648));
                              putFIXED (getFIXED (mSYM_TAB)
                                            + 34 * (COREHALFWORD (mOP1)) + 12
                                            + 4 * (0),
                                        numberRHS);
                            }
                          es1s1s7s1s1:;
                          } // End of DO block
                      es1s1s7s1:;
                      } // End of DO block
              es1s1s7:;
              } // End of DO block
              break;
            case 7:
              // DO; (2561)
              {
              rs1s1s8:;
                // CALL SYMB_SUB; (2561)
                INITIALIZExSYMB_SUB (0);
              es1s1s8:;
              } // End of DO block
              break;
            case 8:
              // DO; (2563)
              {
              rs1s1s9:;
                // CALL SYMB_SUB; (2563)
                INITIALIZExSYMB_SUB (0);
              es1s1s9:;
              } // End of DO block
              break;
            case 9:
              // DO; (2565)
              {
              rs1s1s10:;
                // CALL SYMB_SUB; (2565)
                INITIALIZExSYMB_SUB (0);
              es1s1s10:;
              } // End of DO block
              break;
            }
        } // End of DO CASE block
      }
  } // End of DO for-loop block
  // FIRST_CALL = 0; (2566)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mINITIALIZExBUILD_BLOCK_TABLESxFIRST_CALL, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
