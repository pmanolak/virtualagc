/*
  File EMIT_SUBSCRIPT.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
EMIT_SUBSCRIPT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "EMIT_SUBSCRIPT");
  // J=1; (8614)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mEMIT_SUBSCRIPTxJ, bitRHS);
    bitRHS->inUse = 0;
  }
  // I=PSEUDO_LENGTH; (8615)
  {
    descriptor_t *bitRHS = getBIT (16, mPSEUDO_LENGTH);
    putBIT (16, mEMIT_SUBSCRIPTxI, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE INX(I)>=MODE; (8616)
  while (1
         & (xGE (COREHALFWORD (mINX + 2 * COREHALFWORD (mEMIT_SUBSCRIPTxI)),
                 BYTE0 (mEMIT_SUBSCRIPTxMODE))))
    {
      // IF PSEUDO_TYPE(I)~=0 THEN (8617)
      if (1
          & (xNEQ (BYTE0 (mPSEUDO_TYPE + 1 * COREHALFWORD (mEMIT_SUBSCRIPTxI)),
                   0)))
        // DO; (8618)
        {
        rs1s1:;
          // CALL HALMAT_PIP(SHR(PSEUDO_TYPE(I),4),PSEUDO_TYPE(I)& 15,
          // INX(I),VAL_P(I)); (8619)
          {
            putBITp (
                16, mHALMAT_PIPxOPERAND,
                fixedToBit (32,
                            (int32_t)(SHR (
                                BYTE0 (mPSEUDO_TYPE
                                       + 1 * COREHALFWORD (mEMIT_SUBSCRIPTxI)),
                                4))));
            putBITp (
                8, mHALMAT_PIPxQUAL,
                fixedToBit (32,
                            (int32_t)(xAND (
                                BYTE0 (mPSEUDO_TYPE
                                       + 1 * COREHALFWORD (mEMIT_SUBSCRIPTxI)),
                                15))));
            putBITp (8, mHALMAT_PIPxTAG1,
                     getBIT (16, mINX + 2 * COREHALFWORD (mEMIT_SUBSCRIPTxI)));
            putBITp (
                8, mHALMAT_PIPxTAG2,
                getBIT (16, mVAL_P + 2 * COREHALFWORD (mEMIT_SUBSCRIPTxI)));
            HALMAT_PIP (0);
          }
          // CALL HALMAT_PIP(LOC_P(I),PSEUDO_FORM(I),0,0); (8620)
          {
            putBITp (
                16, mHALMAT_PIPxOPERAND,
                getBIT (16, mLOC_P + 2 * COREHALFWORD (mEMIT_SUBSCRIPTxI)));
            putBITp (8, mHALMAT_PIPxQUAL,
                     getBIT (8, mPSEUDO_FORM
                                    + 1 * COREHALFWORD (mEMIT_SUBSCRIPTxI)));
            putBITp (8, mHALMAT_PIPxTAG1, fixedToBit (32, (int32_t)(0)));
            putBITp (8, mHALMAT_PIPxTAG2, fixedToBit (32, (int32_t)(0)));
            HALMAT_PIP (0);
          }
          // J=J+1; (8621)
          {
            int32_t numberRHS
                = (int32_t)(xadd (COREHALFWORD (mEMIT_SUBSCRIPTxJ), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mEMIT_SUBSCRIPTxJ, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
      // ELSE (8622)
      else
        // CALL HALMAT_PIP(LOC_P(I),PSEUDO_FORM(I),INX(I),VAL_P(I)); (8623)
        {
          putBITp (16, mHALMAT_PIPxOPERAND,
                   getBIT (16, mLOC_P + 2 * COREHALFWORD (mEMIT_SUBSCRIPTxI)));
          putBITp (
              8, mHALMAT_PIPxQUAL,
              getBIT (8, mPSEUDO_FORM + 1 * COREHALFWORD (mEMIT_SUBSCRIPTxI)));
          putBITp (8, mHALMAT_PIPxTAG1,
                   getBIT (16, mINX + 2 * COREHALFWORD (mEMIT_SUBSCRIPTxI)));
          putBITp (8, mHALMAT_PIPxTAG2,
                   getBIT (16, mVAL_P + 2 * COREHALFWORD (mEMIT_SUBSCRIPTxI)));
          HALMAT_PIP (0);
        }
      // J=J+1; (8624)
      {
        int32_t numberRHS
            = (int32_t)(xadd (COREHALFWORD (mEMIT_SUBSCRIPTxJ), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mEMIT_SUBSCRIPTxJ, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF I=IND_LINK THEN (8625)
      if (1
          & (xEQ (COREHALFWORD (mEMIT_SUBSCRIPTxI), COREHALFWORD (mIND_LINK))))
        // DO; (8626)
        {
        rs1s2:;
          // IND_LINK=0; (8627)
          {
            int32_t numberRHS = (int32_t)(0);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mIND_LINK, bitRHS);
            bitRHS->inUse = 0;
          }
          // RETURN J; (8628)
          {
            reentryGuard = 0;
            return COREHALFWORD (mEMIT_SUBSCRIPTxJ);
          }
        es1s2:;
        } // End of DO block
      // I=PSEUDO_LENGTH(I); (8629)
      {
        descriptor_t *bitRHS = getBIT (
            16, mPSEUDO_LENGTH + 2 * COREHALFWORD (mEMIT_SUBSCRIPTxI));
        putBIT (16, mEMIT_SUBSCRIPTxI, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // PSEUDO_LENGTH=I; (8630)
  {
    descriptor_t *bitRHS = getBIT (16, mEMIT_SUBSCRIPTxI);
    putBIT (16, mPSEUDO_LENGTH, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN J; (8631)
  {
    reentryGuard = 0;
    return COREHALFWORD (mEMIT_SUBSCRIPTxJ);
  }
}
