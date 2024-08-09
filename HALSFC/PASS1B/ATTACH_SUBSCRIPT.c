/*
  File ATTACH_SUBSCRIPT.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
ATTACH_SUBSCRIPT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ATTACH_SUBSCRIPT");
  // INX=PTR(SP); (8537)
  {
    descriptor_t *bitRHS = getBIT (16, mPTR + 2 * getFIXED (mSP));
    putBIT (16, mINX, bitRHS);
    bitRHS->inUse = 0;
  }
  // I=2; (8538)
  {
    int32_t numberRHS = (int32_t)(2);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mATTACH_SUBSCRIPTxI, bitRHS);
    bitRHS->inUse = 0;
  }
  // IND_LINK=0; (8539)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mIND_LINK, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF ~GET_ARRAYNESS THEN (8540)
  if (1 & (xNOT (bitToFixed (GET_ARRAYNESS (0)))))
    // IF FIXL(SP)=3 THEN (8541)
    if (1 & (xEQ (getFIXED (mFIXL + 4 * getFIXED (mSP)), 3)))
      // DO; (8542)
      {
      rs1:;
        // CALL ERROR(CLASS_FT,8,VAR(MP)); (8543)
        {
          putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_FT));
          putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(8)));
          putCHARACTERp (mERRORxTEXT,
                         getCHARACTER (mVAR + 4 * getFIXED (mMP)));
          ERROR (0);
        }
        // INX(INX)=0; (8544)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mINX + 2 * (COREHALFWORD (mINX)), bitRHS);
          bitRHS->inUse = 0;
        }
      es1:;
      } // End of DO block
  // IF INX(INX)>0 THEN (8545)
  if (1 & (xGT (COREHALFWORD (mINX + 2 * COREHALFWORD (mINX)), 0)))
    // DO; (8546)
    {
    rs2:;
      // IF PSEUDO_FORM(INX)~=0 THEN (8547)
      if (1 & (xNEQ (BYTE0 (mPSEUDO_FORM + 1 * COREHALFWORD (mINX)), 0)))
        // DO; (8548)
        {
        rs2s1:;
          // CALL ERROR(CLASS_SQ,2,VAR(MP)); (8549)
          {
            putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SQ));
            putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(2)));
            putCHARACTERp (mERRORxTEXT,
                           getCHARACTER (mVAR + 4 * getFIXED (mMP)));
            ERROR (0);
          }
          // PSEUDO_FORM(INX)=0; (8550)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (8, mPSEUDO_FORM + 1 * (COREHALFWORD (mINX)), bitRHS);
            bitRHS->inUse = 0;
          }
        es2s1:;
        } // End of DO block
      // NEXT_SUB=INX; (8551)
      {
        descriptor_t *bitRHS = getBIT (16, mINX);
        putBIT (16, mNEXT_SUB, bitRHS);
        bitRHS->inUse = 0;
      }
      // PSEUDO_LENGTH=0; (8552)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mPSEUDO_LENGTH, bitRHS);
        bitRHS->inUse = 0;
      }
      // I=ATTACH_SUB_STRUCTURE(PSEUDO_LENGTH(INX)); (8553)
      {
        int32_t numberRHS = (int32_t)((
            putBITp (16, mATTACH_SUB_STRUCTURExSUBp,
                     getBIT (16, mPSEUDO_LENGTH + 2 * COREHALFWORD (mINX))),
            ATTACH_SUB_STRUCTURE (0)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mATTACH_SUBSCRIPTxI, bitRHS);
        bitRHS->inUse = 0;
      }
      // J=ATTACH_SUB_ARRAY(VAL_P(INX)); (8554)
      {
        int32_t numberRHS = (int32_t)((
            putBITp (16, mATTACH_SUB_ARRAYxSUBp,
                     getBIT (16, mVAL_P + 2 * COREHALFWORD (mINX))),
            ATTACH_SUB_ARRAY (0)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mATTACH_SUBSCRIPTxJ, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF SYT_CLASS(FIXL(MP))~=VAR_CLASS THEN (8555)
      if (1
          & (xNEQ (BYTE0 (getFIXED (mSYM_TAB)
                          + 34 * (getFIXED (mFIXL + 4 * getFIXED (mMP))) + 30
                          + 1 * (0)),
                   BYTE0 (mVAR_CLASS))))
        // IF SYT_CLASS(FIXL(MP))~=TEMPLATE_CLASS THEN (8556)
        if (1
            & (xNEQ (BYTE0 (getFIXED (mSYM_TAB)
                            + 34 * (getFIXED (mFIXL + 4 * getFIXED (mMP))) + 30
                            + 1 * (0)),
                     BYTE0 (mTEMPLATE_CLASS))))
          // GO TO SS_FUNNIES; (8557)
          goto SS_FUNNIES;
      // IF PSEUDO_TYPE(PTR(MP))<SCALAR_TYPE THEN (8558)
      if (1
          & (xLT (BYTE0 (mPSEUDO_TYPE
                         + 1 * COREHALFWORD (mPTR + 2 * getFIXED (mMP))),
                  5)))
        // DO; (8559)
        {
        rs2s2:;
          // IF I THEN (8560)
          if (1 & (bitToFixed (getBIT (16, mATTACH_SUBSCRIPTxI))))
            // I=ATTACH_SUB_STRUCTURE(0); (8561)
            {
              int32_t numberRHS
                  = (int32_t)((putBITp (16, mATTACH_SUB_STRUCTURExSUBp,
                                        fixedToBit (32, (int32_t)(0))),
                               ATTACH_SUB_STRUCTURE (0)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mATTACH_SUBSCRIPTxI, bitRHS);
              bitRHS->inUse = 0;
            }
          // IF (I~=2) & J & (INX(INX)=0) THEN (8562)
          if (1
              & (xAND (
                  xAND (xNEQ (COREHALFWORD (mATTACH_SUBSCRIPTxI), 2),
                        COREHALFWORD (mATTACH_SUBSCRIPTxJ)),
                  xEQ (COREHALFWORD (mINX + 2 * COREHALFWORD (mINX)), 0))))
            // ESCAPE; (8563)
            goto es2s2;
          // IF J THEN (8564)
          if (1 & (bitToFixed (getBIT (16, mATTACH_SUBSCRIPTxJ))))
            // CALL ATTACH_SUB_ARRAY(0); (8565)
            {
              putBITp (16, mATTACH_SUB_ARRAYxSUBp,
                       fixedToBit (32, (int32_t)(0)));
              ATTACH_SUB_ARRAY (0);
            }
          // CALL ATTACH_SUB_COMPONENT(INX(INX)); (8566)
          {
            putBITp (16, mATTACH_SUB_COMPONENTxSUBp,
                     getBIT (16, mINX + 2 * COREHALFWORD (mINX)));
            ATTACH_SUB_COMPONENT (0);
          }
        es2s2:;
        } // End of DO block
      // ELSE (8567)
      else
        // IF J&(SYT_ARRAY(FIXL(MP))>0) THEN (8568)
        if (1
            & (xAND (COREHALFWORD (mATTACH_SUBSCRIPTxJ),
                     xGT (COREHALFWORD (
                              getFIXED (mSYM_TAB)
                              + 34 * (getFIXED (mFIXL + 4 * getFIXED (mMP)))
                              + 20 + 2 * (0)),
                          0))))
          // DO; (8569)
          {
          rs2s3:;
            // IF I THEN (8570)
            if (1 & (bitToFixed (getBIT (16, mATTACH_SUBSCRIPTxI))))
              // I=ATTACH_SUB_STRUCTURE(0); (8571)
              {
                int32_t numberRHS
                    = (int32_t)((putBITp (16, mATTACH_SUB_STRUCTURExSUBp,
                                          fixedToBit (32, (int32_t)(0))),
                                 ATTACH_SUB_STRUCTURE (0)));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mATTACH_SUBSCRIPTxI, bitRHS);
                bitRHS->inUse = 0;
              }
            // IF (I~=2) & (INX(INX)=0) THEN (8572)
            if (1
                & (xAND (
                    xNEQ (COREHALFWORD (mATTACH_SUBSCRIPTxI), 2),
                    xEQ (COREHALFWORD (mINX + 2 * COREHALFWORD (mINX)), 0))))
              // ESCAPE; (8573)
              goto es2s3;
            // CALL ATTACH_SUB_ARRAY(INX(INX)); (8574)
            {
              putBITp (16, mATTACH_SUB_ARRAYxSUBp,
                       getBIT (16, mINX + 2 * COREHALFWORD (mINX)));
              ATTACH_SUB_ARRAY (0);
            }
          es2s3:;
          } // End of DO block
        // ELSE (8575)
        else
        // SS_FUNNIES: (8576)
        SS_FUNNIES:
          // IF I&(SYT_ARRAY(FIXV(MP))~=0) THEN (8577)
          if (1
              & (xAND (COREHALFWORD (mATTACH_SUBSCRIPTxI),
                       xNEQ (COREHALFWORD (
                                 getFIXED (mSYM_TAB)
                                 + 34 * (getFIXED (mFIXV + 4 * getFIXED (mMP)))
                                 + 20 + 2 * (0)),
                             0))))
            // I=ATTACH_SUB_STRUCTURE(INX(INX)); (8578)
            {
              int32_t numberRHS = (int32_t)((
                  putBITp (16, mATTACH_SUB_STRUCTURExSUBp,
                           getBIT (16, mINX + 2 * COREHALFWORD (mINX))),
                  ATTACH_SUB_STRUCTURE (0)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mATTACH_SUBSCRIPTxI, bitRHS);
              bitRHS->inUse = 0;
            }
          // ELSE (8579)
          else
            // IF INX(INX)>0 THEN (8580)
            if (1 & (xGT (COREHALFWORD (mINX + 2 * COREHALFWORD (mINX)), 0)))
              // CALL ERROR(CLASS_SV,3,VAR(MP)); (8581)
              {
                putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SV));
                putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(3)));
                putCHARACTERp (mERRORxTEXT,
                               getCHARACTER (mVAR + 4 * getFIXED (mMP)));
                ERROR (0);
              }
      // IF VAR_ARRAYNESS>0 THEN (8582)
      if (1 & (xGT (COREHALFWORD (mVAR_ARRAYNESS), 0)))
        // DO; (8583)
        {
        rs2s4:;
          // J=1; (8584)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mATTACH_SUBSCRIPTxJ, bitRHS);
            bitRHS->inUse = 0;
          }
          // DO VAR_ARRAYNESS=1 TO VAR_ARRAYNESS; (8585)
          {
            int32_t from132, to132, by132;
            from132 = 1;
            to132 = bitToFixed (getBIT (16, mVAR_ARRAYNESS));
            by132 = 1;
            for (putBIT (16, mVAR_ARRAYNESS, fixedToBit (16, from132));
                 bitToFixed (getBIT (16, mVAR_ARRAYNESS)) <= to132; putBIT (
                     16, mVAR_ARRAYNESS,
                     fixedToBit (16, bitToFixed (getBIT (16, mVAR_ARRAYNESS))
                                         + by132)))
              {
                // IF VAR_ARRAYNESS(VAR_ARRAYNESS)~=1 THEN (8586)
                if (1
                    & (xNEQ (
                        COREHALFWORD (mVAR_ARRAYNESS
                                      + 2 * COREHALFWORD (mVAR_ARRAYNESS)),
                        1)))
                  // DO; (8587)
                  {
                  rs2s4s1s1:;
                    // VAR_ARRAYNESS(J)=VAR_ARRAYNESS(VAR_ARRAYNESS); (8588)
                    {
                      descriptor_t *bitRHS = getBIT (
                          16,
                          mVAR_ARRAYNESS + 2 * COREHALFWORD (mVAR_ARRAYNESS));
                      putBIT (16,
                              mVAR_ARRAYNESS
                                  + 2 * (COREHALFWORD (mATTACH_SUBSCRIPTxJ)),
                              bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // J=J+1; (8589)
                    {
                      int32_t numberRHS = (int32_t)(xadd (
                          COREHALFWORD (mATTACH_SUBSCRIPTxJ), 1));
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mATTACH_SUBSCRIPTxJ, bitRHS);
                      bitRHS->inUse = 0;
                    }
                  es2s4s1s1:;
                  } // End of DO block
              }
          } // End of DO for-loop block
          // VAR_ARRAYNESS=J-1; (8590)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (COREHALFWORD (mATTACH_SUBSCRIPTxJ), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mVAR_ARRAYNESS, bitRHS);
            bitRHS->inUse = 0;
          }
        es2s4:;
        } // End of DO block
    es2:;
    } // End of DO block
  // ELSE (8591)
  else
    // IF PSEUDO_FORM(INX)>0 THEN (8592)
    if (1 & (xGT (BYTE0 (mPSEUDO_FORM + 1 * COREHALFWORD (mINX)), 0)))
      // DO; (8593)
      {
      rs3:;
        // TEMP=PSEUDO_TYPE(PTR(MP)); (8594)
        {
          descriptor_t *bitRHS = getBIT (
              8, mPSEUDO_TYPE + 1 * COREHALFWORD (mPTR + 2 * getFIXED (mMP)));
          int32_t numberRHS;
          numberRHS = bitToFixed (bitRHS);
          putFIXED (mTEMP, numberRHS);
          bitRHS->inUse = 0;
        }
        // IF TEMP<MAT_TYPE|TEMP>INT_TYPE THEN (8595)
        if (1 & (xOR (xLT (getFIXED (mTEMP), 3), xGT (getFIXED (mTEMP), 6))))
          // DO; (8596)
          {
          rs3s1:;
            // CALL ERROR(CLASS_SQ,1,VAR(MP)); (8597)
            {
              putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SQ));
              putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(1)));
              putCHARACTERp (mERRORxTEXT,
                             getCHARACTER (mVAR + 4 * getFIXED (mMP)));
              ERROR (0);
            }
            // PSEUDO_FORM(INX)=0; (8598)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (8, mPSEUDO_FORM + 1 * (COREHALFWORD (mINX)), bitRHS);
              bitRHS->inUse = 0;
            }
          es3s1:;
          } // End of DO block
      es3:;
      } // End of DO block
  // IF SYT_PTR(FIXL(MP))<0 THEN (8599)
  if (1
      & (xLT (COREHALFWORD (getFIXED (mSYM_TAB)
                            + 34 * (getFIXED (mFIXL + 4 * getFIXED (mMP))) + 22
                            + 2 * (0)),
              0)))
    // IF NAME_BIT=0 THEN (8600)
    if (1 & (xEQ (BYTE0 (mNAME_BIT), 0)))
      // DO; (8601)
      {
      rs4:;
        // LOC_P(PTR(MP))=-SYT_PTR(FIXL(MP)); (8602)
        {
          int32_t numberRHS = (int32_t)(xminus (COREHALFWORD (
              getFIXED (mSYM_TAB)
              + 34 * (getFIXED (mFIXL + 4 * getFIXED (mMP))) + 22 + 2 * (0))));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mLOC_P + 2 * (COREHALFWORD (mPTR + 2 * getFIXED (mMP))),
                  bitRHS);
          bitRHS->inUse = 0;
        }
        // PSEUDO_FORM(PTR(MP))=XLIT; (8603)
        {
          descriptor_t *bitRHS = getBIT (8, mXLIT);
          putBIT (
              8, mPSEUDO_FORM + 1 * (COREHALFWORD (mPTR + 2 * getFIXED (mMP))),
              bitRHS);
          bitRHS->inUse = 0;
        }
      es4:;
      } // End of DO block
  // IF NAME_BIT~=0 THEN (8604)
  if (1 & (xNEQ (BYTE0 (mNAME_BIT), 0)))
    // IF CHECK_ARRAYNESS THEN (8605)
    if (1 & (CHECK_ARRAYNESS (0)))
      // VAL_P(PTR(MP))=VAL_P(PTR(MP))| 16; (8606)
      {
        int32_t numberRHS = (int32_t)(xOR (
            COREHALFWORD (mVAL_P
                          + 2 * COREHALFWORD (mPTR + 2 * getFIXED (mMP))),
            16));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mVAL_P + 2 * (COREHALFWORD (mPTR + 2 * getFIXED (mMP))),
                bitRHS);
        bitRHS->inUse = 0;
      }
  // IF SUBSCRIPT_LEVEL=0 THEN (8607)
  if (1 & (xEQ (COREHALFWORD (mSUBSCRIPT_LEVEL), 0)))
    // ARRAYNESS_FLAG=SAVE_ARRAYNESS_FLAG; (8608)
    {
      descriptor_t *bitRHS = getBIT (8, mSAVE_ARRAYNESS_FLAG);
      putBIT (8, mARRAYNESS_FLAG, bitRHS);
      bitRHS->inUse = 0;
    }
  // CALL MATCH_ARRAYNESS; (8609)
  MATCH_ARRAYNESS (0);
  // IF ARRAYNESS_FLAG THEN (8610)
  if (1 & (bitToFixed (getBIT (8, mARRAYNESS_FLAG))))
    // IF RESET_ARRAYNESS>0 THEN (8611)
    if (1 & (xGT (RESET_ARRAYNESS (0), 0)))
      // CALL ERROR(CLASS_AA,2, VAR(MP)); (8612)
      {
        putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_AA));
        putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(2)));
        putCHARACTERp (mERRORxTEXT, getCHARACTER (mVAR + 4 * getFIXED (mMP)));
        ERROR (0);
      }
  // RETURN I~=2; (8613)
  {
    reentryGuard = 0;
    return xNEQ (COREHALFWORD (mATTACH_SUBSCRIPTxI), 2);
  }
}
