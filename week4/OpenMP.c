#include <stdio.h>

void sayHello()
{
    #pragma omp parallel num_threads(3)
    printf("Hello world from OpenMP\n");

}

void main(){
    sayHello();
}