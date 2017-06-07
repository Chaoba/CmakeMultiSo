
//
// Created by Li Yanshun on 2017/6/6.
//
#include <jni.h>
#include <string>
#include "../include/Layer2.h"

extern "C"
{
JNIEXPORT jstring JNICALL
Java_com_mushuichuan_cmakemutiso_MainActivity_requestStringFromJNI(JNIEnv *env, jobject) {
    LOG_E("layer3 get request");
    std::string request = "Layer3:" + net_client_layer2.getRequest();
    return env->NewStringUTF(request.c_str());
}

JNIEXPORT jstring JNICALL
Java_com_mushuichuan_cmakemutiso_MainActivity_responseStringFromJNI(JNIEnv *env, jobject) {
    LOG_E("layer3 get response");
    std::string response = "Layer3:" + net_client_layer2.getResponse();
    return env->NewStringUTF(response.c_str());
}
}
