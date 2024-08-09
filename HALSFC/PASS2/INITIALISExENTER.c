/*
  File INITIALISExENTER.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
INITIALISExENTER (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INITIALISExENTER");
  // IF (SYT_FLAGS(SYM) & TEMPORARY_FLAG) ~= 0 THEN (2548)
  if (1
      & (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                               + 34 * (COREHALFWORD (mINITIALISExENTERxSYM))
                               + 8 + 4 * (0)),
                     getFIXED (mTEMPORARY_FLAG)),
               0)))
    // RETURN; (2549)
    {
      reentryGuard = 0;
      return 0;
    }
  // NDECSY = NDECSY + 1; (2550)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mNDECSY), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mNDECSY, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE NDECSY >= RECORD_TOP(DOSORT); (2551)
  while (1
         & (xGE (COREHALFWORD (mNDECSY),
                 xsubtract (COREWORD (xadd (
                                ADDR ("DOSORT", 0x80000000, NULL, 0), 12)),
                            1))))
    {
      // DO ; (2552)
      {
      rs1s1:;
        // IF COREWORD ( ADDR ( DOSORT ) + 12 ) >= COREWORD ( ADDR ( DOSORT ) +
        // 8 ) THEN (2553)
        if (1
            & (xGE (
                COREWORD (xadd (ADDR ("DOSORT", 0x80000000, NULL, 0), 12)),
                COREWORD (xadd (ADDR ("DOSORT", 0x80000000, NULL, 0), 8)))))
          // CALL _NEEDMORE_SPACE ( ADDR ( DOSORT )  ) ; (2554)
          {
            putFIXED (m_NEEDMORE_SPACExDOPE,
                      ADDR ("DOSORT", 0x80000000, NULL, 0));
            _NEEDMORE_SPACE (0);
          }
        // COREWORD ( ADDR ( DOSORT ) + 12 ) = COREWORD ( ADDR ( DOSORT ) + 12
        // ) + 1 ; (2555)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREWORD (xadd (ADDR ("DOSORT", 0x80000000, NULL, 0), 12)), 1));
          COREWORD2 (xadd (ADDR ("DOSORT", 0x80000000, NULL, 0), 12),
                     numberRHS);
        }
      es1s1:;
      } // End of DO block
    }   // End of DO WHILE block
  // SYT_SORT(NDECSY) = SHL(SYT_DISP(SYM), 16) + SYM; (2556)
  {
    int32_t numberRHS = (int32_t)(xadd (
        SHL (COREHALFWORD (getFIXED (mP2SYMS)
                           + 12 * (COREHALFWORD (mINITIALISExENTERxSYM)) + 6
                           + 2 * (0)),
             16),
        COREHALFWORD (mINITIALISExENTERxSYM)));
    putFIXED (getFIXED (mDOSORT) + 4 * (COREHALFWORD (mNDECSY)) + 0 + 4 * (0),
              numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
