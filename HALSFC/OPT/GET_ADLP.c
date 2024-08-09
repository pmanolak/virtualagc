/*
  File GET_ADLP.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

descriptor_t *
GET_ADLP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_ADLP");
  // RET = PTR; (2205)
  {
    descriptor_t *bitRHS = getBIT (16, mGET_ADLPxPTR);
    putBIT (16, mGET_ADLPxRET, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF OP THEN (2206)
  if (1 & (bitToFixed (getBIT (8, mGET_ADLPxOP))))
    // DO; (2207)
    {
    rs1:;
      // DO WHILE NODE(RET) ~= END_OF_NODE; (2208)
      while (1
             & (xNEQ (getFIXED (mNODE + 4 * COREHALFWORD (mGET_ADLPxRET)),
                      getFIXED (mEND_OF_NODE))))
        {
          // RET = RET - 1; (2209)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (COREHALFWORD (mGET_ADLPxRET), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGET_ADLPxRET, bitRHS);
            bitRHS->inUse = 0;
          }
        } // End of DO WHILE block
      // RET = NODE(RET - 1) &  65535; (2210)
      {
        int32_t numberRHS = (int32_t)(xAND (
            getFIXED (mNODE + 4 * xsubtract (COREHALFWORD (mGET_ADLPxRET), 1)),
            65535));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGET_ADLPxRET, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
// REPEATT: (2211)
REPEATT:
  // RET = LAST_OP(RET - 1); (2212)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (16, mLAST_OPxPTR,
                 fixedToBit (32, (int32_t)(xsubtract (
                                     COREHALFWORD (mGET_ADLPxRET), 1)))),
        LAST_OP (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGET_ADLPxRET, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE (OPR(RET) &  65528) ~= ADLP_WORD; (2213)
  while (1
         & (xNEQ (
             xAND (getFIXED (mOPR + 4 * COREHALFWORD (mGET_ADLPxRET)), 65528),
             getFIXED (mADLP_WORD))))
    {
      // TEMP = OPOP(RET); (2214)
      {
        descriptor_t *bitRHS
            = (putBITp (16, mOPOPxPTR, getBIT (16, mGET_ADLPxRET)), OPOP (0));
        putBIT (16, mGET_ADLPxTEMP, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF TEMP = SMRK OR TEMP = DLPE OR RET < 0 THEN (2215)
      if (1
          & (xOR (
              xOR (xEQ (COREHALFWORD (mGET_ADLPxTEMP), COREHALFWORD (mSMRK)),
                   xEQ (COREHALFWORD (mGET_ADLPxTEMP), COREHALFWORD (mDLPE))),
              xLT (COREHALFWORD (mGET_ADLPxRET), 0))))
        // DO; (2216)
        {
        rs2s1:;
          // RET = -1; (2217)
          {
            int32_t numberRHS = (int32_t)(-1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGET_ADLPxRET, bitRHS);
            bitRHS->inUse = 0;
          }
          // GO TO EXITT; (2218)
          goto EXITT;
        es2s1:;
        } // End of DO block
      // RET = LAST_OP(RET - 1); (2219)
      {
        int32_t numberRHS = (int32_t)((
            putBITp (16, mLAST_OPxPTR,
                     fixedToBit (32, (int32_t)(xsubtract (
                                         COREHALFWORD (mGET_ADLPxRET), 1)))),
            LAST_OP (0)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGET_ADLPxRET, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // IF OP THEN (2220)
  if (1 & (bitToFixed (getBIT (8, mGET_ADLPxOP))))
    // DO; (2221)
    {
    rs3:;
      // TEMP = LAST_OP(RET - 1); (2222)
      {
        int32_t numberRHS = (int32_t)((
            putBITp (16, mLAST_OPxPTR,
                     fixedToBit (32, (int32_t)(xsubtract (
                                         COREHALFWORD (mGET_ADLPxRET), 1)))),
            LAST_OP (0)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGET_ADLPxTEMP, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF (OPR(TEMP) &  65528) = DLPE_WORD THEN (2223)
      if (1
          & (xEQ (xAND (getFIXED (mOPR + 4 * COREHALFWORD (mGET_ADLPxTEMP)),
                        65528),
                  getFIXED (mDLPE_WORD))))
        // DO; (2224)
        {
        rs3s1:;
          // RET = LAST_OP(TEMP - 1); (2225)
          {
            int32_t numberRHS = (int32_t)((
                putBITp (
                    16, mLAST_OPxPTR,
                    fixedToBit (32, (int32_t)(xsubtract (
                                        COREHALFWORD (mGET_ADLPxTEMP), 1)))),
                LAST_OP (0)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGET_ADLPxRET, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF (OPR(RET) &  65528) = ADLP_WORD THEN (2226)
          if (1
              & (xEQ (xAND (getFIXED (mOPR + 4 * COREHALFWORD (mGET_ADLPxRET)),
                            65528),
                      getFIXED (mADLP_WORD))))
            // RET = RET + 1; (2227)
            {
              int32_t numberRHS
                  = (int32_t)(xadd (COREHALFWORD (mGET_ADLPxRET), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mGET_ADLPxRET, bitRHS);
              bitRHS->inUse = 0;
            }
          // GO TO REPEATT; (2228)
          goto REPEATT;
        es3s1:;
        } // End of DO block
    es3:;
    } // End of DO block
// EXITT: (2229)
EXITT:
  // IF I_TRACE THEN (2230)
  if (1 & (bitToFixed (getBIT (8, mSTACK_TRACE))))
    // OUTPUT = 'GET_ADLP(' || PTR || ',' || OP || '):  ' || RET; (2231)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          xsCAT (xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "GET_ADLP("),
                                      bitToCharacter (
                                          getBIT (16, mGET_ADLPxPTR))),
                               cToDescriptor (NULL, ",")),
                        bitToCharacter (getBIT (8, mGET_ADLPxOP))),
                 cToDescriptor (NULL, "):  ")),
          bitToCharacter (getBIT (16, mGET_ADLPxRET)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // OP = 0; (2232)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mGET_ADLPxOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN RET; (2233)
  {
    reentryGuard = 0;
    return getBIT (16, mGET_ADLPxRET);
  }
}
