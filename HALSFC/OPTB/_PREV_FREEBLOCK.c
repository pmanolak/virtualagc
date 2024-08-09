/*
  File _PREV_FREEBLOCK.c generated by XCOM-I, 2024-08-09 12:41:07.
*/

#include "runtimeC.h"

int32_t
_PREV_FREEBLOCK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_PREV_FREEBLOCK");
  // PREV=0; (196)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (m_PREV_FREEBLOCKxPREV, numberRHS);
  }
  // CUR=FIRSTBLOCK; (197)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mFIRSTBLOCK));
    putFIXED (m_PREV_FREEBLOCKxCUR, numberRHS);
  }
  // DO WHILE (CUR > 0) & (CUR ~= BLOCK); (198)
  while (1
         & (xAND (xGT (getFIXED (m_PREV_FREEBLOCKxCUR), 0),
                  xNEQ (getFIXED (m_PREV_FREEBLOCKxCUR),
                        getFIXED (m_PREV_FREEBLOCKxBLOCK)))))
    {
      // PREV=CUR; (199)
      {
        int32_t numberRHS = (int32_t)(getFIXED (m_PREV_FREEBLOCKxCUR));
        putFIXED (m_PREV_FREEBLOCKxPREV, numberRHS);
      }
      // CUR=_FREEBLOCK_NEXT(CUR); (200)
      {
        int32_t numberRHS
            = (int32_t)(COREWORD (getFIXED (m_PREV_FREEBLOCKxCUR)));
        putFIXED (m_PREV_FREEBLOCKxCUR, numberRHS);
      }
    } // End of DO WHILE block
  // RETURN PREV; (201)
  {
    reentryGuard = 0;
    return getFIXED (m_PREV_FREEBLOCKxPREV);
  }
}
