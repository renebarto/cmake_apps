cmake_minimum_required(VERSION 3.5.1)
project(weston-apps)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(platform)
include(list_to_string)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)

# Avoid re-linking shared libs / executables
set(CMAKE_SKIP_BUILD_RPATH ON)

if ("${ENABLE_WESTEROS}" STREQUAL "")
    set(ENABLE_WESTEROS ON)
    message(STATUS "Setting if ENABLE_WESTEROS to default ${ENABLE_WESTEROS}")
endif()

if(CMAKE_BUILD_TYPE)
    message(STATUS "Current build type: ${CMAKE_BUILD_TYPE}")
else()
    message(STATUS "Setting build to Debug")
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING
        "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

message(STATUS "Build config directory: " ${CMAKE_BINARY_DIR})
message(STATUS "Sytem root  directory: " ${CMAKE_SYSROOT})
message(STATUS "Install prefix       : " ${CMAKE_INSTALL_PREFIX})
set(CMAKE_PROGRAM_PATH ${CMAKE_INSTALL_PREFIX}/bin)
message(STATUS "CMAKE_PROGRAM_PATH   : ${CMAKE_PROGRAM_PATH}")
set(CMAKE_LIBRARY_PATH ${CMAKE_INSTALL_PREFIX}/lib)
message(STATUS "CMAKE_LIBRARY_PATH   : ${CMAKE_LIBRARY_PATH}")
set(CMAKE_INCLUDE_PATH ${CMAKE_INSTALL_PREFIX}/include)
message(STATUS "CMAKE_PROGRAM_PATH   : ${CMAKE_INCLUDE_PATH}")
set(CMAKE_PREFIX_PATH ${CMAKE_INSTALL_PREFIX})
message(STATUS "CMAKE_PREFIX_PATH    : ${CMAKE_PREFIX_PATH}")

if (NOT CMAKE_CROSSCOMPILING)
list(APPEND SYSTEM_INCLUDES ${CMAKE_INSTALL_PREFIX}/include)
list(APPEND SYSTEM_INCLUDES /usr/include)
list(APPEND SYSTEM_INCLUDES /usr/include/x86_64-linux-gnu)
list(APPEND SYSTEM_INCLUDES /usr/local/include)
list(APPEND SYSTEM_INCLUDES /usr/local/include/x86_64-linux-gnu)
message(STATUS "Add directories SYSTEM_INCLUDES: ${SYSTEM_INCLUDES}")
endif()

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/lib)
#message(STATUS "Static lib output directory:  " ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/bin)
#message(STATUS "Shared lib output directory: " ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/bin)
#message(STATUS "Executable output directory:  " ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

set(LINK_WHOLE_LIB -Wl,--whole-archive)
set(LINK_NO_WHOLE_LIB -Wl,--no-whole-archive)
set(LINK_RPATH -Wl,-rpath,'\$ORIGIN/../lib/')

add_custom_target(install-components)
add_custom_target(uninstall-components)

#add_subdirectory(cmake_package_builder)
#add_subdirectory(weston-simple-demo)
#add_subdirectory(weston-simple-gl)
#add_subdirectory(weston-texture)
#add_subdirectory(hello-wayland-org)
#add_subdirectory(wayland-1.13.0)
#add_subdirectory(wayland-protocols-1.7)
if (ENABLE_WESTEROS)
    add_subdirectory(westeros)
endif()
#add_subdirectory(weston-2.0.0)
#add_subdirectory(ogl-OpenGL-tutorial_0015_21)

#add_subdirectory(wayland-classes)
#add_subdirectory(wayland-demo1)
#add_subdirectory(wayland-demo2)
#add_subdirectory(hello-wayland)
#add_subdirectory(weston-simple-egl)
