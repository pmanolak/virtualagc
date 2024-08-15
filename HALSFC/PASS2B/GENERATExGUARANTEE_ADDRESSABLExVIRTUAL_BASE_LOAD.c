/*
  File GENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOAD.c generated by XCOM-I,
  2024-08-09 12:41:32.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOAD (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (
      reentryGuard, "GENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOAD");
  // IF NR_DEREF(OP) & BASE_LOADED & R=3 THEN (4682)
  if (1
      & (xAND (
          xAND (
              BYTE0 (
                  getFIXED (mIND_STACK)
                  + 73
                        * (COREHALFWORD (
                            mGENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOADxOP))
                  + 60 + 1 * (0)),
              BYTE0 (mGENERATExGUARANTEE_ADDRESSABLExBASE_LOADED)),
          xEQ (COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExR), 3))))
    // DO; (4683)
    {
    rs1:;
      // BASE_LOADED = 0; (4684)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mGENERATExGUARANTEE_ADDRESSABLExBASE_LOADED, bitRHS);
        bitRHS->inUse = 0;
      }
      // TARGET_R = 2; (4685)
      {
        int32_t numberRHS = (int32_t)(2);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mTARGET_R, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // IF SRS_DESIRABLE(OP, NEED_SRS | BASE_LOADED) THEN (4686)
  if (1
      & (bitToFixed (
          (putBITp (
               16, mGENERATExGUARANTEE_ADDRESSABLExSRS_DESIRABLExOP,
               getBIT (16,
                       mGENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOADxOP)),
           putBITp (
               1, mGENERATExGUARANTEE_ADDRESSABLExSRS_DESIRABLExNEED_SRS,
               fixedToBit (
                   32,
                   (int32_t)(xOR (
                       BYTE0 (mGENERATExGUARANTEE_ADDRESSABLExNEED_SRS),
                       BYTE0 (mGENERATExGUARANTEE_ADDRESSABLExBASE_LOADED))))),
           GENERATExGUARANTEE_ADDRESSABLExSRS_DESIRABLE (0)))))
    // DO; (4687)
    {
    rs2:;
      // J = 0; (4688)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExJ, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF BASE_LOADED THEN (4689)
      if (1
          & (bitToFixed (
              getBIT (1, mGENERATExGUARANTEE_ADDRESSABLExBASE_LOADED))))
        // DO; (4690)
        {
        rs2s1:;
          // IF R = 1 THEN (4691)
          if (1 & (xEQ (COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExR), 1)))
            // R1_USED = FALSE; (4692)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mGENERATExR1_USED, bitRHS);
              bitRHS->inUse = 0;
            }
          // ELSE (4693)
          else
            // IF R = 3 THEN (4694)
            if (1
                & (xEQ (COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExR), 3)))
              // R3_USED = FALSE; (4695)
              {
                int32_t numberRHS = (int32_t)(0);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (1, mGENERATExR3_USED, bitRHS);
                bitRHS->inUse = 0;
              }
        es2s1:;
        } // End of DO block
      // IF ~BASE_LOADED THEN (4696)
      if (1 & (xNOT (BYTE0 (mGENERATExGUARANTEE_ADDRESSABLExBASE_LOADED))))
        // DO; (4697)
        {
        rs2s2:;
          // IF DATA_REMOTE & (CSECT_TYPE(PLOC,OP)=LOCAL#D) &
          // (SYT_BASE(PLOC)<0) THEN (4698)
          if (1
              & (xAND (
                  xAND (
                      BYTE0 (mDATA_REMOTE),
                      xEQ (
                          bitToFixed ((
                              putBITp (
                                  16, mCSECT_TYPExPTR,
                                  getBIT (
                                      16,
                                      mGENERATExGUARANTEE_ADDRESSABLExPLOC)),
                              putBITp (
                                  16, mCSECT_TYPExOP,
                                  getBIT (
                                      16,
                                      mGENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOADxOP)),
                              CSECT_TYPE (0))),
                          6)),
                  xLT (COREHALFWORD (
                           getFIXED (mP2SYMS)
                           + 12
                                 * (COREHALFWORD (
                                     mGENERATExGUARANTEE_ADDRESSABLExPLOC))
                           + 4 + 2 * (0)),
                       0))))
            // DO; (4699)
            {
            rs2s2s1:;
              // IF CHECK_SRS(INST, INX(OP), 3, INX_CON(OP)) ~= SRSTYPE THEN
              // (4700)
              if (1
                  & (xNEQ (
                      bitToFixed ((
                          putBITp (
                              16, mCHECK_SRSxINST,
                              getBIT (16,
                                      mGENERATExGUARANTEE_ADDRESSABLExINST)),
                          putBITp (
                              16, mCHECK_SRSxIX,
                              getBIT (
                                  16,
                                  getFIXED (mIND_STACK)
                                      + 73
                                            * (COREHALFWORD (
                                                mGENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOADxOP))
                                      + 34 + 2 * (0))),
                          putBITp (16, mCHECK_SRSxBASE,
                                   fixedToBit (32, (int32_t)(3))),
                          putFIXED (
                              mCHECK_SRSxDISP,
                              getFIXED (
                                  getFIXED (mIND_STACK)
                                  + 73
                                        * (COREHALFWORD (
                                            mGENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOADxOP))
                                  + 4 + 4 * (0))),
                          CHECK_SRS (0))),
                      BYTE0 (mSRSTYPE))))
                // DO; (4701)
                {
                rs2s2s1s1:;
                  // TARGET_R = 1; (4702)
                  {
                    int32_t numberRHS = (int32_t)(1);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mTARGET_R, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // D_R1_CHANGE = SHL(D_R1_CHANGE,1) | TRUE; (4703)
                  {
                    int32_t numberRHS
                        = (int32_t)(xOR (SHL (BYTE0 (mD_R1_CHANGE), 1), 1));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (8, mD_R1_CHANGE, bitRHS);
                    bitRHS->inUse = 0;
                  }
                es2s2s1s1:;
                } // End of DO block
              // ELSE (4704)
              else
                // DO; (4705)
                {
                rs2s2s1s2:;
                  // TARGET_R = 3; (4706)
                  {
                    int32_t numberRHS = (int32_t)(3);
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mTARGET_R, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // D_R3_CHANGE = SHL(D_R3_CHANGE,1) | TRUE; (4707)
                  {
                    int32_t numberRHS
                        = (int32_t)(xOR (SHL (BYTE0 (mD_R3_CHANGE), 1), 1));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (8, mD_R3_CHANGE, bitRHS);
                    bitRHS->inUse = 0;
                  }
                es2s2s1s2:;
                } // End of DO block
            es2s2s1:;
            } // End of DO block
          // IF BASE_POSSIBLE > 0 THEN (4708)
          if (1
              & (xGT (
                  COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExBASE_POSSIBLE),
                  0)))
            // IF INX(OP) ~= 0 THEN (4709)
            if (1
                & (xNEQ (
                    COREHALFWORD (
                        getFIXED (mIND_STACK)
                        + 73
                              * (COREHALFWORD (
                                  mGENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOADxOP))
                        + 34 + 2 * (0)),
                    0)))
              // IF R_SECTION(-R_VAR(BASE_POSSIBLE))=R_SECTION(-SYT_BASE(PLOC))
              // THEN (4710)
              if (1
                  & (xEQ (
                      BYTE0 (
                          mR_SECTION
                          + 1
                                * xminus (COREHALFWORD (
                                    mR_VAR
                                    + 2
                                          * COREHALFWORD (
                                              mGENERATExGUARANTEE_ADDRESSABLExBASE_POSSIBLE)))),
                      BYTE0 (
                          mR_SECTION
                          + 1
                                * xminus (COREHALFWORD (
                                    getFIXED (mP2SYMS)
                                    + 12
                                          * (COREHALFWORD (
                                              mGENERATExGUARANTEE_ADDRESSABLExPLOC))
                                    + 4 + 2 * (0)))))))
                // DO; (4711)
                {
                rs2s2s2:;
                  // I = R_BASE(-SYT_BASE(PLOC)) -
                  // R_BASE(-R_VAR(BASE_POSSIBLE)); (4712)
                  {
                    int32_t numberRHS = (int32_t)(xsubtract (
                        getFIXED (
                            mR_BASE
                            + 4
                                  * xminus (COREHALFWORD (
                                      getFIXED (mP2SYMS)
                                      + 12
                                            * (COREHALFWORD (
                                                mGENERATExGUARANTEE_ADDRESSABLExPLOC))
                                      + 4 + 2 * (0)))),
                        getFIXED (
                            mR_BASE
                            + 4
                                  * xminus (COREHALFWORD (
                                      mR_VAR
                                      + 2
                                            * COREHALFWORD (
                                                mGENERATExGUARANTEE_ADDRESSABLExBASE_POSSIBLE))))));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExI, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // IF I >= 0 THEN (4713)
                  if (1
                      & (xGE (COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExI),
                              0)))
                    // IF SYT_DISP(PLOC)+INX_CON(OP)+I < 2048 THEN (4714)
                    if (1
                        & (xLT (
                            xadd (
                                xadd (
                                    COREHALFWORD (
                                        getFIXED (mP2SYMS)
                                        + 12
                                              * (COREHALFWORD (
                                                  mGENERATExGUARANTEE_ADDRESSABLExPLOC))
                                        + 6 + 2 * (0)),
                                    getFIXED (
                                        getFIXED (mIND_STACK)
                                        + 73
                                              * (COREHALFWORD (
                                                  mGENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOADxOP))
                                        + 4 + 4 * (0))),
                                COREHALFWORD (
                                    mGENERATExGUARANTEE_ADDRESSABLExI)),
                            2048)))
                      // DO; (4715)
                      {
                      rs2s2s2s1:;
                        // J = I; (4716)
                        {
                          descriptor_t *bitRHS
                              = getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExI);
                          putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExJ,
                                  bitRHS);
                          bitRHS->inUse = 0;
                        }
                        // R = BASE_POSSIBLE; (4717)
                        {
                          descriptor_t *bitRHS = getBIT (
                              16,
                              mGENERATExGUARANTEE_ADDRESSABLExBASE_POSSIBLE);
                          putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR,
                                  bitRHS);
                          bitRHS->inUse = 0;
                        }
                        // BASE_LOADED = TRUE; (4718)
                        {
                          int32_t numberRHS = (int32_t)(1);
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (1,
                                  mGENERATExGUARANTEE_ADDRESSABLExBASE_LOADED,
                                  bitRHS);
                          bitRHS->inUse = 0;
                        }
                      es2s2s2s1:;
                      } // End of DO block
                es2s2s2:;
                } // End of DO block
          // IF ~BASE_LOADED THEN (4719)
          if (1 & (xNOT (BYTE0 (mGENERATExGUARANTEE_ADDRESSABLExBASE_LOADED))))
            // DO; (4720)
            {
            rs2s2s3:;
              // IF SPAREBASE = R3 & TARGET_R < 0 THEN (4721)
              if (1
                  & (xAND (xEQ (COREHALFWORD (
                                    mGENERATExGUARANTEE_ADDRESSABLExSPAREBASE),
                                BYTE0 (mR3)),
                           xLT (COREHALFWORD (mTARGET_R), 0))))
                // DO; (4722)
                {
                rs2s2s3s1:;
                  // IF USAGE(PTRARG1) = 0 THEN (4723)
                  if (1
                      & (xEQ (COREHALFWORD (mUSAGE + 2 * BYTE0 (mPTRARG1)),
                              0)))
                    // R = PTRARG1; (4724)
                    {
                      descriptor_t *bitRHS = getBIT (8, mPTRARG1);
                      putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR, bitRHS);
                      bitRHS->inUse = 0;
                    }
                  // ELSE (4725)
                  else
                    // IF USAGE(PTRARG1) = 1 THEN (4726)
                    if (1
                        & (xEQ (COREHALFWORD (mUSAGE + 2 * BYTE0 (mPTRARG1)),
                                1)))
                      // DO; (4727)
                      {
                      rs2s2s3s1s1:;
                        // IF USAGE(R3) <= 1 THEN (4728)
                        if (1
                            & (xLE (COREHALFWORD (mUSAGE + 2 * BYTE0 (mR3)),
                                    1)))
                          // DO; (4729)
                          {
                          rs2s2s3s1s1s1:;
                            // IF BASE_POSSIBLE=R3 & OTHER_BASE_REFS>0 THEN
                            // (4730)
                            if (1
                                & (xAND (
                                    xEQ (
                                        COREHALFWORD (
                                            mGENERATExGUARANTEE_ADDRESSABLExBASE_POSSIBLE),
                                        BYTE0 (mR3)),
                                    xGT (
                                        COREHALFWORD (
                                            mGENERATExGUARANTEE_ADDRESSABLExOTHER_BASE_REFS),
                                        0))))
                              // R = PTRARG1; (4731)
                              {
                                descriptor_t *bitRHS = getBIT (8, mPTRARG1);
                                putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR,
                                        bitRHS);
                                bitRHS->inUse = 0;
                              }
                            // ELSE (4732)
                            else
                              // R = R3; (4733)
                              {
                                descriptor_t *bitRHS = getBIT (8, mR3);
                                putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR,
                                        bitRHS);
                                bitRHS->inUse = 0;
                              }
                          es2s2s3s1s1s1:;
                          } // End of DO block
                        // ELSE (4734)
                        else
                          // R = PTRARG1; (4735)
                          {
                            descriptor_t *bitRHS = getBIT (8, mPTRARG1);
                            putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR,
                                    bitRHS);
                            bitRHS->inUse = 0;
                          }
                      es2s2s3s1s1:;
                      } // End of DO block
                    // ELSE (4736)
                    else
                      // IF USAGE(R3) <= 1 THEN (4737)
                      if (1
                          & (xLE (COREHALFWORD (mUSAGE + 2 * BYTE0 (mR3)), 1)))
                        // R = R3; (4738)
                        {
                          descriptor_t *bitRHS = getBIT (8, mR3);
                          putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR,
                                  bitRHS);
                          bitRHS->inUse = 0;
                        }
                      // ELSE (4739)
                      else
                        // RETURN INL; (4740)
                        {
                          reentryGuard = 0;
                          return getBIT (8, mINL);
                        }
                  // TARGET_R = R; (4741)
                  {
                    descriptor_t *bitRHS
                        = getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR);
                    putBIT (16, mTARGET_R, bitRHS);
                    bitRHS->inUse = 0;
                  }
                es2s2s3s1:;
                } // End of DO block
              // R = GET_R(OP,LOADBASE); (4742)
              {
                descriptor_t *bitRHS
                    = (putBITp (
                           16, mGENERATExGET_RxOP,
                           getBIT (
                               16,
                               mGENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOADxOP)),
                       putBITp (8, mGENERATExGET_RxTYPE_LOAD,
                                fixedToBit (32, (int32_t)(0))),
                       GENERATExGET_R (0));
                putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR, bitRHS);
                bitRHS->inUse = 0;
              }
              // TARGET_R = -1; (4743)
              {
                int32_t numberRHS = (int32_t)(-1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mTARGET_R, bitRHS);
                bitRHS->inUse = 0;
              }
              // CALL SET_USAGE(R, XPT, SYT_BASE(PLOC)); (4744)
              {
                putBITp (16, mGENERATExSET_USAGExR,
                         getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
                putBITp (16, mGENERATExSET_USAGExRFORM, getBIT (8, mXPT));
                putFIXED (mGENERATExSET_USAGExRVAR,
                          COREHALFWORD (
                              getFIXED (mP2SYMS)
                              + 12
                                    * (COREHALFWORD (
                                        mGENERATExGUARANTEE_ADDRESSABLExPLOC))
                              + 4 + 2 * (0)));
                GENERATExSET_USAGE (0);
              }
              // I = -SYT_BASE(PLOC); (4745)
              {
                int32_t numberRHS = (int32_t)(xminus (COREHALFWORD (
                    getFIXED (mP2SYMS)
                    + 12
                          * (COREHALFWORD (
                              mGENERATExGUARANTEE_ADDRESSABLExPLOC))
                    + 4 + 2 * (0))));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mGENERATExGUARANTEE_ADDRESSABLExI, bitRHS);
                bitRHS->inUse = 0;
              }
              // R_BASE_USED(I) = TRUE; (4746)
              {
                int32_t numberRHS = (int32_t)(1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (1,
                        mR_BASE_USED
                            + 1
                                  * (COREHALFWORD (
                                      mGENERATExGUARANTEE_ADDRESSABLExI)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
              // CALL EMITP(LH, R, 0, XPT, I); (4747)
              {
                putBITp (16, mGENERATExEMITPxINST, getBIT (8, mLH));
                putBITp (16, mGENERATExEMITPxXREG,
                         getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
                putBITp (16, mGENERATExEMITPxINDEX,
                         fixedToBit (32, (int32_t)(0)));
                putBITp (16, mGENERATExEMITPxFLAG, getBIT (8, mXPT));
                putBITp (16, mGENERATExEMITPxPTR,
                         getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExI));
                GENERATExEMITP (0);
              }
              // IF DATA_REMOTE & ((R=1) | (R=3)) THEN (4748)
              if (1
                  & (xAND (BYTE0 (mDATA_REMOTE),
                           xOR (xEQ (COREHALFWORD (
                                         mGENERATExGUARANTEE_ADDRESSABLExR),
                                     1),
                                xEQ (COREHALFWORD (
                                         mGENERATExGUARANTEE_ADDRESSABLExR),
                                     3)))))
                // CALL EMITP(NHI,R,0,0, 32767); (4749)
                {
                  putBITp (16, mGENERATExEMITPxINST, getBIT (8, mNHI));
                  putBITp (16, mGENERATExEMITPxXREG,
                           getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
                  putBITp (16, mGENERATExEMITPxINDEX,
                           fixedToBit (32, (int32_t)(0)));
                  putBITp (16, mGENERATExEMITPxFLAG,
                           fixedToBit (32, (int32_t)(0)));
                  putBITp (16, mGENERATExEMITPxPTR,
                           fixedToBit (32, (int32_t)(32767)));
                  GENERATExEMITP (0);
                }
            es2s2s3:;
            } // End of DO block
        es2s2:;
        } // End of DO block
      // BASE_LOADED=TRUE; (4750)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mGENERATExGUARANTEE_ADDRESSABLExBASE_LOADED, bitRHS);
        bitRHS->inUse = 0;
      }
      // BASE(OP), BACKUP_REG(OP) = R; (4751)
      {
        descriptor_t *bitRHS = getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR);
        putBIT (
            16,
            getFIXED (mIND_STACK)
                + 73
                      * (COREHALFWORD (
                          mGENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOADxOP))
                + 22 + 2 * (0),
            bitRHS);
        putBIT (
            16,
            getFIXED (mIND_STACK)
                + 73
                      * (COREHALFWORD (
                          mGENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOADxOP))
                + 20 + 2 * (0),
            bitRHS);
        bitRHS->inUse = 0;
      }
      // DISP(OP) = SYT_DISP(PLOC) + J; (4752)
      {
        int32_t numberRHS = (int32_t)(xadd (
            COREHALFWORD (
                getFIXED (mP2SYMS)
                + 12 * (COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExPLOC))
                + 6 + 2 * (0)),
            COREHALFWORD (mGENERATExGUARANTEE_ADDRESSABLExJ)));
        putBIT (
            16,
            getFIXED (mIND_STACK)
                + 73
                      * (COREHALFWORD (
                          mGENERATExGUARANTEE_ADDRESSABLExVIRTUAL_BASE_LOADxOP))
                + 30 + 2 * (0),
            fixedToBit (16, numberRHS));
      }
      // CALL INCR_USAGE(R); (4753)
      {
        putBITp (16, mGENERATExINCR_USAGExR,
                 getBIT (16, mGENERATExGUARANTEE_ADDRESSABLExR));
        GENERATExINCR_USAGE (0);
      }
      // RETURN CSYM; (4754)
      {
        reentryGuard = 0;
        return getBIT (8, mCSYM);
      }
    es2:;
    } // End of DO block
  // ELSE (4755)
  else
    // RETURN INL; (4756)
    {
      reentryGuard = 0;
      return getBIT (8, mINL);
    }
}