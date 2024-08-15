/*
  File GENERATExCHECK_VAC.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

int32_t
GENERATExCHECK_VAC (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExCHECK_VAC");
  // IF FORM(OP) = WORK THEN (5319)
  if (1
      & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExCHECK_VACxOP)) + 32
                            + 2 * (0)),
              BYTE0 (mWORK))))
    // DO; (5320)
    {
    rs1:;
      // IF R = 0 THEN (5321)
      if (1 & (xEQ (COREHALFWORD (mGENERATExCHECK_VACxR), 0)))
        // REG(OP) = FINDAC(INDEX_REG); (5322)
        {
          descriptor_t *bitRHS = (putBITp (16, mGENERATExFINDACxRCLASS,
                                           fixedToBit (32, (int32_t)(4))),
                                  GENERATExFINDAC (0));
          putBIT (16,
                  getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExCHECK_VACxOP)) + 46
                      + 2 * (0),
                  bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (5323)
      else
        // DO; (5324)
        {
        rs1s1:;
          // CALL CHECKPOINT_REG(R); (5325)
          {
            putBITp (16, mGENERATExCHECKPOINT_REGxR,
                     getBIT (16, mGENERATExCHECK_VACxR));
            GENERATExCHECKPOINT_REG (0);
          }
          // REG(OP) = R; (5326)
          {
            descriptor_t *bitRHS = getBIT (16, mGENERATExCHECK_VACxR);
            putBIT (16,
                    getFIXED (mIND_STACK)
                        + 73 * (COREHALFWORD (mGENERATExCHECK_VACxOP)) + 46
                        + 2 * (0),
                    bitRHS);
            bitRHS->inUse = 0;
          }
        es1s1:;
        } // End of DO block
      // CALL EMIT_BY_MODE(LOAD, REG(OP), OP, TYPE(OP)); (5327)
      {
        putBITp (16, mGENERATExEMIT_BY_MODExOP, getBIT (16, mGENERATExLOAD));
        putBITp (16, mGENERATExEMIT_BY_MODExR,
                 getBIT (16, getFIXED (mIND_STACK)
                                 + 73 * (COREHALFWORD (mGENERATExCHECK_VACxOP))
                                 + 46 + 2 * (0)));
        putBITp (16, mGENERATExEMIT_BY_MODExOP2,
                 getBIT (16, mGENERATExCHECK_VACxOP));
        putBITp (16, mGENERATExEMIT_BY_MODExMODE,
                 getBIT (16, getFIXED (mIND_STACK)
                                 + 73 * (COREHALFWORD (mGENERATExCHECK_VACxOP))
                                 + 50 + 2 * (0)));
        GENERATExEMIT_BY_MODE (0);
      }
      // USAGE(REG(OP)) = 2; (5328)
      {
        int32_t numberRHS = (int32_t)(2);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16,
                mUSAGE
                    + 2
                          * (COREHALFWORD (
                              getFIXED (mIND_STACK)
                              + 73 * (COREHALFWORD (mGENERATExCHECK_VACxOP))
                              + 46 + 2 * (0))),
                bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL DROPSAVE(OP); (5329)
      {
        putBITp (16, mGENERATExDROPSAVExENTRY,
                 getBIT (16, mGENERATExCHECK_VACxOP));
        GENERATExDROPSAVE (0);
      }
      // FORM(OP) = VAC; (5330)
      {
        descriptor_t *bitRHS = getBIT (8, mVAC);
        putBIT (16,
                getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExCHECK_VACxOP)) + 32
                    + 2 * (0),
                bitRHS);
        bitRHS->inUse = 0;
      }
    es1:;
    } // End of DO block
  // R = 0; (5331)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExCHECK_VACxR, bitRHS);
    bitRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}