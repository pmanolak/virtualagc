/*
  File CHECK_IMPLICIT_T.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
CHECK_IMPLICIT_T (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CHECK_IMPLICIT_T");
  // IF IMPLICIT_T THEN (9780)
  if (1 & (bitToFixed (getBIT (1, mIMPLICIT_T))))
    // DO; (9781)
    {
    rs1:;
      // IMPLICIT_T=FALSE; (9782)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mIMPLICIT_T, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL ERROR(CLASS_DU,1,'T'); (9783)
      {
        putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DU));
        putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(1)));
        putCHARACTERp (mERRORxTEXT, cToDescriptor (NULL, "T"));
        ERROR (0);
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
