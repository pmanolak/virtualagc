/*
  File GET_CELL.c generated by XCOM-I, 2024-08-09 12:38:39.
*/

#include "runtimeC.h"

int32_t
GET_CELL (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_CELL");
  // CELL_SIZE = (CELL_SIZE + 3)& 4294967292; (1000)
  {
    int32_t numberRHS = (int32_t)(xAND (
        xadd (getFIXED (mGET_CELLxCELL_SIZE), 3), 4294967292));
    putFIXED (mGET_CELLxCELL_SIZE, numberRHS);
  }
  // IF CELL_SIZE > VMEM_PAGE_SIZE THEN (1001)
  if (1 & (xGT (getFIXED (mGET_CELLxCELL_SIZE), 3360)))
    // DO; (1002)
    {
    rs1:;
      // CALL ERRORS(CLASS_BI,703); (1003)
      {
        putBITp (16, mERRORSxCLASS, getBIT (16, mCLASS_BI));
        putBITp (16, mERRORSxNUM, fixedToBit (32, (int32_t)(703)));
        ERRORS (0);
      }
      // CALL EXIT; (1004)
      EXIT ();
    es1:;
    } // End of DO block
  // IF CELL_SIZE < VMEM_PAGE_SIZE THEN (1005)
  if (1 & (xLT (getFIXED (mGET_CELLxCELL_SIZE), 3360)))
    // DO; (1006)
    {
    rs2:;
      // IF VMEM_LOOK_AHEAD THEN (1007)
      if (1 & (bitToFixed (getBIT (1, mVMEM_LOOK_AHEAD))))
        // DO; (1008)
        {
        rs2s1:;
          // PAGE = VMEM_LAST_PAGE; (1009)
          {
            descriptor_t *bitRHS = getBIT (16, mVMEM_LAST_PAGE);
            int32_t numberRHS;
            numberRHS = bitToFixed (bitRHS);
            putFIXED (mGET_CELLxPAGE, numberRHS);
            bitRHS->inUse = 0;
          }
          // AVAIL_SIZE = VMEM_PAGE_AVAIL_SPACE(PAGE); (1010)
          {
            descriptor_t *bitRHS = getBIT (
                16, mVMEM_PAGE_AVAIL_SPACE + 2 * getFIXED (mGET_CELLxPAGE));
            int32_t numberRHS;
            numberRHS = bitToFixed (bitRHS);
            putFIXED (mGET_CELLxAVAIL_SIZE, numberRHS);
            bitRHS->inUse = 0;
          }
          // IF AVAIL_SIZE >= CELL_SIZE THEN (1011)
          if (1
              & (xGE (getFIXED (mGET_CELLxAVAIL_SIZE),
                      getFIXED (mGET_CELLxCELL_SIZE))))
            // GO TO GET_SPACE; (1012)
            goto GET_SPACE;
          // ELSE (1013)
          else
            // GO TO EXTEND_VMEM; (1014)
            goto EXTEND_VMEM;
        es2s1:;
        } // End of DO block
      // DO I = 0 TO VMEM_LAST_PAGE; (1015)
      {
        int32_t from21, to21, by21;
        from21 = 0;
        to21 = bitToFixed (getBIT (16, mVMEM_LAST_PAGE));
        by21 = 1;
        for (putFIXED (mGET_CELLxI, from21); getFIXED (mGET_CELLxI) <= to21;
             putFIXED (mGET_CELLxI, getFIXED (mGET_CELLxI) + by21))
          {
            // PAGE = VMEM_LAST_PAGE - I; (1016)
            {
              int32_t numberRHS = (int32_t)(xsubtract (
                  COREHALFWORD (mVMEM_LAST_PAGE), getFIXED (mGET_CELLxI)));
              putFIXED (mGET_CELLxPAGE, numberRHS);
            }
            // AVAIL_SIZE = VMEM_PAGE_AVAIL_SPACE(PAGE); (1017)
            {
              descriptor_t *bitRHS = getBIT (
                  16, mVMEM_PAGE_AVAIL_SPACE + 2 * getFIXED (mGET_CELLxPAGE));
              int32_t numberRHS;
              numberRHS = bitToFixed (bitRHS);
              putFIXED (mGET_CELLxAVAIL_SIZE, numberRHS);
              bitRHS->inUse = 0;
            }
            // IF (AVAIL_SIZE >= CELL_SIZE)&(VMEM_PAGE_TO_NDX(PAGE)~=-1) THEN
            // (1018)
            if (1
                & (xAND (xGE (getFIXED (mGET_CELLxAVAIL_SIZE),
                              getFIXED (mGET_CELLxCELL_SIZE)),
                         xNEQ (COREHALFWORD (mVMEM_PAGE_TO_NDX
                                             + 2 * getFIXED (mGET_CELLxPAGE)),
                               -1))))
              // GO TO GET_SPACE; (1019)
              goto GET_SPACE;
          }
      } // End of DO for-loop block
    es2:;
    } // End of DO block
// EXTEND_VMEM: (1020)
EXTEND_VMEM:
  // PAGE = VMEM_LAST_PAGE + 1; (1021)
  {
    int32_t numberRHS = (int32_t)(xadd (COREHALFWORD (mVMEM_LAST_PAGE), 1));
    putFIXED (mGET_CELLxPAGE, numberRHS);
  }
  // AVAIL_SIZE = VMEM_PAGE_SIZE; (1022)
  {
    int32_t numberRHS = (int32_t)(3360);
    putFIXED (mGET_CELLxAVAIL_SIZE, numberRHS);
  }
// GET_SPACE: (1023)
GET_SPACE:
  // CALL PTR_LOCATE(SHL(PAGE,16)+(VMEM_PAGE_SIZE-AVAIL_SIZE),MODF|FLAGS);
  // (1024)
  {
    putFIXED (mPTR_LOCATExPTR,
              xadd (SHL (getFIXED (mGET_CELLxPAGE), 16),
                    xsubtract (3360, getFIXED (mGET_CELLxAVAIL_SIZE))));
    putBITp (8, mPTR_LOCATExFLAGS,
             fixedToBit (
                 32, (int32_t)(xOR (BYTE0 (mMODF), BYTE0 (mGET_CELLxFLAGS)))));
    PTR_LOCATE (0);
  }
  // CELL_TEMP = AVAIL_SIZE - CELL_SIZE; (1025)
  {
    int32_t numberRHS = (int32_t)(xsubtract (getFIXED (mGET_CELLxAVAIL_SIZE),
                                             getFIXED (mGET_CELLxCELL_SIZE)));
    putFIXED (mGET_CELLxCELL_TEMP, numberRHS);
  }
  // VMEM_PAGE_AVAIL_SPACE(PAGE) = CELL_TEMP; (1026)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mGET_CELLxCELL_TEMP));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mVMEM_PAGE_AVAIL_SPACE + 2 * (getFIXED (mGET_CELLxPAGE)),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // COREWORD(BVAR) = VMEM_LOC_ADDR; (1027)
  {
    int32_t numberRHS = (int32_t)(getFIXED (mVMEM_LOC_ADDR));
    COREWORD2 (getFIXED (mGET_CELLxBVAR), numberRHS);
  }
  // RETURN VMEM_LOC_PTR; (1028)
  {
    reentryGuard = 0;
    return getFIXED (mVMEM_LOC_PTR);
  }
}
