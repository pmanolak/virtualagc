/*
  File GENERATExBIT_STORExMAKE_BIT_OP.c generated by XCOM-I, 2024-08-09
  12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExBIT_STORExMAKE_BIT_OP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExBIT_STORExMAKE_BIT_OP");
  // CALL RETURN_STACK_ENTRY(TOP); (7555)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
             getBIT (16, mGENERATExBIT_STORExTOP));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  // IF SHORTLIT THEN (7556)
  if (1 & (bitToFixed (getBIT (1, mGENERATExBIT_STORExSHORTLIT))))
    // DO; (7557)
    {
    rs1:;
      // IF VAL(ROP) = 0 THEN (7558)
      if (1
          & (xEQ (getFIXED (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExBIT_STORExROP))
                            + 12 + 4 * (0)),
                  0)))
        // TMP = AND; (7559)
        {
          descriptor_t *bitRHS = getBIT (16, mGENERATExAND);
          int32_t numberRHS;
          numberRHS = bitToFixed (bitRHS);
          putFIXED (mTMP, numberRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (7560)
      else
        // TMP = XOR; (7561)
        {
          descriptor_t *bitRHS = getBIT (8, mXOR);
          int32_t numberRHS;
          numberRHS = bitToFixed (bitRHS);
          putFIXED (mTMP, numberRHS);
          bitRHS->inUse = 0;
        }
      // TOP, LOP = MAKE_BIT_LIT(TMP, VAL(ROP), OP); (7562)
      {
        descriptor_t *bitRHS
            = (putBITp (16, mGENERATExMAKE_BIT_LITxOPC,
                        fixedToBit (32, (int32_t)(getFIXED (mTMP)))),
               putFIXED (
                   mGENERATExMAKE_BIT_LITxVALUE,
                   getFIXED (getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mGENERATExBIT_STORExROP))
                             + 12 + 4 * (0))),
               putBITp (16, mGENERATExMAKE_BIT_LITxOP,
                        getBIT (16, mGENERATExBIT_STORExOP)),
               GENERATExMAKE_BIT_LIT (0));
        putBIT (16, mGENERATExBIT_STORExTOP, bitRHS);
        putBIT (16, mGENERATExBIT_STORExLOP, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (7563)
  else
    // DO; (7564)
    {
    rs2:;
      // TMP = DEL(ROP); (7565)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExBIT_STORExROP))
                              + 28 + 2 * (0));
        int32_t numberRHS;
        numberRHS = bitToFixed (bitRHS);
        putFIXED (mTMP, numberRHS);
        bitRHS->inUse = 0;
      }
      // TOP, LOP = MAKE_BIT_LIT(TMP, CONST(ROP), OP); (7566)
      {
        descriptor_t *bitRHS
            = (putBITp (16, mGENERATExMAKE_BIT_LITxOPC,
                        fixedToBit (32, (int32_t)(getFIXED (mTMP)))),
               putFIXED (
                   mGENERATExMAKE_BIT_LITxVALUE,
                   getFIXED (getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mGENERATExBIT_STORExROP))
                             + 0 + 4 * (0))),
               putBITp (16, mGENERATExMAKE_BIT_LITxOP,
                        getBIT (16, mGENERATExBIT_STORExOP)),
               GENERATExMAKE_BIT_LIT (0));
        putBIT (16, mGENERATExBIT_STORExTOP, bitRHS);
        putBIT (16, mGENERATExBIT_STORExLOP, bitRHS);
        bitRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
