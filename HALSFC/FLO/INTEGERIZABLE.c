/*
  File INTEGERIZABLE.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

int32_t
INTEGERIZABLE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INTEGERIZABLE");
  {   // (25) CALL INLINE( 88,1, 0, FOR_DW);
    { /*
       * File:      patch25.c
       * For:       INTEGERIZABLE.c
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

      p25_0:;
  // (25)       CALL INLINE("58",1, 0, FOR_DW);
  address360B = (mFOR_DW)&0xFFFFFF;
  // Type RX, p. 7-7:		L	1,mFOR_DW(0,0)
  detailedInlineBefore (25, "L	1,mFOR_DW(0,0)");
  GR[1] = COREWORD (address360B);
  detailedInlineAfter ();

p25_4:;
  // (26)       CALL INLINE("68", 0, 0, 1, 0);              /* LE 0,0(0,1) */
  address360B = (GR[1] + 0) & 0xFFFFFF;
  // Type RX, p. 9-10:		LD	0,0(0,1)
  detailedInlineBefore (26, "LD	0,0(0,1)");
  FR[0] = fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
  detailedInlineAfter ();

p25_8:;
}
}
; // (26) CALL INLINE( 104, 0, 0, 1, 0);
// IF DW(0) =  4278190080 THEN (1544)
if (1
    & (xEQ (getFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0 + 4 * (0)),
            4278190080)))
  // DO; (1545)
  {
  rs1:;
  // NO_INTEGER: (1546)
  NO_INTEGER:
    // RETURN FALSE; (1547)
    {
      reentryGuard = 0;
      return 0;
    }
  es1:;
  } // End of DO block
// TEMP = ADDR(NO_INTEGER); (1548)
{
  int32_t numberRHS = (int32_t)(-2);
  putFIXED (mINTEGERIZABLExTEMP, numberRHS);
}
// TEMP1 = ADDR(LIT_NEGMAX); (1549)
{
  int32_t numberRHS = (int32_t)(-1);
  putFIXED (mINTEGERIZABLExTEMP1, numberRHS);
}
{   // (27) CALL INLINE( 40, 2, 0);
  { /*
     * File:      patch27.c
     * For:       INTEGERIZABLE.c
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

    p27_0:;
// (27)       CALL INLINE("28", 2, 0);                    /* LDR 2,0     */
// Type RR, p. 9-10:		LDR	2,0
detailedInlineBefore (27, "LDR	2,0");
FR[2] = FR[0];
detailedInlineAfter ();

p27_2:;
// (28)       CALL INLINE("20", 0, 0);                    /* LPDR 0,0    */
// Type RR, p. 18-17:		LPDR	0,0
detailedInlineBefore (28, "LPDR	0,0");
scratchd = fabs (FR[0]);
setCCd ();
FR[0] = scratchd;
detailedInlineAfter ();

p27_4:;
// (29)       CALL INLINE("2B", 4, 4);                    /* SDR 4,4     */
// Type RR, p. 18-23:		SDR	4,4
detailedInlineBefore (29, "SDR	4,4");
scratchd = FR[4] - FR[4];
setCCd ();
FR[4] = scratchd;
detailedInlineAfter ();

p27_6:;
// (30)       CALL INLINE("78", 4, 0, FLT_NEGMAX);        /* LE 4,FLT_NEGMAX */
address360B = (mINTEGERIZABLExFLT_NEGMAX)&0xFFFFFF;
// Type RX, p. 9-10:		LE	4,mINTEGERIZABLExFLT_NEGMAX(0,0)
detailedInlineBefore (30, "LE	4,mINTEGERIZABLExFLT_NEGMAX(0,0)");
FR[4] = fromFloatIBM (COREWORD (address360B), 0);
detailedInlineAfter ();

p27_10:;
// (31)       CALL INLINE("58", 2, 0, TEMP1);             /* L 2,TEMP1   */
address360B = (mINTEGERIZABLExTEMP1)&0xFFFFFF;
// Type RX, p. 7-7:		L	2,mINTEGERIZABLExTEMP1(0,0)
detailedInlineBefore (31, "L	2,mINTEGERIZABLExTEMP1(0,0)");
GR[2] = COREWORD (address360B);
detailedInlineAfter ();

p27_14:;
// (32)       CALL INLINE("29", 4, 2);                    /* CDR 4,2     */
// Type RR, p. 18-10:		CDR	4,2
detailedInlineBefore (32, "CDR	4,2");
scratchd = FR[4] - FR[2];
setCCd ();
detailedInlineAfter ();

p27_16:;
// (33)       CALL INLINE("07", 8, 2);                    /* BCR 8,2     */
// Type RR, p. 7-17:		BCR	8,2
detailedInlineBefore (33, "BCR	8,2");
mask360 = 8;
if ((CC == 0 && (mask360 & 8) != 0) || (CC == 1 && (mask360 & 4) != 0)
    || (CC == 2 && (mask360 & 2) != 0) || (CC == 3 && (mask360 & 1) != 0))
  switch (GR[2])
    {
    case -1:
      goto LIT_NEGMAX;
    case -2:
      goto NO_INTEGER;
    default:
      abend ("Branch address must be a label in this procedure");
    }
detailedInlineAfter ();

p27_18:;
// (34)       CALL INLINE("58", 1, 0, ADDR_ROUNDER);      /* L 1,ADDR_ROUNDER
// */
address360B = (mADDR_ROUNDER)&0xFFFFFF;
// Type RX, p. 7-7:		L	1,mADDR_ROUNDER(0,0)
detailedInlineBefore (34, "L	1,mADDR_ROUNDER(0,0)");
GR[1] = COREWORD (address360B);
detailedInlineAfter ();

p27_22:;
// (35)       CALL INLINE("6A", 0, 0, 1, 0);              /* AD 0,0(0,1) */
address360B = (GR[1] + 0) & 0xFFFFFF;
// Type RX, p. 18-8:		AD	0,0(0,1)
detailedInlineBefore (35, "AD	0,0(0,1)");
scratchd = FR[0];
scratchd += fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
setCCd ();
FR[0] = scratchd;
detailedInlineAfter ();

p27_26:;
// (36)       CALL INLINE("58", 1, 0, ADDR_FIXED_LIMIT);  /* L 1,ADDR__LIMIT */
address360B = (mADDR_FIXED_LIMIT)&0xFFFFFF;
// Type RX, p. 7-7:		L	1,mADDR_FIXED_LIMIT(0,0)
detailedInlineBefore (36, "L	1,mADDR_FIXED_LIMIT(0,0)");
GR[1] = COREWORD (address360B);
detailedInlineAfter ();

p27_30:;
// (37)       CALL INLINE("58", 2, 0, TEMP);              /* L 2,TEMP    */
address360B = (mINTEGERIZABLExTEMP)&0xFFFFFF;
// Type RX, p. 7-7:		L	2,mINTEGERIZABLExTEMP(0,0)
detailedInlineBefore (37, "L	2,mINTEGERIZABLExTEMP(0,0)");
GR[2] = COREWORD (address360B);
detailedInlineAfter ();

p27_34:;
// (38)       CALL INLINE("69", 0, 0, 1, 0);              /* CD 0,0(0,1) */
address360B = (GR[1] + 0) & 0xFFFFFF;
// Type RX, p. 18-10:		CD	0,0(0,1)
detailedInlineBefore (38, "CD	0,0(0,1)");
scratchd = FR[0];
scratchd -= fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
setCCd ();
detailedInlineAfter ();

p27_38:;
// (39)       CALL INLINE("07", 2, 2);                    /* BCR 2,2     */
// Type RR, p. 7-17:		BCR	2,2
detailedInlineBefore (39, "BCR	2,2");
mask360 = 2;
if ((CC == 0 && (mask360 & 8) != 0) || (CC == 1 && (mask360 & 4) != 0)
    || (CC == 2 && (mask360 & 2) != 0) || (CC == 3 && (mask360 & 1) != 0))
  switch (GR[2])
    {
    case -1:
      goto LIT_NEGMAX;
    case -2:
      goto NO_INTEGER;
    default:
      abend ("Branch address must be a label in this procedure");
    }
detailedInlineAfter ();

p27_40:;
}
}
; // (28) CALL INLINE( 32, 0, 0);
; // (29) CALL INLINE( 43, 4, 4);
; // (30) CALL INLINE( 120, 4, 0, FLT_NEGMAX);
; // (31) CALL INLINE( 88, 2, 0, TEMP1);
; // (32) CALL INLINE( 41, 4, 2);
; // (33) CALL INLINE( 7, 8, 2);
; // (34) CALL INLINE( 88, 1, 0, ADDR_ROUNDER);
; // (35) CALL INLINE( 106, 0, 0, 1, 0);
; // (36) CALL INLINE( 88, 1, 0, ADDR_FIXED_LIMIT);
; // (37) CALL INLINE( 88, 2, 0, TEMP);
; // (38) CALL INLINE( 105, 0, 0, 1, 0);
; // (39) CALL INLINE( 7, 2, 2);
// LIT_NEGMAX: (1563)
LIT_NEGMAX
    : {   // (40) CALL INLINE( 88, 1, 0, ADDR_FIXER);
        { /*
           * File:      patch40.c
           * For:       INTEGERIZABLE.c
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

          p40_0:;
// (40)       CALL INLINE("58", 1, 0, ADDR_FIXER);        /* L 1,ADDR_FIXER */
address360B = (mADDR_FIXER)&0xFFFFFF;
// Type RX, p. 7-7:		L	1,mADDR_FIXER(0,0)
detailedInlineBefore (40, "L	1,mADDR_FIXER(0,0)");
GR[1] = COREWORD (address360B);
detailedInlineAfter ();

p40_4:;
// (41)       CALL INLINE("6E", 0, 0, 1, 0);              /* AW 0,0(0,1) */
address360B = (GR[1] + 0) & 0xFFFFFF;
// Type RX, p. 18-10:		AW	0,0(0,1)
detailedInlineBefore (41, "AW	0,0(0,1)");
aw (0, address360B);
detailedInlineAfter ();

p40_8:;
// (42)       CALL INLINE("58", 1, 0, FOR_DW);
address360B = (mFOR_DW)&0xFFFFFF;
// Type RX, p. 7-7:		L	1,mFOR_DW(0,0)
detailedInlineBefore (42, "L	1,mFOR_DW(0,0)");
GR[1] = COREWORD (address360B);
detailedInlineAfter ();

p40_12:;
// (43)       CALL INLINE("60", 0, 0, 1, 8);              /* STD 0,8(0,1) */
address360B = (GR[1] + 8) & 0xFFFFFF;
// Type RX, p. 9-11:		STD	0,8(0,1)
detailedInlineBefore (43, "STD	0,8(0,1)");
std (0, address360B);
detailedInlineAfter ();

p40_16:;
// (44)       CALL INLINE("70", 2, 0, 1, 8);              /* STE 2,8(0,1) */
address360B = (GR[1] + 8) & 0xFFFFFF;
// Type RX, p. 9-11:		STE	2,8(0,1)
detailedInlineBefore (44, "STE	2,8(0,1)");
toFloatIBM (&msw360, &lsw360, FR[2]);
COREWORD2 (address360B, msw360);
detailedInlineAfter ();

p40_20:;
}
}
; // (41) CALL INLINE( 110, 0, 0, 1, 0);
; // (42) CALL INLINE( 88, 1, 0, FOR_DW);
; // (43) CALL INLINE( 96, 0, 0, 1, 8);
; // (44) CALL INLINE( 112, 2, 0, 1, 8);
// NEGLIT = SHR(DW(2), 31); (1569)
{
  int32_t numberRHS = (int32_t)(SHR (
      getFIXED (getFIXED (mFOR_DW) + 4 * (2) + 0 + 4 * (0)), 31));
  descriptor_t *bitRHS;
  bitRHS = fixedToBit (32, (int32_t)(numberRHS));
  putBIT (8, mINTEGERIZABLExNEGLIT, bitRHS);
  bitRHS->inUse = 0;
}
// IF NEGLIT THEN (1570)
if (1 & (bitToFixed (getBIT (8, mINTEGERIZABLExNEGLIT))))
  // DO; (1571)
  {
  rs2:;
    // IF DW(3) ~= NEGMAX THEN (1572)
    if (1
        & (xNEQ (getFIXED (getFIXED (mFOR_DW) + 4 * (3) + 0 + 4 * (0)),
                 getFIXED (mINTEGERIZABLExNEGMAX))))
      // DW(3) = -DW(3); (1573)
      {
        int32_t numberRHS = (int32_t)(xminus (
            getFIXED (getFIXED (mFOR_DW) + 4 * (3) + 0 + 4 * (0))));
        putFIXED (getFIXED (mFOR_DW) + 4 * (3) + 0 + 4 * (0), numberRHS);
      }
  es2:;
  } // End of DO block
// RETURN TRUE; (1574)
{
  reentryGuard = 0;
  return 1;
}
}
