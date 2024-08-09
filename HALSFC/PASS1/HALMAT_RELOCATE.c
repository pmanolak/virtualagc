/*
  File HALMAT_RELOCATE.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
HALMAT_RELOCATE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "HALMAT_RELOCATE");
  // HALMAT_RELOCATE_FLAG=FALSE; (7143)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mHALMAT_RELOCATE_FLAG, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF ~HALMAT_OK THEN (7144)
  if (1 & (xNOT (BYTE0 (mHALMAT_OK))))
    // RETURN; (7145)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF ATOM#_FAULT=ATOM#_LIM THEN (7146)
  if (1 & (xEQ (getFIXED (mATOMp_FAULT), 1799)))
    // DO; (7147)
    {
    rs1:;
      // ATOM#_FAULT=0; (7148)
      {
        int32_t numberRHS = (int32_t)(0);
        putFIXED (mATOMp_FAULT, numberRHS);
      }
      // RETURN; (7149)
      {
        reentryGuard = 0;
        return 0;
      }
    es1:;
    } // End of DO block
  // D1=ATOM#_FAULT-NEXT_ATOM#; (7150)
  {
    int32_t numberRHS = (int32_t)(xsubtract (getFIXED (mATOMp_FAULT),
                                             getFIXED (mNEXT_ATOMp)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mHALMAT_RELOCATExD1, bitRHS);
    bitRHS->inUse = 0;
  }
  // D2=ATOM#_LIM-ATOM#_FAULT; (7151)
  {
    int32_t numberRHS = (int32_t)(xsubtract (1799, getFIXED (mATOMp_FAULT)));
    putFIXED (mHALMAT_RELOCATExD2, numberRHS);
  }
  // D3 = 2 - ATOM#_FAULT; (7152)
  {
    int32_t numberRHS = (int32_t)(xsubtract (2, getFIXED (mATOMp_FAULT)));
    putFIXED (mHALMAT_RELOCATExD3, numberRHS);
  }
  // D4 = 2; (7153)
  {
    int32_t numberRHS = (int32_t)(2);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mHALMAT_RELOCATExD4, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE D1<D2; (7154)
  while (1
         & (xLT (COREHALFWORD (mHALMAT_RELOCATExD1),
                 getFIXED (mHALMAT_RELOCATExD2))))
    {
      // CALL MOVE_BLOCK(D4,NEXT_ATOM#,D1); (7155)
      {
        putBITp (16, mHALMAT_RELOCATExMOVE_BLOCKxSTART,
                 getBIT (16, mHALMAT_RELOCATExD4));
        putBITp (16, mHALMAT_RELOCATExMOVE_BLOCKxSTOP,
                 fixedToBit (32, (int32_t)(getFIXED (mNEXT_ATOMp))));
        putBITp (16, mHALMAT_RELOCATExMOVE_BLOCKxDELTA,
                 getBIT (16, mHALMAT_RELOCATExD1));
        HALMAT_RELOCATExMOVE_BLOCK (0);
      }
      // CALL MOVE_BLOCK(ATOM#_FAULT,ATOM#_FAULT+D1,D3); (7156)
      {
        putBITp (16, mHALMAT_RELOCATExMOVE_BLOCKxSTART,
                 fixedToBit (32, (int32_t)(getFIXED (mATOMp_FAULT))));
        putBITp (16, mHALMAT_RELOCATExMOVE_BLOCKxSTOP,
                 fixedToBit (32, (int32_t)(xadd (
                                     getFIXED (mATOMp_FAULT),
                                     COREHALFWORD (mHALMAT_RELOCATExD1)))));
        putBITp (16, mHALMAT_RELOCATExMOVE_BLOCKxDELTA,
                 fixedToBit (32, (int32_t)(getFIXED (mHALMAT_RELOCATExD3))));
        HALMAT_RELOCATExMOVE_BLOCK (0);
      }
      // D4=D4+D1; (7157)
      {
        int32_t numberRHS
            = (int32_t)(xadd (COREHALFWORD (mHALMAT_RELOCATExD4),
                              COREHALFWORD (mHALMAT_RELOCATExD1)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mHALMAT_RELOCATExD4, bitRHS);
        bitRHS->inUse = 0;
      }
      // D2=D2-D1; (7158)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (getFIXED (mHALMAT_RELOCATExD2),
                                   COREHALFWORD (mHALMAT_RELOCATExD1)));
        putFIXED (mHALMAT_RELOCATExD2, numberRHS);
      }
      // NEXT_ATOM#=NEXT_ATOM#+D1; (7159)
      {
        int32_t numberRHS = (int32_t)(xadd (
            getFIXED (mNEXT_ATOMp), COREHALFWORD (mHALMAT_RELOCATExD1)));
        putFIXED (mNEXT_ATOMp, numberRHS);
      }
      // ATOM#_FAULT=ATOM#_FAULT+D1; (7160)
      {
        int32_t numberRHS = (int32_t)(xadd (
            getFIXED (mATOMp_FAULT), COREHALFWORD (mHALMAT_RELOCATExD1)));
        putFIXED (mATOMp_FAULT, numberRHS);
      }
    } // End of DO WHILE block
  // CALL MOVE_BLOCK(D4,NEXT_ATOM#,D2); (7161)
  {
    putBITp (16, mHALMAT_RELOCATExMOVE_BLOCKxSTART,
             getBIT (16, mHALMAT_RELOCATExD4));
    putBITp (16, mHALMAT_RELOCATExMOVE_BLOCKxSTOP,
             fixedToBit (32, (int32_t)(getFIXED (mNEXT_ATOMp))));
    putBITp (16, mHALMAT_RELOCATExMOVE_BLOCKxDELTA,
             fixedToBit (32, (int32_t)(getFIXED (mHALMAT_RELOCATExD2))));
    HALMAT_RELOCATExMOVE_BLOCK (0);
  }
  // CALL MOVE_BLOCK(ATOM#_FAULT,ATOM#_LIM,D3); (7162)
  {
    putBITp (16, mHALMAT_RELOCATExMOVE_BLOCKxSTART,
             fixedToBit (32, (int32_t)(getFIXED (mATOMp_FAULT))));
    putBITp (16, mHALMAT_RELOCATExMOVE_BLOCKxSTOP,
             fixedToBit (32, (int32_t)(1799)));
    putBITp (16, mHALMAT_RELOCATExMOVE_BLOCKxDELTA,
             fixedToBit (32, (int32_t)(getFIXED (mHALMAT_RELOCATExD3))));
    HALMAT_RELOCATExMOVE_BLOCK (0);
  }
  // NEXT_ATOM#=NEXT_ATOM#+D2; (7163)
  {
    int32_t numberRHS = (int32_t)(xadd (getFIXED (mNEXT_ATOMp),
                                        getFIXED (mHALMAT_RELOCATExD2)));
    putFIXED (mNEXT_ATOMp, numberRHS);
  }
  // ATOM#_FAULT = 2; (7164)
  {
    int32_t numberRHS = (int32_t)(2);
    putFIXED (mATOMp_FAULT, numberRHS);
  }
  // D3=SHL(-D3,16); (7165)
  {
    int32_t numberRHS
        = (int32_t)(SHL (xminus (getFIXED (mHALMAT_RELOCATExD3)), 16));
    putFIXED (mHALMAT_RELOCATExD3, numberRHS);
  }
  // D2 = SHL(D2 + D4 - ATOM#_FAULT,16); (7166)
  {
    int32_t numberRHS
        = (int32_t)(SHL (xsubtract (xadd (getFIXED (mHALMAT_RELOCATExD2),
                                          COREHALFWORD (mHALMAT_RELOCATExD4)),
                                    getFIXED (mATOMp_FAULT)),
                         16));
    putFIXED (mHALMAT_RELOCATExD2, numberRHS);
  }
  // DO I = 2 TO NEXT_ATOM# - 1; (7167)
  {
    int32_t from115, to115, by115;
    from115 = 2;
    to115 = xsubtract (getFIXED (mNEXT_ATOMp), 1);
    by115 = 1;
    for (putFIXED (mHALMAT_RELOCATExI, from115);
         getFIXED (mHALMAT_RELOCATExI) <= to115;
         putFIXED (mHALMAT_RELOCATExI, getFIXED (mHALMAT_RELOCATExI) + by115))
      {
        // D4=SHR(ATOMS(I)& 240,4); (7168)
        {
          int32_t numberRHS = (int32_t)(SHR (
              xAND (getFIXED (getFIXED (mFOR_ATOMS)
                              + 4 * (getFIXED (mHALMAT_RELOCATExI)) + 0
                              + 4 * (0)),
                    240),
              4));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mHALMAT_RELOCATExD4, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF ATOMS(I) THEN (7169)
        if (1
            & (getFIXED (getFIXED (mFOR_ATOMS)
                         + 4 * (getFIXED (mHALMAT_RELOCATExI)) + 0 + 4 * (0))))
          // IF (D4=XVAC)|(D4=XXPT) THEN (7170)
          if (1
              & (xOR (
                  xEQ (COREHALFWORD (mHALMAT_RELOCATExD4), BYTE0 (mXVAC)),
                  xEQ (COREHALFWORD (mHALMAT_RELOCATExD4), BYTE0 (mXXPT)))))
            // DO; (7171)
            {
            rs3s1:;
              // IF ATOMS(I)>=D3 THEN (7172)
              if (1
                  & (xGE (getFIXED (getFIXED (mFOR_ATOMS)
                                    + 4 * (getFIXED (mHALMAT_RELOCATExI)) + 0
                                    + 4 * (0)),
                          getFIXED (mHALMAT_RELOCATExD3))))
                // ATOMS(I)=ATOMS(I)-D3; (7173)
                {
                  int32_t numberRHS = (int32_t)(xsubtract (
                      getFIXED (getFIXED (mFOR_ATOMS)
                                + 4 * (getFIXED (mHALMAT_RELOCATExI)) + 0
                                + 4 * (0)),
                      getFIXED (mHALMAT_RELOCATExD3)));
                  putFIXED (getFIXED (mFOR_ATOMS)
                                + 4 * (getFIXED (mHALMAT_RELOCATExI)) + 0
                                + 4 * (0),
                            numberRHS);
                }
              // ELSE (7174)
              else
                // ATOMS(I)=ATOMS(I)+D2; (7175)
                {
                  int32_t numberRHS = (int32_t)(xadd (
                      getFIXED (getFIXED (mFOR_ATOMS)
                                + 4 * (getFIXED (mHALMAT_RELOCATExI)) + 0
                                + 4 * (0)),
                      getFIXED (mHALMAT_RELOCATExD2)));
                  putFIXED (getFIXED (mFOR_ATOMS)
                                + 4 * (getFIXED (mHALMAT_RELOCATExI)) + 0
                                + 4 * (0),
                            numberRHS);
                }
            es3s1:;
            } // End of DO block
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
