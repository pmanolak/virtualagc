/*
  File EMIT_OUTPUT.c generated by XCOM-I, 2024-08-09 12:40:27.
*/

#include "runtimeC.h"

descriptor_t *
EMIT_OUTPUT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "EMIT_OUTPUT");
  // IF LENGTH(STRING) < 133 THEN (622)
  if (1 & (xLT (LENGTH (getCHARACTER (mEMIT_OUTPUTxSTRING)), 133)))
    // OUTPUT = STRING; (623)
    {
      descriptor_t *stringRHS;
      stringRHS = getCHARACTER (mEMIT_OUTPUTxSTRING);
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // ELSE (624)
  else
    // DO; (625)
    {
    rs1:;
      // OUTPUT = SUBSTR(STRING,0,132); (626)
      {
        descriptor_t *stringRHS;
        stringRHS = SUBSTR (getCHARACTER (mEMIT_OUTPUTxSTRING), 0, 132);
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = SUBSTR(STRING,132); (627)
      {
        descriptor_t *stringRHS;
        stringRHS = SUBSTR2 (getCHARACTER (mEMIT_OUTPUTxSTRING), 132);
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
