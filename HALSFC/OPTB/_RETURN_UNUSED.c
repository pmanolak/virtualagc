/*
  File _RETURN_UNUSED.c generated by XCOM-I, 2024-08-09 12:41:07.
*/

#include "runtimeC.h"

int32_t
_RETURN_UNUSED (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_RETURN_UNUSED");
  // DIF=_DOPE_ALLOC(DOPE)-_DOPE_USED(DOPE); (308)
  {
    int32_t numberRHS = (int32_t)(xsubtract (
        COREWORD (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 8)),
        COREWORD (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 12))));
    putFIXED (m_RETURN_UNUSEDxDIF, numberRHS);
  }
  // IF NRECS=0 THEN (309)
  if (1 & (xEQ (getFIXED (m_RETURN_UNUSEDxNRECS), 0)))
    // DO; (310)
    {
    rs1:;
      // NRECS=DIF; (311)
      {
        int32_t numberRHS = (int32_t)(getFIXED (m_RETURN_UNUSEDxDIF));
        putFIXED (m_RETURN_UNUSEDxNRECS, numberRHS);
      }
      // _NUM_TIMES_ZEROED(DOPE)=0; (312)
      {
        int32_t numberRHS = (int32_t)(0);
        COREHALFWORD2 (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 24), numberRHS);
      }
      // IF NRECS=0 THEN (313)
      if (1 & (xEQ (getFIXED (m_RETURN_UNUSEDxNRECS), 0)))
        // RETURN; (314)
        {
          reentryGuard = 0;
          return 0;
        }
    es1:;
    } // End of DO block
  // ELSE (315)
  else
    // IF NRECS=DIF THEN (316)
    if (1
        & (xEQ (getFIXED (m_RETURN_UNUSEDxNRECS),
                getFIXED (m_RETURN_UNUSEDxDIF))))
      // DO; (317)
      {
      rs2:;
        // _NUM_TIMES_ZEROED(DOPE)=_NUM_TIMES_ZEROED(DOPE)+1; (318)
        {
          int32_t numberRHS = (int32_t)(xadd (
              COREHALFWORD (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 24)), 1));
          COREHALFWORD2 (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 24),
                         numberRHS);
        }
        // IF _NUM_TIMES_ZEROED(DOPE)>_MAX_ZEROED THEN (319)
        if (1
            & (xGT (COREHALFWORD (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 24)),
                    2)))
          // DO; (320)
          {
          rs2s1:;
            // OUTPUT='BI010 SEVERITY 3  SPACE MANAGEMENT ' || 'YOYOING -- TRY
            // LARGER REGION.'; (321)
            {
              descriptor_t *stringRHS;
              stringRHS
                  = cToDescriptor (NULL, "BI010 SEVERITY 3  SPACE MANAGEMENT "
                                         "YOYOING -- TRY LARGER REGION.");
              OUTPUT (0, stringRHS);
              stringRHS->inUse = 0;
            }
            // CALL EXIT; (322)
            EXIT ();
          es2s1:;
          } // End of DO block
      es2:;
      } // End of DO block
    // ELSE (323)
    else
      // IF NRECS > DIF THEN (324)
      if (1
          & (xGT (getFIXED (m_RETURN_UNUSEDxNRECS),
                  getFIXED (m_RETURN_UNUSEDxDIF))))
        // DO; (325)
        {
        rs3:;
          // DO; (326)
          {
          rs3s1:;
            // CALL _SPMANERR('TRIED TO RETURN '||NRECS||' BUT ONLY
            // '||DIF||'ARE UNUSED IN '||DOPE); (327)
            {
              putCHARACTERp (
                  m_SPMANERRxMSG,
                  xsCAT (
                      xsCAT (
                          xsCAT (xsCAT (xsCAT (cToDescriptor (
                                                   NULL, "TRIED TO RETURN "),
                                               fixedToCharacter (getFIXED (
                                                   m_RETURN_UNUSEDxNRECS))),
                                        cToDescriptor (NULL, " BUT ONLY ")),
                                 fixedToCharacter (
                                     getFIXED (m_RETURN_UNUSEDxDIF))),
                          cToDescriptor (NULL, "ARE UNUSED IN ")),
                      fixedToCharacter (getFIXED (m_RETURN_UNUSEDxDOPE))));
              _SPMANERR (0);
            }
          es3s1:;
          } // End of DO block
          // NRECS=DIF; (328)
          {
            int32_t numberRHS = (int32_t)(getFIXED (m_RETURN_UNUSEDxDIF));
            putFIXED (m_RETURN_UNUSEDxNRECS, numberRHS);
          }
        es3:;
        } // End of DO block
  // IF DIF=_DOPE_ALLOC(DOPE) THEN (329)
  if (1
      & (xEQ (getFIXED (m_RETURN_UNUSEDxDIF),
              COREWORD (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 8)))))
    // CALL _RECORD_FREE(DOPE _IFA(NAME)); (330)
    {
      putFIXED (m_RECORD_FREExDOPE, getFIXED (m_RETURN_UNUSEDxDOPE));
      _RECORD_FREE (0);
    }
  // ELSE (331)
  else
    // DO; (332)
    {
    rs4:;
      // TOTAL_RDESC=TOTAL_RDESC-NRECS*_DOPE_#DESCRIPTORS(DOPE); (333)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            getFIXED (mTOTAL_RDESC),
            xmultiply (
                getFIXED (m_RETURN_UNUSEDxNRECS),
                COREHALFWORD (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 6)))));
        putFIXED (mTOTAL_RDESC, numberRHS);
      }
      // OLDNBYTES=_RECORD#BYTES(DOPE); (334)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (
                m_SPACE_ROUNDxBYTES,
                xmultiply (
                    COREWORD (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 8)),
                    COREHALFWORD (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 4)))),
            _SPACE_ROUND (0)));
        putFIXED (m_RETURN_UNUSEDxOLDNBYTES, numberRHS);
      }
      // _DOPE_ALLOC(DOPE)=_DOPE_ALLOC(DOPE)-NRECS; (335)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            COREWORD (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 8)),
            getFIXED (m_RETURN_UNUSEDxNRECS)));
        COREWORD2 (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 8), numberRHS);
      }
      // NEWNBYTES=_RECORD#BYTES(DOPE); (336)
      {
        int32_t numberRHS = (int32_t)((
            putFIXED (
                m_SPACE_ROUNDxBYTES,
                xmultiply (
                    COREWORD (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 8)),
                    COREHALFWORD (xadd (getFIXED (m_RETURN_UNUSEDxDOPE), 4)))),
            _SPACE_ROUND (0)));
        putFIXED (m_RETURN_UNUSEDxNEWNBYTES, numberRHS);
      }
      // DIF=OLDNBYTES-NEWNBYTES; (337)
      {
        int32_t numberRHS
            = (int32_t)(xsubtract (getFIXED (m_RETURN_UNUSEDxOLDNBYTES),
                                   getFIXED (m_RETURN_UNUSEDxNEWNBYTES)));
        putFIXED (m_RETURN_UNUSEDxDIF, numberRHS);
      }
      // IF DIF=0 THEN (338)
      if (1 & (xEQ (getFIXED (m_RETURN_UNUSEDxDIF), 0)))
        // RETURN; (339)
        {
          reentryGuard = 0;
          return 0;
        }
      // NEWBLOCK=_DOPE_POINTER(DOPE)+OLDNBYTES-4; (340)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            xadd (COREWORD (getFIXED (m_RETURN_UNUSEDxDOPE)),
                  getFIXED (m_RETURN_UNUSEDxOLDNBYTES)),
            4));
        putFIXED (m_RETURN_UNUSEDxNEWBLOCK, numberRHS);
      }
      // _FREEBLOCK_NEXT(NEWBLOCK)=0; (341)
      {
        int32_t numberRHS = (int32_t)(0);
        COREWORD2 (getFIXED (m_RETURN_UNUSEDxNEWBLOCK), numberRHS);
      }
      // _FREEBLOCK_SIZE(NEWBLOCK)=DIF; (342)
      {
        int32_t numberRHS = (int32_t)(getFIXED (m_RETURN_UNUSEDxDIF));
        COREWORD2 (xsubtract (getFIXED (m_RETURN_UNUSEDxNEWBLOCK), 4),
                   numberRHS);
      }
      // FREEBYTES=FREEBYTES+DIF; (343)
      {
        int32_t numberRHS = (int32_t)(xadd (getFIXED (mFREEBYTES),
                                            getFIXED (m_RETURN_UNUSEDxDIF)));
        putFIXED (mFREEBYTES, numberRHS);
      }
      // RECBYTES=RECBYTES-DIF; (344)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            getFIXED (mRECBYTES), getFIXED (m_RETURN_UNUSEDxDIF)));
        putFIXED (mRECBYTES, numberRHS);
      }
      // CALL _ATTACH_BLOCK(NEWBLOCK); (345)
      {
        putFIXED (m_ATTACH_BLOCKxBLOCK, getFIXED (m_RETURN_UNUSEDxNEWBLOCK));
        _ATTACH_BLOCK (0);
      }
    es4:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
