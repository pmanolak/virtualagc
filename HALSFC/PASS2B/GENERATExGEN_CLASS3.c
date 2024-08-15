/*
  File GENERATExGEN_CLASS3.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS3 (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExGEN_CLASS3");
// CLASS3: (12826)
CLASS3:
  // DO; (12827)
  {
  rs1:;
    // DO CASE SUBCODE; (12828)
    {
    rs1s1:
      switch (COREHALFWORD (mSUBCODE))
        {
        case 0:
          // DO; (12830)
          {
          rs1s1s1:;
            // CALL MAT_ASSIGN; (12830)
            GENERATExMAT_ASSIGN (0);
          es1s1s1:;
          } // End of DO block
          break;
        case 1:
          // DO; (12832)
          {
          rs1s1s2:;
            // CALL ARG_ASSEMBLE; (12832)
            GENERATExARG_ASSEMBLE (0);
            // ROW(0) = COLUMN(LEFTOP); (12833)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                          + 24 + 2 * (0));
              putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 48 + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // COLUMN(0) = ROW(LEFTOP); (12834)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                          + 48 + 2 * (0));
              putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 24 + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // TEMPSPACE = ROW(0) * COLUMN(0); (12835)
            {
              int32_t numberRHS = (int32_t)(xmultiply (
                  COREHALFWORD (getFIXED (mIND_STACK) + 73 * (0) + 48
                                + 2 * (0)),
                  COREHALFWORD (getFIXED (mIND_STACK) + 73 * (0) + 24
                                + 2 * (0))));
              putFIXED (mTEMPSPACE, numberRHS);
            }
            // CALL MAT_TEMP; (12836)
            GENERATExMAT_TEMP (0);
          es1s1s2:;
          } // End of DO block
          break;
        case 2:
          // DO; (12838)
          {
          rs1s1s3:;
            // CALL MAT_NEGATE; (12838)
            GENERATExMAT_NEGATE (0);
          es1s1s3:;
          } // End of DO block
          break;
        case 3:
          // DO; (12840)
          {
          rs1s1s4:;
            // CALL ARG_ASSEMBLE; (12840)
            GENERATExARG_ASSEMBLE (0);
            // COLUMN(0) = COLUMN(RIGHTOP); (12841)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRIGHTOP))
                          + 24 + 2 * (0));
              putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 24 + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // TEMPSPACE = ROW(0) * COLUMN(0); (12842)
            {
              int32_t numberRHS = (int32_t)(xmultiply (
                  COREHALFWORD (getFIXED (mIND_STACK) + 73 * (0) + 48
                                + 2 * (0)),
                  COREHALFWORD (getFIXED (mIND_STACK) + 73 * (0) + 24
                                + 2 * (0))));
              putFIXED (mTEMPSPACE, numberRHS);
            }
            // IF OPCODE= 2 | OPCODE= 3 THEN (12843)
            if (1
                & (xOR (xEQ (COREHALFWORD (mOPCODE), 2),
                        xEQ (COREHALFWORD (mOPCODE), 3))))
              // CLASS3_OP=TRUE; (12844)
              {
                int32_t numberRHS = (int32_t)(1);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (1, mGENERATExCLASS3_OP, bitRHS);
                bitRHS->inUse = 0;
              }
            // CALL MAT_TEMP; (12845)
            GENERATExMAT_TEMP (0);
          es1s1s4:;
          } // End of DO block
          break;
        case 4:
          // DO; (12847)
          {
          rs1s1s5:;
            // CALL ARG_ASSEMBLE; (12847)
            GENERATExARG_ASSEMBLE (0);
            // ROW(0) = COLUMN(LEFTOP); (12848)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                          + 24 + 2 * (0));
              putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 48 + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // COLUMN(0) = COLUMN(RIGHTOP); (12849)
            {
              descriptor_t *bitRHS = getBIT (
                  16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mRIGHTOP))
                          + 24 + 2 * (0));
              putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 24 + 2 * (0),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // TEMPSPACE = ROW(0) * COLUMN(0); (12850)
            {
              int32_t numberRHS = (int32_t)(xmultiply (
                  COREHALFWORD (getFIXED (mIND_STACK) + 73 * (0) + 48
                                + 2 * (0)),
                  COREHALFWORD (getFIXED (mIND_STACK) + 73 * (0) + 24
                                + 2 * (0))));
              putFIXED (mTEMPSPACE, numberRHS);
            }
            // OPTYPE = OPTYPE & 8 | CLASS; (12851)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  xAND (COREHALFWORD (mOPTYPE), 8), COREHALFWORD (mCLASS)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mOPTYPE, bitRHS);
              bitRHS->inUse = 0;
            }
            // CALL MAT_TEMP; (12852)
            GENERATExMAT_TEMP (0);
          es1s1s5:;
          } // End of DO block
          break;
        case 5:
          // DO; (12854)
          {
          rs1s1s6:;
            // CALL MIX_ASSEMBLE; (12854)
            GENERATExMIX_ASSEMBLE (0);
            // TEMPSPACE = ROW(0) * COLUMN(0); (12855)
            {
              int32_t numberRHS = (int32_t)(xmultiply (
                  COREHALFWORD (getFIXED (mIND_STACK) + 73 * (0) + 48
                                + 2 * (0)),
                  COREHALFWORD (getFIXED (mIND_STACK) + 73 * (0) + 24
                                + 2 * (0))));
              putFIXED (mTEMPSPACE, numberRHS);
            }
            // CLASS3_OP=TRUE; (12856)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mGENERATExCLASS3_OP, bitRHS);
              bitRHS->inUse = 0;
            }
            // CALL MAT_TEMP; (12857)
            GENERATExMAT_TEMP (0);
          es1s1s6:;
          } // End of DO block
          break;
        case 6:
          // DO; (12859)
          {
          rs1s1s7:;
            // LEFTOP = GET_OPERAND(1); (12859)
            {
              descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                               fixedToBit (32, (int32_t)(1))),
                                      GENERATExGET_OPERAND (0));
              putBIT (16, mLEFTOP, bitRHS);
              bitRHS->inUse = 0;
            }
            // STMT_PREC=(TYPE(LEFTOP) & 8); (12860)
            {
              int32_t numberRHS = (int32_t)(xAND (
                  COREHALFWORD (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mLEFTOP)) + 50
                                + 2 * (0)),
                  8));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mGENERATExSTMT_PREC, bitRHS);
              bitRHS->inUse = 0;
            }
            // IF CHECK_REMOTE(LEFTOP) | DEL(LEFTOP) > 0 THEN (12861)
            if (1
                & (xOR (bitToFixed ((putBITp (16, mGENERATExCHECK_REMOTExOP,
                                              getBIT (16, mLEFTOP)),
                                     GENERATExCHECK_REMOTE (0))),
                        xGT (COREHALFWORD (getFIXED (mIND_STACK)
                                           + 73 * (COREHALFWORD (mLEFTOP)) + 28
                                           + 2 * (0)),
                             0))))
              // LEFTOP = VECMAT_CONVERT(LEFTOP); (12862)
              {
                int32_t numberRHS
                    = (int32_t)((putBITp (16, mGENERATExVECMAT_CONVERTxOP,
                                          getBIT (16, mLEFTOP)),
                                 GENERATExVECMAT_CONVERT (0)));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mLEFTOP, bitRHS);
                bitRHS->inUse = 0;
              }
            // IF DATA_REMOTE & (CSECT_TYPE(LOC(LEFTOP),LEFTOP)=LOCAL#D) THEN
            // (12863)
            if (1
                & (xAND (
                    BYTE0 (mDATA_REMOTE),
                    xEQ (
                        bitToFixed ((
                            putBITp (
                                16, mCSECT_TYPExPTR,
                                getBIT (16, getFIXED (mIND_STACK)
                                                + 73 * (COREHALFWORD (mLEFTOP))
                                                + 40 + 2 * (0))),
                            putBITp (16, mCSECT_TYPExOP, getBIT (16, mLEFTOP)),
                            CSECT_TYPE (0))),
                        6))))
              // LEFTOP = VECMAT_CONVERT(LEFTOP); (12864)
              {
                int32_t numberRHS
                    = (int32_t)((putBITp (16, mGENERATExVECMAT_CONVERTxOP,
                                          getBIT (16, mLEFTOP)),
                                 GENERATExVECMAT_CONVERT (0)));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mLEFTOP, bitRHS);
                bitRHS->inUse = 0;
              }
            // CALL DROPSAVE(LEFTOP); (12865)
            {
              putBITp (16, mGENERATExDROPSAVExENTRY, getBIT (16, mLEFTOP));
              GENERATExDROPSAVE (0);
            }
            // LITTYPE = INTEGER; (12866)
            {
              descriptor_t *bitRHS = getBIT (8, mINTEGER);
              putBIT (16, mLITTYPE, bitRHS);
              bitRHS->inUse = 0;
            }
            // RIGHTOP = GET_OPERAND(2); (12867)
            {
              descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                               fixedToBit (32, (int32_t)(2))),
                                      GENERATExGET_OPERAND (0));
              putBIT (16, mRIGHTOP, bitRHS);
              bitRHS->inUse = 0;
            }
            // IF VAL(RIGHTOP) = 1 THEN (12868)
            if (1
                & (xEQ (getFIXED (getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mRIGHTOP)) + 12
                                  + 4 * (0)),
                        1)))
              // DO; (12869)
              {
              rs1s1s7s1:;
                // RESULT = LEFTOP; (12870)
                {
                  descriptor_t *bitRHS = getBIT (16, mLEFTOP);
                  putBIT (16, mRESULT, bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL RETURN_STACK_ENTRY(RIGHTOP); (12871)
                {
                  putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                           getBIT (16, mRIGHTOP));
                  GENERATExRETURN_STACK_ENTRY (0);
                }
              es1s1s7s1:;
              } // End of DO block
            // ELSE (12872)
            else
              // DO; (12873)
              {
              rs1s1s7s2:;
                // ROW(0), COLUMN(0) = COLUMN(LEFTOP); (12874)
                {
                  descriptor_t *bitRHS = getBIT (
                      16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                              + 24 + 2 * (0));
                  putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 48 + 2 * (0),
                          bitRHS);
                  putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 24 + 2 * (0),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
                // TEMPSPACE = ROW(0) * COLUMN(0); (12875)
                {
                  int32_t numberRHS = (int32_t)(xmultiply (
                      COREHALFWORD (getFIXED (mIND_STACK) + 73 * (0) + 48
                                    + 2 * (0)),
                      COREHALFWORD (getFIXED (mIND_STACK) + 73 * (0) + 24
                                    + 2 * (0))));
                  putFIXED (mTEMPSPACE, numberRHS);
                }
                // OPTYPE = TYPE(LEFTOP); (12876)
                {
                  descriptor_t *bitRHS = getBIT (
                      16, getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mLEFTOP))
                              + 50 + 2 * (0));
                  putBIT (16, mOPTYPE, bitRHS);
                  bitRHS->inUse = 0;
                }
                // IF VAL(RIGHTOP) < -1 THEN (12877)
                if (1
                    & (xLT (getFIXED (getFIXED (mIND_STACK)
                                      + 73 * (COREHALFWORD (mRIGHTOP)) + 12
                                      + 4 * (0)),
                            -1)))
                  // DO; (12878)
                  {
                  rs1s1s7s2s1:;
                    // VAL(RIGHTOP) = -VAL(RIGHTOP); (12879)
                    {
                      int32_t numberRHS = (int32_t)(xminus (getFIXED (
                          getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mRIGHTOP)) + 12 + 4 * (0))));
                      putFIXED (getFIXED (mIND_STACK)
                                    + 73 * (COREHALFWORD (mRIGHTOP)) + 12
                                    + 4 * (0),
                                numberRHS);
                    }
                    // RESULT = GET_VM_TEMP; (12880)
                    {
                      descriptor_t *bitRHS = GENERATExGET_VM_TEMP (0);
                      putBIT (16, mRESULT, bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // EXTOP = GETINVTEMP(OPTYPE, ROW(0)); (12881)
                    {
                      int32_t numberRHS = (int32_t)((
                          putBITp (16, mGENERATExGETINVTEMPxOPTYP,
                                   getBIT (16, mOPTYPE)),
                          putBITp (16, mGENERATExGETINVTEMPxSIZ,
                                   getBIT (16, getFIXED (mIND_STACK) + 73 * (0)
                                                   + 48 + 2 * (0))),
                          GENERATExGETINVTEMP (0)));
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mGENERATExEXTOP, bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // CALL DROPSAVE(EXTOP); (12882)
                    {
                      putBITp (16, mGENERATExDROPSAVExENTRY,
                               getBIT (16, mGENERATExEXTOP));
                      GENERATExDROPSAVE (0);
                    }
                    // CALL VMCALL(OPCODE,(OPTYPE&8)~=0,RESULT,LEFTOP,EXTOP,
                    // 0); (12883)
                    {
                      putBITp (16, mGENERATExVMCALLxOPCODE,
                               getBIT (16, mOPCODE));
                      putBITp (
                          8, mGENERATExVMCALLxOPTYPE,
                          fixedToBit (
                              32, (int32_t)(xNEQ (
                                      xAND (COREHALFWORD (mOPTYPE), 8), 0))));
                      putBITp (16, mGENERATExVMCALLxOP0, getBIT (16, mRESULT));
                      putBITp (16, mGENERATExVMCALLxOP1, getBIT (16, mLEFTOP));
                      putBITp (16, mGENERATExVMCALLxOP2,
                               getBIT (16, mGENERATExEXTOP));
                      putFIXED (mGENERATExVMCALLxPART, 0);
                      GENERATExVMCALL (0);
                    }
                    // CALL RETURN_STACK_ENTRIES(LEFTOP, EXTOP); (12884)
                    {
                      putBITp (16, mGENERATExRETURN_STACK_ENTRIESxPTR1,
                               getBIT (16, mLEFTOP));
                      putBITp (16, mGENERATExRETURN_STACK_ENTRIESxPTR2,
                               getBIT (16, mGENERATExEXTOP));
                      GENERATExRETURN_STACK_ENTRIES (0);
                    }
                    // CALL DROPFREESPACE; (12885)
                    GENERATExDROPFREESPACE (0);
                    // LEFTOP, LASTRESULT = RESULT; (12886)
                    {
                      descriptor_t *bitRHS = getBIT (16, mRESULT);
                      putBIT (16, mLEFTOP, bitRHS);
                      putBIT (16, mLASTRESULT, bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // CALL DROPSAVE(LEFTOP); (12887)
                    {
                      putBITp (16, mGENERATExDROPSAVExENTRY,
                               getBIT (16, mLEFTOP));
                      GENERATExDROPSAVE (0);
                    }
                  es1s1s7s2s1:;
                  } // End of DO block
                // IF VAL(RIGHTOP) > 1 THEN (12888)
                if (1
                    & (xGT (getFIXED (getFIXED (mIND_STACK)
                                      + 73 * (COREHALFWORD (mRIGHTOP)) + 12
                                      + 4 * (0)),
                            1)))
                  // DO; (12889)
                  {
                  rs1s1s7s2s2:;
                    // TARGET_REGISTER = FIXARG2; (12890)
                    {
                      descriptor_t *bitRHS = getBIT (8, mFIXARG2);
                      putBIT (16, mTARGET_REGISTER, bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // CALL FORCE_ACCUMULATOR(RIGHTOP); (12891)
                    {
                      putBITp (16, mGENERATExFORCE_ACCUMULATORxOP,
                               getBIT (16, mRIGHTOP));
                      GENERATExFORCE_ACCUMULATOR (0);
                    }
                    // CALL STACK_TARGET(RIGHTOP); (12892)
                    {
                      putBITp (16, mGENERATExSTACK_TARGETxOP,
                               getBIT (16, mRIGHTOP));
                      GENERATExSTACK_TARGET (0);
                    }
                    // RIGHTOP = 0; (12893)
                    {
                      int32_t numberRHS = (int32_t)(0);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mRIGHTOP, bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // OPCODE = XMEXP; (12894)
                    {
                      descriptor_t *bitRHS = getBIT (8, mXMEXP);
                      putBIT (16, mOPCODE, bitRHS);
                      bitRHS->inUse = 0;
                    }
                  es1s1s7s2s2:;
                  } // End of DO block
                // ELSE (12895)
                else
                  // IF VAL(RIGHTOP)=0 THEN (12896)
                  if (1
                      & (xEQ (getFIXED (getFIXED (mIND_STACK)
                                        + 73 * (COREHALFWORD (mRIGHTOP)) + 12
                                        + 4 * (0)),
                              0)))
                    // DO; (12897)
                    {
                    rs1s1s7s2s3:;
                      // OPCODE=XMIDN; (12898)
                      {
                        descriptor_t *bitRHS = getBIT (8, mXMIDN);
                        putBIT (16, mOPCODE, bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // CLASS1_OP=TRUE; (12899)
                      {
                        int32_t numberRHS = (int32_t)(1);
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (1, mGENERATExCLASS1_OP, bitRHS);
                        bitRHS->inUse = 0;
                      }
                    es1s1s7s2s3:;
                    } // End of DO block
                // CALL RETURN_STACK_ENTRY(RIGHTOP); (12900)
                {
                  putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                           getBIT (16, mRIGHTOP));
                  GENERATExRETURN_STACK_ENTRY (0);
                }
                // IF OPCODE = XMINV THEN (12901)
                if (1 & (xEQ (COREHALFWORD (mOPCODE), BYTE0 (mXMINV))))
                  // RIGHTOP = GETINVTEMP(OPTYPE, ROW(0)); (12902)
                  {
                    int32_t numberRHS = (int32_t)((
                        putBITp (16, mGENERATExGETINVTEMPxOPTYP,
                                 getBIT (16, mOPTYPE)),
                        putBITp (16, mGENERATExGETINVTEMPxSIZ,
                                 getBIT (16, getFIXED (mIND_STACK) + 73 * (0)
                                                 + 48 + 2 * (0))),
                        GENERATExGETINVTEMP (0)));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16, mRIGHTOP, bitRHS);
                    bitRHS->inUse = 0;
                  }
                // ELSE (12903)
                else
                  // IF OPCODE = XMEXP THEN (12904)
                  if (1 & (xEQ (COREHALFWORD (mOPCODE), BYTE0 (mXMEXP))))
                    // RIGHTOP = GETFREESPACE(OPTYPE, TEMPSPACE); (12905)
                    {
                      int32_t numberRHS = (int32_t)((
                          putFIXED (mGENERATExGETFREESPACExOPTYPE,
                                    COREHALFWORD (mOPTYPE)),
                          putFIXED (mGENERATExGETFREESPACExTEMPSPACE,
                                    getFIXED (mTEMPSPACE)),
                          GENERATExGETFREESPACE (0)));
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mRIGHTOP, bitRHS);
                      bitRHS->inUse = 0;
                    }
                  // ELSE (12906)
                  else
                    // RIGHTOP = 0; (12907)
                    {
                      int32_t numberRHS = (int32_t)(0);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mRIGHTOP, bitRHS);
                      bitRHS->inUse = 0;
                    }
                // IF RIGHTOP > 0 THEN (12908)
                if (1 & (xGT (COREHALFWORD (mRIGHTOP), 0)))
                  // CALL DROPSAVE(RIGHTOP); (12909)
                  {
                    putBITp (16, mGENERATExDROPSAVExENTRY,
                             getBIT (16, mRIGHTOP));
                    GENERATExDROPSAVE (0);
                  }
                // CALL MAT_TEMP; (12910)
                GENERATExMAT_TEMP (0);
              es1s1s7s2:;
              } // End of DO block
          es1s1s7:;
          } // End of DO block
          break;
        }
    } // End of DO CASE block
    // CALL SETUP_VAC(RESULT); (12911)
    {
      putBITp (16, mGENERATExSETUP_VACxOP, getBIT (16, mRESULT));
      GENERATExSETUP_VAC (0);
    }
  es1:;
  } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}