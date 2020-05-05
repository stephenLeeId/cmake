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


  /*
 * Class:     com_renren_face_FaceInterface
 * Method:    getInt2DArray
 * Signature: (I)[[I
 */
JNIEXPORT jobjectArray JNICALL Java_com_renren_face_FaceInterface_getInt2DArray
  (JNIEnv *env, jclass obj, jint mSize)
  {
      jobjectArray result;
      int size = mSize;

     int i;

     jclass intArrCls = env->FindClass("[I");

     if (intArrCls == NULL) {

         return NULL; /* exception thrown */

     }

     result = env->NewObjectArray(size, intArrCls, NULL);

     if (result == NULL) {

         return NULL; /* out of memory error thrown */

     }

     for (i = 0; i < size; i++) {

         jint tmp[256];  /* make sure it is large enough! */

         int j;

         jintArray iarr = env->NewIntArray(size);

         if (iarr == NULL) {

             return NULL; /* out of memory error thrown */

         }

         for (j = 0; j < size; j++) {

             tmp[j] = i + j;

         }

         env->SetIntArrayRegion( iarr, 0, size, tmp);

         env->SetObjectArrayElement( result, i, iarr);

         env->DeleteLocalRef( iarr);

     }

     return result;


  }

JavaVM* vm_global;
jclass jclassFaceInfo;
jmethodID jidFaceInfo;


jmethodID jidFaceInfoSetNum;


void thread_run(void *ptr)
{

    LOGEM("run() .... \n");


    JNIEnv *env = NULL;
    int status;
    bool isAttached = false;
    status = vm_global->GetEnv((void**)&env, JNI_VERSION_1_6);
    if (status < 0) {
#ifdef ANDROID
        if (vm_global->AttachCurrentThread((JNIEnv **)&env, NULL))////将当前线程注册到虚拟机中
#else
        if (vm_global->AttachCurrentThread((void **)&env, NULL))////将当前线程注册到虚拟机中

#endif
        {
            return;
        }
        isAttached = true;
    }
    //实例化该类
    jobject jobject = env->AllocObject(jclassFaceInfo);//分配新 Java 对象而不调用该对象的任何构造函数。返回该对象的引用。
    //调用Java方法
    (env)->CallVoidMethod(jobject, jidFaceInfoSetNum,  521);
 
    if (isAttached) {
        vm_global->DetachCurrentThread();
    }




}

  // 这个函数不用手动调用，加载库时候自动调用，如果不重载就不调用
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
		JNIEnv* env = NULL;
		if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
			return -1;
		}
    //LOGINIT();

		vm_global = vm;

		jclass jclassFaceInfo_temp = env->FindClass("com/renren/face/FaceInfo"); // 获取类 引用

		jclassFaceInfo = (jclass)env->NewGlobalRef(jclassFaceInfo_temp);


     jidFaceInfo =
			env->GetMethodID(jclassFaceInfo, "<init>", "(ILjava/lang/String;[B)V");

      
  jidFaceInfoSetNum = env->GetMethodID(jclassFaceInfo, "setFaceNum", "(I)V");
		

		LOGEM("JNI_OnLoad ok ..... \n");
		return JNI_VERSION_1_6;
	}
// 和上个函数相反
	JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved) {
		JNIEnv* env = NULL;
		if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
			return;
		}
		env->DeleteGlobalRef(jclassFaceInfo);



    LOGEM("JNI_OnUnload ok ..... \n");
	}



  /*
 * Class:     com_renren_face_FaceInterface
 * Method:    getFaceInfo
 * Signature: ()Lcom/renren/face/FaceInfo;
 */
JNIEXPORT jobject JNICALL Java_com_renren_face_FaceInterface_getFaceInfo
  (JNIEnv *env, jclass obj)
  {
      //jmethodID jidFaceInfo =
			//env->GetMethodID(jclassFaceInfo, "<init>", "(ILjava/lang/String;[B)V"); // 获取类的方法，此方法是构造函数
      // "(ILjava/lang/String;[B)V" 解释一下这个字符串，V代表返回空类型， ()号里面代表三个参数， 分解成三个分别是(我用空格隔开)   I   Ljava/lang/String;  [B   分别代表整数，字符string,和byte[] 自己体会

      int faceNum = 1;

      jstring jstr = env->NewStringUTF("hello world ");

      int mSize = 100;
      char buffer[100] = { 0 };
      for (int i = 0; i < mSize; i++)
      {
        buffer[i] = i;
      }
      jbyteArray byteA = env->NewByteArray(mSize);
      env->SetByteArrayRegion(byteA, 0, mSize, (const jbyte*)buffer);
      jobject result = env->NewObject(jclassFaceInfo, jidFaceInfo, faceNum, jstr, byteA); // 返回值不需要要释放
      env->DeleteLocalRef(byteA);  // 中间变量需要释放
      env->DeleteLocalRef(jstr); // 中间变量需要释放
      return result;

  }

  /*
 * Class:     com_renren_face_FaceInterface
 * Method:    getFaceInfoArray
 * Signature: ()[Lcom/renren/face/FaceInfo;
 */
JNIEXPORT jobjectArray JNICALL Java_com_renren_face_FaceInterface_getFaceInfoArray
  (JNIEnv *env, jclass obj)
  {

      //jmethodID jidFaceInfo =
			//env->GetMethodID(jclassFaceInfo, "<init>", "(ILjava/lang/String;[B)V"); // 获取类的方法，此方法是构造函数
      // "(ILjava/lang/String;[B)V" 解释一下这个字符串，V代表返回空类型， ()号里面代表三个参数， 分解成三个分别是(我用空格隔开)   I   Ljava/lang/String;  [B   分别代表整数，字符string,和byte[] 自己体会

      int faceNum = 1;

      jstring jstr = env->NewStringUTF("hello world ");

      int mSize = 100;
      char buffer[100] = { 0 };
      for (int i = 0; i < mSize; i++)
      {
        buffer[i] = i;
      }
      jbyteArray byteA = env->NewByteArray(mSize);
      env->SetByteArrayRegion(byteA, 0, mSize, (const jbyte*)buffer);
      jobject result = env->NewObject(jclassFaceInfo, jidFaceInfo, faceNum, jstr, byteA); // 返回值不需要要释放

      faceNum = 2;
      jobject result1 = env->NewObject(jclassFaceInfo, jidFaceInfo, faceNum, jstr, byteA); // 返回值不需要要释放
      env->DeleteLocalRef(byteA);  // 中间变量需要释放
      env->DeleteLocalRef(jstr); // 中间变量需要释放

      jobjectArray resultArray = env->NewObjectArray(2,jclassFaceInfo, result);
      env->SetObjectArrayElement(resultArray, 1, result1);

      env->DeleteLocalRef(result);
      env->DeleteLocalRef(result1);

      return resultArray;


  }


  /*
 * Class:     com_renren_face_FaceInterface
 * Method:    setFaceInfo
 * Signature: (Lcom/renren/face/FaceInfo;)V
 */
JNIEXPORT void JNICALL Java_com_renren_face_FaceInterface_setFaceInfo
  (JNIEnv *env, jclass cls, jobject obj)
  {



      //jclass staticsitcs = env->GetObjectClass(obj); // 可以替换jclassFaceInfo

      //jclassFaceInfo = staticsitcs;

      //LOGEM(" jclassFaceInfo = %d staticsitcs = %d \n", jclassFaceInfo, staticsitcs);

      jmethodID id_getBase64CutImage = env->GetMethodID(jclassFaceInfo, "getBase64CutImage","()Ljava/lang/String;");

      jobject Base64CutImage = env->CallObjectMethod(obj, id_getBase64CutImage);

      jstring t_base64 = (jstring)Base64CutImage;

      char* c_Base64CutImage_t = (char *)env->GetStringUTFChars(t_base64,0);

      LOGEM("c_Base64CutImage_t = %s \n",c_Base64CutImage_t);
      env->ReleaseStringUTFChars(t_base64, c_Base64CutImage_t);

      jmethodID id_getByteCutImage = env->GetMethodID(jclassFaceInfo, "getByteCutImage","()[B");

      jbyteArray jdata = (jbyteArray)(env->CallObjectMethod(obj, id_getByteCutImage));


      char *c_getByteCutImage = ( char *)env->GetByteArrayElements(jdata, 0);


      int length = env->GetArrayLength(jdata);

      for(int i = 0; i < length; i ++)
      {
          LOGEM("cpp c_getByteCutImage[%d] = %d \n", i, c_getByteCutImage[i]);

          // 改变值会影响java层么，和下面有关系
          
      }

      env->ReleaseByteArrayElements(jdata, (jbyte*)c_getByteCutImage, JNI_ABORT); //JNI_COMMIT 同步到java层  JNI_ABORT 不同步到java层



    
      jmethodID id_getfaceNum = env->GetMethodID(jclassFaceInfo, "getfaceNum","()I");

      int faceNum = env->CallIntMethod(obj, id_getfaceNum);
      LOGEM("faceNum ==== %d \n", faceNum);
      

      jfieldID jf_Base64CutImage = env->GetFieldID(jclassFaceInfo, "Base64CutImage", "Ljava/lang/String;");

      jstring dateString =(jstring)env->GetObjectField(obj,jf_Base64CutImage);

      char* c_Base64CutImage = (char *)env->GetStringUTFChars(dateString,0);

      LOGEM("c_Base64CutImage = %s \n",c_Base64CutImage);
      env->ReleaseStringUTFChars(dateString, c_Base64CutImage);

      jfieldID jf_faceNum = env->GetFieldID(jclassFaceInfo, "faceNum", "I");

      int faceNum1 = env->GetIntField(obj, jf_faceNum);

      LOGEM("faceNum1 ==== %d \n", faceNum);

      jfieldID jf_byteCutImage = env->GetFieldID(jclassFaceInfo, "byteCutImage", "[B");

     jbyteArray t_byteCutImage = (jbyteArray)env->GetObjectField(obj, jf_byteCutImage);

      c_getByteCutImage = ( char *)env->GetByteArrayElements(t_byteCutImage, 0);
	   
     length = env->GetArrayLength(t_byteCutImage);

      for(int i = 0; i < length; i ++)
      {
          LOGEM("111 cpp c_getByteCutImage[%d] = %d \n", i, c_getByteCutImage[i]);

          // 改变值会影响java层么，和下面有关系
          c_getByteCutImage[i] += 10;
      }

      env->ReleaseByteArrayElements(t_byteCutImage, (jbyte*)c_getByteCutImage, JNI_COMMIT); //JNI_COMMIT 同步到java层  JNI_ABORT 不同步到java层


      //void * p = NULL;
      //std::thread t_th(thread_run, p);

      //t_th.join();


  }
