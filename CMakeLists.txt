cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)

# Check if simulator is the root folder
set(IS_ROOT "${CMAKE_CURRENT_LIST_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")

if(${IS_ROOT})
  project(project VERSION 1.0
                  DESCRIPTION "state_estimator"
                  LANGUAGES CXX)
else(${IS_ROOT})
  set(SIMULATOR_HEADER "${SIMULATOR_HEADER}" PARENT_SCOPE)
endif(${IS_ROOT})

# Find external packages#
find_package(Eigen3 CONFIG REQUIRED)

# Expose PROJECT_SOURCE_DIR to the source code.
add_definitions(-DPROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")


add_subdirectory(external/math_engine)
add_subdirectory(external/mocap_subscriber)