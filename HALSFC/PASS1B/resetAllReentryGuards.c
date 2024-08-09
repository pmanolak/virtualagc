/*
  File resetAllReentryGuards.c was generated by XCOM-I, 2024-08-09 12:40:41.
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
  _RECORD_SEAL(1);
  RECORD_LINK(1);
  DOWNGRADE_SUMMARY(1);
  PAD(1);
  CHAR_INDEX(1);
  COMMON_ERRORS(1);
  ERRORS(1);
  HEX1(1);
  DUMP_VMEM_STATUS(1);
  MOVE(1);
  ZERO_256(1);
  ZERO_CORE(1);
  DISP(1);
  PTR_LOCATE(1);
  GET_CELL(1);
  LOCATE(1);
  VMEM_INIT(1);
  MIN(1);
  MAX(1);
  GET_LITERAL(1);
  UNSPEC(1);
  BLANK(1);
  LEFT_PAD(1);
  DESCORE(1);
  HEX(1);
  I_FORMAT(1);
  SAVE_INPUT(1);
  PRINT2(1);
  OUTPUT_GROUP(1);
  SAVE_DUMP(1);
  ERROR(1);
  MAKE_FIXED_LIT(1);
  FLOATING(1);
  HASH(1);
  ENTER_XREF(1);
  SAVE_LITERAL(1);
  ICQ_TERMp(1);
  ICQ_ARRAYp(1);
  CHECK_STRUC_CONFLICTS(1);
  ENTER(1);
  ENTER_DIMS(1);
  DISCONNECT(1);
  SET_DUPL_FLAG(1);
  FINISH_MACRO_TEXT(1);
  ENTER_LAYOUT(1);
  MAKE_INCL_CELL(1);
  SET_T_LIMIT(1);
  SRNCMP(1);
  CHECK_DOWN(1);
  OUTPUT_WRITER(1);
  FINDER(1);
  SAVE_TOKEN(1);
  INTERPRET_ACCESS_FILE(1);
  DECOMPRESS(1);
  SOURCE_COMPARE(1);
  NEXT_RECORD(1);
  ORDER_OK(1);
  STREAM(1);
  COMPRESS_OUTER_REF(1);
  BLOCK_SUMMARY(1);
  SET_OUTER_REF(1);
  SET_BI_XREF(1);
  SET_XREF(1);
  SET_XREF_RORS(1);
  BUFFER_MACRO_XREF(1);
  POP_MACRO_XREF(1);
  IDENTIFY(1);
  SYT_DUMP(1);
  TIE_XREF(1);
  LIT_DUMP(1);
  PREP_LITERAL(1);
  SCAN(1);
  EMIT_EXTERNAL(1);
  SRN_UPDATE(1);
  CHARTIME(1);
  CHARDATE(1);
  PRINT_TIME(1);
  PRINT_DATE_AND_TIME(1);
  STAB_VAR(1);
  STAB_LAB(1);
  STAB_HDR(1);
  HALMAT_BLAB(1);
  HALMAT_RELOCATE(1);
  HALMAT_OUT(1);
  HALMAT(1);
  HALMAT_XNOP(1);
  HALMAT_BACKUP(1);
  HALMAT_POP(1);
  HALMAT_PIP(1);
  HALMAT_TUPLE(1);
  HALMAT_FIX_PIPp(1);
  HALMAT_FIX_POPTAG(1);
  HALMAT_FIX_PIPTAGS(1);
  EMIT_SMRK(1);
  EMIT_PUSH_DO(1);
  PUSH_INDIRECT(1);
  LABEL_MATCH(1);
  UNBRANCHABLE(1);
  SETUP_VAC(1);
  VECTOR_COMPARE(1);
  MATRIX_COMPARE(1);
  CHECK_ARRAYNESS(1);
  UNARRAYED_INTEGER(1);
  UNARRAYED_SCALAR(1);
  UNARRAYED_SIMPLE(1);
  CHECK_EVENT_EXP(1);
  PROCESS_CHECK(1);
  CHECK_ASSIGN_CONTEXT(1);
  ERROR_SUB(1);
  MATCH_SIMPLES(1);
  READ_ALL_TYPE(1);
  STRUCTURE_COMPARE(1);
  PUSH_FCN_STACK(1);
  UPDATE_BLOCK_CHECK(1);
  ARITH_LITERAL(1);
  PREC_SCALE(1);
  BIT_LITERAL(1);
  CHAR_LITERAL(1);
  MATCH_ARITH(1);
  LIT_RESULT_TYPE(1);
  ADD_AND_SUBTRACT(1);
  MULTIPLY_SYNTHESIZE(1);
  IORS(1);
  EMIT_ARRAYNESS(1);
  SAVE_ARRAYNESS(1);
  RESET_ARRAYNESS(1);
  ARITH_TO_CHAR(1);
  GET_ARRAYNESS(1);
  NAME_COMPARE(1);
  KILL_NAME(1);
  COPINESS(1);
  NAME_ARRAYNESS(1);
  CHECK_NAMING(1);
  MATCH_ARRAYNESS(1);
  STRUCTURE_FCN(1);
  SETUP_NO_ARG_FCN(1);
  START_NORMAL_FCN(1);
  GET_FCN_PARM(1);
  SETUP_CALL_ARG(1);
  ARITH_SHAPER_SUB(1);
  CHECK_SUBSCRIPT(1);
  REDUCE_SUBSCRIPT(1);
  AST_STACKER(1);
  SLIP_SUBSCRIPT(1);
  ATTACH_SUB_COMPONENT(1);
  ATTACH_SUB_ARRAY(1);
  ATTACH_SUB_STRUCTURE(1);
  ATTACH_SUBSCRIPT(1);
  EMIT_SUBSCRIPT(1);
  END_ANY_FCN(1);
  END_SUBBIT_FCN(1);
  GET_ICQ(1);
  ICQ_ARRAYNESS_OUTPUT(1);
  ICQ_CHECK_TYPE(1);
  ICQ_OUTPUT(1);
  HOW_TO_INIT_ARGS(1);
  HALMAT_INIT_CONST(1);
  COMPARE(1);
  CHECK_CONSISTENCY(1);
  CHECK_CONFLICTS(1);
  CHECK_EVENT_CONFLICTS(1);
  SET_SYT_ENTRIES(1);
  GET_SUBSET(1);
  INITIALIZATION(1);
  CHECK_IMPLICIT_T(1);
  CALL_SCAN(1);
  DUMPIT(1);
  STACK_DUMP(1);
  SET_LABEL_TYPE(1);
  ASSOCIATE(1);
  SET_BLOCK_SRN(1);
  SYNTHESIZE(1);
  CHECK_TOKEN(1);
  RECOVER(1);
  COMPILATION_LOOP(1);
  ERROR_SUMMARY(1);
  PRINT_SUMMARY(1);
  _FREEBLOCK_CHECKxADDRESS_CHECK(1);
  _FREEBLOCK_CHECKxBLKPROC(1);
  _ATTACH_BLOCKxJOIN(1);
  COMPACTIFYxADD_DESC(1);
  PTR_LOCATExSAVE_PTR_STATE(1);
  PTR_LOCATExPAGING_STRATEGY(1);
  PTR_LOCATExBAD_PTR(1);
  OUTPUT_WRITERxERROR_PRINT(1);
  OUTPUT_WRITERxATTACH(1);
  OUTPUT_WRITERxEXPAND(1);
  OUTPUT_WRITERxMATCH(1);
  OUTPUT_WRITERxSKIP_REPL(1);
  OUTPUT_WRITERxCHECK_FOR_FUNC(1);
  OUTPUT_WRITERxRESET(1);
  OUTPUT_WRITERxPRINT_TEXT(1);
  OUTPUT_WRITERxATTACHxADD(1);
  OUTPUT_WRITERxEXPANDxCOMMENT_BRACKET(1);
  SAVE_TOKENxOUTPUT_STACK_RELOCATE(1);
  INTERPRET_ACCESS_FILExACCESS_ERROR(1);
  INTERPRET_ACCESS_FILExRESET_ACCESS_FLAG(1);
  INTERPRET_ACCESS_FILExLOOKUP(1);
  INTERPRET_ACCESS_FILExADVANCE_CP(1);
  INTERPRET_ACCESS_FILExNEXT_TOKEN(1);
  STREAMxPRINT_COMMENT(1);
  STREAMxD_TOKEN(1);
  STREAMxINCLUDE_SDF(1);
  STREAMxINCLUDE_OK(1);
  STREAMxPROCESS_COMMENT(1);
  STREAMxSTACK_RETURN_CHAR(1);
  STREAMxREAD_CARD(1);
  STREAMxSCAN_CARD(1);
  STREAMxCOMP(1);
  STREAMxGET_GROUP(1);
  STREAMxCHOP(1);
  STREAMxSTACK(1);
  STREAMxBUILD_XSCRIPTS(1);
  STREAMxMACRO_DIAGNOSTICS(1);
  STREAMxINCLUDE_SDFxFIND(1);
  STREAMxINCLUDE_SDFxDUPLICATE_NAME(1);
  STREAMxINCLUDE_SDFxSET_SYT_FLAGS(1);
  STREAMxINCLUDE_SDFxSET_TYPE_AND_LEN(1);
  STREAMxINCLUDE_SDFxENTER_SDF_VAR(1);
  STREAMxINCLUDE_SDFxENTER_SDF_LABEL(1);
  STREAMxINCLUDE_SDFxENTER_SDF_TEMPLATE(1);
  STREAMxINCLUDE_SDFxENTER_SDF_MACRO(1);
  STREAMxINCLUDE_SDFxENTER_SDF_THING(1);
  STREAMxINCLUDE_SDFxENTER_COMSUB_ARGS(1);
  STREAMxINCLUDE_SDFxENTER_COMPOOL_VARS(1);
  STREAMxINCLUDE_SDFxSDF_FOUND(1);
  STREAMxINCLUDE_SDFxSET_SYT_FLAGSxSDF_INITIAL_CHECK(1);
  STREAMxPROCESS_COMMENTxCHAR_VALUE(1);
  STREAMxPROCESS_COMMENTxCOPY_TO_8(1);
  BLOCK_SUMMARYxINDIRECT(1);
  BLOCK_SUMMARYxISSUE_HEADER(1);
  BLOCK_SUMMARYxOUTPUT_IDENT(1);
  BLOCK_SUMMARYxCHECK_IDENT(1);
  BLOCK_SUMMARYxOUT_BLOCK_SUMMARY(1);
  SYT_DUMPxPRINT_SYMBOL_HEADER(1);
  SYT_DUMPxPRINT_VAR_NAMES(1);
  SYT_DUMPxENTER_SORT(1);
  SYT_DUMPxCHECK_AND_ENTER(1);
  SYT_DUMPxADD_ATTR(1);
  SYT_DUMPxMACRO_TEXT_RESET(1);
  SYT_DUMPxADD_XREFS(1);
  SYT_DUMPxSTORE_BI_XREF(1);
  SYT_DUMPxTRUNCATE(1);
  SCANxCHAR_OP_CHECK(1);
  SCANxBUILD_BCD(1);
  SCANxBUILD_INTERNAL_BCD(1);
  SCANxPARAMETER_PROCESSING(1);
  SCANxEND_OF_MACRO(1);
  SCANxBUILD_COMMENT(1);
  SCANxID_LOOP(1);
  SCANxPARM_FOUND(1);
  SCANxPUSH_MACRO(1);
  EMIT_EXTERNALxEX_WRITE(1);
  EMIT_EXTERNALxADD_CHAR(1);
  STAB_VARxSTAB_STACKER(1);
  HALMAT_RELOCATExMOVE_BLOCK(1);
  ERROR_SUBxERROR_SS_FIX(1);
  REDUCE_SUBSCRIPTxSTEPPER(1);
  END_ANY_FCNxBI_COMPILE_TIME(1);
  HALMAT_INIT_CONSTxMULTI_VALUED(1);
  HALMAT_INIT_CONSTxROUND_SCALAR(1);
  GET_SUBSETxVALUE(1);
  GET_SUBSETxGET_TOKEN(1);
  GET_SUBSETxSUBSET_ERROR(1);
  DUMPITxFORM_UP(1);
  SYNTHESIZExSET_INIT(1);
  SYNTHESIZExTEMPL_INITIAL_CHECK(1);
  COMPILATION_LOOPxADD_TO_STACK(1);
}
