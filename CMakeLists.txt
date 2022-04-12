cmake_minimum_required(VERSION 2.8.12)
project(conan-project)

add_definitions("-std=c17")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(print-libcurl-version src/main.c)
target_link_libraries(print-libcurl-version ${CONAN_LIBS})
