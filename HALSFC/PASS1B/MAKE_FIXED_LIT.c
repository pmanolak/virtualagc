/*
  File MAKE_FIXED_LIT.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
MAKE_FIXED_LIT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "MAKE_FIXED_LIT");
  // PTR=GET_LITERAL(PTR); (1208)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (mGET_LITERALxPTR, getFIXED (mMAKE_FIXED_LITxPTR)),
        GET_LITERAL (0)));
    putFIXED (mMAKE_FIXED_LITxPTR, numberRHS);
  }
  // DW(0)=LIT2(PTR); (1209)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 520
                              + 4 * (getFIXED (mMAKE_FIXED_LITxPTR))));
    putFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0 + 4 * (0), numberRHS);
  }
  // DW(1)=LIT3(PTR); (1210)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (getFIXED (mLIT_PG) + 1560 * (0) + 1040
                              + 4 * (getFIXED (mMAKE_FIXED_LITxPTR))));
    putFIXED (getFIXED (mFOR_DW) + 4 * (1) + 0 + 4 * (0), numberRHS);
  }
  // PTR=ADDR(LIMIT_OK); (1211)
  {
    int32_t numberRHS = (int32_t)(-1);
    putFIXED (mMAKE_FIXED_LITxPTR, numberRHS);
  }
  {   // (33) CALL INLINE( 88,3,0,DW_AD);
    { // File:      patch33.c
      // For:       MAKE_FIXED_LIT.c
      // Notes:     1. Page references are from IBM "ESA/390 Principles of
      //               Operation", SA22-7201-08, Ninth Edition, June 2003.
      //            2. Labels are of the form p%d_%d, where the 1st number
      //               indicates the leading patch number of the block, and
      //               the 2nd is the byte offset of the instruction within
      //               within the block.
      //            3. Known-problematic translations are marked with the
      //               string  "* * * F I X M E * * *" (without spaces).
      // History:   2024-07-17 RSB  Auto-generated by XCOM-I --guess=....
      //                            Inspected.

      p33_0:;
  // (33)       CALL INLINE("58",3,0,DW_AD);             /*  L    3,DW_AD */
  address360B = (mDW_AD)&0xFFFFFF;
  // Type RX, p. 7-7:		L	3,mDW_AD(0,0)
  detailedInlineBefore (33, "L	3,mDW_AD(0,0)");
  GR[3] = COREWORD (address360B);
  detailedInlineAfter ();

p33_4:;
  // (34)       CALL INLINE("68",0,0,3,0);               /*  LD   0,0(0,3) */
  address360B = (GR[3] + 0) & 0xFFFFFF;
  // Type RX, p. 9-10:		LD	0,0(0,3)
  detailedInlineBefore (34, "LD	0,0(0,3)");
  FR[0] = fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
  detailedInlineAfter ();

p33_8:;
  // (35)       CALL INLINE("20", 0, 0);                            /* LPDR 0,0
  // */ Type RR, p. 18-17:		LPDR	0,0
  detailedInlineBefore (35, "LPDR	0,0");
  scratchd = fabs (FR[0]);
  setCCd ();
  FR[0] = scratchd;
  detailedInlineAfter ();

p33_10:;
  // (36)       CALL INLINE("58", 1, 0, ADDR_ROUNDER);/* L   1,ADDR_ROUNDER */
  address360B = (mADDR_ROUNDER)&0xFFFFFF;
  // Type RX, p. 7-7:		L	1,mADDR_ROUNDER(0,0)
  detailedInlineBefore (36, "L	1,mADDR_ROUNDER(0,0)");
  GR[1] = COREWORD (address360B);
  detailedInlineAfter ();

p33_14:;
  // (37)       CALL INLINE("6A", 0, 0, 1, 0);        /* AD  0,0(0,1) */
  address360B = (GR[1] + 0) & 0xFFFFFF;
  // Type RX, p. 18-8:		AD	0,0(0,1)
  detailedInlineBefore (37, "AD	0,0(0,1)");
  scratchd = FR[0];
  scratchd
      += fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
  setCCd ();
  FR[0] = scratchd;
  detailedInlineAfter ();

p33_18:;
  // (38)       CALL INLINE("58", 1, 0, ADDR_FIXED_LIMIT);/* L
  // 1,ADDR_FIXED_LIMIT   */
  address360B = (mADDR_FIXED_LIMIT)&0xFFFFFF;
  // Type RX, p. 7-7:		L	1,mADDR_FIXED_LIMIT(0,0)
  detailedInlineBefore (38, "L	1,mADDR_FIXED_LIMIT(0,0)");
  GR[1] = COREWORD (address360B);
  detailedInlineAfter ();

p33_22:;
  // (39)       CALL INLINE("58",2,0,PTR);                   /*   L   2,  PTR
  // */
  address360B = (mMAKE_FIXED_LITxPTR)&0xFFFFFF;
  // Type RX, p. 7-7:		L	2,mMAKE_FIXED_LITxPTR(0,0)
  detailedInlineBefore (39, "L	2,mMAKE_FIXED_LITxPTR(0,0)");
  GR[2] = COREWORD (address360B);
  detailedInlineAfter ();

p33_26:;
  // (40)       CALL INLINE("69", 0, 0, 1, 0);        /* CD  0,0(0,1) */
  address360B = (GR[1] + 0) & 0xFFFFFF;
  // Type RX, p. 18-10:		CD	0,0(0,1)
  detailedInlineBefore (40, "CD	0,0(0,1)");
  scratchd = FR[0];
  scratchd
      -= fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
  setCCd ();
  detailedInlineAfter ();

p33_30:;
  // (41)       CALL INLINE("07",12,2);                  /*  BNHR 2 */ Type RR,
  // p. 7-17:		BCR	12,2
  detailedInlineBefore (41, "BCR	12,2");
  mask360 = 12;
  if ((CC == 0 && (mask360 & 8) != 0) || (CC == 1 && (mask360 & 4) != 0)
      || (CC == 2 && (mask360 & 2) != 0) || (CC == 3 && (mask360 & 1) != 0))
    switch (GR[2])
      {
      case -1:
        goto LIMIT_OK;
      default:
        abend ("Branch address must be a label in this procedure");
      }
  detailedInlineAfter ();

p33_32:;
  // (42)       CALL INLINE("68",0,0,1,0);               /*  LD   0,0(0,1) */
  address360B = (GR[1] + 0) & 0xFFFFFF;
  // Type RX, p. 9-10:		LD	0,0(0,1)
  detailedInlineBefore (42, "LD	0,0(0,1)");
  FR[0] = fromFloatIBM (COREWORD (address360B), COREWORD (address360B + 4));
  detailedInlineAfter ();

p33_36:;
}
}
; // (34) CALL INLINE( 104,0,0,3,0);
; // (35) CALL INLINE( 32, 0, 0);
; // (36) CALL INLINE( 88, 1, 0, ADDR_ROUNDER);
; // (37) CALL INLINE( 106, 0, 0, 1, 0);
; // (38) CALL INLINE( 88, 1, 0, ADDR_FIXED_LIMIT);
; // (39) CALL INLINE( 88,2,0,PTR);
; // (40) CALL INLINE( 105, 0, 0, 1, 0);
; // (41) CALL INLINE( 7,12,2);
; // (42) CALL INLINE( 104,0,0,1,0);
// LIMIT_OK: (1222)
LIMIT_OK
    : {   // (43) CALL INLINE( 88, 1, 0, ADDR_FIXER);
        { // File:      patch43.c
          // For:       MAKE_FIXED_LIT.c
          // Notes:     1. Page references are from IBM "ESA/390 Principles of
          //               Operation", SA22-7201-08, Ninth Edition, June 2003.
          //            2. Labels are of the form p%d_%d, where the 1st number
          //               indicates the leading patch number of the block, and
          //               the 2nd is the byte offset of the instruction within
          //               within the block.
          //            3. Known-problematic translations are marked with the
          //               string  "* * * F I X M E * * *" (without spaces).
          // History:   2024-07-17 RSB  Auto-generated by XCOM-I --guess=....
          //                            Inspected.

          p43_0:;
// (43)       CALL INLINE("58", 1, 0, ADDR_FIXER);  /* L   1,ADDR_FIXER */
address360B = (mADDR_FIXER)&0xFFFFFF;
// Type RX, p. 7-7:		L	1,mADDR_FIXER(0,0)
detailedInlineBefore (43, "L	1,mADDR_FIXER(0,0)");
GR[1] = COREWORD (address360B);
detailedInlineAfter ();

p43_4:;
// (44)       CALL INLINE("6E", 0, 0, 1, 0);        /* AW  0,0(0,1) */
address360B = (GR[1] + 0) & 0xFFFFFF;
// Type RX, p. 18-10:		AW	0,0(0,1)
detailedInlineBefore (44, "AW	0,0(0,1)");
aw (0, address360B);
detailedInlineAfter ();

p43_8:;
// (45)       CALL INLINE("60",0,0,3,8);                   /*  STD 0,8(0,3) */
address360B = (GR[3] + 8) & 0xFFFFFF;
// Type RX, p. 9-11:		STD	0,8(0,3)
detailedInlineBefore (45, "STD	0,8(0,3)");
std (0, address360B);
detailedInlineAfter ();

p43_12:;
}
}
; // (44) CALL INLINE( 110, 0, 0, 1, 0);
; // (45) CALL INLINE( 96,0,0,3,8);
// IF SHR(DW(0),31) THEN (1226)
if (1 & (SHR (getFIXED (getFIXED (mFOR_DW) + 4 * (0) + 0 + 4 * (0)), 31)))
  // RETURN -DW(3); (1227)
  {
    reentryGuard = 0;
    return xminus (getFIXED (getFIXED (mFOR_DW) + 4 * (3) + 0 + 4 * (0)));
  }
// RETURN DW(3); (1228)
{
  reentryGuard = 0;
  return getFIXED (getFIXED (mFOR_DW) + 4 * (3) + 0 + 4 * (0));
}
}