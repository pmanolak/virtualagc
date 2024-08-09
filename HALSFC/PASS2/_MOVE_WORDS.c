/*
  File _MOVE_WORDS.c generated by XCOM-I, 2024-08-09 12:39:31.
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
  // IF DEST > SOURCE THEN (153)
  if (1 & (xGT (getFIXED (m_MOVE_WORDSxDEST), getFIXED (m_MOVE_WORDSxSOURCE))))
    // DO I=0 TO NUMBYTES-4 BY 4; (154)
    {
      int32_t from2, to2, by2;
      from2 = 0;
      to2 = xsubtract (getFIXED (m_MOVE_WORDSxNUMBYTES), 4);
      by2 = 4;
      for (putFIXED (m_MOVE_WORDSxI, from2); getFIXED (m_MOVE_WORDSxI) <= to2;
           putFIXED (m_MOVE_WORDSxI, getFIXED (m_MOVE_WORDSxI) + by2))
        {
          // COREWORD(DEST-I) = COREWORD(SOURCE-I); (155)
          {
            int32_t numberRHS = (int32_t)(COREWORD (xsubtract (
                getFIXED (m_MOVE_WORDSxSOURCE), getFIXED (m_MOVE_WORDSxI))));
            COREWORD2 (xsubtract (getFIXED (m_MOVE_WORDSxDEST),
                                  getFIXED (m_MOVE_WORDSxI)),
                       numberRHS);
          }
        }
    } // End of DO for-loop block
  // ELSE (156)
  else
    // DO I=0 TO NUMBYTES -4 BY 4; (157)
    {
      int32_t from3, to3, by3;
      from3 = 0;
      to3 = xsubtract (getFIXED (m_MOVE_WORDSxNUMBYTES), 4);
      by3 = 4;
      for (putFIXED (m_MOVE_WORDSxI, from3); getFIXED (m_MOVE_WORDSxI) <= to3;
           putFIXED (m_MOVE_WORDSxI, getFIXED (m_MOVE_WORDSxI) + by3))
        {
          // COREWORD(DEST+I)=COREWORD(SOURCE+I); (158)
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
