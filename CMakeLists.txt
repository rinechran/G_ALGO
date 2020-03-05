# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (KPU_ALGO)



foreach(NUM RANGE 1 11)
	add_subdirectory(src/chapter1/problem${NUM})
endforeach()
foreach(NUM RANGE 1 10)
	add_subdirectory(src/chapter2/problem${NUM})
endforeach()
foreach(NUM RANGE 1 2)
	add_subdirectory(src/chapter3/problem${NUM})
endforeach()
