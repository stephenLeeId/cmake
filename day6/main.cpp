#include <stdio.h>

#include "myLog.h"
#include<thread>
int main()
{

    LOGINIT();
    printf("hello world \n");



    for(int i = 0; i < 100000; i ++)
    {

    #ifdef USE_Detect

    LOGEM(" USE_Detect i = %d  ", i);

    #elif USE_Detect_A
    LOGEM(" USE_Detect_A i = %d  ", i);
    #elif USE_Detect_B
    LOGEM(" USE_Detect_B i = %d ", i);

    #elif USE_Detect_C

    LOGEM("USE_Detect_C i = %d  ", i);
    #endif
        

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    
    

}


