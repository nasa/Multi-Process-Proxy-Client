
/*************************************************************************
** Includes
*************************************************************************/
#include "proxy_client.h"
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
char * name = "actual_app";
char * url = "ipc:///tmp/pair.ipc";
nng_socket sock;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Proxy Client Initialization Routine                             */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// TODO: Remove? Not needed?
int32 PROXY_ClientInit(void)
{
    int rv;

    // Flat Buff Stuff
    flatcc_builder_init(&builder);

    // NNG Stuff
    // TODO: Error handling? Events won't work if nng doesn't
    sleep(1);
    if ((rv = nng_pair0_open(&sock)) != 0)
    {
        printf("nng_pair0_open: %d\n", rv);
    }
    if ((rv = nng_dial(sock, url, NULL, 0)) != 0)
    {
        printf("nng_dial: %d\n", rv);
    }

    if ((rv = nng_setopt_ms(sock, NNG_OPT_RECVTIMEO, 10000)) != 0)
    {
        printf("nng_setopt_ms: %d\n", rv);
    }

    //CFE_ES_WriteToSysLog("PROXY Client Initialized.  Version %d.%d.%d.%d\n",
    //              PROXY_CLIENT_MAJOR_VERSION,
    //              PROXY_CLIENT_MINOR_VERSION,
    //              PROXY_CLIENT_REVISION,
    //              PROXY_CLIENT_MISSION_REV);
    return OS_SUCCESS;
}

/************************/
/*  End of File Comment */
/************************/