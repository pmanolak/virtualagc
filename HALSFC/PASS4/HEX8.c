/*
  File HEX8.c generated by XCOM-I, 2024-08-09 12:40:27.
*/

#include "runtimeC.h"

descriptor_t *
HEX8 (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "HEX8");
  // T = ''; (660)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "");
    putCHARACTER (mHEX8xT, stringRHS);
    stringRHS->inUse = 0;
  }
  // DO I = 0 TO 7; (661)
  {
    int32_t from17, to17, by17;
    from17 = 0;
    to17 = 7;
    by17 = 1;
    for (putFIXED (mHEX8xI, from17); getFIXED (mHEX8xI) <= to17;
         putFIXED (mHEX8xI, getFIXED (mHEX8xI) + by17))
      {
        // T = T || SUBSTR(HEXCODES, SHR(HVAL, SHL(7-I,2))& 15, 1); (662)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              getCHARACTER (mHEX8xT),
              SUBSTR (getCHARACTER (mHEXCODES),
                      xAND (SHR (getFIXED (mHEX8xHVAL),
                                 SHL (xsubtract (7, getFIXED (mHEX8xI)), 2)),
                            15),
                      1));
          putCHARACTER (mHEX8xT, stringRHS);
          stringRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  // RETURN T; (663)
  {
    reentryGuard = 0;
    return getCHARACTER (mHEX8xT);
  }
}
