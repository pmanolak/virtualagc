/*
  File ARITH_TO_CHAR.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
ARITH_TO_CHAR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ARITH_TO_CHAR");
  // TEMP=SCALAR_TYPE; (7703)
  {
    int32_t numberRHS = (int32_t)(5);
    putFIXED (mTEMP, numberRHS);
  }
  // DO CASE PSEUDO_TYPE(PTR(I))-MAT_TYPE; (7704)
  {
  rs1:
    switch (xsubtract (
        BYTE0 (
            mPSEUDO_TYPE
            + 1 * COREHALFWORD (mPTR + 2 * COREHALFWORD (mARITH_TO_CHARxI))),
        3))
      {
      case 0:
        // CALL ERROR(CLASS_EM,2); (7706)
        {
          putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_EM));
          putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(2)));
          ERROR (0);
        }
        break;
      case 1:
        // CALL ERROR(CLASS_EV,5); (7707)
        {
          putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_EV));
          putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(5)));
          ERROR (0);
        }
        break;
      case 2:
          // ; (7708)
          ;
        break;
      case 3:
        // TEMP=INT_TYPE; (7709)
        {
          int32_t numberRHS = (int32_t)(6);
          putFIXED (mTEMP, numberRHS);
        }
        break;
      }
  } // End of DO CASE block
  // CALL HALMAT_TUPLE(XBTOC(TEMP-BIT_TYPE),0,I,0,0); (7709)
  {
    putBITp (16, mHALMAT_TUPLExPOPCODE,
             getBIT (16, mXBTOC + 2 * xsubtract (getFIXED (mTEMP), 1)));
    putBITp (8, mHALMAT_TUPLExCOPT, fixedToBit (32, (int32_t)(0)));
    putBITp (16, mHALMAT_TUPLExOP1, getBIT (16, mARITH_TO_CHARxI));
    putBITp (16, mHALMAT_TUPLExOP2, fixedToBit (32, (int32_t)(0)));
    putBITp (8, mHALMAT_TUPLExTAG, fixedToBit (32, (int32_t)(0)));
    HALMAT_TUPLE (0);
  }
  // CALL SETUP_VAC(I,CHAR_TYPE); (7710)
  {
    putBITp (16, mSETUP_VACxLOC, getBIT (16, mARITH_TO_CHARxI));
    putBITp (16, mSETUP_VACxTYPE, fixedToBit (32, (int32_t)(2)));
    SETUP_VAC (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
