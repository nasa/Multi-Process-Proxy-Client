
/*************************************************************************
** Includes
*************************************************************************/
#include "core_lib.h"
#include "core_lib_version.h"
#include "cfe_sb_extern_typedefs.h"
#include "cfe.h"
#include "cfe_sb.h"

/*************************************************************************
** Macro Definitions
*************************************************************************/

/*************************************************************************
** Private Function Prototypes
*************************************************************************/
int32 CORE_LibInit(void);


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* CORE Library Initialization Routine                              */
/* cFE requires that a library have an initialization routine      */ 
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 CFS_LibInit(void)
{
    
  //CFE_ES_WriteToSysLog("CORE Lib Initialized.  Version %d.%d.%d.%d\n",
  //              CORE_LIB_MAJOR_VERSION,
  //              CORE_LIB_MINOR_VERSION,
  //              CORE_LIB_REVISION,
  //              CORE_LIB_MISSION_REV);
    return OS_SUCCESS;
}/* End CORE_LibInit */

void cl_CFE_SB_InitMsg(void *MsgPtr, CFE_SB_MsgId_t MsgId, uint16 Length, boolean Clear) {
  CFE_SB_InitMsg(MsgPtr, MsgId, Length, Clear);
}

/************************/
/*  End of File Comment */
/************************/
