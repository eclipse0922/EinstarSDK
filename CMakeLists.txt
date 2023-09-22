cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)
project(E10SDKScannerDemo VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENTDIR ON)

set(CMAKE_VS_INCLUDE_INSTALL_TO_DEFAULT_BUILD ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_BUILD_TYPE "" CACHE STRING "" FORCE)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_definitions(-DSDK_API_VERSION="v2.0")

option(RUN_SIGNTOOL "Run the signtool" OFF)

function(set_project_compile_definitions targetName compileFlagsInRelease)
	option(_using_debug_compile_definitions_${targetName} "对项目 ${targetName} 开启DEBUG模式" OFF)
	if(_using_debug_compile_definitions_${targetName})
		message("project: ${targetName} debug open.")
		set_target_properties(${targetName} PROPERTIES COMPILE_FLAGS "/Zi /Od")
		set_target_properties(${targetName} PROPERTIES LINK_FLAGS "/DEBUG /INCREMENTAL:NO /OPT:REF /OPT:ICF")
	else()
		set_target_properties(${targetName} PROPERTIES COMPILE_FLAGS ${compileFlagsInRelease})
	endif()
endfunction(set_project_compile_definitions)

find_package(Qt5 COMPONENTS Core Gui Widgets remoteobjects REQUIRED CONFIG)

get_target_property(_qmake_executable Qt5::qmake IMPORTED_LOCATION)
get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
find_program(DEPLOYQT_EXECUTABLE NAMES windeployqt macdeployqt HINTS "${_qt_bin_dir}")

if(RUN_SIGNTOOL)
	find_program(SIGNTOOL_EXECUTABLE NAMES signtool REQUIRED)
endif()

#set(VERSIONINFO_RC "${CMAKE_BINARY_DIR}/VersionInforc")
#configure_file("${CMAKE_SOURCE_DIR}/VersionInfo.rc.in"
#	"${VERSIONINFO_RC}")
	
#install(DIRECTORY cmake_configs/ DESTINATION cmake)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_subdirectory(ScannerDemo)
