/*
  File _FREEBLOCK_CHECKxADDRESS_CHECK.c generated by XCOM-I, 2024-08-09
  12:40:16.
*/

#include "runtimeC.h"

int32_t
_FREEBLOCK_CHECKxADDRESS_CHECK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_FREEBLOCK_CHECKxADDRESS_CHECK");
  // IF ADDRESS >= 0 THEN (179)
  if (1 & (xGE (getFIXED (m_FREEBLOCK_CHECKxADDRESS_CHECKxADDRESS), 0)))
    // IF ( ADDRESS & 7 ) = 0 THEN (180)
    if (1
        & (xEQ (xAND (getFIXED (m_FREEBLOCK_CHECKxADDRESS_CHECKxADDRESS), 7),
                0)))
      // RETURN; (181)
      {
        reentryGuard = 0;
        return 0;
      }
  // DO; (182)
  {
  rs1:;
    // CALL _SPMANERR('IN FREEBLOCK_CHECK, NOT ALIGNED ON DOUBLE WORD,
    // ADDRESS='||((ADDRESS^=0)*(ADDRESS-FREEBASE-3))); (183)
    {
      putCHARACTERp (
          m_SPMANERRxMSG,
          xsCAT (
              cToDescriptor (
                  NULL,
                  "IN FREEBLOCK_CHECK, NOT ALIGNED ON DOUBLE WORD, ADDRESS="),
              fixedToCharacter (xmultiply (
                  xNEQ (getFIXED (m_FREEBLOCK_CHECKxADDRESS_CHECKxADDRESS), 0),
                  xsubtract (
                      xsubtract (
                          getFIXED (m_FREEBLOCK_CHECKxADDRESS_CHECKxADDRESS),
                          FREEBASE ()),
                      3)))));
      _SPMANERR (0);
    }
  es1:;
  } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
