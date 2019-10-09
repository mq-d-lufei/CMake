#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_crazy_cmake_NativeLib_getStringFromJni(JNIEnv *env, jclass type) {

    return env->NewStringUTF("i am from c++");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_crazy_cmake_NativeLib_stringFromJNI(
        JNIEnv *env,
        jclass jclazz) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


