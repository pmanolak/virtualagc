/*
  File GENERATExMAKE_INST.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExMAKE_INST (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExMAKE_INST");
  // RETURN ARITH_OP(OPCODE) + MODE_MOD(OPMODE(OPTYPE)+OPFORM); (3254)
  {
    reentryGuard = 0;
    return fixedToBit (
        32,
        (int32_t)(xadd (
            COREHALFWORD (mGENERATExARITH_OP
                          + 2 * COREHALFWORD (mGENERATExMAKE_INSTxOPCODE)),
            COREHALFWORD (
                mGENERATExMODE_MOD
                + 2
                      * xadd (
                          BYTE0 (
                              mOPMODE
                              + 1 * COREHALFWORD (mGENERATExMAKE_INSTxOPTYPE)),
                          COREHALFWORD (mGENERATExMAKE_INSTxOPFORM))))));
  }
}
