#include <stdio.h>

void sayHello()
{
	printf("Hello world from OpenMP!\n");
}

void main()
{
	#pragma omp parallel num_threads(4)
	sayHello();
}