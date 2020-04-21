
cmake_minimum_required(VERSION 3.10)

find_package(gazebo REQUIRED)

set(PLUGIN_PATH ${CMAKE_CURRENT_LIST_DIR}/plugins)

add_library(InvertedPendulumControllerPlugin SHARED ${PLUGIN_PATH}/InvertedPendulumControllerPlugin.cpp)
target_link_libraries(InvertedPendulumControllerPlugin ${GAZEBO_LIBRARIES})
target_include_directories(InvertedPendulumControllerPlugin PUBLIC ${PLUGIN_PATH} ${GAZEBO_INCLUDE_DIRS})
