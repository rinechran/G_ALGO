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
foreach(NUM RANGE 1 9)
	add_subdirectory(src/chapter3/problem${NUM})
endforeach()
foreach(NUM RANGE 1 9)
	add_subdirectory(src/chapter4/problem${NUM})
endforeach()

foreach(NUM RANGE 1 4)
	add_subdirectory(src/chapter5/problem${NUM})
endforeach()

foreach(NUM RANGE 1 10)
	add_subdirectory(src/chapter6/problem${NUM})
endforeach()

foreach(NUM RANGE 1 7)
	add_subdirectory(src/chapter7/problem${NUM})
endforeach()

foreach(NUM RANGE 1 1)
	add_subdirectory(src/chapter8/problem${NUM})
endforeach()