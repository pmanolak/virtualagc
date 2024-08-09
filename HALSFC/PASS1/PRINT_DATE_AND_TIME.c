/*
  File PRINT_DATE_AND_TIME.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
PRINT_DATE_AND_TIME (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PRINT_DATE_AND_TIME");
  // C = CHARDATE(D); (7013)
  {
    descriptor_t *stringRHS;
    stringRHS = (putFIXED (mCHARDATExD, getFIXED (mPRINT_DATE_AND_TIMExD)),
                 CHARDATE (0));
    putCHARACTER (mPRINT_DATE_AND_TIMExC, stringRHS);
    stringRHS->inUse = 0;
  }
  // CALL PRINT_TIME(MESSAGE || C || '.  CLOCK TIME = ', T); (7014)
  {
    putCHARACTERp (mPRINT_TIMExMESSAGE,
                   xsCAT (xsCAT (getCHARACTER (mPRINT_DATE_AND_TIMExMESSAGE),
                                 getCHARACTER (mPRINT_DATE_AND_TIMExC)),
                          cToDescriptor (NULL, ".  CLOCK TIME = ")));
    putFIXED (mPRINT_TIMExT, getFIXED (mPRINT_DATE_AND_TIMExT));
    PRINT_TIME (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
