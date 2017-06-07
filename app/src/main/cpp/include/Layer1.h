//
// Created by Li Yanshun on 2017/6/6.
//

#ifndef SINGLELIB_LAYER1_H
#define SINGLELIB_LAYER1_H

#include <stddef.h>
#include <android/log.h>
#include <jni.h>
#include <string>

#define  LOG_E(...)  __android_log_print(ANDROID_LOG_ERROR,"Netclient",__VA_ARGS__)

#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
    std::string (*getResponse)();

    std::string (*getRequest)();

} NET_API_FUNCTIONS_TYPE_LAYER1;

extern __attribute__ ((visibility ("default"))) NET_API_FUNCTIONS_TYPE_LAYER1 net_client_layer1;

#ifdef __cplusplus
}
#endif

#endif //SINGLELIB_LAYER1_H

