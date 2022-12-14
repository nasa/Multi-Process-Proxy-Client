#ifndef COMMON_VERIFIER_H
#define COMMON_VERIFIER_H

/* Generated by flatcc 0.6.0-pre FlatBuffers schema compiler for C by dvide.com */

#ifndef COMMON_READER_H
#include "common_reader.h"
#endif
#include "flatcc/flatcc_verifier.h"
#include "flatcc/flatcc_prologue.h"

static int cFETime_verify_table(flatcc_table_verifier_descriptor_t *td);

static int cFETime_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 4, 4) /* Seconds */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 4, 4) /* Subseconds */)) return ret;
    return flatcc_verify_ok;
}

static inline int cFETime_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, cFETime_identifier, &cFETime_verify_table);
}

static inline int cFETime_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, cFETime_type_identifier, &cFETime_verify_table);
}

static inline int cFETime_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &cFETime_verify_table);
}

static inline int cFETime_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &cFETime_verify_table);
}

#include "flatcc/flatcc_epilogue.h"
#endif /* COMMON_VERIFIER_H */
