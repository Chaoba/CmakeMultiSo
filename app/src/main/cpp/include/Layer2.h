//
// Created by Li Yanshun on 2017/6/6.
//

#ifndef CMAKEMUTISO_LAYER2_H
#define CMAKEMUTISO_LAYER2_H


#include <stdio.h>
#include "layer1.h"
#include <string>

using namespace std;

class NetClientLayer2 {
private:
    std::string layer2 = "layer2:";
public:
    NetClientLayer2();

    ~NetClientLayer2();

    std::string getClientResponse();

    std::string getClientRequest();

};

#endif //CMAKEMUTISO_LAYER2_H
