/*
  File _DETACH_RECORD.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

int32_t
_DETACH_RECORD (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_DETACH_RECORD");
  // PREV=_PREV_RECORD(DOPE); (233)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (m_PREV_RECORDxDOPE, getFIXED (m_DETACH_RECORDxDOPE)),
        _PREV_RECORD (0)));
    putFIXED (m_DETACH_RECORDxPREV, numberRHS);
  }
  // IF PREV=0 THEN (234)
  if (1 & (xEQ (getFIXED (m_DETACH_RECORDxPREV), 0)))
    // FIRSTRECORD=_DOPE_NEXT(DOPE); (235)
    {
      int32_t numberRHS
          = (int32_t)(COREWORD (xadd (getFIXED (m_DETACH_RECORDxDOPE), 16)));
      putFIXED (mFIRSTRECORD, numberRHS);
    }
  // ELSE (236)
  else
    // _DOPE_NEXT(PREV)=_DOPE_NEXT(DOPE); (237)
    {
      int32_t numberRHS
          = (int32_t)(COREWORD (xadd (getFIXED (m_DETACH_RECORDxDOPE), 16)));
      COREWORD2 (xadd (getFIXED (m_DETACH_RECORDxPREV), 16), numberRHS);
    }
  // TOTAL_RDESC=TOTAL_RDESC-(_DOPE_#DESCRIPTORS(DOPE)*_DOPE_ALLOC(DOPE));
  // (238)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        getFIXED (mTOTAL_RDESC),
        xmultiply (COREHALFWORD (xadd (getFIXED (m_DETACH_RECORDxDOPE), 6)),
                   COREWORD (xadd (getFIXED (m_DETACH_RECORDxDOPE), 8)))));
    putFIXED (mTOTAL_RDESC, numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
