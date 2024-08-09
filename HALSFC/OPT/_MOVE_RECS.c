/*
  File _MOVE_RECS.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
_MOVE_RECS (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "_MOVE_RECS");
  // CURDOPE=DOPE; (515)
  {
    int32_t numberRHS = (int32_t)(getFIXED (m_MOVE_RECSxDOPE));
    putFIXED (m_MOVE_RECSxCURDOPE, numberRHS);
  }
  // NBYTES=0; (516)
  {
    int32_t numberRHS = (int32_t)(0);
    putFIXED (m_MOVE_RECSxNBYTES, numberRHS);
  }
  // IF FIRSTBLOCK ~= 0 THEN (517)
  if (1 & (xNEQ (getFIXED (mFIRSTBLOCK), 0)))
    // IF COREWORD ( FIRSTBLOCK ) = 0 THEN (518)
    if (1 & (xEQ (COREWORD (getFIXED (mFIRSTBLOCK)), 0)))
      // IF COREWORD(FIRSTBLOCK-4) >= BYTES_TO_MOVE_BY THEN (519)
      if (1
          & (xGE (COREWORD (xsubtract (getFIXED (mFIRSTBLOCK), 4)),
                  getFIXED (m_MOVE_RECSxBYTES_TO_MOVE_BY))))
        // DO; (520)
        {
        rs1:;
          // DO UNTIL CURDOPE=0; (521)
          do
            {
              // SOURCE=_DOPE_POINTER(CURDOPE); (522)
              {
                int32_t numberRHS
                    = (int32_t)(COREWORD (getFIXED (m_MOVE_RECSxCURDOPE)));
                putFIXED (m_MOVE_RECSxSOURCE, numberRHS);
              }
              // NBYTES=NBYTES+ _RECORD#BYTES(CURDOPE); (523)
              {
                int32_t numberRHS = (int32_t)(xadd (
                    getFIXED (m_MOVE_RECSxNBYTES),
                    (putFIXED (
                         m_SPACE_ROUNDxBYTES,
                         xmultiply (COREWORD (xadd (
                                        getFIXED (m_MOVE_RECSxCURDOPE), 8)),
                                    COREHALFWORD (xadd (
                                        getFIXED (m_MOVE_RECSxCURDOPE), 4)))),
                     _SPACE_ROUND (0))));
                putFIXED (m_MOVE_RECSxNBYTES, numberRHS);
              }
              // _DOPE_POINTER(CURDOPE)=_DOPE_POINTER(CURDOPE)-BYTES_TO_MOVE_BY;
              // (524)
              {
                int32_t numberRHS = (int32_t)(xsubtract (
                    COREWORD (getFIXED (m_MOVE_RECSxCURDOPE)),
                    getFIXED (m_MOVE_RECSxBYTES_TO_MOVE_BY)));
                COREWORD2 (getFIXED (m_MOVE_RECSxCURDOPE), numberRHS);
              }
              // CURDOPE=_DOPE_NEXT(CURDOPE); (525)
              {
                int32_t numberRHS = (int32_t)(COREWORD (
                    xadd (getFIXED (m_MOVE_RECSxCURDOPE), 16)));
                putFIXED (m_MOVE_RECSxCURDOPE, numberRHS);
              }
            }
          while (!(1
                   & (xEQ (getFIXED (m_MOVE_RECSxCURDOPE),
                           0)))); // End of DO UNTIL block
          // CALL _REDUCE_BLOCK(FIRSTBLOCK,BYTES_TO_MOVE_BY,_TRUE); (526)
          {
            putFIXED (m_REDUCE_BLOCKxBLOCK, getFIXED (mFIRSTBLOCK));
            putFIXED (m_REDUCE_BLOCKxREMBYTES,
                      getFIXED (m_MOVE_RECSxBYTES_TO_MOVE_BY));
            putBITp (1, m_REDUCE_BLOCKxTOP, fixedToBit (32, (int32_t)(1)));
            _REDUCE_BLOCK (0);
          }
          // CALL _MOVE_WORDS(SOURCE,SOURCE-BYTES_TO_MOVE_BY,NBYTES); (527)
          {
            putFIXED (m_MOVE_WORDSxSOURCE, getFIXED (m_MOVE_RECSxSOURCE));
            putFIXED (m_MOVE_WORDSxDEST,
                      xsubtract (getFIXED (m_MOVE_RECSxSOURCE),
                                 getFIXED (m_MOVE_RECSxBYTES_TO_MOVE_BY)));
            putFIXED (m_MOVE_WORDSxNUMBYTES, getFIXED (m_MOVE_RECSxNBYTES));
            _MOVE_WORDS (0);
          }
          // RETURN; (528)
          {
            reentryGuard = 0;
            return 0;
          }
        es1:;
        } // End of DO block
  // CALL _SPMANERR('IN MOVE_RECS,FIRSTBLOCK='||_RF(FIRSTBLOCK)||' SIZE= '||
  // _FREEBLOCK_SIZE(FIRSTBLOCK)); (529)
  {
    putCHARACTERp (
        m_SPMANERRxMSG,
        xsCAT (xsCAT (xsCAT (cToDescriptor (NULL, "IN MOVE_RECS,FIRSTBLOCK="),
                             fixedToCharacter (xmultiply (
                                 xNEQ (getFIXED (mFIRSTBLOCK), 0),
                                 xsubtract (xsubtract (getFIXED (mFIRSTBLOCK),
                                                       FREEBASE ()),
                                            3)))),
                      cToDescriptor (NULL, " SIZE= ")),
               fixedToCharacter (
                   COREWORD (xsubtract (getFIXED (mFIRSTBLOCK), 4)))));
    _SPMANERR (0);
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
