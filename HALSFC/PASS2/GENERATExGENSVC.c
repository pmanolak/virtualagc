/*
  File GENERATExGENSVC.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExGENSVC (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExGENSVC");
  // INX_CON(PTR) = 0; (8671)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (getFIXED (mIND_STACK) + 73 * (getFIXED (mGENERATExGENSVCxPTR))
                  + 4 + 4 * (0),
              numberRHS);
  }
  // IF SVC# ~= 0 THEN (8672)
  if (1 & (xNEQ (getFIXED (mGENERATExGENSVCxSVCp), 0)))
    // DO; (8673)
    {
    rs1:;
      // CALL FORCE_NUM(LINKREG, SVC#); (8674)
      {
        putBITp (16, mGENERATExFORCE_NUMxR, getBIT (8, mLINKREG));
        putFIXED (mGENERATExFORCE_NUMxNUM, getFIXED (mGENERATExGENSVCxSVCp));
        GENERATExFORCE_NUM (0);
      }
      // CALL EMITOP(STH, LINKREG, PTR); (8675)
      {
        putBITp (16, mGENERATExEMITOPxINST, getBIT (8, mSTH));
        putBITp (16, mGENERATExEMITOPxXREG, getBIT (8, mLINKREG));
        putBITp (16, mGENERATExEMITOPxOP,
                 fixedToBit (32, (int32_t)(getFIXED (mGENERATExGENSVCxPTR))));
        GENERATExEMITOP (0);
      }
    es1:;
    } // End of DO block
  // CALL EMITOP(SVC, 0, PTR); (8676)
  {
    putBITp (16, mGENERATExEMITOPxINST, getBIT (8, mSVC));
    putBITp (16, mGENERATExEMITOPxXREG, fixedToBit (32, (int32_t)(0)));
    putBITp (16, mGENERATExEMITOPxOP,
             fixedToBit (32, (int32_t)(getFIXED (mGENERATExGENSVCxPTR))));
    GENERATExEMITOP (0);
  }
  // CALL DROPSAVE(PTR); (8677)
  {
    putBITp (16, mGENERATExDROPSAVExENTRY,
             fixedToBit (32, (int32_t)(getFIXED (mGENERATExGENSVCxPTR))));
    GENERATExDROPSAVE (0);
  }
  // CALL RETURN_STACK_ENTRY(PTR); (8678)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
             fixedToBit (32, (int32_t)(getFIXED (mGENERATExGENSVCxPTR))));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
