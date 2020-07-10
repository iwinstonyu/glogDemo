cmake_minimum_required(VERSION 3.1)

project(glogDemo VERSION 1.0.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_UTILITY_ROOT})
include(Common)

find_package(glog REQUIRED
	PATHS ${GLOG_ROOT}
)
MESSAGE("gloginc: " ${glog_INCLUDE_DIR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)

m_set_vs_runtime_mt()

add_subdirectory(Src)
	