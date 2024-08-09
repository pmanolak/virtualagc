/*
  File OBJECT_GENERATORxINST_ADDRS.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
OBJECT_GENERATORxINST_ADDRS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "OBJECT_GENERATORxINST_ADDRS");
  // IF FIRST_INST THEN (16270)
  if (1 & (bitToFixed (getBIT (1, mFIRST_INST))))
    // DO; (16271)
    {
    rs1:;
      // ERRSEG(CURRENT_ESDID) = CURRENT_ADDRESS; (16272)
      {
        int32_t numberRHS
            = (int32_t)(getFIXED (mWORKSEG + 4 * getFIXED (mCURRENT_ESDID)));
        putFIXED (mERRSEG + 4 * (getFIXED (mCURRENT_ESDID)), numberRHS);
      }
      // FIRST_INST = FALSE; (16273)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mFIRST_INST, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // STACKSPACE(CURRENT_ESDID) = CURRENT_ADDRESS; (16274)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (mWORKSEG + 4 * getFIXED (mCURRENT_ESDID)));
    putFIXED (mSTACKSPACE + 4 * (getFIXED (mCURRENT_ESDID)), numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
