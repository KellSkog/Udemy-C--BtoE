project(Subliminal VERSION 1.0)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(Subliminal 
                        main.cc
                        test.cc)

target_include_directories(Subliminal PUBLIC
                            "${PROJECT_SOURCE_DIR}"
                            "${PROJECT_SOURCE_DIR}/Inc"
                            "${PROJECT_BINARY_DIR}"
                           )
