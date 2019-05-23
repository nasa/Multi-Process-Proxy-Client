#include <nng/nng.h>
#include <nng/protocol/pair0/pair.h>

#include <cfs_api_builder.h>
#include <cfs_return_reader.h>
#undef ns
#define ns(x) FLATBUFFERS_WRAP_NAMESPACE(cFS_API, x)
#undef nsr
#define nsr(x) FLATBUFFERS_WRAP_NAMESPACE(cFS_Return, x)

extern flatcc_builder_t builder;
extern char * name;
extern nng_socket sock;

int32 receive_int32(void);
uint32 receive_uint32(void);
int16 receive_int16(void);
uint16 receive_uint16(void);

CFE_TIME_SysTime_t receive_SysTime(void);
