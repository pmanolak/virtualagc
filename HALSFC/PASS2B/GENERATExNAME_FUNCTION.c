/*
  File GENERATExNAME_FUNCTION.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExNAME_FUNCTION (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExNAME_FUNCTION");
  // IF (HALMAT_OPCODE = XNNEQ) | (HALMAT_OPCODE = XNEQU) | (HALMAT_OPCODE =
  // XNASN) THEN (2733)
  if (1
      & (xOR (xOR (xEQ (COREHALFWORD (mHALMAT_OPCODE), 85),
                   xEQ (COREHALFWORD (mHALMAT_OPCODE), 86)),
              xEQ (COREHALFWORD (mHALMAT_OPCODE), 87))))
    // RETURN TRUE; (2734)
    {
      reentryGuard = 0;
      return fixedToBit (32, (int32_t)(1));
    }
  // IF (HALMAT_OPCODE = XPMAR) THEN (2735)
  if (1 & (xEQ (COREHALFWORD (mHALMAT_OPCODE), 90)))
    // DO ; (2736)
    {
    rs1:;
      // IF (PMINDEX = NCOPY_TAG) | ( (PMINDEX = NADD_TAG) &
      // ((ARG_STACK_PTR-SAVE_ARG_STACK_PTR) ~= 2) )  THEN (2737)
      if (1
          & (xOR (xEQ (COREHALFWORD (mPMINDEX), 3),
                  xAND (xEQ (COREHALFWORD (mPMINDEX), 6),
                        xNEQ (xsubtract (
                                  COREHALFWORD (mARG_STACK_PTR),
                                  COREHALFWORD (mGENERATExSAVE_ARG_STACK_PTR)),
                              2)))))
        // RETURN TRUE; (2738)
        {
          reentryGuard = 0;
          return fixedToBit (32, (int32_t)(1));
        }
    es1:;
    } // End of DO block
  // IF (HALMAT_OPCODE = XPMIN) THEN (2739)
  if (1 & (xEQ (COREHALFWORD (mHALMAT_OPCODE), 91)))
    // DO ; (2740)
    {
    rs2:;
      // IF (TAG = NCOPY_TAG) | ( (TAG = NADD_TAG) &  (OP ~=
      // ARG_STACK(SAVE_ARG_STACK_PTR+2)) )  THEN (2741)
      if (1
          & (xOR (
              xEQ (COREHALFWORD (mTAG), 3),
              xAND (xEQ (COREHALFWORD (mTAG), 6),
                    xNEQ (COREHALFWORD (mGENERATExNAME_FUNCTIONxOP),
                          COREHALFWORD (
                              mGENERATExARG_STACK
                              + 2
                                    * xadd (COREHALFWORD (
                                                mGENERATExSAVE_ARG_STACK_PTR),
                                            2)))))))
        // RETURN TRUE; (2742)
        {
          reentryGuard = 0;
          return fixedToBit (32, (int32_t)(1));
        }
    es2:;
    } // End of DO block
  // IF (HALMAT_OPCODE = XDSUB) & NAME_SUB THEN (2743)
  if (1
      & (xAND (xEQ (COREHALFWORD (mHALMAT_OPCODE), 25),
               BYTE0 (mGENERATExNAME_SUB))))
    // IF TAG1=6 | (TAG3 ~= 5 & TAG3 ~= 1) THEN (2744)
    if (1
        & (xOR (xEQ (COREHALFWORD (mTAG1), 6),
                xAND (xNEQ (COREHALFWORD (mTAG3), 5),
                      xNEQ (COREHALFWORD (mTAG3), 1)))))
      // RETURN TRUE; (2745)
      {
        reentryGuard = 0;
        return fixedToBit (32, (int32_t)(1));
      }
  // IF (HALMAT_OPCODE = XXXAR) THEN (2746)
  if (1 & (xEQ (COREHALFWORD (mHALMAT_OPCODE), 39)))
    // DO; (2747)
    {
    rs3:;
      // IF ARG_NAME(ARG_STACK_PTR) THEN (2748)
      if (1
          & (bitToFixed (getBIT (1, mGENERATExARG_NAME
                                        + 1 * COREHALFWORD (mARG_STACK_PTR)))))
        // RETURN TRUE; (2749)
        {
          reentryGuard = 0;
          return fixedToBit (32, (int32_t)(1));
        }
    es3:;
    } // End of DO block
  // IF (HALMAT_OPCODE = XPCAL) | (HALMAT_OPCODE = XFCAL) THEN (2750)
  if (1
      & (xOR (xEQ (COREHALFWORD (mHALMAT_OPCODE), 29),
              xEQ (COREHALFWORD (mHALMAT_OPCODE), 30))))
    // DO; (2751)
    {
    rs4:;
      // IF ARG_NAME(ARG#) THEN (2752)
      if (1
          & (bitToFixed (
              getBIT (1, mGENERATExARG_NAME + 1 * COREHALFWORD (mARGp)))))
        // RETURN TRUE; (2753)
        {
          reentryGuard = 0;
          return fixedToBit (32, (int32_t)(1));
        }
    es4:;
    } // End of DO block
  // RETURN FALSE; (2754)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}