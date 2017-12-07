//
// Created by Li Yanshun on 2017/6/6.
//

#ifndef CMAKEMUTISO_LAYER2_H
#define CMAKEMUTISO_LAYER2_H


#include <stdio.h>
#include "layer1.h"
#include <string>
#include <android/log.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
    std::string (*getResponse)();

    std::string (*getRequest)();

    void (*init)();

} NET_API_FUNCTIONS_TYPE_LAYER2;

extern __attribute__ ((visibility ("default"))) NET_API_FUNCTIONS_TYPE_LAYER2 net_client_layer2;

#ifdef __cplusplus
}
#endif

#endif //CMAKEMUTISO_LAYER2_H
