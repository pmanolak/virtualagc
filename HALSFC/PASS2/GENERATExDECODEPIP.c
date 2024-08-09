/*
  File GENERATExDECODEPIP.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExDECODEPIP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExDECODEPIP");
  // OP=OP+CTR; (2731)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mGENERATExDECODEPIPxOP),
                                        COREHALFWORD (mCTR)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExDECODEPIPxOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // OP1=SHR(OPR(OP),16); (2732)
  {
    int32_t numberRHS = (int32_t)(SHR (
        getFIXED (getFIXED (mFOR_ATOMS)
                  + 4 * (COREHALFWORD (mGENERATExDECODEPIPxOP)) + 0 + 4 * (0)),
        16));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOP1, bitRHS);
    bitRHS->inUse = 0;
  }
  // TAG1=SHR(OPR(OP),4)& 15; (2733)
  {
    int32_t numberRHS = (int32_t)(xAND (
        SHR (getFIXED (getFIXED (mFOR_ATOMS)
                       + 4 * (COREHALFWORD (mGENERATExDECODEPIPxOP)) + 0
                       + 4 * (0)),
             4),
        15));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mTAG1, bitRHS);
    bitRHS->inUse = 0;
  }
  // TAG2(N)=SHR(OPR(OP),1)& 7; (2734)
  {
    int32_t numberRHS = (int32_t)(xAND (
        SHR (getFIXED (getFIXED (mFOR_ATOMS)
                       + 4 * (COREHALFWORD (mGENERATExDECODEPIPxOP)) + 0
                       + 4 * (0)),
             1),
        7));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mTAG2 + 2 * (COREHALFWORD (mGENERATExDECODEPIPxN)), bitRHS);
    bitRHS->inUse = 0;
  }
  // TAG3(N)=SHR(OPR(OP),8)& 255; (2735)
  {
    int32_t numberRHS = (int32_t)(xAND (
        SHR (getFIXED (getFIXED (mFOR_ATOMS)
                       + 4 * (COREHALFWORD (mGENERATExDECODEPIPxOP)) + 0
                       + 4 * (0)),
             8),
        255));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mTAG3 + 2 * (COREHALFWORD (mGENERATExDECODEPIPxN)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IF HALMAT_REQUESTED THEN (2736)
  if (1 & (bitToFixed (getBIT (1, mHALMAT_REQUESTED))))
    // DO; (2737)
    {
    rs1:;
      // MESSAGE=FORMAT(TAG3(N),3)||COMMA||TAG2(N)||' :'||CURCBLK-1||'.'||OP;
      // (2738)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (
                xsCAT (
                    xsCAT (
                        xsCAT (
                            xsCAT ((putFIXED (
                                        mFORMATxIVAL,
                                        COREHALFWORD (
                                            mTAG3
                                            + 2
                                                  * COREHALFWORD (
                                                      mGENERATExDECODEPIPxN))),
                                    putFIXED (mFORMATxN, 3), FORMAT (0)),
                                   getCHARACTER (mCOMMA)),
                            bitToCharacter (getBIT (
                                16, mTAG2
                                        + 2
                                              * COREHALFWORD (
                                                  mGENERATExDECODEPIPxN)))),
                        cToDescriptor (NULL, " :")),
                    fixedToCharacter (xsubtract (BYTE0 (mCURCBLK), 1))),
                cToDescriptor (NULL, ".")),
            bitToCharacter (getBIT (16, mGENERATExDECODEPIPxOP)));
        putCHARACTER (mMESSAGE, stringRHS);
        stringRHS->inUse = 0;
      }
      // MESSAGE=FORMAT(TAG1,2)||'),'||MESSAGE; (2739)
      {
        descriptor_t *stringRHS;
        stringRHS
            = xsCAT (xsCAT ((putFIXED (mFORMATxIVAL, COREHALFWORD (mTAG1)),
                             putFIXED (mFORMATxN, 2), FORMAT (0)),
                            cToDescriptor (NULL, "),")),
                     getCHARACTER (mMESSAGE));
        putCHARACTER (mMESSAGE, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT=FORMAT(OP1,20)||LEFTBRACKET||MESSAGE; (2740)
      {
        descriptor_t *stringRHS;
        stringRHS
            = xsCAT (xsCAT ((putFIXED (mFORMATxIVAL, COREHALFWORD (mOP1)),
                             putFIXED (mFORMATxN, 20), FORMAT (0)),
                            getCHARACTER (mLEFTBRACKET)),
                     getCHARACTER (mMESSAGE));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // N = 0; (2741)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExDECODEPIPxN, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
