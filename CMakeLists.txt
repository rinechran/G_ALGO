# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (KPU_ALGO)



foreach(NUM RANGE 1 11)
	add_subdirectory(src/chapter1/problem${NUM})
endforeach()
foreach(NUM RANGE 1 5)
	add_subdirectory(src/chapter2/problem${NUM})
endforeach()
add_subdirectory(libraries/googletest)
