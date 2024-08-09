/*
  File INITIALISExSYMBOL_USED.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

descriptor_t *
INITIALISExSYMBOL_USED (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INITIALISExSYMBOL_USED");
  // IF SELFNAMELOC > 0 THEN (2177)
  if (1 & (xGT (COREHALFWORD (mSELFNAMELOC), 0)))
    // IF PTR >= SELFNAMELOC THEN (2178)
    if (1
        & (xGE (COREHALFWORD (mINITIALISExSYMBOL_USEDxPTR),
                COREHALFWORD (mSELFNAMELOC))))
      // RETURN TRUE; (2179)
      {
        reentryGuard = 0;
        return fixedToBit (32, (int32_t)(1));
      }
  // IF MAX_SEVERITY > 0 THEN (2180)
  if (1 & (xGT (COREHALFWORD (mMAX_SEVERITY), 0)))
    // RETURN TRUE; (2181)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(1));
    }
  // PTR = SYT_XREF(PTR); (2182)
  {
    descriptor_t *bitRHS
        = getBIT (16, getFIXED (mSYM_TAB)
                          + 34 * (COREHALFWORD (mINITIALISExSYMBOL_USEDxPTR))
                          + 16 + 2 * (0));
    putBIT (16, mINITIALISExSYMBOL_USEDxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE PTR > 0; (2183)
  while (1 & (xGT (COREHALFWORD (mINITIALISExSYMBOL_USEDxPTR), 0)))
    {
      // IF (XREF(PTR) &  57344) ~= 0 THEN (2184)
      if (1
          & (xNEQ (xAND (getFIXED (
                             getFIXED (mCROSS_REF)
                             + 4 * (COREHALFWORD (mINITIALISExSYMBOL_USEDxPTR))
                             + 0 + 4 * (0)),
                         57344),
                   0)))
        // IF (XREF(PTR) &  8191) > FIRSTSTMT# THEN (2185)
        if (1
            & (xGT (
                xAND (getFIXED (
                          getFIXED (mCROSS_REF)
                          + 4 * (COREHALFWORD (mINITIALISExSYMBOL_USEDxPTR))
                          + 0 + 4 * (0)),
                      8191),
                getFIXED (mCOMM + 4 * 11))))
          // RETURN TRUE; (2186)
          {
            reentryGuard = 0;
            return fixedToBit (32, (int32_t)(1));
          }
      // PTR = SHR(XREF(PTR), 16); (2187)
      {
        int32_t numberRHS = (int32_t)(SHR (
            getFIXED (getFIXED (mCROSS_REF)
                      + 4 * (COREHALFWORD (mINITIALISExSYMBOL_USEDxPTR)) + 0
                      + 4 * (0)),
            16));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mINITIALISExSYMBOL_USEDxPTR, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // RETURN FALSE; (2188)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
