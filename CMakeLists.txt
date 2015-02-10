cmake_minimum_required(VERSION 3.1)

project(APUE)

set(PROJECT_BINARY_DIR bin)
set(PROJECT_SOURCE_DIR src)

add_compile_options(
  "-Wall"
  "-pedantic"
  "-std=c99"
  )

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(${PROJECT_SOURCE_DIR})
