cmake_minimum_required(VERSION 3.0.2)
project(simple_fastlio)

SET( CMAKE_CXX_FLAGS "-std=c++11 -O3" )
add_compile_options(-std=c++11)
add_definitions(-DPROJ_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
    sensor_msgs
)

find_package(PCL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(YAML_CPP REQUIRED yaml-cpp)

catkin_package(
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${PCL_INCLUDE_DIRS}
    ${YAML_CPP_INCLUDEDIR}
)

