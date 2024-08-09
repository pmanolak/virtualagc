/*
  File SYT_DUMPxADD_ATTR.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
SYT_DUMPxADD_ATTR (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SYT_DUMPxADD_ATTR");
  // IF LENGTH(S) + LENGTH(ATTR) + 2 > 132 THEN (5923)
  if (1
      & (xGT (xadd (xadd (LENGTH (getCHARACTER (mSYT_DUMPxS)),
                          LENGTH (getCHARACTER (mSYT_DUMPxADD_ATTRxATTR))),
                    2),
              132)))
    // DO; (5924)
    {
    rs1:;
      // OUTPUT = S; (5925)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mSYT_DUMPxS);
        OUTPUT (0, stringRHS);
        stringRHS->inUse = 0;
      }
      // S = SUBSTR(X70, 0, ATTR_START); (5926)
      {
        descriptor_t *stringRHS;
        stringRHS = SUBSTR (getCHARACTER (mX70), 0,
                            COREHALFWORD (mSYT_DUMPxATTR_START));
        putCHARACTER (mSYT_DUMPxS, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // S = S || ATTR || ', '; (5927)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (xsCAT (getCHARACTER (mSYT_DUMPxS),
                              getCHARACTER (mSYT_DUMPxADD_ATTRxATTR)),
                       cToDescriptor (NULL, ", "));
    putCHARACTER (mSYT_DUMPxS, stringRHS);
    stringRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
