/*
  File GET_NODExCATALOG_CHECK.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

descriptor_t *
GET_NODExCATALOG_CHECK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_NODExCATALOG_CHECK");
  // IF CATALOG_SRCH(CAT_POINT) = 0 THEN (5544)
  if (1
      & (xEQ (bitToFixed (
                  (putBITp (16, mCATALOG_SRCHxPTR,
                            getBIT (16, mGET_NODExCATALOG_CHECKxCAT_POINT)),
                   CATALOG_SRCH (0))),
              0)))
    // DO; (5545)
    {
    rs1:;
      // IF ~ARRAYED_CONDITIONAL THEN (5546)
      if (1 & (xNOT (BYTE0 (mARRAYED_CONDITIONAL))))
        // CALL CATALOG(0,1); (5547)
        {
          putBITp (16, mCATALOGxSYT_POINT, fixedToBit (32, (int32_t)(0)));
          putBITp (16, mCATALOGxNEW_OP, fixedToBit (32, (int32_t)(1)));
          CATALOG (0);
        }
      // IF TWIN_OP THEN (5548)
      if (1 & (bitToFixed (getBIT (8, mTWIN_OP))))
        // IF CATALOG_SRCH(CAT_POINT,1) ~= 0 THEN (5549)
        if (1
            & (xNEQ (
                bitToFixed (
                    (putBITp (16, mCATALOG_SRCHxPTR,
                              getBIT (16, mGET_NODExCATALOG_CHECKxCAT_POINT)),
                     putBITp (8, mCATALOG_SRCHxTWIN_FLAG,
                              fixedToBit (32, (int32_t)(1))),
                     CATALOG_SRCH (0))),
                0)))
          // CALL BUMP_SEARCH(BUMP#); (5550)
          {
            putBITp (8, mGET_NODExBUMP_SEARCHxTAG,
                     getBIT (8, mGET_NODExCATALOG_CHECKxBUMPp));
            GET_NODExBUMP_SEARCH (0);
          }
      // RETURN TRUE; (5551)
      {
        reentryGuard = 0;
        return fixedToBit (32, (int32_t)(1));
      }
    es1:;
    } // End of DO block
  // RETURN FALSE; (5552)
  {
    reentryGuard = 0;
    return fixedToBit (32, (int32_t)(0));
  }
}
