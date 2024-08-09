/*
  File _TAKE_BACK.c generated by XCOM-I, 2024-08-09 12:42:16.
*/

#include "runtimeC.h"

int32_t
_TAKE_BACK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_TAKE_BACK");
  // REALLOCATIONS=REALLOCATIONS+1; (408)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mREALLOCATIONS), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mREALLOCATIONS, bitRHS);
    bitRHS->inUse = 0;
  }
  // PREV_FREEPRINT=FREEPRINT; (409)
  {
    descriptor_t *bitRHS = getBIT (1, mFREEPRINT);
    putBIT (1, m_TAKE_BACKxPREV_FREEPRINT, bitRHS);
    bitRHS->inUse = 0;
  }
  // FREEPRINT=_FALSE; (410)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mFREEPRINT, bitRHS);
    bitRHS->inUse = 0;
  }
  // POSSIBLE=_UNUSED_BYTES; (411)
  {
    int32_t numberRHS = (int32_t)(_UNUSED_BYTES (0));
    putFIXED (m_TAKE_BACKxPOSSIBLE, numberRHS);
  }
  // IF NBYTES > POSSIBLE THEN (412)
  if (1
      & (xGT (getFIXED (m_TAKE_BACKxNBYTES), getFIXED (m_TAKE_BACKxPOSSIBLE))))
    // NBYTES=POSSIBLE; (413)
    {
      int32_t numberRHS = (int32_t)(getFIXED (m_TAKE_BACKxPOSSIBLE));
      putFIXED (m_TAKE_BACKxNBYTES, numberRHS);
    }
  // LEFTBYTES=NBYTES; (414)
  {
    int32_t numberRHS = (int32_t)(getFIXED (m_TAKE_BACKxNBYTES));
    putFIXED (m_TAKE_BACKxLEFTBYTES, numberRHS);
  }
  // CUR=FIRSTRECORD; (415)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mFIRSTRECORD));
    putFIXED (m_TAKE_BACKxCUR, numberRHS);
  }
  // DO WHILE (CUR > 0) & (LEFTBYTES > 0); (416)
  while (1
         & (xAND (xGT (getFIXED (m_TAKE_BACKxCUR), 0),
                  xGT (getFIXED (m_TAKE_BACKxLEFTBYTES), 0))))
    {
      // IF ~_IS_REC_CONSTANT(CUR) THEN (417)
      if (1
          & (xNOT (
              xNEQ (xAND (COREWORD (xadd (getFIXED (m_TAKE_BACKxCUR), 20)),
                          50331648),
                    0))))
        // DO; (418)
        {
        rs1s1:;
          // DIF_RECS,RET_RECS=_DOPE_ALLOC(CUR)-_DOPE_USED(CUR); (419)
          {
            int32_t numberRHS = (int32_t)(xsubtract (
                COREWORD (xadd (getFIXED (m_TAKE_BACKxCUR), 8)),
                COREWORD (xadd (getFIXED (m_TAKE_BACKxCUR), 12))));
            putFIXED (m_TAKE_BACKxDIF_RECS, numberRHS);
            putFIXED (m_TAKE_BACKxRET_RECS, numberRHS);
          }
          // IF RET_RECS > 0 THEN (420)
          if (1 & (xGT (getFIXED (m_TAKE_BACKxRET_RECS), 0)))
            // DO; (421)
            {
            rs1s1s1:;
              // RET_RECS=(NBYTES*RET_RECS)/POSSIBLE + 1; (422)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    xdivide (xmultiply (getFIXED (m_TAKE_BACKxNBYTES),
                                        getFIXED (m_TAKE_BACKxRET_RECS)),
                             getFIXED (m_TAKE_BACKxPOSSIBLE)),
                    1));
                putFIXED (m_TAKE_BACKxRET_RECS, numberRHS);
              }
              // IF RET_RECS*_DOPE_WIDTH(CUR) > LEFTBYTES THEN (423)
              if (1
                  & (xGT (xmultiply (getFIXED (m_TAKE_BACKxRET_RECS),
                                     COREHALFWORD (xadd (
                                         getFIXED (m_TAKE_BACKxCUR), 4))),
                          getFIXED (m_TAKE_BACKxLEFTBYTES))))
                // RET_RECS=LEFTBYTES/_DOPE_WIDTH(CUR) + 1; (424)
                {
                  int32_t numberRHS = (int32_t)(xadd (
                      xdivide (
                          getFIXED (m_TAKE_BACKxLEFTBYTES),
                          COREHALFWORD (xadd (getFIXED (m_TAKE_BACKxCUR), 4))),
                      1));
                  putFIXED (m_TAKE_BACKxRET_RECS, numberRHS);
                }
              // IF RET_RECS > DIF_RECS THEN (425)
              if (1
                  & (xGT (getFIXED (m_TAKE_BACKxRET_RECS),
                          getFIXED (m_TAKE_BACKxDIF_RECS))))
                // RET_RECS=DIF_RECS; (426)
                {
                  int32_t numberRHS
                      = (int32_t)(getFIXED (m_TAKE_BACKxDIF_RECS));
                  putFIXED (m_TAKE_BACKxRET_RECS, numberRHS);
                }
              // PREV_FREEBYTES=FREEBYTES; (427)
              {
                int32_t numberRHS = (int32_t)(getFIXED (mFREEBYTES));
                putFIXED (m_TAKE_BACKxPREV_FREEBYTES, numberRHS);
              }
              // CALL _RETURN_UNUSED(CUR,RET_RECS ); (428)
              {
                putFIXED (m_RETURN_UNUSEDxDOPE, getFIXED (m_TAKE_BACKxCUR));
                putFIXED (m_RETURN_UNUSEDxNRECS,
                          getFIXED (m_TAKE_BACKxRET_RECS));
                _RETURN_UNUSED (0);
              }
              // LEFTBYTES=LEFTBYTES-(FREEBYTES-PREV_FREEBYTES); (429)
              {
                int32_t numberRHS = (int32_t)(xsubtract (
                    getFIXED (m_TAKE_BACKxLEFTBYTES),
                    xsubtract (getFIXED (mFREEBYTES),
                               getFIXED (m_TAKE_BACKxPREV_FREEBYTES))));
                putFIXED (m_TAKE_BACKxLEFTBYTES, numberRHS);
              }
            es1s1s1:;
            } // End of DO block
        es1s1:;
        } // End of DO block
      // CUR=_DOPE_NEXT(CUR); (430)
      {
        int32_t numberRHS
            = (int32_t)(COREWORD (xadd (getFIXED (m_TAKE_BACKxCUR), 16)));
        putFIXED (m_TAKE_BACKxCUR, numberRHS);
      }
    } // End of DO WHILE block
  // FREEPRINT=PREV_FREEPRINT; (431)
  {
    descriptor_t *bitRHS = getBIT (1, m_TAKE_BACKxPREV_FREEPRINT);
    putBIT (1, mFREEPRINT, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
