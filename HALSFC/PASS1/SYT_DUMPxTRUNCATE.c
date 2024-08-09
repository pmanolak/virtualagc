/*
  File SYT_DUMPxTRUNCATE.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

descriptor_t *
SYT_DUMPxTRUNCATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SYT_DUMPxTRUNCATE");
  // L = LENGTH(STRING); (5957)
  {
    int32_t numberRHS
        = (int32_t)(LENGTH (getCHARACTER (mSYT_DUMPxTRUNCATExSTRING)));
    putFIXED (mSYT_DUMPxTRUNCATExL, numberRHS);
  }
  // DO WHILE SUBSTR(STRING,L-1,1) = X1; (5958)
  while (1
         & (xsEQ (SUBSTR (getCHARACTER (mSYT_DUMPxTRUNCATExSTRING),
                          xsubtract (getFIXED (mSYT_DUMPxTRUNCATExL), 1), 1),
                  getCHARACTER (mX1))))
    {
      // L = L-1; (5959)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (getFIXED (mSYT_DUMPxTRUNCATExL), 1));
        putFIXED (mSYT_DUMPxTRUNCATExL, numberRHS);
      }
    } // End of DO WHILE block
  // RETURN SUBSTR(STRING,0,L); (5960)
  {
    reentryGuard = 0;
    return SUBSTR (getCHARACTER (mSYT_DUMPxTRUNCATExSTRING), 0,
                   getFIXED (mSYT_DUMPxTRUNCATExL));
  }
}
