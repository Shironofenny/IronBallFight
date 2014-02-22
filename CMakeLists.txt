# CMake project file for W4160 Computer Graphics
# Changxi Zheng (cxz@cs.columbia.edu)
# ===============================================
# Modified by Yihan Zhang
project(IBF)

cmake_minimum_required(VERSION 2.6.2 FATAL_ERROR)

option(BUILD_DEBUG "Turn on the debug mode" OFF)

# ===================================================================
## Compiler
# set compiler flags for debug/release
if ( BUILD_DEBUG )
    add_definitions(-DDEBUG)
    set(CMAKE_BUILD_TYPE Debug)
else ()
    add_definitions(-Wno-deprecated)
    set(CMAKE_BUILD_TYPE Release)
endif ()

# set output executable path
set (EXECUTABLE_OUTPUT_PATH ../bin)

# add compiler flags
set (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

# add header files and source files
file (GLOB IBF_HEADERS "./src/*.h" "./src/GameEngine/*.h" "./src/GameEngine/Utilities/*.h" "./src/GameEngine/Interaction/*.h")
file (GLOB IBF_SOURCES "./src/*.cpp" "./src/GameEngine/*.cpp" "./src/GameEngine/Utilities/*.cpp" "./src/GameEngine/Interaction/*.cpp")

# package for opengl and glut
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
	include_directories (${OPENGL_INCLUDEDIR})
	set (IBF_LIBRARIES ${IBF_LIBRARIES} ${OPENGL_LIBRARIES})
endif (OPENGL_FOUND)

find_package(GLUT REQUIRED)
if (GLUT_FOUND)
	include_directories (${GLUT_INCLUDEDIR})
	set (IBF_LIBRARIES ${IBF_LIBRARIES} ${GLUT_LIBRARIES})
endif (GLUT_FOUND)

add_executable(IronBallFight ${IBF_SOURCES})
target_link_libraries(IronBallFight ${IBF_LIBRARIES})
