/*
  File GENERATExGEN_CLASS6xINTEGER_MULTIPLYxDO_MR.c generated by XCOM-I,
  2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS6xINTEGER_MULTIPLYxDO_MR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard,
                               "GENERATExGEN_CLASS6xINTEGER_MULTIPLYxDO_MR");
  // CALL SET_LEFTOP_REG(OP1); (13543)
  {
    putBITp (16, mGENERATExGEN_CLASS6xINTEGER_MULTIPLYxSET_LEFTOP_REGxOP,
             getBIT (16, mGENERATExGEN_CLASS6xINTEGER_MULTIPLYxDO_MRxOP1));
    GENERATExGEN_CLASS6xINTEGER_MULTIPLYxSET_LEFTOP_REG (0);
  }
  // CALL EMITRR(MR, REG(OP1), REG(OP2)); (13544)
  {
    putBITp (16, mGENERATExEMITRRxINST, getBIT (8, mMR));
    putBITp (
        16, mGENERATExEMITRRxREG1,
        getBIT (16,
                getFIXED (mIND_STACK)
                    + 73
                          * (COREHALFWORD (
                              mGENERATExGEN_CLASS6xINTEGER_MULTIPLYxDO_MRxOP1))
                    + 46 + 2 * (0)));
    putBITp (
        16, mGENERATExEMITRRxREG2,
        getBIT (16,
                getFIXED (mIND_STACK)
                    + 73
                          * (COREHALFWORD (
                              mGENERATExGEN_CLASS6xINTEGER_MULTIPLYxDO_MRxOP2))
                    + 46 + 2 * (0)));
    GENERATExEMITRR (0);
  }
  // CALL DROP_REG(OP2); (13545)
  {
    putBITp (16, mGENERATExDROP_REGxOP,
             getBIT (16, mGENERATExGEN_CLASS6xINTEGER_MULTIPLYxDO_MRxOP2));
    GENERATExDROP_REG (0);
  }
  // CALL SET_RESULT_REG(OP1, OP2); (13546)
  {
    putBITp (16, mGENERATExGEN_CLASS6xINTEGER_MULTIPLYxSET_RESULT_REGxOP1,
             getBIT (16, mGENERATExGEN_CLASS6xINTEGER_MULTIPLYxDO_MRxOP1));
    putBITp (16, mGENERATExGEN_CLASS6xINTEGER_MULTIPLYxSET_RESULT_REGxOP2,
             getBIT (16, mGENERATExGEN_CLASS6xINTEGER_MULTIPLYxDO_MRxOP2));
    GENERATExGEN_CLASS6xINTEGER_MULTIPLYxSET_RESULT_REG (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
