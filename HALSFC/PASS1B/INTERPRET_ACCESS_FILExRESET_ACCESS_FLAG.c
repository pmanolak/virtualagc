/*
  File INTERPRET_ACCESS_FILExRESET_ACCESS_FLAG.c generated by XCOM-I,
  2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
INTERPRET_ACCESS_FILExRESET_ACCESS_FLAG (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "INTERPRET_ACCESS_FILExRESET_ACCESS_FLAG");
  // J = SYT_FLAGS(I); (2778)
  {
    int32_t numberRHS = (int32_t)(getFIXED (
        getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mINTERPRET_ACCESS_FILExI))
        + 8 + 4 * (0)));
    putFIXED (mINTERPRET_ACCESS_FILExRESET_ACCESS_FLAGxJ, numberRHS);
  }
  // IF (J & ACCESS_FLAG) ~= 0 THEN (2779)
  if (1
      & (xNEQ (
          xAND (getFIXED (mINTERPRET_ACCESS_FILExRESET_ACCESS_FLAGxJ), 65536),
          0)))
    // SYT_FLAGS(I) = J & ACCESS_OFF; (2780)
    {
      int32_t numberRHS = (int32_t)(xAND (
          getFIXED (mINTERPRET_ACCESS_FILExRESET_ACCESS_FLAGxJ),
          getFIXED (mINTERPRET_ACCESS_FILExACCESS_OFF)));
      putFIXED (getFIXED (mSYM_TAB)
                    + 34 * (COREHALFWORD (mINTERPRET_ACCESS_FILExI)) + 8
                    + 4 * (0),
                numberRHS);
    }
  // ELSE (2781)
  else
    // CALL ACCESS_ERROR(3, A_TOKEN); (2782)
    {
      putBITp (16, mINTERPRET_ACCESS_FILExACCESS_ERRORxMSG_NUM,
               fixedToBit (32, (int32_t)(3)));
      putCHARACTERp (mINTERPRET_ACCESS_FILExACCESS_ERRORxNAME,
                     getCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN));
      INTERPRET_ACCESS_FILExACCESS_ERROR (0);
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
