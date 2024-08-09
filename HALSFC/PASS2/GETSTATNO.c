/*
  File GETSTATNO.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

descriptor_t *
GETSTATNO (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GETSTATNO");
  // DO ; (1410)
  {
  rs1:;
    // IF COREWORD ( ADDR ( LAB_LOC ) + 12 ) >= COREWORD ( ADDR ( LAB_LOC ) + 8
    // ) THEN (1411)
    if (1
        & (xGE (COREWORD (xadd (ADDR ("LAB_LOC", 0x80000000, NULL, 0), 12)),
                COREWORD (xadd (ADDR ("LAB_LOC", 0x80000000, NULL, 0), 8)))))
      // CALL _NEEDMORE_SPACE ( ADDR ( LAB_LOC )  ) ; (1412)
      {
        putFIXED (m_NEEDMORE_SPACExDOPE,
                  ADDR ("LAB_LOC", 0x80000000, NULL, 0));
        _NEEDMORE_SPACE (0);
      }
    // COREWORD ( ADDR ( LAB_LOC ) + 12 ) = COREWORD ( ADDR ( LAB_LOC ) + 12 )
    // + 1 ; (1413)
    {
      int32_t numberRHS = (int32_t)(xadd (
          COREWORD (xadd (ADDR ("LAB_LOC", 0x80000000, NULL, 0), 12)), 1));
      COREWORD2 (xadd (ADDR ("LAB_LOC", 0x80000000, NULL, 0), 12), numberRHS);
    }
  es1:;
  } // End of DO block
  // STATNO=STATNO+1; (1414)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mSTATNO), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSTATNO, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN STATNO; (1415)
  {
    reentryGuard = 0;
    return getBIT (16, mSTATNO);
  }
}
