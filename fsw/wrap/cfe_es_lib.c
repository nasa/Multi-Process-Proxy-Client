/*
** GSC-18364-1, "Proxy Core Flight System Application and Client for External Process"
**
** Copyright © 2019 United States Government as represented by
** the Administrator of the National Aeronautics and Space Administration.
** No copyright is claimed in the United States under Title 17, U.S. Code.
** All Other Rights Reserved.
**
** Licensed under the NASA Open Source Agreement version 1.3
** See "NOSA GSC-18364-1.pdf"
*/

#include "cfe.h"
#include "common_wrap.h"

// TODO: Consider error handling. Events won't work without NNG
// TODO: function for getting return

int32 __wrap_CFE_ES_RunLoop(uint32 *ExitStatus)
{
    flatcc_builder_t *B = &builder;

    int rv;
    void *buffer;
    size_t size;

    /* Construct a buffer specific to schema. */
    ns(RunLoop_ref_t) runLoop = ns(RunLoop_create(B, *ExitStatus));
    ns(Function_union_ref_t) function = ns(Function_as_RunLoop(runLoop));
    ns(RemoteCall_create_as_root(B, function));

    /* Retrieve buffer - see also `flatcc_builder_get_direct_buffer`. */
    buffer = flatcc_builder_finalize_aligned_buffer(B, &size);

    rv = nng_send(sock, buffer, size, 0);
    if (rv != 0)
    {
        printf("%s - Error: %s\n", __func__, nng_strerror(rv));
    }

    flatcc_builder_aligned_free(buffer);

    // Receive the return value
    rv = receive_int32();

    /*
     * Reset, but keep allocated stack etc.,
     * or optionally reduce memory using `flatcc_builder_custom_reset`.
     */
    flatcc_builder_reset(B);

    return rv;
}

// ES Functions
void __wrap_CFE_ES_PerfLogAdd(uint32 Marker, uint32 EntryExit)
{
    flatcc_builder_t *B = &builder;

    int rv;

    void *buffer;
    size_t size;

    /* Construct a buffer specific to schema. */
    ns(PerfLogAdd_ref_t) perfLogAdd = ns(PerfLogAdd_create(B, Marker, EntryExit));
    ns(Function_union_ref_t) function = ns(Function_as_PerfLogAdd(perfLogAdd));
    ns(RemoteCall_create_as_root(B, function));

    /* Retrieve buffer - see also `flatcc_builder_get_direct_buffer`. */
    buffer = flatcc_builder_finalize_aligned_buffer(B, &size);

    rv = nng_send(sock, buffer, size, 0);
    if (rv != 0)
    {
        printf("%s - Error: %s\n", __func__, nng_strerror(rv));
    }

    flatcc_builder_aligned_free(buffer);

    /*
     * Reset, but keep allocated stack etc.,
     * or optionally reduce memory using `flatcc_builder_custom_reset`.
     */
    flatcc_builder_reset(B);
}

int32 __wrap_CFE_ES_RegisterApp(void)
{
    // Not implemented here: the proxy calls RegisterApp instead
    return CFE_SUCCESS;
}

void __wrap_CFE_ES_ExitApp(uint32 ExitStatus)
{
    flatcc_builder_t *B = &builder;

    int rv;

    void *buffer;
    size_t size;

    /* Construct a buffer specific to schema. */
    ns(ExitApp_ref_t) exitApp = ns(ExitApp_create(B, ExitStatus));
    ns(Function_union_ref_t) function = ns(Function_as_ExitApp(exitApp));
    ns(RemoteCall_create_as_root(B, function));

    /* Retrieve buffer - see also `flatcc_builder_get_direct_buffer`. */
    buffer = flatcc_builder_finalize_aligned_buffer(B, &size);

    rv = nng_send(sock, buffer, size, 0);
    if (rv != 0)
    {
        printf("%s - Error: %s\n", __func__, nng_strerror(rv));
    }

    flatcc_builder_aligned_free(buffer);

    /*
     * Reset, but keep allocated stack etc.,
     * or optionally reduce memory using `flatcc_builder_custom_reset`.
     */
    flatcc_builder_reset(B);

    // Clean up flatcc
    flatcc_builder_clear(&builder);

    // Clean up nng
    nng_close(sock);

    exit(0);
}
