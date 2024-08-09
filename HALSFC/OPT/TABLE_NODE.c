/*
  File TABLE_NODE.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
TABLE_NODE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "TABLE_NODE");
  // IF TRACE THEN (3479)
  if (1 & (bitToFixed (getBIT (8, mTRACE))))
    // OUTPUT = 'TABLE_NODE'; (3480)
    {
      descriptor_t *stringRHS;
      stringRHS = cToDescriptor (NULL, "TABLE_NODE");
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // IF ARRAYED_CONDITIONAL THEN (3481)
  if (1 & (bitToFixed (getBIT (8, mARRAYED_CONDITIONAL))))
    // RETURN; (3482)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF TOTAL_MATCH_PRES AND INVARIANT_PULLED THEN (3483)
  if (1 & (xAND (BYTE0 (mTOTAL_MATCH_PRES), BYTE0 (mINVARIANT_PULLED))))
    // DO; (3484)
    {
    rs1:;
      // NODE_SIZE = 0; (3485)
      {
        int32_t numberRHS = (int32_t)(0);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mNODE_SIZE, bitRHS);
        bitRHS->inUse = 0;
      }
      // TEMP = 1; (3486)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mTABLE_NODExTEMP, bitRHS);
        bitRHS->inUse = 0;
      }
      // NODE = NODE(NODE_BEGINNING - TEMP); (3487)
      {
        int32_t numberRHS = (int32_t)(getFIXED (
            mNODE
            + 4
                  * xsubtract (COREHALFWORD (mNODE_BEGINNING),
                               COREHALFWORD (mTABLE_NODExTEMP))));
        putFIXED (mNODE, numberRHS);
      }
      // DO WHILE NODE ~= END_OF_NODE; (3488)
      while (1 & (xNEQ (getFIXED (mNODE), getFIXED (mEND_OF_NODE))))
        {
          // IF TYPE(NODE) > 5 THEN (3489)
          if (1
              & (xGT (bitToFixed ((putFIXED (mTYPExCSE_WORD, getFIXED (mNODE)),
                                   TYPE (0))),
                      5)))
            // DO; (3490)
            {
            rs1s1s1:;
              // NODE_SIZE = NODE_SIZE + 1; (3491)
              {
                int32_t numberRHS
                    = (int32_t)(xadd (COREHALFWORD (mNODE_SIZE), 1));
                descriptor_t *bitRHS;
                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                putBIT (16, mNODE_SIZE, bitRHS);
                bitRHS->inUse = 0;
              }
              // SEARCH(NODE_SIZE) = NODE; (3492)
              {
                int32_t numberRHS = (int32_t)(getFIXED (mNODE));
                putFIXED (mSEARCH + 4 * (COREHALFWORD (mNODE_SIZE)),
                          numberRHS);
              }
              // SEARCH2(NODE_SIZE) = NODE2(NODE_BEGINNING - TEMP); (3493)
              {
                descriptor_t *bitRHS = getBIT (
                    16,
                    mNODE2
                        + 2
                              * xsubtract (COREHALFWORD (mNODE_BEGINNING),
                                           COREHALFWORD (mTABLE_NODExTEMP)));
                putBIT (16, mSEARCH2 + 2 * (COREHALFWORD (mNODE_SIZE)),
                        bitRHS);
                bitRHS->inUse = 0;
              }
            es1s1s1:;
            } // End of DO block
          // TEMP = TEMP + 1; (3494)
          {
            int32_t numberRHS
                = (int32_t)(xadd (COREHALFWORD (mTABLE_NODExTEMP), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mTABLE_NODExTEMP, bitRHS);
            bitRHS->inUse = 0;
          }
          // NODE = NODE(NODE_BEGINNING - TEMP); (3495)
          {
            int32_t numberRHS = (int32_t)(getFIXED (
                mNODE
                + 4
                      * xsubtract (COREHALFWORD (mNODE_BEGINNING),
                                   COREHALFWORD (mTABLE_NODExTEMP))));
            putFIXED (mNODE, numberRHS);
          }
        } // End of DO WHILE block
    es1:;
    } // End of DO block
  // DO FOR SEARCH_INX = 1 TO NODE_SIZE; (3496)
  {
    int32_t from87, to87, by87;
    from87 = 1;
    to87 = bitToFixed (getBIT (16, mNODE_SIZE));
    by87 = 1;
    for (putBIT (16, mTABLE_NODExSEARCH_INX, fixedToBit (16, from87));
         bitToFixed (getBIT (16, mTABLE_NODExSEARCH_INX)) <= to87; putBIT (
             16, mTABLE_NODExSEARCH_INX,
             fixedToBit (16, bitToFixed (getBIT (16, mTABLE_NODExSEARCH_INX))
                                 + by87)))
      {
        // SEARCH = SEARCH(SEARCH_INX); (3497)
        {
          int32_t numberRHS = (int32_t)(getFIXED (
              mSEARCH + 4 * COREHALFWORD (mTABLE_NODExSEARCH_INX)));
          putFIXED (mSEARCH, numberRHS);
        }
        // IF SEARCH ~= 0 THEN (3498)
        if (1 & (xNEQ (getFIXED (mSEARCH), 0)))
          // DO CASE TYPE(SEARCH); (3499)
          {
          rs2s1:
            switch (bitToFixed (
                (putFIXED (mTYPExCSE_WORD, getFIXED (mSEARCH)), TYPE (0))))
              {
              case 0:
                  // ; (3501)
                  ;
                break;
              case 1:
                  // ; (3502)
                  ;
                break;
              case 2:
                  // ; (3503)
                  ;
                break;
              case 3:
                  // ; (3504)
                  ;
                break;
              case 4:
                  // ; (3505)
                  ;
                break;
              case 5:
                  // ; (3506)
                  ;
                break;
              case 6:
                  // ; (3507)
                  ;
                break;
              case 7:
                  // ; (3508)
                  ;
                break;
              case 8:
                  // ; (3509)
                  ;
                break;
              case 9:
                  // ; (3510)
                  ;
                break;
              case 10:
                  // ; (3511)
                  ;
                break;
              case 11:
                // DO; (3512)
                {
                rs2s1s1:;
                  // CAT_PTR = CATALOG_SRCH(SEARCH); (3512)
                  {
                    descriptor_t *bitRHS
                        = (putBITp (
                               16, mCATALOG_SRCHxPTR,
                               fixedToBit (32, (int32_t)(getFIXED (mSEARCH)))),
                           CATALOG_SRCH (0));
                    putBIT (16, mTABLE_NODExCAT_PTR, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // IF CAT_PTR ~= 0 THEN (3513)
                  if (1 & (xNEQ (COREHALFWORD (mTABLE_NODExCAT_PTR), 0)))
                    // DO; (3514)
                    {
                    rs2s1s1s1:;
                    // ENTER: (3515)
                    ENTER:
                      // IF CSE_TAB(CSE_INX) ~= NODE_BEGINNING THEN (3516)
                      if (1
                          & (xNEQ (COREHALFWORD (
                                       mCSE_TAB + 2 * COREHALFWORD (mCSE_INX)),
                                   COREHALFWORD (mNODE_BEGINNING))))
                        // DO; (3517)
                        {
                        rs2s1s1s1s1:;
                          // CSE_TAB(CAT_PTR),TEMP =
                          // GET_FREE_SPACE(NODE_ENTRY_SIZE); (3518)
                          {
                            descriptor_t *bitRHS
                                = (putBITp (16, mGET_FREE_SPACExSPACE,
                                            fixedToBit (32, (int32_t)(3))),
                                   GET_FREE_SPACE (0));
                            putBIT (
                                16,
                                mCSE_TAB
                                    + 2 * (COREHALFWORD (mTABLE_NODExCAT_PTR)),
                                bitRHS);
                            putBIT (16, mTABLE_NODExTEMP, bitRHS);
                            bitRHS->inUse = 0;
                          }
                          // CSE_TAB(TEMP) = NODE_BEGINNING; (3519)
                          {
                            descriptor_t *bitRHS
                                = getBIT (16, mNODE_BEGINNING);
                            putBIT (
                                16,
                                mCSE_TAB
                                    + 2 * (COREHALFWORD (mTABLE_NODExTEMP)),
                                bitRHS);
                            bitRHS->inUse = 0;
                          }
                          // CSE_TAB(TEMP+1) = CSE_INX; (3520)
                          {
                            descriptor_t *bitRHS = getBIT (16, mCSE_INX);
                            putBIT (16,
                                    mCSE_TAB
                                        + 2
                                              * (xadd (COREHALFWORD (
                                                           mTABLE_NODExTEMP),
                                                       1)),
                                    bitRHS);
                            bitRHS->inUse = 0;
                          }
                          // IF TOTAL_MATCH_PRES AND INVARIANT_PULLED THEN
                          // (3521)
                          if (1
                              & (xAND (BYTE0 (mTOTAL_MATCH_PRES),
                                       BYTE0 (mINVARIANT_PULLED))))
                            // CSE_TAB(TEMP + 2) = SHL(OLD_LEVEL,11) |
                            // OLD_BLOCK#; (3522)
                            {
                              int32_t numberRHS = (int32_t)(xOR (
                                  SHL (COREHALFWORD (mOLD_LEVEL), 11),
                                  COREHALFWORD (mOLD_BLOCKp)));
                              descriptor_t *bitRHS;
                              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                              putBIT (16,
                                      mCSE_TAB
                                          + 2
                                                * (xadd (COREHALFWORD (
                                                             mTABLE_NODExTEMP),
                                                         2)),
                                      bitRHS);
                              bitRHS->inUse = 0;
                            }
                          // ELSE (3523)
                          else
                            // CSE_TAB(TEMP + 2) = SHL(LEVEL,11) | BLOCK#;
                            // (3524)
                            {
                              int32_t numberRHS = (int32_t)(xOR (
                                  SHL (COREHALFWORD (mLEVEL), 11),
                                  COREHALFWORD (mBLOCKp)));
                              descriptor_t *bitRHS;
                              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                              putBIT (16,
                                      mCSE_TAB
                                          + 2
                                                * (xadd (COREHALFWORD (
                                                             mTABLE_NODExTEMP),
                                                         2)),
                                      bitRHS);
                              bitRHS->inUse = 0;
                            }
                        es2s1s1s1s1:;
                        } // End of DO block
                      // ELSE (3525)
                      else
                        // DO; (3526)
                        {
                        rs2s1s1s1s2:;
                          // IF TRACE THEN (3527)
                          if (1 & (bitToFixed (getBIT (8, mTRACE))))
                            // OUTPUT = '   CSE_INX=' || CSE_INX || ', TMP=' ||
                            // TOTAL_MATCH_PRES|| ', IP=' || INVARIANT_PULLED
                            // || ', OB#=' || OLD_BLOCK#; (3528)
                            {
                              descriptor_t *stringRHS;
                              stringRHS = xsCAT (
                                  xsCAT (
                                      xsCAT (
                                          xsCAT (
                                              xsCAT (
                                                  xsCAT (
                                                      xsCAT (
                                                          cToDescriptor (
                                                              NULL,
                                                              "   CSE_INX="),
                                                          bitToCharacter (
                                                              getBIT (
                                                                  16,
                                                                  mCSE_INX))),
                                                      cToDescriptor (
                                                          NULL, ", TMP=")),
                                                  bitToCharacter (getBIT (
                                                      8, mTOTAL_MATCH_PRES))),
                                              cToDescriptor (NULL, ", IP=")),
                                          bitToCharacter (
                                              getBIT (8, mINVARIANT_PULLED))),
                                      cToDescriptor (NULL, ", OB#=")),
                                  bitToCharacter (getBIT (16, mOLD_BLOCKp)));
                              OUTPUT (0, stringRHS);
                              stringRHS->inUse = 0;
                            }
                          // IF TOTAL_MATCH_PRES AND INVARIANT_PULLED THEN
                          // (3529)
                          if (1
                              & (xAND (BYTE0 (mTOTAL_MATCH_PRES),
                                       BYTE0 (mINVARIANT_PULLED))))
                            // CSE_TAB(CSE_INX + 2) = SHL(OLD_LEVEL,11) |
                            // OLD_BLOCK#; (3530)
                            {
                              int32_t numberRHS = (int32_t)(xOR (
                                  SHL (COREHALFWORD (mOLD_LEVEL), 11),
                                  COREHALFWORD (mOLD_BLOCKp)));
                              descriptor_t *bitRHS;
                              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                              putBIT (
                                  16,
                                  mCSE_TAB
                                      + 2
                                            * (xadd (COREHALFWORD (mCSE_INX),
                                                     2)),
                                  bitRHS);
                              bitRHS->inUse = 0;
                            }
                        es2s1s1s1s2:;
                        } // End of DO block
                    es2s1s1s1:;
                    } // End of DO block
                  // IF NONCOMMUTATIVE THEN (3531)
                  if (1 & (bitToFixed (getBIT (8, mNONCOMMUTATIVE))))
                    // RETURN; (3532)
                    {
                      reentryGuard = 0;
                      return 0;
                    }
                es2s1s1:;
                } // End of DO block
                break;
              case 12:
                // DO; (3534)
                {
                rs2s1s2:;
                  // CAT_PTR = CATALOG_SRCH(SEARCH2(SEARCH_INX)); (3534)
                  {
                    descriptor_t *bitRHS
                        = (putBITp (
                               16, mCATALOG_SRCHxPTR,
                               getBIT (16,
                                       mSEARCH2
                                           + 2
                                                 * COREHALFWORD (
                                                     mTABLE_NODExSEARCH_INX))),
                           CATALOG_SRCH (0));
                    putBIT (16, mTABLE_NODExCAT_PTR, bitRHS);
                    bitRHS->inUse = 0;
                  }
                  // IF CAT_PTR = 0 THEN (3535)
                  if (1 & (xEQ (COREHALFWORD (mTABLE_NODExCAT_PTR), 0)))
                    // DO; (3536)
                    {
                    rs2s1s2s1:;
                      // TEMP = GET_FREE_SPACE(CATALOG_ENTRY_SIZE); (3537)
                      {
                        descriptor_t *bitRHS
                            = (putBITp (16, mGET_FREE_SPACExSPACE,
                                        fixedToBit (32, (int32_t)(3))),
                               GET_FREE_SPACE (0));
                        putBIT (16, mTABLE_NODExTEMP, bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // CSE_TAB(CSE_INX + 2) = TEMP; (3538)
                      {
                        descriptor_t *bitRHS = getBIT (16, mTABLE_NODExTEMP);
                        putBIT (16,
                                mCSE_TAB
                                    + 2 * (xadd (COREHALFWORD (mCSE_INX), 2)),
                                bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // CALL CATALOG_ENTRY(TEMP,NODE_BEGINNING); (3539)
                      {
                        putBITp (16, mCATALOG_ENTRYxTEMP,
                                 getBIT (16, mTABLE_NODExTEMP));
                        putBITp (16, mCATALOG_ENTRYxNODE_BEGINNING,
                                 getBIT (16, mNODE_BEGINNING));
                        CATALOG_ENTRY (0);
                      }
                      // CSE_INX = CSE_TAB(TEMP); (3540)
                      {
                        descriptor_t *bitRHS = getBIT (
                            16,
                            mCSE_TAB + 2 * COREHALFWORD (mTABLE_NODExTEMP));
                        putBIT (16, mCSE_INX, bitRHS);
                        bitRHS->inUse = 0;
                      }
                    es2s1s2s1:;
                    } // End of DO block
                  // GO TO ENTER; (3541)
                  goto ENTER;
                es2s1s2:;
                } // End of DO block
                break;
              case 13:
                  // ; (3543)
                  ;
                break;
              case 14:
                  // ; (3544)
                  ;
                break;
              case 15:
                  // ; (3545)
                  ;
                break;
              }
          } // End of DO CASE block
      }
  } // End of DO for-loop block
  // INVARIANT_PULLED = FALSE; (3545)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (8, mINVARIANT_PULLED, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
