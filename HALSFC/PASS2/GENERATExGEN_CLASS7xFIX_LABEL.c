/*
  File GENERATExGEN_CLASS7xFIX_LABEL.c generated by XCOM-I, 2024-08-09
  12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS7xFIX_LABEL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExGEN_CLASS7xFIX_LABEL");
  // IF ASSEMBLER_CODE THEN (13762)
  if (1 & (bitToFixed (getBIT (1, mASSEMBLER_CODE))))
    // OUTPUT = HEX_LOCCTR||'P#'||LAB1||' EQU P#'||LAB2; (13763)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          xsCAT (xsCAT (xsCAT (HEX_LOCCTR (0), cToDescriptor (NULL, "P#")),
                        bitToCharacter (
                            getBIT (16, mGENERATExGEN_CLASS7xFIX_LABELxLAB1))),
                 cToDescriptor (NULL, " EQU P#")),
          bitToCharacter (getBIT (16, mGENERATExGEN_CLASS7xFIX_LABELxLAB2)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // DO ; (13764)
  {
  rs1:;
    // IF COREWORD ( ADDR ( LAB_LOC ) + 12 ) >= COREWORD ( ADDR ( LAB_LOC ) + 8
    // ) THEN (13765)
    if (1
        & (xGE (COREWORD (xadd (ADDR ("LAB_LOC", 0x80000000, NULL, 0), 12)),
                COREWORD (xadd (ADDR ("LAB_LOC", 0x80000000, NULL, 0), 8)))))
      // CALL _NEEDMORE_SPACE ( ADDR ( LAB_LOC )  ) ; (13766)
      {
        putFIXED (m_NEEDMORE_SPACExDOPE,
                  ADDR ("LAB_LOC", 0x80000000, NULL, 0));
        _NEEDMORE_SPACE (0);
      }
    // COREWORD ( ADDR ( LAB_LOC ) + 12 ) = COREWORD ( ADDR ( LAB_LOC ) + 12 )
    // + 1 ; (13767)
    {
      int32_t numberRHS = (int32_t)(xadd (
          COREWORD (xadd (ADDR ("LAB_LOC", 0x80000000, NULL, 0), 12)), 1));
      COREWORD2 (xadd (ADDR ("LAB_LOC", 0x80000000, NULL, 0), 12), numberRHS);
    }
  es1:;
  } // End of DO block
  // LOCATION(LAB1) = -LAB2; (13768)
  {
    int32_t numberRHS = (int32_t)(xminus (
        COREHALFWORD (mGENERATExGEN_CLASS7xFIX_LABELxLAB2)));
    putFIXED (getFIXED (mLAB_LOC)
                  + 8 * (COREHALFWORD (mGENERATExGEN_CLASS7xFIX_LABELxLAB1))
                  + 0 + 4 * (0),
              numberRHS);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
