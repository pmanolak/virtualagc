/*
  File ZERO_256.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
ZERO_256 (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "ZERO_256");
  // COUNT = COUNT - 2; (648)
  {
    int32_t numberRHS
        = (int32_t)(xsubtract (COREHALFWORD (mZERO_256xCOUNT), 2));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mZERO_256xCOUNT, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF COUNT < 0 THEN (649)
  if (1 & (xLT (COREHALFWORD (mZERO_256xCOUNT), 0)))
    // DO; (650)
    {
    rs1:;
      {   // (5) CALL INLINE( 88, 1, 0, CORE_ADDR);
        { /*
           * File:      patch5.c
           * For:       ZERO_256.c
           * Notes:     1. Page references are from IBM "ESA/390 Principles of
           *               Operation", SA22-7201-08, Ninth Edition, June 2003.
           *            2. Labels are of the form p%d_%d, where the 1st number
           *               indicates the leading patch number of the block, and
           *               the 2nd is the byte offset of the instruction within
           *               within the block.
           *            3. Known-problematic translations are marked with the
           *               string  "* * * F I X M E * * *" (without spaces).
           * History:   2024-07-18 RSB  Auto-generated by XCOM-I --guess=....
           *                            Inspected.
           */

          p5_0:;
      // (5)          CALL INLINE("58", 1, 0, CORE_ADDR);  /* L   1,CORE_ADDR
      // */
      address360B = (mZERO_256xCORE_ADDR)&0xFFFFFF;
      // Type RX, p. 7-7:		L	1,mZERO_256xCORE_ADDR(0,0)
      detailedInlineBefore (5, "L	1,mZERO_256xCORE_ADDR(0,0)");
      GR[1] = COREWORD (address360B);
      detailedInlineAfter ();

    p5_4:;
      // (6)          CALL INLINE("92", 0, 0, 1, 0);       /* MVI 0(1),X'00' */
      address360A = (GR[1] + 0) & 0xFFFFFF;
      // Type SI, p. 7-83:		MVI	0(1),0
      detailedInlineBefore (6, "MVI	0(1),0");
      memory[address360A] = 0;
      detailedInlineAfter ();

    p5_8:;
    }
}; // (6) CALL INLINE( 146, 0, 0, 1, 0);
es1:;
} // End of DO block
// ELSE (653)
else
// DO; (654)
{
rs2:;
  // MVCTEMP = ADDR(MVC); (655)
  {
    int32_t numberRHS = (int32_t)(-1);
    putFIXED (mZERO_256xMVCTEMP, numberRHS);
  }
  {   // (7) CALL INLINE( 88, 1, 0, CORE_ADDR);
    { /*
       * File:      patch7.c
       * For:       ZERO_256.c
       * Notes:     1. Page references are from IBM "ESA/390 Principles of
       *               Operation", SA22-7201-08, Ninth Edition, June 2003.
       *            2. Labels are of the form p%d_%d, where the 1st number
       *               indicates the leading patch number of the block, and
       *               the 2nd is the byte offset of the instruction within
       *               within the block.
       *            3. Known-problematic translations are marked with the
       *               string  "* * * F I X M E * * *" (without spaces).
       * History:   2024-07-18 RSB  Auto-generated by XCOM-I --guess=....
       *                            Fixed the FIXME.
       */

      p7_0:;
  // (7)          CALL INLINE("58", 1, 0, CORE_ADDR);  /* L   1,CORE_ADDR */
  address360B = (mZERO_256xCORE_ADDR)&0xFFFFFF;
  // Type RX, p. 7-7:		L	1,mZERO_256xCORE_ADDR(0,0)
  detailedInlineBefore (7, "L	1,mZERO_256xCORE_ADDR(0,0)");
  GR[1] = COREWORD (address360B);
  detailedInlineAfter ();

p7_4:;
  // (8)          CALL INLINE("92", 0, 0, 1, 0);       /* MVI 0(1),X'00' */
  address360A = (GR[1] + 0) & 0xFFFFFF;
  // Type SI, p. 7-83:		MVI	0(1),0
  detailedInlineBefore (8, "MVI	0(1),0");
  memory[address360A] = 0;
  detailedInlineAfter ();

p7_8:;
  // (9)          CALL INLINE("48", 2, 0, COUNT);      /* LH  2,COUNT */
  address360B = (mZERO_256xCOUNT)&0xFFFFFF;
  // Type RX, p. 7-80:		LH	2,mZERO_256xCOUNT(0,0)
  detailedInlineBefore (9, "LH	2,mZERO_256xCOUNT(0,0)");
  GR[2] = COREHALFWORD (address360B);
  detailedInlineAfter ();

p7_12:;
  // (10)          CALL INLINE("58", 3, 0, MVCTEMP);    /* L   3,MVCTEMP */
  address360B = (mZERO_256xMVCTEMP)&0xFFFFFF;
  // Type RX, p. 7-7:		L	3,mZERO_256xMVCTEMP(0,0)
  detailedInlineBefore (10, "L	3,mZERO_256xMVCTEMP(0,0)");
  GR[3] = COREWORD (address360B);
  detailedInlineAfter ();

p7_16:;
  // (11)          CALL INLINE("44", 2, 0, 3, 0);       /* EX  2,0(0,3) */
  address360B = (GR[3] + 0) & 0xFFFFFF;
  // Type RX, p. 7-74:		EX	2,0(0,3)
  detailedInlineBefore (11, "EX	2,0(0,3)");
  // (12)       CALL INLINE("D2", 0, 0, 1, 1, 1, 0);    /* MVC 1(0,1),0(1) */
  address360A = (GR[1] + 1) & 0xFFFFFF;
  address360B = (GR[1] + 0) & 0xFFFFFF;
  // Type SS, p. 7-83:          MVC     1(0,1),0(1)
  mvc (address360A, address360B, GR[2]);
  detailedInlineAfter ();

p7_20:;
}
}
; // (8) CALL INLINE( 146, 0, 0, 1, 0);
; // (9) CALL INLINE( 72, 2, 0, COUNT);
; // (10) CALL INLINE( 88, 3, 0, MVCTEMP);
; // (11) CALL INLINE( 68, 2, 0, 3, 0);
es2:;
} // End of DO block
// RETURN; (661)
{
  reentryGuard = 0;
  return 0;
}
// MVC: (662)
MVC : {   // (12) CALL INLINE( 210, 0, 0, 1, 1, 1, 0);
        { /*
           * File:      patch12.c
           * For:       ZERO_256.c
           * Notes:     1. Page references are from IBM "ESA/390 Principles of
           *               Operation", SA22-7201-08, Ninth Edition, June 2003.
           *            2. Labels are of the form p%d_%d, where the 1st number
           *               indicates the leading patch number of the block, and
           *               the 2nd is the byte offset of the instruction within
           *               within the block.
           *            3. Known-problematic translations are marked with the
           *               string  "* * * F I X M E * * *" (without spaces).
           * History:   2024-07-18 RSB  Auto-generated by XCOM-I --guess=....
           *                            Inspected.
           */

          p12_0:;
// (12)       CALL INLINE("D2", 0, 0, 1, 1, 1, 0);    /* MVC 1(0,1),0(1) */
address360A = (GR[1] + 1) & 0xFFFFFF;
address360B = (GR[1] + 0) & 0xFFFFFF;
// Type SS, p. 7-83:		MVC	1(0,1),0(1)
detailedInlineBefore (12, "MVC	1(0,1),0(1)");
mvc (address360A, address360B, 0);
detailedInlineAfter ();

p12_6:;
}
}
{
  reentryGuard = 0;
  return 0;
}
}
