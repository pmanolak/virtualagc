/*
  File TERM_CHECK.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

descriptor_t *
TERM_CHECK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "TERM_CHECK");
  // IF NAME_CHECK(ST_PTR,1) THEN (3117)
  if (1
      & (bitToFixed (
          (putBITp (16, mNAME_CHECKxPTR, getBIT (16, mTERM_CHECKxST_PTR)),
           putBITp (8, mNAME_CHECKxKEEP_VALIDITY,
                    fixedToBit (32, (int32_t)(1))),
           NAME_CHECK (0)))))
    // RETURN 1; (3118)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(1));
    }
  // PTR = LAST_OPERAND(PTR); (3119)
  {
    descriptor_t *bitRHS
        = (putBITp (16, mLAST_OPERANDxPTR, getBIT (16, mTERM_CHECKxPTR)),
           LAST_OPERAND (0));
    putBIT (16, mTERM_CHECKxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF ~HIGHOPT THEN (3120)
  if (1 & (xNOT (BYTE0 (mHIGHOPT))))
    // DO; (3121)
    {
    rs1:;
      // ST_PTR = ST_PTR + 1; (3122)
      {
        int32_t numberRHS
            = (int32_t)(xadd (COREHALFWORD (mTERM_CHECKxST_PTR), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mTERM_CHECKxST_PTR, bitRHS);
        bitRHS->inUse = 0;
      }
      // DO WHILE ST_PTR < PTR; (3123)
      while (1
             & (xLT (COREHALFWORD (mTERM_CHECKxST_PTR),
                     COREHALFWORD (mTERM_CHECKxPTR))))
        {
          // IF (SHR(OPR(ST_PTR),4) &  15) = SYM  THEN (3124)
          if (1
              & (xEQ (
                  xAND (SHR (getFIXED (
                                 mOPR + 4 * COREHALFWORD (mTERM_CHECKxST_PTR)),
                             4),
                        15),
                  COREHALFWORD (mSYM))))
            // DO; (3125)
            {
            rs1s1s1:;
              // IF NAME_CHECK(ST_PTR,1)  THEN (3126)
              if (1
                  & (bitToFixed ((putBITp (16, mNAME_CHECKxPTR,
                                           getBIT (16, mTERM_CHECKxST_PTR)),
                                  putBITp (8, mNAME_CHECKxKEEP_VALIDITY,
                                           fixedToBit (32, (int32_t)(1))),
                                  NAME_CHECK (0)))))
                // RETURN 1; (3127)
                {
                  reentryGuard = 0;
                  return fixedToBit (32, (int32_t)(1));
                }
            es1s1s1:;
            } // End of DO block
          // ST_PTR = ST_PTR + 1; (3128)
          {
            int32_t numberRHS
                = (int32_t)(xadd (COREHALFWORD (mTERM_CHECKxST_PTR), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mTERM_CHECKxST_PTR, bitRHS);
            bitRHS->inUse = 0;
          }
        } // End of DO WHILE block
    es1:;
    } // End of DO block
  // IF SYT_TYPE(SHR(OPR(PTR),16)) < MAJ_STRUCT THEN (3129)
  if (1
      & (xLT (
          BYTE0 (getFIXED (mSYM_TAB)
                 + 34
                       * (SHR (getFIXED (mOPR
                                         + 4 * COREHALFWORD (mTERM_CHECKxPTR)),
                               16))
                 + 32 + 1 * (0)),
          COREHALFWORD (mMAJ_STRUCT))))
    // RETURN NAME_CHECK(PTR,0); (3130)
    {
      reentryGuard = 0;
      return (putBITp (16, mNAME_CHECKxPTR, getBIT (16, mTERM_CHECKxPTR)),
              putBITp (8, mNAME_CHECKxKEEP_VALIDITY,
                       fixedToBit (32, (int32_t)(0))),
              NAME_CHECK (0));
    }
  // ELSE (3131)
  else
    // DO; (3132)
    {
    rs2:;
      // CALL ZAP_TABLES; (3133)
      ZAP_TABLES (0);
      // RETURN 1; (3134)
      {
        reentryGuard = 0;
        return fixedToBit (32, (int32_t)(1));
      }
    es2:;
    } // End of DO block
  // RETURN 0; (3135)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
