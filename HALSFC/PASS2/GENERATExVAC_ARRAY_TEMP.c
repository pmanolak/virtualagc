/*
  File GENERATExVAC_ARRAY_TEMP.c generated by XCOM-I, 2024-08-09 12:39:31.
*/

#include "runtimeC.h"

int32_t
GENERATExVAC_ARRAY_TEMP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GENERATExVAC_ARRAY_TEMP");
  // PTR = GET_ARRAY_TEMP(OP, TYPE(OP)); (7883)
  {
    descriptor_t *bitRHS
        = (putBITp (16, mGENERATExGET_ARRAY_TEMPxOP,
                    getBIT (16, mGENERATExVAC_ARRAY_TEMPxOP)),
           putBITp (
               16, mGENERATExGET_ARRAY_TEMPxATYPE,
               getBIT (16,
                       getFIXED (mIND_STACK)
                           + 73 * (COREHALFWORD (mGENERATExVAC_ARRAY_TEMPxOP))
                           + 50 + 2 * (0))),
           GENERATExGET_ARRAY_TEMP (0));
    putBIT (16, mGENERATExVAC_ARRAY_TEMPxPTR, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO CASE PACKTYPE(TYPE(OP)); (7884)
  {
  rs1:
    switch (
        BYTE0 (mPACKTYPE
               + 1
                     * COREHALFWORD (
                         getFIXED (mIND_STACK)
                         + 73 * (COREHALFWORD (mGENERATExVAC_ARRAY_TEMPxOP))
                         + 50 + 2 * (0))))
      {
      case 0:
        // DO; (7886)
        {
        rs1s1:;
          // IF VDLP_ACTIVE THEN (7886)
          if (1 & (bitToFixed (getBIT (1, mVDLP_ACTIVE))))
            // GO TO INTSCA_TEMP; (7887)
            goto INTSCA_TEMP;
          // TEMPSPACE = ROW(OP) * COLUMN(OP); (7888)
          {
            int32_t numberRHS = (int32_t)(xmultiply (
                COREHALFWORD (
                    getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExVAC_ARRAY_TEMPxOP)) + 48
                    + 2 * (0)),
                COREHALFWORD (
                    getFIXED (mIND_STACK)
                    + 73 * (COREHALFWORD (mGENERATExVAC_ARRAY_TEMPxOP)) + 24
                    + 2 * (0))));
            putFIXED (mTEMPSPACE, numberRHS);
          }
          // CALL VECMAT_ASSIGN(PTR, OP); (7889)
          {
            putBITp (16, mGENERATExVECMAT_ASSIGNxOP0,
                     getBIT (16, mGENERATExVAC_ARRAY_TEMPxPTR));
            putBITp (16, mGENERATExVECMAT_ASSIGNxOP1,
                     getBIT (16, mGENERATExVAC_ARRAY_TEMPxOP));
            GENERATExVECMAT_ASSIGN (0);
          }
        es1s1:;
        } // End of DO block
        break;
      case 1:
        // GO TO INTSCA_TEMP; (7891)
        goto INTSCA_TEMP;
        break;
      case 2:
        // CALL CHAR_CALL(XXASN, PTR, OP, 0); (7892)
        {
          putBITp (16, mGENERATExCHAR_CALLxOPCODE, getBIT (8, mXXASN));
          putBITp (16, mGENERATExCHAR_CALLxOP0,
                   getBIT (16, mGENERATExVAC_ARRAY_TEMPxPTR));
          putBITp (16, mGENERATExCHAR_CALLxOP1,
                   getBIT (16, mGENERATExVAC_ARRAY_TEMPxOP));
          putBITp (16, mGENERATExCHAR_CALLxOP2, fixedToBit (32, (int32_t)(0)));
          GENERATExCHAR_CALL (0);
        }
        break;
      case 3:
        // DO; (7893)
        {
        rs1s2:;
        // INTSCA_TEMP: (7893)
        INTSCA_TEMP:
          // CALL EMIT_BY_MODE(STORE, REG(OP), PTR, TYPE(OP)); (7894)
          {
            putBITp (16, mGENERATExEMIT_BY_MODExOP,
                     getBIT (16, mGENERATExSTORE));
            putBITp (
                16, mGENERATExEMIT_BY_MODExR,
                getBIT (16,
                        getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExVAC_ARRAY_TEMPxOP))
                            + 46 + 2 * (0)));
            putBITp (16, mGENERATExEMIT_BY_MODExOP2,
                     getBIT (16, mGENERATExVAC_ARRAY_TEMPxPTR));
            putBITp (
                16, mGENERATExEMIT_BY_MODExMODE,
                getBIT (16,
                        getFIXED (mIND_STACK)
                            + 73 * (COREHALFWORD (mGENERATExVAC_ARRAY_TEMPxOP))
                            + 50 + 2 * (0)));
            GENERATExEMIT_BY_MODE (0);
          }
          // CALL DROP_REG(OP); (7895)
          {
            putBITp (16, mGENERATExDROP_REGxOP,
                     getBIT (16, mGENERATExVAC_ARRAY_TEMPxOP));
            GENERATExDROP_REG (0);
          }
        es1s2:;
        } // End of DO block
        break;
      case 4:
          // ; (7897)
          ;
        break;
      }
  } // End of DO CASE block
  // CALL DROP_INX(PTR); (7897)
  {
    putBITp (16, mGENERATExDROP_INXxOP,
             getBIT (16, mGENERATExVAC_ARRAY_TEMPxPTR));
    GENERATExDROP_INX (0);
  }
  // CALL DROPSAVE(OP); (7898)
  {
    putBITp (16, mGENERATExDROPSAVExENTRY,
             getBIT (16, mGENERATExVAC_ARRAY_TEMPxOP));
    GENERATExDROPSAVE (0);
  }
  // CALL RETURN_STACK_ENTRY(OP); (7899)
  {
    putBITp (16, mGENERATExRETURN_STACK_ENTRYxP,
             getBIT (16, mGENERATExVAC_ARRAY_TEMPxOP));
    GENERATExRETURN_STACK_ENTRY (0);
  }
  // RETURN PTR; (7900)
  {
    reentryGuard = 0;
    return COREHALFWORD (mGENERATExVAC_ARRAY_TEMPxPTR);
  }
}