#add_library(layer1 SHARED IMPORTED )
#set_target_properties(layer1 PROPERTIES IMPORTED_LOCATION "${jnilibs}/${ANDROID_ABI}/liblayer1.so")

add_library(layer2 SHARED Layer2.cpp)

#target_link_libraries(layer2 layer1 log)
target_link_libraries(layer2 log)
