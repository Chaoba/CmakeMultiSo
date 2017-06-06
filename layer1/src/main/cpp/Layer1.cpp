//
// Created by Li Yanshun on 2017/6/6.
//

#include "Layer1.h"

std::string get_response() {
    return "Response from layer1";
}

std::string get_request() {
    return "Request from layer1";
}


__attribute__ ((visibility ("default"))) NET_API_FUNCTIONS_TYPE net_client = {
        get_response,
        get_request,
};