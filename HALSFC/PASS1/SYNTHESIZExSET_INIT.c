/*
  File SYNTHESIZExSET_INIT.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
SYNTHESIZExSET_INIT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SYNTHESIZExSET_INIT");
  // IC_LINE=IC_LINE+1; (13901)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mIC_LINE), 1));
    putFIXED (mIC_LINE, numberRHS);
  }
  // IF IC_LINE>NUM_EL_MAX THEN (13902)
  if (1 & (xGT (getFIXED (mIC_LINE), 32767)))
    // CALL ERROR(CLASS_BT,7); (13903)
    {
      putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_BT));
      putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(7)));
      ERROR (0);
    }
  // Q=GET_ICQ(IC_LINE); (13904)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (mGET_ICQxPTR, getFIXED (mIC_LINE)), GET_ICQ (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSYNTHESIZExSET_INITxQ, bitRHS);
    bitRHS->inUse = 0;
  }
  // IC_VAL(Q)=E; (13905)
  {
    descriptor_t *bitRHS = getBIT (16, mSYNTHESIZExSET_INITxE);
    putBIT (16, mIC_VAL + 2 * (COREHALFWORD (mSYNTHESIZExSET_INITxQ)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IC_LOC(Q)=A; (13906)
  {
    descriptor_t *bitRHS = getBIT (16, mSYNTHESIZExSET_INITxA);
    putBIT (16, mIC_LOC + 2 * (COREHALFWORD (mSYNTHESIZExSET_INITxQ)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IC_LEN(Q)=C; (13907)
  {
    descriptor_t *bitRHS = getBIT (16, mSYNTHESIZExSET_INITxC);
    putBIT (16, mIC_LEN + 2 * (COREHALFWORD (mSYNTHESIZExSET_INITxQ)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IC_FORM(Q)=B; (13908)
  {
    descriptor_t *bitRHS = getBIT (8, mSYNTHESIZExSET_INITxB);
    putBIT (8, mIC_FORM + 1 * (COREHALFWORD (mSYNTHESIZExSET_INITxQ)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IC_TYPE(Q)=D; (13909)
  {
    descriptor_t *bitRHS = getBIT (8, mSYNTHESIZExSET_INITxD);
    putBIT (8, mIC_TYPE + 1 * (COREHALFWORD (mSYNTHESIZExSET_INITxQ)), bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
