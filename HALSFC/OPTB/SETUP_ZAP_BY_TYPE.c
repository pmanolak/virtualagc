/*
  File SETUP_ZAP_BY_TYPE.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
SETUP_ZAP_BY_TYPE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SETUP_ZAP_BY_TYPE");
  // DO FOR K = 2 TO COMM(10); (1146)
  {
    int32_t from25, to25, by25;
    from25 = 2;
    to25 = getFIXED (mCOMM + 4 * 10);
    by25 = 1;
    for (putBIT (16, mSETUP_ZAP_BY_TYPExK, fixedToBit (16, from25));
         bitToFixed (getBIT (16, mSETUP_ZAP_BY_TYPExK)) <= to25;
         putBIT (16, mSETUP_ZAP_BY_TYPExK,
                 fixedToBit (16, bitToFixed (getBIT (16, mSETUP_ZAP_BY_TYPExK))
                                     + by25)))
      {
        // PTR = REL(K); (1147)
        {
          descriptor_t *bitRHS
              = getBIT (16, getFIXED (mSYM_SHRINK)
                                + 2 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExK)) + 0
                                + 2 * (0));
          putBIT (16, mSETUP_ZAP_BY_TYPExPTR, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF PTR > 1 THEN (1148)
        if (1 & (xGT (COREHALFWORD (mSETUP_ZAP_BY_TYPExPTR), 1)))
          // DO; (1149)
          {
          rs1s1:;
            // TYPE = SYT_TYPE(K); (1150)
            {
              descriptor_t *bitRHS
                  = getBIT (8, getFIXED (mSYM_TAB)
                                   + 34 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExK))
                                   + 32 + 1 * (0));
              putBIT (16, mSETUP_ZAP_BY_TYPExTYPE, bitRHS);
              bitRHS->inUse = 0;
            }
            // IF TYPE > 0 AND TYPE <= INT_VAR THEN (1151)
            if (1
                & (xAND (xGT (COREHALFWORD (mSETUP_ZAP_BY_TYPExTYPE), 0),
                         xLE (COREHALFWORD (mSETUP_ZAP_BY_TYPExTYPE),
                              BYTE0 (mINT_VAR)))))
              // DO; (1152)
              {
              rs1s1s1:;
                // BIT_PTR = PTR &  31; (1153)
                {
                  int32_t numberRHS = (int32_t)(xAND (
                      COREHALFWORD (mSETUP_ZAP_BY_TYPExPTR), 31));
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (16, mSETUP_ZAP_BY_TYPExBIT_PTR, bitRHS);
                  bitRHS->inUse = 0;
                }
                // ZAPIT(TYPE-1).TYPE_ZAP(SHR(PTR,5)) =
                // ZAPIT(TYPE-1).TYPE_ZAP(SHR(PTR,5)) | SHL(1,BIT_PTR); (1154)
                {
                  int32_t numberRHS = (int32_t)(xOR (
                      getFIXED (
                          getFIXED (mZAPIT)
                          + 4
                                * (xsubtract (
                                    COREHALFWORD (mSETUP_ZAP_BY_TYPExTYPE), 1))
                          + 0
                          + 4
                                * (SHR (COREHALFWORD (mSETUP_ZAP_BY_TYPExPTR),
                                        5))),
                      SHL (1, COREHALFWORD (mSETUP_ZAP_BY_TYPExBIT_PTR))));
                  putFIXED (
                      getFIXED (mZAPIT)
                          + 4
                                * (xsubtract (
                                    COREHALFWORD (mSETUP_ZAP_BY_TYPExTYPE), 1))
                          + 0
                          + 4
                                * (SHR (COREHALFWORD (mSETUP_ZAP_BY_TYPExPTR),
                                        5)),
                      numberRHS);
                }
              es1s1s1:;
              } // End of DO block
          es1s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // MAT_BASE = VAL_SIZE + VAL_SIZE; (1155)
  {
    int32_t numberRHS
        = (int32_t)(xadd (COREHALFWORD (mVAL_SIZE), COREHALFWORD (mVAL_SIZE)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSETUP_ZAP_BY_TYPExMAT_BASE, bitRHS);
    bitRHS->inUse = 0;
  }
  // MAT_BASE = 2; (1156)
  {
    int32_t numberRHS = (int32_t)(2);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSETUP_ZAP_BY_TYPExMAT_BASE, bitRHS);
    bitRHS->inUse = 0;
  }
  // VEC_BASE = 3; (1157)
  {
    int32_t numberRHS = (int32_t)(3);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSETUP_ZAP_BY_TYPExVEC_BASE, bitRHS);
    bitRHS->inUse = 0;
  }
  // SCAL_BASE = 4; (1158)
  {
    int32_t numberRHS = (int32_t)(4);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSETUP_ZAP_BY_TYPExSCAL_BASE, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO FOR K = 0 TO VAL_SIZE - 1; (1159)
  {
    int32_t from26, to26, by26;
    from26 = 0;
    to26 = xsubtract (COREHALFWORD (mVAL_SIZE), 1);
    by26 = 1;
    for (putBIT (16, mSETUP_ZAP_BY_TYPExK, fixedToBit (16, from26));
         bitToFixed (getBIT (16, mSETUP_ZAP_BY_TYPExK)) <= to26;
         putBIT (16, mSETUP_ZAP_BY_TYPExK,
                 fixedToBit (16, bitToFixed (getBIT (16, mSETUP_ZAP_BY_TYPExK))
                                     + by26)))
      {
        // ZAPIT(VEC_BASE).TYPE_ZAP(K) = ZAPIT(VEC_BASE).TYPE_ZAP(K) |
        // ZAPIT(MAT_BASE).TYPE_ZAP(K); (1160)
        {
          int32_t numberRHS = (int32_t)(xOR (
              getFIXED (getFIXED (mZAPIT)
                        + 4 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExVEC_BASE)) + 0
                        + 4 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExK))),
              getFIXED (getFIXED (mZAPIT)
                        + 4 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExMAT_BASE)) + 0
                        + 4 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExK)))));
          putFIXED (getFIXED (mZAPIT)
                        + 4 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExVEC_BASE)) + 0
                        + 4 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExK)),
                    numberRHS);
        }
        // ZAPIT(SCAL_BASE).TYPE_ZAP(K) = ZAPIT(SCAL_BASE).TYPE_ZAP(K) |
        // ZAPIT(VEC_BASE).TYPE_ZAP(K); (1161)
        {
          int32_t numberRHS = (int32_t)(xOR (
              getFIXED (getFIXED (mZAPIT)
                        + 4 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExSCAL_BASE)) + 0
                        + 4 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExK))),
              getFIXED (getFIXED (mZAPIT)
                        + 4 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExVEC_BASE)) + 0
                        + 4 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExK)))));
          putFIXED (getFIXED (mZAPIT)
                        + 4 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExSCAL_BASE)) + 0
                        + 4 * (COREHALFWORD (mSETUP_ZAP_BY_TYPExK)),
                    numberRHS);
        }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
