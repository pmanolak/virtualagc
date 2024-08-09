/*
  File IORS.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
IORS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "IORS");
  // LOC=PTR(LOC); (7650)
  {
    descriptor_t *bitRHS = getBIT (16, mPTR + 2 * COREHALFWORD (mIORSxLOC));
    putBIT (16, mIORSxLOC, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF PSEUDO_TYPE(LOC)~=INT_TYPE THEN (7651)
  if (1 & (xNEQ (BYTE0 (mPSEUDO_TYPE + 1 * COREHALFWORD (mIORSxLOC)), 6)))
    // IF PSEUDO_TYPE(LOC)~=SCALAR_TYPE THEN (7652)
    if (1 & (xNEQ (BYTE0 (mPSEUDO_TYPE + 1 * COREHALFWORD (mIORSxLOC)), 5)))
      // DO; (7653)
      {
      rs1:;
        // CALL ERROR(CLASS_ST,1,VAR(MP)); (7654)
        {
          putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_ST));
          putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(1)));
          putCHARACTERp (mERRORxTEXT,
                         getCHARACTER (mVAR + 4 * getFIXED (mMP)));
          ERROR (0);
        }
        // PSEUDO_TYPE(LOC)=INT_TYPE; (7655)
        {
          int32_t numberRHS = (int32_t)(6);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (8, mPSEUDO_TYPE + 1 * (COREHALFWORD (mIORSxLOC)), bitRHS);
          bitRHS->inUse = 0;
        }
      es1:;
      } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
