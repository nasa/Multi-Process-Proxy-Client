# core_lib

The goal of this library is to expose functions from cFE core-services that may be safely called from a separate process.
These functions will not access state used by other cFS applications, as this state is not available from other processes.

For example: CFE_SB_InitMsg is a suitable function to place here. CFE_SB_SendMsg is not.
