/*
  File HEX.c generated by XCOM-I, 2024-08-09 12:39:13.
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
  // STRING = SUBSTR(BLANK || '0000', 1); (642)
  {
    descriptor_t *stringRHS;
    stringRHS = SUBSTR2 (
        xsCAT (getCHARACTER (mBLANK), cToDescriptor (NULL, "0000")), 1);
    putCHARACTER (mHEXxSTRING, stringRHS);
    stringRHS->inUse = 0;
  }
  // K = 3; (643)
  {
    int32_t numberRHS = (int32_t)(3);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mHEXxK, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE NUMBER > 0; (644)
  while (1 & (xGT (COREHALFWORD (mHEXxNUMBER), 0)))
    {
      // B = BYTE(HEXCODES, NUMBER &  15); (645)
      {
        int32_t numberRHS
            = (int32_t)(BYTE (getCHARACTER (mHEXxHEXCODES),
                              xAND (COREHALFWORD (mHEXxNUMBER), 15)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mHEXxB, bitRHS);
        bitRHS->inUse = 0;
      }
      // BYTE(STRING, K) = B; (646)
      {
        descriptor_t *bitRHS = getBIT (16, mHEXxB);
        lBYTEb (ADDR (NULL, 0, "HEXxSTRING", 0), COREHALFWORD (mHEXxK),
                COREHALFWORD (mHEXxB));
        bitRHS->inUse = 0;
      }
      // K = K - 1; (647)
      {
        int32_t numberRHS = (int32_t)(xsubtract (COREHALFWORD (mHEXxK), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mHEXxK, bitRHS);
        bitRHS->inUse = 0;
      }
      // NUMBER = SHR(NUMBER, 4); (648)
      {
        int32_t numberRHS = (int32_t)(SHR (COREHALFWORD (mHEXxNUMBER), 4));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mHEXxNUMBER, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // RETURN SUBSTR(STRING, 4 - TOTAL_LENGTH); (649)
  {
    reentryGuard = 0;
    return SUBSTR2 (getCHARACTER (mHEXxSTRING),
                    xsubtract (4, COREHALFWORD (mHEXxTOTAL_LENGTH)));
  }
}
