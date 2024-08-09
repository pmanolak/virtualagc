/*
  File CHECK_ARRAYNESS.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
CHECK_ARRAYNESS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CHECK_ARRAYNESS");
  // CALL SET_VAR(K); (2596)
  {
    putBITp (16, mSET_VARxPTR, getBIT (16, mCHECK_ARRAYNESSxK));
    SET_VAR (0);
  }
  // MV = VAR_TYPE = MAT_VAR OR VAR_TYPE = VEC_VAR; (2597)
  {
    int32_t numberRHS
        = (int32_t)(xOR (xEQ (COREHALFWORD (mVAR_TYPE), BYTE0 (mMAT_VAR)),
                         xEQ (COREHALFWORD (mVAR_TYPE), BYTE0 (mVEC_VAR))));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mCHECK_ARRAYNESSxMV, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF (SYT_CLASS(VAR)=7) & (SYT_LINK2(VAR)~=0) &  (ASSIGN_OP) & (K>LOOP+1)
  // THEN (2598)
  if (1
      & (xAND (
          xAND (xAND (xEQ (BYTE0 (getFIXED (mSYM_TAB)
                                  + 34 * (COREHALFWORD (mVAR)) + 30 + 1 * (0)),
                           7),
                      xNEQ (COREHALFWORD (getFIXED (mSYM_TAB)
                                          + 34 * (COREHALFWORD (mVAR)) + 26
                                          + 2 * (0)),
                            0)),
                BYTE0 (mASSIGN_OP)),
          xGT (COREHALFWORD (mCHECK_ARRAYNESSxK),
               xadd (COREHALFWORD (mCHECK_ARRAYNESSxLOOP), 1)))))
    // DO; (2599)
    {
    rs1:;
      // I = VAR; (2600)
      {
        descriptor_t *bitRHS = getBIT (16, mVAR);
        putBIT (16, mCHECK_ARRAYNESSxI, bitRHS);
        bitRHS->inUse = 0;
      }
      // DO UNTIL SYT_LINK2(I)=0; (2601)
      do
        {
          // I = I - 1; (2602)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (COREHALFWORD (mCHECK_ARRAYNESSxI), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mCHECK_ARRAYNESSxI, bitRHS);
            bitRHS->inUse = 0;
          }
        }
      while (!(1
               & (xEQ (COREHALFWORD (getFIXED (mSYM_TAB)
                                     + 34 * (COREHALFWORD (mCHECK_ARRAYNESSxI))
                                     + 26 + 2 * (0)),
                       0)))); // End of DO UNTIL block
      // STRUC_TEMPL = I; (2603)
      {
        descriptor_t *bitRHS = getBIT (16, mCHECK_ARRAYNESSxI);
        putBIT (16, mSTRUC_TEMPL, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // IF (SYT_TYPE(VAR)=62) &  (ASSIGN_OP) & (K=LOOP+1) THEN (2604)
  if (1
      & (xAND (xAND (xEQ (BYTE0 (getFIXED (mSYM_TAB)
                                 + 34 * (COREHALFWORD (mVAR)) + 32 + 1 * (0)),
                          62),
                     BYTE0 (mASSIGN_OP)),
               xEQ (COREHALFWORD (mCHECK_ARRAYNESSxK),
                    xadd (COREHALFWORD (mCHECK_ARRAYNESSxLOOP), 1)))))
    // IF STRUC_TEMPL ~= 0  THEN (2605)
    if (1 & (xNEQ (COREHALFWORD (mSTRUC_TEMPL), 0)))
      // REF_TO_STRUC = TRUE; (2606)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (8, mREF_TO_STRUC, bitRHS);
        bitRHS->inUse = 0;
      }
  // ARRAYED = SYT_ARRAY(VAR) = 0; (2607)
  {
    int32_t numberRHS = (int32_t)(xEQ (
        COREHALFWORD (getFIXED (mSYM_TAB) + 34 * (COREHALFWORD (mVAR)) + 20
                      + 2 * (0)),
        0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mCHECK_ARRAYNESSxARRAYED, bitRHS);
    bitRHS->inUse = 0;
  }
  // LOOPE = LOOPY(LOOP); (2608)
  {
    int32_t numberRHS = (int32_t)((
        putBITp (16, mLOOPYxPTR, getBIT (16, mCHECK_ARRAYNESSxLOOP)),
        LOOPY (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mCHECK_ARRAYNESSxLOOPE, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF MV AND ARRAYED  THEN (2609)
  if (1
      & (xAND (BYTE0 (mCHECK_ARRAYNESSxMV), BYTE0 (mCHECK_ARRAYNESSxARRAYED))))
    // IF ASSIGN_OP AND K>=LOOP+2 AND IN_VM AND ~IN_AR THEN (2610)
    if (1
        & (xAND (
            xAND (xAND (BYTE0 (mASSIGN_OP),
                        xGE (COREHALFWORD (mCHECK_ARRAYNESSxK),
                             xadd (COREHALFWORD (mCHECK_ARRAYNESSxLOOP), 2))),
                  BYTE0 (mIN_VM)),
            xNOT (BYTE0 (mIN_AR)))))
      // CALL BUMP_REF_OPS(K,1); (2611)
      {
        putBITp (16, mBUMP_REF_OPSxPTR, getBIT (16, mCHECK_ARRAYNESSxK));
        putBITp (8, mBUMP_REF_OPSxASSIGN_FLAG, fixedToBit (32, (int32_t)(1)));
        BUMP_REF_OPS (0);
      }
    // ELSE (2612)
    else
      // IF (~ASSIGN_OP AND (~LOOPE OR (IN_AR AND IN_VM))) THEN (2613)
      if (1
          & (xAND (xNOT (BYTE0 (mASSIGN_OP)),
                   xOR (xNOT (COREHALFWORD (mCHECK_ARRAYNESSxLOOPE)),
                        xAND (BYTE0 (mIN_AR), BYTE0 (mIN_VM))))))
        // CALL BUMP_REF_OPS(K,0); (2614)
        {
          putBITp (16, mBUMP_REF_OPSxPTR, getBIT (16, mCHECK_ARRAYNESSxK));
          putBITp (8, mBUMP_REF_OPSxASSIGN_FLAG,
                   fixedToBit (32, (int32_t)(0)));
          BUMP_REF_OPS (0);
        }
      // ELSE (2615)
      else
        // IF ASSIGN_OP AND K=LOOP+1 AND IN_AR AND IN_VM THEN (2616)
        if (1
            & (xAND (
                xAND (xAND (BYTE0 (mASSIGN_OP),
                            xEQ (COREHALFWORD (mCHECK_ARRAYNESSxK),
                                 xadd (COREHALFWORD (mCHECK_ARRAYNESSxLOOP),
                                       1))),
                      BYTE0 (mIN_AR)),
                BYTE0 (mIN_VM))))
          // CALL BUMP_REF_OPS(K,0); (2617)
          {
            putBITp (16, mBUMP_REF_OPSxPTR, getBIT (16, mCHECK_ARRAYNESSxK));
            putBITp (8, mBUMP_REF_OPSxASSIGN_FLAG,
                     fixedToBit (32, (int32_t)(0)));
            BUMP_REF_OPS (0);
          }
  // IF IN_VM THEN (2618)
  if (1 & (bitToFixed (getBIT (8, mIN_VM))))
    // IF MV = ARRAYED THEN (2619)
    if (1
        & (xEQ (BYTE0 (mCHECK_ARRAYNESSxMV),
                BYTE0 (mCHECK_ARRAYNESSxARRAYED))))
      // DO; (2620)
      {
      rs2:;
        // NESTED_VM = FALSE; (2621)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (8, mNESTED_VM, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF C_TRACE THEN (2622)
        if (1 & (bitToFixed (getBIT (8, mC_TRACE))))
          // OUTPUT = 'CHECK_ARRAYNESS(' || K||') = 1'; (2623)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                xsCAT (cToDescriptor (NULL, "CHECK_ARRAYNESS("),
                       bitToCharacter (getBIT (16, mCHECK_ARRAYNESSxK))),
                cToDescriptor (NULL, ") = 1"));
            OUTPUT (0, stringRHS);
            stringRHS->inUse = 0;
          }
      es2:;
      } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
