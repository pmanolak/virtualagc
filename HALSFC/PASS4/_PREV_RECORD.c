/*
  File _PREV_RECORD.c generated by XCOM-I, 2024-08-09 12:40:27.
*/

#include "runtimeC.h"

int32_t
_PREV_RECORD (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_PREV_RECORD");
  // PREV=0; (180)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (m_PREV_RECORDxPREV, numberRHS);
  }
  // CUR=FIRSTRECORD; (181)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mFIRSTRECORD));
    putFIXED (m_PREV_RECORDxCUR, numberRHS);
  }
  // DO WHILE (CUR > 0) & (CUR ~= DOPE); (182)
  while (1
         & (xAND (xGT (getFIXED (m_PREV_RECORDxCUR), 0),
                  xNEQ (getFIXED (m_PREV_RECORDxCUR),
                        getFIXED (m_PREV_RECORDxDOPE)))))
    {
      // PREV=CUR; (183)
      {
        int32_t numberRHS = (int32_t)(getFIXED (m_PREV_RECORDxCUR));
        putFIXED (m_PREV_RECORDxPREV, numberRHS);
      }
      // CUR=_DOPE_NEXT(CUR); (184)
      {
        int32_t numberRHS
            = (int32_t)(COREWORD (xadd (getFIXED (m_PREV_RECORDxCUR), 16)));
        putFIXED (m_PREV_RECORDxCUR, numberRHS);
      }
    } // End of DO WHILE block
  // RETURN PREV; (185)
  {
    reentryGuard = 0;
    return getFIXED (m_PREV_RECORDxPREV);
  }
}
