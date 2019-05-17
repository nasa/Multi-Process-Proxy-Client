#ifndef CFS_API_BUILDER_H
#define CFS_API_BUILDER_H

/* Generated by flatcc 0.6.0-pre FlatBuffers schema compiler for C by dvide.com */

#ifndef CFS_API_READER_H
#include "cfs_api_reader.h"
#endif
#ifndef FLATBUFFERS_COMMON_BUILDER_H
#include "flatbuffers_common_builder.h"
#endif
#include "flatcc/flatcc_prologue.h"
#ifndef flatbuffers_identifier
#define flatbuffers_identifier 0
#endif
#ifndef flatbuffers_extension
#define flatbuffers_extension ".bin"
#endif

typedef flatbuffers_union_ref_t cFS_API_Function_union_ref_t;
typedef flatbuffers_union_vec_ref_t cFS_API_Function_union_vec_ref_t;
static cFS_API_Function_union_ref_t cFS_API_Function_clone(flatbuffers_builder_t *B, cFS_API_Function_union_t t);

static const flatbuffers_voffset_t __cFS_API_RunLoop_required[] = { 0 };
typedef flatbuffers_ref_t cFS_API_RunLoop_ref_t;
static cFS_API_RunLoop_ref_t cFS_API_RunLoop_clone(flatbuffers_builder_t *B, cFS_API_RunLoop_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_API_RunLoop, 1)

static const flatbuffers_voffset_t __cFS_API_PerfLogAdd_required[] = { 0 };
typedef flatbuffers_ref_t cFS_API_PerfLogAdd_ref_t;
static cFS_API_PerfLogAdd_ref_t cFS_API_PerfLogAdd_clone(flatbuffers_builder_t *B, cFS_API_PerfLogAdd_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_API_PerfLogAdd, 2)

static const flatbuffers_voffset_t __cFS_API_RegisterApp_required[] = { 0 };
typedef flatbuffers_ref_t cFS_API_RegisterApp_ref_t;
static cFS_API_RegisterApp_ref_t cFS_API_RegisterApp_clone(flatbuffers_builder_t *B, cFS_API_RegisterApp_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_API_RegisterApp, 0)

static const flatbuffers_voffset_t __cFS_API_ExitApp_required[] = { 0 };
typedef flatbuffers_ref_t cFS_API_ExitApp_ref_t;
static cFS_API_ExitApp_ref_t cFS_API_ExitApp_clone(flatbuffers_builder_t *B, cFS_API_ExitApp_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_API_ExitApp, 1)

static const flatbuffers_voffset_t __cFS_API_SendEvent_required[] = { 0 };
typedef flatbuffers_ref_t cFS_API_SendEvent_ref_t;
static cFS_API_SendEvent_ref_t cFS_API_SendEvent_clone(flatbuffers_builder_t *B, cFS_API_SendEvent_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_API_SendEvent, 3)

static const flatbuffers_voffset_t __cFS_API_SendEventWithAppID_required[] = { 0 };
typedef flatbuffers_ref_t cFS_API_SendEventWithAppID_ref_t;
static cFS_API_SendEventWithAppID_ref_t cFS_API_SendEventWithAppID_clone(flatbuffers_builder_t *B, cFS_API_SendEventWithAppID_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_API_SendEventWithAppID, 4)

static const flatbuffers_voffset_t __cFS_API_Filter_required[] = { 0 };
typedef flatbuffers_ref_t cFS_API_Filter_ref_t;
static cFS_API_Filter_ref_t cFS_API_Filter_clone(flatbuffers_builder_t *B, cFS_API_Filter_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_API_Filter, 2)

static const flatbuffers_voffset_t __cFS_API_Register_required[] = { 0 };
typedef flatbuffers_ref_t cFS_API_Register_ref_t;
static cFS_API_Register_ref_t cFS_API_Register_clone(flatbuffers_builder_t *B, cFS_API_Register_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_API_Register, 3)

static const flatbuffers_voffset_t __cFS_API_RemoteCall_required[] = { 0 };
typedef flatbuffers_ref_t cFS_API_RemoteCall_ref_t;
static cFS_API_RemoteCall_ref_t cFS_API_RemoteCall_clone(flatbuffers_builder_t *B, cFS_API_RemoteCall_table_t t);
__flatbuffers_build_table(flatbuffers_, cFS_API_RemoteCall, 2)

#define __cFS_API_RunLoop_formal_args , uint32_t v0
#define __cFS_API_RunLoop_call_args , v0
static inline cFS_API_RunLoop_ref_t cFS_API_RunLoop_create(flatbuffers_builder_t *B __cFS_API_RunLoop_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_API_RunLoop, cFS_API_RunLoop_identifier, cFS_API_RunLoop_type_identifier)

#define __cFS_API_PerfLogAdd_formal_args , uint32_t v0, uint32_t v1
#define __cFS_API_PerfLogAdd_call_args , v0, v1
static inline cFS_API_PerfLogAdd_ref_t cFS_API_PerfLogAdd_create(flatbuffers_builder_t *B __cFS_API_PerfLogAdd_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_API_PerfLogAdd, cFS_API_PerfLogAdd_identifier, cFS_API_PerfLogAdd_type_identifier)

#define __cFS_API_RegisterApp_formal_args 
#define __cFS_API_RegisterApp_call_args 
static inline cFS_API_RegisterApp_ref_t cFS_API_RegisterApp_create(flatbuffers_builder_t *B __cFS_API_RegisterApp_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_API_RegisterApp, cFS_API_RegisterApp_identifier, cFS_API_RegisterApp_type_identifier)

#define __cFS_API_ExitApp_formal_args , uint32_t v0
#define __cFS_API_ExitApp_call_args , v0
static inline cFS_API_ExitApp_ref_t cFS_API_ExitApp_create(flatbuffers_builder_t *B __cFS_API_ExitApp_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_API_ExitApp, cFS_API_ExitApp_identifier, cFS_API_ExitApp_type_identifier)

#define __cFS_API_SendEvent_formal_args , uint16_t v0, uint16_t v1, flatbuffers_string_ref_t v2
#define __cFS_API_SendEvent_call_args , v0, v1, v2
static inline cFS_API_SendEvent_ref_t cFS_API_SendEvent_create(flatbuffers_builder_t *B __cFS_API_SendEvent_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_API_SendEvent, cFS_API_SendEvent_identifier, cFS_API_SendEvent_type_identifier)

#define __cFS_API_SendEventWithAppID_formal_args , uint16_t v0, uint16_t v1, uint32_t v2, flatbuffers_string_ref_t v3
#define __cFS_API_SendEventWithAppID_call_args , v0, v1, v2, v3
static inline cFS_API_SendEventWithAppID_ref_t cFS_API_SendEventWithAppID_create(flatbuffers_builder_t *B __cFS_API_SendEventWithAppID_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_API_SendEventWithAppID, cFS_API_SendEventWithAppID_identifier, cFS_API_SendEventWithAppID_type_identifier)

#define __cFS_API_Filter_formal_args , uint16_t v0, uint16_t v1
#define __cFS_API_Filter_call_args , v0, v1
static inline cFS_API_Filter_ref_t cFS_API_Filter_create(flatbuffers_builder_t *B __cFS_API_Filter_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_API_Filter, cFS_API_Filter_identifier, cFS_API_Filter_type_identifier)

#define __cFS_API_Register_formal_args , cFS_API_Filter_vec_ref_t v0, uint16_t v1, uint16_t v2
#define __cFS_API_Register_call_args , v0, v1, v2
static inline cFS_API_Register_ref_t cFS_API_Register_create(flatbuffers_builder_t *B __cFS_API_Register_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_API_Register, cFS_API_Register_identifier, cFS_API_Register_type_identifier)

#define __cFS_API_RemoteCall_formal_args , cFS_API_Function_union_ref_t v1
#define __cFS_API_RemoteCall_call_args , v1
static inline cFS_API_RemoteCall_ref_t cFS_API_RemoteCall_create(flatbuffers_builder_t *B __cFS_API_RemoteCall_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, cFS_API_RemoteCall, cFS_API_RemoteCall_identifier, cFS_API_RemoteCall_type_identifier)

static inline cFS_API_Function_union_ref_t cFS_API_Function_as_NONE()
{ cFS_API_Function_union_ref_t uref; uref.type = cFS_API_Function_NONE; uref.value = 0; return uref; }
static inline cFS_API_Function_union_ref_t cFS_API_Function_as_RunLoop(cFS_API_RunLoop_ref_t ref)
{ cFS_API_Function_union_ref_t uref; uref.type = cFS_API_Function_RunLoop; uref.value = ref; return uref; }
static inline cFS_API_Function_union_ref_t cFS_API_Function_as_PerfLogAdd(cFS_API_PerfLogAdd_ref_t ref)
{ cFS_API_Function_union_ref_t uref; uref.type = cFS_API_Function_PerfLogAdd; uref.value = ref; return uref; }
static inline cFS_API_Function_union_ref_t cFS_API_Function_as_RegisterApp(cFS_API_RegisterApp_ref_t ref)
{ cFS_API_Function_union_ref_t uref; uref.type = cFS_API_Function_RegisterApp; uref.value = ref; return uref; }
static inline cFS_API_Function_union_ref_t cFS_API_Function_as_ExitApp(cFS_API_ExitApp_ref_t ref)
{ cFS_API_Function_union_ref_t uref; uref.type = cFS_API_Function_ExitApp; uref.value = ref; return uref; }
static inline cFS_API_Function_union_ref_t cFS_API_Function_as_Register(cFS_API_Register_ref_t ref)
{ cFS_API_Function_union_ref_t uref; uref.type = cFS_API_Function_Register; uref.value = ref; return uref; }
static inline cFS_API_Function_union_ref_t cFS_API_Function_as_SendEvent(cFS_API_SendEvent_ref_t ref)
{ cFS_API_Function_union_ref_t uref; uref.type = cFS_API_Function_SendEvent; uref.value = ref; return uref; }
static inline cFS_API_Function_union_ref_t cFS_API_Function_as_SendEventWithAppID(cFS_API_SendEventWithAppID_ref_t ref)
{ cFS_API_Function_union_ref_t uref; uref.type = cFS_API_Function_SendEventWithAppID; uref.value = ref; return uref; }
__flatbuffers_build_union_vector(flatbuffers_, cFS_API_Function)

static cFS_API_Function_union_ref_t cFS_API_Function_clone(flatbuffers_builder_t *B, cFS_API_Function_union_t u)
{
    switch (u.type) {
    case 1: return cFS_API_Function_as_RunLoop(cFS_API_RunLoop_clone(B, (cFS_API_RunLoop_table_t)u.value));
    case 2: return cFS_API_Function_as_PerfLogAdd(cFS_API_PerfLogAdd_clone(B, (cFS_API_PerfLogAdd_table_t)u.value));
    case 3: return cFS_API_Function_as_RegisterApp(cFS_API_RegisterApp_clone(B, (cFS_API_RegisterApp_table_t)u.value));
    case 4: return cFS_API_Function_as_ExitApp(cFS_API_ExitApp_clone(B, (cFS_API_ExitApp_table_t)u.value));
    case 5: return cFS_API_Function_as_Register(cFS_API_Register_clone(B, (cFS_API_Register_table_t)u.value));
    case 6: return cFS_API_Function_as_SendEvent(cFS_API_SendEvent_clone(B, (cFS_API_SendEvent_table_t)u.value));
    case 7: return cFS_API_Function_as_SendEventWithAppID(cFS_API_SendEventWithAppID_clone(B, (cFS_API_SendEventWithAppID_table_t)u.value));
    default: return cFS_API_Function_as_NONE();
    }
}

__flatbuffers_build_scalar_field(0, flatbuffers_, cFS_API_RunLoop_ExitStatus, flatbuffers_uint32, uint32_t, 4, 4, UINT32_C(0), cFS_API_RunLoop)

static inline cFS_API_RunLoop_ref_t cFS_API_RunLoop_create(flatbuffers_builder_t *B __cFS_API_RunLoop_formal_args)
{
    if (cFS_API_RunLoop_start(B)
        || cFS_API_RunLoop_ExitStatus_add(B, v0)) {
        return 0;
    }
    return cFS_API_RunLoop_end(B);
}

static cFS_API_RunLoop_ref_t cFS_API_RunLoop_clone(flatbuffers_builder_t *B, cFS_API_RunLoop_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_API_RunLoop_start(B)
        || cFS_API_RunLoop_ExitStatus_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_API_RunLoop_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, cFS_API_PerfLogAdd_Marker, flatbuffers_uint32, uint32_t, 4, 4, UINT32_C(0), cFS_API_PerfLogAdd)
__flatbuffers_build_scalar_field(1, flatbuffers_, cFS_API_PerfLogAdd_EntryExit, flatbuffers_uint32, uint32_t, 4, 4, UINT32_C(0), cFS_API_PerfLogAdd)

static inline cFS_API_PerfLogAdd_ref_t cFS_API_PerfLogAdd_create(flatbuffers_builder_t *B __cFS_API_PerfLogAdd_formal_args)
{
    if (cFS_API_PerfLogAdd_start(B)
        || cFS_API_PerfLogAdd_Marker_add(B, v0)
        || cFS_API_PerfLogAdd_EntryExit_add(B, v1)) {
        return 0;
    }
    return cFS_API_PerfLogAdd_end(B);
}

static cFS_API_PerfLogAdd_ref_t cFS_API_PerfLogAdd_clone(flatbuffers_builder_t *B, cFS_API_PerfLogAdd_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_API_PerfLogAdd_start(B)
        || cFS_API_PerfLogAdd_Marker_pick(B, t)
        || cFS_API_PerfLogAdd_EntryExit_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_API_PerfLogAdd_end(B));
}


static inline cFS_API_RegisterApp_ref_t cFS_API_RegisterApp_create(flatbuffers_builder_t *B __cFS_API_RegisterApp_formal_args)
{
    if (cFS_API_RegisterApp_start(B)) {
        return 0;
    }
    return cFS_API_RegisterApp_end(B);
}

static cFS_API_RegisterApp_ref_t cFS_API_RegisterApp_clone(flatbuffers_builder_t *B, cFS_API_RegisterApp_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_API_RegisterApp_start(B)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_API_RegisterApp_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, cFS_API_ExitApp_ExitStatus, flatbuffers_uint32, uint32_t, 4, 4, UINT32_C(0), cFS_API_ExitApp)

static inline cFS_API_ExitApp_ref_t cFS_API_ExitApp_create(flatbuffers_builder_t *B __cFS_API_ExitApp_formal_args)
{
    if (cFS_API_ExitApp_start(B)
        || cFS_API_ExitApp_ExitStatus_add(B, v0)) {
        return 0;
    }
    return cFS_API_ExitApp_end(B);
}

static cFS_API_ExitApp_ref_t cFS_API_ExitApp_clone(flatbuffers_builder_t *B, cFS_API_ExitApp_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_API_ExitApp_start(B)
        || cFS_API_ExitApp_ExitStatus_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_API_ExitApp_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, cFS_API_SendEvent_EventID, flatbuffers_uint16, uint16_t, 2, 2, UINT16_C(0), cFS_API_SendEvent)
__flatbuffers_build_scalar_field(1, flatbuffers_, cFS_API_SendEvent_EventType, flatbuffers_uint16, uint16_t, 2, 2, UINT16_C(0), cFS_API_SendEvent)
__flatbuffers_build_string_field(2, flatbuffers_, cFS_API_SendEvent_Spec, cFS_API_SendEvent)

static inline cFS_API_SendEvent_ref_t cFS_API_SendEvent_create(flatbuffers_builder_t *B __cFS_API_SendEvent_formal_args)
{
    if (cFS_API_SendEvent_start(B)
        || cFS_API_SendEvent_Spec_add(B, v2)
        || cFS_API_SendEvent_EventID_add(B, v0)
        || cFS_API_SendEvent_EventType_add(B, v1)) {
        return 0;
    }
    return cFS_API_SendEvent_end(B);
}

static cFS_API_SendEvent_ref_t cFS_API_SendEvent_clone(flatbuffers_builder_t *B, cFS_API_SendEvent_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_API_SendEvent_start(B)
        || cFS_API_SendEvent_Spec_pick(B, t)
        || cFS_API_SendEvent_EventID_pick(B, t)
        || cFS_API_SendEvent_EventType_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_API_SendEvent_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, cFS_API_SendEventWithAppID_EventID, flatbuffers_uint16, uint16_t, 2, 2, UINT16_C(0), cFS_API_SendEventWithAppID)
__flatbuffers_build_scalar_field(1, flatbuffers_, cFS_API_SendEventWithAppID_EventType, flatbuffers_uint16, uint16_t, 2, 2, UINT16_C(0), cFS_API_SendEventWithAppID)
__flatbuffers_build_scalar_field(2, flatbuffers_, cFS_API_SendEventWithAppID_AppID, flatbuffers_uint32, uint32_t, 4, 4, UINT32_C(0), cFS_API_SendEventWithAppID)
__flatbuffers_build_string_field(3, flatbuffers_, cFS_API_SendEventWithAppID_Spec, cFS_API_SendEventWithAppID)

static inline cFS_API_SendEventWithAppID_ref_t cFS_API_SendEventWithAppID_create(flatbuffers_builder_t *B __cFS_API_SendEventWithAppID_formal_args)
{
    if (cFS_API_SendEventWithAppID_start(B)
        || cFS_API_SendEventWithAppID_AppID_add(B, v2)
        || cFS_API_SendEventWithAppID_Spec_add(B, v3)
        || cFS_API_SendEventWithAppID_EventID_add(B, v0)
        || cFS_API_SendEventWithAppID_EventType_add(B, v1)) {
        return 0;
    }
    return cFS_API_SendEventWithAppID_end(B);
}

static cFS_API_SendEventWithAppID_ref_t cFS_API_SendEventWithAppID_clone(flatbuffers_builder_t *B, cFS_API_SendEventWithAppID_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_API_SendEventWithAppID_start(B)
        || cFS_API_SendEventWithAppID_AppID_pick(B, t)
        || cFS_API_SendEventWithAppID_Spec_pick(B, t)
        || cFS_API_SendEventWithAppID_EventID_pick(B, t)
        || cFS_API_SendEventWithAppID_EventType_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_API_SendEventWithAppID_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, cFS_API_Filter_EventID, flatbuffers_uint16, uint16_t, 2, 2, UINT16_C(0), cFS_API_Filter)
__flatbuffers_build_scalar_field(1, flatbuffers_, cFS_API_Filter_Mask, flatbuffers_uint16, uint16_t, 2, 2, UINT16_C(0), cFS_API_Filter)

static inline cFS_API_Filter_ref_t cFS_API_Filter_create(flatbuffers_builder_t *B __cFS_API_Filter_formal_args)
{
    if (cFS_API_Filter_start(B)
        || cFS_API_Filter_EventID_add(B, v0)
        || cFS_API_Filter_Mask_add(B, v1)) {
        return 0;
    }
    return cFS_API_Filter_end(B);
}

static cFS_API_Filter_ref_t cFS_API_Filter_clone(flatbuffers_builder_t *B, cFS_API_Filter_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_API_Filter_start(B)
        || cFS_API_Filter_EventID_pick(B, t)
        || cFS_API_Filter_Mask_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_API_Filter_end(B));
}

__flatbuffers_build_table_vector_field(0, flatbuffers_, cFS_API_Register_Filters, cFS_API_Filter, cFS_API_Register)
__flatbuffers_build_scalar_field(1, flatbuffers_, cFS_API_Register_NumFilteredEvents, flatbuffers_uint16, uint16_t, 2, 2, UINT16_C(0), cFS_API_Register)
__flatbuffers_build_scalar_field(2, flatbuffers_, cFS_API_Register_FilterScheme, flatbuffers_uint16, uint16_t, 2, 2, UINT16_C(0), cFS_API_Register)

static inline cFS_API_Register_ref_t cFS_API_Register_create(flatbuffers_builder_t *B __cFS_API_Register_formal_args)
{
    if (cFS_API_Register_start(B)
        || cFS_API_Register_Filters_add(B, v0)
        || cFS_API_Register_NumFilteredEvents_add(B, v1)
        || cFS_API_Register_FilterScheme_add(B, v2)) {
        return 0;
    }
    return cFS_API_Register_end(B);
}

static cFS_API_Register_ref_t cFS_API_Register_clone(flatbuffers_builder_t *B, cFS_API_Register_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_API_Register_start(B)
        || cFS_API_Register_Filters_pick(B, t)
        || cFS_API_Register_NumFilteredEvents_pick(B, t)
        || cFS_API_Register_FilterScheme_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_API_Register_end(B));
}

__flatbuffers_build_union_field(1, flatbuffers_, cFS_API_RemoteCall_input, cFS_API_Function, cFS_API_RemoteCall)
__flatbuffers_build_union_table_value_field(flatbuffers_, cFS_API_RemoteCall_input, cFS_API_Function, RunLoop, cFS_API_RunLoop)
__flatbuffers_build_union_table_value_field(flatbuffers_, cFS_API_RemoteCall_input, cFS_API_Function, PerfLogAdd, cFS_API_PerfLogAdd)
__flatbuffers_build_union_table_value_field(flatbuffers_, cFS_API_RemoteCall_input, cFS_API_Function, RegisterApp, cFS_API_RegisterApp)
__flatbuffers_build_union_table_value_field(flatbuffers_, cFS_API_RemoteCall_input, cFS_API_Function, ExitApp, cFS_API_ExitApp)
__flatbuffers_build_union_table_value_field(flatbuffers_, cFS_API_RemoteCall_input, cFS_API_Function, Register, cFS_API_Register)
__flatbuffers_build_union_table_value_field(flatbuffers_, cFS_API_RemoteCall_input, cFS_API_Function, SendEvent, cFS_API_SendEvent)
__flatbuffers_build_union_table_value_field(flatbuffers_, cFS_API_RemoteCall_input, cFS_API_Function, SendEventWithAppID, cFS_API_SendEventWithAppID)

static inline cFS_API_RemoteCall_ref_t cFS_API_RemoteCall_create(flatbuffers_builder_t *B __cFS_API_RemoteCall_formal_args)
{
    if (cFS_API_RemoteCall_start(B)
        || cFS_API_RemoteCall_input_add_value(B, v1)
        || cFS_API_RemoteCall_input_add_type(B, v1.type)) {
        return 0;
    }
    return cFS_API_RemoteCall_end(B);
}

static cFS_API_RemoteCall_ref_t cFS_API_RemoteCall_clone(flatbuffers_builder_t *B, cFS_API_RemoteCall_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (cFS_API_RemoteCall_start(B)
        || cFS_API_RemoteCall_input_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, cFS_API_RemoteCall_end(B));
}

#include "flatcc/flatcc_epilogue.h"
#endif /* CFS_API_BUILDER_H */
