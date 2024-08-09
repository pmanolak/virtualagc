/*
  File SEARCH_EXPRESSIONxDO_OPERAND.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

int32_t
SEARCH_EXPRESSIONxDO_OPERAND (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SEARCH_EXPRESSIONxDO_OPERAND");
  // DO CASE TYPE_BITS(OPERAND); (1513)
  {
  rs1:
    switch (bitToFixed (
        (putBITp (16, mTYPE_BITSxCTR,
                  getBIT (16, mSEARCH_EXPRESSIONxDO_OPERANDxOPERAND)),
         TYPE_BITS (0))))
      {
      case 0:
          // ; (1515)
          ;
        break;
      case 1:
        // DO; (1516)
        {
        rs1s1:;
          // VAR_INX = VAR_INX + 1; (1516)
          {
            int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mVAR_INX), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mVAR_INX, bitRHS);
            bitRHS->inUse = 0;
          }
          // EXP_VARS(VAR_INX) = SHR(OPR(OPERAND),16); (1517)
          {
            int32_t numberRHS = (int32_t)(SHR (
                getFIXED (mOPR
                          + 4
                                * COREHALFWORD (
                                    mSEARCH_EXPRESSIONxDO_OPERANDxOPERAND)),
                16));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mEXP_VARS + 2 * (COREHALFWORD (mVAR_INX)), bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
        break;
      case 2:
          // ; (1519)
          ;
        break;
      case 3:
        // CALL BUMP_VAC(OPERAND); (1520)
        {
          putBITp (16, mSEARCH_EXPRESSIONxBUMP_VACxOPERAND,
                   getBIT (16, mSEARCH_EXPRESSIONxDO_OPERANDxOPERAND));
          SEARCH_EXPRESSIONxBUMP_VAC (0);
        }
        break;
      case 4:
        // CALL PROCESS_EXTN(SHR(OPR(OPERAND),16)); (1521)
        {
          putBITp (
              16, mPROCESS_EXTNxCTR,
              fixedToBit (
                  32,
                  (int32_t)(SHR (
                      getFIXED (
                          mOPR
                          + 4
                                * COREHALFWORD (
                                    mSEARCH_EXPRESSIONxDO_OPERANDxOPERAND)),
                      16))));
          PROCESS_EXTN (0);
        }
        break;
      case 5:
          // ; (1522)
          ;
        break;
      case 6:
          // ; (1523)
          ;
        break;
      case 7:
          // ; (1524)
          ;
        break;
      case 8:
          // ; (1525)
          ;
        break;
      case 9:
          // ; (1526)
          ;
        break;
      case 10:
          // ; (1527)
          ;
        break;
      case 11:
          // ; (1528)
          ;
        break;
      }
  } // End of DO CASE block
  {
    reentryGuard = 0;
    return 0;
  }
}
