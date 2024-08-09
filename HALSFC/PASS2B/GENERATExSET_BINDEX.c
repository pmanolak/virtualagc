/*
  File GENERATExSET_BINDEX.c generated by XCOM-I, 2024-08-09 12:41:32.
*/

#include "runtimeC.h"

descriptor_t *
GENERATExSET_BINDEX (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExSET_BINDEX");
  // IF FORM(OP) = LIT THEN (8220)
  if (1
      & (xEQ (COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP))
                            + 32 + 2 * (0)),
              BYTE0 (mLIT))))
    // DO; (8221)
    {
    rs1:;
      // VAL(OP) = SZ - VAL(OP); (8222)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            getFIXED (mGENERATExSET_BINDEXxSZ),
            getFIXED (getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP)) + 12
                      + 4 * (0))));
        putFIXED (getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP)) + 12
                      + 4 * (0),
                  numberRHS);
      }
      // IF VAL(OP) < 0 THEN (8223)
      if (1
          & (xLT (getFIXED (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP))
                            + 12 + 4 * (0)),
                  0)))
        // CALL ERRORS(CLASS_SR,100); (8224)
        {
          putBITp (16, mERRORSxCLASS, getBIT (8, mCLASS_SR));
          putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(100)));
          ERRORS (0);
        }
      // IF OLDOP > 0 THEN (8225)
      if (1 & (xGT (COREHALFWORD (mGENERATExSET_BINDEXxOLDOP), 0)))
        // DO CASE FORM(OLDOP) ~= LIT; (8226)
        {
        rs1s1:
          switch (xNEQ (
              COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOLDOP))
                            + 32 + 2 * (0)),
              BYTE0 (mLIT)))
            {
            case 0:
              // DO; (8228)
              {
              rs1s1s1:;
                // VAL(OP) = VAL(OP) + VAL(OLDOP); (8228)
                {
                  int32_t numberRHS = (int32_t)(xadd (
                      getFIXED (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP))
                                + 12 + 4 * (0)),
                      getFIXED (
                          getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOLDOP))
                          + 12 + 4 * (0))));
                  putFIXED (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP))
                                + 12 + 4 * (0),
                            numberRHS);
                }
                // CALL RETURN_STACK_ENTRY(OLDOP); (8229)
                {
                  putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                           getBIT (16, mGENERATExSET_BINDEXxOLDOP));
                  GENERATExRETURN_STACK_ENTRY (0);
                }
              es1s1s1:;
              } // End of DO block
              break;
            case 1:
              // DO; (8231)
              {
              rs1s1s2:;
                // CONST(OLDOP) = CONST(OLDOP) + VAL(OP); (8231)
                {
                  int32_t numberRHS = (int32_t)(xadd (
                      getFIXED (
                          getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOLDOP))
                          + 0 + 4 * (0)),
                      getFIXED (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP))
                                + 12 + 4 * (0))));
                  putFIXED (
                      getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOLDOP))
                          + 0 + 4 * (0),
                      numberRHS);
                }
                // CALL RETURN_STACK_ENTRY(OP); (8232)
                {
                  putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                           getBIT (16, mGENERATExSET_BINDEXxOP));
                  GENERATExRETURN_STACK_ENTRY (0);
                }
                // OP = OLDOP; (8233)
                {
                  descriptor_t *bitRHS
                      = getBIT (16, mGENERATExSET_BINDEXxOLDOP);
                  putBIT (16, mGENERATExSET_BINDEXxOP, bitRHS);
                  bitRHS->inUse = 0;
                }
              es1s1s2:;
              } // End of DO block
              break;
            }
        } // End of DO CASE block
    es1:;
    } // End of DO block
  // ELSE (8234)
  else
    // DO; (8235)
    {
    rs2:;
      // SZ = SZ - CONST(OP); (8236)
      {
        int32_t numberRHS = (int32_t)(xsubtract (
            getFIXED (mGENERATExSET_BINDEXxSZ),
            getFIXED (getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP)) + 0
                      + 4 * (0))));
        putFIXED (mGENERATExSET_BINDEXxSZ, numberRHS);
      }
      // CONST(OP) = 0; (8237)
      {
        int32_t numberRHS = (int32_t)(0);
        putFIXED (getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP)) + 0
                      + 4 * (0),
                  numberRHS);
      }
      // TO_BE_MODIFIED = TRUE; (8238)
      {
        int32_t numberRHS = (int32_t)(1);
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (1, mGENERATExTO_BE_MODIFIED, bitRHS);
        bitRHS->inUse = 0;
      }
      // CALL FORCE_ACCUMULATOR(OP, INTEGER, INDEX_REG); (8239)
      {
        putBITp (16, mGENERATExFORCE_ACCUMULATORxOP,
                 getBIT (16, mGENERATExSET_BINDEXxOP));
        putBITp (16, mGENERATExFORCE_ACCUMULATORxOPTYPE, getBIT (8, mINTEGER));
        putBITp (16, mGENERATExFORCE_ACCUMULATORxACCLASS,
                 fixedToBit (32, (int32_t)(4)));
        GENERATExFORCE_ACCUMULATOR (0);
      }
      // CALL EMITRR(LCR, REG(OP), REG(OP)); (8240)
      {
        putBITp (16, mGENERATExEMITRRxINST, getBIT (8, mLCR));
        putBITp (
            16, mGENERATExEMITRRxREG1,
            getBIT (16, getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP))
                            + 46 + 2 * (0)));
        putBITp (
            16, mGENERATExEMITRRxREG2,
            getBIT (16, getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP))
                            + 46 + 2 * (0)));
        GENERATExEMITRR (0);
      }
      // CONST(OP) = SZ; (8241)
      {
        int32_t numberRHS = (int32_t)(getFIXED (mGENERATExSET_BINDEXxSZ));
        putFIXED (getFIXED (mIND_STACK)
                      + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP)) + 0
                      + 4 * (0),
                  numberRHS);
      }
      // CALL UNRECOGNIZABLE(REG(OP)); (8242)
      {
        putBITp (
            16, mGENERATExUNRECOGNIZABLExR,
            getBIT (16, getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP))
                            + 46 + 2 * (0)));
        GENERATExUNRECOGNIZABLE (0);
      }
      // IF OLDOP > 0 THEN (8243)
      if (1 & (xGT (COREHALFWORD (mGENERATExSET_BINDEXxOLDOP), 0)))
        // DO CASE FORM(OLDOP) ~= LIT; (8244)
        {
        rs2s1:
          switch (xNEQ (
              COREHALFWORD (getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOLDOP))
                            + 32 + 2 * (0)),
              BYTE0 (mLIT)))
            {
            case 0:
              // DO; (8246)
              {
              rs2s1s1:;
                // CONST(OP) = CONST(OP) + VAL(OLDOP); (8246)
                {
                  int32_t numberRHS = (int32_t)(xadd (
                      getFIXED (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP))
                                + 0 + 4 * (0)),
                      getFIXED (
                          getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOLDOP))
                          + 12 + 4 * (0))));
                  putFIXED (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP))
                                + 0 + 4 * (0),
                            numberRHS);
                }
                // CALL RETURN_STACK_ENTRY(OLDOP); (8247)
                {
                  putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                           getBIT (16, mGENERATExSET_BINDEXxOLDOP));
                  GENERATExRETURN_STACK_ENTRY (0);
                }
              es2s1s1:;
              } // End of DO block
              break;
            case 1:
              // DO; (8249)
              {
              rs2s1s2:;
                // CONST(OP) = CONST(OP) + CONST(OLDOP); (8249)
                {
                  int32_t numberRHS = (int32_t)(xadd (
                      getFIXED (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP))
                                + 0 + 4 * (0)),
                      getFIXED (
                          getFIXED (mIND_STACK)
                          + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOLDOP))
                          + 0 + 4 * (0))));
                  putFIXED (getFIXED (mIND_STACK)
                                + 73 * (COREHALFWORD (mGENERATExSET_BINDEXxOP))
                                + 0 + 4 * (0),
                            numberRHS);
                }
                // CALL ARITH_BY_MODE(SUM, OP, OLDOP, TYPE(OLDOP)); (8250)
                {
                  putBITp (16, mGENERATExARITH_BY_MODExOP,
                           getBIT (8, mGENERATExSUM));
                  putBITp (16, mGENERATExARITH_BY_MODExOP1,
                           getBIT (16, mGENERATExSET_BINDEXxOP));
                  putBITp (16, mGENERATExARITH_BY_MODExOP2,
                           getBIT (16, mGENERATExSET_BINDEXxOLDOP));
                  putBITp (
                      16, mGENERATExARITH_BY_MODExOPTYPE,
                      getBIT (16, getFIXED (mIND_STACK)
                                      + 73
                                            * (COREHALFWORD (
                                                mGENERATExSET_BINDEXxOLDOP))
                                      + 50 + 2 * (0)));
                  GENERATExARITH_BY_MODE (0);
                }
                // CALL RETURN_STACK_ENTRY(OLDOP); (8251)
                {
                  putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
                           getBIT (16, mGENERATExSET_BINDEXxOLDOP));
                  GENERATExRETURN_STACK_ENTRY (0);
                }
              es2s1s2:;
              } // End of DO block
              break;
            }
        } // End of DO CASE block
    es2:;
    } // End of DO block
  // CALL INCORPORATE(OP); (8252)
  {
    putBITp (16, mGENERATExINCORPORATExOP,
             getBIT (16, mGENERATExSET_BINDEXxOP));
    GENERATExINCORPORATE (0);
  }
  // OLDOP = 0; (8253)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGENERATExSET_BINDEXxOLDOP, bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN OP; (8254)
  {
    reentryGuard = 0;
    return getBIT (16, mGENERATExSET_BINDEXxOP);
  }
}
