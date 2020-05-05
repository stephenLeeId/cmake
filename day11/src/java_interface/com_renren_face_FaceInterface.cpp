#include "../add/add.h"
#include "../sum/sum.h"
#include "myLog.h"
#include "com_renren_face_FaceInterface.h"

JNIEXPORT jfloat JNICALL Java_com_renren_face_FaceInterface_add
  (JNIEnv *env, jclass cls, jfloat a, jfloat b)
  {
      return add(a, b);
  }

/*
 * Class:     com_renren_face_FaceInterface
 * Method:    sum
 * Signature: (FFF)F
 */
JNIEXPORT jfloat JNICALL Java_com_renren_face_FaceInterface_sum
  (JNIEnv *env, jclass cls, jfloat a, jfloat b, jfloat c) 
  {
      return sum(a, b, c);
  }


/*
 * Class:     com_renren_face_FaceInterface
 * Method:    SetString
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_renren_face_FaceInterface_SetString
  (JNIEnv *env, jclass obj, jstring path)
  {

    const char* str;
    
    str = env->GetStringUTFChars(path, NULL); // 直接NULL, 系统自动决定拷贝还是引用

    if(str == NULL) {
 
        return NULL; /* OutOfMemoryError already thrown */
 
    }
 
    LOGEM("cpp str = %s \n", str);
 
    env->ReleaseStringUTFChars(path, str);
 
  
    char* tmpstr = "return string succeeded";
 
    jstring rtstr = env->NewStringUTF(tmpstr);
 
    return rtstr;

  }

/*
 * Class:     com_renren_face_FaceInterface
 * Method:    SetByte
 * Signature: (B)B
 */
JNIEXPORT jbyte JNICALL Java_com_renren_face_FaceInterface_SetByte
  (JNIEnv *env, jclass obj, jbyte mByte)
  {

    LOGEM("cpp mByte = %c \n", mByte);

    return mByte + 1;

  }

/*
 * Class:     com_renren_face_FaceInterface
 * Method:    SetByteArray
 * Signature: ([B)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_renren_face_FaceInterface_SetByteArray
  (JNIEnv *env, jclass obj, jbyteArray mByteArray)
  {
   
    jboolean isCopy = false;
    LOGEM("cpp isCopy = %d \n", isCopy);
    char *preview = ( char *)env->GetByteArrayElements(mByteArray, &isCopy);

    LOGEM("cpp isCopy = %d \n", isCopy);
    int length = env->GetArrayLength(mByteArray);

    for(int i = 0; i < length; i ++)
    {
        LOGEM("cpp mByteArray[%d] = %d \n", i, preview[i]);

        // 改变值会影响java层么，和下面有关系
        preview[i] = preview[i] + 1;
    }


    env->ReleaseByteArrayElements(mByteArray, (jbyte*)preview, JNI_ABORT); //JNI_COMMIT 同步到java层  JNI_ABORT 不同步到java层

    // 如何返回一个 数组呢

    char retByteArray_c[10] = {1, 2, 3, 4, 5, 6, 7,8, 9, 0};
    jbyteArray retByteArray = env->NewByteArray(10);

		env->SetByteArrayRegion(retByteArray, 0, 10, (jbyte *)retByteArray_c);
    // 如果retByteArray_c 是堆空间，请在这里释放
    //  返回值不需要释放，什么时候释放，由java jvm 决定
    return retByteArray;

  }

  /*
 * Class:     com_renren_face_FaceInterface
 * Method:    SetInt
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_renren_face_FaceInterface_SetInt
  (JNIEnv *env, jclass obj, jint mInt)
{

  LOGEM("Java_com_renren_face_FaceInterface_SetInt mInt = %d \n", mInt);

  return  mInt + 1;

}
/*
 * Class:     com_renren_face_FaceInterface
 * Method:    SetIntArray
 * Signature: ([I)[I
 */
JNIEXPORT jintArray JNICALL Java_com_renren_face_FaceInterface_SetIntArray
  (JNIEnv *env, jclass obj, jintArray mIntArray)
  {

    int *preview = ( int *)env->GetIntArrayElements(mIntArray, NULL);
    int length = env->GetArrayLength(mIntArray);

    for(int i = 0; i < length; i ++)
    {
        LOGEM("cpp mIntArray[%d] = %d \n", i, preview[i]);

        // 改变值会影响java层么，和下面有关系
        preview[i] = preview[i] + 1;
    }
     env->ReleaseIntArrayElements(mIntArray, (jint*)preview, JNI_COMMIT); //JNI_COMMIT 同步到java层  JNI_ABORT 不同步到java层

    // 如何返回一个 数组呢
    

    int * retIntArray_c = new int[10];
    retIntArray_c[0] = 555;retIntArray_c[1] = 666;retIntArray_c[2] = 777;retIntArray_c[3] = 888;
    jintArray retIntArray = env->NewIntArray(10);

		env->SetIntArrayRegion(retIntArray, 0, 10, (jint *)retIntArray_c);
    // 如果retByteArray_c 是堆空间，请在这里释放
    delete retIntArray_c;
    //  返回值不需要释放，什么时候释放，由java jvm 决定
    return retIntArray;

  }


/*
 * Class:     com_renren_face_FaceInterface
 * Method:    SetLong
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_renren_face_FaceInterface_SetLong
  (JNIEnv *env, jclass obj, jlong mLong)
  {
      return mLong + 1;
  }

/*
 * Class:     com_renren_face_FaceInterface
 * Method:    SetLongArray
 * Signature: ([J)[J
 */
JNIEXPORT jlongArray JNICALL Java_com_renren_face_FaceInterface_SetLongArray
  (JNIEnv *env, jclass obj, jlongArray mLongArray)
  {
    long *preview = ( long *)env->GetLongArrayElements(mLongArray, NULL);
    int length = env->GetArrayLength(mLongArray);

    for(int i = 0; i < length; i ++)
    {
        LOGEM("cpp mLongArray[%d] = %d \n", i, preview[i]);

        // 改变值会影响java层么，和下面有关系
        preview[i] = preview[i] + 1;
    }
     env->ReleaseLongArrayElements(mLongArray, (jlong*)preview, JNI_COMMIT); //JNI_COMMIT 同步到java层  JNI_ABORT 不同步到java层

    // 如何返回一个 数组呢

    std::vector<long> mVec;
    mVec.push_back(555);
    mVec.push_back(666);
    mVec.push_back(777);
    mVec.push_back(888);
    jlongArray retLongArray = env->NewLongArray(mVec.size());

		env->SetLongArrayRegion(retLongArray, 0, mVec.size(), (jlong *)mVec.data());
    // mVec 可以自动释放

    // 返回值不需要释放，什么时候释放，由java jvm 决定
    return retLongArray;
  }



/*
 * Class:     com_renren_face_FaceInterface
 * Method:    SetFloat
 * Signature: (F)F
 */
JNIEXPORT jfloat JNICALL Java_com_renren_face_FaceInterface_SetFloat
  (JNIEnv *env, jclass obj, jfloat mFloat)
  {
      return mFloat + 1.1f;
  }

  /*
 * Class:     com_renren_face_FaceInterface
 * Method:    SetFloatArray
 * Signature: ([F)[F
 */
JNIEXPORT jfloatArray JNICALL Java_com_renren_face_FaceInterface_SetFloatArray
  (JNIEnv *env, jclass obj, jfloatArray mFloatArray)
  {
    float *preview = ( float *)env->GetFloatArrayElements(mFloatArray, NULL);
    int length = env->GetArrayLength(mFloatArray);

    for(int i = 0; i < length; i ++)
    {
        LOGEM("cpp mFloatArray[%d] = %f \n", i, preview[i]);

        // 改变值会影响java层么，和下面有关系
        preview[i] = preview[i] + 1;
    }
     env->ReleaseFloatArrayElements(mFloatArray, (jfloat*)preview, JNI_COMMIT); //JNI_COMMIT 同步到java层  JNI_ABORT 不同步到java层

    // 如何返回一个 数组呢

    std::vector<float> mVec;
    mVec.push_back(555.3f);
    mVec.push_back(666.4f);
    mVec.push_back(777.5f);
    mVec.push_back(888.6f);
    jfloatArray retFloatArray = env->NewFloatArray(mVec.size());

		env->SetFloatArrayRegion(retFloatArray, 0, mVec.size(), (jfloat *)mVec.data());
    // mVec 可以自动释放

    // 返回值不需要释放，什么时候释放，由java jvm 决定
    return retFloatArray;

  }

  /*
 * Class:     com_renren_face_FaceInterface
 * Method:    SetDouble
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_renren_face_FaceInterface_SetDouble
  (JNIEnv *env, jclass obj, jdouble mDouble)
  {
      return mDouble + 5.5;
  }

/*
 * Class:     com_renren_face_FaceInterface
 * Method:    SetDoubleArray
 * Signature: ([D)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_com_renren_face_FaceInterface_SetDoubleArray
  (JNIEnv *env, jclass obj, jdoubleArray mDoubleArray)
  {
    double *preview = ( double *)env->GetDoubleArrayElements(mDoubleArray, NULL);
    int length = env->GetArrayLength(mDoubleArray);

    for(int i = 0; i < length; i ++)
    {
        LOGEM("cpp mLongArray[%d] = %lf \n", i, preview[i]);

        // 改变值会影响java层么，和下面有关系
        preview[i] = preview[i] + 1;
    }
     env->ReleaseDoubleArrayElements(mDoubleArray, (jdouble*)preview, JNI_COMMIT); //JNI_COMMIT 同步到java层  JNI_ABORT 不同步到java层

    // 如何返回一个 数组呢

    std::vector<double> mVec;
    mVec.push_back(555.89898);
    mVec.push_back(666.89898);
    mVec.push_back(777.89898);
    mVec.push_back(888.89898);
    jdoubleArray retDoubleArray = env->NewDoubleArray(mVec.size());

		env->SetDoubleArrayRegion(retDoubleArray, 0, mVec.size(), (jdouble *)mVec.data());
    // mVec 可以自动释放

    // 返回值不需要释放，什么时候释放，由java jvm 决定
    return retDoubleArray;

  }
