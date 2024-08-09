/*
  File _RETURN_TO_FREESTRING.c generated by XCOM-I, 2024-08-09 12:41:32.
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
  // IF NBYTES=0 THEN (282)
  if (1 & (xEQ (getFIXED (m_RETURN_TO_FREESTRINGxNBYTES), 0)))
    // RETURN; (283)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF NBYTES > FREEBYTES THEN (284)
  if (1
      & (xGT (getFIXED (m_RETURN_TO_FREESTRINGxNBYTES),
              getFIXED (mFREEBYTES))))
    // DO; (285)
    {
    rs1:;
      // CALL _SPMANERR('IN RETURN_TO_FREESTRING, NBYTES='||NBYTES||',
      // FREEBYTES='||FREEBYTES); (286)
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
  // ELSE (287)
  else
    // DO; (288)
    {
    rs2:;
      // CALL _SQUASH_RECORDS; (289)
      _SQUASH_RECORDS (0);
      // IF FIRSTBLOCK <= 0 THEN (290)
      if (1 & (xLE (getFIXED (mFIRSTBLOCK), 0)))
        // DO; (291)
        {
        rs2s1:;
          // CALL _SPMANERR('IN RETURN_TO_FREESTRING,
          // FIRSTBLOCK='||FIRSTBLOCK); (292)
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
      // CALL _REDUCE_BLOCK(FIRSTBLOCK,NBYTES,_FALSE); (293)
      {
        putFIXED (m_REDUCE_BLOCKxBLOCK, getFIXED (mFIRSTBLOCK));
        putFIXED (m_REDUCE_BLOCKxREMBYTES,
                  getFIXED (m_RETURN_TO_FREESTRINGxNBYTES));
        putBITp (1, m_REDUCE_BLOCKxTOP, fixedToBit (32, (int32_t)(0)));
        _REDUCE_BLOCK (0);
      }
      // _OLDFREELIMIT,FREELIMIT=FREELIMIT+NBYTES; (294)
      {
        int32_t numberRHS = (int32_t)(xadd (
            FREELIMIT (), getFIXED (m_RETURN_TO_FREESTRINGxNBYTES)));
        putFIXED (m_OLDFREELIMIT, numberRHS);
        FREELIMIT2 (numberRHS);
      }
      // FREEBYTES=FREEBYTES-NBYTES; (295)
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
