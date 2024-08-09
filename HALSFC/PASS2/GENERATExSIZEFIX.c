/*
  File GENERATExSIZEFIX.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExSIZEFIX (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExSIZEFIX");
  // IF TYPE(PTR) >= ANY_LABEL THEN (5122)
  if (1
      & (xGE (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR)) + 50
                            + 2 * (0)),
              BYTE0 (mANY_LABEL))))
    // RETURN; (5123)
    {
      reentryGuard = 0;
      return 0;
    }
  // DO CASE PACKTYPE(TYPE(PTR)); (5124)
  {
  rs1:
    switch (BYTE0 (
        mPACKTYPE
        + 1
              * COREHALFWORD (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR))
                              + 50 + 2 * (0))))
      {
      case 0:
        // DO; (5126)
        {
        rs1s1:;
          // ROW(PTR) = SHR(SYT_DIMS(OP1), 8) &  255; (5126)
          {
            int32_t numberRHS = (int32_t)(xAND (
                SHR (
                    COREHALFWORD (getFIXED (mSYM_TAB)
                                  + 34 * (COREHALFWORD (mGENERATExSIZEFIXxOP1))
                                  + 18 + 2 * (0)),
                    8),
                255));
            putBIT (16,
                    getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR)) + 48
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
          // COLUMN(PTR) = SYT_DIMS(OP1) &  255; (5127)
          {
            int32_t numberRHS = (int32_t)(xAND (
                COREHALFWORD (getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mGENERATExSIZEFIXxOP1))
                              + 18 + 2 * (0)),
                255));
            putBIT (16,
                    getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR)) + 24
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
          // DEL(PTR) = 0; (5128)
          {
            int32_t numberRHS = (int32_t)(0);
            putBIT (16,
                    getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR)) + 28
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
        es1s1:;
        } // End of DO block
        break;
      case 1:
        // DO; (5130)
        {
        rs1s2:;
          // LITOP = SYT_DIMS(OP1); (5130)
          {
            descriptor_t *bitRHS
                = getBIT (16, getFIXED (mSYM_TAB)
                                  + 34 * (COREHALFWORD (mGENERATExSIZEFIXxOP1))
                                  + 18 + 2 * (0));
            putBIT (16, mGENERATExSIZEFIXxLITOP, bitRHS);
            bitRHS->inUse = 0;
          }
          // SIZE(PTR) = LITOP &  255; (5131)
          {
            int32_t numberRHS = (int32_t)(xAND (
                COREHALFWORD (mGENERATExSIZEFIXxLITOP), 255));
            putBIT (16,
                    getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR)) + 48
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
          // LITOP = SHR(LITOP, 8) &  255; (5132)
          {
            int32_t numberRHS = (int32_t)(xAND (
                SHR (COREHALFWORD (mGENERATExSIZEFIXxLITOP), 8), 255));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGENERATExSIZEFIXxLITOP, bitRHS);
            bitRHS->inUse = 0;
          }
          // COLUMN(PTR) = 0; (5133)
          {
            int32_t numberRHS = (int32_t)(0);
            putBIT (16,
                    getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR)) + 24
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
          // IF ~( (SYT_TYPE(OP1) >= TASK_LABEL) &  (CLASS ~=7) & (CLASS ~= 1)
          // ) THEN (5134)
          if (1
              & (xNOT (xAND (
                  xAND (
                      xGE (BYTE0 (getFIXED (mSYM_TAB)
                                  + 34 * (COREHALFWORD (mGENERATExSIZEFIXxOP1))
                                  + 32 + 1 * (0)),
                           BYTE0 (mTASK_LABEL)),
                      xNEQ (COREHALFWORD (mCLASS), 7)),
                  xNEQ (COREHALFWORD (mCLASS), 1)))))
            // IF LITOP ~= 0 THEN (5135)
            if (1 & (xNEQ (COREHALFWORD (mGENERATExSIZEFIXxLITOP), 0)))
              // IF BY_NAME = 0 THEN (5136)
              if (1 & (xEQ (BYTE0 (mGENERATExSIZEFIXxBY_NAME), 0)))
                // DO; (5137)
                {
                rs1s2s1:;
                  // IF LITOP =  255 THEN (5138)
                  if (1 & (xEQ (COREHALFWORD (mGENERATExSIZEFIXxLITOP), 255)))
                    // LITOP = 0; (5139)
                    {
                      int32_t numberRHS = (int32_t)(0);
                      descriptor_t *bitRHS;
                      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                      putBIT (16, mGENERATExSIZEFIXxLITOP, bitRHS);
                      bitRHS->inUse = 0;
                    }
                  // IF TYPE(PTR) = FULLBIT THEN (5140)
                  if (1
                      & (xEQ (COREHALFWORD (
                                  getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR))
                                  + 50 + 2 * (0)),
                              BYTE0 (mFULLBIT))))
                    // IF LITOP+SIZE(PTR) <= HALFWORDSIZE THEN (5141)
                    if (1
                        & (xLE (xadd (COREHALFWORD (mGENERATExSIZEFIXxLITOP),
                                      COREHALFWORD (
                                          getFIXED (mIND_STACK)
                                          + 73
                                                * (COREHALFWORD (
                                                    mGENERATExSIZEFIXxPTR))
                                          + 48 + 2 * (0))),
                                BYTE0 (mHALFWORDSIZE))))
                      // DO; (5142)
                      {
                      rs1s2s1s1:;
                        // TYPE(PTR) = BITS; (5143)
                        {
                          descriptor_t *bitRHS = getBIT (8, mBITS);
                          putBIT (
                              16,
                              getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR))
                                  + 50 + 2 * (0),
                              bitRHS);
                          bitRHS->inUse = 0;
                        }
                        // STRUCT_CON(PTR) = STRUCT_CON(PTR) + 1; (5144)
                        {
                          int32_t numberRHS = (int32_t)(xadd (
                              getFIXED (
                                  getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR))
                                  + 8 + 4 * (0)),
                              1));
                          putFIXED (
                              getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR))
                                  + 8 + 4 * (0),
                              numberRHS);
                        }
                      es1s2s1s1:;
                      } // End of DO block
                    // ELSE (5145)
                    else
                      // IF LITOP >= HALFWORDSIZE THEN (5146)
                      if (1
                          & (xGE (COREHALFWORD (mGENERATExSIZEFIXxLITOP),
                                  BYTE0 (mHALFWORDSIZE))))
                        // DO; (5147)
                        {
                        rs1s2s1s2:;
                          // TYPE(PTR) = BITS; (5148)
                          {
                            descriptor_t *bitRHS = getBIT (8, mBITS);
                            putBIT (16,
                                    getFIXED (mIND_STACK)
                                        + 73
                                              * (COREHALFWORD (
                                                  mGENERATExSIZEFIXxPTR))
                                        + 50 + 2 * (0),
                                    bitRHS);
                            bitRHS->inUse = 0;
                          }
                          // LITOP = LITOP - HALFWORDSIZE; (5149)
                          {
                            int32_t numberRHS = (int32_t)(xsubtract (
                                COREHALFWORD (mGENERATExSIZEFIXxLITOP),
                                BYTE0 (mHALFWORDSIZE)));
                            descriptor_t *bitRHS;
                            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                            putBIT (16, mGENERATExSIZEFIXxLITOP, bitRHS);
                            bitRHS->inUse = 0;
                          }
                        es1s2s1s2:;
                        } // End of DO block
                  // COLUMN(PTR) = GET_INTEGER_LITERAL(LITOP); (5150)
                  {
                    descriptor_t *bitRHS
                        = (putFIXED (mGENERATExGET_INTEGER_LITERALxVALUE,
                                     COREHALFWORD (mGENERATExSIZEFIXxLITOP)),
                           GENERATExGET_INTEGER_LITERAL (0));
                    putBIT (16,
                            getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR))
                                + 24 + 2 * (0),
                            bitRHS);
                    bitRHS->inUse = 0;
                  }
                es1s2s1:;
                } // End of DO block
          // DEL(PTR) = 0; (5151)
          {
            int32_t numberRHS = (int32_t)(0);
            putBIT (16,
                    getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR)) + 28
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
        es1s2:;
        } // End of DO block
        break;
      case 2:
        // SIZE(PTR) = SYT_DIMS(OP1); (5153)
        {
          descriptor_t *bitRHS
              = getBIT (16, getFIXED (mSYM_TAB)
                                + 34 * (COREHALFWORD (mGENERATExSIZEFIXxOP1))
                                + 18 + 2 * (0));
          putBIT (16,
                  getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR)) + 48
                      + 2 * (0),
                  bitRHS);
          bitRHS->inUse = 0;
        }
        break;
      case 3:
        // DEL(PTR) = 0; (5154)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR)) + 28
                      + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        break;
      case 4:
        // DO; (5155)
        {
        rs1s3:;
          // DEL(PTR) = OP1; (5155)
          {
            descriptor_t *bitRHS = getBIT (16, mGENERATExSIZEFIXxOP1);
            putBIT (16,
                    getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR)) + 28
                        + 2 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
          // SIZE(PTR) = EXTENT(OP1); (5156)
          {
            int32_t numberRHS = (int32_t)(getFIXED (
                getFIXED (mSYM_TAB)
                + 34 * (COREHALFWORD (mGENERATExSIZEFIXxOP1)) + 12 + 4 * (0)));
            putBIT (16,
                    getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExSIZEFIXxPTR)) + 48
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
        es1s3:;
        } // End of DO block
        break;
      }
  } // End of DO CASE block
  // BY_NAME = FALSE; (5157)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExSIZEFIXxBY_NAME, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
