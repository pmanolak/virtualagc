/*
  File GET_EON.c generated by XCOM-I, 2024-08-09 12:41:08.
*/

#include "runtimeC.h"

int32_t
GET_EON (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_EON");
// REPEATT: (716)
REPEATT:
  // DO WHILE NODE(PTR) ~= END_OF_NODE; (717)
  while (1
         & (xNEQ (getFIXED (mNODE + 4 * COREHALFWORD (mGET_EONxPTR)),
                  getFIXED (mEND_OF_NODE))))
    {
      // PTR = PTR - 1; (718)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (COREHALFWORD (mGET_EONxPTR), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGET_EONxPTR, bitRHS);
        bitRHS->inUse = 0;
      }
      if (0)
        {
        rs1:
          continue;
        es1:
          break;
        } // block labeled REPEATT
    }     // End of DO WHILE block
  // IF GET_EOL THEN (719)
  if (1 & (bitToFixed (getBIT (8, mGET_EONxGET_EOL))))
    // DO; (720)
    {
    rs2:;
      // PTR = PTR - 2; (721)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (COREHALFWORD (mGET_EONxPTR), 2));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mGET_EONxPTR, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF NODE(PTR) ~= END_OF_LIST THEN (722)
      if (1
          & (xNEQ (getFIXED (mNODE + 4 * COREHALFWORD (mGET_EONxPTR)),
                   getFIXED (mEND_OF_LIST))))
        // GO TO REPEATT; (723)
        goto REPEATT;
    es2:;
    } // End of DO block
  // GET_EOL = FALSE; (724)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mGET_EONxGET_EOL, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN PTR; (725)
  {
    reentryGuard = 0;
    return COREHALFWORD (mGET_EONxPTR);
  }
}
