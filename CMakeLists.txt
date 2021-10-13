cmake_minimum_required(VERSION 3.0.2)
project(chrono_demo)

find_package(Chrono REQUIRED)

include_directories(${CHRONO_INCLUDE_DIRS})

add_executable(chrono_demo src/chrono_demo.cpp)

target_link_libraries(chrono_demo ${CHRONO_LIBRARIES})
