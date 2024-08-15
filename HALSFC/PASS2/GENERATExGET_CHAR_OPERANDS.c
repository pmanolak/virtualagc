/*
  File GENERATExGET_CHAR_OPERANDS.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExGET_CHAR_OPERANDS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExGET_CHAR_OPERANDS");
  // LITTYPE = CHAR; (7735)
  {
    descriptor_t *bitRHS = getBIT (8, mCHAR);
    putBIT (16, mLITTYPE, bitRHS);
    bitRHS->inUse = 0;
  }
  // LEFTOP = GET_OPERAND(1); (7736)
  {
    descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                     fixedToBit (32, (int32_t)(1))),
                            GENERATExGET_OPERAND (0));
    putBIT (16, mLEFTOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF CHECK_REMOTE(LEFTOP) | COLUMN(LEFTOP) > 0 THEN (7737)
  if (1
      & (xOR (
          bitToFixed (
              (putBITp (16, mGENERATExCHECK_REMOTExOP, getBIT (16, mLEFTOP)),
               GENERATExCHECK_REMOTE (0))),
          xGT (COREHALFWORD (getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mLEFTOP)) + 24 + 2 * (0)),
               0))))
    // LEFTOP = CHAR_CONVERT(LEFTOP); (7738)
    {
      descriptor_t *bitRHS
          = (putBITp (16, mGENERATExCHAR_CONVERTxOP, getBIT (16, mLEFTOP)),
             GENERATExCHAR_CONVERT (0));
      putBIT (16, mLEFTOP, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF DATA_REMOTE & (CSECT_TYPE(LOC(LEFTOP),LEFTOP)=LOCAL#D) THEN (7739)
  if (1
      & (xAND (
          BYTE0 (mDATA_REMOTE),
          xEQ (bitToFixed (
                   (putBITp (16, mCSECT_TYPExPTR,
                             getBIT (16, getFIXED (mIND_STACK)
                                             + 73 * (COREHALFWORD (mLEFTOP))
                                             + 40 + 2 * (0))),
                    putBITp (16, mCSECT_TYPExOP, getBIT (16, mLEFTOP)),
                    CSECT_TYPE (0))),
               6))))
    // LEFTOP = CHAR_CONVERT(LEFTOP); (7740)
    {
      descriptor_t *bitRHS
          = (putBITp (16, mGENERATExCHAR_CONVERTxOP, getBIT (16, mLEFTOP)),
             GENERATExCHAR_CONVERT (0));
      putBIT (16, mLEFTOP, bitRHS);
      bitRHS->inUse = 0;
    }
  // CALL DROPSAVE(LEFTOP); (7741)
  {
    putBITp (16, mGENERATExDROPSAVExENTRY, getBIT (16, mLEFTOP));
    GENERATExDROPSAVE (0);
  }
  // IF NUMOP = 2 THEN (7742)
  if (1 & (xEQ (COREHALFWORD (mNUMOP), 2)))
    // DO; (7743)
    {
    rs1:;
      // IF CLASS = 0 THEN (7744)
      if (1 & (xEQ (COREHALFWORD (mCLASS), 0)))
        // LITTYPE = TYPE_BITS(2); (7745)
        {
          descriptor_t *bitRHS = (putBITp (16, mGENERATExTYPE_BITSxOP,
                                           fixedToBit (32, (int32_t)(2))),
                                  GENERATExTYPE_BITS (0));
          putBIT (16, mLITTYPE, bitRHS);
          bitRHS->inUse = 0;
        }
      // RIGHTOP = GET_OPERAND(2); (7746)
      {
        descriptor_t *bitRHS = (putBITp (16, mGENERATExGET_OPERANDxOP,
                                         fixedToBit (32, (int32_t)(2))),
                                GENERATExGET_OPERAND (0));
        putBIT (16, mRIGHTOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF TYPE(RIGHTOP) = CHAR THEN (7747)
      if (1
          & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mRIGHTOP)) + 50
                                + 2 * (0)),
                  BYTE0 (mCHAR))))
        // DO; (7748)
        {
        rs1s1:;
          // IF CHECK_REMOTE(RIGHTOP) | COLUMN(RIGHTOP) > 0 THEN (7749)
          if (1
              & (xOR (bitToFixed ((putBITp (16, mGENERATExCHECK_REMOTExOP,
                                            getBIT (16, mRIGHTOP)),
                                   GENERATExCHECK_REMOTE (0))),
                      xGT (COREHALFWORD (getFIXED (mIND_STACK)
                                         + 73 * (COREHALFWORD (mRIGHTOP)) + 24
                                         + 2 * (0)),
                           0))))
            // RIGHTOP = CHAR_CONVERT(RIGHTOP); (7750)
            {
              descriptor_t *bitRHS = (putBITp (16, mGENERATExCHAR_CONVERTxOP,
                                               getBIT (16, mRIGHTOP)),
                                      GENERATExCHAR_CONVERT (0));
              putBIT (16, mRIGHTOP, bitRHS);
              bitRHS->inUse = 0;
            }
          // IF DATA_REMOTE & (CSECT_TYPE(LOC(RIGHTOP),RIGHTOP)=LOCAL#D) THEN
          // (7751)
          if (1
              & (xAND (
                  BYTE0 (mDATA_REMOTE),
                  xEQ (bitToFixed ((
                           putBITp (
                               16, mCSECT_TYPExPTR,
                               getBIT (16, getFIXED (mIND_STACK)
                                               + 73 * (COREHALFWORD (mRIGHTOP))
                                               + 40 + 2 * (0))),
                           putBITp (16, mCSECT_TYPExOP, getBIT (16, mRIGHTOP)),
                           CSECT_TYPE (0))),
                       6))))
            // RIGHTOP = CHAR_CONVERT(RIGHTOP); (7752)
            {
              descriptor_t *bitRHS = (putBITp (16, mGENERATExCHAR_CONVERTxOP,
                                               getBIT (16, mRIGHTOP)),
                                      GENERATExCHAR_CONVERT (0));
              putBIT (16, mRIGHTOP, bitRHS);
              bitRHS->inUse = 0;
            }
          // CALL DROPSAVE(RIGHTOP); (7753)
          {
            putBITp (16, mGENERATExDROPSAVExENTRY, getBIT (16, mRIGHTOP));
            GENERATExDROPSAVE (0);
          }
        es1s1:;
        } // End of DO block
      // ELSE (7754)
      else
        // DO; (7755)
        {
        rs1s2:;
          // TARGET_REGISTER = FIXARG1; (7756)
          {
            descriptor_t *bitRHS = getBIT (8, mFIXARG1);
            putBIT (16, mTARGET_REGISTER, bitRHS);
            bitRHS->inUse = 0;
          }
          // CALL FORCE_ACCUMULATOR(RIGHTOP); (7757)
          {
            putBITp (16, mGENERATExFORCE_ACCUMULATORxOP,
                     getBIT (16, mRIGHTOP));
            GENERATExFORCE_ACCUMULATOR (0);
          }
          // CALL STACK_TARGET(RIGHTOP); (7758)
          {
            putBITp (16, mGENERATExSTACK_TARGETxOP, getBIT (16, mRIGHTOP));
            GENERATExSTACK_TARGET (0);
          }
          // RIGHTOP = 0; (7759)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mRIGHTOP, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s2:;
        } // End of DO block
    es1:;
    } // End of DO block
  // ELSE (7760)
  else
    // RIGHTOP = 0; (7761)
    {
      int32_t numberRHS = (int32_t)(0);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mRIGHTOP, bitRHS);
      bitRHS->inUse = 0;
    }
  {
    reentryGuard = 0;
    return 0;
  }
}