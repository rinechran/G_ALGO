# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (KPU_ALGO)


include_directories(libraries/googletest)


foreach(NUM RANGE 1 9)
	add_subdirectory(src/chapter1/problem${NUM})
endforeach()