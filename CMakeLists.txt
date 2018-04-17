cmake_minimum_required(VERSION 3.5)
project( Quad VERSION 0.1.1 )

add_library(Quad STATIC src/Quad.c)

target_include_directories( Quad PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_sources( Quad PRIVATE ${PROJECT_SOURCE_DIR}/src/Quad )
target_sources( Quad PUBLIC ${PROJECT_SOURCE_DIR}/include/Quad )

set_target_properties(Quad
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)
