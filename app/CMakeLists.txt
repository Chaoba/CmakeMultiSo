cmake_minimum_required(VERSION 3.4.1)

include_directories(${CMAKE_SOURCE_DIR}/src/main/cpp/include)
set(jnilibs "${CMAKE_SOURCE_DIR}/src/main/jniLibs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${jnilibs}/${ANDROID_ABI})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -fexceptions -frtti -lstdc++")


ADD_SUBDIRECTORY(${CMAKE_SOURCE_DIR}/src/main/cpp/layer2)
ADD_SUBDIRECTORY(${CMAKE_SOURCE_DIR}/src/main/cpp/layer3)