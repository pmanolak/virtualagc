/*
  File OBJECT_GENERATORxAPRINT.c generated by XCOM-I, 2024-08-09 12:41:33.
*/

#include "runtimeC.h"

int32_t
OBJECT_GENERATORxAPRINT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "OBJECT_GENERATORxAPRINT");
  // IF CODE_LISTING THEN (15035)
  if (1 & (bitToFixed (getBIT (1, mCODE_LISTING))))
    // OUTPUT(1) = LINE; (15036)
    {
      descriptor_t *stringRHS;
      stringRHS = getCHARACTER (mOBJECT_GENERATORxAPRINTxLINE);
      OUTPUT (1, stringRHS);
      stringRHS->inUse = 0;
    }
  // IF EXTRA_LISTING THEN (15037)
  if (1 & (bitToFixed (getBIT (1, mEXTRA_LISTING))))
    // DO; (15038)
    {
    rs1:;
      // ABSLIST_COUNT = ABSLIST_COUNT + 1; (15039)
      {
        int32_t numberRHS = (int32_t)(xadd (
            COREHALFWORD (mOBJECT_GENERATORxABSLIST_COUNT), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mOBJECT_GENERATORxABSLIST_COUNT, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF ABSLIST_COUNT > LINE_LIM THEN (15040)
      if (1
          & (xGT (COREHALFWORD (mOBJECT_GENERATORxABSLIST_COUNT),
                  COREHALFWORD (mOBJECT_GENERATORxLINE_LIM))))
        // DO; (15041)
        {
        rs1s1:;
          // IF PAGE_NUM = 0 THEN (15042)
          if (1 & (xEQ (COREHALFWORD (mOBJECT_GENERATORxAPRINTxPAGE_NUM), 0)))
            // DO; (15043)
            {
            rs1s1s1:;
              // LINE_LIM = VALS(1); (15044)
              {
                int32_t numberRHS
                    = (int32_t)(getFIXED (getFIXED (mVALS) + 4 * 1));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mOBJECT_GENERATORxLINE_LIM, bitRHS);
                bitRHS->inUse = 0;
              }
              // DO I = 0 TO 3; (15045)
              {
                int32_t from143, to143, by143;
                from143 = 0;
                to143 = 3;
                by143 = 1;
                for (putBIT (16, mOBJECT_GENERATORxAPRINTxI,
                             fixedToBit (16, from143));
                     bitToFixed (getBIT (16, mOBJECT_GENERATORxAPRINTxI))
                     <= to143;
                     putBIT (
                         16, mOBJECT_GENERATORxAPRINTxI,
                         fixedToBit (16, bitToFixed (getBIT (
                                             16, mOBJECT_GENERATORxAPRINTxI))
                                             + by143)))
                  {
                    // BYTE(CC(I)) = ICC(I); (15046)
                    {
                      descriptor_t *bitRHS = getBIT (
                          8,
                          mOBJECT_GENERATORxICC
                              + 1 * COREHALFWORD (mOBJECT_GENERATORxAPRINTxI));
                      lBYTEb (ADDR (NULL, 0, "OBJECT_GENERATORxCC",
                                    COREHALFWORD (mOBJECT_GENERATORxAPRINTxI)),
                              0,
                              BYTE0 (mOBJECT_GENERATORxICC
                                     + 1
                                           * COREHALFWORD (
                                               mOBJECT_GENERATORxAPRINTxI)));
                      bitRHS->inUse = 0;
                    }
                  }
              } // End of DO for-loop block
            es1s1s1:;
            } // End of DO block
          // PAGE_NUM = PAGE_NUM + 1; (15047)
          {
            int32_t numberRHS = (int32_t)(xadd (
                COREHALFWORD (mOBJECT_GENERATORxAPRINTxPAGE_NUM), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mOBJECT_GENERATORxAPRINTxPAGE_NUM, bitRHS);
            bitRHS->inUse = 0;
          }
          // OUTPUT(7) = CC; (15048)
          {
            descriptor_t *stringRHS;
            stringRHS = getCHARACTER (mOBJECT_GENERATORxCC);
            OUTPUT (7, stringRHS);
            stringRHS->inUse = 0;
          }
          // OUTPUT(7) = CC(3) || ATITLE(APAGE) || ' PAGE ' || PAGE_NUM;
          // (15049)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                xsCAT (
                    xsCAT (getCHARACTER (mOBJECT_GENERATORxCC + 4 * 3),
                           getCHARACTER (
                               mOBJECT_GENERATORxATITLE
                               + 4 * COREHALFWORD (mOBJECT_GENERATORxAPAGE))),
                    cToDescriptor (
                        NULL, "                                   PAGE ")),
                bitToCharacter (
                    getBIT (16, mOBJECT_GENERATORxAPRINTxPAGE_NUM)));
            OUTPUT (7, stringRHS);
            stringRHS->inUse = 0;
          }
          // OUTPUT(7) = CC(2) || SUBSTR(AHEAD(APAGE), 1); (15050)
          {
            descriptor_t *stringRHS;
            stringRHS = xsCAT (
                getCHARACTER (mOBJECT_GENERATORxCC + 4 * 2),
                SUBSTR2 (getCHARACTER (
                             mOBJECT_GENERATORxAHEAD
                             + 4 * COREHALFWORD (mOBJECT_GENERATORxAPAGE)),
                         1));
            OUTPUT (7, stringRHS);
            stringRHS->inUse = 0;
          }
          // ABSLIST_COUNT = 6; (15051)
          {
            int32_t numberRHS = (int32_t)(6);
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mOBJECT_GENERATORxABSLIST_COUNT, bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
      // OUTPUT(7) = CC(1) || SUBSTR(LINE, 1); (15052)
      {
        descriptor_t *stringRHS;
        stringRHS = xsCAT (
            getCHARACTER (mOBJECT_GENERATORxCC + 4 * 1),
            SUBSTR2 (getCHARACTER (mOBJECT_GENERATORxAPRINTxLINE), 1));
        OUTPUT (7, stringRHS);
        stringRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
