/*
  File resetAllReentryGuards.c was generated by XCOM-I, 2024-08-09 12:39:13.
*/

#include "runtimeC.h"

void
resetAllReentryGuards(void) {
  _SPMANERR(1);
  _SPACE_ROUND(1);
  _ACTIVE_DESCRIPTORS(1);
  _CHECK_FOR_THEFT(1);
  _FREEBLOCK_CHECK(1);
  _UNUSED_BYTES(1);
  _MOVE_WORDS(1);
  _SQUASH_RECORDS(1);
  _PREV_FREEBLOCK(1);
  _PREV_RECORD(1);
  _ATTACH_BLOCK(1);
  _ATTACH_RECORD(1);
  _DETACH_RECORD(1);
  _REDUCE_BLOCK(1);
  _RETURN_TO_FREESTRING(1);
  _RECORD_FREE(1);
  _RETURN_UNUSED(1);
  _TAKE_BACK(1);
  COMPACTIFY(1);
  _STEAL(1);
  _MOVE_RECS(1);
  _FIND_FREE(1);
  _INCREASE_RECORD(1);
  _GET_SPACE(1);
  _HOW_MUCH(1);
  _ALLOCATE_SPACE(1);
  _RECORD_CONSTANT(1);
  _NEEDMORE_SPACE(1);
  RECORD_LINK(1);
  pRJUST(1);
  HEX(1);
  FORMAT_HALMAT(1);
  FORMAT_AUXMAT(1);
  PRINT_TIME(1);
  PRINT_DATE_AND_TIME(1);
  PRINT_PHASE_HEADER(1);
  PRINT_SUMMARY(1);
  PRETTY_PRINT_MAT(1);
  OUTPUT_LIST(1);
  OUTPUT_SYT_MAP(1);
  OUTPUT_VAC_MAP(1);
  TRACE_MSG(1);
  PAD(1);
  CHAR_INDEX(1);
  DOWNGRADE_SUMMARY(1);
  COMMON_ERRORS(1);
  ERRORS(1);
  NEW_HALMAT_BLOCK(1);
  NEW_SYT_REF_FRAME(1);
  FREE_SYT_REF_FRAME(1);
  NEW_VAC_REF_FRAME(1);
  FREE_VAC_REF_FRAME(1);
  NEW_ZERO_SYT_REF_FRAME(1);
  NEW_ZERO_VAC_REF_FRAME(1);
  MERGE_SYT_REF_FRAMES(1);
  MERGE_VAC_REF_FRAMES(1);
  COPY_SYT_REF_FRAME(1);
  COPY_VAC_REF_FRAME(1);
  PASS_BACK_SYT_REFS(1);
  PASS_BACK_VAC_REFS(1);
  GET_FREE_CELL(1);
  LIST(1);
  LINK_CELL_AREA(1);
  REINITIALIZE(1);
  INITIALIZE(1);
  INCR_STACK_PTR(1);
  DECR_STACK_PTR(1);
  PASS1(1);
  PASS2(1);
  _FREEBLOCK_CHECKxADDRESS_CHECK(1);
  _FREEBLOCK_CHECKxBLKPROC(1);
  _ATTACH_BLOCKxJOIN(1);
  COMPACTIFYxADD_DESC(1);
  PRETTY_PRINT_MATxTEST_FOR_SKIP(1);
  INITIALIZExSHRINK_SYT_SIZE(1);
  INITIALIZExSHRINK_SYT_SIZExREFERENCED(1);
  PASS1xDECODE_HALRATOR(1);
  PASS1xDECODE_HALRAND(1);
  PASS1xSET_DEBUG_SWITCH(1);
  PASS1xCOMPUTE_NOOSE(1);
  PASS1xADD_UVC(1);
  PASS1xSEARCH_FOR_REF(1);
  PASS1xDUMP_STACK(1);
  PASS1xADD_TO_VAC_BOUNDS(1);
  PASS1xSET_RAND_NOOSE(1);
  PASS1xSET_ASN_NOOSE(1);
  PASS1xSET_SIMP_NOOSE(1);
  PASS1xZAPPER(1);
  PASS1xFLUSH_INFO(1);
  PASS1xHANDLE_SIMP_NOOSE(1);
  PASS1xHANDLE_SIMP_OR_ASN_NOOSE(1);
  PASS1xSTACK_ERROR(1);
  PASS1xPUSH_BLOCK_FRAME(1);
  PASS1xPOP_BLOCK_FRAME(1);
  PASS1xPUSH_CB_FRAME(1);
  PASS1xPOP_CB_FRAME(1);
  PASS1xPUSH_FIRST_CASE_FRAME(1);
  PASS1xPUSH_CASE_FRAME(1);
  PASS1xPOP_CASE_FRAME(1);
  PASS1xCLASS_0(1);
  PASS1xCLASS_1(1);
  PASS1xCLASS_2(1);
  PASS1xCLASS_3(1);
  PASS1xCLASS_4(1);
  PASS1xCLASS_5(1);
  PASS1xCLASS_6(1);
  PASS1xCLASS_7(1);
  PASS1xSET_RAND_NOOSExRET_MIN_NOOSE(1);
  PASS1xSET_RAND_NOOSExSET_MIN_NOOSE(1);
  PASS1xSET_RAND_NOOSExINTERVENING_CB(1);
  PASS1xSET_RAND_NOOSExMARK_SYT_CASE(1);
  PASS1xSET_RAND_NOOSExMARK_SYT_REF(1);
  PASS1xSET_RAND_NOOSExMARK_SYT_UVCS(1);
  PASS1xSET_RAND_NOOSExMARK_VAC_CASE(1);
  PASS1xSET_RAND_NOOSExMARK_VAC_REF(1);
  PASS1xSET_RAND_NOOSExMARK_VAC_UVCS(1);
  PASS1xSET_RAND_NOOSExMARK_CASE_LIST_PTRS(1);
  PASS1xCLASS_0xCLASS_00(1);
  PASS1xCLASS_0xCLASS_01(1);
  PASS1xCLASS_0xCLASS_02(1);
  PASS1xCLASS_0xCLASS_03(1);
  PASS1xCLASS_0xCLASS_04(1);
  PASS1xCLASS_0xCLASS_05(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGET(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGETxDECODE_HALRAND(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGETxDECODE_HALRATOR(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGETxTARGET_ERROR(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGETxMARK_TARGET(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGETxCSE_STOP(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_THIS_RATOR(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDS(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGETxCOMMUTATIVE_RATOR(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_THIS_RATORxGET_NEXT_RATOR(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxADD_TO_NODES(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxGET_A_NODE(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxDECODE_HALRAND(1);
  PASS1xCLASS_0xCLASS_04xGEN_TARGETxSTOP_CONDSxDECODE_HALRATOR(1);
  PASS2xPRINT_AUXMAT_LINE(1);
  PASS2xGEN_AUXRATOR(1);
  PASS2xGEN_AUXRAND(1);
  PASS2xGEN_NOOSE(1);
  PASS2xGEN_XREC(1);
  PASS2xGEN_TARGET(1);
  PASS2xGEN_AUXMAT_END(1);
  PASS2xGEN_CASE_LIST(1);
  PASS2xGEN_SNCS(1);
  PASS2xPASS2_DISPATCHER(1);
}
