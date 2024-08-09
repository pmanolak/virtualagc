/*
  File STAB_LAB.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
STAB_LAB (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "STAB_LAB");
  // IF STAB2_STACKTOP = STAB_STACKLIM THEN (7045)
  if (1 & (xEQ (COREHALFWORD (mSTAB2_STACKTOP), 128)))
    // CALL ERROR(CLASS_BT,2); (7046)
    {
      putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_BT));
      putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(2)));
      ERROR (0);
    }
  // ELSE (7047)
  else
    // DO; (7048)
    {
    rs1:;
      // STAB2_STACKTOP = STAB2_STACKTOP + 1; (7049)
      {
        int32_t numberRHS
            = (int32_t)(xadd (COREHALFWORD (mSTAB2_STACKTOP), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSTAB2_STACKTOP, bitRHS);
        bitRHS->inUse = 0;
      }
      // STAB2_STACK(STAB2_STACKTOP) = VAL &  32767; (7050)
      {
        int32_t numberRHS
            = (int32_t)(xAND (COREHALFWORD (mSTAB_LABxVAL), 32767));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSTAB2_STACK + 2 * (COREHALFWORD (mSTAB2_STACKTOP)),
                bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
