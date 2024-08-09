/*
  File ICQ_TERMp.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
ICQ_TERMp (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ICQ_TERMp");
  // IF NAME_IMPLIED THEN (1296)
  if (1 & (bitToFixed (getBIT (1, mNAME_IMPLIED))))
    // RETURN 1; (1297)
    {
      reentryGuard = 0;
      return 1;
    }
  // IF SYT_TYPE(LOC)=VEC_TYPE THEN (1298)
  if (1
      & (xEQ (BYTE0 (getFIXED (mSYM_TAB) + 34 * (getFIXED (mICQ_TERMpxLOC))
                     + 32 + 1 * (0)),
              4)))
    // RETURN VAR_LENGTH(LOC); (1299)
    {
      reentryGuard = 0;
      return COREHALFWORD (getFIXED (mSYM_TAB)
                           + 34 * (getFIXED (mICQ_TERMpxLOC)) + 18 + 2 * (0));
    }
  // IF SYT_TYPE(LOC)=MAT_TYPE THEN (1300)
  if (1
      & (xEQ (BYTE0 (getFIXED (mSYM_TAB) + 34 * (getFIXED (mICQ_TERMpxLOC))
                     + 32 + 1 * (0)),
              3)))
    // DO; (1301)
    {
    rs1:;
      // I=VAR_LENGTH(LOC)& 255; (1302)
      {
        int32_t numberRHS = (int32_t)(xAND (
            COREHALFWORD (getFIXED (mSYM_TAB)
                          + 34 * (getFIXED (mICQ_TERMpxLOC)) + 18 + 2 * (0)),
            255));
        putFIXED (mICQ_TERMpxI, numberRHS);
      }
      // LOC=SHR(VAR_LENGTH(LOC),8); (1303)
      {
        int32_t numberRHS = (int32_t)(SHR (
            COREHALFWORD (getFIXED (mSYM_TAB)
                          + 34 * (getFIXED (mICQ_TERMpxLOC)) + 18 + 2 * (0)),
            8));
        putFIXED (mICQ_TERMpxLOC, numberRHS);
      }
      // RETURN LOC*I; (1304)
      {
        reentryGuard = 0;
        return xmultiply (getFIXED (mICQ_TERMpxLOC), getFIXED (mICQ_TERMpxI));
      }
    es1:;
    } // End of DO block
  // IF SYT_TYPE(LOC)=MAJ_STRUC THEN (1305)
  if (1
      & (xEQ (BYTE0 (getFIXED (mSYM_TAB) + 34 * (getFIXED (mICQ_TERMpxLOC))
                     + 32 + 1 * (0)),
              10)))
    // DO; (1306)
    {
    rs2:;
      // LOC=SYT_ADDR(VAR_LENGTH(LOC)); (1307)
      {
        int32_t numberRHS = (int32_t)(getFIXED (
            getFIXED (mSYM_TAB)
            + 34
                  * (COREHALFWORD (getFIXED (mSYM_TAB)
                                   + 34 * (getFIXED (mICQ_TERMpxLOC)) + 18
                                   + 2 * (0)))
            + 4 + 4 * (0)));
        putFIXED (mICQ_TERMpxLOC, numberRHS);
      }
      // IF LOC>0 THEN (1308)
      if (1 & (xGT (getFIXED (mICQ_TERMpxLOC), 0)))
        // RETURN LOC; (1309)
        {
          reentryGuard = 0;
          return getFIXED (mICQ_TERMpxLOC);
        }
    es2:;
    } // End of DO block
  // RETURN 1; (1310)
  {
    reentryGuard = 0;
    return 1;
  }
}
