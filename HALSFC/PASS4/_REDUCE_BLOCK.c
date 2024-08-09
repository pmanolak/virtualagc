/*
  File _REDUCE_BLOCK.c generated by XCOM-I, 2024-08-09 12:40:27.
*/

#include "runtimeC.h"

int32_t
_REDUCE_BLOCK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_REDUCE_BLOCK");
  // OLDNBYTES=_FREEBLOCK_SIZE(BLOCK); (232)
  {
    int32_t numberRHS
        = (int32_t)(COREWORD (xsubtract (getFIXED (m_REDUCE_BLOCKxBLOCK), 4)));
    putFIXED (m_REDUCE_BLOCKxOLDNBYTES, numberRHS);
  }
  // IF REMBYTES > OLDNBYTES THEN (233)
  if (1
      & (xGT (getFIXED (m_REDUCE_BLOCKxREMBYTES),
              getFIXED (m_REDUCE_BLOCKxOLDNBYTES))))
    // DO; (234)
    {
    rs1:;
      // DO; (235)
      {
      rs1s1:;
        // CALL _SPMANERR('IN REDUCE_BLOCK, REMBYTES='||REMBYTES||',
        // OLDNBYTES='||OLDNBYTES); (236)
        {
          putCHARACTERp (
              m_SPMANERRxMSG,
              xsCAT (xsCAT (xsCAT (cToDescriptor (
                                       NULL, "IN REDUCE_BLOCK, REMBYTES="),
                                   fixedToCharacter (
                                       getFIXED (m_REDUCE_BLOCKxREMBYTES))),
                            cToDescriptor (NULL, ", OLDNBYTES=")),
                     fixedToCharacter (getFIXED (m_REDUCE_BLOCKxOLDNBYTES))));
          _SPMANERR (0);
        }
      es1s1:;
      } // End of DO block
      // CALL EXIT; (237)
      EXIT ();
    es1:;
    } // End of DO block
  // IF ~TOP & (REMBYTES < OLDNBYTES) THEN (238)
  if (1
      & (xAND (xNOT (BYTE0 (m_REDUCE_BLOCKxTOP)),
               xLT (getFIXED (m_REDUCE_BLOCKxREMBYTES),
                    getFIXED (m_REDUCE_BLOCKxOLDNBYTES)))))
    // _FREEBLOCK_SIZE(BLOCK)=OLDNBYTES-REMBYTES; (239)
    {
      int32_t numberRHS
          = (int32_t)(xsubtract (getFIXED (m_REDUCE_BLOCKxOLDNBYTES),
                                 getFIXED (m_REDUCE_BLOCKxREMBYTES)));
      COREWORD2 (xsubtract (getFIXED (m_REDUCE_BLOCKxBLOCK), 4), numberRHS);
    }
  // ELSE (240)
  else
    // DO; (241)
    {
    rs2:;
      // PREV=_PREV_FREEBLOCK(BLOCK); (242)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (m_PREV_FREEBLOCKxBLOCK, getFIXED (m_REDUCE_BLOCKxBLOCK)),
            _PREV_FREEBLOCK (0)));
        putFIXED (m_REDUCE_BLOCKxPREV, numberRHS);
      }
      // IF REMBYTES=OLDNBYTES THEN (243)
      if (1
          & (xEQ (getFIXED (m_REDUCE_BLOCKxREMBYTES),
                  getFIXED (m_REDUCE_BLOCKxOLDNBYTES))))
        // DO; (244)
        {
        rs2s1:;
          // IF PREV=0 THEN (245)
          if (1 & (xEQ (getFIXED (m_REDUCE_BLOCKxPREV), 0)))
            // FIRSTBLOCK=_FREEBLOCK_NEXT(BLOCK); (246)
            {
              int32_t numberRHS
                  = (int32_t)(COREWORD (getFIXED (m_REDUCE_BLOCKxBLOCK)));
              putFIXED (mFIRSTBLOCK, numberRHS);
            }
          // ELSE (247)
          else
            // _FREEBLOCK_NEXT(PREV)=_FREEBLOCK_NEXT(BLOCK); (248)
            {
              int32_t numberRHS
                  = (int32_t)(COREWORD (getFIXED (m_REDUCE_BLOCKxBLOCK)));
              COREWORD2 (getFIXED (m_REDUCE_BLOCKxPREV), numberRHS);
            }
        es2s1:;
        } // End of DO block
      // ELSE (249)
      else
        // DO; (250)
        {
        rs2s2:;
          // NEWBLOCK=BLOCK-REMBYTES; (251)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (getFIXED (m_REDUCE_BLOCKxBLOCK),
                                       getFIXED (m_REDUCE_BLOCKxREMBYTES)));
            putFIXED (m_REDUCE_BLOCKxNEWBLOCK, numberRHS);
          }
          // _FREEBLOCK_NEXT(NEWBLOCK)=_FREEBLOCK_NEXT(BLOCK); (252)
          {
            int32_t numberRHS
                = (int32_t)(COREWORD (getFIXED (m_REDUCE_BLOCKxBLOCK)));
            COREWORD2 (getFIXED (m_REDUCE_BLOCKxNEWBLOCK), numberRHS);
          }
          // _FREEBLOCK_SIZE(NEWBLOCK)=OLDNBYTES-REMBYTES; (253)
          {
            int32_t numberRHS
                = (int32_t)(xsubtract (getFIXED (m_REDUCE_BLOCKxOLDNBYTES),
                                       getFIXED (m_REDUCE_BLOCKxREMBYTES)));
            COREWORD2 (xsubtract (getFIXED (m_REDUCE_BLOCKxNEWBLOCK), 4),
                       numberRHS);
          }
          // IF PREV=0 THEN (254)
          if (1 & (xEQ (getFIXED (m_REDUCE_BLOCKxPREV), 0)))
            // FIRSTBLOCK=NEWBLOCK; (255)
            {
              int32_t numberRHS
                  = (int32_t)(getFIXED (m_REDUCE_BLOCKxNEWBLOCK));
              putFIXED (mFIRSTBLOCK, numberRHS);
            }
          // ELSE (256)
          else
            // _FREEBLOCK_NEXT(PREV)=NEWBLOCK; (257)
            {
              int32_t numberRHS
                  = (int32_t)(getFIXED (m_REDUCE_BLOCKxNEWBLOCK));
              COREWORD2 (getFIXED (m_REDUCE_BLOCKxPREV), numberRHS);
            }
        es2s2:;
        } // End of DO block
    es2:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
