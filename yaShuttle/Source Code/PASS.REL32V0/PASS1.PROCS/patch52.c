{
  // File:      patch52.c
  // For:       SAVE_LITERAL.c
  // Notes:     1. Page references are from IBM "ESA/390 Principles of
  //               Operation", SA22-7201-08, Ninth Edition, June 2003.
  //            2. Labels are of the form p%d_%d, where the 1st number
  //               indicates the leading patch number of the block, and
  //               the 2nd is the byte offset of the instruction within
  //               within the block.
  //            3. Known-problematic translations are marked with the
  //               string  "* * * F I X M E * * *" (without spaces).
  // History:   2024-07-17 RSB  Auto-generated by XCOM-I --guess=....
  //                            Fixed the self-modifying code.

p52_0: ;
  // (52)             CALL INLINE("58",1,0,VAL);              /* L    1,VAL        */     
  address360B = (mSAVE_LITERALxVAL) & 0xFFFFFF;
  // Type RX, p. 7-7:		L	1,mSAVE_LITERALxVAL(0,0)
  detailedInlineBefore(52, "L	1,mSAVE_LITERALxVAL(0,0)");
  GR[1] = COREWORD(address360B);
  detailedInlineAfter();

p52_4: ;
  // (53)             CALL INLINE("58",2,0,LIT_CHAR_AD);      /* L    2,LIT_CHAR_AD */    
  address360B = (mCOMM) & 0xFFFFFF;
  // Type RX, p. 7-7:		L	2,mCOMM(0,0)
  detailedInlineBefore(53, "L	2,mCOMM(0,0)");
  GR[2] = COREWORD(address360B);
  detailedInlineAfter();

p52_8: ;
  // (54)             CALL INLINE("58",3,0,SIZE);             /* L    3,SIZE        */    
  address360B = (mSAVE_LITERALxSIZE) & 0xFFFFFF;
  // Type RX, p. 7-7:		L	3,mSAVE_LITERALxSIZE(0,0)
  detailedInlineBefore(54, "L	3,mSAVE_LITERALxSIZE(0,0)");
  GR[3] = COREWORD(address360B);
  detailedInlineAfter();

p52_12: ;
/*
 * This inline copies the MSB of the FIXED VAL, a string descriptor, into the
 * Length-1 fields of the MVC of patch56.c.  I find it expedient to merge this
 * into patch56.c and do nothing here.
 */
#if 0
  // (55)             CALL INLINE("D2",0,0,3,1,VAL);          /* MVC  1(0,3),VAL    */    
  address360A = (GR[3] + 1) & 0xFFFFFF;
  address360B = (mSAVE_LITERALxVAL) & 0xFFFFFF;
  // Type SS, p. 7-83:		MVC	1(0,3),mSAVE_LITERALxVAL(0)
  detailedInlineBefore(55, "MVC	1(0,3),mSAVE_LITERALxVAL(0)");
  mvc(address360A, address360B, 0);
  detailedInlineAfter();
#endif

p52_18: ;
}