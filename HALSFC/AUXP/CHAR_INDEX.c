/*
  File CHAR_INDEX.c generated by XCOM-I, 2024-08-09 12:39:13.
*/

#include "runtimeC.h"

int32_t
CHAR_INDEX (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CHAR_INDEX");
  // L1 = LENGTH(STRING1); (826)
  {
    int32_t numberRHS = (int32_t)(LENGTH (getCHARACTER (mCHAR_INDEXxSTRING1)));
    putFIXED (mCHAR_INDEXxL1, numberRHS);
  }
  // L2 = LENGTH(STRING2); (827)
  {
    int32_t numberRHS = (int32_t)(LENGTH (getCHARACTER (mCHAR_INDEXxSTRING2)));
    putFIXED (mCHAR_INDEXxL2, numberRHS);
  }
  // IF L2 > L1 THEN (828)
  if (1 & (xGT (getFIXED (mCHAR_INDEXxL2), getFIXED (mCHAR_INDEXxL1))))
    // RETURN -1; (829)
    {
      reentryGuard = 0;
      return -1;
    }
  // DO I = 0 TO L1 - L2; (830)
  {
    int32_t from19, to19, by19;
    from19 = 0;
    to19 = xsubtract (getFIXED (mCHAR_INDEXxL1), getFIXED (mCHAR_INDEXxL2));
    by19 = 1;
    for (putFIXED (mCHAR_INDEXxI, from19); getFIXED (mCHAR_INDEXxI) <= to19;
         putFIXED (mCHAR_INDEXxI, getFIXED (mCHAR_INDEXxI) + by19))
      {
        // IF SUBSTR(STRING1, I, L2) = STRING2 THEN (831)
        if (1
            & (xsEQ (SUBSTR (getCHARACTER (mCHAR_INDEXxSTRING1),
                             getFIXED (mCHAR_INDEXxI),
                             getFIXED (mCHAR_INDEXxL2)),
                     getCHARACTER (mCHAR_INDEXxSTRING2))))
          // RETURN I; (832)
          {
            reentryGuard = 0;
            return getFIXED (mCHAR_INDEXxI);
          }
      }
  } // End of DO for-loop block
  // RETURN -1; (833)
  {
    reentryGuard = 0;
    return -1;
  }
}
