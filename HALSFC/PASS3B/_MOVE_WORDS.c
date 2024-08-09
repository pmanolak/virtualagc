/*
  File _MOVE_WORDS.c generated by XCOM-I, 2024-08-09 12:42:16.
*/

#include "runtimeC.h"

int32_t
_MOVE_WORDS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_MOVE_WORDS");
  // IF DEST > SOURCE THEN (211)
  if (1 & (xGT (getFIXED (m_MOVE_WORDSxDEST), getFIXED (m_MOVE_WORDSxSOURCE))))
    // DO I=0 TO NUMBYTES-4 BY 4; (212)
    {
      int32_t from6, to6, by6;
      from6 = 0;
      to6 = xsubtract (getFIXED (m_MOVE_WORDSxNUMBYTES), 4);
      by6 = 4;
      for (putFIXED (m_MOVE_WORDSxI, from6); getFIXED (m_MOVE_WORDSxI) <= to6;
           putFIXED (m_MOVE_WORDSxI, getFIXED (m_MOVE_WORDSxI) + by6))
        {
          // COREWORD(DEST-I) = COREWORD(SOURCE-I); (213)
          {
            int32_t numberRHS = (int32_t)(COREWORD (xsubtract (
                getFIXED (m_MOVE_WORDSxSOURCE), getFIXED (m_MOVE_WORDSxI))));
            COREWORD2 (xsubtract (getFIXED (m_MOVE_WORDSxDEST),
                                  getFIXED (m_MOVE_WORDSxI)),
                       numberRHS);
          }
        }
    } // End of DO for-loop block
  // ELSE (214)
  else
    // DO I=0 TO NUMBYTES -4 BY 4; (215)
    {
      int32_t from7, to7, by7;
      from7 = 0;
      to7 = xsubtract (getFIXED (m_MOVE_WORDSxNUMBYTES), 4);
      by7 = 4;
      for (putFIXED (m_MOVE_WORDSxI, from7); getFIXED (m_MOVE_WORDSxI) <= to7;
           putFIXED (m_MOVE_WORDSxI, getFIXED (m_MOVE_WORDSxI) + by7))
        {
          // COREWORD(DEST+I)=COREWORD(SOURCE+I); (216)
          {
            int32_t numberRHS = (int32_t)(COREWORD (xadd (
                getFIXED (m_MOVE_WORDSxSOURCE), getFIXED (m_MOVE_WORDSxI))));
            COREWORD2 (
                xadd (getFIXED (m_MOVE_WORDSxDEST), getFIXED (m_MOVE_WORDSxI)),
                numberRHS);
          }
        }
    } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
