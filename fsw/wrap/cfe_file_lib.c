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

#include "cfe.h"
#include "common_wrap.h"

// TODO: warning of implicit definition of __real_CFE_FS_InitHeader
void __wrap_CFE_FS_InitHeader(CFE_FS_Header_t *Hdr, const char *Description, uint32 SubType)
{
    printf("\n\nCFE_FS_InitHeader Wrapper called\n\n");
    //__real_CFE_FS_InitHeader(Hdr, Description, SubType);
}
