/*
  File GENERATExGEN_CLASS0xRETURN_STRUCTURE_STACK.c generated by XCOM-I,
  2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExGEN_CLASS0xRETURN_STRUCTURE_STACK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard,
                               "GENERATExGEN_CLASS0xRETURN_STRUCTURE_STACK");
  // SAVE_STACK = FALSE; (10769)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mSAVE_STACK, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO FOR I = 1 TO STACK_SIZE; (10770)
  {
    int32_t from107, to107, by107;
    from107 = 1;
    to107 = 100;
    by107 = 1;
    for (putBIT (16, mGENERATExGEN_CLASS0xRETURN_STRUCTURE_STACKxI,
                 fixedToBit (16, from107));
         bitToFixed (
             getBIT (16, mGENERATExGEN_CLASS0xRETURN_STRUCTURE_STACKxI))
         <= to107;
         putBIT (
             16, mGENERATExGEN_CLASS0xRETURN_STRUCTURE_STACKxI,
             fixedToBit (
                 16, bitToFixed (getBIT (
                         16, mGENERATExGEN_CLASS0xRETURN_STRUCTURE_STACKxI))
                         + by107)))
      {
        // IF SAVE_STACK(I) = TRUE THEN (10771)
        if (1
            & (xEQ (
                BYTE0 (
                    mSAVE_STACK
                    + 1
                          * COREHALFWORD (
                              mGENERATExGEN_CLASS0xRETURN_STRUCTURE_STACKxI)),
                1)))
          // DO; (10772)
          {
          rs1s1:;
            // CALL RETURN_STACK_ENTRY(I); (10773)
            {
              putBITp (
                  16, mGENERATExRETURN_STACK_ENTRYxP,
                  getBIT (16, mGENERATExGEN_CLASS0xRETURN_STRUCTURE_STACKxI));
              GENERATExRETURN_STACK_ENTRY (0);
            }
            // SAVE_STACK(I) = FALSE; (10774)
            {
              int32_t numberRHS = (int32_t)(0);
              descriptor_t *bitRHS;
              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
              putBIT (
                  1,
                  mSAVE_STACK
                      + 1
                            * (COREHALFWORD (
                                mGENERATExGEN_CLASS0xRETURN_STRUCTURE_STACKxI)),
                  bitRHS);
              bitRHS->inUse = 0;
            }
          es1s1:;
          } // End of DO block
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
