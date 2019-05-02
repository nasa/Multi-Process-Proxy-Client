
/*************************************************************************
** Includes
*************************************************************************/
#include "proxy_lib.h"
#include "proxy_lib_version.h"
#include "cfe_sb_extern_typedefs.h"
#include "cfe.h"
#include "cfe_sb.h"

/*************************************************************************
** Macro Definitions
*************************************************************************/

/*************************************************************************
** Private Function Prototypes
*************************************************************************/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* CORE Library Initialization Routine                              */
/* cFE requires that a library have an initialization routine      */ 
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// TODO: Remove? Not needed?
int32 PROXY_LibInit(void)
{
    
  //CFE_ES_WriteToSysLog("PROXY Lib Initialized.  Version %d.%d.%d.%d\n",
  //              PROXY_LIB_MAJOR_VERSION,
  //              PROXY_LIB_MINOR_VERSION,
  //              PROXY_LIB_REVISION,
  //              PROXY_LIB_MISSION_REV);
    return OS_SUCCESS;
}

/************************/
/*  End of File Comment */
/************************/
