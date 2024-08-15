/*
  File CHARDATE.c generated by XCOM-I, 2024-08-09 12:40:27.
*/

#include "runtimeC.h"

descriptor_t *
CHARDATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "CHARDATE");
  // YEAR=D/1000+1900; (673)
  {
    int32_t numberRHS
        = (int32_t)(xadd (xdivide (getFIXED (mCHARDATExD), 1000), 1900));
    putFIXED (mCHARDATExYEAR, numberRHS);
  }
  // DAY=D MOD 1000; (674)
  {
    int32_t numberRHS = (int32_t)(xmod (getFIXED (mCHARDATExD), 1000));
    putFIXED (mCHARDATExDAY, numberRHS);
  }
  // IF (YEAR& 3)~=0 THEN (675)
  if (1 & (xNEQ (xAND (getFIXED (mCHARDATExYEAR), 3), 0)))
    // IF DAY>59 THEN (676)
    if (1 & (xGT (getFIXED (mCHARDATExDAY), 59)))
      // DAY=DAY+1; (677)
      {
        int32_t numberRHS = (int32_t)(xadd (getFIXED (mCHARDATExDAY), 1));
        putFIXED (mCHARDATExDAY, numberRHS);
      }
  // M=1; (678)
  {
    int32_t numberRHS = (int32_t)(1);
    putFIXED (mCHARDATExM, numberRHS);
  }
  // DO WHILE DAY>DAYS(M); (679)
  while (1
         & (xGT (getFIXED (mCHARDATExDAY),
                 getFIXED (mCHARDATExDAYS + 4 * getFIXED (mCHARDATExM)))))
    {
      // M=M+1; (680)
      {
        int32_t numberRHS = (int32_t)(xadd (getFIXED (mCHARDATExM), 1));
        putFIXED (mCHARDATExM, numberRHS);
      }
    } // End of DO WHILE block
  // RETURN MONTH(M-1)||X1||DAY-DAYS(M-1)||', '||YEAR; (681)
  {
    reentryGuard = 0;
    return xsCAT (
        xsCAT (xsCAT (xsCAT (getCHARACTER (
                                 mCHARDATExMONTH
                                 + 4 * xsubtract (getFIXED (mCHARDATExM), 1)),
                             getCHARACTER (mX1)),
                      fixedToCharacter (xsubtract (
                          getFIXED (mCHARDATExDAY),
                          getFIXED (
                              mCHARDATExDAYS
                              + 4 * xsubtract (getFIXED (mCHARDATExM), 1))))),
               cToDescriptor (NULL, ", ")),
        fixedToCharacter (getFIXED (mCHARDATExYEAR)));
  }
}