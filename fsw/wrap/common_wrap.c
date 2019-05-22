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
