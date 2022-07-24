
set( target EnigmaDriver )

set( sources
    main.cpp
    )

set( public_headers
    )

set( private_headers
    )

add_executable( ${target} ${sources} )

target_sources( ${target}
        PRIVATE FILE_SET private_headers FILES ${private_headers} TYPE HEADERS
        PUBLIC  FILE_SET public_headers FILES ${public_headers} TYPE HEADERS
    )

target_compile_definitions( ${target} PRIVATE ${PROJECT_DEFINITIONS} )

target_compile_options( ${target} PRIVATE ${PROJECT_CXX_FLAGS} )

target_include_directories( ${target} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )

target_link_libraries( ${target} PRIVATE EnigmaLib )

target_link_options( ${target} PRIVATE ${PROJECT_LINKER_FLAGS} )

install( TARGETS ${target}
        EXPORT  ${PROJECT_EXPORT}
        ARCHIVE DESTINATION ${PROJECT_INSTALL_LIB} COMPONENT lib
        LIBRARY DESTINATION ${PROJECT_INSTALL_LIB} COMPONENT lib
        RUNTIME DESTINATION ${PROJECT_INSTALL_BIN} COMPONENT bin
        FILE_SET public_headers DESTINATION ${PROJECT_INSTALL_INC} COMPONENT dev
    )
