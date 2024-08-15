/*
  File PROCESS_EXTN.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

int32_t
PROCESS_EXTN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PROCESS_EXTN");
  // IF PROC_TRACE THEN (1442)
  if (1 & (bitToFixed (getBIT (8, mPROC_TRACE))))
    // OUTPUT='PROCESS_EXTN('||BLOCK#||':'||CTR||')'; (1443)
    {
      descriptor_t *stringRHS;
      stringRHS
          = xsCAT (xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "PROCESS_EXTN("),
                                        bitToCharacter (getBIT (16, mBLOCKp))),
                                 cToDescriptor (NULL, ":")),
                          bitToCharacter (getBIT (16, mPROCESS_EXTNxCTR))),
                   cToDescriptor (NULL, ")"));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // IF HALMAT_PTR(CTR) ~= 0 THEN (1444)
  if (1
      & (xNEQ (getFIXED (mHALMAT_PTR + 4 * COREHALFWORD (mPROCESS_EXTNxCTR)),
               0)))
    // DO; (1445)
    {
    rs1:;
      // PTR_INX = PTR_INX + 1; (1446)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mPTR_INX), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPTR_INX, bitRHS);
        bitRHS->inUse = 0;
      }
      // EXP_PTRS(PTR_INX) = HALMAT_PTR(CTR); (1447)
      {
        int32_t numberRHS = (int32_t)(getFIXED (
            mHALMAT_PTR + 4 * COREHALFWORD (mPROCESS_EXTNxCTR)));
        putFIXED (mEXP_PTRS + 4 * (COREHALFWORD (mPTR_INX)), numberRHS);
      }
    es1:;
    } // End of DO block
  // ELSE (1448)
  else
    // IF TYPE_BITS(CTR+1) = VAC THEN (1449)
    if (1
        & (xEQ (
            bitToFixed (
                (putBITp (16, mTYPE_BITSxCTR,
                          fixedToBit (
                              32, (int32_t)(xadd (
                                      COREHALFWORD (mPROCESS_EXTNxCTR), 1)))),
                 TYPE_BITS (0))),
            COREHALFWORD (mVAC))))
      // CALL ERRORS (CLASS_BI, 202, ' '||BLOCK#||':'||CTR); (1450)
      {
        putBITp (16, mERRORSxCLASS, getBIT (16, mCLASS_BI));
        putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(202)));
        putCHARACTERp (
            mERRORSxTEXT,
            xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, " "),
                                 bitToCharacter (getBIT (16, mBLOCKp))),
                          cToDescriptor (NULL, ":")),
                   bitToCharacter (getBIT (16, mPROCESS_EXTNxCTR))));
        ERRORS (0);
      }
    // ELSE (1451)
    else
      // DO; (1452)
      {
      rs2:;
        // VAR_INX = VAR_INX + 1; (1453)
        {
          int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mVAR_INX), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mVAR_INX, bitRHS);
          bitRHS->inUse = 0;
        }
        // K = X_BITS(CTR+POPNUM(CTR)-1); (1454)
        {
          descriptor_t *bitRHS
              = (putBITp (
                     16, mX_BITSxCTR,
                     fixedToBit (
                         32, (int32_t)(xsubtract (
                                 xadd (COREHALFWORD (mPROCESS_EXTNxCTR),
                                       bitToFixed ((
                                           putBITp (
                                               16, mPOPNUMxCTR,
                                               getBIT (16, mPROCESS_EXTNxCTR)),
                                           POPNUM (0)))),
                                 1)))),
                 X_BITS (0));
          putBIT (16, mPROCESS_EXTNxK, bitRHS);
          bitRHS->inUse = 0;
        }
        // EXP_VARS(VAR_INX) = -POPNUM(CTR) + K; (1455)
        {
          int32_t numberRHS = (int32_t)(xadd (
              xminus (bitToFixed (
                  (putBITp (16, mPOPNUMxCTR, getBIT (16, mPROCESS_EXTNxCTR)),
                   POPNUM (0)))),
              COREHALFWORD (mPROCESS_EXTNxK)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mEXP_VARS + 2 * (COREHALFWORD (mVAR_INX)), bitRHS);
          bitRHS->inUse = 0;
        }
        // DO J = 1 TO POPNUM(CTR)-K; (1456)
        {
          int32_t from32, to32, by32;
          from32 = 1;
          to32 = xsubtract (
              bitToFixed (
                  (putBITp (16, mPOPNUMxCTR, getBIT (16, mPROCESS_EXTNxCTR)),
                   POPNUM (0))),
              COREHALFWORD (mPROCESS_EXTNxK));
          by32 = 1;
          for (putBIT (16, mPROCESS_EXTNxJ, fixedToBit (16, from32));
               bitToFixed (getBIT (16, mPROCESS_EXTNxJ)) <= to32; putBIT (
                   16, mPROCESS_EXTNxJ,
                   fixedToBit (16, bitToFixed (getBIT (16, mPROCESS_EXTNxJ))
                                       + by32)))
            {
              // VAR_INX = VAR_INX + 1; (1457)
              {
                int32_t numberRHS
                    = (int32_t)(xadd (COREHALFWORD (mVAR_INX), 1));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mVAR_INX, bitRHS);
                bitRHS->inUse = 0;
              }
              // EXP_VARS(VAR_INX) = POPVAL(CTR+J); (1458)
              {
                descriptor_t *bitRHS
                    = (putBITp (16, mPOPVALxCTR,
                                fixedToBit (
                                    32, (int32_t)(xadd (
                                            COREHALFWORD (mPROCESS_EXTNxCTR),
                                            COREHALFWORD (mPROCESS_EXTNxJ))))),
                       POPVAL (0));
                putBIT (16, mEXP_VARS + 2 * (COREHALFWORD (mVAR_INX)), bitRHS);
                bitRHS->inUse = 0;
              }
            }
        } // End of DO for-loop block
      es2:;
      } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}