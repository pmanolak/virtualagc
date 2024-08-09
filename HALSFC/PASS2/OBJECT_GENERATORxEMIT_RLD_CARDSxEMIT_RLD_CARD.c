/*
  File OBJECT_GENERATORxEMIT_RLD_CARDSxEMIT_RLD_CARD.c generated by XCOM-I,
  2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
OBJECT_GENERATORxEMIT_RLD_CARDSxEMIT_RLD_CARD (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (
      reentryGuard, "OBJECT_GENERATORxEMIT_RLD_CARDSxEMIT_RLD_CARD");
  // CALL EMIT_CARD; (16241)
  OBJECT_GENERATORxEMIT_CARD (0);
  // BYTES_REMAINING, CURRENT_SIZE = 48; (16242)
  {
    int32_t numberRHS = (int32_t)(48);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOBJECT_GENERATORxBYTES_REMAINING, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOBJECT_GENERATORxCURRENT_SIZE, bitRHS);
    bitRHS->inUse = 0;
  }
  // CARDIMAGE,CARDIMAGE(1) = RLD_CARD; (16243)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mOBJECT_GENERATORxRLD_CARD));
    putFIXED (mOBJECT_GENERATORxCARDIMAGE, numberRHS);
    putFIXED (mOBJECT_GENERATORxCARDIMAGE + 4 * (1), numberRHS);
  }
  // J = 5; (16244)
  {
    int32_t numberRHS = (int32_t)(5);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOBJECT_GENERATORxEMIT_RLD_CARDSxJ, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
