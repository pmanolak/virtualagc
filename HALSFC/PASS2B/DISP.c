/*
  File DISP.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
DISP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "DISP");
  // TEMP = VMEM_PAD_DISP(VMEM_OLD_NDX); (673)
  {
    descriptor_t *bitRHS
        = getBIT (16, mVMEM_PAD_DISP + 2 * COREHALFWORD (mVMEM_OLD_NDX));
    putBIT (16, mDISPxTEMP, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF (FLAGS&MODF) ~= 0 THEN (674)
  if (1 & (xNEQ (xAND (BYTE0 (mDISPxFLAGS), BYTE0 (mMODF)), 0)))
    // TEMP = TEMP| 16384; (675)
    {
      int32_t numberRHS = (int32_t)(xOR (COREHALFWORD (mDISPxTEMP), 16384));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mDISPxTEMP, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF (FLAGS&RESV) ~= 0 THEN (676)
  if (1 & (xNEQ (xAND (BYTE0 (mDISPxFLAGS), BYTE0 (mRESV)), 0)))
    // DO; (677)
    {
    rs1:;
      // TEMP = TEMP + 1; (678)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mDISPxTEMP), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mDISPxTEMP, bitRHS);
        bitRHS->inUse = 0;
      }
      // VMEM_RESV_CNT = VMEM_RESV_CNT + 1; (679)
      {
        int32_t numberRHS = (int32_t)(xadd (getFIXED (mVMEM_RESV_CNT), 1));
        putFIXED (mVMEM_RESV_CNT, numberRHS);
      }
    es1:;
    } // End of DO block
  // ELSE (680)
  else
    // IF (FLAGS&RELS) ~= 0 THEN (681)
    if (1 & (xNEQ (xAND (BYTE0 (mDISPxFLAGS), BYTE0 (mRELS)), 0)))
      // DO; (682)
      {
      rs2:;
        // TEMP = TEMP - 1; (683)
        {
          int32_t numberRHS
              = (int32_t)(xsubtract (COREHALFWORD (mDISPxTEMP), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mDISPxTEMP, bitRHS);
          bitRHS->inUse = 0;
        }
        // VMEM_RESV_CNT = VMEM_RESV_CNT - 1; (684)
        {
          int32_t numberRHS
              = (int32_t)(xsubtract (getFIXED (mVMEM_RESV_CNT), 1));
          putFIXED (mVMEM_RESV_CNT, numberRHS);
        }
      es2:;
      } // End of DO block
  // VMEM_PAD_DISP(VMEM_OLD_NDX) = TEMP; (685)
  {
    descriptor_t *bitRHS = getBIT (16, mDISPxTEMP);
    putBIT (16, mVMEM_PAD_DISP + 2 * (COREHALFWORD (mVMEM_OLD_NDX)), bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
