#include <stdio.h>

void sayHello()
{
    printf("Hello world from openMP!\n");
}

void main()
{
    #pragma omp parallel
    sayHello();
}