/*
  File _STEAL.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
_STEAL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_STEAL");
  // IF CORELIMIT=0 THEN (493)
  if (1 & (xEQ (getFIXED (mCORELIMIT), 0)))
    // CORELIMIT=FREELIMIT+512; (494)
    {
      int32_t numberRHS = (int32_t)(xadd (FREELIMIT (), 512));
      putFIXED (mCORELIMIT, numberRHS);
    }
  // IF FREELIMIT-FREEPOINT < NBYTES THEN (495)
  if (1
      & (xLT (xsubtract (FREELIMIT (), FREEPOINT ()),
              getFIXED (m_STEALxNBYTES))))
    // DO; (496)
    {
    rs1:;
      // FORCE_MAJOR=_TRUE; (497)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mFORCE_MAJOR, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL COMPACTIFY; (498)
      COMPACTIFY (0);
    es1:;
    } // End of DO block
  // IF FREELIMIT-FREEPOINT < NBYTES THEN (499)
  if (1
      & (xLT (xsubtract (FREELIMIT (), FREEPOINT ()),
              getFIXED (m_STEALxNBYTES))))
    // DO; (500)
    {
    rs2:;
      // OUTPUT= 'BI011 SEVERITY 3 ' || 'NOT ENOUGH FREE STRING AVAILABLE,
      // RERUN WITH LARGER REGION.'; (501)
      {
        descriptor_t *stringRHS;
        stringRHS
            = cToDescriptor (NULL, "BI011 SEVERITY 3 NOT ENOUGH FREE STRING "
                                   "AVAILABLE, RERUN WITH LARGER REGION.");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // CALL EXIT; (502)
      EXIT ();
    es2:;
    } // End of DO block
  // _OLDFREELIMIT,FREELIMIT=FREELIMIT-NBYTES; (503)
  {
    int32_t numberRHS
        = (int32_t)(xsubtract (FREELIMIT (), getFIXED (m_STEALxNBYTES)));
    putFIXED (m_OLDFREELIMIT, numberRHS);
    FREELIMIT2 (numberRHS);
  }
  // FREEBYTES=FREEBYTES+NBYTES; (504)
  {
    int32_t numberRHS
        = (int32_t)(xadd (getFIXED (mFREEBYTES), getFIXED (m_STEALxNBYTES)));
    putFIXED (mFREEBYTES, numberRHS);
  }
  // BLOCKLOC=FREELIMIT+NBYTES+512-4; (505)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        xadd (xadd (FREELIMIT (), getFIXED (m_STEALxNBYTES)), 512), 4));
    putFIXED (m_STEALxBLOCKLOC, numberRHS);
  }
  // _FREEBLOCK_NEXT(BLOCKLOC)=0; (506)
  {
    int32_t numberRHS = (int32_t)(0);
    COREWORD2 (getFIXED (m_STEALxBLOCKLOC), numberRHS);
  }
  // _FREEBLOCK_SIZE(BLOCKLOC)=NBYTES; (507)
  {
    int32_t numberRHS = (int32_t)(getFIXED (m_STEALxNBYTES));
    COREWORD2 (xsubtract (getFIXED (m_STEALxBLOCKLOC), 4), numberRHS);
  }
  // CALL _ATTACH_BLOCK(BLOCKLOC); (508)
  {
    putFIXED (m_ATTACH_BLOCKxBLOCK, getFIXED (m_STEALxBLOCKLOC));
    _ATTACH_BLOCK (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
