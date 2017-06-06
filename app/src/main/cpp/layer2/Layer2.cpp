//
// Created by Li Yanshun on 2017/6/6.
//

#include "../include/Layer2.h"
#include "../include/Layer1.h"

NetClientLayer2::NetClientLayer2() {
    LOG_E("Create NEtClient Layer2");
}

NetClientLayer2::~NetClientLayer2() {
    LOG_E("Destroy NEtClient Layer2");
}

std::string NetClientLayer2::getClientRequest() {
    return layer2 + net_client.getRequest();
}

std::string NetClientLayer2::getClientResponse() {
    return layer2 + net_client.getResponse();
}