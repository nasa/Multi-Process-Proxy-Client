#include "cfe.h"
#include "common_wrap.h"

// TODO: warning of implicit definition of __real_CFE_FS_InitHeader
void __wrap_CFE_FS_InitHeader(CFE_FS_Header_t *Hdr, const char *Description, uint32 SubType)
{
    printf("\n\nCFE_FS_InitHeader Wrapper called\n\n");
    //__real_CFE_FS_InitHeader(Hdr, Description, SubType);
}
