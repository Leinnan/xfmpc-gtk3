# Set the name and the supported language of the project
set( PROJECT_NAME "xfmpc-gtk3" )
## Set our project name
project(${PROJECT_NAME})
# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 2.6)
INCLUDE(CMakeForceCompiler) 
CMAKE_FORCE_C_COMPILER(gcc GNU)
CMAKE_FORCE_CXX_COMPILER(g++ GNU)

## Use the variable PROJECT_NAME for changing the target name


set(CMAKE_CXX_FLAGS "-g -Wall")
# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

## Use all the *.cpp files we found under this folder for the project
set(SRC_DIR "src")
add_subdirectory(${SRC_DIR}) 
