/*
  File GENERATExERRCALL.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExERRCALL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExERRCALL");
  // IF CALL#(PROGPOINT) = 2 THEN (4796)
  if (1 & (xEQ (BYTE0 (mCALLp + 1 * COREHALFWORD (mPROGPOINT)), 2)))
    // RETURN; (4797)
    {
      reentryGuard = 0;
      return 0;
    }
  // VAL(0) = SHL(20 , 16) + SHL(4 , 8) + ERR#; (4798)
  {
    int32_t numberRHS
        = (int32_t)(xadd (xadd (SHL (20, 16), SHL (4, 8)),
                          COREHALFWORD (mGENERATExERRCALLxERRp)));
    putFIXED (getFIXED (mIND_STACK) + 73 * (0) + 12 + 4 * (0), numberRHS);
  }
  // INX(0), INX_CON(0) = 0; (4799)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (16, getFIXED (mIND_STACK) + 73 * (0) + 34 + 2 * (0),
            fixedToBit (16, numberRHS));
    putFIXED (getFIXED (mIND_STACK) + 73 * (0) + 4 + 4 * (0), numberRHS);
  }
  // CALL SAVE_LITERAL(0,DINTEGER); (4800)
  {
    putBITp (16, mGENERATExSAVE_LITERALxOP, fixedToBit (32, (int32_t)(0)));
    putBITp (16, mGENERATExSAVE_LITERALxOPTYPE, getBIT (8, mDINTEGER));
    GENERATExSAVE_LITERAL (0);
  }
  // CALL EMITOP(SVC, 0, 0); (4801)
  {
    putBITp (16, mGENERATExEMITOPxINST, getBIT (8, mSVC));
    putBITp (16, mGENERATExEMITOPxXREG, fixedToBit (32, (int32_t)(0)));
    putBITp (16, mGENERATExEMITOPxOP, fixedToBit (32, (int32_t)(0)));
    GENERATExEMITOP (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
