/*
  File GENERATExCLEAR_NAME_SAFE.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExCLEAR_NAME_SAFE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExCLEAR_NAME_SAFE");
  // NAMETYPE = SYT_TYPE(LOC2(OP)); (5977)
  {
    descriptor_t *bitRHS = getBIT (
        8, getFIXED (mSYM_TAB)
               + 34
                     * (COREHALFWORD (
                         getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExCLEAR_NAME_SAFExOP))
                         + 42 + 2 * (0)))
               + 32 + 1 * (0));
    putBIT (16, mGENERATExCLEAR_NAME_SAFExNAMETYPE, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL CLEAR_COPY_SAFE(OP); (5978)
  {
    putBITp (16, mGENERATExCLEAR_COPY_SAFExOP,
             getBIT (16, mGENERATExCLEAR_NAME_SAFExOP));
    GENERATExCLEAR_COPY_SAFE (0);
  }
  // IF ~NAME_VAR(OP) & (SYT_FLAGS(LOC(OP)) & ASSIGN_FLAG)=0  THEN (5979)
  if (1
      & (xAND (
          xNOT (BYTE0 (getFIXED (mIND_STACK)
                       + 73 * (COREHALFWORD (mGENERATExCLEAR_NAME_SAFExOP))
                       + 70 + 1 * (0))),
          xEQ (xAND (
                   getFIXED (getFIXED (mSYM_TAB)
                             + 34
                                   * (COREHALFWORD (
                                       getFIXED (mIND_STACK)
                                       + 73
                                             * (COREHALFWORD (
                                                 mGENERATExCLEAR_NAME_SAFExOP))
                                       + 40 + 2 * (0)))
                             + 8 + 4 * (0)),
                   getFIXED (mASSIGN_FLAG)),
               0))))
    // RETURN; (5980)
    {
      reentryGuard = 0;
      return 0;
    }
  // DO I = 0 TO REG_NUM; (5981)
  {
    int32_t from73, to73, by73;
    from73 = 0;
    to73 = 15;
    by73 = 1;
    for (putBIT (16, mGENERATExCLEAR_NAME_SAFExI, fixedToBit (16, from73));
         bitToFixed (getBIT (16, mGENERATExCLEAR_NAME_SAFExI)) <= to73;
         putBIT (16, mGENERATExCLEAR_NAME_SAFExI,
                 fixedToBit (
                     16, bitToFixed (getBIT (16, mGENERATExCLEAR_NAME_SAFExI))
                             + by73)))
      {
        // IF USAGE(I) THEN (5982)
        if (1
            & (bitToFixed (getBIT (
                16, mUSAGE + 2 * COREHALFWORD (mGENERATExCLEAR_NAME_SAFExI)))))
          // IF R_CONTENTS(I) = SYM | R_CONTENTS(I) = SYM2 THEN (5983)
          if (1
              & (xOR (
                  xEQ (
                      BYTE0 (mR_CONTENTS
                             + 1 * COREHALFWORD (mGENERATExCLEAR_NAME_SAFExI)),
                      BYTE0 (mSYM)),
                  xEQ (
                      BYTE0 (mR_CONTENTS
                             + 1 * COREHALFWORD (mGENERATExCLEAR_NAME_SAFExI)),
                      BYTE0 (mSYM2)))))
            // DO; (5984)
            {
            rs1s1:;
              // REGTYPE = SYT_TYPE(R_VAR(I)); (5985)
              {
                descriptor_t *bitRHS = getBIT (
                    8, getFIXED (mSYM_TAB)
                           + 34
                                 * (COREHALFWORD (
                                     mR_VAR
                                     + 2
                                           * COREHALFWORD (
                                               mGENERATExCLEAR_NAME_SAFExI)))
                           + 32 + 1 * (0));
                putBIT (16, mGENERATExCLEAR_NAME_SAFExREGTYPE, bitRHS);
                bitRHS->inUse = 0;
              }
              // IF ~HIGHOPT & NAME_VAR(OP) THEN (5986)
              if (1
                  & (xAND (
                      xNOT (BYTE0 (mHIGHOPT)),
                      BYTE0 (
                          getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExCLEAR_NAME_SAFExOP))
                          + 70 + 1 * (0)))))
                // DO; (5987)
                {
                rs1s1s1:;
                  // CALL UNRECOGNIZABLE(I); (5988)
                  {
                    putBITp (16, mGENERATExUNRECOGNIZABLExR,
                             getBIT (16, mGENERATExCLEAR_NAME_SAFExI));
                    GENERATExUNRECOGNIZABLE (0);
                  }
                es1s1s1:;
                } // End of DO block
              // ELSE (5989)
              else
                // DO; (5990)
                {
                rs1s1s2:;
                  // IF (SYT_FLAGS(LOC2(OP)) & NAME_FLAG)=0 &  (NAME_VAR(OP)) &
                  // REGTYPE ~= STRUCTURE  THEN (5991)
                  if (1
                      & (xAND (
                          xAND (
                              xEQ (
                                  xAND (
                                      getFIXED (
                                          getFIXED (mSYM_TAB)
                                          + 34
                                                * (COREHALFWORD (
                                                    getFIXED (mIND_STACK)
                                                    + 73
                                                          * (COREHALFWORD (
                                                              mGENERATExCLEAR_NAME_SAFExOP))
                                                    + 42 + 2 * (0)))
                                          + 8 + 4 * (0)),
                                      getFIXED (mNAME_FLAG)),
                                  0),
                              BYTE0 (getFIXED (mIND_STACK)
                                     + 73
                                           * (COREHALFWORD (
                                               mGENERATExCLEAR_NAME_SAFExOP))
                                     + 70 + 1 * (0))),
                          xNEQ (
                              COREHALFWORD (mGENERATExCLEAR_NAME_SAFExREGTYPE),
                              BYTE0 (mSTRUCTURE)))))
                    // ESCAPE; (5992)
                    goto es1s1s2;
                  // IF ~NAME_VAR(OP) & (SYT_SCOPE(R_VAR(I)) >=
                  // SYT_SCOPE(LOC(OP)) )  THEN (5993)
                  if (1
                      & (xAND (
                          xNOT (BYTE0 (getFIXED (mIND_STACK)
                                       + 73
                                             * (COREHALFWORD (
                                                 mGENERATExCLEAR_NAME_SAFExOP))
                                       + 70 + 1 * (0))),
                          xGE (
                              BYTE0 (
                                  getFIXED (mSYM_TAB)
                                  + 34
                                        * (COREHALFWORD (
                                            mR_VAR
                                            + 2
                                                  * COREHALFWORD (
                                                      mGENERATExCLEAR_NAME_SAFExI)))
                                  + 29 + 1 * (0)),
                              BYTE0 (
                                  getFIXED (mSYM_TAB)
                                  + 34
                                        * (COREHALFWORD (
                                            getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExCLEAR_NAME_SAFExOP))
                                            + 40 + 2 * (0)))
                                  + 29 + 1 * (0))))))
                    // ESCAPE; (5994)
                    goto es1s1s2;
                  // IF (REGTYPE=STRUCTURE) |  ((NAMETYPE& 7)=SCALAR) THEN
                  // (5995)
                  if (1
                      & (xOR (
                          xEQ (
                              COREHALFWORD (mGENERATExCLEAR_NAME_SAFExREGTYPE),
                              BYTE0 (mSTRUCTURE)),
                          xEQ (xAND (COREHALFWORD (
                                         mGENERATExCLEAR_NAME_SAFExNAMETYPE),
                                     7),
                               BYTE0 (mSCALAR)))))
                    // DO; (5996)
                    {
                    rs1s1s2s1:;
                      // REGTYPE = R_TYPE(I); (5997)
                      {
                        descriptor_t *bitRHS = getBIT (
                            8, mR_TYPE
                                   + 1
                                         * COREHALFWORD (
                                             mGENERATExCLEAR_NAME_SAFExI));
                        putBIT (16, mGENERATExCLEAR_NAME_SAFExREGTYPE, bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // IF (NAMETYPE& 7) = VECTOR THEN (5998)
                      if (1
                          & (xEQ (
                              xAND (COREHALFWORD (
                                        mGENERATExCLEAR_NAME_SAFExNAMETYPE),
                                    7),
                              BYTE0 (mVECTOR))))
                        // NAMETYPE = NAMETYPE + 1; (5999)
                        {
                          int32_t numberRHS = (int32_t)(xadd (
                              COREHALFWORD (
                                  mGENERATExCLEAR_NAME_SAFExNAMETYPE),
                              1));
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (16, mGENERATExCLEAR_NAME_SAFExNAMETYPE,
                                  bitRHS);
                          bitRHS->inUse = 0;
                        }
                      // IF (NAMETYPE& 7) = MATRIX THEN (6000)
                      if (1
                          & (xEQ (
                              xAND (COREHALFWORD (
                                        mGENERATExCLEAR_NAME_SAFExNAMETYPE),
                                    7),
                              BYTE0 (mMATRIX))))
                        // NAMETYPE = NAMETYPE + 2; (6001)
                        {
                          int32_t numberRHS = (int32_t)(xadd (
                              COREHALFWORD (
                                  mGENERATExCLEAR_NAME_SAFExNAMETYPE),
                              2));
                          descriptor_t *bitRHS;
                          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                          putBIT (16, mGENERATExCLEAR_NAME_SAFExNAMETYPE,
                                  bitRHS);
                          bitRHS->inUse = 0;
                        }
                    es1s1s2s1:;
                    } // End of DO block
                  // IF NAMETYPE = REGTYPE THEN (6002)
                  if (1
                      & (xEQ (
                          COREHALFWORD (mGENERATExCLEAR_NAME_SAFExNAMETYPE),
                          COREHALFWORD (mGENERATExCLEAR_NAME_SAFExREGTYPE))))
                    // CALL UNRECOGNIZABLE(I); (6003)
                    {
                      putBITp (16, mGENERATExUNRECOGNIZABLExR,
                               getBIT (16, mGENERATExCLEAR_NAME_SAFExI));
                      GENERATExUNRECOGNIZABLE (0);
                    }
                es1s1s2:;
                } // End of DO block
            es1s1:;
            } // End of DO block
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}