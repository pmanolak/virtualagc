/*
  File SET_NONCOMMUTATIVE.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
SET_NONCOMMUTATIVE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SET_NONCOMMUTATIVE");
  // IF TRACE THEN (2027)
  if (1 & (bitToFixed (getBIT (8, mTRACE))))
    // OUTPUT = HEX(OP,4) || ': SET_NONCOMMUTATIVE'; (2028)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          (putFIXED (mHEXxHVAL, COREHALFWORD (mSET_NONCOMMUTATIVExOP)),
           putFIXED (mHEXxN, 4), HEX (0)),
          cToDescriptor (NULL, ": SET_NONCOMMUTATIVE"));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // TWIN_OP, BIT_TYPE = FALSE; (2029)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mTWIN_OP, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mBIT_TYPE, bitRHS);
    bitRHS->inUse = 0;
  }
  // NONCOMMUTATIVE = TRUE; (2030)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mSET_NONCOMMUTATIVExNONCOMMUTATIVE, bitRHS);
    bitRHS->inUse = 0;
  }
  // TRANSPARENT = (OP &  255) =  1 & SHR(OP,8) ~= 0; (2031)
  {
    int32_t numberRHS = (int32_t)(xAND (
        xEQ (xAND (COREHALFWORD (mSET_NONCOMMUTATIVExOP), 255), 1),
        xNEQ (SHR (COREHALFWORD (mSET_NONCOMMUTATIVExOP), 8), 0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mTRANSPARENT, bitRHS);
    bitRHS->inUse = 0;
  }
  // TRANSPARENT = TRANSPARENT & ((OP &  3840) ~=  3840); (2032)
  {
    int32_t numberRHS = (int32_t)(xAND (
        BYTE0 (mTRANSPARENT),
        xNEQ (xAND (COREHALFWORD (mSET_NONCOMMUTATIVExOP), 3840), 3840)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mTRANSPARENT, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO CASE (SHR(OP,8) &  15) ; (2033)
  {
  rs1:
    switch (xAND (SHR (COREHALFWORD (mSET_NONCOMMUTATIVExOP), 8), 15))
      {
      case 0:
        // IF OP = RTRN OR OP = TASN  OR (OP >= MSHP AND OP <= ISHP) THEN
        // (2035)
        if (1
            & (xOR (xOR (xEQ (COREHALFWORD (mSET_NONCOMMUTATIVExOP),
                              COREHALFWORD (mRTRN)),
                         xEQ (COREHALFWORD (mSET_NONCOMMUTATIVExOP),
                              COREHALFWORD (mTASN))),
                    xAND (xGE (COREHALFWORD (mSET_NONCOMMUTATIVExOP),
                               COREHALFWORD (mMSHP)),
                          xLE (COREHALFWORD (mSET_NONCOMMUTATIVExOP),
                               COREHALFWORD (mISHP))))))
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (8, mTRANSPARENT, bitRHS);
            bitRHS->inUse = 0;
          }
        break;
      case 1:
        // DO; (2037)
        {
        rs1s1:;
          // BIT_TYPE = TRUE; (2037)
          {
            int32_t numberRHS = (int32_t)(1);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (8, mBIT_TYPE, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF OP >  261 THEN (2038)
          if (1 & (xGT (COREHALFWORD (mSET_NONCOMMUTATIVExOP), 261)))
            // DO; (2039)
            {
            rs1s1s1:;
              // IF OP THEN (2040)
              if (1 & (bitToFixed (getBIT (16, mSET_NONCOMMUTATIVExOP))))
                // TRANSPARENT = TRUE; (2041)
                {
                  int32_t numberRHS = (int32_t)(1);
                  descriptor_t *bitRHS;
                  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                  putBIT (8, mTRANSPARENT, bitRHS);
                  bitRHS->inUse = 0;
                }
            es1s1s1:;
            } // End of DO block
          // ELSE (2042)
          else
            // IF OP >=  258 & OP <=  259 THEN (2043)
            if (1
                & (xAND (xGE (COREHALFWORD (mSET_NONCOMMUTATIVExOP), 258),
                         xLE (COREHALFWORD (mSET_NONCOMMUTATIVExOP), 259))))
              // NONCOMMUTATIVE = FALSE; (2044)
              {
                int32_t numberRHS = (int32_t)(0);
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (8, mSET_NONCOMMUTATIVExNONCOMMUTATIVE, bitRHS);
                bitRHS->inUse = 0;
              }
        es1s1:;
        } // End of DO block
        break;
      case 2:
          // ; (2046)
          ;
        break;
      case 3:
        // IF OP = MADD THEN (2047)
        if (1
            & (xEQ (COREHALFWORD (mSET_NONCOMMUTATIVExOP),
                    COREHALFWORD (mMADD))))
          {
          rs1s2:;
            // NONCOMMUTATIVE = FALSE; (2048)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (8, mSET_NONCOMMUTATIVExNONCOMMUTATIVE, bitRHS);
              bitRHS->inUse = 0;
            }
            // REVERSE_OP = MSUB; (2049)
            {
              descriptor_t *bitRHS = getBIT (16, mMSUB);
              putBIT (16, mREVERSE_OP, bitRHS);
              bitRHS->inUse = 0;
            }
          es1s2:;
          } // End of DO block
        break;
      case 4:
        // IF OP = VADD THEN (2051)
        if (1
            & (xEQ (COREHALFWORD (mSET_NONCOMMUTATIVExOP),
                    COREHALFWORD (mVADD))))
          {
          rs1s3:;
            // NONCOMMUTATIVE = FALSE; (2052)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (8, mSET_NONCOMMUTATIVExNONCOMMUTATIVE, bitRHS);
              bitRHS->inUse = 0;
            }
            // REVERSE_OP = VSUB; (2053)
            {
              descriptor_t *bitRHS = getBIT (16, mVSUB);
              putBIT (16, mREVERSE_OP, bitRHS);
              bitRHS->inUse = 0;
            }
          es1s3:;
          } // End of DO block
        break;
      case 5:
        // IF OP = SADD | OP = SSPR THEN (2055)
        if (1
            & (xOR (xEQ (COREHALFWORD (mSET_NONCOMMUTATIVExOP),
                         COREHALFWORD (mSADD)),
                    xEQ (COREHALFWORD (mSET_NONCOMMUTATIVExOP),
                         COREHALFWORD (mSSPR)))))
          {
          rs1s4:;
            // NONCOMMUTATIVE = FALSE; (2056)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (8, mSET_NONCOMMUTATIVExNONCOMMUTATIVE, bitRHS);
              bitRHS->inUse = 0;
            }
            // REVERSE_OP = OP + 1; (2057)
            {
              int32_t numberRHS
                  = (int32_t)(xadd (COREHALFWORD (mSET_NONCOMMUTATIVExOP), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mREVERSE_OP, bitRHS);
              bitRHS->inUse = 0;
            }
          es1s4:;
          } // End of DO block
        break;
      case 6:
        // IF OP = IADD | OP = IIPR THEN (2059)
        if (1
            & (xOR (xEQ (COREHALFWORD (mSET_NONCOMMUTATIVExOP),
                         COREHALFWORD (mIADD)),
                    xEQ (COREHALFWORD (mSET_NONCOMMUTATIVExOP),
                         COREHALFWORD (mIIPR)))))
          {
          rs1s5:;
            // NONCOMMUTATIVE = FALSE; (2060)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (8, mSET_NONCOMMUTATIVExNONCOMMUTATIVE, bitRHS);
              bitRHS->inUse = 0;
            }
            // REVERSE_OP = OP + 1; (2061)
            {
              int32_t numberRHS
                  = (int32_t)(xadd (COREHALFWORD (mSET_NONCOMMUTATIVExOP), 1));
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (16, mREVERSE_OP, bitRHS);
              bitRHS->inUse = 0;
            }
          es1s5:;
          } // End of DO block
        break;
      case 7:
        // TRANSPARENT = TRUE; (2063)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (8, mTRANSPARENT, bitRHS);
          bitRHS->inUse = 0;
        }
        break;
      case 8:
          // ; (2064)
          ;
        break;
      case 9:
          // ; (2065)
          ;
        break;
      case 10:
          // ; (2066)
          ;
        break;
      case 11:
          // ; (2067)
          ;
        break;
      case 12:
          // ; (2068)
          ;
        break;
      case 13:
          // ; (2069)
          ;
        break;
      case 14:
          // ; (2070)
          ;
        break;
      case 15:
        // DO; (2071)
        {
        rs1s6:;
          // REVERSE_OP = SHR(OK(OP &  255),1) |  3840; (2071)
          {
            int32_t numberRHS = (int32_t)(xOR (
                SHR (
                    BYTE0 (mOK
                           + 1
                                 * xAND (COREHALFWORD (mSET_NONCOMMUTATIVExOP),
                                         255)),
                    1),
                3840));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mREVERSE_OP, bitRHS);
            bitRHS->inUse = 0;
          }
          // TWIN_OP = REVERSE_OP ~=  3840; (2072)
          {
            int32_t numberRHS
                = (int32_t)(xNEQ (COREHALFWORD (mREVERSE_OP), 3840));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (8, mTWIN_OP, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s6:;
        } // End of DO block
        break;
      }
  } // End of DO CASE block
  // RETURN NONCOMMUTATIVE; (2073)
  {
    reentryGuard = 0;
    return BYTE0 (mSET_NONCOMMUTATIVExNONCOMMUTATIVE);
  }
}
