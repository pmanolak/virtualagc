/*
  File PASS1xCLASS_0xCLASS_04xGEN_TARGETxTARGET_ERROR.c generated by XCOM-I,
  2024-08-09 12:39:13.
*/

#include "runtimeC.h"

int32_t
PASS1xCLASS_0xCLASS_04xGEN_TARGETxTARGET_ERROR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (
      reentryGuard, "PASS1xCLASS_0xCLASS_04xGEN_TARGETxTARGET_ERROR");
  // CALL ERRORS (CLASS_BI, 409, ' '||RATOR_TYPE); (2366)
  {
    putBITp (16, mERRORSxCLASS, getBIT (16, mCLASS_BI));
    putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(409)));
    putCHARACTERp (
        mERRORSxTEXT,
        xsCAT (
            cToDescriptor (NULL, " "),
            getCHARACTER (
                mPASS1xCLASS_0xCLASS_04xGEN_TARGETxTARGET_ERRORxRATOR_TYPE)));
    ERRORS (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
