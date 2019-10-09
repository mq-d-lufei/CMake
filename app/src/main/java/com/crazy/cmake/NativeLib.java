package com.crazy.cmake;

/**
 * Created by feaoes on 2018/3/21.
 */

public class NativeLib {

    static {
        System.loadLibrary("native-lib");
    }

    public static native String getStringFromJni();

    public static native String stringFromJNI();
}
