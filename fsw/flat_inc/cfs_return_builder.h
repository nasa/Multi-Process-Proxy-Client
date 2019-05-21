#ifndef CFS_RETURN_BUILDER_H
#define CFS_RETURN_BUILDER_H

/* Generated by flatcc 0.6.0-pre FlatBuffers schema compiler for C by dvide.com */

#ifndef CFS_RETURN_READER_H
#include "cfs_return_reader.h"
#endif
#ifndef FLATBUFFERS_COMMON_BUILDER_H
#include "flatbuffers_common_builder.h"
#endif
#ifndef COMMON_BUILDER_H
#include "common_builder.h"
#endif
#include "flatcc/flatcc_prologue.h"
#ifndef flatbuffers_identifier
#define flatbuffers_identifier 0
#endif
#ifndef flatbuffers_extension
#define flatbuffers_extension ".bin"
#endif

typedef flatbuffers_union_ref_t cFS_Return_PointerReturn_union_ref_t;
typedef flatbuffers_union_vec_ref_t cFS_Return_PointerReturn_union_vec_ref_t;
static cFS_Return_PointerReturn_union_ref_t cFS_Return_PointerReturn_clone(flatbuffers_builder_t *B, cFS_Return_PointerReturn_union_t t);
typedef flatbuffers_union_ref_t cFS_Return_FuncReturn_union_ref_t;
typedef flatbuffers_union_vec_ref_t cFS_Return_FuncReturn_union_vec_ref_t;
static cFS_Return_FuncReturn_union_ref_t cFS_Return_FuncReturn_clone(flatbuffers_builder_t *B, cFS_Return_FuncReturn_union_t t);

static const flatbuffers_voffset_t __cFS_Return_Empty_required[] = { 0 };
typedef flatbuffers_ref_t cFS_Return_Empty_ref_t;
static cFS_Return_Empty_ref_t cFS_Return_Empty_clone(flatbuffers_builder_t *B, cFS_Return_Empty_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_Return_Empty, 0)

static const flatbuffers_voffset_t __cFS_Return_Integer32_required[] = { 0 };
typedef flatbuffers_ref_t cFS_Return_Integer32_ref_t;
static cFS_Return_Integer32_ref_t cFS_Return_Integer32_clone(flatbuffers_builder_t *B, cFS_Return_Integer32_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_Return_Integer32, 1)

static const flatbuffers_voffset_t __cFS_Return_Integer16_required[] = { 0 };
typedef flatbuffers_ref_t cFS_Return_Integer16_ref_t;
static cFS_Return_Integer16_ref_t cFS_Return_Integer16_clone(flatbuffers_builder_t *B, cFS_Return_Integer16_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_Return_Integer16, 1)

static const flatbuffers_voffset_t __cFS_Return_UnInteger32_required[] = { 0 };
typedef flatbuffers_ref_t cFS_Return_UnInteger32_ref_t;
static cFS_Return_UnInteger32_ref_t cFS_Return_UnInteger32_clone(flatbuffers_builder_t *B, cFS_Return_UnInteger32_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_Return_UnInteger32, 1)

static const flatbuffers_voffset_t __cFS_Return_ReturnData_required[] = { 0 };
typedef flatbuffers_ref_t cFS_Return_ReturnData_ref_t;
static cFS_Return_ReturnData_ref_t cFS_Return_ReturnData_clone(flatbuffers_builder_t *B, cFS_Return_ReturnData_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_Return_ReturnData, 4)

#define __cFS_Return_Empty_formal_args 
#define __cFS_Return_Empty_call_args 
static inline cFS_Return_Empty_ref_t cFS_Return_Empty_create(flatbuffers_builder_t *B __cFS_Return_Empty_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_Return_Empty, cFS_Return_Empty_identifier, cFS_Return_Empty_type_identifier)

#define __cFS_Return_Integer32_formal_args , int32_t v0
#define __cFS_Return_Integer32_call_args , v0
static inline cFS_Return_Integer32_ref_t cFS_Return_Integer32_create(flatbuffers_builder_t *B __cFS_Return_Integer32_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_Return_Integer32, cFS_Return_Integer32_identifier, cFS_Return_Integer32_type_identifier)

#define __cFS_Return_Integer16_formal_args , int16_t v0
#define __cFS_Return_Integer16_call_args , v0
static inline cFS_Return_Integer16_ref_t cFS_Return_Integer16_create(flatbuffers_builder_t *B __cFS_Return_Integer16_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_Return_Integer16, cFS_Return_Integer16_identifier, cFS_Return_Integer16_type_identifier)

#define __cFS_Return_UnInteger32_formal_args , uint32_t v0
#define __cFS_Return_UnInteger32_call_args , v0
static inline cFS_Return_UnInteger32_ref_t cFS_Return_UnInteger32_create(flatbuffers_builder_t *B __cFS_Return_UnInteger32_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_Return_UnInteger32, cFS_Return_UnInteger32_identifier, cFS_Return_UnInteger32_type_identifier)

#define __cFS_Return_ReturnData_formal_args , cFS_Return_FuncReturn_union_ref_t v1, cFS_Return_PointerReturn_union_ref_t v3
#define __cFS_Return_ReturnData_call_args , v1, v3
static inline cFS_Return_ReturnData_ref_t cFS_Return_ReturnData_create(flatbuffers_builder_t *B __cFS_Return_ReturnData_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_Return_ReturnData, cFS_Return_ReturnData_identifier, cFS_Return_ReturnData_type_identifier)

static inline cFS_Return_PointerReturn_union_ref_t cFS_Return_PointerReturn_as_NONE()
{ cFS_Return_PointerReturn_union_ref_t uref; uref.type = cFS_Return_PointerReturn_NONE; uref.value = 0; return uref; }
static inline cFS_Return_PointerReturn_union_ref_t cFS_Return_PointerReturn_as_Empty(cFS_Return_Empty_ref_t ref)
{ cFS_Return_PointerReturn_union_ref_t uref; uref.type = cFS_Return_PointerReturn_Empty; uref.value = ref; return uref; }
static inline cFS_Return_PointerReturn_union_ref_t cFS_Return_PointerReturn_as_UnInteger32(cFS_Return_UnInteger32_ref_t ref)
{ cFS_Return_PointerReturn_union_ref_t uref; uref.type = cFS_Return_PointerReturn_UnInteger32; uref.value = ref; return uref; }
__flatbuffers_build_union_vector(flatbuffers_, cFS_Return_PointerReturn)

static cFS_Return_PointerReturn_union_ref_t cFS_Return_PointerReturn_clone(flatbuffers_builder_t *B, cFS_Return_PointerReturn_union_t u)
{
    switch (u.type) {
    case 1: return cFS_Return_PointerReturn_as_Empty(cFS_Return_Empty_clone(B, (cFS_Return_Empty_table_t)u.value));
    case 2: return cFS_Return_PointerReturn_as_UnInteger32(cFS_Return_UnInteger32_clone(B, (cFS_Return_UnInteger32_table_t)u.value));
    default: return cFS_Return_PointerReturn_as_NONE();
    }
}

static inline cFS_Return_FuncReturn_union_ref_t cFS_Return_FuncReturn_as_NONE()
{ cFS_Return_FuncReturn_union_ref_t uref; uref.type = cFS_Return_FuncReturn_NONE; uref.value = 0; return uref; }
static inline cFS_Return_FuncReturn_union_ref_t cFS_Return_FuncReturn_as_Integer32(cFS_Return_Integer32_ref_t ref)
{ cFS_Return_FuncReturn_union_ref_t uref; uref.type = cFS_Return_FuncReturn_Integer32; uref.value = ref; return uref; }
static inline cFS_Return_FuncReturn_union_ref_t cFS_Return_FuncReturn_as_Integer16(cFS_Return_Integer16_ref_t ref)
{ cFS_Return_FuncReturn_union_ref_t uref; uref.type = cFS_Return_FuncReturn_Integer16; uref.value = ref; return uref; }
static inline cFS_Return_FuncReturn_union_ref_t cFS_Return_FuncReturn_as_UnInteger32(cFS_Return_UnInteger32_ref_t ref)
{ cFS_Return_FuncReturn_union_ref_t uref; uref.type = cFS_Return_FuncReturn_UnInteger32; uref.value = ref; return uref; }
static inline cFS_Return_FuncReturn_union_ref_t cFS_Return_FuncReturn_as_cFETime(cFETime_ref_t ref)
{ cFS_Return_FuncReturn_union_ref_t uref; uref.type = cFS_Return_FuncReturn_cFETime; uref.value = ref; return uref; }
__flatbuffers_build_union_vector(flatbuffers_, cFS_Return_FuncReturn)

static cFS_Return_FuncReturn_union_ref_t cFS_Return_FuncReturn_clone(flatbuffers_builder_t *B, cFS_Return_FuncReturn_union_t u)
{
    switch (u.type) {
    case 1: return cFS_Return_FuncReturn_as_Integer32(cFS_Return_Integer32_clone(B, (cFS_Return_Integer32_table_t)u.value));
    case 2: return cFS_Return_FuncReturn_as_Integer16(cFS_Return_Integer16_clone(B, (cFS_Return_Integer16_table_t)u.value));
    case 3: return cFS_Return_FuncReturn_as_UnInteger32(cFS_Return_UnInteger32_clone(B, (cFS_Return_UnInteger32_table_t)u.value));
    case 4: return cFS_Return_FuncReturn_as_cFETime(cFETime_clone(B, (cFETime_table_t)u.value));
    default: return cFS_Return_FuncReturn_as_NONE();
    }
}


static inline cFS_Return_Empty_ref_t cFS_Return_Empty_create(flatbuffers_builder_t *B __cFS_Return_Empty_formal_args)
{
    if (cFS_Return_Empty_start(B)) {
        return 0;
    }
    return cFS_Return_Empty_end(B);
}

static cFS_Return_Empty_ref_t cFS_Return_Empty_clone(flatbuffers_builder_t *B, cFS_Return_Empty_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_Return_Empty_start(B)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_Return_Empty_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, cFS_Return_Integer32_integer32, flatbuffers_int32, int32_t, 4, 4, INT32_C(0), cFS_Return_Integer32)

static inline cFS_Return_Integer32_ref_t cFS_Return_Integer32_create(flatbuffers_builder_t *B __cFS_Return_Integer32_formal_args)
{
    if (cFS_Return_Integer32_start(B)
        || cFS_Return_Integer32_integer32_add(B, v0)) {
        return 0;
    }
    return cFS_Return_Integer32_end(B);
}

static cFS_Return_Integer32_ref_t cFS_Return_Integer32_clone(flatbuffers_builder_t *B, cFS_Return_Integer32_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_Return_Integer32_start(B)
        || cFS_Return_Integer32_integer32_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_Return_Integer32_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, cFS_Return_Integer16_integer16, flatbuffers_int16, int16_t, 2, 2, INT16_C(0), cFS_Return_Integer16)

static inline cFS_Return_Integer16_ref_t cFS_Return_Integer16_create(flatbuffers_builder_t *B __cFS_Return_Integer16_formal_args)
{
    if (cFS_Return_Integer16_start(B)
        || cFS_Return_Integer16_integer16_add(B, v0)) {
        return 0;
    }
    return cFS_Return_Integer16_end(B);
}

static cFS_Return_Integer16_ref_t cFS_Return_Integer16_clone(flatbuffers_builder_t *B, cFS_Return_Integer16_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_Return_Integer16_start(B)
        || cFS_Return_Integer16_integer16_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_Return_Integer16_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, cFS_Return_UnInteger32_unInteger32, flatbuffers_uint32, uint32_t, 4, 4, UINT32_C(0), cFS_Return_UnInteger32)

static inline cFS_Return_UnInteger32_ref_t cFS_Return_UnInteger32_create(flatbuffers_builder_t *B __cFS_Return_UnInteger32_formal_args)
{
    if (cFS_Return_UnInteger32_start(B)
        || cFS_Return_UnInteger32_unInteger32_add(B, v0)) {
        return 0;
    }
    return cFS_Return_UnInteger32_end(B);
}

static cFS_Return_UnInteger32_ref_t cFS_Return_UnInteger32_clone(flatbuffers_builder_t *B, cFS_Return_UnInteger32_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_Return_UnInteger32_start(B)
        || cFS_Return_UnInteger32_unInteger32_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_Return_UnInteger32_end(B));
}

__flatbuffers_build_union_field(1, flatbuffers_, cFS_Return_ReturnData_retval, cFS_Return_FuncReturn, cFS_Return_ReturnData)
__flatbuffers_build_union_table_value_field(flatbuffers_, cFS_Return_ReturnData_retval, cFS_Return_FuncReturn, Integer32, cFS_Return_Integer32)
__flatbuffers_build_union_table_value_field(flatbuffers_, cFS_Return_ReturnData_retval, cFS_Return_FuncReturn, Integer16, cFS_Return_Integer16)
__flatbuffers_build_union_table_value_field(flatbuffers_, cFS_Return_ReturnData_retval, cFS_Return_FuncReturn, UnInteger32, cFS_Return_UnInteger32)
__flatbuffers_build_union_table_value_field(flatbuffers_, cFS_Return_ReturnData_retval, cFS_Return_FuncReturn, cFETime, cFETime)
__flatbuffers_build_union_field(3, flatbuffers_, cFS_Return_ReturnData_output, cFS_Return_PointerReturn, cFS_Return_ReturnData)
__flatbuffers_build_union_table_value_field(flatbuffers_, cFS_Return_ReturnData_output, cFS_Return_PointerReturn, Empty, cFS_Return_Empty)
__flatbuffers_build_union_table_value_field(flatbuffers_, cFS_Return_ReturnData_output, cFS_Return_PointerReturn, UnInteger32, cFS_Return_UnInteger32)

static inline cFS_Return_ReturnData_ref_t cFS_Return_ReturnData_create(flatbuffers_builder_t *B __cFS_Return_ReturnData_formal_args)
{
    if (cFS_Return_ReturnData_start(B)
        || cFS_Return_ReturnData_retval_add_value(B, v1)
        || cFS_Return_ReturnData_output_add_value(B, v3)
        || cFS_Return_ReturnData_retval_add_type(B, v1.type)
        || cFS_Return_ReturnData_output_add_type(B, v3.type)) {
        return 0;
    }
    return cFS_Return_ReturnData_end(B);
}

static cFS_Return_ReturnData_ref_t cFS_Return_ReturnData_clone(flatbuffers_builder_t *B, cFS_Return_ReturnData_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_Return_ReturnData_start(B)
        || cFS_Return_ReturnData_retval_pick(B, t)
        || cFS_Return_ReturnData_output_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_Return_ReturnData_end(B));
}

#include "flatcc/flatcc_epilogue.h"
#endif /* CFS_RETURN_BUILDER_H */
