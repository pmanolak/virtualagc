/*
  File INTERPRET_ACCESS_FILE.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

jmp_buf jbINTERPRET_ACCESS_FILExEND_FILE_EXIT;

int32_t
INTERPRET_ACCESS_FILE (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "INTERPRET_ACCESS_FILE");
  int setjmpInitialize = 1;
  if (setjmpInitialize)
    {
      goto END_FILE_EXIT;
    setjmpInitialized:
      setjmpInitialize = 0;
    }
  // IF ~ACCESS_FOUND THEN (2670)
  if (1 & (xNOT (BYTE0 (mACCESS_FOUND))))
    // RETURN; (2671)
    {
      reentryGuard = 0;
      return 0;
    }
  // IF MONITOR(2, 6, PROGRAM_ID) THEN (2672)
  if (1 & (MONITOR2 (6, getCHARACTER (mPROGRAM_ID))))
    // DO; (2673)
    {
    rs1:;
      // CALL ERROR(CLASS_PA, 1, PROGRAM_ID); (2674)
      {
        putBITp (16, mERRORxCLASS, getBIT (16, mCLASS_PA));
        putBITp (8, mERRORxNUM, fixedToBit (32, (int32_t)(1)));
        putCHARACTERp (mERRORxTEXT, getCHARACTER (mPROGRAM_ID));
        ERROR (0);
      }
      // RETURN; (2675)
      {
        reentryGuard = 0;
        return 0;
      }
    es1:;
    } // End of DO block
  // ACCESS_OFF = ~ACCESS_FLAG; (2676)
  {
    int32_t numberRHS = (int32_t)(4294901759);
    putFIXED (mINTERPRET_ACCESS_FILExACCESS_OFF, numberRHS);
  }
  // LETTER_OR_DIGIT(BYTE('$')) = TRUE; (2677)
  {
    int32_t numberRHS = (int32_t)(1);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mLETTER_OR_DIGIT + 1 * (BYTE1 (cToDescriptor (NULL, "$"))),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // CP = TEXT_LIMIT; (2678)
  {
    descriptor_t *bitRHS = getBIT (16, mTEXT_LIMIT);
    putBIT (16, mINTERPRET_ACCESS_FILExCP, bitRHS);
    bitRHS->inUse = 0;
  }
  // CALL ADVANCE_CP; (2679)
  INTERPRET_ACCESS_FILExADVANCE_CP (0);
// RESTART: (2680)
RESTART:
  // I = NEXT_TOKEN; (2681)
  {
    int32_t numberRHS = (int32_t)(INTERPRET_ACCESS_FILExNEXT_TOKEN (0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mINTERPRET_ACCESS_FILExI, bitRHS);
    bitRHS->inUse = 0;
  }
  // IF I ~= 0 THEN (2682)
  if (1 & (xNEQ (COREHALFWORD (mINTERPRET_ACCESS_FILExI), 0)))
    // GO TO SYNTAX_ERROR; (2683)
    goto SYNTAX_ERROR;
  // BLOCK_NAME = A_TOKEN; (2684)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN);
    putCHARACTER (mINTERPRET_ACCESS_FILExBLOCK_NAME, stringRHS);
    stringRHS->inUse = 0;
  }
  // IF NEXT_TOKEN ~= 1 THEN (2685)
  if (1 & (xNEQ (INTERPRET_ACCESS_FILExNEXT_TOKEN (0), 1)))
    // GO TO SYNTAX_ERROR; (2686)
    goto SYNTAX_ERROR;
// RECOVERY_POINT: (2687)
RECOVERY_POINT:
  // IF BLOCK_NAME = '$BLOCK' THEN (2688)
  if (1
      & (xsEQ (getCHARACTER (mINTERPRET_ACCESS_FILExBLOCK_NAME),
               cToDescriptor (NULL, "$BLOCK"))))
    // DO FOREVER; (2689)
    while (1 & (1))
      {
        // IF NEXT_TOKEN ~= 0 THEN (2690)
        if (1 & (xNEQ (INTERPRET_ACCESS_FILExNEXT_TOKEN (0), 0)))
          // GO TO SYNTAX_ERROR; (2691)
          goto SYNTAX_ERROR;
        // I = LOOKUP(A_TOKEN); (2692)
        {
          int32_t numberRHS = (int32_t)((
              putCHARACTERp (mINTERPRET_ACCESS_FILExLOOKUPxNAME,
                             getCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN)),
              INTERPRET_ACCESS_FILExLOOKUP (0)));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mINTERPRET_ACCESS_FILExI, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF I < 0 THEN (2693)
        if (1 & (xLT (COREHALFWORD (mINTERPRET_ACCESS_FILExI), 0)))
          // CALL ACCESS_ERROR(1, A_TOKEN); (2694)
          {
            putBITp (16, mINTERPRET_ACCESS_FILExACCESS_ERRORxMSG_NUM,
                     fixedToBit (32, (int32_t)(1)));
            putCHARACTERp (mINTERPRET_ACCESS_FILExACCESS_ERRORxNAME,
                           getCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN));
            INTERPRET_ACCESS_FILExACCESS_ERROR (0);
          }
        // ELSE (2695)
        else
          // DO; (2696)
          {
          rs2s1:;
            // IF (SYT_TYPE(I) = PROC_LABEL) | (SYT_TYPE(I) = PROG_LABEL) |
            // (SYT_CLASS(I) = FUNC_CLASS) THEN (2697)
            if (1
                & (xOR (
                    xOR (xEQ (BYTE0 (getFIXED (mSYM_TAB)
                                     + 34
                                           * (COREHALFWORD (
                                               mINTERPRET_ACCESS_FILExI))
                                     + 32 + 1 * (0)),
                              71),
                         xEQ (BYTE0 (getFIXED (mSYM_TAB)
                                     + 34
                                           * (COREHALFWORD (
                                               mINTERPRET_ACCESS_FILExI))
                                     + 32 + 1 * (0)),
                              73)),
                    xEQ (
                        BYTE0 (getFIXED (mSYM_TAB)
                               + 34 * (COREHALFWORD (mINTERPRET_ACCESS_FILExI))
                               + 30 + 1 * (0)),
                        BYTE0 (mFUNC_CLASS)))))
              // CALL RESET_ACCESS_FLAG; (2698)
              INTERPRET_ACCESS_FILExRESET_ACCESS_FLAG (0);
            // ELSE (2699)
            else
              // IF SYT_TYPE(I) = COMPOOL_LABEL THEN (2700)
              if (1
                  & (xEQ (
                      BYTE0 (getFIXED (mSYM_TAB)
                             + 34 * (COREHALFWORD (mINTERPRET_ACCESS_FILExI))
                             + 32 + 1 * (0)),
                      74)))
                // DO; (2701)
                {
                rs2s1s1:;
                  // J = ~READ_ACCESS_FLAG; (2702)
                  {
                    int32_t numberRHS = (int32_t)(3758096383);
                    putFIXED (mJ, numberRHS);
                  }
                  // CALL RESET_ACCESS_FLAG; (2703)
                  INTERPRET_ACCESS_FILExRESET_ACCESS_FLAG (0);
                  // DO WHILE (SYT_FLAGS(I) & ENDSCOPE_FLAG) = 0; (2704)
                  while (1
                         & (xEQ (xAND (getFIXED (
                                           getFIXED (mSYM_TAB)
                                           + 34
                                                 * (COREHALFWORD (
                                                     mINTERPRET_ACCESS_FILExI))
                                           + 8 + 4 * (0)),
                                       16384),
                                 0)))
                    {
                      // I = I + 1; (2705)
                      {
                        int32_t numberRHS = (int32_t)(xadd (
                            COREHALFWORD (mINTERPRET_ACCESS_FILExI), 1));
                        descriptor_t *bitRHS;
                        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
                        putBIT (16, mINTERPRET_ACCESS_FILExI, bitRHS);
                        bitRHS->inUse = 0;
                      }
                      // SYT_FLAGS(I) = SYT_FLAGS(I) & J; (2706)
                      {
                        int32_t numberRHS = (int32_t)(xAND (
                            getFIXED (getFIXED (mSYM_TAB)
                                      + 34
                                            * (COREHALFWORD (
                                                mINTERPRET_ACCESS_FILExI))
                                      + 8 + 4 * (0)),
                            getFIXED (mJ)));
                        putFIXED (getFIXED (mSYM_TAB)
                                      + 34
                                            * (COREHALFWORD (
                                                mINTERPRET_ACCESS_FILExI))
                                      + 8 + 4 * (0),
                                  numberRHS);
                      }
                    } // End of DO WHILE block
                es2s1s1:;
                } // End of DO block
              // ELSE (2707)
              else
                // CALL ACCESS_ERROR(2, A_TOKEN); (2708)
                {
                  putBITp (16, mINTERPRET_ACCESS_FILExACCESS_ERRORxMSG_NUM,
                           fixedToBit (32, (int32_t)(2)));
                  putCHARACTERp (
                      mINTERPRET_ACCESS_FILExACCESS_ERRORxNAME,
                      getCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN));
                  INTERPRET_ACCESS_FILExACCESS_ERROR (0);
                }
          es2s1:;
          } // End of DO block
        // I = NEXT_TOKEN; (2709)
        {
          int32_t numberRHS = (int32_t)(INTERPRET_ACCESS_FILExNEXT_TOKEN (0));
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mINTERPRET_ACCESS_FILExI, bitRHS);
          bitRHS->inUse = 0;
        }
        // IF I = 2 THEN (2710)
        if (1 & (xEQ (COREHALFWORD (mINTERPRET_ACCESS_FILExI), 2)))
          // GO TO RESTART; (2711)
          goto RESTART;
        // IF I ~= 3 THEN (2712)
        if (1 & (xNEQ (COREHALFWORD (mINTERPRET_ACCESS_FILExI), 3)))
          // GO TO SYNTAX_ERROR; (2713)
          goto SYNTAX_ERROR;
      } // End of DO WHILE block
  // ELSE (2714)
  else
    // DO; (2715)
    {
    rs3:;
      // BLOCK_START = LOOKUP(BLOCK_NAME); (2716)
      {
        int32_t numberRHS = (int32_t)((
            putCHARACTERp (mINTERPRET_ACCESS_FILExLOOKUPxNAME,
                           getCHARACTER (mINTERPRET_ACCESS_FILExBLOCK_NAME)),
            INTERPRET_ACCESS_FILExLOOKUP (0)));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mINTERPRET_ACCESS_FILExBLOCK_START, bitRHS);
        bitRHS->inUse = 0;
      }
      // IF BLOCK_START < 0 THEN (2717)
      if (1 & (xLT (COREHALFWORD (mINTERPRET_ACCESS_FILExBLOCK_START), 0)))
        // DO; (2718)
        {
        rs3s1:;
          // CALL ACCESS_ERROR(1, BLOCK_NAME); (2719)
          {
            putBITp (16, mINTERPRET_ACCESS_FILExACCESS_ERRORxMSG_NUM,
                     fixedToBit (32, (int32_t)(1)));
            putCHARACTERp (mINTERPRET_ACCESS_FILExACCESS_ERRORxNAME,
                           getCHARACTER (mINTERPRET_ACCESS_FILExBLOCK_NAME));
            INTERPRET_ACCESS_FILExACCESS_ERROR (0);
          }
          // GO TO RECOVER_WITHOUT_MSG; (2720)
          goto RECOVER_WITHOUT_MSG;
        es3s1:;
        } // End of DO block
      // IF SYT_TYPE(BLOCK_START) ~= COMPOOL_LABEL THEN (2721)
      if (1
          & (xNEQ (
              BYTE0 (getFIXED (mSYM_TAB)
                     + 34 * (COREHALFWORD (mINTERPRET_ACCESS_FILExBLOCK_START))
                     + 32 + 1 * (0)),
              74)))
        // DO; (2722)
        {
        rs3s2:;
          // CALL ACCESS_ERROR(5, BLOCK_NAME); (2723)
          {
            putBITp (16, mINTERPRET_ACCESS_FILExACCESS_ERRORxMSG_NUM,
                     fixedToBit (32, (int32_t)(5)));
            putCHARACTERp (mINTERPRET_ACCESS_FILExACCESS_ERRORxNAME,
                           getCHARACTER (mINTERPRET_ACCESS_FILExBLOCK_NAME));
            INTERPRET_ACCESS_FILExACCESS_ERROR (0);
          }
          // GO TO RECOVER_WITHOUT_MSG; (2724)
          goto RECOVER_WITHOUT_MSG;
        es3s2:;
        } // End of DO block
      // IF (SYT_FLAGS(BLOCK_START) & ACCESS_FLAG) ~= 0 THEN (2725)
      if (1
          & (xNEQ (
              xAND (getFIXED (getFIXED (mSYM_TAB)
                              + 34
                                    * (COREHALFWORD (
                                        mINTERPRET_ACCESS_FILExBLOCK_START))
                              + 8 + 4 * (0)),
                    65536),
              0)))
        // DO; (2726)
        {
        rs3s3:;
          // CALL ACCESS_ERROR(6, BLOCK_NAME); (2727)
          {
            putBITp (16, mINTERPRET_ACCESS_FILExACCESS_ERRORxMSG_NUM,
                     fixedToBit (32, (int32_t)(6)));
            putCHARACTERp (mINTERPRET_ACCESS_FILExACCESS_ERRORxNAME,
                           getCHARACTER (mINTERPRET_ACCESS_FILExBLOCK_NAME));
            INTERPRET_ACCESS_FILExACCESS_ERROR (0);
          }
          // GO TO RECOVER_WITHOUT_MSG; (2728)
          goto RECOVER_WITHOUT_MSG;
        es3s3:;
        } // End of DO block
      // BLOCK_END = BLOCK_START; (2729)
      {
        descriptor_t *bitRHS = getBIT (16, mINTERPRET_ACCESS_FILExBLOCK_START);
        putBIT (16, mINTERPRET_ACCESS_FILExBLOCK_END, bitRHS);
        bitRHS->inUse = 0;
      }
      // DO WHILE (SYT_FLAGS(BLOCK_END) & ENDSCOPE_FLAG) = 0; (2730)
      while (
          1
          & (xEQ (xAND (getFIXED (getFIXED (mSYM_TAB)
                                  + 34
                                        * (COREHALFWORD (
                                            mINTERPRET_ACCESS_FILExBLOCK_END))
                                  + 8 + 4 * (0)),
                        16384),
                  0)))
        {
          // BLOCK_END = BLOCK_END + 1; (2731)
          {
            int32_t numberRHS = (int32_t)(xadd (
                COREHALFWORD (mINTERPRET_ACCESS_FILExBLOCK_END), 1));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mINTERPRET_ACCESS_FILExBLOCK_END, bitRHS);
            bitRHS->inUse = 0;
          }
        } // End of DO WHILE block
      // DO FOREVER; (2732)
      while (1 & (1))
        {
          // IF NEXT_TOKEN ~= 0 THEN (2733)
          if (1 & (xNEQ (INTERPRET_ACCESS_FILExNEXT_TOKEN (0), 0)))
            // GO TO SYNTAX_ERROR; (2734)
            goto SYNTAX_ERROR;
          // IF A_TOKEN = '$ALL' THEN (2735)
          if (1
              & (xsEQ (getCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN),
                       cToDescriptor (NULL, "$ALL"))))
            // DO; (2736)
            {
            rs3s5s1:;
              // DO I = BLOCK_START TO BLOCK_END; (2737)
              {
                int32_t from55, to55, by55;
                from55 = bitToFixed (
                    getBIT (16, mINTERPRET_ACCESS_FILExBLOCK_START));
                to55 = bitToFixed (
                    getBIT (16, mINTERPRET_ACCESS_FILExBLOCK_END));
                by55 = 1;
                for (putBIT (16, mINTERPRET_ACCESS_FILExI,
                             fixedToBit (16, from55));
                     bitToFixed (getBIT (16, mINTERPRET_ACCESS_FILExI))
                     <= to55;
                     putBIT (16, mINTERPRET_ACCESS_FILExI,
                             fixedToBit (16, bitToFixed (getBIT (
                                                 16, mINTERPRET_ACCESS_FILExI))
                                                 + by55)))
                  {
                    // SYT_FLAGS(I) = SYT_FLAGS(I) & ACCESS_OFF; (2738)
                    {
                      int32_t numberRHS = (int32_t)(xAND (
                          getFIXED (
                              getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mINTERPRET_ACCESS_FILExI))
                              + 8 + 4 * (0)),
                          getFIXED (mINTERPRET_ACCESS_FILExACCESS_OFF)));
                      putFIXED (
                          getFIXED (mSYM_TAB)
                              + 34 * (COREHALFWORD (mINTERPRET_ACCESS_FILExI))
                              + 8 + 4 * (0),
                          numberRHS);
                    }
                  }
              } // End of DO for-loop block
              // IF NEXT_TOKEN ~= 2 THEN (2739)
              if (1 & (xNEQ (INTERPRET_ACCESS_FILExNEXT_TOKEN (0), 2)))
                // GO TO SYNTAX_ERROR; (2740)
                goto SYNTAX_ERROR;
              // GO TO RESTART; (2741)
              goto RESTART;
            es3s5s1:;
            } // End of DO block
          // I = LOOKUP(A_TOKEN); (2742)
          {
            int32_t numberRHS = (int32_t)((
                putCHARACTERp (mINTERPRET_ACCESS_FILExLOOKUPxNAME,
                               getCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN)),
                INTERPRET_ACCESS_FILExLOOKUP (0)));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mINTERPRET_ACCESS_FILExI, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF I < 0 THEN (2743)
          if (1 & (xLT (COREHALFWORD (mINTERPRET_ACCESS_FILExI), 0)))
            // CALL ACCESS_ERROR(1, A_TOKEN); (2744)
            {
              putBITp (16, mINTERPRET_ACCESS_FILExACCESS_ERRORxMSG_NUM,
                       fixedToBit (32, (int32_t)(1)));
              putCHARACTERp (mINTERPRET_ACCESS_FILExACCESS_ERRORxNAME,
                             getCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN));
              INTERPRET_ACCESS_FILExACCESS_ERROR (0);
            }
          // ELSE (2745)
          else
            // DO; (2746)
            {
            rs3s5s2:;
              // IF (I > BLOCK_END) | (I < BLOCK_START) THEN (2747)
              if (1
                  & (xOR (
                      xGT (COREHALFWORD (mINTERPRET_ACCESS_FILExI),
                           COREHALFWORD (mINTERPRET_ACCESS_FILExBLOCK_END)),
                      xLT (
                          COREHALFWORD (mINTERPRET_ACCESS_FILExI),
                          COREHALFWORD (mINTERPRET_ACCESS_FILExBLOCK_START)))))
                // CALL ACCESS_ERROR(4, A_TOKEN); (2748)
                {
                  putBITp (16, mINTERPRET_ACCESS_FILExACCESS_ERRORxMSG_NUM,
                           fixedToBit (32, (int32_t)(4)));
                  putCHARACTERp (
                      mINTERPRET_ACCESS_FILExACCESS_ERRORxNAME,
                      getCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN));
                  INTERPRET_ACCESS_FILExACCESS_ERROR (0);
                }
              // ELSE (2749)
              else
                // CALL RESET_ACCESS_FLAG; (2750)
                INTERPRET_ACCESS_FILExRESET_ACCESS_FLAG (0);
            es3s5s2:;
            } // End of DO block
          // I = NEXT_TOKEN; (2751)
          {
            int32_t numberRHS
                = (int32_t)(INTERPRET_ACCESS_FILExNEXT_TOKEN (0));
            descriptor_t *bitRHS;
            bitRHS = fixedToBit (32, (int32_t)(numberRHS));
            putBIT (16, mINTERPRET_ACCESS_FILExI, bitRHS);
            bitRHS->inUse = 0;
          }
          // IF I = 2 THEN (2752)
          if (1 & (xEQ (COREHALFWORD (mINTERPRET_ACCESS_FILExI), 2)))
            // GO TO RESTART; (2753)
            goto RESTART;
          // IF I ~= 3 THEN (2754)
          if (1 & (xNEQ (COREHALFWORD (mINTERPRET_ACCESS_FILExI), 3)))
            // GO TO SYNTAX_ERROR; (2755)
            goto SYNTAX_ERROR;
        } // End of DO WHILE block
    es3:;
    } // End of DO block
// SYNTAX_ERROR: (2756)
SYNTAX_ERROR:
  // CALL ACCESS_ERROR(0); (2757)
  {
    putBITp (16, mINTERPRET_ACCESS_FILExACCESS_ERRORxMSG_NUM,
             fixedToBit (32, (int32_t)(0)));
    INTERPRET_ACCESS_FILExACCESS_ERROR (0);
  }
  // I = NEXT_TOKEN; (2758)
  {
    int32_t numberRHS = (int32_t)(INTERPRET_ACCESS_FILExNEXT_TOKEN (0));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mINTERPRET_ACCESS_FILExI, bitRHS);
    bitRHS->inUse = 0;
  }
  // BLOCK_NAME = A_TOKEN; (2759)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN);
    putCHARACTER (mINTERPRET_ACCESS_FILExBLOCK_NAME, stringRHS);
    stringRHS->inUse = 0;
  }
// RECOVER_WITHOUT_MSG: (2760)
RECOVER_WITHOUT_MSG:
  // DO WHILE NEXT_TOKEN ~= 1; (2761)
  while (1 & (xNEQ (INTERPRET_ACCESS_FILExNEXT_TOKEN (0), 1)))
    {
      // BLOCK_NAME = A_TOKEN; (2762)
      {
        descriptor_t *stringRHS;
        stringRHS = getCHARACTER (mINTERPRET_ACCESS_FILExA_TOKEN);
        putCHARACTER (mINTERPRET_ACCESS_FILExBLOCK_NAME, stringRHS);
        stringRHS->inUse = 0;
      }
      if (0)
        {
        rs4:
          continue;
        es4:
          break;
        } // block labeled RECOVER_WITHOUT_MSG
    }     // End of DO WHILE block
  // GO TO RECOVERY_POINT; (2763)
  goto RECOVERY_POINT;
  // END_FILE_EXIT: (2764)
  if (0)
    {
    END_FILE_EXIT:
      if (setjmpInitialize)
        {
          if (!setjmp (jbINTERPRET_ACCESS_FILExEND_FILE_EXIT))
            goto setjmpInitialized;
        }
    }
  // LETTER_OR_DIGIT(BYTE('$')) = FALSE; (2765)
  {
    int32_t numberRHS = (int32_t)(0);
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (1, mLETTER_OR_DIGIT + 1 * (BYTE1 (cToDescriptor (NULL, "$"))),
            bitRHS);
    bitRHS->inUse = 0;
  }
  // RETURN; (2766)
  {
    reentryGuard = 0;
    return 0;
  }
}
