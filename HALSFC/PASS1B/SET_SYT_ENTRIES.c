/*
  File SET_SYT_ENTRIES.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
SET_SYT_ENTRIES (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SET_SYT_ENTRIES");
  // SYT_TYPE(ID_LOC) = TYPE; (9356)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mTYPE));
    putBIT (8, getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 32 + 1 * (0),
            fixedToBit (8, numberRHS));
  }
  // IF (ATTRIBUTES&LOCK_FLAG)~=0 THEN (9357)
  if (1 & (xNEQ (xAND (getFIXED (mATTRIBUTES), 1), 0)))
    // DO; (9358)
    {
    rs1:;
      // IF (NEST=1&BLOCK_MODE(NEST)~<CMPL_MODE)|
      // (SYT_FLAGS(ID_LOC)&ASSIGN_PARM)~=0 THEN (9359)
      if (1
          & (xOR (
              xAND (xEQ (getFIXED (mNEST), 1),
                    xGE (BYTE0 (mBLOCK_MODE + 1 * getFIXED (mNEST)),
                         BYTE0 (mCMPL_MODE))),
              xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                    + 34 * (getFIXED (mID_LOC)) + 8 + 4 * (0)),
                          32),
                    0))))
        // SYT_LOCK#(ID_LOC)=LOCK#; (9360)
        {
          int32_t numberRHS = (int32_t)(getFIXED (mLOCKp));
          putBIT (8,
                  getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 31
                      + 1 * (0),
                  fixedToBit (8, numberRHS));
        }
      // ELSE (9361)
      else
        // DO; (9362)
        {
        rs1s1:;
          // ATTRIBUTES=ATTRIBUTES&(~LOCK_FLAG); (9363)
          {
            int32_t numberRHS
                = (int32_t)(xAND (getFIXED (mATTRIBUTES), 4294967294));
            putFIXED (mATTRIBUTES, numberRHS);
          }
          // CALL ERROR(CLASS_DL,1,SYT_NAME(ID_LOC)); (9364)
          {
            putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DL));
            putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(1)));
            putCHARACTERp (mERRORxTEXT,
                           getCHARACTER (getFIXED (mSYM_TAB)
                                         + 34 * (getFIXED (mID_LOC)) + 0
                                         + 4 * (0)));
            ERROR (0);
          }
        es1s1:;
        } // End of DO block
    es1:;
    } // End of DO block
  // IF NAME_IMPLIED THEN (9365)
  if (1 & (bitToFixed (getBIT (1, mNAME_IMPLIED))))
    // ATTRIBUTES=ATTRIBUTES|NAME_FLAG; (9366)
    {
      int32_t numberRHS = (int32_t)(xOR (getFIXED (mATTRIBUTES), 268435456));
      putFIXED (mATTRIBUTES, numberRHS);
    }
  // SYT_FLAGS(ID_LOC) = SYT_FLAGS(ID_LOC) | ATTRIBUTES; (9367)
  {
    int32_t numberRHS
        = (int32_t)(xOR (getFIXED (getFIXED (mSYM_TAB)
                                   + 34 * (getFIXED (mID_LOC)) + 8 + 4 * (0)),
                         getFIXED (mATTRIBUTES)));
    putFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 8 + 4 * (0),
              numberRHS);
  }
  // IF TYPE=CHAR_TYPE THEN (9368)
  if (1 & (xEQ (getFIXED (mTYPE), 2)))
    // DO; (9369)
    {
    rs2:;
      // IF NAME_IMPLIED THEN (9370)
      if (1 & (bitToFixed (getBIT (1, mNAME_IMPLIED))))
        // DO; (9371)
        {
        rs2s1:;
          // IF N_DIM~=0 THEN (9372)
          if (1 & (xNEQ (getFIXED (mN_DIM), 0)))
            // GO TO CHAR_STAR_ERR; (9373)
            goto CHAR_STAR_ERR;
        es2s1:;
        } // End of DO block
      // ELSE (9374)
      else
        // IF (SYT_FLAGS(ID_LOC)&PARM_FLAGS)~=0 THEN (9375)
        if (1
            & (xNEQ (
                xAND (getFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC))
                                + 8 + 4 * (0)),
                      1056),
                0)))
          // DO; (9376)
          {
          rs2s2:;
            // IF CHAR_LENGTH~=-1 THEN (9377)
            if (1 & (xNEQ (getFIXED (mCHAR_LENGTH), -1)))
              // DO; (9378)
              {
              rs2s2s1:;
                // CHAR_LENGTH=-1; (9379)
                {
                  int32_t numberRHS = (int32_t)(-1);
                  putFIXED (mCHAR_LENGTH, numberRHS);
                }
                // CALL ERROR(CLASS_DS,11); (9380)
                {
                  putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DS));
                  putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(11)));
                  ERROR (0);
                }
              es2s2s1:;
              } // End of DO block
          es2s2:;
          } // End of DO block
        // ELSE (9381)
        else
        // CHAR_STAR_ERR: (9382)
        CHAR_STAR_ERR:
          // IF CHAR_LENGTH=-1 THEN (9383)
          if (1 & (xEQ (getFIXED (mCHAR_LENGTH), -1)))
            // DO; (9384)
            {
            rs2s3:;
              // CHAR_LENGTH=DEF_CHAR_LENGTH; (9385)
              {
                descriptor_t *bitRHS = getBIT (16, mDEF_CHAR_LENGTH);
                int32_t numberRHS;
                numberRHS = bitToFixed (bitRHS);
                putFIXED (mCHAR_LENGTH, numberRHS);
                bitRHS->inUse = 0;
              }
              // CALL ERROR(CLASS_DS,3); (9386)
              {
                putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DS));
                putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(3)));
                ERROR (0);
              }
            es2s3:;
            } // End of DO block
    es2:;
    } // End of DO block
  // IF TYPE <= VEC_TYPE THEN (9387)
  if (1 & (xLE (getFIXED (mTYPE), 4)))
    // VAR_LENGTH(ID_LOC) = TYPE(TYPE); (9388)
    {
      int32_t numberRHS = (int32_t)(getFIXED (mTYPE + 4 * getFIXED (mTYPE)));
      putBIT (16,
              getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 18 + 2 * (0),
              fixedToBit (16, numberRHS));
    }
  // IF N_DIM ~= 0 THEN (9389)
  if (1 & (xNEQ (getFIXED (mN_DIM), 0)))
    // DO; (9390)
    {
    rs3:;
      // IF EXT_ARRAY_PTR+N_DIM>=ON_ERROR_PTR THEN (9391)
      if (1
          & (xGE (xadd (getFIXED (mEXT_ARRAY_PTR), getFIXED (mN_DIM)),
                  COREHALFWORD (mON_ERROR_PTR))))
        // CALL ERROR(CLASS_BX, 5); (9392)
        {
          putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_BX));
          putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(5)));
          ERROR (0);
        }
      // ELSE (9393)
      else
        // DO; (9394)
        {
        rs3s1:;
          // IF (N_DIM = 1) & (S_ARRAY = -1) THEN (9395)
          if (1
              & (xAND (xEQ (getFIXED (mN_DIM), 1),
                       xEQ (getFIXED (mS_ARRAY), -1))))
            // DO; (9396)
            {
            rs3s1s1:;
              // IF (SYT_FLAGS(ID_LOC)&PARM_FLAGS)~=0&(~NAME_IMPLIED) THEN
              // (9397)
              if (1
                  & (xAND (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                                 + 34 * (getFIXED (mID_LOC))
                                                 + 8 + 4 * (0)),
                                       1056),
                                 0),
                           xNOT (BYTE0 (mNAME_IMPLIED)))))
                // S_ARRAY = -ID_LOC; (9398)
                {
                  int32_t numberRHS = (int32_t)(xminus (getFIXED (mID_LOC)));
                  putFIXED (mS_ARRAY, numberRHS);
                }
              // ELSE (9399)
              else
                // DO; (9400)
                {
                rs3s1s1s1:;
                  // S_ARRAY = 2; (9401)
                  {
                    int32_t numberRHS = (int32_t)(2);
                    putFIXED (mS_ARRAY, numberRHS);
                  }
                  // CALL ERROR(CLASS_DD,10, SYT_NAME(ID_LOC)); (9402)
                  {
                    putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DD));
                    putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(10)));
                    putCHARACTERp (mERRORxTEXT,
                                   getCHARACTER (getFIXED (mSYM_TAB)
                                                 + 34 * (getFIXED (mID_LOC))
                                                 + 0 + 4 * (0)));
                    ERROR (0);
                  }
                es3s1s1s1:;
                } // End of DO block
            es3s1s1:;
            } // End of DO block
          // CALL ENTER_DIMS; (9403)
          ENTER_DIMS (0);
          // IF EXT_ARRAY(SYT_ARRAY(ID_LOC)+1) > 0 THEN (9404)
          if (1
              & (xGT (
                  COREHALFWORD (
                      mEXT_ARRAY
                      + 2
                            * xadd (COREHALFWORD (getFIXED (mSYM_TAB)
                                                  + 34 * (getFIXED (mID_LOC))
                                                  + 20 + 2 * (0)),
                                    1)),
                  0)))
            // DO; (9405)
            {
            rs3s1s2:;
              // IF (ICQ_TERM#(ID_LOC) * ICQ_ARRAY#(ID_LOC) > ARRAY_DIM_LIM )
              // | (ICQ_TERM#(ID_LOC) * ICQ_ARRAY#(ID_LOC) < 1)  THEN (9406)
              if (1
                  & (xOR (
                      xGT (xmultiply (
                               (putFIXED (mICQ_TERMpxLOC, getFIXED (mID_LOC)),
                                ICQ_TERMp (0)),
                               (putBITp (16, mICQ_ARRAYpxLOC,
                                         fixedToBit (32, (int32_t)(getFIXED (
                                                             mID_LOC)))),
                                ICQ_ARRAYp (0))),
                           COREHALFWORD (mARRAY_DIM_LIM)),
                      xLT (xmultiply (
                               (putFIXED (mICQ_TERMpxLOC, getFIXED (mID_LOC)),
                                ICQ_TERMp (0)),
                               (putBITp (16, mICQ_ARRAYpxLOC,
                                         fixedToBit (32, (int32_t)(getFIXED (
                                                             mID_LOC)))),
                                ICQ_ARRAYp (0))),
                           1))))
                // CALL ERROR(CLASS_DD, 1); (9407)
                {
                  putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DD));
                  putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(1)));
                  ERROR (0);
                }
            es3s1s2:;
            } // End of DO block
        es3s1:;
        } // End of DO block
    es3:;
    } // End of DO block
  // IF TYPE = MAJ_STRUC THEN (9408)
  if (1 & (xEQ (getFIXED (mTYPE), 10)))
    // DO; (9409)
    {
    rs4:;
      // VAR_LENGTH(ID_LOC)=STRUC_PTR; (9410)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mSTRUC_PTR));
        putBIT (16,
                getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 18 + 2 * (0),
                fixedToBit (16, numberRHS));
      }
      // IF STRUC_DIM = -1 THEN (9411)
      if (1 & (xEQ (getFIXED (mSTRUC_DIM), -1)))
        // DO; (9412)
        {
        rs4s1:;
          // IF (SYT_FLAGS(ID_LOC)&PARM_FLAGS)~=0&(~NAME_IMPLIED) THEN (9413)
          if (1
              & (xAND (xNEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                             + 34 * (getFIXED (mID_LOC)) + 8
                                             + 4 * (0)),
                                   1056),
                             0),
                       xNOT (BYTE0 (mNAME_IMPLIED)))))
            // STRUC_DIM = -ID_LOC; (9414)
            {
              int32_t numberRHS = (int32_t)(xminus (getFIXED (mID_LOC)));
              putFIXED (mSTRUC_DIM, numberRHS);
            }
          // ELSE (9415)
          else
            // DO; (9416)
            {
            rs4s1s1:;
              // CALL ERROR(CLASS_DD, 8, SYT_NAME(ID_LOC)); (9417)
              {
                putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DD));
                putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(8)));
                putCHARACTERp (mERRORxTEXT,
                               getCHARACTER (getFIXED (mSYM_TAB)
                                             + 34 * (getFIXED (mID_LOC)) + 0
                                             + 4 * (0)));
                ERROR (0);
              }
              // STRUC_DIM = 2; (9418)
              {
                int32_t numberRHS = (int32_t)(2);
                putFIXED (mSTRUC_DIM, numberRHS);
              }
            es4s1s1:;
            } // End of DO block
        es4s1:;
        } // End of DO block
      // IF STRUC_DIM~=0 THEN (9419)
      if (1 & (xNEQ (getFIXED (mSTRUC_DIM), 0)))
        // DO; (9420)
        {
        rs4s2:;
          // SYT_ARRAY(ID_LOC) = STRUC_DIM; (9421)
          {
            int32_t numberRHS = (int32_t)(getFIXED (mSTRUC_DIM));
            putBIT (16,
                    getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 20
                        + 2 * (0),
                    fixedToBit (16, numberRHS));
          }
          // IF STRUC_DIM > 0 THEN (9422)
          if (1 & (xGT (getFIXED (mSTRUC_DIM), 0)))
            // IF (ICQ_TERM#(ID_LOC) * SYT_ARRAY(ID_LOC) > ARRAY_DIM_LIM)  |
            // (ICQ_TERM#(ID_LOC) * SYT_ARRAY(ID_LOC) < 1)  THEN (9423)
            if (1
                & (xOR (
                    xGT (xmultiply (
                             (putFIXED (mICQ_TERMpxLOC, getFIXED (mID_LOC)),
                              ICQ_TERMp (0)),
                             COREHALFWORD (getFIXED (mSYM_TAB)
                                           + 34 * (getFIXED (mID_LOC)) + 20
                                           + 2 * (0))),
                         COREHALFWORD (mARRAY_DIM_LIM)),
                    xLT (xmultiply (
                             (putFIXED (mICQ_TERMpxLOC, getFIXED (mID_LOC)),
                              ICQ_TERMp (0)),
                             COREHALFWORD (getFIXED (mSYM_TAB)
                                           + 34 * (getFIXED (mID_LOC)) + 20
                                           + 2 * (0))),
                         1))))
              // CALL ERROR(CLASS_DD, 11); (9424)
              {
                putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DD));
                putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(11)));
                ERROR (0);
              }
        es4s2:;
        } // End of DO block
      // ELSE (9425)
      else
        // IF (ICQ_TERM#(ID_LOC) > ARRAY_DIM_LIM) |  (ICQ_TERM#(ID_LOC) < 1)
        // THEN (9426)
        if (1
            & (xOR (xGT ((putFIXED (mICQ_TERMpxLOC, getFIXED (mID_LOC)),
                          ICQ_TERMp (0)),
                         COREHALFWORD (mARRAY_DIM_LIM)),
                    xLT ((putFIXED (mICQ_TERMpxLOC, getFIXED (mID_LOC)),
                          ICQ_TERMp (0)),
                         1))))
          // CALL ERROR(CLASS_DD, 11); (9427)
          {
            putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_DD));
            putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(11)));
            ERROR (0);
          }
    es4:;
    } // End of DO block
  // ELSE (9428)
  else
    // IF TYPE=TASK_LABEL|TYPE=PROG_LABEL THEN (9429)
    if (1 & (xOR (xEQ (getFIXED (mTYPE), 72), xEQ (getFIXED (mTYPE), 73))))
      // SYT_FLAGS(ID_LOC)=SYT_FLAGS(ID_LOC)|LATCHED_FLAG; (9430)
      {
        int32_t numberRHS = (int32_t)(xOR (
            getFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 8
                      + 4 * (0)),
            131072));
        putFIXED (getFIXED (mSYM_TAB) + 34 * (getFIXED (mID_LOC)) + 8
                      + 4 * (0),
                  numberRHS);
      }
  // CALL HALMAT_INIT_CONST; (9431)
  HALMAT_INIT_CONST (0);
  // DO I = 0 TO FACTOR_LIM; (9432)
  {
    int32_t from138, to138, by138;
    from138 = 0;
    to138 = 19;
    by138 = 1;
    for (putFIXED (mI, from138); getFIXED (mI) <= to138;
         putFIXED (mI, getFIXED (mI) + by138))
      {
        // TYPE(I) = 0; (9433)
        {
          int32_t numberRHS = (int32_t)(0);
          putFIXED (mTYPE + 4 * (getFIXED (mI)), numberRHS);
        }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
