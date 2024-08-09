/*
  File OBJECT_CONDENSERxVERIFY.c generated by XCOM-I, 2024-08-09 12:41:33.
*/

#include "runtimeC.h"

int32_t
OBJECT_CONDENSERxVERIFY (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "OBJECT_CONDENSERxVERIFY");
  // IF LOCATION(LBL) ~= CURRENT_ADDRESS THEN (14382)
  if (1
      & (xNEQ (getFIXED (getFIXED (mLAB_LOC)
                         + 8 * (COREHALFWORD (mOBJECT_CONDENSERxVERIFYxLBL))
                         + 0 + 4 * (0)),
               getFIXED (mWORKSEG + 4 * getFIXED (mCURRENT_ESDID)))))
    // DO; (14383)
    {
    rs1:;
      // CALL ERRORS(CLASS_BI,509,' '||LBL); (14384)
      {
        putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BI));
        putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(509)));
        putCHARACTERp (mERRORSxTEXT,
                       xsCAT (cToDescriptor (NULL, " "),
                              bitToCharacter (
                                  getBIT (16, mOBJECT_CONDENSERxVERIFYxLBL))));
        ERRORS (0);
      }
      // IF MAX_SEVERITY = 0 THEN (14385)
      if (1 & (xEQ (COREHALFWORD (mMAX_SEVERITY), 0)))
        // MAX_SEVERITY = 1; (14386)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mMAX_SEVERITY, bitRHS);
          bitRHS->inUse = 0;
        }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
