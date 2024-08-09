/*
  File _RETURN_TO_FREESTRING.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

int32_t
_RETURN_TO_FREESTRING (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_RETURN_TO_FREESTRING");
  // IF NBYTES=0 THEN (265)
  if (1 & (xEQ (getFIXED (m_RETURN_TO_FREESTRINGxNBYTES), 0)))
    // RETURN; (266)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF NBYTES > FREEBYTES THEN (267)
  if (1
      & (xGT (getFIXED (m_RETURN_TO_FREESTRINGxNBYTES),
              getFIXED (mFREEBYTES))))
    // DO; (268)
    {
    rs1:;
      // CALL _SPMANERR('IN RETURN_TO_FREESTRING, NBYTES='||NBYTES||',
      // FREEBYTES='||FREEBYTES); (269)
      {
        putCHARACTERp (
            m_SPMANERRxMSG,
            xsCAT (xsCAT (xsCAT (cToDescriptor (
                                     NULL, "IN RETURN_TO_FREESTRING, NBYTES="),
                                 fixedToCharacter (getFIXED (
                                     m_RETURN_TO_FREESTRINGxNBYTES))),
                          cToDescriptor (NULL, ", FREEBYTES=")),
                   fixedToCharacter (getFIXED (mFREEBYTES))));
        _SPMANERR (0);
      }
    es1:;
    } // End of DO block
  // ELSE (270)
  else
    // DO; (271)
    {
    rs2:;
      // CALL _SQUASH_RECORDS; (272)
      _SQUASH_RECORDS (0);
      // IF FIRSTBLOCK <= 0 THEN (273)
      if (1 & (xLE (getFIXED (mFIRSTBLOCK), 0)))
        // DO; (274)
        {
        rs2s1:;
          // CALL _SPMANERR('IN RETURN_TO_FREESTRING,
          // FIRSTBLOCK='||FIRSTBLOCK); (275)
          {
            putCHARACTERp (
                m_SPMANERRxMSG,
                xsCAT (cToDescriptor (NULL,
                                      "IN RETURN_TO_FREESTRING, FIRSTBLOCK="),
                       fixedToCharacter (getFIXED (mFIRSTBLOCK))));
            _SPMANERR (0);
          }
        es2s1:;
        } // End of DO block
      // CALL _REDUCE_BLOCK(FIRSTBLOCK,NBYTES,_FALSE); (276)
      {
        putFIXED (m_REDUCE_BLOCKxBLOCK, getFIXED (mFIRSTBLOCK));
        putFIXED (m_REDUCE_BLOCKxREMBYTES,
                  getFIXED (m_RETURN_TO_FREESTRINGxNBYTES));
        putBITp (1, m_REDUCE_BLOCKxTOP, fixedToBit (32, (int32_t)(0)));
        _REDUCE_BLOCK (0);
      }
      // _OLDFREELIMIT,FREELIMIT=FREELIMIT+NBYTES; (277)
      {
        int32_t numberRHS = (int32_t)(xadd (
            FREELIMIT (), getFIXED (m_RETURN_TO_FREESTRINGxNBYTES)));
        putFIXED (m_OLDFREELIMIT, numberRHS);
        FREELIMIT2 (numberRHS);
      }
      // FREEBYTES=FREEBYTES-NBYTES; (278)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            getFIXED (mFREEBYTES), getFIXED (m_RETURN_TO_FREESTRINGxNBYTES)));
        putFIXED (mFREEBYTES, numberRHS);
      }
    es2:;
    } // End of DO block
  {
    reentryGuard = 0;
    return 0;
  }
}
