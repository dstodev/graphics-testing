# Generate file with DLL export information
include(GenerateExportHeader)
generate_export_header(msdl
	EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/include/msdl_export.hxx
)

target_include_directories(msdl
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
		$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
	PRIVATE
		src
)

file(GLOB public_headers "${CMAKE_CURRENT_LIST_DIR}/*.h*")
list(APPEND public_headers "${CMAKE_BINARY_DIR}/include/msdl_export.hxx")
set_target_properties(msdl PROPERTIES
	PUBLIC_HEADER "${public_headers}"
)
