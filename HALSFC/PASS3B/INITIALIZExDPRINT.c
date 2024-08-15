/*
  File INITIALIZExDPRINT.c generated by XCOM-I, 2024-08-09 12:42:16.
*/

#include "runtimeC.h"

int32_t
INITIALIZExDPRINT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INITIALIZExDPRINT");
  // IF DLIST THEN (2592)
  if (1 & (bitToFixed (getBIT (1, mDLIST))))
    // DO; (2593)
    {
    rs1:;
      // S1 = FORMAT((#DEL_SYMBOLS + 1),4); (2594)
      {
        descriptor_t *stringRHS;
        stringRHS
            = (putFIXED (mFORMATxIVAL, xadd (COREHALFWORD (mpDEL_SYMBOLS), 1)),
               putFIXED (mFORMATxN, 4), FORMAT (0));
        putCHARACTER (mINITIALIZExDPRINTxS1, stringRHS);
        stringRHS->inUse = 0;
      }
      // S2 = FORMAT(REASON#,2); (2595)
      {
        descriptor_t *stringRHS;
        stringRHS = (putFIXED (mFORMATxIVAL,
                               COREHALFWORD (mINITIALIZExDPRINTxREASONp)),
                     putFIXED (mFORMATxN, 2), FORMAT (0));
        putCHARACTER (mINITIALIZExDPRINTxS2, stringRHS);
        stringRHS->inUse = 0;
      }
      // S3 = SYT_NAME(OP1); (2596)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (getFIXED (mSYM_TAB)
                                  + 34 * (COREHALFWORD (mOP1)) + 0 + 4 * (0));
        putCHARACTER (mINITIALIZExDPRINTxS3, stringRHS);
        stringRHS->inUse = 0;
      }
      // K = LENGTH(S3); (2597)
      {
        int32_t numberRHS
            = (int32_t)(LENGTH (getCHARACTER (mINITIALIZExDPRINTxS3)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mINITIALIZExDPRINTxK, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF K < 32 THEN (2598)
      if (1 & (xLT (COREHALFWORD (mINITIALIZExDPRINTxK), 32)))
        // S3 = S3 || SUBSTR(X72,0,32-K); (2599)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (
              getCHARACTER (mINITIALIZExDPRINTxS3),
              SUBSTR (getCHARACTER (mX72), 0,
                      xsubtract (32, COREHALFWORD (mINITIALIZExDPRINTxK))));
          putCHARACTER (mINITIALIZExDPRINTxS3, stringRHS);
          stringRHS->inUse = 0;
        }
      // S4 = REASONS(REASON#); (2600)
      {
        descriptor_t *stringRHS;
        stringRHS
            = getCHARACTER (mINITIALIZExDPRINTxREASONS
                            + 4 * COREHALFWORD (mINITIALIZExDPRINTxREASONp));
        putCHARACTER (mINITIALIZExDPRINTxS4, stringRHS);
        stringRHS->inUse = 0;
      }
      // OUTPUT = X2||'#: '||S1||X2||'REASON: '||S2||X4||S3||X4||S4; (2601)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            xsCAT (
                xsCAT (
                    xsCAT (
                        xsCAT (
                            xsCAT (xsCAT (xsCAT (xsCAT (getCHARACTER (mX2),
                                                        cToDescriptor (NULL,
                                                                       "#: ")),
                                                 getCHARACTER (
                                                     mINITIALIZExDPRINTxS1)),
                                          getCHARACTER (mX2)),
                                   cToDescriptor (NULL, "REASON: ")),
                            getCHARACTER (mINITIALIZExDPRINTxS2)),
                        getCHARACTER (mX4)),
                    getCHARACTER (mINITIALIZExDPRINTxS3)),
                getCHARACTER (mX4)),
            getCHARACTER (mINITIALIZExDPRINTxS4));
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (2602)
  else
    // IF (REASON#=0)|(REASON#=3) THEN (2603)
    if (1
        & (xOR (xEQ (COREHALFWORD (mINITIALIZExDPRINTxREASONp), 0),
                xEQ (COREHALFWORD (mINITIALIZExDPRINTxREASONp), 3))))
      // DO; (2604)
      {
      rs2:;
        // IF ~HDR_FLAG THEN (2605)
        if (1 & (xNOT (BYTE0 (mINITIALIZExDPRINTxHDR_FLAG))))
          // DO; (2606)
          {
          rs2s1:;
            // HDR_FLAG = TRUE; (2607)
            {
              int32_t numberRHS = (int32_t)(1);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (1, mINITIALIZExDPRINTxHDR_FLAG, bitRHS);
              bitRHS->inUse = 0;
            }
            // OUTPUT = X1; (2608)
            {
              descriptor_t *stringRHS;
              stringRHS = getCHARACTER (mX1);
              OUTPUT (0, stringRHS);
              stringRHS->inUse = 0;
            }
            // OUTPUT='*** THE FOLLOWING COMPILATION TEMPLATES WERE INCLUDED
            // BUT MAY NOT HAVE BEEN USED ***'; (2609)
            {
              descriptor_t *stringRHS;
              stringRHS = cToDescriptor (
                  NULL, "*** THE FOLLOWING COMPILATION TEMPLATES WERE "
                        "INCLUDED BUT MAY NOT HAVE BEEN USED ***");
              OUTPUT (0, stringRHS);
              stringRHS->inUse = 0;
            }
            // OUTPUT = X1; (2610)
            {
              descriptor_t *stringRHS;
              stringRHS = getCHARACTER (mX1);
              OUTPUT (0, stringRHS);
              stringRHS->inUse = 0;
            }
          es2s1:;
          } // End of DO block
        // OUTPUT = X6||SYT_NAME(OP1); (2611)
        {
          descriptor_t *stringRHS;
          stringRHS = xsCAT (getCHARACTER (mX6),
                             getCHARACTER (getFIXED (mSYM_TAB)
                                           + 34 * (COREHALFWORD (mOP1)) + 0
                                           + 4 * (0)));
          OUTPUT (0, stringRHS);
          stringRHS->inUse = 0;
        }
      es2:;
      } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}