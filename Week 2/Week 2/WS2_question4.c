#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int counter=0;


typedef struct{
    int start;
    int end;
}count;

void *countPrime(void *p){
    count *parameter;
    parameter = (count *)p;
    int start = parameter->start;
    int end = parameter->end;
    int i,c;
    for(i=start;i<end;i++){
        for(c=2;c<=i-1;c++){
            if(i%c==0){
                break;
            }
        }
         if (counter >= 5)
            {
                pthread_cancel(pthread_self());
            }
        if(c == i){
            counter+=1;
            printf("%d is prime.\n",i);
        }
    }
}

void main()
{
    int n,i;
    printf("Enter number of threads:");
    scanf("%d",&n);
    pthread_t thread[n];
    count range[n]; 
    int split = 1000/n;

    for(i=0;i<n;i++){
        if(i==0){
            range[i].start = 1; 
            range[i].end = split;
        }
        else{
            range[i].start = range[i-1].end + 1;
            range[i].end = range[i-1].end + split; 
        } 
    }

    for ( i = 0; i < n; i++)
    {
        pthread_create(&thread[i],NULL,countPrime,(void *)&range[i]);
    }


    for ( i = 0; i < n; i++)
    {
        pthread_join(thread[i],NULL);
    }
    printf("Total prime:%d",counter);
}