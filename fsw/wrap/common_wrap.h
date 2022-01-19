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

#ifndef common_wrap_h
#define common_wrap_h

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

#endif /* common_wrap_h */
