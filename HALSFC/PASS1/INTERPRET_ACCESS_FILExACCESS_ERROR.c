/*
  File INTERPRET_ACCESS_FILExACCESS_ERROR.c generated by XCOM-I, 2024-08-09
  12:38:15.
*/

#include "runtimeC.h"

int32_t
INTERPRET_ACCESS_FILExACCESS_ERROR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "INTERPRET_ACCESS_FILExACCESS_ERROR");
  // IF ~MSG_ISSUED THEN (2767)
  if (1 & (xNOT (BYTE0 (mINTERPRET_ACCESS_FILExACCESS_ERRORxMSG_ISSUED))))
    // DO; (2768)
    {
    rs1:;
      // MSG_ISSUED = TRUE; (2769)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mINTERPRET_ACCESS_FILExACCESS_ERRORxMSG_ISSUED, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL ERROR(CLASS_PA, 2, PROGRAM_ID); (2770)
      {
        putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_PA));
        putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(2)));
        putCHARACTERp (mERRORxTEXT, getCHARACTER (mPROGRAM_ID));
        ERROR (0);
      }
      // CALL OUTPUT_WRITER; (2771)
      OUTPUT_WRITER (0);
    es1:;
    } // End of DO block
  // IF MSG_NUM = 0 THEN (2772)
  if (1
      & (xEQ (COREHALFWORD (mINTERPRET_ACCESS_FILExACCESS_ERRORxMSG_NUM), 0)))
    // DO; (2773)
    {
    rs2:;
      // OUTPUT = X8 || ACCESS_MSG; (2774)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            getCHARACTER (mX8),
            getCHARACTER (mINTERPRET_ACCESS_FILExACCESS_ERRORxACCESS_MSG));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = S; (2775)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mINTERPRET_ACCESS_FILExS);
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // ELSE (2776)
  else
    // OUTPUT = X8 || NAME || ACCESS_MSG(MSG_NUM); (2777)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          xsCAT (getCHARACTER (mX8),
                 getCHARACTER (mINTERPRET_ACCESS_FILExACCESS_ERRORxNAME)),
          getCHARACTER (
              mINTERPRET_ACCESS_FILExACCESS_ERRORxACCESS_MSG
              + 4
                    * COREHALFWORD (
                        mINTERPRET_ACCESS_FILExACCESS_ERRORxMSG_NUM)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
