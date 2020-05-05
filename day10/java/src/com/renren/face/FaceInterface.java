package com.renren.face;
public class FaceInterface {	
    public final static native float add(float a, float b);
    public final static native float sum(float a, float b, float c);
    static 
    {
        System.out.println("load interface before");
        System.loadLibrary("myProject");
        System.out.println("load interface after");
    }	
}

