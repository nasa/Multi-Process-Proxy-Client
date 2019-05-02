#include "cfe.h"
#include "common.h"

// TODO: Consider error handling. Events won't work without NNG

int32 __wrap_CFE_EVS_SendEvent(uint16 EventID, uint16 EventType, const char *Spec, ... ) {
    flatcc_builder_t *B = &builder;

    int rv;
    va_list Ptr;
    char spec_buffer[CFE_MISSION_EVS_MAX_MESSAGE_LENGTH] = {0};

    va_start(Ptr, Spec);
    vsnprintf(spec_buffer, sizeof(spec_buffer), Spec, Ptr);
    // printf("What's the new string? %s\n", spec_buffer);
    va_end(Ptr);

    flatbuffers_string_ref_t s;
    s = flatbuffers_string_create_str(B, spec_buffer);

    void *buffer;
    size_t size;

    /* Construct a buffer specific to schema. */
    ns(SendEvent_ref_t) sendEvent = ns(SendEvent_create(B, EventID, EventType, s));
    ns(Function_union_ref_t) function = ns(Function_as_SendEvent(sendEvent));
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

int32 __wrap_CFE_EVS_SendEventWithAppID(uint16 EventID, uint16 EventType, uint32 AppID, const char *Spec, ... )
{
    flatcc_builder_t *B = &builder;

    int rv;
    va_list Ptr;
    char spec_buffer[CFE_MISSION_EVS_MAX_MESSAGE_LENGTH] = {0};

    va_start(Ptr, Spec);
    vsnprintf(spec_buffer, sizeof(spec_buffer), Spec, Ptr);
    // printf("(w/ID) What's the new string? %s\n", spec_buffer);
    va_end(Ptr);

    flatbuffers_string_ref_t s;
    s = flatbuffers_string_create_str(B, spec_buffer);

    void *buffer;
    size_t size;

    /* Construct a buffer specific to schema. */
    ns(SendEventWithAppID_ref_t) sendEvent = ns(SendEventWithAppID_create(B, EventID, EventType, AppID, s));
    ns(Function_union_ref_t) function = ns(Function_as_SendEventWithAppID(sendEvent));
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

    // Recieve the return value
    void *ret_buffer;
    if ((rv = nng_recv(sock, &ret_buffer, &size, NNG_FLAG_ALLOC)) == 0)
    {
        nsr(ReturnData_table_t) returnData = nsr(ReturnData_as_root(ret_buffer));
        rv = nsr(ReturnData_retval(returnData));
        nng_free(ret_buffer, size);
    }
    else
    {
        rv = -1;
    }

    /*
     * Reset, but keep allocated stack etc.,
     * or optionally reduce memory using `flatcc_builder_custom_reset`.
     */
    flatcc_builder_reset(B);

    return rv;
}
