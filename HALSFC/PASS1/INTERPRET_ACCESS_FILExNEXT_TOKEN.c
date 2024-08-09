/*
  File INTERPRET_ACCESS_FILExNEXT_TOKEN.c generated by XCOM-I, 2024-08-09
  12:38:15.
*/

#include "runtimeC.h"

int32_t
INTERPRET_ACCESS_FILExNEXT_TOKEN (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "INTERPRET_ACCESS_FILExNEXT_TOKEN");
  // DO WHILE BYTE(S, CP) = BYTE(X1); (2804)
  while (1
         & (xEQ (BYTE (getCHARACTER (mINTERPRET_ACCESS_FILExS),
                       COREHALFWORD (mINTERPRET_ACCESS_FILExCP)),
                 BYTE1 (getCHARACTER (mX1)))))
    {
      // CALL ADVANCE_CP; (2805)
      INTERPRET_ACCESS_FILExADVANCE_CP (0);
    } // End of DO WHILE block
  // A_TOKEN = ''; (2806)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "");
    putCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN, stringRHS);
    stringRHS->inUse = 0;
  }
  // DO WHILE LETTER_OR_DIGIT(BYTE(S, CP)); (2807)
  while (1
         & (bitToFixed (getBIT (
             1, mLETTER_OR_DIGIT
                    + 1
                          * BYTE (getCHARACTER (mINTERPRET_ACCESS_FILExS),
                                  COREHALFWORD (mINTERPRET_ACCESS_FILExCP))))))
    {
      // A_TOKEN=A_TOKEN||SUBSTR(S,CP,1); (2808)
      {
        descriptor_t *stringRHS;
        stringRHS
            = xsCAT (getCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN),
                     SUBSTR (getCHARACTER (mINTERPRET_ACCESS_FILExS),
                             COREHALFWORD (mINTERPRET_ACCESS_FILExCP), 1));
        putCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN, stringRHS);
        stringRHS->inUse = 0;
      }
      // CALL ADVANCE_CP; (2809)
      INTERPRET_ACCESS_FILExADVANCE_CP (0);
    } // End of DO WHILE block
  // IF LENGTH(A_TOKEN) ~= 0 THEN (2810)
  if (1 & (xNEQ (LENGTH (getCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN)), 0)))
    // RETURN 0; (2811)
    {
      reentryGuard = 0;
      return 0;
    }
  // DO I = 1 TO NUM_DELIMETERS; (2812)
  {
    int32_t from56, to56, by56;
    from56 = 1;
    to56 = 3;
    by56 = 1;
    for (putBIT (16, mINTERPRET_ACCESS_FILExNEXT_TOKENxI,
                 fixedToBit (16, from56));
         bitToFixed (getBIT (16, mINTERPRET_ACCESS_FILExNEXT_TOKENxI)) <= to56;
         putBIT (16, mINTERPRET_ACCESS_FILExNEXT_TOKENxI,
                 fixedToBit (16, bitToFixed (getBIT (
                                     16, mINTERPRET_ACCESS_FILExNEXT_TOKENxI))
                                     + by56)))
      {
        // IF BYTE(S,CP)=DELIMETERS(I) THEN (2813)
        if (1
            & (xEQ (BYTE (getCHARACTER (mINTERPRET_ACCESS_FILExS),
                          COREHALFWORD (mINTERPRET_ACCESS_FILExCP)),
                    BYTE0 (mINTERPRET_ACCESS_FILExNEXT_TOKENxDELIMETERS
                           + 1
                                 * COREHALFWORD (
                                     mINTERPRET_ACCESS_FILExNEXT_TOKENxI)))))
          // DO; (2814)
          {
          rs3s1:;
            // CALL ADVANCE_CP; (2815)
            INTERPRET_ACCESS_FILExADVANCE_CP (0);
            // RETURN I; (2816)
            {
              reentryGuard = 0;
              return COREHALFWORD (mINTERPRET_ACCESS_FILExNEXT_TOKENxI);
            }
          es3s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // CALL ADVANCE_CP; (2817)
  INTERPRET_ACCESS_FILExADVANCE_CP (0);
  // RETURN NUM_DELIMETERS + 1; (2818)
  {
    reentryGuard = 0;
    return 4;
  }
}
