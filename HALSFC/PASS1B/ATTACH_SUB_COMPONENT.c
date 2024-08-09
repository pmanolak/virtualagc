/*
  File ATTACH_SUB_COMPONENT.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
ATTACH_SUB_COMPONENT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ATTACH_SUB_COMPONENT");
  // I=PTR(MP); (8413)
  {
    descriptor_t *bitRHS = getBIT (16, mPTR + 2 * getFIXED (mMP));
    putBIT (16, mATTACH_SUB_COMPONENTxI, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF SUB#>0 THEN (8414)
  if (1 & (xGT (COREHALFWORD (mATTACH_SUB_COMPONENTxSUBp), 0)))
    // DO CASE PSEUDO_TYPE(I); (8415)
    {
    rs1:
      switch (
          BYTE0 (mPSEUDO_TYPE + 1 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)))
        {
        case 0:
            // ; (8417)
            ;
          break;
        case 1:
          // DO; (8418)
          {
          rs1s1:;
            // CALL REDUCE_SUBSCRIPT( 0,PSEUDO_LENGTH(I)); (8418)
            {
              putBITp (16, mREDUCE_SUBSCRIPTxMODE,
                       fixedToBit (32, (int32_t)(0)));
              putBITp (
                  16, mREDUCE_SUBSCRIPTxSIZE,
                  getBIT (16,
                          mPSEUDO_LENGTH
                              + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)));
              REDUCE_SUBSCRIPT (0);
            }
            // PSEUDO_LENGTH(I)=FIX_DIM; (8419)
            {
              descriptor_t *bitRHS = getBIT (16, mFIX_DIM);
              putBIT (16,
                      mPSEUDO_LENGTH
                          + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
          // FIXING_BIT_AND_CHAR: (8420)
          FIXING_BIT_AND_CHAR:
            // VAL_P(I)=VAL_P(I)| 16; (8421)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  COREHALFWORD (mVAL_P
                                + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                  16));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16,
                      mVAL_P + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // SUB#=SUB#-1; (8422)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  COREHALFWORD (mATTACH_SUB_COMPONENTxSUBp), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mATTACH_SUB_COMPONENTxSUBp, bitRHS);
              bitRHS->inUse = 0;
            }
            // IF INX(NEXT_SUB)=0 & ~VAL_P(I) THEN (8423)
            if (1
                & (xAND (
                    xEQ (COREHALFWORD (mINX + 2 * COREHALFWORD (mNEXT_SUB)),
                         0),
                    xNOT (COREHALFWORD (
                        mVAL_P
                        + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI))))))
              // VAL_P(I)=VAL_P(I)& 65519; (8424)
              {
                int32_t numberRHS = (int32_t)(xAND (
                    COREHALFWORD (
                        mVAL_P + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                    65519));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16,
                        mVAL_P + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
          // COMP_SLIP: (8425)
          COMP_SLIP:
            // VAL_P(I)=VAL_P(I)| 8; (8426)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  COREHALFWORD (mVAL_P
                                + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                  8));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16,
                      mVAL_P + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // IF SUB#>0 THEN (8427)
            if (1 & (xGT (COREHALFWORD (mATTACH_SUB_COMPONENTxSUBp), 0)))
              // DO; (8428)
              {
              rs1s1s1:;
                // CALL ERROR(CLASS_SC,4,VAR(MP)); (8429)
                {
                  putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SC));
                  putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(4)));
                  putCHARACTERp (mERRORxTEXT,
                                 getCHARACTER (mVAR + 4 * getFIXED (mMP)));
                  ERROR (0);
                }
                // CALL SLIP_SUBSCRIPT(SUB#); (8430)
                {
                  putBITp (16, mSLIP_SUBSCRIPTxNUM,
                           getBIT (16, mATTACH_SUB_COMPONENTxSUBp));
                  SLIP_SUBSCRIPT (0);
                }
              es1s1s1:;
              } // End of DO block
          es1s1:;
          } // End of DO block
          break;
        case 2:
          // DO; (8432)
          {
          rs1s2:;
            // CALL REDUCE_SUBSCRIPT( 0,PSEUDO_LENGTH(I),1); (8432)
            {
              putBITp (16, mREDUCE_SUBSCRIPTxMODE,
                       fixedToBit (32, (int32_t)(0)));
              putBITp (
                  16, mREDUCE_SUBSCRIPTxSIZE,
                  getBIT (16,
                          mPSEUDO_LENGTH
                              + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)));
              putBITp (1, mREDUCE_SUBSCRIPTxFLAG,
                       fixedToBit (32, (int32_t)(1)));
              REDUCE_SUBSCRIPT (0);
            }
            // GO TO FIXING_BIT_AND_CHAR; (8433)
            goto FIXING_BIT_AND_CHAR;
          es1s2:;
          } // End of DO block
          break;
        case 3:
          // DO; (8435)
          {
          rs1s3:;
            // IF SUB#=1 THEN (8435)
            if (1 & (xEQ (COREHALFWORD (mATTACH_SUB_COMPONENTxSUBp), 1)))
              // DO; (8436)
              {
              rs1s3s1:;
                // CALL ERROR(CLASS_SC,5,VAR(MP)); (8437)
                {
                  putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SC));
                  putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(5)));
                  putCHARACTERp (mERRORxTEXT,
                                 getCHARACTER (mVAR + 4 * getFIXED (mMP)));
                  ERROR (0);
                }
                // CALL SLIP_SUBSCRIPT(SUB#); (8438)
                {
                  putBITp (16, mSLIP_SUBSCRIPTxNUM,
                           getBIT (16, mATTACH_SUB_COMPONENTxSUBp));
                  SLIP_SUBSCRIPT (0);
                }
              es1s3s1:;
              } // End of DO block
            // ELSE (8439)
            else
              // DO; (8440)
              {
              rs1s3s2:;
                // CALL REDUCE_SUBSCRIPT( 0,SHR(PSEUDO_LENGTH(I),8),2); (8441)
                {
                  putBITp (16, mREDUCE_SUBSCRIPTxMODE,
                           fixedToBit (32, (int32_t)(0)));
                  putBITp (16, mREDUCE_SUBSCRIPTxSIZE,
                           fixedToBit (
                               32, (int32_t)(SHR (
                                       COREHALFWORD (
                                           mPSEUDO_LENGTH
                                           + 2
                                                 * COREHALFWORD (
                                                     mATTACH_SUB_COMPONENTxI)),
                                       8))));
                  putBITp (1, mREDUCE_SUBSCRIPTxFLAG,
                           fixedToBit (32, (int32_t)(2)));
                  REDUCE_SUBSCRIPT (0);
                }
                // T1=FIX_DIM; (8442)
                {
                  descriptor_t *bitRHS = getBIT (16, mFIX_DIM);
                  putBIT (16, mATTACH_SUB_COMPONENTxT1, bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL REDUCE_SUBSCRIPT( 0,PSEUDO_LENGTH(I)& 255,2); (8443)
                {
                  putBITp (16, mREDUCE_SUBSCRIPTxMODE,
                           fixedToBit (32, (int32_t)(0)));
                  putBITp (16, mREDUCE_SUBSCRIPTxSIZE,
                           fixedToBit (
                               32, (int32_t)(xAND (
                                       COREHALFWORD (
                                           mPSEUDO_LENGTH
                                           + 2
                                                 * COREHALFWORD (
                                                     mATTACH_SUB_COMPONENTxI)),
                                       255))));
                  putBITp (1, mREDUCE_SUBSCRIPTxFLAG,
                           fixedToBit (32, (int32_t)(2)));
                  REDUCE_SUBSCRIPT (0);
                }
                // IF T1=1&FIX_DIM=1 THEN (8444)
                if (1
                    & (xAND (xEQ (COREHALFWORD (mATTACH_SUB_COMPONENTxT1), 1),
                             xEQ (COREHALFWORD (mFIX_DIM), 1))))
                  // DO; (8445)
                  {
                  rs1s3s2s1:;
                    // PSEUDO_TYPE(I) = SCALAR_TYPE; (8446)
                    {
                      int32_t numberRHS = (int32_t)(5);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (
                          8,
                          mPSEUDO_TYPE
                              + 1 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                          bitRHS);
                      bitRHS->inUse = 0;
                    }
                    // PSEUDO_LENGTH(I) = 0; (8447)
                    {
                      int32_t numberRHS = (int32_t)(0);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (
                          16,
                          mPSEUDO_LENGTH
                              + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                          bitRHS);
                      bitRHS->inUse = 0;
                    }
                  es1s3s2s1:;
                  } // End of DO block
                // ELSE (8448)
                else
                  // IF T1=1|FIX_DIM=1 THEN (8449)
                  if (1
                      & (xOR (xEQ (COREHALFWORD (mATTACH_SUB_COMPONENTxT1), 1),
                              xEQ (COREHALFWORD (mFIX_DIM), 1))))
                    // DO; (8450)
                    {
                    rs1s3s2s2:;
                      // PSEUDO_TYPE(I)=VEC_TYPE; (8451)
                      {
                        int32_t numberRHS = (int32_t)(4);
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (
                            8,
                            mPSEUDO_TYPE
                                + 1 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                            bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // PSEUDO_LENGTH(I)=T1+FIX_DIM-1; (8452)
                      {
                        int32_t numberRHS = (int32_t)(xsubtract (
                            xadd (COREHALFWORD (mATTACH_SUB_COMPONENTxT1),
                                  COREHALFWORD (mFIX_DIM)),
                            1));
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (
                            16,
                            mPSEUDO_LENGTH
                                + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                            bitRHS);
                        bitRHS->inUse = 0;
                      }
                    es1s3s2s2:;
                    } // End of DO block
                  // ELSE (8453)
                  else
                    // PSEUDO_LENGTH(I)=SHL(T1,8)|FIX_DIM; (8454)
                    {
                      int32_t numberRHS = (int32_t)(xOR (
                          SHL (COREHALFWORD (mATTACH_SUB_COMPONENTxT1), 8),
                          COREHALFWORD (mFIX_DIM)));
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (
                          16,
                          mPSEUDO_LENGTH
                              + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                          bitRHS);
                      bitRHS->inUse = 0;
                    }
                // IF PSEUDO_TYPE(I)~=SCALAR_TYPE THEN (8455)
                if (1
                    & (xNEQ (
                        BYTE0 (mPSEUDO_TYPE
                               + 1 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                        5)))
                  // VAL_P(I)=VAL_P(I)| 16; (8456)
                  {
                    int32_t numberRHS = (int32_t)(xOR (
                        COREHALFWORD (
                            mVAL_P
                            + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                        16));
                    descriptor_t *bitRHS;
                    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                    putBIT (16,
                            mVAL_P
                                + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                // SUB#=SUB#-2; (8457)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      COREHALFWORD (mATTACH_SUB_COMPONENTxSUBp), 2));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mATTACH_SUB_COMPONENTxSUBp, bitRHS);
                  bitRHS->inUse = 0;
                }
                // GO TO COMP_SLIP; (8458)
                goto COMP_SLIP;
              es1s3s2:;
              } // End of DO block
          es1s3:;
          } // End of DO block
          break;
        case 4:
          // DO; (8460)
          {
          rs1s4:;
            // CALL REDUCE_SUBSCRIPT( 0,PSEUDO_LENGTH(I),2); (8460)
            {
              putBITp (16, mREDUCE_SUBSCRIPTxMODE,
                       fixedToBit (32, (int32_t)(0)));
              putBITp (
                  16, mREDUCE_SUBSCRIPTxSIZE,
                  getBIT (16,
                          mPSEUDO_LENGTH
                              + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)));
              putBITp (1, mREDUCE_SUBSCRIPTxFLAG,
                       fixedToBit (32, (int32_t)(2)));
              REDUCE_SUBSCRIPT (0);
            }
            // PSEUDO_LENGTH(I)=FIX_DIM; (8461)
            {
              descriptor_t *bitRHS = getBIT (16, mFIX_DIM);
              putBIT (16,
                      mPSEUDO_LENGTH
                          + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // IF FIX_DIM = 1 THEN (8462)
            if (1 & (xEQ (COREHALFWORD (mFIX_DIM), 1)))
              // DO; (8463)
              {
              rs1s4s1:;
                // PSEUDO_TYPE(I) = SCALAR_TYPE; (8464)
                {
                  int32_t numberRHS = (int32_t)(5);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (8,
                          mPSEUDO_TYPE
                              + 1 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
                // PSEUDO_LENGTH(I) = 0; (8465)
                {
                  int32_t numberRHS = (int32_t)(0);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16,
                          mPSEUDO_LENGTH
                              + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
              es1s4s1:;
              } // End of DO block
            // ELSE (8466)
            else
              // VAL_P(I)=VAL_P(I)| 16; (8467)
              {
                int32_t numberRHS = (int32_t)(xOR (
                    COREHALFWORD (
                        mVAL_P + 2 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                    16));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16,
                        mVAL_P + 2 * (COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
            // SUB#=SUB#-1; (8468)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  COREHALFWORD (mATTACH_SUB_COMPONENTxSUBp), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mATTACH_SUB_COMPONENTxSUBp, bitRHS);
              bitRHS->inUse = 0;
            }
            // GO TO COMP_SLIP; (8469)
            goto COMP_SLIP;
          es1s4:;
          } // End of DO block
          break;
        }
    } // End of DO CASE block
  // ELSE (8470)
  else
    // DO; (8471)
    {
    rs2:;
      // IF PSEUDO_TYPE(I)=MAT_TYPE THEN (8472)
      if (1
          & (xEQ (BYTE0 (mPSEUDO_TYPE
                         + 1 * COREHALFWORD (mATTACH_SUB_COMPONENTxI)),
                  3)))
        // SUB#=2; (8473)
        {
          int32_t numberRHS = (int32_t)(2);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mATTACH_SUB_COMPONENTxSUBp, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (8474)
      else
        // SUB#=1; (8475)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mATTACH_SUB_COMPONENTxSUBp, bitRHS);
          bitRHS->inUse = 0;
        }
      // CALL AST_STACKER( 0,SUB#); (8476)
      {
        putBITp (16, mAST_STACKERxMODE, fixedToBit (32, (int32_t)(0)));
        putBITp (16, mAST_STACKERxNUM,
                 getBIT (16, mATTACH_SUB_COMPONENTxSUBp));
        AST_STACKER (0);
      }
    es2:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
