cmake_minimum_required(VERSION 2.6.4)
project(CFS_PROXY_LIB C)

include_directories(fsw/public_inc)
include_directories(fsw/flat_inc)
aux_source_directory(fsw/src APP_SRC_FILES)

# Create the app module
#add_cfe_app(core_lib ${APP_SRC_FILES})

set(APP_NAME proxy_lib)

add_library(${APP_NAME} "SHARED" ${APP_SRC_FILES})

# Override the default behavior of attaching a "lib" prefix
set_target_properties(${APP_NAME} PROPERTIES PREFIX "")
# TARGET_LINK_LIBRARIES(${APP_NAME} core-${TGTNAME})

# Create the install targets for this shared/modular app
foreach(TGT ${APP_INSTALL_LIST})
  install(TARGETS ${APP_NAME} DESTINATION ${TGT}/${INSTALL_SUBDIR})
endforeach()
