cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
Project(demo)

find_package(catkin REQUIRED COMPONENTS roscpp std_msgs sensor_msgs geometry_msgs message_filters message_generation)

add_message_files(
  FILES
  DemoMsg.msg
  )

add_service_files(
  FILES
  DemoSrv.srv
  )

generate_messages(
  DEPENDENCIES
  std_msgs
  sensor_msgs
)

catkin_package()
set(CMAKE_BUILD_TYPE RelWithDebInfo)

# PCL
find_package(PCL 1.7 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# OpenCV
find_package(OpenCV REQUIRED)

include_directories(include
  ${catkin_INCLUDE_DIRS})
# Head files
set(HEAD_FILES
  include/demo/demo.h
  src/demo_impl.h
  )

set(SOURCE_FILES
  src/demo.cpp
  src/demo_impl.cpp
  )

add_library(demo ${SOURCE_FILES} ${HEAD_FILES})
target_link_libraries(demo ${PCL_LIBRARIES} ${OpenCV_LIBRARIES} ${catkin_LIBRARIES})

# Executable
add_executable(demo_node src/main.cpp)
target_link_libraries(demo_node demo ${PCL_LIBRARIES} ${OpenCV_LIBRARIES} ${catkin_LIBRARIES})
