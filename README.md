# core_lib

The goal of this library is to expose functions from cFE core-services that may be safely called from a separate process.
These functions will not access state used by other cFS applications, as this state is not available from other processes.

For example: CFE_SB_InitMsg is a suitable function to place here. CFE_SB_SendMsg is not.

## UPDATE

It looks like the original intended use of this library is not needed as we can link directly to the cFE library for functions we want to use, and wrap the others using the LD option `--wrap=symbol`.
This library may be repurposed to wrap functions from the cFE library that we don't want direct calls to.
