# Set the source files from the ./func directory
file(GLOB FUNC_SOURCES "${CMAKE_SOURCE_DIR}/src/func/*.cpp")

message(STATUS "FUNC_HEADERS: ${FUNC_HEADERS}")
message(STATUS "FUNC_SOURCES: ${FUNC_SOURCES}")

# Add the library target
add_library(lib_func ${FUNC_SOURCES})
target_include_directories(lib_func PUBLIC ${CMAKE_SOURCE_DIR}/include)
