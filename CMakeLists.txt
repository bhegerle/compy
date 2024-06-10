cmake_minimum_required(VERSION 3.26)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
llvm_map_components_to_libnames(llvm_libs support)

project(lang)
set (CMAKE_CXX_STANDARD 20)
add_executable(lang "main.cpp" "platform.h" "platform.cpp")
target_compile_features(lang PUBLIC cxx_std_20)

add_subdirectory("ast")

target_precompile_headers(lang PRIVATE 
    <iostream>
)

target_link_libraries(lang ${llvm_libs})
