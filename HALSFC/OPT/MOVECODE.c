/*
  File MOVECODE.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
MOVECODE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "MOVECODE");
  // DO WHILE BIG>MOVEBLOCKSIZE; (1279)
  while (1 & (xGT (COREHALFWORD (mMOVECODExBIG), 20)))
    {
      // CALL MOVEBLOCK(LOW,HIGH,MOVEBLOCKSIZE); (1280)
      {
        putBITp (16, mMOVECODExMOVEBLOCKxNEW, getBIT (16, mMOVECODExLOW));
        putBITp (16, mMOVECODExMOVEBLOCKxSTART, getBIT (16, mMOVECODExHIGH));
        putBITp (16, mMOVECODExMOVEBLOCKxROW, fixedToBit (32, (int32_t)(20)));
        MOVECODExMOVEBLOCK (0);
      }
      // LOW=LOW+MOVEBLOCKSIZE; (1281)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mMOVECODExLOW), 20));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mMOVECODExLOW, bitRHS);
        bitRHS->inUse = 0;
      }
      // HIGH=HIGH+MOVEBLOCKSIZE; (1282)
      {
        int32_t numberRHS
            = (int32_t)(xadd (COREHALFWORD (mMOVECODExHIGH), 20));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mMOVECODExHIGH, bitRHS);
        bitRHS->inUse = 0;
      }
      // BIG=BIG-MOVEBLOCKSIZE; (1283)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (COREHALFWORD (mMOVECODExBIG), 20));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mMOVECODExBIG, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // CALL MOVEBLOCK(LOW,HIGH,BIG); (1284)
  {
    putBITp (16, mMOVECODExMOVEBLOCKxNEW, getBIT (16, mMOVECODExLOW));
    putBITp (16, mMOVECODExMOVEBLOCKxSTART, getBIT (16, mMOVECODExHIGH));
    putBITp (16, mMOVECODExMOVEBLOCKxROW, getBIT (16, mMOVECODExBIG));
    MOVECODExMOVEBLOCK (0);
  }
  // ENTER_TAG = 0; (1285)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mMOVECODExENTER_TAG, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
