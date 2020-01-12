#[[
    When CMake processes a project source tree, the entry point is a source file called CMakeLists.txt 
    in the top-level source directory. This file may contain the entire build specification or 
    use the add_subdirectory() command to add subdirectories to the build. 
    Each subdirectory added by the command must also contain a CMakeLists.txt file as the entry point to that directory. 
    For each source directory whose CMakeLists.txt file is processed CMake generates 
    a corresponding directory in the build tree to act as the default working and output directory.]]
cmake_minimum_required(VERSION 3.10)

#[[The top-level CMakeLists.txt file for a project must contain a literal, direct call to the project() command; 
    loading one through the include() command is not sufficient.
    Call the project() command near the top of the top-level CMakeLists.txt, 
    but after calling cmake_minimum_required().]]
project(main VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_VERBOSE_MAKEFILE ON)
configure_file(PrimalConfig.h.in ../Inc/PrimalConfig.h)

add_executable(main 
                        Src/doStuff.cc
                        Src/doOtherStuff.cc
                        Src/main.cc)

target_include_directories(main PUBLIC
                            #"${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/Inc"
                           )
project(catch)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_VERBOSE_MAKEFILE ON)
add_executable(catch 
                Src/doOtherStuff.cc
                Src/doStuff.cc
                Src/catchtest.cc)
target_include_directories(catch PRIVATE
                            "${PROJECT_SOURCE_DIR}/catch2"
                            "${PROJECT_SOURCE_DIR}/Inc"
                           )
project(doctest)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_VERBOSE_MAKEFILE ON)
add_executable(doctest 
                Src/doOtherStuff.cc
                Src/doStuff.cc
                Src/doctest.cc)
target_include_directories(doctest PRIVATE
                            "${PROJECT_SOURCE_DIR}/doctest"
                            "${PROJECT_SOURCE_DIR}/Inc"
                           )