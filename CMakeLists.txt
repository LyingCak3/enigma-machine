
##
# Set CMake "Global" Variables
##

# Set minimum required version
cmake_minimum_required( VERSION 3.23.2 FATAL_ERROR )

set( CMAKE_CXX_STANDARD 98 )
set( CMAKE_CXX_EXTENSIONS FALSE )

set( CMAKE_POSITION_INDEPENDENT_CODE TRUE )

set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/libs )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/libs )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin  )


##
# Define the Project
##
project( EnigmaMachine VERSION 1.0.0 LANGUAGES CXX )

option( BUILD_SHARED_LIBS  "Build shared libraries.  Turn off to build static libraries" ON )


##
# Project variables
##


# Project install variables
set( PROJECT_EXPORT ${PROJECT_NAME}-targets )
set( PROJECT_INSTALL_NAMESPACE ${PROJECT_NAME}:: )

set( PROJECT_INSTALL_BIN bin/$<$<NOT:$<CONFIG:Release>>:$<CONFIG>> )
set( PROJECT_INSTALL_LIB lib/${PROJECT_NAME}-${PROJECT_VERSION} )
set( PROJECT_INSTALL_CMAKE_CONFIG lib/cmake/${PROJECT_NAME}-${PROJECT_VERSION} )
set( PROJECT_INSTALL_INC include/${PROJECT_NAME}-${PROJECT_VERSION} )
set( PROJECT_INSTALL_SHARE share/${PROJECT_NAME}-${PROJECT_VERSION} )

# Project wide definitions
set( PROJECT_DEFINTIONS )

# Project wide compiler flags
set( PROJECT_CXX_FLAGS
    $<$<CXX_COMPILER_ID:gcc>:-Wall>
    $<$<CXX_COMPILER_ID:gcc>:-Werror>
    -save-temps
    )

# Project wide linker flags
set( PROJECT_LINKER_FLAGS
    $<$<CXX_COMPILER_ID:gcc>:LINKER:--no-undefined>
    $<$<CXX_COMPILER_ID:gcc>:LINKER:--error-unresolved-symbols>
    )

##
# Dive into sub directories
##

add_subdirectory( src )

##
# Install options
##

install( EXPORT ${PROJECT_EXPORT} 
        DESTINATION ${PROJECT_INSTALL_CMAKE_CONFIG} COMPONENT dev
        NAMESPACE ${PROJECT_INSTALL_NAMESPACE}
    )
