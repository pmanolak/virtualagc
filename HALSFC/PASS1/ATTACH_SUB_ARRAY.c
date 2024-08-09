/*
  File ATTACH_SUB_ARRAY.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
ATTACH_SUB_ARRAY (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ATTACH_SUB_ARRAY");
  // IF SUB#<0 THEN (8464)
  if (1 & (xLT (COREHALFWORD (mATTACH_SUB_ARRAYxSUBp), 0)))
    // RETURN TRUE; (8465)
    {
      reentryGuard = 0;
      return 1;
    }
  // I=PTR(MP); (8466)
  {
    descriptor_t *bitRHS = getBIT (16, mPTR + 2 * getFIXED (mMP));
    putBIT (16, mATTACH_SUB_ARRAYxI, bitRHS);
    bitRHS->inUse = 0;
  }
  // INX(INX)=INX(INX)-SUB#; (8467)
  {
    int32_t numberRHS
        = (int32_t)(xsubtract (COREHALFWORD (mINX + 2 * COREHALFWORD (mINX)),
                               COREHALFWORD (mATTACH_SUB_ARRAYxSUBp)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mINX + 2 * (COREHALFWORD (mINX)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IF SYT_ARRAY(FIXL(MP))<=0 THEN (8468)
  if (1
      & (xLE (COREHALFWORD (getFIXED (mSYM_TAB)
                            + 34 * (getFIXED (mFIXL + 4 * getFIXED (mMP))) + 20
                            + 2 * (0)),
              0)))
    // DO; (8469)
    {
    rs1:;
    // ARR_SLIP: (8470)
    ARR_SLIP:
      // IF SUB#>0 THEN (8471)
      if (1 & (xGT (COREHALFWORD (mATTACH_SUB_ARRAYxSUBp), 0)))
        // DO; (8472)
        {
        rs1s1:;
          // CALL ERROR(CLASS_SC,2,VAR(MP)); (8473)
          {
            putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SC));
            putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(2)));
            putCHARACTERp (mERRORxTEXT,
                           getCHARACTER (mVAR + 4 * getFIXED (mMP)));
            ERROR (0);
          }
          // CALL SLIP_SUBSCRIPT(SUB#); (8474)
          {
            putBITp (16, mSLIP_SUBSCRIPTxNUM,
                     getBIT (16, mATTACH_SUB_ARRAYxSUBp));
            SLIP_SUBSCRIPT (0);
          }
        es1s1:;
        } // End of DO block
    es1:;
    } // End of DO block
  // ELSE (8475)
  else
    // DO; (8476)
    {
    rs2:;
      // K=EXT_ARRAY(SYT_ARRAY(FIXL(MP))); (8477)
      {
        descriptor_t *bitRHS = getBIT (
            16, mEXT_ARRAY
                    + 2
                          * COREHALFWORD (
                              getFIXED (mSYM_TAB)
                              + 34 * (getFIXED (mFIXL + 4 * getFIXED (mMP)))
                              + 20 + 2 * (0)));
        putBIT (16, mATTACH_SUB_ARRAYxK, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF SUB#=0 THEN (8478)
      if (1 & (xEQ (COREHALFWORD (mATTACH_SUB_ARRAYxSUBp), 0)))
        // CALL AST_STACKER( 4,K); (8479)
        {
          putBITp (16, mAST_STACKERxMODE, fixedToBit (32, (int32_t)(4)));
          putBITp (16, mAST_STACKERxNUM, getBIT (16, mATTACH_SUB_ARRAYxK));
          AST_STACKER (0);
        }
      // ELSE (8480)
      else
        // IF SUB#<K THEN (8481)
        if (1
            & (xLT (COREHALFWORD (mATTACH_SUB_ARRAYxSUBp),
                    COREHALFWORD (mATTACH_SUB_ARRAYxK))))
          // DO; (8482)
          {
          rs2s1:;
            // CALL ERROR(CLASS_SC,3,VAR(MP)); (8483)
            {
              putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SC));
              putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(3)));
              putCHARACTERp (mERRORxTEXT,
                             getCHARACTER (mVAR + 4 * getFIXED (mMP)));
              ERROR (0);
            }
            // CALL SLIP_SUBSCRIPT(SUB#); (8484)
            {
              putBITp (16, mSLIP_SUBSCRIPTxNUM,
                       getBIT (16, mATTACH_SUB_ARRAYxSUBp));
              SLIP_SUBSCRIPT (0);
            }
          es2s1:;
          } // End of DO block
        // ELSE (8485)
        else
          // DO; (8486)
          {
          rs2s2:;
            // VAL_P(I)=VAL_P(I)| 8; (8487)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  COREHALFWORD (mVAL_P
                                + 2 * COREHALFWORD (mATTACH_SUB_ARRAYxI)),
                  8));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mVAL_P + 2 * (COREHALFWORD (mATTACH_SUB_ARRAYxI)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // SUB#=SUB#-K; (8488)
            {
              int32_t numberRHS
                  = (int32_t)(xsubtract (COREHALFWORD (mATTACH_SUB_ARRAYxSUBp),
                                         COREHALFWORD (mATTACH_SUB_ARRAYxK)));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mATTACH_SUB_ARRAYxSUBp, bitRHS);
              bitRHS->inUse = 0;
            }
            // TEMP=0; (8489)
            {
              int32_t numberRHS = (int32_t)(0);
              putFIXED (mTEMP, numberRHS);
            }
            // DO K=VAR_ARRAYNESS-K+1 TO VAR_ARRAYNESS-SUB#; (8490)
            {
              int32_t from131, to131, by131;
              from131 = xadd (xsubtract (COREHALFWORD (mVAR_ARRAYNESS),
                                         COREHALFWORD (mATTACH_SUB_ARRAYxK)),
                              1);
              to131 = xsubtract (COREHALFWORD (mVAR_ARRAYNESS),
                                 COREHALFWORD (mATTACH_SUB_ARRAYxSUBp));
              by131 = 1;
              for (putBIT (16, mATTACH_SUB_ARRAYxK, fixedToBit (16, from131));
                   bitToFixed (getBIT (16, mATTACH_SUB_ARRAYxK)) <= to131;
                   putBIT (16, mATTACH_SUB_ARRAYxK,
                           fixedToBit (16, bitToFixed (getBIT (
                                               16, mATTACH_SUB_ARRAYxK))
                                               + by131)))
                {
                  // CALL REDUCE_SUBSCRIPT( 4,VAR_ARRAYNESS(K)); (8491)
                  {
                    putBITp (16, mREDUCE_SUBSCRIPTxMODE,
                             fixedToBit (32, (int32_t)(4)));
                    putBITp (
                        16, mREDUCE_SUBSCRIPTxSIZE,
                        getBIT (16,
                                mVAR_ARRAYNESS
                                    + 2 * COREHALFWORD (mATTACH_SUB_ARRAYxK)));
                    REDUCE_SUBSCRIPT (0);
                  }
                  // VAR_ARRAYNESS(K)=FIX_DIM; (8492)
                  {
                    descriptor_t *bitRHS = getBIT (16, mFIX_DIM);
                    putBIT (16,
                            mVAR_ARRAYNESS
                                + 2 * (COREHALFWORD (mATTACH_SUB_ARRAYxK)),
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // TEMP=TEMP|(FIX_DIM~=1); (8493)
                  {
                    int32_t numberRHS = (int32_t)(xOR (
                        getFIXED (mTEMP), xNEQ (COREHALFWORD (mFIX_DIM), 1)));
                    putFIXED (mTEMP, numberRHS);
                  }
                }
            } // End of DO for-loop block
            // IF TEMP=0 THEN (8494)
            if (1 & (xEQ (getFIXED (mTEMP), 0)))
              // VAL_P(I)=VAL_P(I)& 65534; (8495)
              {
                int32_t numberRHS = (int32_t)(xAND (
                    COREHALFWORD (mVAL_P
                                  + 2 * COREHALFWORD (mATTACH_SUB_ARRAYxI)),
                    65534));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mVAL_P + 2 * (COREHALFWORD (mATTACH_SUB_ARRAYxI)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
            // ELSE (8496)
            else
              // VAL_P(I)=VAL_P(I)| 16; (8497)
              {
                int32_t numberRHS = (int32_t)(xOR (
                    COREHALFWORD (mVAL_P
                                  + 2 * COREHALFWORD (mATTACH_SUB_ARRAYxI)),
                    16));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mVAL_P + 2 * (COREHALFWORD (mATTACH_SUB_ARRAYxI)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
            // GO TO ARR_SLIP; (8498)
            goto ARR_SLIP;
          es2s2:;
          } // End of DO block
    es2:;
    } // End of DO block
  // RETURN FALSE; (8499)
  {
    reentryGuard = 0;
    return 0;
  }
}
