cmake_minimum_required(VERSION 3.19)
project(vsremovedirt CXX)

build_command(target clean)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

string(REGEX REPLACE "([\\/\\-]O)3" "\\12" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
string(REGEX REPLACE "([\\/\\-]O)3" "\\12" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
string(REGEX REPLACE "([\\/\\-]O)3" "\\12" CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}")
string(REGEX REPLACE "([\\/\\-]O)3" "\\12" CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")

add_library(
  ${PROJECT_NAME} SHARED
  src/DupBlocks.cpp
  src/RestoreMotionBlocks.cpp
  src/SCSelect.cpp
  src/shared.cpp
  src/RemoveDirt.cpp
)

find_library(vapoursynth "${VS_LIB_PATH}\\sdk\\lib64")

target_include_directories(${PROJECT_NAME} PRIVATE "${VS_LIB_PATH}\\sdk\\include")