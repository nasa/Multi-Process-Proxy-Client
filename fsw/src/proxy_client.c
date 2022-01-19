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

/*************************************************************************
** Includes
*************************************************************************/
#include "proxy_client.h"
#include "proxy_client_defs.h"
#include "proxy_client_version.h"
#include <unistd.h>

#include <nng/nng.h>
#include <nng/protocol/pair0/pair.h>

// Flat Buff Stuff
#include "cfs_api_builder.h"
#include <cfs_return_reader.h>
#undef ns
#define ns(x) FLATBUFFERS_WRAP_NAMESPACE(cFS_API, x)
#undef nsr
#define nsr(x) FLATBUFFERS_WRAP_NAMESPACE(cFS_Return, x)


/*************************************************************************
** Macro Definitions
*************************************************************************/

/*************************************************************************
** Private Function Prototypes
*************************************************************************/

flatcc_builder_t builder;

// NNG Stuff
nng_socket sock;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Proxy Client Initialization Routine                             */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 PROXY_Client_Init(void)
{
    int rv;

    // Flat Buff Stuff
    flatcc_builder_init(&builder);

    // NNG Stuff
    // TODO: Error handling? Events won't work if nng doesn't

    // Give cFS/proxy a chance to start up
    sleep(1);
    if ((rv = nng_pair0_open(&sock)) != 0)
    {
        printf("(PROXY_CLIENT) nng_pair0_open: %d\n", rv);
    }
    if ((rv = nng_dial(sock, IPC_PIPE_ADDRESS, NULL, 0)) != 0)
    {
        printf("(PROXY_CLIENT) nng_dial: %d - %s\n", rv, nng_strerror(rv));
        printf("\tFailed to dial %s\n", IPC_PIPE_ADDRESS);
    }

    if ((rv = nng_setopt_ms(sock, NNG_OPT_RECVTIMEO, 10000)) != 0)
    {
        printf("(PROXY_CLIENT) nng_setopt_ms: %d\n", rv);
    }

    return OS_SUCCESS;
}

/************************/
/*  End of File Comment */
/************************/
