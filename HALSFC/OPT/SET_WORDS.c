/*
  File SET_WORDS.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
SET_WORDS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SET_WORDS");
  // IF TRACE THEN (4355)
  if (1 & (bitToFixed (getBIT (8, mTRACE))))
    // DO; (4356)
    {
    rs1:;
      // OUTPUT = 'SET_WORDS:  H_INX '||H_INX||' OPPARITY '||OPPARITY|| '
      // MATCHED_OPS ' ||MATCHED_OPS; (4357)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (xsCAT (xsCAT (xsCAT (cToDescriptor (NULL,
                                                       "SET_WORDS:  H_INX "),
                                        bitToCharacter (getBIT (16, mH_INX))),
                                 cToDescriptor (NULL, " OPPARITY ")),
                          bitToCharacter (getBIT (8, mSET_WORDSxOPPARITY))),
                   cToDescriptor (NULL, " MATCHED_OPS ")),
            bitToCharacter (getBIT (8, mSET_WORDSxMATCHED_OPS)));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = '            TERMINAL# '||TERMINAL#||' TAG '||TAG||' SPECIAL
      // ' ||SPECIAL; (4358)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (xsCAT (xsCAT (xsCAT (cToDescriptor (
                                            NULL, "            TERMINAL# "),
                                        bitToCharacter (getBIT (
                                            16, mSET_WORDSxTERMINALp))),
                                 cToDescriptor (NULL, " TAG ")),
                          bitToCharacter (getBIT (8, mSET_WORDSxTAG))),
                   cToDescriptor (NULL, " SPECIAL ")),
            bitToCharacter (getBIT (8, mSET_WORDSxSPECIAL)));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // H_INX = NEXT_FLAG(H_INX); (4359)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (16, mNEXT_FLAGxPTR, getBIT (16, mH_INX)), NEXT_FLAG (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mH_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL FORM_OPERATOR(H_INX,OPPARITY,TAG); (4360)
  {
    putBITp (16, mFORM_OPERATORxH_INX, getBIT (16, mH_INX));
    putBITp (8, mFORM_OPERATORxPARITY, getBIT (8, mSET_WORDSxOPPARITY));
    putBITp (8, mFORM_OPERATORxTAG, getBIT (8, mSET_WORDSxTAG));
    FORM_OPERATOR (0);
  }
  // IF SPECIAL THEN (4361)
  if (1 & (bitToFixed (getBIT (8, mSET_WORDSxSPECIAL))))
    // DO; (4362)
    {
    rs2:;
      // SAVE_INX = LAST_INX; (4363)
      {
        descriptor_t *bitRHS = getBIT (16, mLAST_INX);
        putBIT (16, mSET_WORDSxSAVE_INX, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF MATCHED_OPS THEN (4364)
      if (1 & (bitToFixed (getBIT (8, mSET_WORDSxMATCHED_OPS))))
        // CALL FORCE_MATCH(H_INX + 1,0); (4365)
        {
          putBITp (
              16, mFORCE_MATCHxPTR,
              fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mH_INX), 1))));
          putBITp (8, mFORCE_MATCHxINVERSE, fixedToBit (32, (int32_t)(0)));
          FORCE_MATCH (0);
        }
      // ELSE (4366)
      else
        // CALL FORCE_TERMINAL(H_INX + 1,0); (4367)
        {
          putBITp (
              16, mFORCE_TERMINALxORIG,
              fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mH_INX), 1))));
          putBITp (8, mFORCE_TERMINALxINVERSE, fixedToBit (32, (int32_t)(0)));
          FORCE_TERMINAL (0);
        }
      // IF TERMINAL# THEN (4368)
      if (1 & (bitToFixed (getBIT (16, mSET_WORDSxTERMINALp))))
        // DO; (4369)
        {
        rs2s1:;
          // IF MATCHED_OPS THEN (4370)
          if (1 & (bitToFixed (getBIT (8, mSET_WORDSxMATCHED_OPS))))
            // CALL FORCE_MATCH(H_INX + 2,1); (4371)
            {
              putBITp (
                  16, mFORCE_MATCHxPTR,
                  fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mH_INX), 2))));
              putBITp (8, mFORCE_MATCHxINVERSE, fixedToBit (32, (int32_t)(1)));
              FORCE_MATCH (0);
            }
          // ELSE (4372)
          else
            // CALL FORCE_TERMINAL(H_INX + 2,1); (4373)
            {
              putBITp (
                  16, mFORCE_TERMINALxORIG,
                  fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mH_INX), 2))));
              putBITp (8, mFORCE_TERMINALxINVERSE,
                       fixedToBit (32, (int32_t)(1)));
              FORCE_TERMINAL (0);
            }
        es2s1:;
        } // End of DO block
      // ELSE (4374)
      else
        // DO; (4375)
        {
        rs2s2:;
          // CALL PUSH_OPERAND(H_INX + 2); (4376)
          {
            putBITp (
                16, mPUSH_OPERANDxORIG,
                fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mH_INX), 2))));
            PUSH_OPERAND (0);
          }
          // CALL SET_VAC_REF(H_INX + 2,SAVE_INX); (4377)
          {
            putBITp (
                16, mSET_VAC_REFxHALMAT_PTR,
                fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mH_INX), 2))));
            putBITp (16, mSET_VAC_REFxPREVIOUS_HALMAT,
                     getBIT (16, mSET_WORDSxSAVE_INX));
            SET_VAC_REF (0);
          }
        es2s2:;
        } // End of DO block
    es2:;
    } // End of DO block
  // ELSE (4378)
  else
    // DO CASE TERMINAL#; (4379)
    {
    rs3:
      switch (COREHALFWORD (mSET_WORDSxTERMINALp))
        {
        case 0:
          // DO; (4381)
          {
          rs3s1:;
            // CALL PUSH_OPERAND(H_INX + 1); (4381)
            {
              putBITp (
                  16, mPUSH_OPERANDxORIG,
                  fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mH_INX), 1))));
              PUSH_OPERAND (0);
            }
            // CALL PUSH_OPERAND(H_INX + 2); (4382)
            {
              putBITp (
                  16, mPUSH_OPERANDxORIG,
                  fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mH_INX), 2))));
              PUSH_OPERAND (0);
            }
            // CALL SET_VAC_REF(H_INX + 1,POINT1); (4383)
            {
              putBITp (
                  16, mSET_VAC_REFxHALMAT_PTR,
                  fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mH_INX), 1))));
              putBITp (16, mSET_VAC_REFxPREVIOUS_HALMAT, getBIT (16, mPOINT1));
              SET_VAC_REF (0);
            }
            // CALL SET_VAC_REF(H_INX + 2,LAST_INX); (4384)
            {
              putBITp (
                  16, mSET_VAC_REFxHALMAT_PTR,
                  fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mH_INX), 2))));
              putBITp (16, mSET_VAC_REFxPREVIOUS_HALMAT,
                       getBIT (16, mLAST_INX));
              SET_VAC_REF (0);
            }
          es3s1:;
          } // End of DO block
          break;
        case 1:
          // DO; (4386)
          {
          rs3s2:;
            // CALL PUSH_OPERAND(H_INX + 1); (4386)
            {
              putBITp (
                  16, mPUSH_OPERANDxORIG,
                  fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mH_INX), 1))));
              PUSH_OPERAND (0);
            }
            // CALL SET_VAC_REF(H_INX + 1,LAST_INX); (4387)
            {
              putBITp (
                  16, mSET_VAC_REFxHALMAT_PTR,
                  fixedToBit (32, (int32_t)(xadd (COREHALFWORD (mH_INX), 1))));
              putBITp (16, mSET_VAC_REFxPREVIOUS_HALMAT,
                       getBIT (16, mLAST_INX));
              SET_VAC_REF (0);
            }
            // IF MATCHED_OPS THEN (4388)
            if (1 & (bitToFixed (getBIT (8, mSET_WORDSxMATCHED_OPS))))
              // CALL FORCE_MATCH(H_INX + 2,INVERSE); (4389)
              {
                putBITp (16, mFORCE_MATCHxPTR,
                         fixedToBit (
                             32, (int32_t)(xadd (COREHALFWORD (mH_INX), 2))));
                putBITp (8, mFORCE_MATCHxINVERSE, getBIT (8, mINVERSE));
                FORCE_MATCH (0);
              }
            // ELSE (4390)
            else
              // CALL FORCE_TERMINAL(H_INX + 2,INVERSE); (4391)
              {
                putBITp (16, mFORCE_TERMINALxORIG,
                         fixedToBit (
                             32, (int32_t)(xadd (COREHALFWORD (mH_INX), 2))));
                putBITp (8, mFORCE_TERMINALxINVERSE, getBIT (8, mINVERSE));
                FORCE_TERMINAL (0);
              }
          es3s2:;
          } // End of DO block
          break;
        case 2:
          // DO; (4393)
          {
          rs3s3:;
            // IF MATCHED_OPS THEN (4393)
            if (1 & (bitToFixed (getBIT (8, mSET_WORDSxMATCHED_OPS))))
              // DO; (4394)
              {
              rs3s3s1:;
                // CALL FORCE_MATCH(H_INX + 1,INVERSE); (4395)
                {
                  putBITp (16, mFORCE_MATCHxPTR,
                           fixedToBit (32, (int32_t)(xadd (
                                               COREHALFWORD (mH_INX), 1))));
                  putBITp (8, mFORCE_MATCHxINVERSE, getBIT (8, mINVERSE));
                  FORCE_MATCH (0);
                }
                // CALL FORCE_MATCH(H_INX + 2,INVERSE); (4396)
                {
                  putBITp (16, mFORCE_MATCHxPTR,
                           fixedToBit (32, (int32_t)(xadd (
                                               COREHALFWORD (mH_INX), 2))));
                  putBITp (8, mFORCE_MATCHxINVERSE, getBIT (8, mINVERSE));
                  FORCE_MATCH (0);
                }
              es3s3s1:;
              } // End of DO block
            // ELSE (4397)
            else
              // DO; (4398)
              {
              rs3s3s2:;
                // CALL FORCE_TERMINAL(H_INX + 1,INVERSE); (4399)
                {
                  putBITp (16, mFORCE_TERMINALxORIG,
                           fixedToBit (32, (int32_t)(xadd (
                                               COREHALFWORD (mH_INX), 1))));
                  putBITp (8, mFORCE_TERMINALxINVERSE, getBIT (8, mINVERSE));
                  FORCE_TERMINAL (0);
                }
                // CALL FORCE_TERMINAL(H_INX + 2,INVERSE); (4400)
                {
                  putBITp (16, mFORCE_TERMINALxORIG,
                           fixedToBit (32, (int32_t)(xadd (
                                               COREHALFWORD (mH_INX), 2))));
                  putBITp (8, mFORCE_TERMINALxINVERSE, getBIT (8, mINVERSE));
                  FORCE_TERMINAL (0);
                }
              es3s3s2:;
              } // End of DO block
          es3s3:;
          } // End of DO block
          break;
        }
    } // End of DO CASE block
  // LAST_INX = H_INX; (4401)
  {
    descriptor_t *bitRHS = getBIT (16, mH_INX);
    putBIT (16, mLAST_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  // FLAG(H_INX), FLAG(H_INX + 1),FLAG(H_INX + 2) = 0; (4402)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mFLAG + 1 * (COREHALFWORD (mH_INX)), bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mFLAG + 1 * (xadd (COREHALFWORD (mH_INX), 1)), bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mFLAG + 1 * (xadd (COREHALFWORD (mH_INX), 2)), bitRHS);
    bitRHS->inUse = 0;
  }
  // TAG,SPECIAL = 0; (4403)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mSET_WORDSxTAG, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mSET_WORDSxSPECIAL, bitRHS);
    bitRHS->inUse = 0;
  }
  // H_INX = H_INX + 3; (4404)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mH_INX), 3));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mH_INX, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
