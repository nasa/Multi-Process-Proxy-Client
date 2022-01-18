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

// Some common code for the wrapped functions

#include "cfe.h"
#include "common_wrap.h"

int32 receive_int32(void)
{
    int32 rv;
    size_t size;
    void *ret_buffer;

    rv = nng_recv(sock, &ret_buffer, &size, NNG_FLAG_ALLOC);
    if (rv == 0)
    {
        // printf("Actual return value receive!\n");
        nsr(ReturnData_table_t) returnData = nsr(ReturnData_as_root(ret_buffer));
        nsr(Integer32_table_t) integer = nsr(ReturnData_retval(returnData));
        rv = nsr(Integer32_integer32(integer));

        nng_free(ret_buffer, size);
    }
    else
    {
        printf("Oh no. %d\n", rv);
        printf("Error: %s\n", nng_strerror(rv));
        rv = -1;
    }

    return rv;
}

uint32 receive_uint32(void)
{
    int32 rv;
    uint32 received;
    size_t size;
    void *ret_buffer;

    rv = nng_recv(sock, &ret_buffer, &size, NNG_FLAG_ALLOC);
    if (rv == 0)
    {
        // printf("Actual return value receive!\n");
        nsr(ReturnData_table_t) returnData = nsr(ReturnData_as_root(ret_buffer));
        nsr(UnInteger32_table_t) unInteger = nsr(ReturnData_retval(returnData));
        received = nsr(UnInteger32_unInteger32(unInteger));

        nng_free(ret_buffer, size);
    }
    else
    {
        printf("Oh no. %d\n", rv);
        printf("Error: %s\n", nng_strerror(rv));
        received = 0;
    }

    return received;
}

int16 receive_int16(void)
{
    int32 rv;
    int16 received;
    size_t size;
    void *ret_buffer;

    rv = nng_recv(sock, &ret_buffer, &size, NNG_FLAG_ALLOC);
    if (rv == 0)
    {
        // printf("Actual return value receive!\n");
        nsr(ReturnData_table_t) returnData = nsr(ReturnData_as_root(ret_buffer));
        nsr(Integer16_table_t) integer = nsr(ReturnData_retval(returnData));
        received = nsr(Integer16_integer16(integer));

        nng_free(ret_buffer, size);
    }
    else
    {
        printf("Oh no. %d\n", rv);
        printf("Error: %s\n", nng_strerror(rv));
        received = -1;
    }

    return received;
}

uint16 receive_uint16(void)
{
    int32 rv;
    uint16 received;
    size_t size;
    void *ret_buffer;

    rv = nng_recv(sock, &ret_buffer, &size, NNG_FLAG_ALLOC);
    if (rv == 0)
    {
        // printf("Actual return value receive!\n");
        nsr(ReturnData_table_t) returnData = nsr(ReturnData_as_root(ret_buffer));
        nsr(UnInteger16_table_t) unInteger = nsr(ReturnData_retval(returnData));
        received = nsr(UnInteger16_unInteger16(unInteger));

        nng_free(ret_buffer, size);
    }
    else
    {
        printf("Oh no. %d\n", rv);
        printf("Error: %s\n", nng_strerror(rv));
        received = 0;
    }

    return received;
}

CFE_TIME_SysTime_t receive_SysTime(void)
{
    int32 rv;
    CFE_TIME_SysTime_t received;
    size_t size;
    void *ret_buffer;

    rv = nng_recv(sock, &ret_buffer, &size, NNG_FLAG_ALLOC);
    if (rv == 0)
    {

                //ns(SendTimedEvent_table_t) sendTimedEvent = (ns(SendTimedEvent_table_t)) ns(RemoteCall_input(remoteCall));
                //cFETime_table_t time = ns(SendTimedEvent_Time(sendTimedEvent));
                //CFE_TIME_SysTime_t cfe_time;
                //cfe_time.Seconds = ns(cFETime_Seconds(time));
                //cfe_time.Subseconds = ns(cFETime_Subseconds(time));

        // printf("Actual return value receive!\n");
        nsr(ReturnData_table_t) returnData = nsr(ReturnData_as_root(ret_buffer));
        cFETime_table_t time = nsr(ReturnData_retval(returnData));
        received.Seconds = cFETime_Seconds(time);
        received.Subseconds = cFETime_Subseconds(time);

        nng_free(ret_buffer, size);
    }
    else
    {
        printf("Oh no. %d\n", rv);
        printf("Error: %s\n", nng_strerror(rv));
        received.Seconds = 0;
        received.Subseconds = 0;
    }

    return received;
}
