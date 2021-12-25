#include <stdio.h>
#include<omp.h>
int primeCnt =0;
void main()

{
int i, c;
printf("Prime numbers between 1 and 1000 are :\n");
#pragma omp parallel num_threads(5)
for(i = 1; i <= 1000; i++)
{
for(c = 2; c <= i - 1; c++)
{
if ( i % c == 0 )
	break;
}
if ( c == i ){
		primeCnt++;

		printf("Thread Id:%d found prime number %d\n",omp_get_thread_num(), i );
	}
  }
}
