cmake_minimum_required(VERSION 3.0.0.)

project(fork_nohup)

include_directories(include)

aux_source_directory(src include_src)

add_executable(main main.cpp ${include_src})

add_compile_options(std=c++11)

target_link_libraries(main pthread)


