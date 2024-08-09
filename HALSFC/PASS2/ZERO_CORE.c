/*
  File ZERO_CORE.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
ZERO_CORE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ZERO_CORE");
  // DO WHILE COUNT ~= 0; (666)
  while (1 & (xNEQ (getFIXED (mZERO_CORExCOUNT), 0)))
    {
      // IF COUNT > 256 THEN (667)
      if (1 & (xGT (getFIXED (mZERO_CORExCOUNT), 256)))
        // #BYTES = 256; (668)
        {
          int32_t numberRHS = (int32_t)(256);
          putFIXED (mZERO_CORExpBYTES, numberRHS);
        }
      // ELSE (669)
      else
        // #BYTES = COUNT; (670)
        {
          int32_t numberRHS = (int32_t)(getFIXED (mZERO_CORExCOUNT));
          putFIXED (mZERO_CORExpBYTES, numberRHS);
        }
      // CALL ZERO_256(CORE_ADDR,#BYTES); (671)
      {
        putFIXED (mZERO_256xCORE_ADDR, getFIXED (mZERO_CORExCORE_ADDR));
        putBITp (16, mZERO_256xCOUNT,
                 fixedToBit (32, (int32_t)(getFIXED (mZERO_CORExpBYTES))));
        ZERO_256 (0);
      }
      // CORE_ADDR = CORE_ADDR + #BYTES; (672)
      {
        int32_t numberRHS = (int32_t)(xadd (getFIXED (mZERO_CORExCORE_ADDR),
                                            getFIXED (mZERO_CORExpBYTES)));
        putFIXED (mZERO_CORExCORE_ADDR, numberRHS);
      }
      // COUNT = COUNT - #BYTES; (673)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            getFIXED (mZERO_CORExCOUNT), getFIXED (mZERO_CORExpBYTES)));
        putFIXED (mZERO_CORExCOUNT, numberRHS);
      }
    } // End of DO WHILE block
  // RETURN; (674)
  {
    reentryGuard = 0;
    return 0;
  }
}
