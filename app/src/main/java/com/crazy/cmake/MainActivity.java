package com.crazy.cmake;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private String TAG = "MainActivity";

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("hello_ndk");
    }

    private StringBuilder sb = new StringBuilder();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(NativeLib.stringFromJNI());

        TextView tv1 = (TextView) findViewById(R.id.sample_text1);
        tv1.setText(sayHello());

        TextView tv2 = (TextView) findViewById(R.id.sample_text2);
        tv2.setText(hahaFromJni() + "---" + NativeLib.getStringFromJni());

        sb.append("\n");
        sb.append("hahaFromJni(): ");
        sb.append(hahaFromJni());
        sb.append("\n");
        sb.append("javaString2CString(): ");
        sb.append(javaString2CString("我就是我"));
        sb.append("\n");

        int[] ints = newJavaArrayFromNativeCode();
        if (null != ints) {
            for (int i : ints) {
                Log.e(TAG, "i: " + i);
            }
        } else {
            Log.e(TAG, "ints == null");
        }


    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */

    public static native String sayHello();

    public static native String sayStaticHello();

    public native String hahaFromJni();

    public native String javaString2CString(String javaString);

    public native int[] newJavaArrayFromNativeCode();


}
