/*
  File GENERATExGEN_CLASS0xFORCE_ADDR_LIT.c generated by XCOM-I, 2024-08-09
  12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xFORCE_ADDR_LIT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS0xFORCE_ADDR_LIT");
  // R = TR; (11124)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxTR);
    putBIT (16, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxR, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF DATA_REMOTE THEN (11125)
  if (1 & (bitToFixed (getBIT (1, mDATA_REMOTE))))
    // R = REG_STAT(OP,TR,LOADBASE); (11126)
    {
      descriptor_t *bitRHS
          = (putBITp (16, mGENERATExREG_STATxOP,
                      getBIT (16, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP)),
             putBITp (16, mGENERATExREG_STATxR,
                      getBIT (16, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxTR)),
             putBITp (8, mGENERATExREG_STATxTYPE_LOAD,
                      fixedToBit (32, (int32_t)(0))),
             GENERATExREG_STAT (0));
      putBIT (16, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxR, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF FORM(OP) = EXTSYM THEN (11127)
  if (1
      & (xEQ (
          COREHALFWORD (
              getFIXED (mIND_STACK)
              + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
              + 32 + 2 * (0)),
          BYTE0 (mEXTSYM))))
    // DO; (11128)
    {
    rs1:;
      // XVAL(OP) = LOC(OP); (11129)
      {
        descriptor_t *bitRHS = getBIT (
            16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                + 40 + 2 * (0));
        putFIXED (
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                + 16 + 4 * (0),
            bitToFixed (bitRHS));
        bitRHS->inUse = 0;
      }
      // VAL(OP) = 0; (11130)
      {
        int32_t numberRHS = (int32_t)(0);
        putFIXED (
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                + 12 + 4 * (0),
            numberRHS);
      }
    es1:;
    } // End of DO block
  // ELSE (11131)
  else
    // DO; (11132)
    {
    rs2:;
      // XVAL(OP) = DATABASE(SYT_SCOPE(LOC(OP))); (11133)
      {
        descriptor_t *bitRHS = getBIT (
            16,
            mDATABASE
                + 2
                      * BYTE0 (
                          getFIXED (mSYM_TAB)
                          + 34
                                * (COREHALFWORD (
                                    getFIXED (mIND_STACK)
                                    + 73
                                          * (COREHALFWORD (
                                              mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                                    + 40 + 2 * (0)))
                          + 29 + 1 * (0)));
        putFIXED (
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                + 16 + 4 * (0),
            bitToFixed (bitRHS));
        bitRHS->inUse = 0;
      }
      // VAL(OP) = R_BASE(ABS(SYT_BASE(LOC(OP)))) + SYT_DISP(LOC(OP)); (11134)
      {
        int32_t numberRHS = (int32_t)(xadd (
            getFIXED (
                getFIXED (mBASE_REGS)
                + 11
                      * (ABS (COREHALFWORD (
                          getFIXED (mP2SYMS)
                          + 12
                                * (COREHALFWORD (
                                    getFIXED (mIND_STACK)
                                    + 73
                                          * (COREHALFWORD (
                                              mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                                    + 40 + 2 * (0)))
                          + 4 + 2 * (0))))
                + 0 + 4 * (0)),
            COREHALFWORD (
                getFIXED (mP2SYMS)
                + 12
                      * (COREHALFWORD (
                          getFIXED (mIND_STACK)
                          + 73
                                * (COREHALFWORD (
                                    mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                          + 40 + 2 * (0)))
                + 6 + 2 * (0))));
        putFIXED (
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                + 12 + 4 * (0),
            numberRHS);
      }
    es2:;
    } // End of DO block
  // IF FLAG THEN (11135)
  if (1 & (bitToFixed (getBIT (1, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxFLAG))))
    // DO; (11136)
    {
    rs3:;
      // VAL(OP) = SHL(VAL(OP)+INX_CON(OP), 16) + MODIFIER; (11137)
      {
        int32_t numberRHS = (int32_t)(xadd (
            SHL (xadd (getFIXED (
                           getFIXED (mIND_STACK)
                           + 73
                                 * (COREHALFWORD (
                                     mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                           + 12 + 4 * (0)),
                       getFIXED (
                           getFIXED (mIND_STACK)
                           + 73
                                 * (COREHALFWORD (
                                     mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                           + 4 + 4 * (0))),
                 16),
            COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxMODIFIER)));
        putFIXED (
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                + 12 + 4 * (0),
            numberRHS);
      }
      // XVAL(OP) = SHL(XVAL(OP), 16) + DADDR; (11138)
      {
        int32_t numberRHS = (int32_t)(xadd (
            SHL (getFIXED (getFIXED (mIND_STACK)
                           + 73
                                 * (COREHALFWORD (
                                     mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                           + 16 + 4 * (0)),
                 16),
            BYTE0 (mDADDR)));
        putFIXED (
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                + 16 + 4 * (0),
            numberRHS);
      }
    es3:;
    } // End of DO block
  // ELSE (11139)
  else
    // DO; (11140)
    {
    rs4:;
      // VAL(OP) = SHL(VAL(OP) + INX_CON(OP), 16); (11141)
      {
        int32_t numberRHS = (int32_t)(SHL (
            xadd (getFIXED (getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                            + 12 + 4 * (0)),
                  getFIXED (getFIXED (mIND_STACK)
                            + 73
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                            + 4 + 4 * (0))),
            16));
        putFIXED (
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                + 12 + 4 * (0),
            numberRHS);
      }
      // XVAL(OP) = SHL(XVAL(OP) + MODIFIER, 16) + DADDR; (11142)
      {
        int32_t numberRHS = (int32_t)(xadd (
            SHL (xadd (getFIXED (
                           getFIXED (mIND_STACK)
                           + 73
                                 * (COREHALFWORD (
                                     mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                           + 16 + 4 * (0)),
                       COREHALFWORD (
                           mGENERATExGEN_CLASS0xFORCE_ADDR_LITxMODIFIER)),
                 16),
            BYTE0 (mDADDR)));
        putFIXED (
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                + 16 + 4 * (0),
            numberRHS);
      }
    es4:;
    } // End of DO block
  // INX_CON(OP) = 0; (11143)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (
        getFIXED (mIND_STACK)
            + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP)) + 4
            + 4 * (0),
        numberRHS);
  }
  // CALL SAVE_LITERAL(OP, ADCON); (11144)
  {
    putBITp (16, mGENERATExSAVE_LITERALxOP,
             getBIT (16, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP));
    putBITp (16, mGENERATExSAVE_LITERALxOPTYPE, getBIT (8, mADCON));
    GENERATExSAVE_LITERAL (0);
  }
  // IF R<0 THEN (11145)
  if (1 & (xLT (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxR), 0)))
    // DO; (11146)
    {
    rs5:;
      // R=GET_R(OP,LOADBASE); (11147)
      {
        descriptor_t *bitRHS
            = (putBITp (16, mGENERATExGET_RxOP,
                        getBIT (16, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP)),
               putBITp (8, mGENERATExGET_RxTYPE_LOAD,
                        fixedToBit (32, (int32_t)(0))),
               GENERATExGET_R (0));
        putBIT (16, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxR, bitRHS);
        bitRHS->inUse = 0;
      }
      // USAGE(R)=0; (11148)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (
            16,
            mUSAGE
                + 2 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxR)),
            bitRHS);
        bitRHS->inUse = 0;
      }
    es5:;
    } // End of DO block
  // ELSE (11149)
  else
    // CALL CHECKPOINT_REG(R,1); (11150)
    {
      putBITp (16, mGENERATExCHECKPOINT_REGxR,
               getBIT (16, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxR));
      putBITp (1, mGENERATExCHECKPOINT_REGxSAVE,
               fixedToBit (32, (int32_t)(1)));
      GENERATExCHECKPOINT_REG (0);
    }
  // CALL EMITOP(L, R, OP); (11151)
  {
    putBITp (16, mGENERATExEMITOPxINST, getBIT (8, mL));
    putBITp (16, mGENERATExEMITOPxXREG,
             getBIT (16, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxR));
    putBITp (16, mGENERATExEMITOPxOP,
             getBIT (16, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP));
    GENERATExEMITOP (0);
  }
  // CALL UNRECOGNIZABLE(R); (11152)
  {
    putBITp (16, mGENERATExUNRECOGNIZABLExR,
             getBIT (16, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxR));
    GENERATExUNRECOGNIZABLE (0);
  }
  // IF FLAG THEN (11153)
  if (1 & (bitToFixed (getBIT (1, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxFLAG))))
    // USAGE(R) = 2; (11154)
    {
      int32_t numberRHS = (int32_t)(2);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16,
              mUSAGE
                  + 2 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxR)),
              bitRHS);
      bitRHS->inUse = 0;
    }
  // REG(OP) = R; (11155)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxR);
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExGEN_CLASS0xFORCE_ADDR_LITxOP))
                + 46 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // FLAG = FALSE; (11156)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExGEN_CLASS0xFORCE_ADDR_LITxFLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
