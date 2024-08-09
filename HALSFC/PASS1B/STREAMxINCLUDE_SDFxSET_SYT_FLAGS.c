/*
  File STREAMxINCLUDE_SDFxSET_SYT_FLAGS.c generated by XCOM-I, 2024-08-09
  12:40:41.
*/

#include "runtimeC.h"

int32_t
STREAMxINCLUDE_SDFxSET_SYT_FLAGS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard
      = guardReentry (reentryGuard, "STREAMxINCLUDE_SDFxSET_SYT_FLAGS");
  // SDFFLAGS = SDF_SYMB_FLAGS; (3602)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (getFIXED (mSTREAMxINCLUDE_SDFxSDF_F) + 4 * 2));
    putFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDFFLAGS, numberRHS);
  }
  // CALL SDF_INITIAL_CHECK; (3603)
  STREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDF_INITIAL_CHECK (0);
  // IF CONTROL( 3) THEN (3604)
  if (1 & (bitToFixed (getBIT (1, mCONTROL + 1 * 3))))
    // OUTPUT = 'SET_SYT_FLAGS: SDFFLAGS = '|| HEX(SDFFLAGS, 8)||' INCL_FLAGS =
    // '||HEX(INCL_FLAGS, 2); (3605)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          xsCAT (xsCAT (cToDescriptor (NULL, "SET_SYT_FLAGS: SDFFLAGS = "),
                        (putFIXED (
                             mHEXxNUM,
                             getFIXED (
                                 mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDFFLAGS)),
                         putFIXED (mHEXxWIDTH, 8), HEX (0))),
                 cToDescriptor (NULL, " INCL_FLAGS = ")),
          (putFIXED (mHEXxNUM, BYTE0 (mSTREAMxINCLUDE_SDFxINCL_FLAGS)),
           putFIXED (mHEXxWIDTH, 2), HEX (0)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // IF ACCESS_COMPOOL THEN (3606)
  if (1 & (bitToFixed (getBIT (1, mSTREAMxINCLUDE_SDFxACCESS_COMPOOL))))
    // FLAGS = READ_ACCESS_FLAG; (3607)
    {
      int32_t numberRHS = (int32_t)(536870912);
      putFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS, numberRHS);
    }
  // ELSE (3608)
  else
    // FLAGS = 0; (3609)
    {
      int32_t numberRHS = (int32_t)(0);
      putFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS, numberRHS);
    }
  // IF (SDFFLAGS & SDF_DENSE_FLAG) ~= 0 THEN (3610)
  if (1
      & (xNEQ (xAND (getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDFFLAGS),
                     4194304),
               0)))
    // FLAGS = FLAGS | DENSE_FLAG; (3611)
    {
      int32_t numberRHS = (int32_t)(xOR (
          getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS), 4));
      putFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS, numberRHS);
    }
  // ELSE (3612)
  else
    // FLAGS = FLAGS | ALIGNED_FLAG; (3613)
    {
      int32_t numberRHS = (int32_t)(xOR (
          getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS), 8));
      putFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS, numberRHS);
    }
  // IF (INCL_FLAGS & INCL_REMOTE_FLAG) ~= 0 THEN (3614)
  if (1 & (xNEQ (xAND (BYTE0 (mSTREAMxINCLUDE_SDFxINCL_FLAGS), 1), 0)))
    // IF (SYT_CLASS(NDX) ~= TEMPLATE_CLASS) THEN (3615)
    if (1
        & (xNEQ (
            BYTE0 (
                getFIXED (mSYM_TAB)
                + 34 * (COREHALFWORD (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxNDX))
                + 30 + 1 * (0)),
            BYTE0 (mTEMPLATE_CLASS))))
      // DO; (3616)
      {
      rs1:;
        // IF ((SDFFLAGS & SDF_NAME_FLAG) = 0) & ((SDFFLAGS & SDF_REMOTE_FLAG)
        // = 0) THEN (3617)
        if (1
            & (xAND (
                xEQ (xAND (
                         getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDFFLAGS),
                         67108864),
                     0),
                xEQ (xAND (
                         getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDFFLAGS),
                         65536),
                     0))))
          // FLAGS = FLAGS | REMOTE_FLAG | INCLUDED_REMOTE; (3618)
          {
            int32_t numberRHS = (int32_t)(xOR (
                xOR (getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS), 128),
                33554432));
            putFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS, numberRHS);
          }
        // IF ((SDFFLAGS & SDF_NAME_FLAG) ~= 0) THEN (3619)
        if (1
            & (xNEQ (
                xAND (getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDFFLAGS),
                      67108864),
                0)))
          // FLAGS = FLAGS | INCLUDED_REMOTE; (3620)
          {
            int32_t numberRHS = (int32_t)(xOR (
                getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS), 33554432));
            putFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS, numberRHS);
          }
      es1:;
      } // End of DO block
  // DO I = 0 TO #FLAGS - 1; (3621)
  {
    int32_t from68, to68, by68;
    from68 = 0;
    to68 = 12;
    by68 = 1;
    for (putBIT (16, mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxI,
                 fixedToBit (16, from68));
         bitToFixed (getBIT (16, mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxI)) <= to68;
         putBIT (16, mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxI,
                 fixedToBit (16, bitToFixed (getBIT (
                                     16, mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxI))
                                     + by68)))
      {
        // IF (SDFFLAGS & IN_FLAG(I)) ~= 0 THEN (3622)
        if (1
            & (xNEQ (
                xAND (
                    getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDFFLAGS),
                    getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxIN_FLAG
                              + 4
                                    * COREHALFWORD (
                                        mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxI))),
                0)))
          // FLAGS = FLAGS | OUT_FLAG(I); (3623)
          {
            int32_t numberRHS = (int32_t)(xOR (
                getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS),
                getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxOUT_FLAG
                          + 4
                                * COREHALFWORD (
                                    mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxI))));
            putFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS, numberRHS);
          }
      }
  } // End of DO for-loop block
  // SYT_FLAGS(NDX) = FLAGS; (3624)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS));
    putFIXED (getFIXED (mSYM_TAB)
                  + 34 * (COREHALFWORD (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxNDX))
                  + 8 + 4 * (0),
              numberRHS);
  }
  // NAME_IMPLIED = ((FLAGS & NAME_FLAG) ~= 0); (3625)
  {
    int32_t numberRHS = (int32_t)(xNEQ (
        xAND (getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS), 268435456),
        0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mNAME_IMPLIED, bitRHS);
    bitRHS->inUse = 0;
  }
  // TEMPORARY_IMPLIED = ((FLAGS & TEMPORARY_FLAG) ~= 0); (3626)
  {
    int32_t numberRHS = (int32_t)(xNEQ (
        xAND (getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS), 134217728),
        0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mTEMPORARY_IMPLIED, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF CONTROL( 3) THEN (3627)
  if (1 & (bitToFixed (getBIT (1, mCONTROL + 1 * 3))))
    // OUTPUT = 'SET_SYT_FLAGS:    FLAGS = ' || HEX(FLAGS, 8); (3628)
    {
      descriptor_t *stringRHS;
      stringRHS = xsCAT (
          cToDescriptor (NULL, "SET_SYT_FLAGS:    FLAGS = "),
          (putFIXED (mHEXxNUM,
                     getFIXED (mSTREAMxINCLUDE_SDFxSET_SYT_FLAGSxFLAGS)),
           putFIXED (mHEXxWIDTH, 8), HEX (0)));
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // RETURN; (3629)
  {
    reentryGuard = 0;
    return 0;
  }
}
