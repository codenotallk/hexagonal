cmake_minimum_required (VERSION 3.7.0)
project (hexagonal)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_BUILD_TYPE Debug)

add_executable (hexagonal "")

target_link_libraries (hexagonal PUBLIC sat pthread)

target_sources (hexagonal
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/adapter/keyboard.c
    ${CMAKE_CURRENT_LIST_DIR}/src/adapter/display.c
    ${CMAKE_CURRENT_LIST_DIR}/src/adapter/udp_server.c
    ${CMAKE_CURRENT_LIST_DIR}/src/domain/typewriter.c
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
)

target_include_directories (hexagonal
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/adapter
    ${CMAKE_CURRENT_LIST_DIR}/src/domain
)