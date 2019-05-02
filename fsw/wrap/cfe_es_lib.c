#include "cfe.h"
#include "common.h"

// TODO: Consider error handling. Events won't work without NNG

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
    void *ret_buffer;
    if ((rv = nng_recv(sock, &ret_buffer, &size, NNG_FLAG_ALLOC)) == 0)
    {
        // printf("Actual return value receive!\n");
        nsr(ReturnData_table_t) returnData = nsr(ReturnData_as_root(ret_buffer));
        rv = nsr(ReturnData_retval(returnData));
        nng_free(ret_buffer, size);
    }
    else
    {
        printf("Oh no. %d\n", rv);
        printf("Error: %s\n", nng_strerror(rv));
        rv = -1;
    }

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
