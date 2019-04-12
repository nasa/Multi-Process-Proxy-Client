cmake_minimum_required(VERSION 2.6.4)
project(CFS_CORE_LIB C)
  
include_directories(fsw/public_inc)

aux_source_directory(fsw/src APP_SRC_FILES)

# Create the app module
#add_cfe_app(core_lib ${APP_SRC_FILES})

set(APP_NAME core_lib)

add_library(core_lib "SHARED" ${APP_SRC_FILES})

# Override the default behavior of attaching a "lib" prefix
set_target_properties(core_lib PROPERTIES PREFIX "")
message("WORD: core-${TGTNAME}\n")
TARGET_LINK_LIBRARIES(${APP_NAME} core-${TGTNAME})

# Create the install targets for this shared/modular app
foreach(TGT ${APP_INSTALL_LIST})
  install(TARGETS ${APP_NAME} DESTINATION ${TGT}/${INSTALL_SUBDIR})
  #message("What is going on: libcfe_core_default_${TGT}\n")
  #TARGET_LINK_LIBRARIES(core_lib libcfe_core_default_${TGT})
endforeach()
