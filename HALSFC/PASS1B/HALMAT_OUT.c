/*
  File HALMAT_OUT.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
HALMAT_OUT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "HALMAT_OUT");
  // IF ATOM#_FAULT<0 THEN (7191)
  if (1 & (xLT (getFIXED (mATOMp_FAULT), 0)))
    // ATOM#_FAULT=NEXT_ATOM#-1; (7192)
    {
      int32_t numberRHS = (int32_t)(xsubtract (getFIXED (mNEXT_ATOMp), 1));
      putFIXED (mATOMp_FAULT, numberRHS);
    }
  // ELSE (7193)
  else
    // DO; (7194)
    {
    rs1:;
      // NEXT_ATOM# = 2; (7195)
      {
        int32_t numberRHS = (int32_t)(2);
        putFIXED (mNEXT_ATOMp, numberRHS);
      }
      // IF HALMAT_RELOCATE_FLAG THEN (7196)
      if (1 & (bitToFixed (getBIT (1, mHALMAT_RELOCATE_FLAG))))
        // RETURN; (7197)
        {
          reentryGuard = 0;
          return 0;
        }
      // SAVE_ATOM=ATOMS(ATOM#_FAULT); (7198)
      {
        int32_t numberRHS = (int32_t)(getFIXED (getFIXED (mFOR_ATOMS)
                                                + 4 * (getFIXED (mATOMp_FAULT))
                                                + 0 + 4 * (0)));
        putFIXED (mHALMAT_OUTxSAVE_ATOM, numberRHS);
      }
      // ATOMS(ATOM#_FAULT)=SHL(XXREC,4); (7199)
      {
        int32_t numberRHS = (int32_t)(SHL (COREHALFWORD (mXXREC), 4));
        putFIXED (getFIXED (mFOR_ATOMS) + 4 * (getFIXED (mATOMp_FAULT)) + 0
                      + 4 * (0),
                  numberRHS);
      }
    es1:;
    } // End of DO block
  // ATOMS(1) = SHL(ATOM#_FAULT, 16) | 1; (7200)
  {
    int32_t numberRHS = (int32_t)(xOR (SHL (getFIXED (mATOMp_FAULT), 16), 1));
    putFIXED (getFIXED (mFOR_ATOMS) + 4 * (1) + 0 + 4 * (0), numberRHS);
  }
  // IF CONTROL(11) THEN (7201)
  if (1 & (bitToFixed (getBIT (1, mCONTROL + 1 * 11))))
    // DO; (7202)
    {
    rs2:;
      // EJECT_PAGE; (7203)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mPAGE);
        OUTPUT (1, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT='         *** HALMAT BLOCK '||HALMAT_BLOCK||' ***'; (7204)
      {
        descriptor_t *stringRHS;
        stringRHS
            = xsCAT (xsCAT (cToDescriptor (NULL, "         *** HALMAT BLOCK "),
                            bitToCharacter (getBIT (16, mHALMAT_BLOCK))),
                     cToDescriptor (NULL, " ***"));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // DOUBLE_SPACE; (7205)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mDOUBLE);
        OUTPUT (1, stringRHS);
        stringRHS->inUse = 0;
      }
      // DO I= 0 TO ATOM#_FAULT; (7206)
      {
        int32_t from117, to117, by117;
        from117 = 0;
        to117 = getFIXED (mATOMp_FAULT);
        by117 = 1;
        for (putBIT (16, mHALMAT_OUTxI, fixedToBit (16, from117));
             bitToFixed (getBIT (16, mHALMAT_OUTxI)) <= to117;
             putBIT (16, mHALMAT_OUTxI,
                     fixedToBit (16, bitToFixed (getBIT (16, mHALMAT_OUTxI))
                                         + by117)))
          {
            // CALL HALMAT_BLAB(ATOMS(I),I); (7207)
            {
              putFIXED (mHALMAT_BLABxANY_ATOM,
                        getFIXED (getFIXED (mFOR_ATOMS)
                                  + 4 * (COREHALFWORD (mHALMAT_OUTxI)) + 0
                                  + 4 * (0)));
              putFIXED (mHALMAT_BLABxI, COREHALFWORD (mHALMAT_OUTxI));
              HALMAT_BLAB (0);
            }
          }
      } // End of DO for-loop block
    es2:;
    } // End of DO block
  // FILE(HALMAT_FILE,HALMAT_BLOCK) = ATOMS(0); (7208)
  {
    lFILE (1, COREHALFWORD (mHALMAT_BLOCK),
           ADDR ("FOR_ATOMS", 0, "CONST_ATOMS", 0));
  }
  // HALMAT_BLOCK=HALMAT_BLOCK+1; (7209)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mHALMAT_BLOCK), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mHALMAT_BLOCK, bitRHS);
    bitRHS->inUse = 0;
  }
  // ATOMS(ATOM#_FAULT)=SAVE_ATOM; (7210)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mHALMAT_OUTxSAVE_ATOM));
    putFIXED (getFIXED (mFOR_ATOMS) + 4 * (getFIXED (mATOMp_FAULT)) + 0
                  + 4 * (0),
              numberRHS);
  }
  // HALMAT_RELOCATE_FLAG=TRUE; (7211)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mHALMAT_RELOCATE_FLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
