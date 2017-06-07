//
// Created by Li Yanshun on 2017/6/6.
//

#include "Layer1.h"

std::string get_response() {
    LOG_E("layer1 get response");
    return "layer1:Response";
}

std::string get_request() {
    LOG_E("layer1 get request");
    return "layer1:Request";
}


__attribute__ ((visibility ("default"))) NET_API_FUNCTIONS_TYPE_LAYER1 net_client_layer1 = {
        get_response,
        get_request,
};