/*
  File GENERATExTRUE_INX.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExTRUE_INX (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExTRUE_INX");
  // IF SYMFORM(FORM(OP)) | INX(OP) ~= 0 THEN (5632)
  if (1
      & (xOR (BYTE0 (mSYMFORM
                     + 1
                           * COREHALFWORD (
                               getFIXED (mIND_STACK)
                               + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                               + 32 + 2 * (0))),
              xNEQ (COREHALFWORD (getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                  + 34 + 2 * (0)),
                    0))))
    // DO; (5633)
    {
    rs1:;
      // IF HALMAT_OPCODE= 91&TAG=4 & SSTAR_FLAG THEN (5634)
      if (1
          & (xAND (xAND (xEQ (COREHALFWORD (mHALMAT_OPCODE), 91),
                         xEQ (COREHALFWORD (mTAG), 4)),
                   BYTE0 (mGENERATExSSTAR_FLAG))))
        // IF SYT_TYPE(LOC(OP))=STRUCTURE & SYT_ARRAY(LOC(OP))~=0  THEN (5635)
        if (1
            & (xAND (
                xEQ (
                    BYTE0 (
                        getFIXED (mSYM_TAB)
                        + 34
                              * (COREHALFWORD (
                                  getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                  + 40 + 2 * (0)))
                        + 32 + 1 * (0)),
                    BYTE0 (mSTRUCTURE)),
                xNEQ (
                    COREHALFWORD (
                        getFIXED (mSYM_TAB)
                        + 34
                              * (COREHALFWORD (
                                  getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                  + 40 + 2 * (0)))
                        + 20 + 2 * (0)),
                    0))))
          // CALL ERRORS(CLASS_ZC,1); (5636)
          {
            putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_ZC));
            putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(1)));
            ERRORS (0);
          }
      // IF STRUCT_INX(OP)=0 | (STRUCT_INX(OP)>=4|INX(OP)~=0) & COPY(OP)>0 THEN
      // (5637)
      if (1
          & (xOR (
              xEQ (BYTE0 (getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP)) + 66
                          + 1 * (0)),
                   0),
              xAND (
                  xOR (
                      xGE (BYTE0 (getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                  + 66 + 1 * (0)),
                           4),
                      xNEQ (COREHALFWORD (
                                getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                + 34 + 2 * (0)),
                            0)),
                  xGT (COREHALFWORD (
                           getFIXED (mIND_STACK)
                           + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP)) + 26
                           + 2 * (0)),
                       0)))))
        // DO; (5638)
        {
        rs1s1:;
          // IF MAJOR_STRUCTURE(OP) THEN (5639)
          if (1
              & (bitToFixed ((putBITp (16, mGENERATExMAJOR_STRUCTURExOP,
                                       getBIT (16, mGENERATExTRUE_INXxOP)),
                              GENERATExMAJOR_STRUCTURE (0)))))
            // INX_CON(OP) = INX_CON(OP) - SYT_CONST(LOC(OP)); (5640)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  getFIXED (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP)) + 4
                            + 4 * (0)),
                  getFIXED (
                      getFIXED (mP2SYMS)
                      + 12
                            * (COREHALFWORD (
                                getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                + 40 + 2 * (0)))
                      + 0 + 4 * (0))));
              putFIXED (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP)) + 4
                            + 4 * (0),
                        numberRHS);
            }
          // ELSE (5641)
          else
            // IF TYPE(OP)=CHAR & SIZE(OP)<0 & SYT_CONST(LOC2(OP))~=0 THEN
            // (5642)
            if (1
                & (xAND (
                    xAND (
                        xEQ (COREHALFWORD (
                                 getFIXED (mIND_STACK)
                                 + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                 + 50 + 2 * (0)),
                             BYTE0 (mCHAR)),
                        xLT (COREHALFWORD (
                                 getFIXED (mIND_STACK)
                                 + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                 + 48 + 2 * (0)),
                             0)),
                    xNEQ (getFIXED (getFIXED (mP2SYMS)
                                    + 12
                                          * (COREHALFWORD (
                                              getFIXED (mIND_STACK)
                                              + 73
                                                    * (COREHALFWORD (
                                                        mGENERATExTRUE_INXxOP))
                                              + 42 + 2 * (0)))
                                    + 0 + 4 * (0)),
                          0))))
              // DO; (5643)
              {
              rs1s1s1:;
                // LITOP = GET_VAC(-1); (5644)
                {
                  descriptor_t *bitRHS
                      = (putBITp (16, mGENERATExGET_VACxR,
                                  fixedToBit (32, (int32_t)(-1))),
                         GENERATExGET_VAC (0));
                  putBIT (16, mGENERATExTRUE_INXxLITOP, bitRHS);
                  bitRHS->inUse = 0;
                }
                // CALL LOAD_NUM(REG(LITOP), -SYT_CONST(LOC2(OP))); (5645)
                {
                  putBITp (16, mGENERATExLOAD_NUMxR,
                           getBIT (16, getFIXED (mIND_STACK)
                                           + 73
                                                 * (COREHALFWORD (
                                                     mGENERATExTRUE_INXxLITOP))
                                           + 46 + 2 * (0)));
                  putFIXED (mGENERATExLOAD_NUMxNUM,
                            xminus (getFIXED (
                                getFIXED (mP2SYMS)
                                + 12
                                      * (COREHALFWORD (
                                          getFIXED (mIND_STACK)
                                          + 73
                                                * (COREHALFWORD (
                                                    mGENERATExTRUE_INXxOP))
                                          + 42 + 2 * (0)))
                                + 0 + 4 * (0))));
                  GENERATExLOAD_NUM (0);
                }
                // CALL SUBSCRIPT_MULT(LITOP, SIZE(OP)); (5646)
                {
                  putBITp (16, mGENERATExSUBSCRIPT_MULTxOP,
                           getBIT (16, mGENERATExTRUE_INXxLITOP));
                  putFIXED (mGENERATExSUBSCRIPT_MULTxVALUE,
                            COREHALFWORD (
                                getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                + 48 + 2 * (0)));
                  GENERATExSUBSCRIPT_MULT (0);
                }
                // INX(OP) = REG(LITOP); (5647)
                {
                  descriptor_t *bitRHS = getBIT (
                      16, getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExTRUE_INXxLITOP))
                              + 46 + 2 * (0));
                  putBIT (16,
                          getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                              + 34 + 2 * (0),
                          bitRHS);
                  bitRHS->inUse = 0;
                }
                // INX_NEXT_USE(OP) = 0; (5648)
                {
                  int32_t numberRHS = (int32_t)(0);
                  putBIT (16,
                          getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                              + 38 + 2 * (0),
                          fixedToBit (16, numberRHS));
                }
                // CALL RETURN_STACK_ENTRY(LITOP); (5649)
                {
                  putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                           getBIT (16, mGENERATExTRUE_INXxLITOP));
                  GENERATExRETURN_STACK_ENTRY (0);
                }
              es1s1s1:;
              } // End of DO block
            // ELSE (5650)
            else
              // IF SYT_TYPE(LOC(OP)) = STRUCTURE THEN (5651)
              if (1
                  & (xEQ (BYTE0 (getFIXED (mSYM_TAB)
                                 + 34
                                       * (COREHALFWORD (
                                           getFIXED (mIND_STACK)
                                           + 73
                                                 * (COREHALFWORD (
                                                     mGENERATExTRUE_INXxOP))
                                           + 40 + 2 * (0)))
                                 + 32 + 1 * (0)),
                          BYTE0 (mSTRUCTURE))))
                // DO; (5652)
                {
                rs1s1s2:;
                  // INX_CON(OP) = INX_CON(OP) - SYT_CONST(LOC(OP)) -
                  // SYT_CONST(LOC2(OP)); (5653)
                  {
                    int32_t numberRHS = (int32_t)(xsubtract (
                        xsubtract (
                            getFIXED (
                                getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                + 4 + 4 * (0)),
                            getFIXED (
                                getFIXED (mP2SYMS)
                                + 12
                                      * (COREHALFWORD (
                                          getFIXED (mIND_STACK)
                                          + 73
                                                * (COREHALFWORD (
                                                    mGENERATExTRUE_INXxOP))
                                          + 40 + 2 * (0)))
                                + 0 + 4 * (0))),
                        getFIXED (getFIXED (mP2SYMS)
                                  + 12
                                        * (COREHALFWORD (
                                            getFIXED (mIND_STACK)
                                            + 73
                                                  * (COREHALFWORD (
                                                      mGENERATExTRUE_INXxOP))
                                            + 42 + 2 * (0)))
                                  + 0 + 4 * (0))));
                    putFIXED (getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                  + 4 + 4 * (0),
                              numberRHS);
                  }
                  // IF SYT_CONST(LOC(OP)) ~= 0 THEN (5654)
                  if (1
                      & (xNEQ (
                          getFIXED (getFIXED (mP2SYMS)
                                    + 12
                                          * (COREHALFWORD (
                                              getFIXED (mIND_STACK)
                                              + 73
                                                    * (COREHALFWORD (
                                                        mGENERATExTRUE_INXxOP))
                                              + 40 + 2 * (0)))
                                    + 0 + 4 * (0)),
                          0)))
                    // DO; (5655)
                    {
                    rs1s1s2s1:;
                      // CALL ERRORS(CLASS_ZC,1,''||LINE#); (5656)
                      {
                        putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_ZC));
                        putBITp (16, mERRORSxNUM,
                                 fixedToBit (32, (int32_t)(1)));
                        putCHARACTERp (
                            mERRORSxTEXT,
                            xsCAT (cToDescriptor (NULL, ""),
                                   fixedToCharacter (getFIXED (mLINEp))));
                        ERRORS (0);
                      }
                    es1s1s2s1:;
                    } // End of DO block
                es1s1s2:;
                } // End of DO block
              // ELSE (5657)
              else
                // INX_CON(OP) = INX_CON(OP) - SYT_CONST(LOC2(OP)); (5658)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      getFIXED (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                + 4 + 4 * (0)),
                      getFIXED (getFIXED (mP2SYMS)
                                + 12
                                      * (COREHALFWORD (
                                          getFIXED (mIND_STACK)
                                          + 73
                                                * (COREHALFWORD (
                                                    mGENERATExTRUE_INXxOP))
                                          + 42 + 2 * (0)))
                                + 0 + 4 * (0))));
                  putFIXED (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                + 4 + 4 * (0),
                            numberRHS);
                }
        es1s1:;
        } // End of DO block
      // ELSE (5659)
      else
        // IF PACKTYPE(TYPE(OP)) = VECMAT THEN (5660)
        if (1
            & (xEQ (
                BYTE0 (mPACKTYPE
                       + 1
                             * COREHALFWORD (
                                 getFIXED (mIND_STACK)
                                 + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                 + 50 + 2 * (0))),
                BYTE0 (mVECMAT))))
          // INX_CON(OP) = INX_CON(OP) + BIGHTS(TYPE(OP)); (5661)
          {
            int32_t numberRHS = (int32_t)(xadd (
                getFIXED (getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP)) + 4
                          + 4 * (0)),
                BYTE0 (mBIGHTS
                       + 1
                             * COREHALFWORD (
                                 getFIXED (mIND_STACK)
                                 + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                 + 50 + 2 * (0)))));
            putFIXED (getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP)) + 4
                          + 4 * (0),
                      numberRHS);
          }
    es1:;
    } // End of DO block
  // ELSE (5662)
  else
    // IF PACKTYPE(TYPE(OP)) = VECMAT THEN (5663)
    if (1
        & (xEQ (BYTE0 (mPACKTYPE
                       + 1
                             * COREHALFWORD (
                                 getFIXED (mIND_STACK)
                                 + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP))
                                 + 50 + 2 * (0))),
                BYTE0 (mVECMAT))))
      // INX_CON(OP) = BIGHTS(TYPE(OP)); (5664)
      {
        descriptor_t *bitRHS = getBIT (
            8, mBIGHTS
                   + 1
                         * COREHALFWORD (
                             getFIXED (mIND_STACK)
                             + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP)) + 50
                             + 2 * (0)));
        putFIXED (getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP)) + 4
                      + 4 * (0),
                  bitToFixed (bitRHS));
        bitRHS->inUse = 0;
      }
    // ELSE (5665)
    else
      // INX_CON(OP) = 0; (5666)
      {
        int32_t numberRHS = (int32_t)(0);
        putFIXED (getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP)) + 4
                      + 4 * (0),
                  numberRHS);
      }
  // INX_CON(OP) = INX_CON(OP) + CON; (5667)
  {
    int32_t numberRHS = (int32_t)(xadd (
        getFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP)) + 4 + 4 * (0)),
        COREHALFWORD (mGENERATExTRUE_INXxCON)));
    putFIXED (getFIXED (mIND_STACK)
                  + 73 * (COREHALFWORD (mGENERATExTRUE_INXxOP)) + 4 + 4 * (0),
              numberRHS);
  }
  // IF ~FLAG THEN (5668)
  if (1 & (xNOT (BYTE0 (mGENERATExTRUE_INXxFLAG))))
    // CALL SUBSCRIPT_RANGE_CHECK(OP); (5669)
    {
      putBITp (16, mGENERATExSUBSCRIPT_RANGE_CHECKxOP,
               getBIT (16, mGENERATExTRUE_INXxOP));
      GENERATExSUBSCRIPT_RANGE_CHECK (0);
    }
  // CON, FLAG = 0; (5670)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExTRUE_INXxCON, bitRHS);
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mGENERATExTRUE_INXxFLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
