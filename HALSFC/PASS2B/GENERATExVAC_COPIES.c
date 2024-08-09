/*
  File GENERATExVAC_COPIES.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExVAC_COPIES (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExVAC_COPIES");
  // IF (COPY(OP) + VMCOPY(OP)) = 0 THEN (5807)
  if (1
      & (xEQ (
          xadd (COREHALFWORD (getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExVAC_COPIESxOP))
                              + 26 + 2 * (0)),
                BYTE0 (getFIXED (mIND_STACK)
                       + 73 * (COREHALFWORD (mGENERATExVAC_COPIESxOP)) + 67
                       + 1 * (0))),
          0)))
    // RETURN; (5808)
    {
      reentryGuard = 0;
      return 0;
    }
  // CALL SET_AREA(OP); (5809)
  {
    putBITp (16, mGENERATExSET_AREAxPTR, getBIT (16, mGENERATExVAC_COPIESxOP));
    GENERATExSET_AREA (0);
  }
  // COPY(OP), CPY = SET_DOPTRS(OP, TRUE); (5810)
  {
    descriptor_t *bitRHS = (putBITp (16, mGENERATExSET_DOPTRSxPTR,
                                     getBIT (16, mGENERATExVAC_COPIESxOP)),
                            putBITp (8, mGENERATExSET_DOPTRSxFLAG,
                                     fixedToBit (32, (int32_t)(1))),
                            GENERATExSET_DOPTRS (0));
    putBIT (16,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExVAC_COPIESxOP)) + 26 + 2 * (0),
            bitRHS);
    putBIT (16, mGENERATExVAC_COPIESxCPY, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF FORM(OP) = WORK THEN (5811)
  if (1
      & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExVAC_COPIESxOP))
                            + 32 + 2 * (0)),
              BYTE0 (mWORK))))
    // INX_CON(OP) = 0; (5812)
    {
      int32_t numberRHS = (int32_t)(0);
      putFIXED (getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExVAC_COPIESxOP)) + 4
                    + 4 * (0),
                numberRHS);
    }
  // ARRCONST = 0; (5813)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mARRCONST, numberRHS);
  }
  // DO I = 0 TO CPY-VMCOPY(OP)-1; (5814)
  {
    int32_t from68, to68, by68;
    from68 = 0;
    to68 = xsubtract (
        xsubtract (COREHALFWORD (mGENERATExVAC_COPIESxCPY),
                   BYTE0 (getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExVAC_COPIESxOP)) + 67
                          + 1 * (0))),
        1);
    by68 = 1;
    for (putBIT (16, mGENERATExVAC_COPIESxI, fixedToBit (16, from68));
         bitToFixed (getBIT (16, mGENERATExVAC_COPIESxI)) <= to68; putBIT (
             16, mGENERATExVAC_COPIESxI,
             fixedToBit (16, bitToFixed (getBIT (16, mGENERATExVAC_COPIESxI))
                                 + by68)))
      {
        // IF ADOPTR = 0 THEN (5815)
        if (1 & (xEQ (COREHALFWORD (mGENERATExADOPTR), 0)))
          // P = SF_RANGE(I+VAL(OP)); (5816)
          {
            descriptor_t *bitRHS = getBIT (
                16,
                mGENERATExSF_RANGE
                    + 2
                          * xadd (COREHALFWORD (mGENERATExVAC_COPIESxI),
                                  getFIXED (getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExVAC_COPIESxOP))
                                            + 12 + 4 * (0))));
            putBIT (16, mGENERATExVAC_COPIESxP, bitRHS);
            bitRHS->inUse = 0;
          }
        // ELSE (5817)
        else
          // P = VAL(DORANGE(DOPTR(CALL_LEVEL)+I+1)); (5818)
          {
            int32_t numberRHS = (int32_t)(getFIXED (
                getFIXED (mIND_STACK)
                + 73
                      * (COREHALFWORD (
                          mGENERATExDORANGE
                          + 2
                                * xadd (
                                    xadd (
                                        COREHALFWORD (
                                            mGENERATExDOPTR
                                            + 2 * COREHALFWORD (mCALL_LEVEL)),
                                        COREHALFWORD (mGENERATExVAC_COPIESxI)),
                                    1)))
                + 12 + 4 * (0)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mGENERATExVAC_COPIESxP, bitRHS);
            bitRHS->inUse = 0;
          }
        // IF I = 0 THEN (5819)
        if (1 & (xEQ (COREHALFWORD (mGENERATExVAC_COPIESxI), 0)))
          // ARRCONST = -1; (5820)
          {
            int32_t numberRHS = (int32_t)(-1);
            putFIXED (mARRCONST, numberRHS);
          }
        // ELSE (5821)
        else
          // ARRCONST = ARRCONST * P - 1; (5822)
          {
            int32_t numberRHS = (int32_t)(xsubtract (
                xmultiply (getFIXED (mARRCONST),
                           COREHALFWORD (mGENERATExVAC_COPIESxP)),
                1));
            putFIXED (mARRCONST, numberRHS);
          }
        // SUBLIMIT(STACK#+I) = P; (5823)
        {
          descriptor_t *bitRHS = getBIT (16, mGENERATExVAC_COPIESxP);
          putBIT (16,
                  mGENERATExSUBLIMIT
                      + 2
                            * (xadd (COREHALFWORD (mSTACKp),
                                     COREHALFWORD (mGENERATExVAC_COPIESxI))),
                  bitRHS);
          bitRHS->inUse = 0;
        }
      }
  } // End of DO for-loop block
  // IF VMCOPY(OP) THEN (5824)
  if (1
      & (bitToFixed (
          getBIT (8, getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExVAC_COPIESxOP)) + 67
                         + 1 * (0)))))
    // DO; (5825)
    {
    rs2:;
      // IF ADOPTR = 0 THEN (5826)
      if (1 & (xEQ (COREHALFWORD (mGENERATExADOPTR), 0)))
        // P = SF_RANGE(I+VAL(OP)); (5827)
        {
          descriptor_t *bitRHS = getBIT (
              16,
              mGENERATExSF_RANGE
                  + 2
                        * xadd (
                            COREHALFWORD (mGENERATExVAC_COPIESxI),
                            getFIXED (
                                getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExVAC_COPIESxOP))
                                + 12 + 4 * (0))));
          putBIT (16, mGENERATExVAC_COPIESxP, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (5828)
      else
        // P = VAL(DORANGE(DOPTR(CALL_LEVEL)+I+1)); (5829)
        {
          int32_t numberRHS = (int32_t)(getFIXED (
              getFIXED (mIND_STACK)
              + 73
                    * (COREHALFWORD (
                        mGENERATExDORANGE
                        + 2
                              * xadd (
                                  xadd (COREHALFWORD (
                                            mGENERATExDOPTR
                                            + 2 * COREHALFWORD (mCALL_LEVEL)),
                                        COREHALFWORD (mGENERATExVAC_COPIESxI)),
                                  1)))
              + 12 + 4 * (0)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mGENERATExVAC_COPIESxP, bitRHS);
          bitRHS->inUse = 0;
        }
      // ARRCONST = ARRCONST * P; (5830)
      {
        int32_t numberRHS = (int32_t)(xmultiply (
            getFIXED (mARRCONST), COREHALFWORD (mGENERATExVAC_COPIESxP)));
        putFIXED (mARRCONST, numberRHS);
      }
      // SUBLIMIT(STACK#+I) = P; (5831)
      {
        descriptor_t *bitRHS = getBIT (16, mGENERATExVAC_COPIESxP);
        putBIT (16,
                mGENERATExSUBLIMIT
                    + 2
                          * (xadd (COREHALFWORD (mSTACKp),
                                   COREHALFWORD (mGENERATExVAC_COPIESxI))),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // SUBLIMIT(STACK#+CPY) = 1; (5832)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16,
                mGENERATExSUBLIMIT
                    + 2
                          * (xadd (COREHALFWORD (mSTACKp),
                                   COREHALFWORD (mGENERATExVAC_COPIESxCPY))),
                bitRHS);
        bitRHS->inUse = 0;
      }
    es2:;
    } // End of DO block
  // ELSE (5833)
  else
    // DO; (5834)
    {
    rs3:;
      // ARRCONST = ARRCONST * AREASAVE; (5835)
      {
        int32_t numberRHS = (int32_t)(xmultiply (getFIXED (mARRCONST),
                                                 getFIXED (mAREASAVE)));
        putFIXED (mARRCONST, numberRHS);
      }
      // SUBLIMIT(STACK#+CPY) = AREASAVE; (5836)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mAREASAVE));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16,
                mGENERATExSUBLIMIT
                    + 2
                          * (xadd (COREHALFWORD (mSTACKp),
                                   COREHALFWORD (mGENERATExVAC_COPIESxCPY))),
                bitRHS);
        bitRHS->inUse = 0;
      }
    es3:;
    } // End of DO block
  // IF TYPE(OP) ~= STRUCTURE THEN (5837)
  if (1
      & (xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mGENERATExVAC_COPIESxOP))
                             + 50 + 2 * (0)),
               BYTE0 (mSTRUCTURE))))
    // ARRCONST = ARRCONST * BIGHTS(TYPE(OP)); (5838)
    {
      int32_t numberRHS = (int32_t)(xmultiply (
          getFIXED (mARRCONST),
          BYTE0 (mBIGHTS
                 + 1
                       * COREHALFWORD (
                           getFIXED (mIND_STACK)
                           + 73 * (COREHALFWORD (mGENERATExVAC_COPIESxOP)) + 50
                           + 2 * (0)))));
      putFIXED (mARRCONST, numberRHS);
    }
  // INX_CON(OP) = INX_CON(OP) + ARRCONST; (5839)
  {
    int32_t numberRHS = (int32_t)(xadd (
        getFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExVAC_COPIESxOP)) + 4
                  + 4 * (0)),
        getFIXED (mARRCONST)));
    putFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExVAC_COPIESxOP)) + 4
                  + 4 * (0),
              numberRHS);
  }
  // VMCOPY(OP) = 0; (5840)
  {
    int32_t numberRHS = (int32_t)(0);
    putBIT (8,
            getFIXED (mIND_STACK)
                + 73 * (COREHALFWORD (mGENERATExVAC_COPIESxOP)) + 67 + 1 * (0),
            fixedToBit (8, numberRHS));
  }
  // CALL FREE_ARRAYNESS(OP); (5841)
  {
    putBITp (16, mGENERATExFREE_ARRAYNESSxOP,
             getBIT (16, mGENERATExVAC_COPIESxOP));
    GENERATExFREE_ARRAYNESS (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
