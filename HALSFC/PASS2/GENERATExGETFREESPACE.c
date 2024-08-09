/*
  File GENERATExGETFREESPACE.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExGETFREESPACE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExGETFREESPACE");
  // IX1 = GETFREETEMP; (3888)
  {
    int32_t numberRHS = (int32_t)(GENERATExGETFREETEMP (0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mIX1, bitRHS);
    bitRHS->inUse = 0;
  }
  // IX2 = PROC_LINK(INDEXNEST); (3889)
  {
    descriptor_t *bitRHS
        = getBIT (16, mPROC_LINK + 2 * COREHALFWORD (mINDEXNEST));
    putBIT (16, mIX2, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL NEED_STACK(INDEXNEST); (3890)
  {
    putBITp (16, mNEED_STACKxIX, getBIT (16, mINDEXNEST));
    NEED_STACK (0);
  }
  // TYPESIZE=BIGHTS(OPTYPE); (3891)
  {
    descriptor_t *bitRHS
        = getBIT (8, mBIGHTS + 1 * getFIXED (mGENERATExGETFREESPACExOPTYPE));
    int32_t numberRHS;
    numberRHS = bitToFixed (bitRHS);
    putFIXED (mGENERATExGETFREESPACExTYPESIZE, numberRHS);
    bitRHS->inUse = 0;
  }
  // IF OPTYPE = STRUCTURE THEN (3892)
  if (1 & (xEQ (getFIXED (mGENERATExGETFREESPACExOPTYPE), BYTE0 (mSTRUCTURE))))
    // DO; (3893)
    {
    rs1:;
      // TYPESIZE = BIGHTS(FULLBIT); (3894)
      {
        descriptor_t *bitRHS = getBIT (8, mBIGHTS + 1 * BYTE0 (mFULLBIT));
        int32_t numberRHS;
        numberRHS = bitToFixed (bitRHS);
        putFIXED (mGENERATExGETFREESPACExTYPESIZE, numberRHS);
        bitRHS->inUse = 0;
      }
      // XSIZE = TEMPSPACE; (3895)
      {
        int32_t numberRHS
            = (int32_t)(getFIXED (mGENERATExGETFREESPACExTEMPSPACE));
        putFIXED (mGENERATExGETFREESPACExXSIZE, numberRHS);
      }
    es1:;
    } // End of DO block
  // ELSE (3896)
  else
    // IF OPTYPE = CHAR THEN (3897)
    if (1 & (xEQ (getFIXED (mGENERATExGETFREESPACExOPTYPE), BYTE0 (mCHAR))))
      // XSIZE = CS(TEMPSPACE); (3898)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (mCSxLEN, getFIXED (mGENERATExGETFREESPACExTEMPSPACE)),
            CS (0)));
        putFIXED (mGENERATExGETFREESPACExXSIZE, numberRHS);
      }
    // ELSE (3899)
    else
      // XSIZE = TEMPSPACE * TYPESIZE; (3900)
      {
        int32_t numberRHS = (int32_t)(xmultiply (
            getFIXED (mGENERATExGETFREESPACExTEMPSPACE),
            getFIXED (mGENERATExGETFREESPACExTYPESIZE)));
        putFIXED (mGENERATExGETFREESPACExXSIZE, numberRHS);
      }
  // TEMP = WORKSEG(INDEXNEST); (3901)
  {
    int32_t numberRHS
        = (int32_t)(getFIXED (mWORKSEG + 4 * COREHALFWORD (mINDEXNEST)));
    putFIXED (mGENERATExGETFREESPACExTEMP, numberRHS);
  }
  // DO FOREVER; (3902)
  while (1 & (1))
    {
      // TEMP = ADJUST(TYPESIZE, TEMP); (3903)
      {
        int32_t numberRHS = (int32_t)((
            putBITp (16, mADJUSTxBIGHT,
                     fixedToBit (32, (int32_t)(getFIXED (
                                         mGENERATExGETFREESPACExTYPESIZE)))),
            putFIXED (mADJUSTxADDRESS, getFIXED (mGENERATExGETFREESPACExTEMP)),
            ADJUST (0)));
        putFIXED (mGENERATExGETFREESPACExTEMP, numberRHS);
      }
      // CALL CHECKSIZE(TEMP+XSIZE, 1); (3904)
      {
        putFIXED (mCHECKSIZExNUMBER,
                  xadd (getFIXED (mGENERATExGETFREESPACExTEMP),
                        getFIXED (mGENERATExGETFREESPACExXSIZE)));
        putBITp (16, mCHECKSIZExSEVERITY, fixedToBit (32, (int32_t)(1)));
        CHECKSIZE (0);
      }
      // IF TEMP+XSIZE <= LOWER(POINT(IX2)) THEN (3905)
      if (1
          & (xLE (xadd (getFIXED (mGENERATExGETFREESPACExTEMP),
                        getFIXED (mGENERATExGETFREESPACExXSIZE)),
                  getFIXED (
                      mLOWER
                      + 4 * COREHALFWORD (mPOINT + 2 * COREHALFWORD (mIX2))))))
        // DO; (3906)
        {
        rs2s1:;
          // UPPER(IX1) = TEMP+XSIZE; (3907)
          {
            int32_t numberRHS
                = (int32_t)(xadd (getFIXED (mGENERATExGETFREESPACExTEMP),
                                  getFIXED (mGENERATExGETFREESPACExXSIZE)));
            putFIXED (mUPPER + 4 * (COREHALFWORD (mIX1)), numberRHS);
          }
          // IF UPPER(IX1)>MAXTEMP(INDEXNEST) THEN (3908)
          if (1
              & (xGT (getFIXED (mUPPER + 4 * COREHALFWORD (mIX1)),
                      getFIXED (mMAXTEMP + 4 * COREHALFWORD (mINDEXNEST)))))
            // MAXTEMP(INDEXNEST)=UPPER(IX1); (3909)
            {
              int32_t numberRHS
                  = (int32_t)(getFIXED (mUPPER + 4 * COREHALFWORD (mIX1)));
              putFIXED (mMAXTEMP + 4 * (COREHALFWORD (mINDEXNEST)), numberRHS);
            }
          // GO TO SPACEFOUND; (3910)
          goto SPACEFOUND;
        es2s1:;
        } // End of DO block
      // ELSE (3911)
      else
        // DO; (3912)
        {
        rs2s2:;
          // IX2=POINT(IX2); (3913)
          {
            descriptor_t *bitRHS
                = getBIT (16, mPOINT + 2 * COREHALFWORD (mIX2));
            putBIT (16, mIX2, bitRHS);
            bitRHS->inUse = 0;
          }
          // TEMP = UPPER(IX2); (3914)
          {
            int32_t numberRHS
                = (int32_t)(getFIXED (mUPPER + 4 * COREHALFWORD (mIX2)));
            putFIXED (mGENERATExGETFREESPACExTEMP, numberRHS);
          }
        es2s2:;
        } // End of DO block
    }     // End of DO WHILE block
// SPACEFOUND: (3915)
SPACEFOUND:
  // LOWER(IX1)=TEMP; (3916)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mGENERATExGETFREESPACExTEMP));
    putFIXED (mLOWER + 4 * (COREHALFWORD (mIX1)), numberRHS);
  }
  // POINT(IX1)=POINT(IX2); (3917)
  {
    descriptor_t *bitRHS = getBIT (16, mPOINT + 2 * COREHALFWORD (mIX2));
    putBIT (16, mPOINT + 2 * (COREHALFWORD (mIX1)), bitRHS);
    bitRHS->inUse = 0;
  }
  // POINT(IX2)=IX1; (3918)
  {
    descriptor_t *bitRHS = getBIT (16, mIX1);
    putBIT (16, mPOINT + 2 * (COREHALFWORD (mIX2)), bitRHS);
    bitRHS->inUse = 0;
  }
  // IX2 = GET_STACK_ENTRY; (3919)
  {
    int32_t numberRHS = (int32_t)(GENERATExGET_STACK_ENTRY (0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mIX2, bitRHS);
    bitRHS->inUse = 0;
  }
  // FORM(IX2) = WORK; (3920)
  {
    descriptor_t *bitRHS = getBIT (8, mWORK);
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mIX2)) + 32 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // TYPE(IX2) = OPTYPE; (3921)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mGENERATExGETFREESPACExOPTYPE));
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mIX2)) + 50 + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // LOC(IX2) = IX1; (3922)
  {
    descriptor_t *bitRHS = getBIT (16, mIX1);
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mIX2)) + 40 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // LOC2(IX2) = -1; (3923)
  {
    int32_t numberRHS = (int32_t)(-1);
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mIX2)) + 42 + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // WORK_BLK(IX1) = CURCBLK; (3924)
  {
    descriptor_t *bitRHS = getBIT (8, mCURCBLK);
    putBIT (16, mWORK_BLK + 2 * (COREHALFWORD (mIX1)), bitRHS);
    bitRHS->inUse = 0;
  }
  // WORK_CTR(IX1) = CTR; (3925)
  {
    descriptor_t *bitRHS = getBIT (16, mCTR);
    putBIT (16, mWORK_CTR + 2 * (COREHALFWORD (mIX1)), bitRHS);
    bitRHS->inUse = 0;
  }
  // WORK_USAGE(IX1) = 1; (3926)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mWORK_USAGE + 2 * (COREHALFWORD (mIX1)), bitRHS);
    bitRHS->inUse = 0;
  }
  // SAVED_LINE(IX1) = 0; (3927)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (mSAVED_LINE + 4 * (COREHALFWORD (mIX1)), numberRHS);
  }
  // BASE(IX2) = TEMPBASE; (3928)
  {
    descriptor_t *bitRHS = getBIT (8, mTEMPBASE);
    putBIT (16,
            getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mIX2)) + 22 + 2 * (0),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // IF PACKTYPE(OPTYPE) = VECMAT THEN (3929)
  if (1
      & (xEQ (BYTE0 (mPACKTYPE + 1 * getFIXED (mGENERATExGETFREESPACExOPTYPE)),
              BYTE0 (mVECMAT))))
    // DISP(IX2) = TEMP - TYPESIZE; (3930)
    {
      int32_t numberRHS
          = (int32_t)(xsubtract (getFIXED (mGENERATExGETFREESPACExTEMP),
                                 getFIXED (mGENERATExGETFREESPACExTYPESIZE)));
      putBIT (16,
              getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mIX2)) + 30
                  + 2 * (0),
              fixedToBit (16, numberRHS));
    }
  // ELSE (3931)
  else
    // DISP(IX2) = TEMP; (3932)
    {
      int32_t numberRHS = (int32_t)(getFIXED (mGENERATExGETFREESPACExTEMP));
      putBIT (16,
              getFIXED (mIND_STACK) + 73 * (COREHALFWORD (mIX2)) + 30
                  + 2 * (0),
              fixedToBit (16, numberRHS));
    }
  // IF DISP(IX2) > 2047 & TEMPSPACE > 1 THEN (3933)
  if (1
      & (xAND (xGT (COREHALFWORD (getFIXED (mIND_STACK)
                                  + 73 * (COREHALFWORD (mIX2)) + 30 + 2 * (0)),
                    2047),
               xGT (getFIXED (mGENERATExGETFREESPACExTEMPSPACE), 1))))
    // CALL ERRORS(CLASS_BS,113); (3934)
    {
      putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_BS));
      putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(113)));
      ERRORS (0);
    }
  // DO I = PTRARG1 TO RM; (3935)
  {
    int32_t from51, to51, by51;
    from51 = bitToFixed (getBIT (8, mPTRARG1));
    to51 = getFIXED (mRM);
    by51 = 1;
    for (putBIT (16, mGENERATExGETFREESPACExI, fixedToBit (16, from51));
         bitToFixed (getBIT (16, mGENERATExGETFREESPACExI)) <= to51; putBIT (
             16, mGENERATExGETFREESPACExI,
             fixedToBit (16, bitToFixed (getBIT (16, mGENERATExGETFREESPACExI))
                                 + by51)))
      {
        // IF USAGE(I) THEN (3936)
        if (1
            & (bitToFixed (getBIT (
                16, mUSAGE + 2 * COREHALFWORD (mGENERATExGETFREESPACExI)))))
          // IF R_CONTENTS(I) = WORK THEN (3937)
          if (1
              & (xEQ (BYTE0 (mR_CONTENTS
                             + 1 * COREHALFWORD (mGENERATExGETFREESPACExI)),
                      BYTE0 (mWORK))))
            // IF R_VAR(I) = IX1 THEN (3938)
            if (1
                & (xEQ (
                    COREHALFWORD (
                        mR_VAR + 2 * COREHALFWORD (mGENERATExGETFREESPACExI)),
                    COREHALFWORD (mIX1))))
              // DO; (3939)
              {
              rs3s1:;
                // CALL UNRECOGNIZABLE(I); (3940)
                {
                  putBITp (16, mGENERATExUNRECOGNIZABLExR,
                           getBIT (16, mGENERATExGETFREESPACExI));
                  GENERATExUNRECOGNIZABLE (0);
                }
              es3s1:;
              } // End of DO block
      }
  } // End of DO for-loop block
  // RETURN IX2; (3941)
  {
    reentryGuard = 0;
    return COREHALFWORD (mIX2);
  }
}
