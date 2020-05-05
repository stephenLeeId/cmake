#include "../add/add.h"
#include "../sum/sum.h"
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
