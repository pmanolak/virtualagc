/*
  File SET_OUTER_REF.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
SET_OUTER_REF (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "SET_OUTER_REF");
  // IF OUTER_REF_INDEX = OUTER_REF_LIM THEN (4810)
  if (1
      & (xEQ (COREHALFWORD (mOUTER_REF_INDEX), COREHALFWORD (mOUTER_REF_LIM))))
    // CALL COMPRESS_OUTER_REF; (4811)
    COMPRESS_OUTER_REF (0);
  // DO WHILE OUTER_REF_INDEX >= RECORD_TOP(OUTER_REF_TABLE); (4812)
  while (1
         & (xGE (COREHALFWORD (mOUTER_REF_INDEX),
                 xsubtract (
                     COREWORD (xadd (
                         ADDR ("OUTER_REF_TABLE", 0x80000000, NULL, 0), 12)),
                     1))))
    {
      // DO ; (4813)
      {
      rs1s1:;
        // IF COREWORD ( ADDR ( OUTER_REF_TABLE ) + 12 ) >= COREWORD ( ADDR (
        // OUTER_REF_TABLE ) + 8 ) THEN (4814)
        if (1
            & (xGE (COREWORD (xadd (
                        ADDR ("OUTER_REF_TABLE", 0x80000000, NULL, 0), 12)),
                    COREWORD (xadd (
                        ADDR ("OUTER_REF_TABLE", 0x80000000, NULL, 0), 8)))))
          // CALL _NEEDMORE_SPACE ( ADDR ( OUTER_REF_TABLE )  ) ; (4815)
          {
            putFIXED (m_NEEDMORE_SPACExDOPE,
                      ADDR ("OUTER_REF_TABLE", 0x80000000, NULL, 0));
            _NEEDMORE_SPACE (0);
          }
        // COREWORD ( ADDR ( OUTER_REF_TABLE ) + 12 ) = COREWORD ( ADDR (
        // OUTER_REF_TABLE ) + 12 ) + 1 ; (4816)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREWORD (
                  xadd (ADDR ("OUTER_REF_TABLE", 0x80000000, NULL, 0), 12)),
              1));
          COREWORD2 (xadd (ADDR ("OUTER_REF_TABLE", 0x80000000, NULL, 0), 12),
                     numberRHS);
        }
      es1s1:;
      } // End of DO block
    }   // End of DO WHILE block
  // OUTER_REF_INDEX = OUTER_REF_INDEX + 1; (4817)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mOUTER_REF_INDEX), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOUTER_REF_INDEX, bitRHS);
    bitRHS->inUse = 0;
  }
  // OUTER_REF(OUTER_REF_INDEX) = LOC; (4818)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mSET_OUTER_REFxLOC));
    putBIT (16,
            getFIXED (mOUTER_REF_TABLE) + 3 * (COREHALFWORD (mOUTER_REF_INDEX))
                + 0 + 2 * (0),
            fixedToBit (16, numberRHS));
  }
  // OUTER_REF_FLAGS(OUTER_REF_INDEX) = SHR(FLAG, 13); (4819)
  {
    int32_t numberRHS = (int32_t)(SHR (getFIXED (mSET_OUTER_REFxFLAG), 13));
    putBIT (8,
            getFIXED (mOUTER_REF_TABLE) + 3 * (COREHALFWORD (mOUTER_REF_INDEX))
                + 2 + 1 * (0),
            fixedToBit (8, numberRHS));
  }
  // OUTER_REF_MAX = MAX(OUTER_REF_MAX,OUTER_REF_INDEX); (4820)
  {
    int32_t numberRHS = (int32_t)((
        putFIXED (mMAXxI, COREHALFWORD (mOUTER_REF_MAX)),
        putFIXED (mMAXxJ, COREHALFWORD (mOUTER_REF_INDEX)), MAX (0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mOUTER_REF_MAX, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
