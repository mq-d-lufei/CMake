//
// Created by feaoes on 2018/3/5.
//
#include <jni.h>
#include <stdio.h>
#include "AndroidLog.h"

JNIEXPORT jstring JNICALL
Java_com_crazy_cmake_MainActivity_sayHello(JNIEnv *env, jobject instance) {

    return (*env)->NewStringUTF(env, "this String come from hello_ndk library.");
}

JNIEXPORT jstring JNICALL
Java_com_crazy_cmake_MainActivity_sayStaticHello(JNIEnv *env, jclass type) {

    return (*env)->NewStringUTF(env, "sayStaticHello...");
}

JNIEXPORT jstring JNICALL
Java_com_crazy_cmake_MainActivity_hahaFromJni(JNIEnv *env, jobject instance) {

    return (*env)->NewStringUTF(env, "ha ha ha");
}


JNIEXPORT jstring JNICALL
Java_com_crazy_cmake_MainActivity_javaString2CString(JNIEnv *env, jobject instance,
                                                     jstring javaString) {

    const char *str;
    const jbyte *strJbyte;
    jboolean isCopy = 1;

    str = (*env)->GetStringUTFChars(env, javaString, &isCopy);

    if (0 != str) {
        printf("java str: %s", str);
        LOGE("java str: %s", str);

        if (JNI_TRUE == isCopy) {
            printf("C string is a copy of the Java string.");
            LOGE("C string is a copy of the Java string.");
        } else {
            printf("C string points to actual string.");
            LOGE("C string points to actual string.");
        }
    }

    (*env)->ReleaseStringUTFChars(env, javaString, str);

    return javaString;
}

JNIEXPORT jarray JNICALL
Java_com_crazy_cmake_MainActivity_newJavaArrayFromNativeCode(JNIEnv *env, jobject instance) {

    jintArray javaArray;
    jsize arrayLength;
    javaArray = (*env)->NewIntArray(env, 10);
    if (NULL != javaArray) {
        arrayLength = (*env)->GetArrayLength(env, javaArray);
        for (jsize i = 0; i < arrayLength; i++) {
        }
        return javaArray;
    }
    return NULL;
}

