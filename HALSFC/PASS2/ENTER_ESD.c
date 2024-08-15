/*
  File ENTER_ESD.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
ENTER_ESD (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ENTER_ESD");
  // ESD_NAME_LENGTH(PTR) = LENGTH(NAME); (927)
  {
    int32_t numberRHS = (int32_t)(LENGTH (getCHARACTER (mENTER_ESDxNAME)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mESD_NAME_LENGTH + 1 * (COREHALFWORD (mENTER_ESDxPTR)), bitRHS);
    bitRHS->inUse = 0;
  }
  // I = BYTE(NAME, 1); (928)
  {
    int32_t numberRHS = (int32_t)(BYTE (getCHARACTER (mENTER_ESDxNAME), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mENTER_ESDxI, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF BYTE(NAME) = BYTE('#') THEN (929)
  if (1
      & (xEQ (BYTE1 (getCHARACTER (mENTER_ESDxNAME)),
              BYTE1 (cToDescriptor (NULL, "#")))))
    // IF I = BYTE('Z') | I = BYTE('Q') THEN (930)
    if (1
        & (xOR (xEQ (COREHALFWORD (mENTER_ESDxI),
                     BYTE1 (cToDescriptor (NULL, "Z"))),
                xEQ (COREHALFWORD (mENTER_ESDxI),
                     BYTE1 (cToDescriptor (NULL, "Q"))))))
      // ESD_NAME_LENGTH(PTR) = ESD_NAME_LENGTH(PTR) |  128; (931)
      {
        int32_t numberRHS = (int32_t)(xOR (
            BYTE0 (mESD_NAME_LENGTH + 1 * COREHALFWORD (mENTER_ESDxPTR)),
            128));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mESD_NAME_LENGTH + 1 * (COREHALFWORD (mENTER_ESDxPTR)),
                bitRHS);
        bitRHS->inUse = 0;
      }
  // ESD_TYPE(PTR) = TYP; (932)
  {
    descriptor_t *bitRHS = getBIT (16, mENTER_ESDxTYP);
    putBIT (8, mESD_TYPE + 1 * (COREHALFWORD (mENTER_ESDxPTR)), bitRHS);
    bitRHS->inUse = 0;
  }
  // I = SHR(PTR, 5); (933)
  {
    int32_t numberRHS = (int32_t)(SHR (COREHALFWORD (mENTER_ESDxPTR), 5));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mENTER_ESDxI, bitRHS);
    bitRHS->inUse = 0;
  }
  // J = SHL(PTR-SHL(I,5),3); (934)
  {
    int32_t numberRHS
        = (int32_t)(SHL (xsubtract (COREHALFWORD (mENTER_ESDxPTR),
                                    SHL (COREHALFWORD (mENTER_ESDxI), 5)),
                         3));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mENTER_ESDxJ, bitRHS);
    bitRHS->inUse = 0;
  }
  // NAME = PAD(NAME, 8); (935)
  {
    descriptor_t *stringRHS;
    stringRHS = (putCHARACTERp (mPADxSTRING, getCHARACTER (mENTER_ESDxNAME)),
                 putFIXED (mPADxWIDTH, 8), PAD (0));
    putCHARACTER (mENTER_ESDxNAME, stringRHS);
    stringRHS->inUse = 0;
  }
  // IF J = 0 THEN (936)
  if (1 & (xEQ (COREHALFWORD (mENTER_ESDxJ), 0)))
    // ESD_NAME(I) = NAME || SUBSTR(ESD_NAME(I), 8); (937)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          getCHARACTER (mENTER_ESDxNAME),
          SUBSTR2 (getCHARACTER (mESD_NAME + 4 * COREHALFWORD (mENTER_ESDxI)),
                   8));
      putCHARACTER (mESD_NAME + 4 * (COREHALFWORD (mENTER_ESDxI)), stringRHS);
      stringRHS->inUse = 0;
    }
  // ELSE (938)
  else
    // DO; (939)
    {
    rs1:;
      // NAME = SUBSTR(ESD_NAME(I), 0, J) || NAME || SUBSTR(ESD_NAME(I), J+8);
      // (940)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (SUBSTR (getCHARACTER (mESD_NAME
                                         + 4 * COREHALFWORD (mENTER_ESDxI)),
                           0, COREHALFWORD (mENTER_ESDxJ)),
                   getCHARACTER (mENTER_ESDxNAME)),
            SUBSTR2 (
                getCHARACTER (mESD_NAME + 4 * COREHALFWORD (mENTER_ESDxI)),
                xadd (COREHALFWORD (mENTER_ESDxJ), 8)));
        putCHARACTER (mENTER_ESDxNAME, stringRHS);
        stringRHS->inUse = 0;
      }
      // ESD_NAME(I) = NAME; (941)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mENTER_ESDxNAME);
        putCHARACTER (mESD_NAME + 4 * (COREHALFWORD (mENTER_ESDxI)),
                      stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}