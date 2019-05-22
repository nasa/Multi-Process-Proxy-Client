#include "cfe.h"
#include "common_wrap.h"

// TODO: Consider error handling. Events won't work without NNG
// TODO: Lots of duplicated code. Simplify if possible

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
    rv = recieve_int32();

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
    rv = recieve_int32();

    /*
     * Reset, but keep allocated stack etc.,
     * or optionally reduce memory using `flatcc_builder_custom_reset`.
     */
    flatcc_builder_reset(B);

    return rv;
}

int32 __wrap_CFE_EVS_SendTimedEvent(CFE_TIME_SysTime_t Time, uint16 EventID, uint16 EventType, const char *Spec, ... )
{
    flatcc_builder_t *B = &builder;

    int rv;
    va_list Ptr;
    char spec_buffer[CFE_MISSION_EVS_MAX_MESSAGE_LENGTH] = {0};

    va_start(Ptr, Spec);
    vsnprintf(spec_buffer, sizeof(spec_buffer), Spec, Ptr);
    va_end(Ptr);

    flatbuffers_string_ref_t s;
    s = flatbuffers_string_create_str(B, spec_buffer);

    void *buffer;
    size_t size;

    /* Construct a buffer specific to schema. */
    ns(cFETime_ref_t) cFETime = ns(cFETime_create(B, Time.Seconds, Time.Subseconds));
    ns(SendTimedEvent_ref_t) sendTimedEvent = ns(SendTimedEvent_create(B, cFETime, EventID, EventType, s));
    ns(Function_union_ref_t) function = ns(Function_as_SendTimedEvent(sendTimedEvent));
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

    // Recieve the return value
    rv = recieve_int32();

    /*
     * Reset, but keep allocated stack etc.,
     * or optionally reduce memory using `flatcc_builder_custom_reset`.
     */
    flatcc_builder_reset(B);

    return rv;
}

int32 __wrap_CFE_EVS_Register(void *Filters, uint16 NumFilteredEvents, uint16 FilterScheme)
{
    flatcc_builder_t *B = &builder;

    int rv;
    int index = 0;

    void *buffer;
    size_t size;

    CFE_EVS_BinFilter_t *EventFilters = (CFE_EVS_BinFilter_t *) Filters;

    ns(Filter_vec_start(B));
    for (index = 0; index < NumFilteredEvents; index++)
    {
        ns(Filter_ref_t) filter = ns(Filter_create(B, EventFilters[index].EventID, EventFilters[index].Mask));
        ns(Filter_vec_push(B, filter));
    }
    ns(Filter_vec_ref_t) filters = ns(Filter_vec_end(B));

    /* Construct a buffer specific to schema. */
    ns(Register_ref_t) registerEvents = ns(Register_create(B, filters, NumFilteredEvents, FilterScheme));
    ns(Function_union_ref_t) function = ns(Function_as_Register(registerEvents));
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
    rv = recieve_int32();

    /*
     * Reset, but keep allocated stack etc.,
     * or optionally reduce memory using `flatcc_builder_custom_reset`.
     */
    flatcc_builder_reset(B);

    return rv;
}

int32 __wrap_CFE_EVS_Unregister(void)
{
    flatcc_builder_t *B = &builder;

    int rv;
    int index = 0;

    void *buffer;
    size_t size;

    /* Construct a buffer specific to schema. */
    ns(Unregister_ref_t) unregister = ns(Unregister_create(B));
    ns(Function_union_ref_t) function = ns(Function_as_Unregister(unregister));
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
    rv = recieve_int32();

    /*
     * Reset, but keep allocated stack etc.,
     * or optionally reduce memory using `flatcc_builder_custom_reset`.
     */
    flatcc_builder_reset(B);

    return rv;
}

int32 __wrap_CFE_EVS_ResetFilter(uint16 EventID)
{
    flatcc_builder_t *B = &builder;

    int rv;
    int index = 0;

    void *buffer;
    size_t size;

    /* Construct a buffer specific to schema. */
    ns(ResetFilter_ref_t) resetFilter = ns(ResetFilter_create(B, EventID));
    ns(Function_union_ref_t) function = ns(Function_as_ResetFilter(resetFilter));
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
    rv = recieve_int32();

    /*
     * Reset, but keep allocated stack etc.,
     * or optionally reduce memory using `flatcc_builder_custom_reset`.
     */
    flatcc_builder_reset(B);

    return rv;
}

int32 __wrap_CFE_EVS_ResetAllFilters(void)
{
    flatcc_builder_t *B = &builder;

    int rv;
    int index = 0;

    void *buffer;
    size_t size;

    /* Construct a buffer specific to schema. */
    ns(ResetAllFilters_ref_t) resetAllFilters = ns(ResetAllFilters_create(B));
    ns(Function_union_ref_t) function = ns(Function_as_ResetAllFilters(resetAllFilters));
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
    rv = recieve_int32();

    /*
     * Reset, but keep allocated stack etc.,
     * or optionally reduce memory using `flatcc_builder_custom_reset`.
     */
    flatcc_builder_reset(B);

    return rv;
}
