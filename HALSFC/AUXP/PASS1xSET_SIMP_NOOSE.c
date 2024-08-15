/*
  File PASS1xSET_SIMP_NOOSE.c generated by XCOM-I, 2024-08-09 12:39:13.
*/

#include "runtimeC.h"

int32_t
PASS1xSET_SIMP_NOOSE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PASS1xSET_SIMP_NOOSE");
  // DO FOR NUMOP = START TO HALRATOR_#RANDS; (1637)
  {
    int32_t from39, to39, by39;
    from39 = bitToFixed (getBIT (16, mPASS1xSET_SIMP_NOOSExSTART));
    to39 = bitToFixed (getBIT (8, mHALRATOR_pRANDS));
    by39 = 1;
    for (putBIT (16, mPASS1xNUMOP, fixedToBit (16, from39));
         bitToFixed (getBIT (16, mPASS1xNUMOP)) <= to39; putBIT (
             16, mPASS1xNUMOP,
             fixedToBit (16, bitToFixed (getBIT (16, mPASS1xNUMOP)) + by39)))
      {
        // CALL SET_RAND_NOOSE(NUMOP); (1638)
        {
          putBITp (16, mPASS1xSET_RAND_NOOSExRANDp, getBIT (16, mPASS1xNUMOP));
          PASS1xSET_RAND_NOOSE (0);
        }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}