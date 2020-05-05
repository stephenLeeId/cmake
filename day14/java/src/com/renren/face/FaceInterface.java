package com.renren.face;
public class FaceInterface {	
    public final static native float add(float a, float b);
    public final static native float sum(float a, float b, float c);
    
    public final static native String SetString(String path);
    public final static native byte SetByte(byte mByte);
    public final static native byte[] SetByteArray(byte[] mByteArray);

    public final static native int SetInt(int mInt);
    public final static native int[] SetIntArray(int[] mIntArray);

    public final static native long SetLong(long mLong);
    public final static native long[] SetLongArray(long[] mLongArray);

    public final static native float SetFloat(float mFloat);
    public final static native float[] SetFloatArray(float[] mFloatArray);

    public final static native double SetDouble(double mDouble);

    public final static native double[] SetDoubleArray(double[] mDoubleArray);

    

    public final static native int[][] getInt2DArray(int size);

    public final static native FaceInfo getFaceInfo();

    public final static native FaceInfo[] getFaceInfoArray();

    public final static native void setFaceInfo(FaceInfo mFaceInfo);


    static 
    {
        System.out.println("load interface before");
        System.loadLibrary("myProject");
        System.out.println("load interface after");
    }	
}

