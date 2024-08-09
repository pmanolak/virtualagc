/*
  File REINITIALIZE.c generated by XCOM-I, 2024-08-09 12:39:13.
*/

#include "runtimeC.h"

int32_t
REINITIALIZE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "REINITIALIZE");
  // BLOCK_PRIME = OFF; (1133)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mBLOCK_PRIME, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO FOR WORK = 1 TO RECORD_TOP(STACK_FRAME); (1134)
  {
    int32_t from32, to32, by32;
    from32 = 1;
    to32 = xsubtract (
        COREWORD (xadd (ADDR ("STACK_FRAME", 0x80000000, NULL, 0), 12)), 1);
    by32 = 1;
    for (putFIXED (mREINITIALIZExWORK, from32);
         getFIXED (mREINITIALIZExWORK) <= to32;
         putFIXED (mREINITIALIZExWORK, getFIXED (mREINITIALIZExWORK) + by32))
      {
        // MAX_CASE_LENGTH(WORK), FRAME_START(WORK) = 0; (1135)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mSTACK_FRAME)
                      + 32 * (getFIXED (mREINITIALIZExWORK)) + 0 + 2 * (0),
                  fixedToBit (16, numberRHS));
          putBIT (16,
                  getFIXED (mSTACK_FRAME)
                      + 32 * (getFIXED (mREINITIALIZExWORK)) + 4 + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        // FRAME_FLAGS(WORK) = FRAME_FLAGS(WORK) | PREV_BLOCK_FLAG; (1136)
        {
          int32_t numberRHS = (int32_t)(xOR (
              BYTE0 (getFIXED (mSTACK_FRAME)
                     + 32 * (getFIXED (mREINITIALIZExWORK)) + 31 + 1 * (0)),
              2));
          putBIT (8,
                  getFIXED (mSTACK_FRAME)
                      + 32 * (getFIXED (mREINITIALIZExWORK)) + 31 + 1 * (0),
                  fixedToBit (8, numberRHS));
        }
        // FRAME_UVCS(WORK) = 0; (1137)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mSTACK_FRAME)
                      + 32 * (getFIXED (mREINITIALIZExWORK)) + 6 + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        // CASE_LIST_PTRS(WORK) = 0; (1138)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mSTACK_FRAME)
                      + 32 * (getFIXED (mREINITIALIZExWORK)) + 28 + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        // FRAME_VAC_REF(WORK) = 0; (1139)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mSTACK_FRAME)
                      + 32 * (getFIXED (mREINITIALIZExWORK)) + 12 + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        // FRAME_SYT_REF(WORK) = 0; (1140)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mSTACK_FRAME)
                      + 32 * (getFIXED (mREINITIALIZExWORK)) + 10 + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        // FRAME_VAC_PREV_REF(WORK) = 0; (1141)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mSTACK_FRAME)
                      + 32 * (getFIXED (mREINITIALIZExWORK)) + 16 + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        // FRAME_SYT_PREV_REF(WORK) = 0; (1142)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mSTACK_FRAME)
                      + 32 * (getFIXED (mREINITIALIZExWORK)) + 14 + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        // FRAME_BUMP_FACTOR(WORK) = 0; (1143)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mSTACK_FRAME)
                      + 32 * (getFIXED (mREINITIALIZExWORK)) + 18 + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        // FRAME_MAP_SAVE(WORK) = 0; (1144)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mSTACK_FRAME)
                      + 32 * (getFIXED (mREINITIALIZExWORK)) + 22 + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        // VAC_BOUNDS(WORK) = 0; (1145)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mSTACK_FRAME)
                      + 32 * (getFIXED (mREINITIALIZExWORK)) + 24 + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
        // FRAME_CASE_LIST(WORK) = 0; (1146)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (16,
                  getFIXED (mSTACK_FRAME)
                      + 32 * (getFIXED (mREINITIALIZExWORK)) + 20 + 2 * (0),
                  fixedToBit (16, numberRHS));
        }
      }
  } // End of DO for-loop block
  // WORK = CELL_SIZE - FREE_CELL_PTR; (1147)
  {
    int32_t numberRHS = (int32_t)(xsubtract (COREHALFWORD (mCELL_SIZE),
                                             COREHALFWORD (mFREE_CELL_PTR)));
    putFIXED (mREINITIALIZExWORK, numberRHS);
  }
  // IF WORK > MAX_USED_CELLS THEN (1148)
  if (1
      & (xGT (getFIXED (mREINITIALIZExWORK), COREHALFWORD (mMAX_USED_CELLS))))
    // MAX_USED_CELLS = WORK; (1149)
    {
      int32_t numberRHS = (int32_t)(getFIXED (mREINITIALIZExWORK));
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mMAX_USED_CELLS, bitRHS);
      bitRHS->inUse = 0;
    }
  // CALL LINK_CELL_AREA; (1150)
  LINK_CELL_AREA (0);
  // SYT_REF_POOL_MAP(0), VAC_REF_POOL_MAP(0) =  2147483648; (1151)
  {
    int32_t numberRHS = (int32_t)(2147483648);
    putBIT (32, getFIXED (mS_MAP_VAR) + 4 * (0) + 0 + 4 * (0),
            fixedToBit (32, numberRHS));
    putBIT (32, getFIXED (mV_MAP_VAR) + 4 * (0) + 0 + 4 * (0),
            fixedToBit (32, numberRHS));
  }
  // DO FOR WORK = 1 TO RECORD_TOP(S_MAP_VAR); (1152)
  {
    int32_t from33, to33, by33;
    from33 = 1;
    to33 = xsubtract (
        COREWORD (xadd (ADDR ("S_MAP_VAR", 0x80000000, NULL, 0), 12)), 1);
    by33 = 1;
    for (putFIXED (mREINITIALIZExWORK, from33);
         getFIXED (mREINITIALIZExWORK) <= to33;
         putFIXED (mREINITIALIZExWORK, getFIXED (mREINITIALIZExWORK) + by33))
      {
        // SYT_REF_POOL_MAP(WORK) = 0; (1153)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (32,
                  getFIXED (mS_MAP_VAR) + 4 * (getFIXED (mREINITIALIZExWORK))
                      + 0 + 4 * (0),
                  fixedToBit (32, numberRHS));
        }
      }
  } // End of DO for-loop block
  // DO FOR WORK = 1 TO RECORD_TOP(V_MAP_VAR); (1154)
  {
    int32_t from34, to34, by34;
    from34 = 1;
    to34 = xsubtract (
        COREWORD (xadd (ADDR ("V_MAP_VAR", 0x80000000, NULL, 0), 12)), 1);
    by34 = 1;
    for (putFIXED (mREINITIALIZExWORK, from34);
         getFIXED (mREINITIALIZExWORK) <= to34;
         putFIXED (mREINITIALIZExWORK, getFIXED (mREINITIALIZExWORK) + by34))
      {
        // VAC_REF_POOL_MAP(WORK) = 0; (1155)
        {
          int32_t numberRHS = (int32_t)(0);
          putBIT (32,
                  getFIXED (mV_MAP_VAR) + 4 * (getFIXED (mREINITIALIZExWORK))
                      + 0 + 4 * (0),
                  fixedToBit (32, numberRHS));
        }
      }
  } // End of DO for-loop block
  {
    reentryGuard = 0;
    return 0;
  }
}
