add_library(layer3 SHARED Layer3.cpp)

add_library(layer2sdk SHARED IMPORTED )
set_target_properties(layer2sdk PROPERTIES IMPORTED_LOCATION "${jnilibs}/${ANDROID_ABI}/liblayer2.so")

find_library( log-lib log )

target_link_libraries(layer3 layer2sdk ${log-lib})
