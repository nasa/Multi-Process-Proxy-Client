cmake_minimum_required(VERSION 2.6.4)
project(CFS_PROXY_CLIENT C)

# CFE/PSP/OSAL includes
include_directories(${CFE_SOURCE_DIR}/modules/core_api/fsw/inc/)
include_directories(${CFE_SOURCE_DIR}/modules/msg/fsw/inc/)
include_directories(${OSAL_SOURCE_DIR}/src/os/inc/)
include_directories(${CFEPSP_SOURCE_DIR}/fsw/inc/)

include_directories(fsw/public_inc)
include_directories(fsw/flat_inc)
include_directories(${nng_lib_MISSION_DIR}/include)
include_directories(${flat_lib_MISSION_DIR}/include)

aux_source_directory(fsw/src APP_SRC_FILES)
aux_source_directory(fsw/wrap APP_SRC_FILES)

set(APP_NAME proxy_client)

add_library(${APP_NAME} "SHARED" ${APP_SRC_FILES})

# Override the default behavior of attaching a "lib" prefix
set_target_properties(${APP_NAME} PROPERTIES PREFIX "")
TARGET_LINK_LIBRARIES(${APP_NAME} flat_lib nng_lib)

# Create the install targets for this shared/modular app
foreach(TGT ${APP_INSTALL_LIST})
  install(TARGETS ${APP_NAME} DESTINATION ${TGT}/${INSTALL_SUBDIR})
endforeach()
