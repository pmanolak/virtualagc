/*
  File EMIT_ADDRS.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
EMIT_ADDRS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "EMIT_ADDRS");
  // STMT# = STMT_NO &  32767; (1488)
  {
    int32_t numberRHS
        = (int32_t)(xAND (COREHALFWORD (mEMIT_ADDRSxSTMT_NO), 32767));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mEMIT_ADDRSxSTMTp, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF STMT# = 0 THEN (1489)
  if (1 & (xEQ (COREHALFWORD (mEMIT_ADDRSxSTMTp), 0)))
    // DO; (1490)
    {
    rs1:;
      // IF FIRST_CALL THEN (1491)
      if (1 & (bitToFixed (getBIT (1, mEMIT_ADDRSxFIRST_CALL))))
        // DO; (1492)
        {
        rs1s1:;
          // FIRST_CALL = FALSE; (1493)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mEMIT_ADDRSxFIRST_CALL, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF (((OPTION_BITS& 1048576)~=0)&((OPTION_BITS& 2048)~=0)) THEN
          // (1494)
          if (1
              & (xAND (xNEQ (xAND (getFIXED (mCOMM + 4 * 7), 1048576), 0),
                       xNEQ (xAND (getFIXED (mCOMM + 4 * 7), 2048), 0))))
            // DO; (1495)
            {
            rs1s1s1:;
              // GO_FLAG = TRUE; (1496)
              {
                int32_t numberRHS = (int32_t)(1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (1, mEMIT_ADDRSxGO_FLAG, bitRHS);
                bitRHS->inUse = 0;
              }
              // STMT_DATA_PTR = STMT_DATA_HEAD; (1497)
              {
                int32_t numberRHS = (int32_t)(getFIXED (mCOMM + 4 * 16));
                putFIXED (mEMIT_ADDRSxSTMT_DATA_PTR, numberRHS);
              }
            es1s1s1:;
            } // End of DO block
        es1s1:;
        } // End of DO block
      // ELSE (1498)
      else
        // DO; (1499)
        {
        rs1s2:;
          // GO_FLAG = FALSE; (1500)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (1, mEMIT_ADDRSxGO_FLAG, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s2:;
        } // End of DO block
    es1:;
    } // End of DO block
  // ELSE (1501)
  else
    // IF GO_FLAG THEN (1502)
    if (1 & (bitToFixed (getBIT (1, mEMIT_ADDRSxGO_FLAG))))
      // DO; (1503)
      {
      rs2:;
        // DO UNTIL CUR_STMT# = STMT#; (1504)
        do
          {
            // IF STMT_DATA_PTR = -1 THEN (1505)
            if (1 & (xEQ (getFIXED (mEMIT_ADDRSxSTMT_DATA_PTR), -1)))
              // DO; (1506)
              {
              rs2s1s1:;
                // CALL ERRORS(CLASS_BI,510); (1507)
                {
                  putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
                  putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(510)));
                  ERRORS (0);
                }
                // CALL EXIT; (1508)
                EXIT ();
              es2s1s1:;
              } // End of DO block
            // CALL LOCATE(STMT_DATA_PTR,ADDR(NODE_F),0); (1509)
            {
              putFIXED (mLOCATExPTR, getFIXED (mEMIT_ADDRSxSTMT_DATA_PTR));
              putFIXED (mLOCATExBVAR,
                        ADDR ("EMIT_ADDRSxNODE_F", 0x80000000, NULL, 0));
              putBITp (8, mLOCATExFLAGS, fixedToBit (32, (int32_t)(0)));
              LOCATE (0);
            }
            // CUR_STMT# = (SHR(NODE_F(7),16) &  65535); (1510)
            {
              int32_t numberRHS = (int32_t)(xAND (
                  SHR (getFIXED (getFIXED (mEMIT_ADDRSxNODE_F) + 4 * 7), 16),
                  65535));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mEMIT_ADDRSxCUR_STMTp, bitRHS);
              bitRHS->inUse = 0;
            }
            // IF CUR_STMT# ~= 0 THEN (1511)
            if (1 & (xNEQ (COREHALFWORD (mEMIT_ADDRSxCUR_STMTp), 0)))
              // STMT_DATA_PTR = NODE_F(0); (1512)
              {
                int32_t numberRHS = (int32_t)(getFIXED (
                    getFIXED (mEMIT_ADDRSxNODE_F) + 4 * 0));
                putFIXED (mEMIT_ADDRSxSTMT_DATA_PTR, numberRHS);
              }
          }
        while (!(1
                 & (xEQ (COREHALFWORD (mEMIT_ADDRSxCUR_STMTp),
                         COREHALFWORD (
                             mEMIT_ADDRSxSTMTp))))); // End of DO UNTIL block
        // CALL DISP(MODF); (1513)
        {
          putBITp (8, mDISPxFLAGS, getBIT (8, mMODF));
          DISP (0);
        }
        // IF (CURRENT_ESDID >= PROGPOINT) & (CURRENT_ESDID <= PROCLIMIT) THEN
        // (1514)
        if (1
            & (xAND (
                xGE (getFIXED (mCURRENT_ESDID), COREHALFWORD (mPROGPOINT)),
                xLE (getFIXED (mCURRENT_ESDID), COREHALFWORD (mPROCLIMIT)))))
          // DO; (1515)
          {
          rs2s2:;
            // NODE_F(8)= ADDR1; (1516)
            {
              int32_t numberRHS = (int32_t)(getFIXED (mEMIT_ADDRSxADDR1));
              putFIXED (getFIXED (mEMIT_ADDRSxNODE_F) + 4 * (8), numberRHS);
            }
            // NODE_F(9)= ADDR2; (1517)
            {
              int32_t numberRHS = (int32_t)(getFIXED (mEMIT_ADDRSxADDR2));
              putFIXED (getFIXED (mEMIT_ADDRSxNODE_F) + 4 * (9), numberRHS);
            }
            // NODE_F(10),NODE_F(11)= 0; (1518)
            {
              int32_t numberRHS = (int32_t)(0);
              putFIXED (getFIXED (mEMIT_ADDRSxNODE_F) + 4 * (10), numberRHS);
              putFIXED (getFIXED (mEMIT_ADDRSxNODE_F) + 4 * (11), numberRHS);
            }
          es2s2:;
          } // End of DO block
      es2:;
      } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
