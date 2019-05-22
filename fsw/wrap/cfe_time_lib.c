#include "cfe.h"
#include "common_wrap.h"

// TODO: Consider error handling. Events won't work without NNG
// TODO: Lots of duplicated code. Simplify if possible


CFE_TIME_SysTime_t __wrap_CFE_TIME_GetTime(void)
{

}

CFE_TIME_SysTime_t __wrap_CFE_TIME_GetTAI(void)
{

}

CFE_TIME_SysTime_t __wrap_CFE_TIME_GetUTC(void)
{

}

CFE_TIME_SysTime_t __wrap_CFE_TIME_MET2SCTime (CFE_TIME_SysTime_t METTime)
{

}

CFE_TIME_SysTime_t __wrap_CFE_TIME_GetSTCF(void)
{

}

CFE_TIME_SysTime_t __wrap_CFE_TIME_GetMET(void)
{

}

uint32 __wrap_CFE_TIME_GetMETseconds(void)
{
    flatcc_builder_t *B = &builder;

    int rv;
    int index = 0;

    void *buffer;
    size_t size;

    /* Construct a buffer specific to schema. */
    ns(TIME_GetMETseconds_ref_t) func_table = ns(TIME_GetMETseconds_create(B));
    ns(Function_union_ref_t) function = ns(Function_as_TIME_GetMETseconds(func_table));
    ns(RemoteCall_create_as_root(B, function));

    /* Retrieve buffer - see also `flatcc_builder_get_direct_buffer`. */
    /* buffer = flatcc_builder_finalize_buffer(B, &size); */
    buffer = flatcc_builder_finalize_aligned_buffer(B, &size);

    // printf("%s: SENDING EVS MSG\n", name);
    rv = nng_send(sock, buffer, size, 0);
    if (rv == 0)
    {
        // printf("nng_send: %d\n", rv);
    }
    else
    {
        printf("Oh No! nng_send: %d\n", rv);
    }

    /* free(buffer); */
    flatcc_builder_aligned_free(buffer);

    // Receive the return value
    rv = receive_uint32();

    /*
     * Reset, but keep allocated stack etc.,
     * or optionally reduce memory using `flatcc_builder_custom_reset`.
     */
    flatcc_builder_reset(B);

    return rv;
}

uint32 __wrap_CFE_TIME_GetMETsubsecs(void)
{

}

int16  __wrap_CFE_TIME_GetLeapSeconds(void)
{

}

CFE_TIME_ClockState_Enum_t __wrap_CFE_TIME_GetClockState(void)
{

}

uint16 __wrap_CFE_TIME_GetClockInfo(void)
{

}

/*
Looking into:
CFE_TIME_SysTime_t  CFE_TIME_Add(CFE_TIME_SysTime_t Time1, CFE_TIME_SysTime_t Time2);
CFE_TIME_SysTime_t  CFE_TIME_Subtract(CFE_TIME_SysTime_t Time1, CFE_TIME_SysTime_t Time2);
CFE_TIME_Compare_t  CFE_TIME_Compare(CFE_TIME_SysTime_t TimeA, CFE_TIME_SysTime_t TimeB);
uint32  CFE_TIME_Sub2MicroSecs(uint32 SubSeconds);
uint32  CFE_TIME_Micro2SubSecs(uint32 MicroSeconds);
uint32 CFE_TIME_CFE2FSSeconds(uint32 SecondsCFE);
uint32 CFE_TIME_FS2CFESeconds(uint32 SecondsFS);
void CFE_TIME_Print(char *PrintBuffer, CFE_TIME_SysTime_t TimeToPrint);
void  CFE_TIME_ExternalTone(void);
void CFE_TIME_ExternalMET(CFE_TIME_SysTime_t NewMET);
void CFE_TIME_ExternalGPS(CFE_TIME_SysTime_t NewTime, int16 NewLeaps);
void CFE_TIME_ExternalTime(CFE_TIME_SysTime_t NewTime);
int32  CFE_TIME_RegisterSynchCallback(CFE_TIME_SynchCallbackPtr_t CallbackFuncPtr);
int32  CFE_TIME_UnregisterSynchCallback(CFE_TIME_SynchCallbackPtr_t CallbackFuncPtr);
void CFE_TIME_Local1HzISR(void);
*/
