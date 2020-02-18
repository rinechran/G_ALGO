# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (KPU_ALGO)


include_directories(libraries/googletest)

add_subdirectory(src/chapter1/Problem01)


add_subdirectory(tests)

