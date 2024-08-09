/*
  File COMPUTE_DIMENSIONS.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
COMPUTE_DIMENSIONS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "COMPUTE_DIMENSIONS");
  // TEMP = SYT_ARRAY(VAR); (3649)
  {
    descriptor_t *bitRHS = getBIT (
        16, getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mVAR)) + 20 + 2 * (0));
    putBIT (16, mCOMPUTE_DIMENSIONSxTEMP, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF TEMP = 0 THEN (3650)
  if (1 & (xEQ (COREHALFWORD (mCOMPUTE_DIMENSIONSxTEMP), 0)))
    // DIMENSIONS,ARRAY_DIMENSIONS = 0; (3651)
    {
      int32_t numberRHS = (int32_t)(0);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mDIMENSIONS, bitRHS);
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mARRAY_DIMENSIONS, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (3652)
  else
    // IF TEMP < 0 THEN (3653)
    if (1 & (xLT (COREHALFWORD (mCOMPUTE_DIMENSIONSxTEMP), 0)))
      // DO; (3654)
      {
      rs1:;
        // DIMENSIONS,ARRAY_DIMENSIONS = 1; (3655)
        {
          int32_t numberRHS = (int32_t)(1);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mDIMENSIONS, bitRHS);
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mARRAY_DIMENSIONS, bitRHS);
          bitRHS->inUse = 0;
        }
        // COMPONENT_SIZE(1) = 0; (3656)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mCOMPONENT_SIZE + 2 * (1), bitRHS);
          bitRHS->inUse = 0;
        }
      es1:;
      } // End of DO block
    // ELSE (3657)
    else
      // DO; (3658)
      {
      rs2:;
        // DIMENSIONS,ARRAY_DIMENSIONS = EXT_ARRAY(TEMP); (3659)
        {
          descriptor_t *bitRHS = getBIT (
              16, mEXT_ARRAY + 2 * COREHALFWORD (mCOMPUTE_DIMENSIONSxTEMP));
          putBIT (16, mDIMENSIONS, bitRHS);
          putBIT (16, mARRAY_DIMENSIONS, bitRHS);
          bitRHS->inUse = 0;
        }
        // DO FOR I = 1 TO DIMENSIONS; (3660)
        {
          int32_t from91, to91, by91;
          from91 = 1;
          to91 = bitToFixed (getBIT (16, mDIMENSIONS));
          by91 = 1;
          for (putBIT (16, mCOMPUTE_DIMENSIONSxI, fixedToBit (16, from91));
               bitToFixed (getBIT (16, mCOMPUTE_DIMENSIONSxI)) <= to91;
               putBIT (16, mCOMPUTE_DIMENSIONSxI,
                       fixedToBit (
                           16, bitToFixed (getBIT (16, mCOMPUTE_DIMENSIONSxI))
                                   + by91)))
            {
              // COMPONENT_SIZE(I) = EXT_ARRAY(TEMP + I); (3661)
              {
                descriptor_t *bitRHS = getBIT (
                    16,
                    mEXT_ARRAY
                        + 2
                              * xadd (COREHALFWORD (mCOMPUTE_DIMENSIONSxTEMP),
                                      COREHALFWORD (mCOMPUTE_DIMENSIONSxI)));
                putBIT (16,
                        mCOMPONENT_SIZE
                            + 2 * (COREHALFWORD (mCOMPUTE_DIMENSIONSxI)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
            }
        } // End of DO for-loop block
      es2:;
      } // End of DO block
  // IF VAR_TYPE = MAT_VAR THEN (3662)
  if (1 & (xEQ (COREHALFWORD (mVAR_TYPE), BYTE0 (mMAT_VAR))))
    // DO; (3663)
    {
    rs3:;
      // COMPONENT_SIZE(DIMENSIONS + 1) = SHR(SYT_DIMS(VAR),8); (3664)
      {
        int32_t numberRHS = (int32_t)(SHR (
            COREHALFWORD (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mVAR)) + 18
                          + 2 * (0)),
            8));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16,
                mCOMPONENT_SIZE + 2 * (xadd (COREHALFWORD (mDIMENSIONS), 1)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // COMPONENT_SIZE(DIMENSIONS + 2) = SYT_DIMS(VAR) &  255; (3665)
      {
        int32_t numberRHS = (int32_t)(xAND (
            COREHALFWORD (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mVAR)) + 18
                          + 2 * (0)),
            255));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16,
                mCOMPONENT_SIZE + 2 * (xadd (COREHALFWORD (mDIMENSIONS), 2)),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // DIMENSIONS = DIMENSIONS + 2; (3666)
      {
        int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mDIMENSIONS), 2));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mDIMENSIONS, bitRHS);
        bitRHS->inUse = 0;
      }
    es3:;
    } // End of DO block
  // ELSE (3667)
  else
    // IF VAR_TYPE = VEC_VAR THEN (3668)
    if (1 & (xEQ (COREHALFWORD (mVAR_TYPE), BYTE0 (mVEC_VAR))))
      // DO; (3669)
      {
      rs4:;
        // COMPONENT_SIZE(DIMENSIONS + 1) = SYT_DIMS(VAR); (3670)
        {
          descriptor_t *bitRHS
              = getBIT (16, getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mVAR))
                                + 18 + 2 * (0));
          putBIT (16,
                  mCOMPONENT_SIZE + 2 * (xadd (COREHALFWORD (mDIMENSIONS), 1)),
                  bitRHS);
          bitRHS->inUse = 0;
        }
        // DIMENSIONS = DIMENSIONS + 1; (3671)
        {
          int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mDIMENSIONS), 1));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mDIMENSIONS, bitRHS);
          bitRHS->inUse = 0;
        }
      es4:;
      } // End of DO block
  // IF SUB_TRACE THEN (3672)
  if (1 & (bitToFixed (getBIT (8, mSUB_TRACE))))
    // DO; (3673)
    {
    rs5:;
      // OUTPUT = 'COMPUTE_DIMENSIONS:  COMPONENT_SIZE = '; (3674)
      {
        descriptor_t *stringRHS;
        stringRHS
            = cToDescriptor (NULL, "COMPUTE_DIMENSIONS:  COMPONENT_SIZE = ");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // MSG1 = ''; (3675)
      {
        descriptor_t *stringRHS;
        stringRHS = cToDescriptor (NULL, "");
        putCHARACTER (mMSG1, stringRHS);
        stringRHS->inUse = 0;
      }
      // DO FOR I = 1 TO DIMENSIONS; (3676)
      {
        int32_t from92, to92, by92;
        from92 = 1;
        to92 = bitToFixed (getBIT (16, mDIMENSIONS));
        by92 = 1;
        for (putBIT (16, mCOMPUTE_DIMENSIONSxI, fixedToBit (16, from92));
             bitToFixed (getBIT (16, mCOMPUTE_DIMENSIONSxI)) <= to92;
             putBIT (16, mCOMPUTE_DIMENSIONSxI,
                     fixedToBit (
                         16, bitToFixed (getBIT (16, mCOMPUTE_DIMENSIONSxI))
                                 + by92)))
          {
            // MSG1 = MSG1 || COMPONENT_SIZE(I) || ','; (3677)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  xsCAT (getCHARACTER (mMSG1),
                         bitToCharacter (getBIT (
                             16,
                             mCOMPONENT_SIZE
                                 + 2 * COREHALFWORD (mCOMPUTE_DIMENSIONSxI)))),
                  cToDescriptor (NULL, ","));
              putCHARACTER (mMSG1, stringRHS);
              stringRHS->inUse = 0;
            }
          }
      } // End of DO for-loop block
      // OUTPUT = '   ' || MSG1; (3678)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (cToDescriptor (NULL, "   "), getCHARACTER (mMSG1));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es5:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
