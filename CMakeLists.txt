cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(rl_example)
enable_testing()

find_package(Torch REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

set(RL_EXAMPLE_STATIC_LIB rl_example_static)
set(RL_EXAMPLE_SHARED_LIB rl_example_shared)

add_subdirectory(src)
