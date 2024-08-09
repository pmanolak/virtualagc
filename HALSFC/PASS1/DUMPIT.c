/*
  File DUMPIT.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

int32_t
DUMPIT (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "DUMPIT");
  // OUTPUT = '       OPTIONAL TABLE SIZES'; (9803)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "       OPTIONAL TABLE SIZES");
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '0NAME       REQUESTED    USED'; (9804)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "0NAME       REQUESTED    USED");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = '+____       _________    ____'; (9805)
  {
    descriptor_t *stringRHS;
    stringRHS = cToDescriptor (NULL, "+____       _________    ____");
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = X1; (9806)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mX1);
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = FORM_UP('LITSTRINGS',LIT_CHAR_SIZE,LIT_CHAR_USED); (9807)
  {
    descriptor_t *stringRHS;
    stringRHS = (putCHARACTERp (mDUMPITxFORM_UPxMSG,
                                cToDescriptor (NULL, "LITSTRINGS")),
                 putFIXED (mDUMPITxFORM_UPxVAL1, getFIXED (mLIT_CHAR_SIZE)),
                 putFIXED (mDUMPITxFORM_UPxVAL2, getFIXED (mCOMM + 4 * 1)),
                 DUMPITxFORM_UP (0));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = FORM_UP('SYMBOLS   ', SYTSIZE, NDECSY); (9808)
  {
    descriptor_t *stringRHS;
    stringRHS = (putCHARACTERp (mDUMPITxFORM_UPxMSG,
                                cToDescriptor (NULL, "SYMBOLS   ")),
                 putFIXED (mDUMPITxFORM_UPxVAL1, getFIXED (mSYTSIZE)),
                 putFIXED (mDUMPITxFORM_UPxVAL2, getFIXED (mCOMM + 4 * 10)),
                 DUMPITxFORM_UP (0));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = FORM_UP('MACROSIZE ', MACRO_TEXT_LIM, FIRST_FREE); (9809)
  {
    descriptor_t *stringRHS;
    stringRHS = (putCHARACTERp (mDUMPITxFORM_UPxMSG,
                                cToDescriptor (NULL, "MACROSIZE ")),
                 putFIXED (mDUMPITxFORM_UPxVAL1, getFIXED (mMACRO_TEXT_LIM)),
                 putFIXED (mDUMPITxFORM_UPxVAL2, getFIXED (mCOMM + 4 * 9)),
                 DUMPITxFORM_UP (0));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = FORM_UP('XREFSIZE  ', XREF_LIM, XREF_INDEX); (9810)
  {
    descriptor_t *stringRHS;
    stringRHS = (putCHARACTERp (mDUMPITxFORM_UPxMSG,
                                cToDescriptor (NULL, "XREFSIZE  ")),
                 putFIXED (mDUMPITxFORM_UPxVAL1, getFIXED (mXREF_LIM)),
                 putFIXED (mDUMPITxFORM_UPxVAL2, getFIXED (mCOMM + 4 * 8)),
                 DUMPITxFORM_UP (0));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = FORM_UP('BLOCKSUM  ', OUTER_REF_LIM, OUTER_REF_MAX); (9811)
  {
    descriptor_t *stringRHS;
    stringRHS
        = (putCHARACTERp (mDUMPITxFORM_UPxMSG,
                          cToDescriptor (NULL, "BLOCKSUM  ")),
           putFIXED (mDUMPITxFORM_UPxVAL1, COREHALFWORD (mOUTER_REF_LIM)),
           putFIXED (mDUMPITxFORM_UPxVAL2, COREHALFWORD (mOUTER_REF_MAX)),
           DUMPITxFORM_UP (0));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT(1) = DOUBLE; (9812)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mDOUBLE);
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'CALLS TO SCAN        = ' || SCAN_COUNT; (9813)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "CALLS TO SCAN        = "),
                       fixedToCharacter (getFIXED (mSCAN_COUNT)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'CALLS TO IDENTIFY    = ' || IDENT_COUNT; (9814)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "CALLS TO IDENTIFY    = "),
                       fixedToCharacter (getFIXED (mIDENT_COUNT)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'NUMBER OF REDUCTIONS = ' || REDUCTIONS; (9815)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "NUMBER OF REDUCTIONS = "),
                       fixedToCharacter (getFIXED (mREDUCTIONS)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'MAX STACK SIZE       = ' || MAXSP; (9816)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "MAX STACK SIZE       = "),
                       fixedToCharacter (getFIXED (mMAXSP)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'MAX IND. STACK SIZE  = ' || MAX_PTR_TOP; (9817)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "MAX IND. STACK SIZE  = "),
                       fixedToCharacter (getFIXED (mMAX_PTR_TOP)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'END IND. STACK SIZE  = ' || PTR_TOP; (9818)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "END IND. STACK SIZE  = "),
                       bitToCharacter (getBIT (16, mPTR_TOP)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'END ARRAY STACK SIZE = ' || AS_PTR; (9819)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "END ARRAY STACK SIZE = "),
                       bitToCharacter (getBIT (16, mAS_PTR)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'MAX EXT_ARRAY INDEX  = ' || EXT_ARRAY_PTR; (9820)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "MAX EXT_ARRAY INDEX  = "),
                       fixedToCharacter (getFIXED (mEXT_ARRAY_PTR)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'STATEMENT COUNT      = '||STMT_NUM-1; (9821)
  {
    descriptor_t *stringRHS;
    stringRHS
        = xsCAT (cToDescriptor (NULL, "STATEMENT COUNT      = "),
                 fixedToCharacter (xsubtract (getFIXED (mCOMM + 4 * 3), 1)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'MINOR COMPACTIFIES   = ' || COMPACTIFIES; (9822)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "MINOR COMPACTIFIES   = "),
                       bitToCharacter (getBIT (16, mCOMPACTIFIES)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'MAJOR COMPACTIFIES   = ' || COMPACTIFIES(1); (9823)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "MAJOR COMPACTIFIES   = "),
                       bitToCharacter (getBIT (16, mCOMPACTIFIES + 2 * 1)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'REALLOCATIONS        = '|| REALLOCATIONS; (9824)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "REALLOCATIONS        = "),
                       bitToCharacter (getBIT (16, mREALLOCATIONS)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'MAX NESTING DEPTH    = ' || MAXNEST; (9825)
  {
    descriptor_t *stringRHS;
    stringRHS = xsCAT (cToDescriptor (NULL, "MAX NESTING DEPTH    = "),
                       fixedToCharacter (getFIXED (mMAXNEST)));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // OUTPUT = 'FREE STRING AREA     = ' || FREELIMIT - FREEBASE; (9826)
  {
    descriptor_t *stringRHS;
    stringRHS
        = xsCAT (cToDescriptor (NULL, "FREE STRING AREA     = "),
                 fixedToCharacter (xsubtract (FREELIMIT (), FREEBASE ())));
    OUTPUT (0, stringRHS);
    stringRHS->inUse = 0;
  }
  // DOUBLE_SPACE; (9827)
  {
    descriptor_t *stringRHS;
    stringRHS = getCHARACTER (mDOUBLE);
    OUTPUT (1, stringRHS);
    stringRHS->inUse = 0;
  }
  {
    reentryGuard = 0;
    return 0;
  }
}
