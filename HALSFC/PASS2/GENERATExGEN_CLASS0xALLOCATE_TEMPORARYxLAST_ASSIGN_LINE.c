/*
  File GENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINE.c generated by
  XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (
      reentryGuard, "GENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINE");
  // LINE = 0; (12244)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINExLINE,
            bitRHS);
    bitRHS->inUse = 0;
  }
  // IF MAX_SEVERITY > 0 THEN (12245)
  if (1 & (xGT (COREHALFWORD (mMAX_SEVERITY), 0)))
    // RETURN LINE; (12246)
    {
      reentryGuard = 0;
      return getBIT (
          16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINExLINE);
    }
  // PTR = SYT_XREF(PTR); (12247)
  {
    descriptor_t *bitRHS = getBIT (
        16,
        getFIXED (mSYM_TAB)
            + 34
                  * (COREHALFWORD (
                      mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINExPTR))
            + 16 + 2 * (0));
    putBIT (16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINExPTR,
            bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE PTR > 0; (12248)
  while (1
         & (xGT (
             COREHALFWORD (
                 mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINExPTR),
             0)))
    {
      // IF (XREF(PTR) &  32768) ~= 0 THEN (12249)
      if (1
          & (xNEQ (
              xAND (
                  getFIXED (
                      getFIXED (mCROSS_REF)
                      + 4
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINExPTR))
                      + 0 + 4 * (0)),
                  32768),
              0)))
        // LINE = XREF(PTR) &  8191; (12250)
        {
          int32_t numberRHS = (int32_t)(xAND (
              getFIXED (
                  getFIXED (mCROSS_REF)
                  + 4
                        * (COREHALFWORD (
                            mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINExPTR))
                  + 0 + 4 * (0)),
              8191));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (
              16,
              mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINExLINE,
              bitRHS);
          bitRHS->inUse = 0;
        }
      // PTR = SHR(XREF(PTR), 16); (12251)
      {
        int32_t numberRHS = (int32_t)(SHR (
            getFIXED (
                getFIXED (mCROSS_REF)
                + 4
                      * (COREHALFWORD (
                          mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINExPTR))
                + 0 + 4 * (0)),
            16));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16,
                mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINExPTR,
                bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // RETURN LINE; (12252)
  {
    reentryGuard = 0;
    return getBIT (
        16, mGENERATExGEN_CLASS0xALLOCATE_TEMPORARYxLAST_ASSIGN_LINExLINE);
  }
}
