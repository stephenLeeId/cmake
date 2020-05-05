readme.txt open a Terminal
1$ cd day13/java/src/com/renren/face
2$ javac FaceInterface.java
3$ cd day13/java/src
4$ javah -classpath ./ -d ../../src/java_interface -jni com.renren.face.FaceInterface

...  writer com_renren_face_FaceInterface.cpp ...

5$ cd day13
6$ mkdir build 
7$ cd build
8$ cmake ..
9$ make 

10$ cd day13/java/src
11$ sh run.sh






