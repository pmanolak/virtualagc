/*
  File _STEAL.c generated by XCOM-I, 2024-08-09 12:40:27.
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
  // IF CORELIMIT=0 THEN (477)
  if (1 & (xEQ (getFIXED (mCORELIMIT), 0)))
    // CORELIMIT=FREELIMIT+512; (478)
    {
      int32_t numberRHS = (int32_t)(xadd (FREELIMIT (), 512));
      putFIXED (mCORELIMIT, numberRHS);
    }
  // IF FREELIMIT-FREEPOINT < NBYTES THEN (479)
  if (1
      & (xLT (xsubtract (FREELIMIT (), FREEPOINT ()),
              getFIXED (m_STEALxNBYTES))))
    // DO; (480)
    {
    rs1:;
      // FORCE_MAJOR=_TRUE; (481)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mFORCE_MAJOR, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL COMPACTIFY; (482)
      COMPACTIFY (0);
    es1:;
    } // End of DO block
  // IF FREELIMIT-FREEPOINT < NBYTES THEN (483)
  if (1
      & (xLT (xsubtract (FREELIMIT (), FREEPOINT ()),
              getFIXED (m_STEALxNBYTES))))
    // DO; (484)
    {
    rs2:;
      // OUTPUT= 'BI011 SEVERITY 3 ' || 'NOT ENOUGH FREE STRING AVAILABLE,
      // RERUN WITH LARGER REGION.'; (485)
      {
        descriptor_t *stringRHS;
        stringRHS
            = cToDescriptor (NULL, "BI011 SEVERITY 3 NOT ENOUGH FREE STRING "
                                   "AVAILABLE, RERUN WITH LARGER REGION.");
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // CALL EXIT; (486)
      EXIT ();
    es2:;
    } // End of DO block
  // _OLDFREELIMIT,FREELIMIT=FREELIMIT-NBYTES; (487)
  {
    int32_t numberRHS
        = (int32_t)(xsubtract (FREELIMIT (), getFIXED (m_STEALxNBYTES)));
    putFIXED (m_OLDFREELIMIT, numberRHS);
    FREELIMIT2 (numberRHS);
  }
  // FREEBYTES=FREEBYTES+NBYTES; (488)
  {
    int32_t numberRHS
        = (int32_t)(xadd (getFIXED (mFREEBYTES), getFIXED (m_STEALxNBYTES)));
    putFIXED (mFREEBYTES, numberRHS);
  }
  // BLOCKLOC=FREELIMIT+NBYTES+512-4; (489)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        xadd (xadd (FREELIMIT (), getFIXED (m_STEALxNBYTES)), 512), 4));
    putFIXED (m_STEALxBLOCKLOC, numberRHS);
  }
  // _FREEBLOCK_NEXT(BLOCKLOC)=0; (490)
  {
    int32_t numberRHS = (int32_t)(0);
    COREWORD2 (getFIXED (m_STEALxBLOCKLOC), numberRHS);
  }
  // _FREEBLOCK_SIZE(BLOCKLOC)=NBYTES; (491)
  {
    int32_t numberRHS = (int32_t)(getFIXED (m_STEALxNBYTES));
    COREWORD2 (xsubtract (getFIXED (m_STEALxBLOCKLOC), 4), numberRHS);
  }
  // CALL _ATTACH_BLOCK(BLOCKLOC); (492)
  {
    putFIXED (m_ATTACH_BLOCKxBLOCK, getFIXED (m_STEALxBLOCKLOC));
    _ATTACH_BLOCK (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}