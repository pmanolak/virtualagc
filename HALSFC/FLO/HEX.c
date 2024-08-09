/*
  File HEX.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

descriptor_t *
HEX (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "HEX");
  // STRING = ''; (1050)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "");
    putCHARACTER (mHEXxSTRING, stringRHS);
    stringRHS->inUse = 0;
  }
// H_LOOP: (1051)
H_LOOP:
  // STRING = SUBSTR(HEXCODES, HVAL& 15, 1)|| STRING; (1052)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (SUBSTR (getCHARACTER (mHEXxHEXCODES),
                               xAND (getFIXED (mHEXxHVAL), 15), 1),
                       getCHARACTER (mHEXxSTRING));
    putCHARACTER (mHEXxSTRING, stringRHS);
    stringRHS->inUse = 0;
  }
  // HVAL = SHR(HVAL, 4); (1053)
  {
    int32_t numberRHS = (int32_t)(SHR (getFIXED (mHEXxHVAL), 4));
    putFIXED (mHEXxHVAL, numberRHS);
  }
  // IF HVAL ~= 0 THEN (1054)
  if (1 & (xNEQ (getFIXED (mHEXxHVAL), 0)))
    // GO TO H_LOOP; (1055)
    goto H_LOOP;
  // IF LENGTH(STRING) >= N THEN (1056)
  if (1 & (xGE (LENGTH (getCHARACTER (mHEXxSTRING)), getFIXED (mHEXxN))))
    // RETURN STRING; (1057)
    {
      reentryGuard = 0;
      return getCHARACTER (mHEXxSTRING);
    }
  // RETURN SUBSTR(ZEROS, 0, N-LENGTH(STRING)) || STRING; (1058)
  {
    reentryGuard = 0;
    return xsCAT (SUBSTR (getCHARACTER (mHEXxZEROS), 0,
                          xsubtract (getFIXED (mHEXxN),
                                     LENGTH (getCHARACTER (mHEXxSTRING)))),
                  getCHARACTER (mHEXxSTRING));
  }
}
