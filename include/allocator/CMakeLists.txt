cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(allocator VERSION 0.0.1)

add_library(allocator STATIC allocator.cpp allocator.hpp)

set_target_properties(allocator PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

target_include_directories(allocator
  PRIVATE
  ${CMAKE_SOURCE_DIR}/build
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(allocator PRIVATE -g -Wall -Wextra -Werror -pedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(allocator PRIVATE /W4 /WX)
endif()