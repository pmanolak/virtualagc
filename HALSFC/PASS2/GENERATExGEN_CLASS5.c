/*
  File GENERATExGEN_CLASS5.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS5 (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExGEN_CLASS5");
// CLASS5: (13250)
CLASS5:
  // DO; (13251)
  {
  rs1:;
    // DO CASE SUBCODE; (13252)
    {
    rs1s1:
      switch (COREHALFWORD (mSUBCODE))
        {
        case 0:
          // DO; (13254)
          {
          rs1s1s1:;
            // CALL DO_ASSIGNMENT; (13254)
            GENERATExDO_ASSIGNMENT (0);
          es1s1s1:;
          } // End of DO block
          break;
        case 1:
          // DO; (13256)
          {
          rs1s1s2:;
            // LITTYPE = BITS; (13256)
            {
              descriptor_t *bitRHS = getBIT (8, mBITS);
              putBIT (16, mLITTYPE, bitRHS);
              bitRHS->inUse = 0;
            }
            // LEFTOP = GET_OPERAND(1); (13257)
            {
              descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                               fixedToBit (32, (int32_t)(1))),
                                      GENERATExGET_OPERAND (0));
              putBIT (16, mLEFTOP, bitRHS);
              bitRHS->inUse = 0;
            }
            // CALL FORCE_BY_MODE(LEFTOP, NEWPREC(TAG)|SCALAR); (13258)
            {
              putBITp (16, mGENERATExFORCE_BY_MODExOP, getBIT (16, mLEFTOP));
              putBITp (
                  16, mGENERATExFORCE_BY_MODExMODE,
                  fixedToBit (32, (int32_t)(xOR (
                                      COREHALFWORD (mGENERATExNEWPREC
                                                    + 2 * COREHALFWORD (mTAG)),
                                      BYTE0 (mSCALAR)))));
              GENERATExFORCE_BY_MODE (0);
            }
          es1s1s2:;
          } // End of DO block
          break;
        case 2:
          // DO; (13260)
          {
          rs1s1s3:;
            // LITTYPE = CHAR; (13260)
            {
              descriptor_t *bitRHS = getBIT (8, mCHAR);
              putBIT (16, mLITTYPE, bitRHS);
              bitRHS->inUse = 0;
            }
            // LEFTOP = CTON(GET_OPERAND(1), NEWPREC(TAG)|SCALAR); (13261)
            {
              descriptor_t *bitRHS
                  = (putBITp (16, mGENERATExCTONxOP,
                              (putBITp (16, mGENERATExGET_OPERANDxOP,
                                        fixedToBit (32, (int32_t)(1))),
                               GENERATExGET_OPERAND (0))),
                     putBITp (
                         16, mGENERATExCTONxOPTYPE,
                         fixedToBit (
                             32, (int32_t)(xOR (
                                     COREHALFWORD (mGENERATExNEWPREC
                                                   + 2 * COREHALFWORD (mTAG)),
                                     BYTE0 (mSCALAR))))),
                     GENERATExCTON (0));
              putBIT (16, mLEFTOP, bitRHS);
              bitRHS->inUse = 0;
            }
          es1s1s3:;
          } // End of DO block
          break;
        case 3:
          // DO; (13263)
          {
          rs1s1s4:;
            // CALL EXPONENTIAL(OPCODE); (13263)
            {
              putBITp (16, mGENERATExEXPONENTIALxOPCODE, getBIT (16, mOPCODE));
              GENERATExEXPONENTIAL (0);
            }
          es1s1s4:;
          } // End of DO block
          break;
        case 4:
          // DO; (13265)
          {
          rs1s1s5:;
            // CALL ARG_ASSEMBLE; (13265)
            GENERATExARG_ASSEMBLE (0);
            // TEMPSPACE = COLUMN(0); (13266)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mIND_STACK) + 73 * (0) + 24 + 2 * (0));
              int32_t numberRHS;
              numberRHS = bitToFixed (bitRHS);
              putFIXED (mTEMPSPACE, numberRHS);
              bitRHS->inUse = 0;
            }
            // CALL VMCALL(OPCODE, (OPTYPE&8)~=0, 0, LEFTOP, RIGHTOP, 0);
            // (13267)
            {
              putBITp (16, mGENERATExVMCALLxOPCODE, getBIT (16, mOPCODE));
              putBITp (
                  8, mGENERATExVMCALLxOPTYPE,
                  fixedToBit (32, (int32_t)(xNEQ (
                                      xAND (COREHALFWORD (mOPTYPE), 8), 0))));
              putBITp (16, mGENERATExVMCALLxOP0,
                       fixedToBit (32, (int32_t)(0)));
              putBITp (16, mGENERATExVMCALLxOP1, getBIT (16, mLEFTOP));
              putBITp (16, mGENERATExVMCALLxOP2, getBIT (16, mRIGHTOP));
              putFIXED (mGENERATExVMCALLxPART, 0);
              GENERATExVMCALL (0);
            }
            // CALL RETURN_STACK_ENTRY(RIGHTOP); (13268)
            {
              putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                       getBIT (16, mRIGHTOP));
              GENERATExRETURN_STACK_ENTRY (0);
            }
            // CALL SET_RESULT_REG(LEFTOP, OPTYPE&8 | SCALAR); (13269)
            {
              putBITp (16, mGENERATExSET_RESULT_REGxOP, getBIT (16, mLEFTOP));
              putBITp (16, mGENERATExSET_RESULT_REGxOPTYPE,
                       fixedToBit (
                           32, (int32_t)(xOR (xAND (COREHALFWORD (mOPTYPE), 8),
                                              BYTE0 (mSCALAR)))));
              GENERATExSET_RESULT_REG (0);
            }
            // COLUMN(LEFTOP) = 0; (13270)
            {
              int32_t numberRHS = (int32_t)(0);
              putBIT (16,
                      getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                          + 24 + 2 * (0),
                      fixedToBit (16, numberRHS));
            }
          es1s1s5:;
          } // End of DO block
          break;
        case 5:
          // DO; (13272)
          {
          rs1s1s6:;
            // IF OPCODE = XXASN THEN (13272)
            if (1 & (xEQ (COREHALFWORD (mOPCODE), BYTE0 (mXXASN))))
              // DO; (13273)
              {
              rs1s1s6s1:;
                // LITTYPE = NEWPREC(TAG) | SCALAR; (13274)
                {
                  int32_t numberRHS = (int32_t)(xOR (
                      COREHALFWORD (mGENERATExNEWPREC
                                    + 2 * COREHALFWORD (mTAG)),
                      BYTE0 (mSCALAR)));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mLITTYPE, bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL GET_OPERANDS; (13275)
                GENERATExGET_OPERANDS (0);
                // IF FORM(LEFTOP) = LIT THEN (13276)
                if (1
                    & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                          + 73 * (COREHALFWORD (mLEFTOP)) + 32
                                          + 2 * (0)),
                            BYTE0 (mLIT))))
                  // DO; (13277)
                  {
                  rs1s1s6s1s1:;
                    // TYPE(LEFTOP) = NEWPREC(TAG) | SCALAR; (13278)
                    {
                      int32_t numberRHS = (int32_t)(xOR (
                          COREHALFWORD (mGENERATExNEWPREC
                                        + 2 * COREHALFWORD (mTAG)),
                          BYTE0 (mSCALAR)));
                      putBIT (16,
                              getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mLEFTOP)) + 50
                                  + 2 * (0),
                              fixedToBit (16, numberRHS));
                    }
                    // IF TAG=1 & XVAL(LEFTOP)~=0 THEN (13279)
                    if (1
                        & (xAND (
                            xEQ (COREHALFWORD (mTAG), 1),
                            xNEQ (getFIXED (getFIXED (mIND_STACK)
                                            + 73 * (COREHALFWORD (mLEFTOP))
                                            + 16 + 4 * (0)),
                                  0))))
                      // DO; (13280)
                      {
                      rs1s1s6s1s1s1:;
                        // XVAL(LEFTOP) = 0; (13281)
                        {
                          int32_t numberRHS = (int32_t)(0);
                          putFIXED (getFIXED (mIND_STACK)
                                        + 73 * (COREHALFWORD (mLEFTOP)) + 16
                                        + 4 * (0),
                                    numberRHS);
                        }
                        // LOC(LEFTOP) = -1; (13282)
                        {
                          int32_t numberRHS = (int32_t)(-1);
                          putBIT (16,
                                  getFIXED (mIND_STACK)
                                      + 73 * (COREHALFWORD (mLEFTOP)) + 40
                                      + 2 * (0),
                                  fixedToBit (16, numberRHS));
                        }
                      es1s1s6s1s1s1:;
                      } // End of DO block
                  es1s1s6s1s1:;
                  } // End of DO block
                // ELSE (13283)
                else
                  // IF TYPE(LEFTOP) ~= LITTYPE THEN (13284)
                  if (1
                      & (xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                             + 73 * (COREHALFWORD (mLEFTOP))
                                             + 50 + 2 * (0)),
                               COREHALFWORD (mLITTYPE))))
                    // CALL FORCE_ACCUMULATOR(LEFTOP, LITTYPE); (13285)
                    {
                      putBITp (16, mGENERATExFORCE_ACCUMULATORxOP,
                               getBIT (16, mLEFTOP));
                      putBITp (16, mGENERATExFORCE_ACCUMULATORxOPTYPE,
                               getBIT (16, mLITTYPE));
                      GENERATExFORCE_ACCUMULATOR (0);
                    }
              es1s1s6s1:;
              } // End of DO block
            // ELSE (13286)
            else
              // IF OPCODE ~= XEXP THEN (13287)
              if (1 & (xNEQ (COREHALFWORD (mOPCODE), BYTE0 (mXEXP))))
                // CALL EVALUATE(OPCODE); (13288)
                {
                  putBITp (16, mGENERATExEVALUATExOPCODE,
                           getBIT (16, mOPCODE));
                  GENERATExEVALUATE (0);
                }
              // ELSE (13289)
              else
                // CALL EXPONENTIAL(OPCODE); (13290)
                {
                  putBITp (16, mGENERATExEXPONENTIALxOPCODE,
                           getBIT (16, mOPCODE));
                  GENERATExEXPONENTIAL (0);
                }
          es1s1s6:;
          } // End of DO block
          break;
        case 6:
          // DO; (13292)
          {
          rs1s1s7:;
            // LITTYPE = NEWPREC(TAG) | SCALAR; (13292)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  COREHALFWORD (mGENERATExNEWPREC + 2 * COREHALFWORD (mTAG)),
                  BYTE0 (mSCALAR)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mLITTYPE, bitRHS);
              bitRHS->inUse = 0;
            }
            // LEFTOP=GET_OPERAND(1); (13293)
            {
              descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                               fixedToBit (32, (int32_t)(1))),
                                      GENERATExGET_OPERAND (0));
              putBIT (16, mLEFTOP, bitRHS);
              bitRHS->inUse = 0;
            }
            // IF FORM(LEFTOP) ~= LIT | LOC(LEFTOP) < 0 THEN (13294)
            if (1
                & (xOR (xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                            + 73 * (COREHALFWORD (mLEFTOP))
                                            + 32 + 2 * (0)),
                              BYTE0 (mLIT)),
                        xLT (COREHALFWORD (getFIXED (mIND_STACK)
                                           + 73 * (COREHALFWORD (mLEFTOP)) + 40
                                           + 2 * (0)),
                             0))))
              // DO; (13295)
              {
              rs1s1s7s1:;
                // IF ((TAG=0 ) & (TYPE(LEFTOP) = DINTEGER)) THEN (13296)
                if (1
                    & (xAND (xEQ (COREHALFWORD (mTAG), 0),
                             xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                                + 73 * (COREHALFWORD (mLEFTOP))
                                                + 50 + 2 * (0)),
                                  BYTE0 (mDINTEGER)))))
                  // CALL FORCE_BY_MODE(LEFTOP, DSCALAR); (13297)
                  {
                    putBITp (16, mGENERATExFORCE_BY_MODExOP,
                             getBIT (16, mLEFTOP));
                    putBITp (16, mGENERATExFORCE_BY_MODExMODE,
                             getBIT (8, mDSCALAR));
                    GENERATExFORCE_BY_MODE (0);
                  }
                // ELSE (13298)
                else
                  // CALL FORCE_BY_MODE(LEFTOP, LITTYPE); (13299)
                  {
                    putBITp (16, mGENERATExFORCE_BY_MODExOP,
                             getBIT (16, mLEFTOP));
                    putBITp (16, mGENERATExFORCE_BY_MODExMODE,
                             getBIT (16, mLITTYPE));
                    GENERATExFORCE_BY_MODE (0);
                  }
              es1s1s7s1:;
              } // End of DO block
            // ELSE (13300)
            else
              // IF TAG1 ~= LIT THEN (13301)
              if (1 & (xNEQ (COREHALFWORD (mTAG1), BYTE0 (mLIT))))
                // IF (LIT1(GET_LITERAL(LOC(LEFTOP))) = 2) THEN (13302)
                if (1
                    & (xEQ (
                        getFIXED (
                            getFIXED (mLIT_PG) + 1560 * (0) + 0
                            + 4
                                  * ((putFIXED (
                                          mGET_LITERALxPTR,
                                          COREHALFWORD (
                                              getFIXED (mIND_STACK)
                                              + 73 * (COREHALFWORD (mLEFTOP))
                                              + 40 + 2 * (0))),
                                      GET_LITERAL (0)))),
                        2)))
                  // CALL FORCE_BY_MODE(LEFTOP, LITTYPE); (13303)
                  {
                    putBITp (16, mGENERATExFORCE_BY_MODExOP,
                             getBIT (16, mLEFTOP));
                    putBITp (16, mGENERATExFORCE_BY_MODExMODE,
                             getBIT (16, mLITTYPE));
                    GENERATExFORCE_BY_MODE (0);
                  }
                // ELSE (13304)
                else
                  // CALL LITERAL(LOC(LEFTOP), LITTYPE, LEFTOP); (13305)
                  {
                    putBITp (16, mGENERATExLITERALxPTR,
                             getBIT (16, getFIXED (mIND_STACK)
                                             + 73 * (COREHALFWORD (mLEFTOP))
                                             + 40 + 2 * (0)));
                    putBITp (16, mGENERATExLITERALxLTYPE,
                             getBIT (16, mLITTYPE));
                    putBITp (16, mGENERATExLITERALxSTACK,
                             getBIT (16, mLEFTOP));
                    GENERATExLITERAL (0);
                  }
            // IF FORM(LEFTOP) = LIT THEN (13306)
            if (1
                & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                      + 73 * (COREHALFWORD (mLEFTOP)) + 32
                                      + 2 * (0)),
                        BYTE0 (mLIT))))
              // IF TAG=1 & XVAL(LEFTOP)~=0 THEN (13307)
              if (1
                  & (xAND (xEQ (COREHALFWORD (mTAG), 1),
                           xNEQ (getFIXED (getFIXED (mIND_STACK)
                                           + 73 * (COREHALFWORD (mLEFTOP)) + 16
                                           + 4 * (0)),
                                 0))))
                // DO; (13308)
                {
                rs1s1s7s2:;
                  // XVAL(LEFTOP) = 0; (13309)
                  {
                    int32_t numberRHS = (int32_t)(0);
                    putFIXED (getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mLEFTOP)) + 16
                                  + 4 * (0),
                              numberRHS);
                  }
                  // LOC(LEFTOP) = -1; (13310)
                  {
                    int32_t numberRHS = (int32_t)(-1);
                    putBIT (16,
                            getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mLEFTOP)) + 40 + 2 * (0),
                            fixedToBit (16, numberRHS));
                  }
                es1s1s7s2:;
                } // End of DO block
          es1s1s7:;
          } // End of DO block
          break;
        }
    } // End of DO CASE block
    // CALL SETUP_VAC(LEFTOP); (13311)
    {
      putBITp (16, mGENERATExSETUP_VACxOP, getBIT (16, mLEFTOP));
      GENERATExSETUP_VAC (0);
    }
  es1:;
  } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
