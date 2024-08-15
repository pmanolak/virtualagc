/*
  File _UNUSED_BYTES.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
_UNUSED_BYTES (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_UNUSED_BYTES");
  // CUR=FIRSTRECORD; (136)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mFIRSTRECORD));
    putFIXED (m_UNUSED_BYTESxCUR, numberRHS);
  }
  // ANS=0; (137)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (m_UNUSED_BYTESxANS, numberRHS);
  }
  // DO WHILE CUR > 0; (138)
  while (1 & (xGT (getFIXED (m_UNUSED_BYTESxCUR), 0)))
    {
      // IF ~_IS_REC_CONSTANT(CUR) THEN (139)
      if (1
          & (xNOT (
              xNEQ (xAND (COREWORD (xadd (getFIXED (m_UNUSED_BYTESxCUR), 20)),
                          50331648),
                    0))))
        // ANS=ANS+ ( 4294967288 &
        // (_DOPE_WIDTH(CUR)*(_DOPE_ALLOC(CUR)-_DOPE_USED(CUR)))); (140)
        {
          int32_t numberRHS = (int32_t)(xadd (
              getFIXED (m_UNUSED_BYTESxANS),
              xAND (4294967288,
                    xmultiply (
                        COREHALFWORD (xadd (getFIXED (m_UNUSED_BYTESxCUR), 4)),
                        xsubtract (
                            COREWORD (xadd (getFIXED (m_UNUSED_BYTESxCUR), 8)),
                            COREWORD (
                                xadd (getFIXED (m_UNUSED_BYTESxCUR), 12)))))));
          putFIXED (m_UNUSED_BYTESxANS, numberRHS);
        }
      // CUR=_DOPE_NEXT(CUR); (141)
      {
        int32_t numberRHS
            = (int32_t)(COREWORD (xadd (getFIXED (m_UNUSED_BYTESxCUR), 16)));
        putFIXED (m_UNUSED_BYTESxCUR, numberRHS);
      }
    } // End of DO WHILE block
  // RETURN ANS; (142)
  {
    reentryGuard = 0;
    return getFIXED (m_UNUSED_BYTESxANS);
  }
}