#ifndef __myLog_H_
#define __myLog_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include <iostream>
#include <ratio>
#include <chrono>
#include <mutex>
#include <vector>

#ifdef ANDROID
#include <android/log.h>
#define TAG "JNI"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__)

#endif //ANDROID

#define CLAMPXX(a, s, m) ((a) < (s)? (s) : ((a) > (m) ? (m) : (a)))

void getFiles(std::string cate_dir, std::vector<std::string> &files);

void GetName(std::vector<std::string> &vPath, std::vector<std::string> &vName);
std::string GetLastName(const char * fileName);

std::string getCurrentSystemTime();

long long getCurrentMs();

int LOGINIT();

int LOGEnd();

int LOGSetMaxSpace(int mSize);

int logWrite(char * s);

int rm(std::string file_name);


#ifdef ANDROID

#define mprintf LOGE
#else
#define mprintf printf
#endif

#define  LOGEM(...)  {\
                        char temp[8192] = {0};      \
						sprintf(temp, "%s", getCurrentSystemTime().c_str());  \
						sprintf(temp+strlen(temp), " %s %d ", GetLastName(__FILE__).c_str(), __LINE__);  \
                        sprintf(temp+strlen(temp), __VA_ARGS__); \
						sprintf(temp + strlen(temp), "\n");    \
                        mprintf("%s", temp);   \
						logWrite(temp); \
                    }
#endif
