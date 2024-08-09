/*
  File FINISH_MACRO_TEXT.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
FINISH_MACRO_TEXT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "FINISH_MACRO_TEXT");
  // IF FIRST_FREE ~= 0 THEN (1434)
  if (1 & (xNEQ (getFIXED (mCOMM + 4 * 9), 0)))
    // DO; (1435)
    {
    rs1:;
      // II = MACRO_TEXT(FIRST_FREE-1); (1436)
      {
        descriptor_t *bitRHS
            = getBIT (8, getFIXED (mMACRO_TEXTS)
                             + 1 * (xsubtract (getFIXED (mCOMM + 4 * 9), 1))
                             + 0 + 1 * (0));
        putBIT (16, mFINISH_MACRO_TEXTxII, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF (MACRO_TEXT(FIRST_FREE-2)=BYTE(')') & II=BYTE('`')) | II=BYTE(')')
      // | MACRO_ARG_COUNT>0 THEN (1437)
      if (1
          & (xOR (
              xOR (xAND (
                       xEQ (BYTE0 (
                                getFIXED (mMACRO_TEXTS)
                                + 1 * (xsubtract (getFIXED (mCOMM + 4 * 9), 2))
                                + 0 + 1 * (0)),
                            BYTE1 (cToDescriptor (NULL, ")"))),
                       xEQ (COREHALFWORD (mFINISH_MACRO_TEXTxII),
                            BYTE1 (cToDescriptor (NULL, "`")))),
                   xEQ (COREHALFWORD (mFINISH_MACRO_TEXTxII),
                        BYTE1 (cToDescriptor (NULL, ")")))),
              xGT (COREHALFWORD (mMACRO_ARG_COUNT), 0))))
        // DO; (1438)
        {
        rs1s1:;
          // DO ; (1439)
          {
          rs1s1s1:;
            // IF COREWORD ( ADDR ( MACRO_TEXTS ) + 12 ) >= COREWORD ( ADDR (
            // MACRO_TEXTS ) + 8 ) THEN (1440)
            if (1
                & (xGE (COREWORD (xadd (
                            ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0), 12)),
                        COREWORD (xadd (
                            ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0), 8)))))
              // CALL _NEEDMORE_SPACE ( ADDR ( MACRO_TEXTS )  ) ; (1441)
              {
                putFIXED (m_NEEDMORE_SPACExDOPE,
                          ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0));
                _NEEDMORE_SPACE (0);
              }
            // COREWORD ( ADDR ( MACRO_TEXTS ) + 12 ) = COREWORD ( ADDR (
            // MACRO_TEXTS ) + 12 ) + 1 ; (1442)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  COREWORD (
                      xadd (ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0), 12)),
                  1));
              COREWORD2 (xadd (ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0), 12),
                         numberRHS);
            }
          es1s1s1:;
          } // End of DO block
          // DO ; (1443)
          {
          rs1s1s2:;
            // IF COREWORD ( ADDR ( MACRO_TEXTS ) + 12 ) >= COREWORD ( ADDR (
            // MACRO_TEXTS ) + 8 ) THEN (1444)
            if (1
                & (xGE (COREWORD (xadd (
                            ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0), 12)),
                        COREWORD (xadd (
                            ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0), 8)))))
              // CALL _NEEDMORE_SPACE ( ADDR ( MACRO_TEXTS )  ) ; (1445)
              {
                putFIXED (m_NEEDMORE_SPACExDOPE,
                          ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0));
                _NEEDMORE_SPACE (0);
              }
            // COREWORD ( ADDR ( MACRO_TEXTS ) + 12 ) = COREWORD ( ADDR (
            // MACRO_TEXTS ) + 12 ) + 1 ; (1446)
            {
              int32_t numberRHS = (int32_t)(xadd (
                  COREWORD (
                      xadd (ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0), 12)),
                  1));
              COREWORD2 (xadd (ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0), 12),
                         numberRHS);
            }
          es1s1s2:;
          } // End of DO block
          // MACRO_TEXT(FIRST_FREE) =  238; (1447)
          {
            int32_t numberRHS = (int32_t)(238);
            putBIT (8,
                    getFIXED (mMACRO_TEXTS) + 1 * (getFIXED (mCOMM + 4 * 9))
                        + 0 + 1 * (0),
                    fixedToBit (8, numberRHS));
          }
          // MACRO_TEXT(FIRST_FREE+1) = 0; (1448)
          {
            int32_t numberRHS = (int32_t)(0);
            putBIT (8,
                    getFIXED (mMACRO_TEXTS)
                        + 1 * (xadd (getFIXED (mCOMM + 4 * 9), 1)) + 0
                        + 1 * (0),
                    fixedToBit (8, numberRHS));
          }
          // FIRST_FREE = FIRST_FREE+2; (1449)
          {
            int32_t numberRHS = (int32_t)(xadd (getFIXED (mCOMM + 4 * 9), 2));
            putFIXED (mCOMM + 4 * (9), numberRHS);
          }
        es1s1:;
        } // End of DO block
    es1:;
    } // End of DO block
  // MACRO_TEXT(FIRST_FREE) =  239; (1450)
  {
    int32_t numberRHS = (int32_t)(239);
    putBIT (8,
            getFIXED (mMACRO_TEXTS) + 1 * (getFIXED (mCOMM + 4 * 9)) + 0
                + 1 * (0),
            fixedToBit (8, numberRHS));
  }
  // IF SIMULATING > 0 THEN (1451)
  if (1 & (xGT (BYTE0 (mSIMULATING), 0)))
    // DO; (1452)
    {
    rs2:;
      // IF MACRO_TEXT(FIRST_FREE-2)= 238 & MACRO_TEXT(FIRST_FREE-1)=0 THEN
      // (1453)
      if (1
          & (xAND (xEQ (BYTE0 (getFIXED (mMACRO_TEXTS)
                               + 1 * (xsubtract (getFIXED (mCOMM + 4 * 9), 2))
                               + 0 + 1 * (0)),
                        238),
                   xEQ (BYTE0 (getFIXED (mMACRO_TEXTS)
                               + 1 * (xsubtract (getFIXED (mCOMM + 4 * 9), 1))
                               + 0 + 1 * (0)),
                        0))))
        // DO; (1454)
        {
        rs2s1:;
          // TEXT_SIZE = (FIRST_FREE - 2 ) - START_POINT; (1455)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (xsubtract (getFIXED (mCOMM + 4 * 9), 2),
                                       getFIXED (mSTART_POINT)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mFINISH_MACRO_TEXTxTEXT_SIZE, bitRHS);
            bitRHS->inUse = 0;
          }
          // TEXT_PTR = (FIRST_FREE-2) - MACRO_CELL_LIM; (1456)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (xsubtract (getFIXED (mCOMM + 4 * 9), 2),
                                       COREHALFWORD (mMACRO_CELL_LIM)));
            putFIXED (mFINISH_MACRO_TEXTxTEXT_PTR, numberRHS);
          }
          // IF MACRO_ARG_COUNT > 0 THEN (1457)
          if (1 & (xGT (COREHALFWORD (mMACRO_ARG_COUNT), 0)))
            // ARG_FLAG =  2147483648; (1458)
            {
              int32_t numberRHS = (int32_t)(2147483648);
              putFIXED (mFINISH_MACRO_TEXTxARG_FLAG, numberRHS);
            }
          // ELSE (1459)
          else
            // ARG_FLAG = 0; (1460)
            {
              int32_t numberRHS = (int32_t)(0);
              putFIXED (mFINISH_MACRO_TEXTxARG_FLAG, numberRHS);
            }
        es2s1:;
        } // End of DO block
      // ELSE (1461)
      else
        // DO; (1462)
        {
        rs2s2:;
          // TEXT_SIZE = FIRST_FREE - START_POINT; (1463)
          {
            int32_t numberRHS = (int32_t)(xsubtract (getFIXED (mCOMM + 4 * 9),
                                                     getFIXED (mSTART_POINT)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mFINISH_MACRO_TEXTxTEXT_SIZE, bitRHS);
            bitRHS->inUse = 0;
          }
          // TEXT_PTR = FIRST_FREE - MACRO_CELL_LIM; (1464)
          {
            int32_t numberRHS = (int32_t)(xsubtract (
                getFIXED (mCOMM + 4 * 9), COREHALFWORD (mMACRO_CELL_LIM)));
            putFIXED (mFINISH_MACRO_TEXTxTEXT_PTR, numberRHS);
          }
          // ARG_FLAG = 0; (1465)
          {
            int32_t numberRHS = (int32_t)(0);
            putFIXED (mFINISH_MACRO_TEXTxARG_FLAG, numberRHS);
          }
        es2s2:;
        } // End of DO block
      // IF TEXT_SIZE<0 THEN (1466)
      if (1 & (xLT (COREHALFWORD (mFINISH_MACRO_TEXTxTEXT_SIZE), 0)))
        // TEXT_SIZE = 0; (1467)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mFINISH_MACRO_TEXTxTEXT_SIZE, bitRHS);
          bitRHS->inUse = 0;
        }
      // NEXT_CELL_PTR = -1; (1468)
      {
        int32_t numberRHS = (int32_t)(-1);
        putFIXED (mFINISH_MACRO_TEXTxNEXT_CELL_PTR, numberRHS);
      }
      // DO WHILE TEXT_SIZE >= MACRO_CELL_LIM; (1469)
      while (1
             & (xGE (COREHALFWORD (mFINISH_MACRO_TEXTxTEXT_SIZE),
                     COREHALFWORD (mMACRO_CELL_LIM))))
        {
          // CELLSIZE = MACRO_CELL_LIM; (1470)
          {
            descriptor_t *bitRHS = getBIT (16, mMACRO_CELL_LIM);
            putBIT (16, mFINISH_MACRO_TEXTxCELLSIZE, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF MACRO_TEXT(TEXT_PTR-1) =  238 THEN (1471)
          if (1
              & (xEQ (
                  BYTE0 (getFIXED (mMACRO_TEXTS)
                         + 1
                               * (xsubtract (
                                   getFIXED (mFINISH_MACRO_TEXTxTEXT_PTR), 1))
                         + 0 + 1 * (0)),
                  238)))
            // DO; (1472)
            {
            rs2s3s1:;
              // TEXT_PTR = TEXT_PTR + 1; (1473)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    getFIXED (mFINISH_MACRO_TEXTxTEXT_PTR), 1));
                putFIXED (mFINISH_MACRO_TEXTxTEXT_PTR, numberRHS);
              }
              // CELLSIZE = CELLSIZE - 1; (1474)
              {
                int32_t numberRHS = (int32_t)(xsubtract (
                    COREHALFWORD (mFINISH_MACRO_TEXTxCELLSIZE), 1));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mFINISH_MACRO_TEXTxCELLSIZE, bitRHS);
                bitRHS->inUse = 0;
              }
            es2s3s1:;
            } // End of DO block
          // REPLACE_TEXT_PTR = GET_CELL(CELLSIZE+6,ADDR(NODE_F),MODF); (1475)
          {
            int32_t numberRHS = (int32_t)((
                putFIXED (
                    mGET_CELLxCELL_SIZE,
                    xadd (COREHALFWORD (mFINISH_MACRO_TEXTxCELLSIZE), 6)),
                putFIXED (mGET_CELLxBVAR, ADDR ("FINISH_MACRO_TEXTxNODE_F",
                                                0x80000000, NULL, 0)),
                putBITp (8, mGET_CELLxFLAGS, getBIT (8, mMODF)),
                GET_CELL (0)));
            putFIXED (mREPLACE_TEXT_PTR, numberRHS);
          }
          // NODE_F(0) = NEXT_CELL_PTR; (1476)
          {
            int32_t numberRHS
                = (int32_t)(getFIXED (mFINISH_MACRO_TEXTxNEXT_CELL_PTR));
            putFIXED (getFIXED (mFINISH_MACRO_TEXTxNODE_F) + 4 * (0),
                      numberRHS);
          }
          // NODE_F(1) = SHL(CELLSIZE,16); (1477)
          {
            int32_t numberRHS = (int32_t)(SHL (
                COREHALFWORD (mFINISH_MACRO_TEXTxCELLSIZE), 16));
            putFIXED (getFIXED (mFINISH_MACRO_TEXTxNODE_F) + 4 * (1),
                      numberRHS);
          }
          // MACRO_BYTES = MACRO_BYTES + MACRO_CELL_LIM; (1478)
          {
            int32_t numberRHS = (int32_t)(xadd (
                getFIXED (mCOMM + 4 * 15), COREHALFWORD (mMACRO_CELL_LIM)));
            putFIXED (mCOMM + 4 * (15), numberRHS);
          }
          // CALL MOVE(CELLSIZE,ADDR(MACRO_TEXT(TEXT_PTR)), VMEM_LOC_ADDR+6);
          // (1479)
          {
            putBITp (16, mMOVExLEGNTH,
                     getBIT (16, mFINISH_MACRO_TEXTxCELLSIZE));
            putFIXED (mMOVExFROM, ADDR ("MACRO_TEXTS",
                                        getFIXED (mFINISH_MACRO_TEXTxTEXT_PTR),
                                        "MAC_TXT", 0));
            putFIXED (mMOVExINTO, xadd (getFIXED (mVMEM_LOC_ADDR), 6));
            MOVE (0);
          }
          // NEXT_CELL_PTR = REPLACE_TEXT_PTR; (1480)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mREPLACE_TEXT_PTR));
            putFIXED (mFINISH_MACRO_TEXTxNEXT_CELL_PTR, numberRHS);
          }
          // TEXT_PTR = TEXT_PTR - MACRO_CELL_LIM; (1481)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (getFIXED (mFINISH_MACRO_TEXTxTEXT_PTR),
                                       COREHALFWORD (mMACRO_CELL_LIM)));
            putFIXED (mFINISH_MACRO_TEXTxTEXT_PTR, numberRHS);
          }
          // TEXT_SIZE = TEXT_SIZE - CELLSIZE; (1482)
          {
            int32_t numberRHS = (int32_t)(xsubtract (
                COREHALFWORD (mFINISH_MACRO_TEXTxTEXT_SIZE),
                COREHALFWORD (mFINISH_MACRO_TEXTxCELLSIZE)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mFINISH_MACRO_TEXTxTEXT_SIZE, bitRHS);
            bitRHS->inUse = 0;
          }
        } // End of DO WHILE block
      // IF TEXT_SIZE > 0 THEN (1483)
      if (1 & (xGT (COREHALFWORD (mFINISH_MACRO_TEXTxTEXT_SIZE), 0)))
        // DO; (1484)
        {
        rs2s4:;
          // REPLACE_TEXT_PTR=GET_CELL(TEXT_SIZE+6,ADDR(NODE_F),MODF); (1485)
          {
            int32_t numberRHS = (int32_t)((
                putFIXED (
                    mGET_CELLxCELL_SIZE,
                    xadd (COREHALFWORD (mFINISH_MACRO_TEXTxTEXT_SIZE), 6)),
                putFIXED (mGET_CELLxBVAR, ADDR ("FINISH_MACRO_TEXTxNODE_F",
                                                0x80000000, NULL, 0)),
                putBITp (8, mGET_CELLxFLAGS, getBIT (8, mMODF)),
                GET_CELL (0)));
            putFIXED (mREPLACE_TEXT_PTR, numberRHS);
          }
          // NODE_F(0) = NEXT_CELL_PTR; (1486)
          {
            int32_t numberRHS
                = (int32_t)(getFIXED (mFINISH_MACRO_TEXTxNEXT_CELL_PTR));
            putFIXED (getFIXED (mFINISH_MACRO_TEXTxNODE_F) + 4 * (0),
                      numberRHS);
          }
          // NODE_F(1) = SHL(TEXT_SIZE,16); (1487)
          {
            int32_t numberRHS = (int32_t)(SHL (
                COREHALFWORD (mFINISH_MACRO_TEXTxTEXT_SIZE), 16));
            putFIXED (getFIXED (mFINISH_MACRO_TEXTxNODE_F) + 4 * (1),
                      numberRHS);
          }
          // NEXT_CELL_PTR = REPLACE_TEXT_PTR; (1488)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mREPLACE_TEXT_PTR));
            putFIXED (mFINISH_MACRO_TEXTxNEXT_CELL_PTR, numberRHS);
          }
          // MACRO_BYTES = MACRO_BYTES+((TEXT_SIZE+3)& 65532); (1489)
          {
            int32_t numberRHS = (int32_t)(xadd (
                getFIXED (mCOMM + 4 * 15),
                xAND (xadd (COREHALFWORD (mFINISH_MACRO_TEXTxTEXT_SIZE), 3),
                      65532)));
            putFIXED (mCOMM + 4 * (15), numberRHS);
          }
          // CALL MOVE(TEXT_SIZE,ADDR(MACRO_TEXT(START_POINT)), VMEM_LOC_ADDR +
          // 6); (1490)
          {
            putBITp (16, mMOVExLEGNTH,
                     getBIT (16, mFINISH_MACRO_TEXTxTEXT_SIZE));
            putFIXED (mMOVExFROM, ADDR ("MACRO_TEXTS", getFIXED (mSTART_POINT),
                                        "MAC_TXT", 0));
            putFIXED (mMOVExINTO, xadd (getFIXED (mVMEM_LOC_ADDR), 6));
            MOVE (0);
          }
        es2s4:;
        } // End of DO block
      // REPLACE_TEXT_PTR = GET_CELL(8,ADDR(NODE_F),MODF); (1491)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (mGET_CELLxCELL_SIZE, 8),
            putFIXED (mGET_CELLxBVAR,
                      ADDR ("FINISH_MACRO_TEXTxNODE_F", 0x80000000, NULL, 0)),
            putBITp (8, mGET_CELLxFLAGS, getBIT (8, mMODF)), GET_CELL (0)));
        putFIXED (mREPLACE_TEXT_PTR, numberRHS);
      }
      // NODE_F(0) = NEXT_CELL_PTR; (1492)
      {
        int32_t numberRHS
            = (int32_t)(getFIXED (mFINISH_MACRO_TEXTxNEXT_CELL_PTR));
        putFIXED (getFIXED (mFINISH_MACRO_TEXTxNODE_F) + 4 * (0), numberRHS);
      }
      // NODE_F(1) =  4294901760 + BLANK_BYTES; (1493)
      {
        int32_t numberRHS = (int32_t)(xadd (
            4294901760, COREHALFWORD (mFINISH_MACRO_TEXTxBLANK_BYTES)));
        putFIXED (getFIXED (mFINISH_MACRO_TEXTxNODE_F) + 4 * (1), numberRHS);
      }
      // REPLACE_TEXT_PTR = REPLACE_TEXT_PTR | ARG_FLAG; (1494)
      {
        int32_t numberRHS
            = (int32_t)(xOR (getFIXED (mREPLACE_TEXT_PTR),
                             getFIXED (mFINISH_MACRO_TEXTxARG_FLAG)));
        putFIXED (mREPLACE_TEXT_PTR, numberRHS);
      }
    es2:;
    } // End of DO block
  // FIRST_FREE = FIRST_FREE + 1; (1495)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mCOMM + 4 * 9), 1));
    putFIXED (mCOMM + 4 * (9), numberRHS);
  }
  // DO ; (1496)
  {
  rs3:;
    // IF COREWORD ( ADDR ( MACRO_TEXTS ) + 12 ) >= COREWORD ( ADDR (
    // MACRO_TEXTS ) + 8 ) THEN (1497)
    if (1
        & (xGE (
            COREWORD (xadd (ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0), 12)),
            COREWORD (xadd (ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0), 8)))))
      // CALL _NEEDMORE_SPACE ( ADDR ( MACRO_TEXTS )  ) ; (1498)
      {
        putFIXED (m_NEEDMORE_SPACExDOPE,
                  ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0));
        _NEEDMORE_SPACE (0);
      }
    // COREWORD ( ADDR ( MACRO_TEXTS ) + 12 ) = COREWORD ( ADDR ( MACRO_TEXTS )
    // + 12 ) + 1 ; (1499)
    {
      int32_t numberRHS = (int32_t)(xadd (
          COREWORD (xadd (ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0), 12)), 1));
      COREWORD2 (xadd (ADDR ("MACRO_TEXTS", 0x80000000, NULL, 0), 12),
                 numberRHS);
    }
  es3:;
  } // End of DO block
  // RETURN; (1500)
  {
    reentryGuard = 0;
    return 0;
  }
}
