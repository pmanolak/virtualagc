/*
  File _SPACE_ROUND.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
_SPACE_ROUND (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_SPACE_ROUND");
  // RETURN (BYTES& 16777208)+SHL((BYTES& 7)~=0,3); (53)
  {
    reentryGuard = 0;
    return xadd (xAND (getFIXED (m_SPACE_ROUNDxBYTES), 16777208),
                 SHL (xNEQ (xAND (getFIXED (m_SPACE_ROUNDxBYTES), 7), 0), 3));
  }
}
