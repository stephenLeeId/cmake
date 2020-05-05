#include <stdio.h>

#include "add.h"
#include "sum.h"

int main()
{
    printf("hello world \n");


    float a = 1.0f;
    float b = 3.0f;


    float c = add(a, b);

    printf("add(%f %f) = %f \n", a, b, c);



    float d = sum(a, b, c);

    printf("%f + %f  + %f = %f \n", a, b, c, d);



}


