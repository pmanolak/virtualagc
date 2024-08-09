/*
  File ADD_SMRK_NODExCHANGE_VAC.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

int32_t
ADD_SMRK_NODExCHANGE_VAC (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ADD_SMRK_NODExCHANGE_VAC");
  // OFFSET = #CELLS; (1116)
  {
    descriptor_t *bitRHS = getBIT (16, mpCELLS);
    putBIT (16, mADD_SMRK_NODExCHANGE_VACxOFFSET, bitRHS);
    bitRHS->inUse = 0;
  }
  // OLD_VAL = SHR(CELL,16); (1117)
  {
    int32_t numberRHS
        = (int32_t)(SHR (getFIXED (mADD_SMRK_NODExCHANGE_VACxCELL), 16));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mADD_SMRK_NODExCHANGE_VACxOLD_VAL, bitRHS);
    bitRHS->inUse = 0;
  }
  // NEW_VAL = OFFSET+(OLD_VAL-VAC_START); (1118)
  {
    int32_t numberRHS = (int32_t)(xadd (
        COREHALFWORD (mADD_SMRK_NODExCHANGE_VACxOFFSET),
        xsubtract (COREHALFWORD (mADD_SMRK_NODExCHANGE_VACxOLD_VAL),
                   COREHALFWORD (mVAC_START))));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mADD_SMRK_NODExCHANGE_VACxNEW_VAL, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN SHL(NEW_VAL,16) | (CELL &  65535); (1119)
  {
    reentryGuard = 0;
    return xOR (SHL (COREHALFWORD (mADD_SMRK_NODExCHANGE_VACxNEW_VAL), 16),
                xAND (getFIXED (mADD_SMRK_NODExCHANGE_VACxCELL), 65535));
  }
}
