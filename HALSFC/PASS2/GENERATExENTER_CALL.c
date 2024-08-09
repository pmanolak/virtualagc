/*
  File GENERATExENTER_CALL.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExENTER_CALL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExENTER_CALL");
  // NAME = LIBNAME(NAME); (3812)
  {
    descriptor_t *stringRHS;
    stringRHS = (putCHARACTERp (mGENERATExLIBNAMExNAME,
                                getCHARACTER (mGENERATExENTER_CALLxNAME)),
                 GENERATExLIBNAME (0));
    putCHARACTER (mGENERATExENTER_CALLxNAME, stringRHS);
    stringRHS->inUse = 0;
  }
  // J = HASH(NAME); (3813)
  {
    int32_t numberRHS = (int32_t)((
        putCHARACTERp (mHASHxNAME, getCHARACTER (mGENERATExENTER_CALLxNAME)),
        HASH (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExENTER_CALLxJ, bitRHS);
    bitRHS->inUse = 0;
  }
  // I = ESD_START(J); (3814)
  {
    descriptor_t *bitRHS
        = getBIT (16, mESD_START + 2 * COREHALFWORD (mGENERATExENTER_CALLxJ));
    putBIT (16, mGENERATExENTER_CALLxI, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE I ~= 0; (3815)
  while (1 & (xNEQ (COREHALFWORD (mGENERATExENTER_CALLxI), 0)))
    {
      // IF ESD_TABLE(I) = NAME THEN (3816)
      if (1
          & (xsEQ ((putBITp (16, mESD_TABLExPTR,
                             getBIT (16, mGENERATExENTER_CALLxI)),
                    ESD_TABLE (0)),
                   getCHARACTER (mGENERATExENTER_CALLxNAME))))
        // RETURN I; (3817)
        {
          reentryGuard = 0;
          return getBIT (16, mGENERATExENTER_CALLxI);
        }
      // I = ESD_LINK(I); (3818)
      {
        descriptor_t *bitRHS = getBIT (
            16, mESD_LINK + 2 * COREHALFWORD (mGENERATExENTER_CALLxI));
        putBIT (16, mGENERATExENTER_CALLxI, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // ESD_MAX = ESD_MAX + 1; (3819)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mESD_MAX), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mESD_MAX, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF ESD_MAX > ESD_LIMIT THEN (3820)
  if (1 & (xGT (COREHALFWORD (mESD_MAX), 400)))
    // DO; (3821)
    {
    rs2:;
      // ESD_MAX = ESD_LIMIT; (3822)
      {
        int32_t numberRHS = (int32_t)(400);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mESD_MAX, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL ERRORS(CLASS_BS,110); (3823)
      {
        putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BS));
        putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(110)));
        ERRORS (0);
      }
    es2:;
    } // End of DO block
  // CALL ENTER_ESD(NAME, ESD_MAX, 2); (3824)
  {
    putCHARACTERp (mENTER_ESDxNAME, getCHARACTER (mGENERATExENTER_CALLxNAME));
    putBITp (16, mENTER_ESDxPTR, getBIT (16, mESD_MAX));
    putBITp (16, mENTER_ESDxTYP, fixedToBit (32, (int32_t)(2)));
    ENTER_ESD (0);
  }
  // ESD_LINK(ESD_MAX) = ESD_START(J); (3825)
  {
    descriptor_t *bitRHS
        = getBIT (16, mESD_START + 2 * COREHALFWORD (mGENERATExENTER_CALLxJ));
    putBIT (16, mESD_LINK + 2 * (COREHALFWORD (mESD_MAX)), bitRHS);
    bitRHS->inUse = 0;
  }
  // ESD_START(J) = ESD_MAX; (3826)
  {
    descriptor_t *bitRHS = getBIT (16, mESD_MAX);
    putBIT (16, mESD_START + 2 * (COREHALFWORD (mGENERATExENTER_CALLxJ)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN ESD_MAX; (3827)
  {
    reentryGuard = 0;
    return getBIT (16, mESD_MAX);
  }
}
