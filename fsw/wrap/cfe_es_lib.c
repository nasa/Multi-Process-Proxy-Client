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
    /* buffer = flatcc_builder_finalize_buffer(B, &size); */
    buffer = flatcc_builder_finalize_aligned_buffer(B, &size);

    // printf("%s: SENDING EVS MSG\n", name);
    rv = nng_send(sock, buffer, size, 0);
    if (rv == 0)
    {
        // printf("nng_send: %d\n", rv);
    }
    else
    {
        printf("Oh No! nng_send: %d\n", rv);
    }

    /* free(buffer); */
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
//#define CFE_ES_PerfLogEntry(id) (CFE_ES_PerfLogAdd(id, 0))
//#define CFE_ES_PerfLogExit(id) (CFE_ES_PerfLogAdd(id, 1))
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
    /* buffer = flatcc_builder_finalize_buffer(B, &size); */
    buffer = flatcc_builder_finalize_aligned_buffer(B, &size);

    rv = nng_send(sock, buffer, size, 0);
    if (rv == 0)
    {
        // printf("nng_send: %d\n", rv);
    }
    else
    {
        printf("Oh No! nng_send: %d\n", rv);
    }

    /* free(buffer); */
    flatcc_builder_aligned_free(buffer);

    /*
     * Reset, but keep allocated stack etc.,
     * or optionally reduce memory using `flatcc_builder_custom_reset`.
     */
    flatcc_builder_reset(B);
}

int32 __wrap_CFE_ES_RegisterApp(void)
{
    return CFE_SUCCESS;

    // For now, not implementing so that the proxy may call RegisterApp instead
    // TODO: Remove this dead code once sure that the proxy must call RegisterApp
    /*
    flatcc_builder_t *B = &builder;

    int rv;
    void *buffer;
    size_t size;

    // Construct a buffer specific to schema.
    ns(RegisterApp_ref_t) registerApp = ns(RegisterApp_create(B));
    ns(Function_union_ref_t) function = ns(Function_as_RegisterApp(registerApp));
    ns(RemoteCall_create_as_root(B, function));

    // Retrieve buffer - see also `flatcc_builder_get_direct_buffer`.
    // buffer = flatcc_builder_finalize_buffer(B, &size);
    buffer = flatcc_builder_finalize_aligned_buffer(B, &size);

    // printf("%s: SENDING ES RegisterApp\n", name);
    rv = nng_send(sock, buffer, size, 0);
    if (rv == 0)
    {
        // printf("nng_send: %d\n", rv);
    }
    else
    {
        printf("Oh No! nng_send: %d\n", rv);
    }

    // free(buffer);
    flatcc_builder_aligned_free(buffer);

    // Receive the return value
    rv = receive_int32();

    // Reset, but keep allocated stack etc.,
    // or optionally reduce memory using `flatcc_builder_custom_reset`.
    flatcc_builder_reset(B);

    return rv;
    */
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
    /* buffer = flatcc_builder_finalize_buffer(B, &size); */
    buffer = flatcc_builder_finalize_aligned_buffer(B, &size);

    rv = nng_send(sock, buffer, size, 0);
    if (rv == 0)
    {
        // printf("nng_send: %d\n", rv);
    }
    else
    {
        printf("Oh No! nng_send: %d\n", rv);
    }

    /* free(buffer); */
    flatcc_builder_aligned_free(buffer);

    /*
     * Reset, but keep allocated stack etc.,
     * or optionally reduce memory using `flatcc_builder_custom_reset`.
     */
    flatcc_builder_reset(B);

    exit(0);
}
