/*
  File _FIND_FREE.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

int32_t
_FIND_FREE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_FIND_FREE");
  // DO; (515)
  {
  rs1:;
    // IF FREEBYTES < NBYTES THEN (516)
    if (1 & (xLT (getFIXED (mFREEBYTES), getFIXED (m_FIND_FREExNBYTES))))
      // CALL _STEAL(NBYTES-FREEBYTES); (517)
      {
        putFIXED (m_STEALxNBYTES, xsubtract (getFIXED (m_FIND_FREExNBYTES),
                                             getFIXED (mFREEBYTES)));
        _STEAL (0);
      }
  es1:;
  } // End of DO block
  // ; (518)
  ;
  // IF UNMOVEABLE THEN (519)
  if (1 & (bitToFixed (getBIT (1, m_FIND_FREExUNMOVEABLE))))
    // DO; (520)
    {
    rs2:;
      // CALL _SQUASH_RECORDS; (521)
      _SQUASH_RECORDS (0);
      // DOPE=FIRSTRECORD; (522)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mFIRSTRECORD));
        putFIXED (m_FIND_FREExDOPE, numberRHS);
      }
      // DO WHILE DOPE~=0; (523)
      while (1 & (xNEQ (getFIXED (m_FIND_FREExDOPE), 0)))
        {
          // IF ~_IS_REC_UNMOVEABLE(DOPE) THEN (524)
          if (1
              & (xNOT (xNEQ (
                  xAND (COREWORD (xadd (getFIXED (m_FIND_FREExDOPE), 20)),
                        33554432),
                  0))))
            // DO; (525)
            {
            rs2s1s1:;
              // CURBLOCK=_DOPE_POINTER(DOPE)+_RECORD#BYTES(DOPE)-4; (526)
              {
                int32_t numberRHS = (int32_t)(xsubtract (
                    xadd (
                        COREWORD (getFIXED (m_FIND_FREExDOPE)),
                        (putFIXED (
                             m_SPACE_ROUNDxBYTES,
                             xmultiply (COREWORD (xadd (
                                            getFIXED (m_FIND_FREExDOPE), 8)),
                                        COREHALFWORD (xadd (
                                            getFIXED (m_FIND_FREExDOPE), 4)))),
                         _SPACE_ROUND (0))),
                    4));
                putFIXED (m_FIND_FREExCURBLOCK, numberRHS);
              }
              // CALL _MOVE_RECS(DOPE,NBYTES); (527)
              {
                putFIXED (m_MOVE_RECSxDOPE, getFIXED (m_FIND_FREExDOPE));
                putFIXED (m_MOVE_RECSxBYTES_TO_MOVE_BY,
                          getFIXED (m_FIND_FREExNBYTES));
                _MOVE_RECS (0);
              }
              // _FREEBLOCK_SIZE(CURBLOCK)=NBYTES; (528)
              {
                int32_t numberRHS = (int32_t)(getFIXED (m_FIND_FREExNBYTES));
                COREWORD2 (xsubtract (getFIXED (m_FIND_FREExCURBLOCK), 4),
                           numberRHS);
              }
              // _FREEBLOCK_NEXT(CURBLOCK)=0; (529)
              {
                int32_t numberRHS = (int32_t)(0);
                COREWORD2 (getFIXED (m_FIND_FREExCURBLOCK), numberRHS);
              }
              // CALL _ATTACH_BLOCK(CURBLOCK); (530)
              {
                putFIXED (m_ATTACH_BLOCKxBLOCK,
                          getFIXED (m_FIND_FREExCURBLOCK));
                _ATTACH_BLOCK (0);
              }
              // RETURN CURBLOCK; (531)
              {
                reentryGuard = 0;
                return getFIXED (m_FIND_FREExCURBLOCK);
              }
            es2s1s1:;
            } // End of DO block
          // DOPE=_DOPE_NEXT(DOPE); (532)
          {
            int32_t numberRHS
                = (int32_t)(COREWORD (xadd (getFIXED (m_FIND_FREExDOPE), 16)));
            putFIXED (m_FIND_FREExDOPE, numberRHS);
          }
        } // End of DO WHILE block
      // RETURN FIRSTBLOCK; (533)
      {
        reentryGuard = 0;
        return getFIXED (mFIRSTBLOCK);
      }
    es2:;
    } // End of DO block
  // DO I = 0 TO 1; (534)
  {
    int32_t from13, to13, by13;
    from13 = 0;
    to13 = 1;
    by13 = 1;
    for (putBIT (16, m_FIND_FREExI, fixedToBit (16, from13));
         bitToFixed (getBIT (16, m_FIND_FREExI)) <= to13; putBIT (
             16, m_FIND_FREExI,
             fixedToBit (16, bitToFixed (getBIT (16, m_FIND_FREExI)) + by13)))
      {
        // CURBLOCK=FIRSTBLOCK; (535)
        {
          int32_t numberRHS = (int32_t)(getFIXED (mFIRSTBLOCK));
          putFIXED (m_FIND_FREExCURBLOCK, numberRHS);
        }
        // DO WHILE CURBLOCK ~= 0; (536)
        while (1 & (xNEQ (getFIXED (m_FIND_FREExCURBLOCK), 0)))
          {
            // IF _FREEBLOCK_SIZE(CURBLOCK) >= NBYTES THEN (537)
            if (1
                & (xGE (
                    COREWORD (xsubtract (getFIXED (m_FIND_FREExCURBLOCK), 4)),
                    getFIXED (m_FIND_FREExNBYTES))))
              // RETURN CURBLOCK; (538)
              {
                reentryGuard = 0;
                return getFIXED (m_FIND_FREExCURBLOCK);
              }
            // CURBLOCK=_FREEBLOCK_NEXT(CURBLOCK); (539)
            {
              int32_t numberRHS
                  = (int32_t)(COREWORD (getFIXED (m_FIND_FREExCURBLOCK)));
              putFIXED (m_FIND_FREExCURBLOCK, numberRHS);
            }
          } // End of DO WHILE block
        // CALL _SQUASH_RECORDS; (540)
        _SQUASH_RECORDS (0);
        // RETURN FIRSTBLOCK; (541)
        {
          reentryGuard = 0;
          return getFIXED (mFIRSTBLOCK);
        }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}