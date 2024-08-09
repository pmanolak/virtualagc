/*
  File SET_V_M_TAGS.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
SET_V_M_TAGS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SET_V_M_TAGS");
  // INX = N_INX; (2651)
  {
    descriptor_t *bitRHS = getBIT (16, mN_INX);
    putBIT (16, mSET_V_M_TAGSxINX, bitRHS);
    bitRHS->inUse = 0;
  }
  // NODE,A_PARITY = 0; (2652)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mNODE, numberRHS);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mA_PARITY, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE SHR(NODE(INX),16) > PTR; (2653)
  while (1
         & (xGT (
             SHR (getFIXED (mNODE + 4 * COREHALFWORD (mSET_V_M_TAGSxINX)), 16),
             COREHALFWORD (mSET_V_M_TAGSxPTR))))
    {
      // INX = INX - 1; (2654)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (COREHALFWORD (mSET_V_M_TAGSxINX), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSET_V_M_TAGSxINX, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // DO WHILE INX > 0 AND ((NODE(INX) &  65535) > PTR OR A_PARITY(INX) & CSE);
  // (2655)
  while (
      1
      & (xAND (
          xGT (COREHALFWORD (mSET_V_M_TAGSxINX), 0),
          xOR (xGT (xAND (getFIXED (mNODE
                                    + 4 * COREHALFWORD (mSET_V_M_TAGSxINX)),
                          65535),
                    COREHALFWORD (mSET_V_M_TAGSxPTR)),
               xAND (BYTE0 (mA_PARITY + 1 * COREHALFWORD (mSET_V_M_TAGSxINX)),
                     BYTE0 (mSET_V_M_TAGSxCSE))))))
    {
      // IF ~(CSE & A_PARITY(INX)) AND (NODE(INX) &  65535) > PTR THEN (2656)
      if (1
          & (xAND (
              xNOT (xAND (
                  BYTE0 (mSET_V_M_TAGSxCSE),
                  BYTE0 (mA_PARITY + 1 * COREHALFWORD (mSET_V_M_TAGSxINX)))),
              xGT (xAND (
                       getFIXED (mNODE + 4 * COREHALFWORD (mSET_V_M_TAGSxINX)),
                       65535),
                   COREHALFWORD (mSET_V_M_TAGSxPTR)))))
        // DO; (2657)
        {
        rs2s1:;
          // I = LAST_OPERAND(SHR(NODE(INX),16)); (2658)
          {
            descriptor_t *bitRHS
                = (putBITp (
                       16, mLAST_OPERANDxPTR,
                       fixedToBit (
                           32, (int32_t)(SHR (
                                   getFIXED (
                                       mNODE
                                       + 4 * COREHALFWORD (mSET_V_M_TAGSxINX)),
                                   16)))),
                   LAST_OPERAND (0));
            putBIT (16, mSET_V_M_TAGSxI, bitRHS);
            bitRHS->inUse = 0;
          }
          // OPR(I) = OPR(I) | OUTSIDE_REF_TAG; (2659)
          {
            int32_t numberRHS = (int32_t)(xOR (
                getFIXED (mOPR + 4 * COREHALFWORD (mSET_V_M_TAGSxI)),
                COREHALFWORD (mOUTSIDE_REF_TAG)));
            putFIXED (mOPR + 4 * (COREHALFWORD (mSET_V_M_TAGSxI)), numberRHS);
          }
          // IF CSE THEN (2660)
          if (1 & (bitToFixed (getBIT (8, mSET_V_M_TAGSxCSE))))
            // OPR(PTR) = OPR(PTR) | OUT_OF_ARRAY_TAG; (2661)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  getFIXED (mOPR + 4 * COREHALFWORD (mSET_V_M_TAGSxPTR)),
                  COREHALFWORD (mOUT_OF_ARRAY_TAG)));
              putFIXED (mOPR + 4 * (COREHALFWORD (mSET_V_M_TAGSxPTR)),
                        numberRHS);
            }
          // ELSE (2662)
          else
            // OPR(PTR) = OPR(PTR) | TAG_BIT; (2663)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  getFIXED (mOPR + 4 * COREHALFWORD (mSET_V_M_TAGSxPTR)),
                  getFIXED (mTAG_BIT)));
              putFIXED (mOPR + 4 * (COREHALFWORD (mSET_V_M_TAGSxPTR)),
                        numberRHS);
            }
          // IF C_TRACE THEN (2664)
          if (1 & (bitToFixed (getBIT (8, mC_TRACE))))
            // OUTPUT = 'SET_V_M_TAGS:  ' ||I || ',' || PTR; (2665)
            {
              descriptor_t *stringRHS;
              stringRHS = xsCAT (
                  xsCAT (xsCAT (cToDescriptor (NULL, "SET_V_M_TAGS:  "),
                                bitToCharacter (getBIT (16, mSET_V_M_TAGSxI))),
                         cToDescriptor (NULL, ",")),
                  bitToCharacter (getBIT (16, mSET_V_M_TAGSxPTR)));
              OUTPUT (0, stringRHS);
              stringRHS->inUse = 0;
            }
          // RETURN; (2666)
          {
            reentryGuard = 0;
            return 0;
          }
        es2s1:;
        } // End of DO block
      // INX = INX - 1; (2667)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (COREHALFWORD (mSET_V_M_TAGSxINX), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mSET_V_M_TAGSxINX, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  {
    reentryGuard = 0;
    return 0;
  }
}
