/*
  File GENERATExGEN_CLASS8xSET_DENSE_VALUE.c generated by XCOM-I, 2024-08-09
  12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS8xSET_DENSE_VALUE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "GENERATExGEN_CLASS8xSET_DENSE_VALUE");
  // DENSEADDR(0) = DENSEADDR(0) | SHL(OPMODE(DENSETYPE),24); (13904)
  {
    int32_t numberRHS = (int32_t)(xOR (
        getFIXED (getFIXED (mDNS) + 8 * (0) + 0 + 4 * (0)),
        SHL (BYTE0 (mOPMODE + 1 * COREHALFWORD (mGENERATExDENSETYPE)), 24)));
    putFIXED (getFIXED (mDNS) + 8 * (0) + 0 + 4 * (0), numberRHS);
  }
  // IF DENSE_INX = 0 THEN (13905)
  if (1 & (xEQ (COREHALFWORD (mGENERATExDENSE_INX), 0)))
    // DO; (13906)
    {
    rs1:;
      // CALL BUMP_ENTRY; (13907)
      GENERATExGEN_CLASS8xSET_DENSE_VALUExBUMP_ENTRY (0);
      // RETURN; (13908)
      {
        reentryGuard = 0;
        return 0;
      }
    es1:;
    } // End of DO block
  // DO I = 0 TO DENSE_INX-1; (13909)
  {
    int32_t from125, to125, by125;
    from125 = 0;
    to125 = xsubtract (COREHALFWORD (mGENERATExDENSE_INX), 1);
    by125 = 1;
    for (putBIT (16, mGENERATExGEN_CLASS8xSET_DENSE_VALUExI,
                 fixedToBit (16, from125));
         bitToFixed (getBIT (16, mGENERATExGEN_CLASS8xSET_DENSE_VALUExI))
         <= to125;
         putBIT (
             16, mGENERATExGEN_CLASS8xSET_DENSE_VALUExI,
             fixedToBit (16, bitToFixed (getBIT (
                                 16, mGENERATExGEN_CLASS8xSET_DENSE_VALUExI))
                                 + by125)))
      {
        // J = DENSE_INX - I; (13910)
        {
          int32_t numberRHS = (int32_t)(xsubtract (
              COREHALFWORD (mGENERATExDENSE_INX),
              COREHALFWORD (mGENERATExGEN_CLASS8xSET_DENSE_VALUExI)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mGENERATExGEN_CLASS8xSET_DENSE_VALUExJ, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF DENSEADDR(J) = DENSEADDR(0) THEN (13911)
        if (1
            & (xEQ (
                getFIXED (getFIXED (mDNS)
                          + 8
                                * (COREHALFWORD (
                                    mGENERATExGEN_CLASS8xSET_DENSE_VALUExJ))
                          + 0 + 4 * (0)),
                getFIXED (getFIXED (mDNS) + 8 * (0) + 0 + 4 * (0)))))
          // DO; (13912)
          {
          rs2s1:;
            // DENSEVAL(J) = DENSEVAL(J) | DENSEVAL(0); (13913)
            {
              int32_t numberRHS = (int32_t)(xOR (
                  getFIXED (getFIXED (mDNS)
                            + 8
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS8xSET_DENSE_VALUExJ))
                            + 4 + 4 * (0)),
                  getFIXED (getFIXED (mDNS) + 8 * (0) + 4 + 4 * (0))));
              putFIXED (getFIXED (mDNS)
                            + 8
                                  * (COREHALFWORD (
                                      mGENERATExGEN_CLASS8xSET_DENSE_VALUExJ))
                            + 4 + 4 * (0),
                        numberRHS);
            }
            // RETURN; (13914)
            {
              reentryGuard = 0;
              return 0;
            }
          es2s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // CALL BUMP_ENTRY; (13915)
  GENERATExGEN_CLASS8xSET_DENSE_VALUExBUMP_ENTRY (0);
  {
    reentryGuard = 0;
    return 0;
  }
}
