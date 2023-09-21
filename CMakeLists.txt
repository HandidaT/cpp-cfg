cmake_minimum_required(VERSION 3.0)

project(cpp-cfg)

add_library(cpp-cfg INTERFACE)

target_compile_features(cpp-cfg INTERFACE cxx_std_17)

target_sources(cpp-cfg INTERFACE
    ${CMAKE_SOURCE_DIR}/parseOptions.hpp
)

add_executable(cfg testCfg.cpp)

target_link_libraries(cfg PRIVATE cpp-cfg)

target_include_directories(cfg PRIVATE ${CMAKE_SOURCE_DIR})

