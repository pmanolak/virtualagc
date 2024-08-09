/*
  File STREAMxPROCESS_COMMENTxCOPY_TO_8.c generated by XCOM-I, 2024-08-09
  12:38:15.
*/

#include "runtimeC.h"

int32_t
STREAMxPROCESS_COMMENTxCOPY_TO_8 (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "STREAMxPROCESS_COMMENTxCOPY_TO_8");
  // CALL PRINT_COMMENT(LIST_FLAG); (4459)
  {
    putBITp (1, mSTREAMxPRINT_COMMENTxPRINT,
             getBIT (1, mSTREAMxPROCESS_COMMENTxLIST_FLAG));
    STREAMxPRINT_COMMENT (0);
  }
  // OUTPUT(8) = CURRENT_CARD; (4460)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mCURRENT_CARD);
    OUTPUT (8, stringRHS);
    stringRHS->inUse = 0;
  }
  // RECORD_NOT_WRITTEN = FALSE; (4461)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mSTREAMxPROCESS_COMMENTxRECORD_NOT_WRITTEN, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL MONITOR(16, 16); (4462)
  MONITOR16 (16);
  {
    reentryGuard = 0;
    return 0;
  }
}
