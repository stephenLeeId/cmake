mkdir -p android_build
rm -rf ./build
ln -s ./android_build ./build
cd android_build 
#/home/zhangli/workplace/cmake_study/android-ndk-r16b/build/cmake   "armeabi-v7a" "x86_64"
export ndkroot=./../android-ndk-r18b
cmake .. -DCMAKE_TOOLCHAIN_FILE=${ndkroot}/build/cmake/android.toolchain.cmake \
        -DANDROID_NDK=${ndkroot} \
        -DCMAKE_BUILD_TYPE=Release  \
        -DANDROID_ABI="armeabi-v7a" \
        -DANDROID_NATIVE_API_LEVEL=android-21
make 
