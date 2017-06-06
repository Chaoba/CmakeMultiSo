
//
// Created by Li Yanshun on 2017/6/6.
//
#include <jni.h>
#include <android/log.h>
#include <string>

#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,"unlock",__VA_ARGS__)
extern "C"
{
JNIEXPORT jstring JNICALL
Java_com_mushuichuan_cmakemutiso_MainActivity_requestStringFromJNI(JNIEnv *env, jobject,
    std::string request = "Layer3:"+;
    return env->NewStringUTF(hello.c_str());
}

}
JNIEXPORT jstring JNICALL
Java_com_mushuichuan_cmakemutiso_MainActivity_reponseStringFromJNI(JNIEnv *env, jobject,
                                                                   jobject context) {


}


}