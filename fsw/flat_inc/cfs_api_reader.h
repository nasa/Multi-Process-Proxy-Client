#ifndef CFS_API_READER_H
#define CFS_API_READER_H

/* Generated by flatcc 0.6.0-pre FlatBuffers schema compiler for C by dvide.com */

#ifndef FLATBUFFERS_COMMON_READER_H
#include "flatbuffers_common_reader.h"
#endif
#include "flatcc/flatcc_flatbuffers.h"
#ifndef __alignas_is_defined
#include <stdalign.h>
#endif
#include "flatcc/flatcc_prologue.h"
#ifndef flatbuffers_identifier
#define flatbuffers_identifier 0
#endif
#ifndef flatbuffers_extension
#define flatbuffers_extension ".bin"
#endif


typedef const struct cFS_API_RunLoop_table *cFS_API_RunLoop_table_t;
typedef struct cFS_API_RunLoop_table *cFS_API_RunLoop_mutable_table_t;
typedef const flatbuffers_uoffset_t *cFS_API_RunLoop_vec_t;
typedef flatbuffers_uoffset_t *cFS_API_RunLoop_mutable_vec_t;
typedef const struct cFS_API_PerfLogAdd_table *cFS_API_PerfLogAdd_table_t;
typedef struct cFS_API_PerfLogAdd_table *cFS_API_PerfLogAdd_mutable_table_t;
typedef const flatbuffers_uoffset_t *cFS_API_PerfLogAdd_vec_t;
typedef flatbuffers_uoffset_t *cFS_API_PerfLogAdd_mutable_vec_t;
typedef const struct cFS_API_SendEvent_table *cFS_API_SendEvent_table_t;
typedef struct cFS_API_SendEvent_table *cFS_API_SendEvent_mutable_table_t;
typedef const flatbuffers_uoffset_t *cFS_API_SendEvent_vec_t;
typedef flatbuffers_uoffset_t *cFS_API_SendEvent_mutable_vec_t;
typedef const struct cFS_API_SendEventWithAppID_table *cFS_API_SendEventWithAppID_table_t;
typedef struct cFS_API_SendEventWithAppID_table *cFS_API_SendEventWithAppID_mutable_table_t;
typedef const flatbuffers_uoffset_t *cFS_API_SendEventWithAppID_vec_t;
typedef flatbuffers_uoffset_t *cFS_API_SendEventWithAppID_mutable_vec_t;
typedef const struct cFS_API_RemoteCall_table *cFS_API_RemoteCall_table_t;
typedef struct cFS_API_RemoteCall_table *cFS_API_RemoteCall_mutable_table_t;
typedef const flatbuffers_uoffset_t *cFS_API_RemoteCall_vec_t;
typedef flatbuffers_uoffset_t *cFS_API_RemoteCall_mutable_vec_t;
#ifndef cFS_API_RunLoop_identifier
#define cFS_API_RunLoop_identifier flatbuffers_identifier
#endif
#define cFS_API_RunLoop_type_hash ((flatbuffers_thash_t)0x88f85c1f)
#define cFS_API_RunLoop_type_identifier "\x1f\x5c\xf8\x88"
#ifndef cFS_API_PerfLogAdd_identifier
#define cFS_API_PerfLogAdd_identifier flatbuffers_identifier
#endif
#define cFS_API_PerfLogAdd_type_hash ((flatbuffers_thash_t)0xbf6aca52)
#define cFS_API_PerfLogAdd_type_identifier "\x52\xca\x6a\xbf"
#ifndef cFS_API_SendEvent_identifier
#define cFS_API_SendEvent_identifier flatbuffers_identifier
#endif
#define cFS_API_SendEvent_type_hash ((flatbuffers_thash_t)0x1cc69526)
#define cFS_API_SendEvent_type_identifier "\x26\x95\xc6\x1c"
#ifndef cFS_API_SendEventWithAppID_identifier
#define cFS_API_SendEventWithAppID_identifier flatbuffers_identifier
#endif
#define cFS_API_SendEventWithAppID_type_hash ((flatbuffers_thash_t)0x8f625ab4)
#define cFS_API_SendEventWithAppID_type_identifier "\xb4\x5a\x62\x8f"
#ifndef cFS_API_RemoteCall_identifier
#define cFS_API_RemoteCall_identifier flatbuffers_identifier
#endif
#define cFS_API_RemoteCall_type_hash ((flatbuffers_thash_t)0x249b70b6)
#define cFS_API_RemoteCall_type_identifier "\xb6\x70\x9b\x24"



/** ///////////////////////////////////////////////// */
struct cFS_API_RunLoop_table { uint8_t unused__; };

static inline size_t cFS_API_RunLoop_vec_len(cFS_API_RunLoop_vec_t vec)
__flatbuffers_vec_len(vec)
static inline cFS_API_RunLoop_table_t cFS_API_RunLoop_vec_at(cFS_API_RunLoop_vec_t vec, size_t i)
__flatbuffers_offset_vec_at(cFS_API_RunLoop_table_t, vec, i, 0)
__flatbuffers_table_as_root(cFS_API_RunLoop)

__flatbuffers_define_scalar_field(0, cFS_API_RunLoop, ExitStatus, flatbuffers_uint32, uint32_t, UINT32_C(0))

struct cFS_API_PerfLogAdd_table { uint8_t unused__; };

static inline size_t cFS_API_PerfLogAdd_vec_len(cFS_API_PerfLogAdd_vec_t vec)
__flatbuffers_vec_len(vec)
static inline cFS_API_PerfLogAdd_table_t cFS_API_PerfLogAdd_vec_at(cFS_API_PerfLogAdd_vec_t vec, size_t i)
__flatbuffers_offset_vec_at(cFS_API_PerfLogAdd_table_t, vec, i, 0)
__flatbuffers_table_as_root(cFS_API_PerfLogAdd)

__flatbuffers_define_scalar_field(0, cFS_API_PerfLogAdd, Marker, flatbuffers_uint32, uint32_t, UINT32_C(0))
__flatbuffers_define_scalar_field(1, cFS_API_PerfLogAdd, EntryExit, flatbuffers_uint32, uint32_t, UINT32_C(0))

/** ///////////////////////////////////////////////// */
struct cFS_API_SendEvent_table { uint8_t unused__; };

static inline size_t cFS_API_SendEvent_vec_len(cFS_API_SendEvent_vec_t vec)
__flatbuffers_vec_len(vec)
static inline cFS_API_SendEvent_table_t cFS_API_SendEvent_vec_at(cFS_API_SendEvent_vec_t vec, size_t i)
__flatbuffers_offset_vec_at(cFS_API_SendEvent_table_t, vec, i, 0)
__flatbuffers_table_as_root(cFS_API_SendEvent)

__flatbuffers_define_scalar_field(0, cFS_API_SendEvent, EventID, flatbuffers_uint16, uint16_t, UINT16_C(0))
__flatbuffers_define_scalar_field(1, cFS_API_SendEvent, EventType, flatbuffers_uint16, uint16_t, UINT16_C(0))
__flatbuffers_define_string_field(2, cFS_API_SendEvent, Spec, 0)

struct cFS_API_SendEventWithAppID_table { uint8_t unused__; };

static inline size_t cFS_API_SendEventWithAppID_vec_len(cFS_API_SendEventWithAppID_vec_t vec)
__flatbuffers_vec_len(vec)
static inline cFS_API_SendEventWithAppID_table_t cFS_API_SendEventWithAppID_vec_at(cFS_API_SendEventWithAppID_vec_t vec, size_t i)
__flatbuffers_offset_vec_at(cFS_API_SendEventWithAppID_table_t, vec, i, 0)
__flatbuffers_table_as_root(cFS_API_SendEventWithAppID)

__flatbuffers_define_scalar_field(0, cFS_API_SendEventWithAppID, EventID, flatbuffers_uint16, uint16_t, UINT16_C(0))
__flatbuffers_define_scalar_field(1, cFS_API_SendEventWithAppID, EventType, flatbuffers_uint16, uint16_t, UINT16_C(0))
__flatbuffers_define_scalar_field(2, cFS_API_SendEventWithAppID, AppID, flatbuffers_uint32, uint32_t, UINT32_C(0))
__flatbuffers_define_string_field(3, cFS_API_SendEventWithAppID, Spec, 0)
/** /////////////////////////////////////////////////
 * /////////////////////////////////////////////////
 * /////////////////////////////////////////////////
 * /////////////////////////////////////////////////
 * ///////////////////////////////////////////////// */
typedef uint8_t cFS_API_Function_union_type_t;
__flatbuffers_define_integer_type(cFS_API_Function, cFS_API_Function_union_type_t, 8)
__flatbuffers_define_union(flatbuffers_, cFS_API_Function)
#define cFS_API_Function_NONE ((cFS_API_Function_union_type_t)UINT8_C(0))
#define cFS_API_Function_RunLoop ((cFS_API_Function_union_type_t)UINT8_C(1))
#define cFS_API_Function_PerfLogAdd ((cFS_API_Function_union_type_t)UINT8_C(2))
#define cFS_API_Function_SendEvent ((cFS_API_Function_union_type_t)UINT8_C(3))
#define cFS_API_Function_SendEventWithAppID ((cFS_API_Function_union_type_t)UINT8_C(4))

static inline const char *cFS_API_Function_type_name(cFS_API_Function_union_type_t type)
{
    switch (type) {
    case cFS_API_Function_NONE: return "NONE";
    case cFS_API_Function_RunLoop: return "RunLoop";
    case cFS_API_Function_PerfLogAdd: return "PerfLogAdd";
    case cFS_API_Function_SendEvent: return "SendEvent";
    case cFS_API_Function_SendEventWithAppID: return "SendEventWithAppID";
    default: return "";
    }
}

static inline int cFS_API_Function_is_known_type(cFS_API_Function_union_type_t type)
{
    switch (type) {
    case cFS_API_Function_NONE: return 1;
    case cFS_API_Function_RunLoop: return 1;
    case cFS_API_Function_PerfLogAdd: return 1;
    case cFS_API_Function_SendEvent: return 1;
    case cFS_API_Function_SendEventWithAppID: return 1;
    default: return 0;
    }
}


struct cFS_API_RemoteCall_table { uint8_t unused__; };

static inline size_t cFS_API_RemoteCall_vec_len(cFS_API_RemoteCall_vec_t vec)
__flatbuffers_vec_len(vec)
static inline cFS_API_RemoteCall_table_t cFS_API_RemoteCall_vec_at(cFS_API_RemoteCall_vec_t vec, size_t i)
__flatbuffers_offset_vec_at(cFS_API_RemoteCall_table_t, vec, i, 0)
__flatbuffers_table_as_root(cFS_API_RemoteCall)

__flatbuffers_define_union_field(flatbuffers_, 1, cFS_API_RemoteCall, input, cFS_API_Function, 0)


#include "flatcc/flatcc_epilogue.h"
#endif /* CFS_API_READER_H */