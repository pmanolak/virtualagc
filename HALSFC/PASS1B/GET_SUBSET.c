/*
  File GET_SUBSET.c generated by XCOM-I, 2024-08-09 12:40:41.
*/

#include "runtimeC.h"

int32_t
GET_SUBSET (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "GET_SUBSET");
  // IF MONITOR(2,6,SUBSET) THEN (9434)
  if (1 & (MONITOR2 (6, getCHARACTER (mGET_SUBSETxSUBSET))))
    // RETURN 1; (9435)
    {
      reentryGuard = 0;
      return 1;
    }
  // S=INPUT(6); (9436)
  {
    descriptor_t *stringRHS;
    stringRHS = INPUT (6);
    putCHARACTER (mGET_SUBSETxS, stringRHS);
    stringRHS->inUse = 0;
  }
  // IF LENGTH(S)=0 THEN (9437)
  if (1 & (xEQ (LENGTH (getCHARACTER (mGET_SUBSETxS)), 0)))
    // RETURN 1; (9438)
    {
      reentryGuard = 0;
      return 1;
    }
  // LIMIT=LENGTH(S)-1; (9439)
  {
    int32_t numberRHS
        = (int32_t)(xsubtract (LENGTH (getCHARACTER (mGET_SUBSETxS)), 1));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGET_SUBSETxLIMIT, bitRHS);
    bitRHS->inUse = 0;
  }
  // OUTPUT(1)=SUBSET_MSG||S; (9440)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (getCHARACTER (mGET_SUBSETxSUBSET_MSG),
                       getCHARACTER (mGET_SUBSETxS));
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT=X1; (9441)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mX1);
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // CP=LIMIT; (9442)
  {
    descriptor_t *bitRHS = getBIT (16, mGET_SUBSETxLIMIT);
    putBIT (16, mGET_SUBSETxCP, bitRHS);
    bitRHS->inUse = 0;
  }
  // I=1; (9443)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mGET_SUBSETxI, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE I~=0; (9444)
  while (1 & (xNEQ (COREHALFWORD (mGET_SUBSETxI), 0)))
    {
      // DO CASE GET_TOKEN; (9445)
      {
      rs1s1:
        switch (GET_SUBSETxGET_TOKEN (0))
          {
          case 0:
            // IF LENGTH(A_TOKEN)>0 THEN (9447)
            if (1 & (xGT (LENGTH (getCHARACTER (mGET_SUBSETxA_TOKEN)), 0)))
              {
                putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                         fixedToBit (32, (int32_t)(0)));
                GET_SUBSETxSUBSET_ERROR (0);
              }
            break;
          case 1:
            // DO; (9449)
            {
            rs1s1s1:;
              // IF A_TOKEN='$BUILTINS' THEN (9449)
              if (1
                  & (xsEQ (getCHARACTER (mGET_SUBSETxA_TOKEN),
                           cToDescriptor (NULL, "$BUILTINS"))))
                // DO WHILE I; (9450)
                while (1 & (bitToFixed (getBIT (16, mGET_SUBSETxI))))
                  {
                    // DO CASE GET_TOKEN; (9451)
                    {
                    rs1s1s1s1s1:
                      switch (GET_SUBSETxGET_TOKEN (0))
                        {
                        case 0:
                          // CALL SUBSET_ERROR(0); (9453)
                          {
                            putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                                     fixedToBit (32, (int32_t)(0)));
                            GET_SUBSETxSUBSET_ERROR (0);
                          }
                          break;
                        case 1:
                          // CALL SUBSET_ERROR(1); (9454)
                          {
                            putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                                     fixedToBit (32, (int32_t)(1)));
                            GET_SUBSETxSUBSET_ERROR (0);
                          }
                          break;
                        case 2:
                        // CASE_B2: (9455)
                        CASE_B2:
                          {
                          rs1s1s1s1s1s1:;
                            // L=BI#; (9456)
                            {
                              int32_t numberRHS = (int32_t)(63);
                              descriptor_t *bitRHS;
                              bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                              putBIT (16, mGET_SUBSETxL, bitRHS);
                              bitRHS->inUse = 0;
                            }
                            // DO WHILE L>0; (9457)
                            while (1 & (xGT (COREHALFWORD (mGET_SUBSETxL), 0)))
                              {
                                // IF SUBSTR(BI_NAME(BI_INDX(L)),BI_LOC(L),10)
                                // = PAD(A_TOKEN,10)  THEN (9458)
                                if (1
                                    & (xsEQ (
                                        SUBSTR (
                                            getCHARACTER (
                                                mBI_NAME
                                                + 4
                                                      * BYTE0 (
                                                          mBI_INDX
                                                          + 1
                                                                * COREHALFWORD (
                                                                    mGET_SUBSETxL))),
                                            BYTE0 (mBI_LOC
                                                   + 1
                                                         * COREHALFWORD (
                                                             mGET_SUBSETxL)),
                                            10),
                                        (putCHARACTERp (
                                             mPADxSTRING,
                                             getCHARACTER (
                                                 mGET_SUBSETxA_TOKEN)),
                                         putFIXED (mPADxWIDTH, 10), PAD (0)))))
                                  // DO; (9459)
                                  {
                                  rs1s1s1s1s1s1s1s1:;
                                    // BI_FLAGS(L)=BI_FLAGS(L)|FLAGS; (9460)
                                    {
                                      int32_t numberRHS = (int32_t)(xOR (
                                          BYTE0 (mBI_FLAGS
                                                 + 1
                                                       * COREHALFWORD (
                                                           mGET_SUBSETxL)),
                                          BYTE0 (mGET_SUBSETxFLAGS)));
                                      descriptor_t *bitRHS;
                                      bitRHS = fixedToBit (
                                          32, (int32_t)(numberRHS));
                                      putBIT (8,
                                              mBI_FLAGS
                                                  + 1
                                                        * (COREHALFWORD (
                                                            mGET_SUBSETxL)),
                                              bitRHS);
                                      bitRHS->inUse = 0;
                                    }
                                    // L=-1; (9461)
                                    {
                                      int32_t numberRHS = (int32_t)(-1);
                                      descriptor_t *bitRHS;
                                      bitRHS = fixedToBit (
                                          32, (int32_t)(numberRHS));
                                      putBIT (16, mGET_SUBSETxL, bitRHS);
                                      bitRHS->inUse = 0;
                                    }
                                  es1s1s1s1s1s1s1s1:;
                                  } // End of DO block
                                // ELSE (9462)
                                else
                                  // L=L-1; (9463)
                                  {
                                    int32_t numberRHS = (int32_t)(xsubtract (
                                        COREHALFWORD (mGET_SUBSETxL), 1));
                                    descriptor_t *bitRHS;
                                    bitRHS = fixedToBit (32,
                                                         (int32_t)(numberRHS));
                                    putBIT (16, mGET_SUBSETxL, bitRHS);
                                    bitRHS->inUse = 0;
                                  }
                              } // End of DO WHILE block
                            // IF L=0 THEN (9464)
                            if (1 & (xEQ (COREHALFWORD (mGET_SUBSETxL), 0)))
                              // CALL SUBSET_ERROR(2); (9465)
                              {
                                putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                                         fixedToBit (32, (int32_t)(2)));
                                GET_SUBSETxSUBSET_ERROR (0);
                              }
                          es1s1s1s1s1s1:;
                          } // End of DO block
                          break;
                        case 3:
                          // GO TO CASE_B2; (9467)
                          goto CASE_B2;
                          break;
                        }
                    } // End of DO CASE block
                  }   // End of DO WHILE block
              // ELSE (9467)
              else
                // IF A_TOKEN='$PRODUCTIONS' THEN (9468)
                if (1
                    & (xsEQ (getCHARACTER (mGET_SUBSETxA_TOKEN),
                             cToDescriptor (NULL, "$PRODUCTIONS"))))
                  // DO WHILE I; (9469)
                  while (1 & (bitToFixed (getBIT (16, mGET_SUBSETxI))))
                    {
                      // DO CASE GET_TOKEN; (9470)
                      {
                      rs1s1s1s2s1:
                        switch (GET_SUBSETxGET_TOKEN (0))
                          {
                          case 0:
                            // CALL SUBSET_ERROR(0); (9472)
                            {
                              putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                                       fixedToBit (32, (int32_t)(0)));
                              GET_SUBSETxSUBSET_ERROR (0);
                            }
                            break;
                          case 1:
                            // CALL SUBSET_ERROR(1); (9473)
                            {
                              putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                                       fixedToBit (32, (int32_t)(1)));
                              GET_SUBSETxSUBSET_ERROR (0);
                            }
                            break;
                          case 2:
                          // CASE_P2: (9474)
                          CASE_P2:
                            {
                            rs1s1s1s2s1s1:;
                              // L=VALUE; (9475)
                              {
                                int32_t numberRHS
                                    = (int32_t)(GET_SUBSETxVALUE (0));
                                descriptor_t *bitRHS;
                                bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                                putBIT (16, mGET_SUBSETxL, bitRHS);
                                bitRHS->inUse = 0;
                              }
                              // IF (L>0)&(L<=P#) THEN (9476)
                              if (1
                                  & (xAND (
                                      xGT (COREHALFWORD (mGET_SUBSETxL), 0),
                                      xLE (COREHALFWORD (mGET_SUBSETxL),
                                           453))))
                                // #PRODUCE_NAME(L)=
                                // #PRODUCE_NAME(L)|SHL(FLAGS,12); (9477)
                                {
                                  int32_t numberRHS = (int32_t)(xOR (
                                      COREHALFWORD (
                                          mpPRODUCE_NAME
                                          + 2 * COREHALFWORD (mGET_SUBSETxL)),
                                      SHL (BYTE0 (mGET_SUBSETxFLAGS), 12)));
                                  descriptor_t *bitRHS;
                                  bitRHS
                                      = fixedToBit (32, (int32_t)(numberRHS));
                                  putBIT (
                                      16,
                                      mpPRODUCE_NAME
                                          + 2 * (COREHALFWORD (mGET_SUBSETxL)),
                                      bitRHS);
                                  bitRHS->inUse = 0;
                                }
                              // ELSE (9478)
                              else
                                // CALL SUBSET_ERROR(3); (9479)
                                {
                                  putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                                           fixedToBit (32, (int32_t)(3)));
                                  GET_SUBSETxSUBSET_ERROR (0);
                                }
                            es1s1s1s2s1s1:;
                            } // End of DO block
                            break;
                          case 3:
                            // GO TO CASE_P2; (9481)
                            goto CASE_P2;
                            break;
                          }
                      } // End of DO CASE block
                    }   // End of DO WHILE block
                // ELSE (9481)
                else
                  // IF A_TOKEN = '$BITLENGTH' THEN (9482)
                  if (1
                      & (xsEQ (getCHARACTER (mGET_SUBSETxA_TOKEN),
                               cToDescriptor (NULL, "$BITLENGTH"))))
                    // DO WHILE I; (9483)
                    while (1 & (bitToFixed (getBIT (16, mGET_SUBSETxI))))
                      {
                        // DO CASE GET_TOKEN; (9484)
                        {
                        rs1s1s1s3s1:
                          switch (GET_SUBSETxGET_TOKEN (0))
                            {
                            case 0:
                              // CALL SUBSET_ERROR(0); (9486)
                              {
                                putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                                         fixedToBit (32, (int32_t)(0)));
                                GET_SUBSETxSUBSET_ERROR (0);
                              }
                              break;
                            case 1:
                              // CALL SUBSET_ERROR(1); (9487)
                              {
                                putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                                         fixedToBit (32, (int32_t)(1)));
                                GET_SUBSETxSUBSET_ERROR (0);
                              }
                              break;
                            case 2:
                              // DO; (9488)
                              {
                              rs1s1s1s3s1s1:;
                                // L = VALUE; (9488)
                                {
                                  int32_t numberRHS
                                      = (int32_t)(GET_SUBSETxVALUE (0));
                                  descriptor_t *bitRHS;
                                  bitRHS
                                      = fixedToBit (32, (int32_t)(numberRHS));
                                  putBIT (16, mGET_SUBSETxL, bitRHS);
                                  bitRHS->inUse = 0;
                                }
                                // IF L < 1 | L > BIT_LENGTH_LIM THEN (9489)
                                if (1
                                    & (xOR (
                                        xLT (COREHALFWORD (mGET_SUBSETxL), 1),
                                        xGT (COREHALFWORD (mGET_SUBSETxL),
                                             COREHALFWORD (mBIT_LENGTH_LIM)))))
                                  // CALL SUBSET_ERROR(4); (9490)
                                  {
                                    putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                                             fixedToBit (32, (int32_t)(4)));
                                    GET_SUBSETxSUBSET_ERROR (0);
                                  }
                                // ELSE (9491)
                                else
                                  // BIT_LENGTH_LIM = L; (9492)
                                  {
                                    descriptor_t *bitRHS
                                        = getBIT (16, mGET_SUBSETxL);
                                    putBIT (16, mBIT_LENGTH_LIM, bitRHS);
                                    bitRHS->inUse = 0;
                                  }
                              es1s1s1s3s1s1:;
                              } // End of DO block
                              break;
                            case 3:
                              // CALL SUBSET_ERROR(1); (9494)
                              {
                                putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                                         fixedToBit (32, (int32_t)(1)));
                                GET_SUBSETxSUBSET_ERROR (0);
                              }
                              break;
                            }
                        } // End of DO CASE block
                      }   // End of DO WHILE block
                  // ELSE (9494)
                  else
                    // CALL SUBSET_ERROR(1); (9495)
                    {
                      putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                               fixedToBit (32, (int32_t)(1)));
                      GET_SUBSETxSUBSET_ERROR (0);
                    }
            es1s1s1:;
            } // End of DO block
            break;
          case 2:
            // CALL SUBSET_ERROR(1); (9497)
            {
              putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                       fixedToBit (32, (int32_t)(1)));
              GET_SUBSETxSUBSET_ERROR (0);
            }
            break;
          case 3:
            // CALL SUBSET_ERROR(1); (9498)
            {
              putBITp (16, mGET_SUBSETxSUBSET_ERRORxNUM,
                       fixedToBit (32, (int32_t)(1)));
              GET_SUBSETxSUBSET_ERROR (0);
            }
            break;
          }
      } // End of DO CASE block
    }   // End of DO WHILE block
  // OUTPUT=X1; (9498)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mX1);
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // RETURN 0; (9499)
  {
    reentryGuard = 0;
    return 0;
  }
}
