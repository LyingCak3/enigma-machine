
##
# Set CMake "Global" Variables
##

# Set minimum required version
cmake_minimum_required( VERSION 3.23.2 FATAL_ERROR )

set( CMAKE_CXX_STANDARD 98 )
set( CMAKE_CXX_EXTENSIONS FALSE )


##
# Define the Project
##
project( EnigmaMachine VERSION 1.0.0 LANGUAGES CXX )

option( BUILD_SHARED_LIBS  "Build shared libraries.  Turn off to build static libraries" ON )


##
# Project variables
##

# Project wide definitions
set( PROJECT_DEFINTIONS )

# Project wide compiler flags
set( PROJECT_CXX_FLAGS
    $<$<COMPILER_ID:gcc>:-Wall>
    $<$<COMPILER_ID:gcc>:-Werror>
    )

##
# Dive into sub directories
##

add_subdirectory( src )

##
# Install options
##
