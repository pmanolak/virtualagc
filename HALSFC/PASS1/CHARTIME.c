/*
  File CHARTIME.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

descriptor_t *
CHARTIME (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CHARTIME");
  // C = T /360000; (6996)
  {
    int32_t numberRHS = (int32_t)(xdivide (getFIXED (mCHARTIMExT), 360000));
    descriptor_t *stringRHS;
    stringRHS = fixedToCharacter (numberRHS);
    putCHARACTER (mCHARTIMExC, stringRHS);
    stringRHS->inUse = 0;
  }
  // C = C || COLON || T MOD 360000 / 6000 || COLON || T MOD 6000 /100 ||
  // PERIOD; (6997)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (
        xsCAT (
            xsCAT (xsCAT (xsCAT (getCHARACTER (mCHARTIMExC),
                                 getCHARACTER (mCHARTIMExCOLON)),
                          fixedToCharacter (xdivide (
                              xmod (getFIXED (mCHARTIMExT), 360000), 6000))),
                   getCHARACTER (mCHARTIMExCOLON)),
            fixedToCharacter (
                xdivide (xmod (getFIXED (mCHARTIMExT), 6000), 100))),
        getCHARACTER (mPERIOD));
    putCHARACTER (mCHARTIMExC, stringRHS);
    stringRHS->inUse = 0;
  }
  // T = T MOD 100; (6998)
  {
    int32_t numberRHS = (int32_t)(xmod (getFIXED (mCHARTIMExT), 100));
    putFIXED (mCHARTIMExT, numberRHS);
  }
  // IF T < 10 THEN (6999)
  if (1 & (xLT (getFIXED (mCHARTIMExT), 10)))
    // C = C || '0'; (7000)
    {
      descriptor_t *stringRHS;
      stringRHS
          = xsCAT (getCHARACTER (mCHARTIMExC), cToDescriptor (NULL, "0"));
      putCHARACTER (mCHARTIMExC, stringRHS);
      stringRHS->inUse = 0;
    }
  // RETURN C || T; (7001)
  {
    reentryGuard = 0;
    return xsCAT (getCHARACTER (mCHARTIMExC),
                  fixedToCharacter (getFIXED (mCHARTIMExT)));
  }
}
