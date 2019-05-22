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
