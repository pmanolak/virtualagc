/*
  File GENERATExDROPSAVE.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExDROPSAVE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExDROPSAVE");
  // IF FORM(ENTRY) ~= WORK THEN (3958)
  if (1
      & (xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mGENERATExDROPSAVExENTRY))
                             + 32 + 2 * (0)),
               BYTE0 (mWORK))))
    // RETURN; (3959)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF (NR_STACK(ENTRY)>0) THEN (3960)
  if (1
      & (xGT (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExDROPSAVExENTRY))
                            + 56 + 2 * (0)),
              0)))
    // DO; (3961)
    {
    rs1:;
      // I = NR_STACK(ENTRY); (3962)
      {
        descriptor_t *bitRHS
            = getBIT (16, getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExDROPSAVExENTRY))
                              + 56 + 2 * (0));
        putBIT (16, mGENERATExDROPSAVExI, bitRHS);
        bitRHS->inUse = 0;
      }
      // NR_STACK(ENTRY) = 0; (3963)
      {
        int32_t numberRHS = (int32_t)(0);
        putBIT (16,
                getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExDROPSAVExENTRY)) + 56
                    + 2 * (0),
                fixedToBit (16, numberRHS));
      }
      // ENTRY = I; (3964)
      {
        descriptor_t *bitRHS = getBIT (16, mGENERATExDROPSAVExI);
        putBIT (16, mGENERATExDROPSAVExENTRY, bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // ELSE (3965)
  else
    // ENTRY = LOC(ENTRY); (3966)
    {
      descriptor_t *bitRHS
          = getBIT (16, getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExDROPSAVExENTRY))
                            + 40 + 2 * (0));
      putBIT (16, mGENERATExDROPSAVExENTRY, bitRHS);
      bitRHS->inUse = 0;
    }
  // IF ENTRY <= 0 THEN (3967)
  if (1 & (xLE (COREHALFWORD (mGENERATExDROPSAVExENTRY), 0)))
    // RETURN; (3968)
    {
      reentryGuard = 0;
      return 0;
    }
  // WORK_USAGE(ENTRY) = WORK_USAGE(ENTRY) - 1; (3969)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        COREHALFWORD (mWORK_USAGE
                      + 2 * COREHALFWORD (mGENERATExDROPSAVExENTRY)),
        1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mWORK_USAGE + 2 * (COREHALFWORD (mGENERATExDROPSAVExENTRY)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // IF WORK_USAGE(ENTRY) > 0 THEN (3970)
  if (1
      & (xGT (COREHALFWORD (mWORK_USAGE
                            + 2 * COREHALFWORD (mGENERATExDROPSAVExENTRY)),
              0)))
    // RETURN; (3971)
    {
      reentryGuard = 0;
      return 0;
    }
  // DO I = PTRARG1 TO RM; (3972)
  {
    int32_t from53, to53, by53;
    from53 = bitToFixed (getBIT (8, mPTRARG1));
    to53 = getFIXED (mRM);
    by53 = 1;
    for (putBIT (16, mGENERATExDROPSAVExI, fixedToBit (16, from53));
         bitToFixed (getBIT (16, mGENERATExDROPSAVExI)) <= to53;
         putBIT (16, mGENERATExDROPSAVExI,
                 fixedToBit (16, bitToFixed (getBIT (16, mGENERATExDROPSAVExI))
                                     + by53)))
      {
        // IF USAGE(I) THEN (3973)
        if (1
            & (bitToFixed (getBIT (
                16, mUSAGE + 2 * COREHALFWORD (mGENERATExDROPSAVExI)))))
          // IF R_CONTENTS(I) = WORK THEN (3974)
          if (1
              & (xEQ (BYTE0 (mR_CONTENTS
                             + 1 * COREHALFWORD (mGENERATExDROPSAVExI)),
                      BYTE0 (mWORK))))
            // IF R_VAR(I) = ENTRY THEN (3975)
            if (1
                & (xEQ (COREHALFWORD (
                            mR_VAR + 2 * COREHALFWORD (mGENERATExDROPSAVExI)),
                        COREHALFWORD (mGENERATExDROPSAVExENTRY))))
              // CALL UNRECOGNIZABLE(I); (3976)
              {
                putBITp (16, mGENERATExUNRECOGNIZABLExR,
                         getBIT (16, mGENERATExDROPSAVExI));
                GENERATExUNRECOGNIZABLE (0);
              }
      }
  } // End of DO for-loop block
  // DO I = 1 TO DOLEVEL; (3977)
  {
    int32_t from54, to54, by54;
    from54 = 1;
    to54 = bitToFixed (getBIT (16, mDOLEVEL));
    by54 = 1;
    for (putBIT (16, mGENERATExDROPSAVExI, fixedToBit (16, from54));
         bitToFixed (getBIT (16, mGENERATExDROPSAVExI)) <= to54;
         putBIT (16, mGENERATExDROPSAVExI,
                 fixedToBit (16, bitToFixed (getBIT (16, mGENERATExDROPSAVExI))
                                     + by54)))
      {
        // IF DOTEMPBLK(I) > WORK_BLK(ENTRY) | DOTEMPBLK(I) = WORK_BLK(ENTRY) &
        // DOTEMPCTR(I) >= WORK_CTR(ENTRY) THEN (3978)
        if (1
            & (xOR (
                xGT (COREHALFWORD (mGENERATExDOTEMPBLK
                                   + 2 * COREHALFWORD (mGENERATExDROPSAVExI)),
                     COREHALFWORD (
                         mWORK_BLK
                         + 2 * COREHALFWORD (mGENERATExDROPSAVExENTRY))),
                xAND (
                    xEQ (COREHALFWORD (
                             mGENERATExDOTEMPBLK
                             + 2 * COREHALFWORD (mGENERATExDROPSAVExI)),
                         COREHALFWORD (
                             mWORK_BLK
                             + 2 * COREHALFWORD (mGENERATExDROPSAVExENTRY))),
                    xGE (
                        COREHALFWORD (
                            mGENERATExDOTEMPCTR
                            + 2 * COREHALFWORD (mGENERATExDROPSAVExI)),
                        COREHALFWORD (
                            mWORK_CTR
                            + 2 * COREHALFWORD (mGENERATExDROPSAVExENTRY)))))))
          // DO; (3979)
          {
          rs3s1:;
            // J = DOTEMP(I); (3980)
            {
              descriptor_t *bitRHS
                  = getBIT (16, mGENERATExDOTEMP
                                    + 2 * COREHALFWORD (mGENERATExDROPSAVExI));
              putBIT (16, mGENERATExDROPSAVExJ, bitRHS);
              bitRHS->inUse = 0;
            }
            // DO WHILE J > 0; (3981)
            while (1 & (xGT (COREHALFWORD (mGENERATExDROPSAVExJ), 0)))
              {
                // IF J = ENTRY THEN (3982)
                if (1
                    & (xEQ (COREHALFWORD (mGENERATExDROPSAVExJ),
                            COREHALFWORD (mGENERATExDROPSAVExENTRY))))
                  // RETURN; (3983)
                  {
                    reentryGuard = 0;
                    return 0;
                  }
                // J = ARRAYPOINT(J); (3984)
                {
                  descriptor_t *bitRHS = getBIT (
                      16,
                      mARRAYPOINT + 2 * COREHALFWORD (mGENERATExDROPSAVExJ));
                  putBIT (16, mGENERATExDROPSAVExJ, bitRHS);
                  bitRHS->inUse = 0;
                }
              } // End of DO WHILE block
            // ARRAYPOINT(ENTRY) = DOTEMP(I); (3985)
            {
              descriptor_t *bitRHS
                  = getBIT (16, mGENERATExDOTEMP
                                    + 2 * COREHALFWORD (mGENERATExDROPSAVExI));
              putBIT (16,
                      mARRAYPOINT
                          + 2 * (COREHALFWORD (mGENERATExDROPSAVExENTRY)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // DOTEMP(I) = ENTRY; (3986)
            {
              descriptor_t *bitRHS = getBIT (16, mGENERATExDROPSAVExENTRY);
              putBIT (16,
                      mGENERATExDOTEMP
                          + 2 * (COREHALFWORD (mGENERATExDROPSAVExI)),
                      bitRHS);
              bitRHS->inUse = 0;
            }
            // RETURN; (3987)
            {
              reentryGuard = 0;
              return 0;
            }
          es3s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  // DO I = 0 TO CALL_LEVEL; (3988)
  {
    int32_t from55, to55, by55;
    from55 = 0;
    to55 = bitToFixed (getBIT (16, mCALL_LEVEL));
    by55 = 1;
    for (putBIT (16, mGENERATExDROPSAVExI, fixedToBit (16, from55));
         bitToFixed (getBIT (16, mGENERATExDROPSAVExI)) <= to55;
         putBIT (16, mGENERATExDROPSAVExI,
                 fixedToBit (16, bitToFixed (getBIT (16, mGENERATExDROPSAVExI))
                                     + by55)))
      {
        // IF DOCOPY(I) > 0 THEN (3989)
        if (1
            & (xGT (COREHALFWORD (mDOCOPY
                                  + 2 * COREHALFWORD (mGENERATExDROPSAVExI)),
                    0)))
          // IF DOBLK(I) > WORK_BLK(ENTRY) | DOBLK(I) = WORK_BLK(ENTRY) &
          // DOCTR(I) >= WORK_CTR(ENTRY) | CALL_CONTEXT(I) > 1 THEN (3990)
          if (1
              & (xOR (
                  xOR (
                      xGT (COREHALFWORD (
                               mGENERATExDOBLK
                               + 2 * COREHALFWORD (mGENERATExDROPSAVExI)),
                           COREHALFWORD (
                               mWORK_BLK
                               + 2 * COREHALFWORD (mGENERATExDROPSAVExENTRY))),
                      xAND (
                          xEQ (COREHALFWORD (
                                   mGENERATExDOBLK
                                   + 2 * COREHALFWORD (mGENERATExDROPSAVExI)),
                               COREHALFWORD (
                                   mWORK_BLK
                                   + 2
                                         * COREHALFWORD (
                                             mGENERATExDROPSAVExENTRY))),
                          xGE (COREHALFWORD (
                                   mGENERATExDOCTR
                                   + 2 * COREHALFWORD (mGENERATExDROPSAVExI)),
                               COREHALFWORD (
                                   mWORK_CTR
                                   + 2
                                         * COREHALFWORD (
                                             mGENERATExDROPSAVExENTRY))))),
                  xGT (
                      COREHALFWORD (mGENERATExCALL_CONTEXT
                                    + 2 * COREHALFWORD (mGENERATExDROPSAVExI)),
                      1))))
            // DO; (3991)
            {
            rs4s1:;
              // I = SDOLEVEL(I); (3992)
              {
                descriptor_t *bitRHS = getBIT (
                    16, mGENERATExSDOLEVEL
                            + 2 * COREHALFWORD (mGENERATExDROPSAVExI));
                putBIT (16, mGENERATExDROPSAVExI, bitRHS);
                bitRHS->inUse = 0;
              }
              // J = SDOTEMP(I); (3993)
              {
                descriptor_t *bitRHS = getBIT (
                    16, mGENERATExSDOTEMP
                            + 2 * COREHALFWORD (mGENERATExDROPSAVExI));
                putBIT (16, mGENERATExDROPSAVExJ, bitRHS);
                bitRHS->inUse = 0;
              }
              // DO WHILE J > 0; (3994)
              while (1 & (xGT (COREHALFWORD (mGENERATExDROPSAVExJ), 0)))
                {
                  // IF J = ENTRY THEN (3995)
                  if (1
                      & (xEQ (COREHALFWORD (mGENERATExDROPSAVExJ),
                              COREHALFWORD (mGENERATExDROPSAVExENTRY))))
                    // RETURN; (3996)
                    {
                      reentryGuard = 0;
                      return 0;
                    }
                  // J = ARRAYPOINT(J); (3997)
                  {
                    descriptor_t *bitRHS = getBIT (
                        16,
                        mARRAYPOINT + 2 * COREHALFWORD (mGENERATExDROPSAVExJ));
                    putBIT (16, mGENERATExDROPSAVExJ, bitRHS);
                    bitRHS->inUse = 0;
                  }
                } // End of DO WHILE block
              // ARRAYPOINT(ENTRY) = SDOTEMP(I); (3998)
              {
                descriptor_t *bitRHS = getBIT (
                    16, mGENERATExSDOTEMP
                            + 2 * COREHALFWORD (mGENERATExDROPSAVExI));
                putBIT (16,
                        mARRAYPOINT
                            + 2 * (COREHALFWORD (mGENERATExDROPSAVExENTRY)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
              // SDOTEMP(I) = ENTRY; (3999)
              {
                descriptor_t *bitRHS = getBIT (16, mGENERATExDROPSAVExENTRY);
                putBIT (16,
                        mGENERATExSDOTEMP
                            + 2 * (COREHALFWORD (mGENERATExDROPSAVExI)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
              // RETURN; (4000)
              {
                reentryGuard = 0;
                return 0;
              }
            es4s1:;
            } // End of DO block
      }
  } // End of DO for-loop block
  // DO I = 1 TO SAVEPTR; (4001)
  {
    int32_t from56, to56, by56;
    from56 = 1;
    to56 = bitToFixed (getBIT (16, mSAVEPTR));
    by56 = 1;
    for (putBIT (16, mGENERATExDROPSAVExI, fixedToBit (16, from56));
         bitToFixed (getBIT (16, mGENERATExDROPSAVExI)) <= to56;
         putBIT (16, mGENERATExDROPSAVExI,
                 fixedToBit (16, bitToFixed (getBIT (16, mGENERATExDROPSAVExI))
                                     + by56)))
      {
        // IF SAVEPOINT(I) = ENTRY THEN (4002)
        if (1
            & (xEQ (COREHALFWORD (mSAVEPOINT
                                  + 2 * COREHALFWORD (mGENERATExDROPSAVExI)),
                    COREHALFWORD (mGENERATExDROPSAVExENTRY))))
          // RETURN; (4003)
          {
            reentryGuard = 0;
            return 0;
          }
      }
  } // End of DO for-loop block
  // SAVEPTR = SAVEPTR + 1; (4004)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mSAVEPTR), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mSAVEPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // SAVEPOINT(SAVEPTR) = ENTRY; (4005)
  {
    descriptor_t *bitRHS = getBIT (16, mGENERATExDROPSAVExENTRY);
    putBIT (16, mSAVEPOINT + 2 * (COREHALFWORD (mSAVEPTR)), bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
