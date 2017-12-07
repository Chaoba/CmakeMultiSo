cmake_minimum_required(VERSION 3.4.1)

include_directories(${CMAKE_SOURCE_DIR}/src/main/cpp)
set(jnilibs "${CMAKE_SOURCE_DIR}/src/main/jniLibs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${jnilibs}/${ANDROID_ABI})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++14 -pthread -DMGULK_LOG_STDERR=1 -Wall -Wextra -Wnon-virtual-dtor -g")


add_library(layer1 SHARED src/main/cpp/Layer1.cpp )

find_library(log-lib  log )

target_link_libraries(layer1 ${log-lib} )