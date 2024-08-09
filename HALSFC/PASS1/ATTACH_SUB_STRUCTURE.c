/*
  File ATTACH_SUB_STRUCTURE.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
ATTACH_SUB_STRUCTURE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ATTACH_SUB_STRUCTURE");
  // IF SUB#<0 THEN (8500)
  if (1 & (xLT (COREHALFWORD (mATTACH_SUB_STRUCTURExSUBp), 0)))
    // RETURN TRUE; (8501)
    {
      reentryGuard = 0;
      return 1;
    }
  // RCODE=FALSE; (8502)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mATTACH_SUB_STRUCTURExRCODE, bitRHS);
    bitRHS->inUse = 0;
  }
  // INX(INX)=INX(INX)-SUB#; (8503)
  {
    int32_t numberRHS
        = (int32_t)(xsubtract (COREHALFWORD (mINX + 2 * COREHALFWORD (mINX)),
                               COREHALFWORD (mATTACH_SUB_STRUCTURExSUBp)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mINX + 2 * (COREHALFWORD (mINX)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IF SYT_ARRAY(FIXV(MP))=0 THEN (8504)
  if (1
      & (xEQ (COREHALFWORD (getFIXED (mSYM_TAB)
                            + 34 * (getFIXED (mFIXV + 4 * getFIXED (mMP))) + 20
                            + 2 * (0)),
              0)))
    // DO; (8505)
    {
    rs1:;
      // RCODE=2; (8506)
      {
        int32_t numberRHS = (int32_t)(2);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mATTACH_SUB_STRUCTURExRCODE, bitRHS);
        bitRHS->inUse = 0;
      }
    // STRUC_SLIP: (8507)
    STRUC_SLIP:
      // IF SUB#>0 THEN (8508)
      if (1 & (xGT (COREHALFWORD (mATTACH_SUB_STRUCTURExSUBp), 0)))
        // DO; (8509)
        {
        rs1s1:;
          // CALL ERROR(CLASS_SC,1,VAR(MP)); (8510)
          {
            putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_SC));
            putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(1)));
            putCHARACTERp (mERRORxTEXT,
                           getCHARACTER (mVAR + 4 * getFIXED (mMP)));
            ERROR (0);
          }
          // CALL SLIP_SUBSCRIPT(SUB#); (8511)
          {
            putBITp (16, mSLIP_SUBSCRIPTxNUM,
                     getBIT (16, mATTACH_SUB_STRUCTURExSUBp));
            SLIP_SUBSCRIPT (0);
          }
        es1s1:;
        } // End of DO block
    es1:;
    } // End of DO block
  // ELSE (8512)
  else
    // IF SUB#=0 THEN (8513)
    if (1 & (xEQ (COREHALFWORD (mATTACH_SUB_STRUCTURExSUBp), 0)))
      // CALL AST_STACKER( 8,1); (8514)
      {
        putBITp (16, mAST_STACKERxMODE, fixedToBit (32, (int32_t)(8)));
        putBITp (16, mAST_STACKERxNUM, fixedToBit (32, (int32_t)(1)));
        AST_STACKER (0);
      }
    // ELSE (8515)
    else
      // DO; (8516)
      {
      rs2:;
        // CALL REDUCE_SUBSCRIPT( 8,VAR_ARRAYNESS(1)); (8517)
        {
          putBITp (16, mREDUCE_SUBSCRIPTxMODE, fixedToBit (32, (int32_t)(8)));
          putBITp (16, mREDUCE_SUBSCRIPTxSIZE,
                   getBIT (16, mVAR_ARRAYNESS + 2 * 1));
          REDUCE_SUBSCRIPT (0);
        }
        // VAR_ARRAYNESS(1)=FIX_DIM; (8518)
        {
          descriptor_t *bitRHS = getBIT (16, mFIX_DIM);
          putBIT (16, mVAR_ARRAYNESS + 2 * (1), bitRHS);
          bitRHS->inUse = 0;
        }
        // IF FIX_DIM=1 THEN (8519)
        if (1 & (xEQ (COREHALFWORD (mFIX_DIM), 1)))
          // VAL_P(PTR(MP))=VAL_P(PTR(MP))& 65533; (8520)
          {
            int32_t numberRHS = (int32_t)(xAND (
                COREHALFWORD (mVAL_P
                              + 2 * COREHALFWORD (mPTR + 2 * getFIXED (mMP))),
                65533));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16,
                    mVAL_P + 2 * (COREHALFWORD (mPTR + 2 * getFIXED (mMP))),
                    bitRHS);
            bitRHS->inUse = 0;
          }
        // SUB#=SUB#-1; (8521)
        {
          int32_t numberRHS = (int32_t)(xsubtract (
              COREHALFWORD (mATTACH_SUB_STRUCTURExSUBp), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mATTACH_SUB_STRUCTURExSUBp, bitRHS);
          bitRHS->inUse = 0;
        }
        // GO TO STRUC_SLIP; (8522)
        goto STRUC_SLIP;
      es2:;
      } // End of DO block
  // RETURN RCODE; (8523)
  {
    reentryGuard = 0;
    return BYTE0 (mATTACH_SUB_STRUCTURExRCODE);
  }
}
