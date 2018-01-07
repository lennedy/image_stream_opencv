cmake_minimum_required(VERSION 2.8.3)
project(image_stream_opencv)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  rospy
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES image_stream_opencv
#  CATKIN_DEPENDS cv_bridge image_transport roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
	${OpenCV_INCLUDE_DIRS}
)


add_executable(readImage src/ReadImage.cpp)
target_link_libraries(readImage ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

