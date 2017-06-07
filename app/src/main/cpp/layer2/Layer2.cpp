//
// Created by Li Yanshun on 2017/6/6.
//

#include "../include/Layer2.h"

std::string get_response_layer2() {
    LOG_E("layer2 get response");
    const std::string &layer1 = net_client_layer1.getResponse();
    return "layer2:" + layer1;
}

std::string get_request_layer2() {
    LOG_E("layer2 get request");
    const std::string &layer1 = net_client_layer1.getRequest();
    return "layer2:" + layer1;
}


__attribute__ ((visibility ("default"))) NET_API_FUNCTIONS_TYPE_LAYER2 net_client_layer2 = {
        get_response_layer2,
        get_request_layer2,
};