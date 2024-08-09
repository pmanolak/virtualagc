/*
  File HEX1.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

descriptor_t *
HEX1 (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "HEX1");
  // STRING = ''; (802)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "");
    putCHARACTER (mHEX1xSTRING, stringRHS);
    stringRHS->inUse = 0;
  }
// H_LOOP: (803)
H_LOOP:
  // STRING=SUBSTR(HEXCODES,HVAL& 15,1)||STRING; (804)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (SUBSTR (getCHARACTER (mHEX1xHEXCODES),
                               xAND (getFIXED (mHEX1xHVAL), 15), 1),
                       getCHARACTER (mHEX1xSTRING));
    putCHARACTER (mHEX1xSTRING, stringRHS);
    stringRHS->inUse = 0;
  }
  // HVAL=SHR(HVAL,4); (805)
  {
    int32_t numberRHS = (int32_t)(SHR (getFIXED (mHEX1xHVAL), 4));
    putFIXED (mHEX1xHVAL, numberRHS);
  }
  // IF HVAL ~= 0 THEN (806)
  if (1 & (xNEQ (getFIXED (mHEX1xHVAL), 0)))
    // GO TO H_LOOP; (807)
    goto H_LOOP;
  // IF LENGTH(STRING) >= N THEN (808)
  if (1 & (xGE (LENGTH (getCHARACTER (mHEX1xSTRING)), getFIXED (mHEX1xN))))
    // RETURN STRING; (809)
    {
      reentryGuard = 0;
      return getCHARACTER (mHEX1xSTRING);
    }
  // RETURN SUBSTR(ZEROS,0,N-LENGTH(STRING))||STRING; (810)
  {
    reentryGuard = 0;
    return xsCAT (SUBSTR (getCHARACTER (mHEX1xZEROS), 0,
                          xsubtract (getFIXED (mHEX1xN),
                                     LENGTH (getCHARACTER (mHEX1xSTRING)))),
                  getCHARACTER (mHEX1xSTRING));
  }
}
