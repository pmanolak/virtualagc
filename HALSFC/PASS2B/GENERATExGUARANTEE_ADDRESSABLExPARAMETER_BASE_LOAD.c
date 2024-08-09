/*
  File GENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOAD.c generated by
  XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOAD (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (
      reentryGuard, "GENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOAD");
  // SETUP_R = FALSE; (4645)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxSETUP_R,
            bitRHS);
    bitRHS->inUse = 0;
  }
  // R = PTRARG1 - 1; (4646)
  {
    int32_t numberRHS = (int32_t)(xsubtract (BYTE0 (mPTRARG1), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO UNTIL (R = SPAREBASE) | SETUP_R; (4647)
  do
    {
      // R = R + 1; (4648)
      {
        int32_t numberRHS = (int32_t)(xadd (
            COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExR), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF USAGE(R) THEN (4649)
      if (1
          & (bitToFixed (getBIT (
              16,
              mUSAGE + 2 * COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExR)))))
        // IF R_CONTENTS(R) = APOINTER THEN (4650)
        if (1
            & (xEQ (
                BYTE0 (mR_CONTENTS
                       + 1 * COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExR)),
                BYTE0 (mAPOINTER))))
          // IF R_VAR(R) = PLOC THEN (4651)
          if (1
              & (xEQ (
                  COREHALFWORD (
                      mR_VAR
                      + 2 * COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExR)),
                  COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExPLOC))))
            // SETUP_R = TRUE; (4652)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (
                  1,
                  mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxSETUP_R,
                  bitRHS);
              bitRHS->inUse = 0;
            }
    }
  while (!(
      1
      & (xOR (
          xEQ (COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExR),
               COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExSPAREBASE)),
          BYTE0 (
              mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxSETUP_R))))); // End of DO UNTIL block
  // IF ~SETUP_R THEN (4653)
  if (1
      & (xNOT (BYTE0 (
          mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxSETUP_R))))
    // DO; (4654)
    {
    rs2:;
      // R = CHOOSE_BASE(OP,LOADPARM,SPAREBASE); (4655)
      {
        descriptor_t *bitRHS
            = (putBITp (
                   16, mGENERATExCHOOSE_BASExOP,
                   getBIT (
                       16,
                       mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP)),
               putBITp (8, mGENERATExCHOOSE_BASExTYPE_LOAD,
                        fixedToBit (32, (int32_t)(2))),
               putBITp (
                   16, mGENERATExCHOOSE_BASExSPAREBASE,
                   getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExSPAREBASE)),
               GENERATExCHOOSE_BASE (0));
        putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL SET_USAGE(R, APOINTER, PLOC); (4656)
      {
        putBITp (16, mGENERATExSET_USAGExR,
                 getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
        putBITp (16, mGENERATExSET_USAGExRFORM, getBIT (8, mAPOINTER));
        putFIXED (mGENERATExSET_USAGExRVAR,
                  COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExPLOC));
        GENERATExSET_USAGE (0);
      }
      // CALL CHECK_ADDR_NEST(R, OP); (4657)
      {
        putBITp (16, mGENERATExCHECK_ADDR_NESTxTR,
                 getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
        putBITp (
            16, mGENERATExCHECK_ADDR_NESTxOP,
            getBIT (16,
                    mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP));
        GENERATExCHECK_ADDR_NEST (0);
      }
      // IF ((SYT_FLAGS(PLOC) & ASSIGN_OR_NAME)~=  ASSIGN_OR_NAME) &
      // POINTS_REMOTE(OP)  THEN (4658)
      if (1
          & (xAND (
              xNEQ (xAND (getFIXED (
                              getFIXED (mSYM_TAB)
                              + 34
                                    * (COREHALFWORD (
                                        mGENERATExGUARANTEE_ADDRESSABLExPLOC))
                              + 8 + 4 * (0)),
                          getFIXED (mASSIGN_OR_NAME)),
                    getFIXED (mASSIGN_OR_NAME)),
              BYTE0 (
                  getFIXED (mIND_STACK)
                  + 73
                        * (COREHALFWORD (
                            mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP))
                  + 68 + 1 * (0)))))
        // CALL EMITXOP(L, R, OP); (4659)
        {
          putBITp (16, mGENERATExEMITXOPxINST, getBIT (8, mL));
          putBITp (16, mGENERATExEMITXOPxXREG,
                   getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
          putBITp (
              16, mGENERATExEMITXOPxOP,
              getBIT (16,
                      mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP));
          GENERATExEMITXOP (0);
        }
      // ELSE (4660)
      else
        // CALL EMITXOP(LH, R, OP); (4661)
        {
          putBITp (16, mGENERATExEMITXOPxINST, getBIT (8, mLH));
          putBITp (16, mGENERATExEMITXOPxXREG,
                   getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
          putBITp (
              16, mGENERATExEMITXOPxOP,
              getBIT (16,
                      mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP));
          GENERATExEMITXOP (0);
        }
    es2:;
    } // End of DO block
  // CALL INCR_USAGE(R); (4662)
  {
    putBITp (16, mGENERATExINCR_USAGExR,
             getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
    GENERATExINCR_USAGE (0);
  }
  // IF ((SYT_FLAGS(PLOC) & REMOTE_FLAG) ~= 0)  & DEREF(OP)   THEN (4663)
  if (1
      & (xAND (
          xNEQ (
              xAND (getFIXED (getFIXED (mSYM_TAB)
                              + 34
                                    * (COREHALFWORD (
                                        mGENERATExGUARANTEE_ADDRESSABLExPLOC))
                              + 8 + 4 * (0)),
                    getFIXED (mREMOTE_FLAG)),
              0),
          bitToFixed ((
              putBITp (
                  16, mGENERATExDEREFxOP,
                  getBIT (
                      16,
                      mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP)),
              GENERATExDEREF (0))))))
    // NR_DEREF(OP) = TRUE; (4664)
    {
      int32_t numberRHS = (int32_t)(1);
      putBIT (
          8,
          getFIXED (mIND_STACK)
              + 73
                    * (COREHALFWORD (
                        mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP))
              + 60 + 1 * (0),
          fixedToBit (8, numberRHS));
    }
  // ELSE (4665)
  else
    // IF ~BY_NAME THEN (4666)
    if (1 & (xNOT (BYTE0 (mGENERATExGUARANTEE_ADDRESSABLExBY_NAME))))
      // IF (SYT_FLAGS(PLOC) & ASSIGN_OR_NAME) = ASSIGN_OR_NAME THEN (4667)
      if (1
          & (xEQ (
              xAND (getFIXED (getFIXED (mSYM_TAB)
                              + 34
                                    * (COREHALFWORD (
                                        mGENERATExGUARANTEE_ADDRESSABLExPLOC))
                              + 8 + 4 * (0)),
                    getFIXED (mASSIGN_OR_NAME)),
              getFIXED (mASSIGN_OR_NAME))))
        // DO; (4668)
        {
        rs3:;
          // IF USAGE(R) > 3 THEN (4669)
          if (1
              & (xGT (
                  COREHALFWORD (
                      mUSAGE
                      + 2 * COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExR)),
                  3)))
            // R = GET_R(OP,LOADBASE); (4670)
            {
              descriptor_t *bitRHS
                  = (putBITp (
                         16, mGENERATExGET_RxOP,
                         getBIT (
                             16,
                             mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP)),
                     putBITp (8, mGENERATExGET_RxTYPE_LOAD,
                              fixedToBit (32, (int32_t)(0))),
                     GENERATExGET_R (0));
              putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR, bitRHS);
              bitRHS->inUse = 0;
            }
          // IF POINTS_REMOTE(OP) THEN (4671)
          if (1
              & (bitToFixed (getBIT (
                  8,
                  getFIXED (mIND_STACK)
                      + 73
                            * (COREHALFWORD (
                                mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP))
                      + 68 + 1 * (0)))))
            // CALL EMITRX(L, R, 0, R, 0); (4672)
            {
              putBITp (16, mGENERATExEMITRXxINST, getBIT (8, mL));
              putBITp (16, mGENERATExEMITRXxXREG,
                       getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
              putBITp (16, mGENERATExEMITRXxINDEX,
                       fixedToBit (32, (int32_t)(0)));
              putBITp (16, mGENERATExEMITRXxXBASE,
                       getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
              putBITp (16, mGENERATExEMITRXxXDISP,
                       fixedToBit (32, (int32_t)(0)));
              GENERATExEMITRX (0);
            }
          // ELSE (4673)
          else
            // CALL EMITRX(LH, R, 0, R, 0); (4674)
            {
              putBITp (16, mGENERATExEMITRXxINST, getBIT (8, mLH));
              putBITp (16, mGENERATExEMITRXxXREG,
                       getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
              putBITp (16, mGENERATExEMITRXxINDEX,
                       fixedToBit (32, (int32_t)(0)));
              putBITp (16, mGENERATExEMITRXxXBASE,
                       getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
              putBITp (16, mGENERATExEMITRXxXDISP,
                       fixedToBit (32, (int32_t)(0)));
              GENERATExEMITRX (0);
            }
          // USAGE(R) = 2; (4675)
          {
            int32_t numberRHS = (int32_t)(2);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (
                16,
                mUSAGE
                    + 2 * (COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExR)),
                bitRHS);
            bitRHS->inUse = 0;
          }
        es3:;
        } // End of DO block
  // BASE(OP), BACKUP_REG(OP) = R; (4676)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR);
    putBIT (
        16,
        getFIXED (mIND_STACK)
            + 73
                  * (COREHALFWORD (
                      mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP))
            + 22 + 2 * (0),
        bitRHS);
    putBIT (
        16,
        getFIXED (mIND_STACK)
            + 73
                  * (COREHALFWORD (
                      mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP))
            + 20 + 2 * (0),
        bitRHS);
    bitRHS->inUse = 0;
  }
  // DISP(OP) = INX_CON(OP); (4677)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mIND_STACK)
        + 73
              * (COREHALFWORD (
                  mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP))
        + 4 + 4 * (0)));
    putBIT (
        16,
        getFIXED (mIND_STACK)
            + 73
                  * (COREHALFWORD (
                      mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP))
            + 30 + 2 * (0),
        fixedToBit (16, numberRHS));
  }
  // CALL CHECK_CSYM_INX(OP, R); (4678)
  {
    putBITp (
        16, mGENERATExCHECK_CSYM_INXxOP,
        getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP));
    putBITp (16, mGENERATExCHECK_CSYM_INXxR,
             getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
    GENERATExCHECK_CSYM_INX (0);
  }
  // IF ~POINTS_REMOTE(OP) THEN (4679)
  if (1
      & (xNOT (BYTE0 (
          getFIXED (mIND_STACK)
          + 73
                * (COREHALFWORD (
                    mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP))
          + 68 + 1 * (0)))))
    // INX_CON(OP) = 0; (4680)
    {
      int32_t numberRHS = (int32_t)(0);
      putFIXED (
          getFIXED (mIND_STACK)
              + 73
                    * (COREHALFWORD (
                        mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP))
              + 4 + 4 * (0),
          numberRHS);
    }
  // FORM(OP) = CSYM; (4681)
  {
    descriptor_t *bitRHS = getBIT (8, mCSYM);
    putBIT (
        16,
        getFIXED (mIND_STACK)
            + 73
                  * (COREHALFWORD (
                      mGENERATExGUARANTEE_ADDRESSABLExPARAMETER_BASE_LOADxOP))
            + 32 + 2 * (0),
        bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
