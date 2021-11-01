#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

// thread 0 (3334) -> start ->  | end -> 0-3333 (including end number)
// thread 1 (3334) -> start ->  | end -> 3334 - 6666
// thread 2 (3334) -> start ->  | end -> 6667 - 9999
typedef struct{
    int start;
    int end;
} 
range;

void *prime(void *ptr)
{
    int i,c;
    int *counter;
    counter = malloc(sizeof(int));
    int counts = 0;
    
    range *p = ptr;  
    int nstart=p->start, nend=p->end;  

    for(i=nstart; i<=nend; i++){  
        for(c=2; c<=i-1; c++) { 
            if ( i%c==0 ) {
            break; 
        }

        } 
        if ( c==i ) {  
            counts = counts + 1;            
    }  

    }
    *counter = counts; 
    pthread_exit(counter);
}


void main(){
    void *pointer;
    int count = 1000;
    int thread;
    printf("Number of threads:");
    scanf("%d", &thread);
    int sliceList[thread]; //3 slice boxes

    int rem = count % thread;


    for (int i =0; i<thread; i++){
        sliceList[i] = count / thread; //1st clicelist 0 -> 3333 | *3
    }

    // equally distribute the remainders in each thread
    
    for(int j = 0; j<rem; j++){
        sliceList[j] = sliceList[j] + 1;  //first index matra +1 hunchha  | 3333 -> 3334| 3333 | 3333 |
    }

    int startList[thread];
    int endList[thread];
    // start = 0
    // end = 3333

    for(int l = 0 ;l < thread; l++){
        // if it is the start
        if(l == 0){
            startList[l] = 0;
        }
        // endList[1 -1] = 0 which is starting index gets the endlist value + 1
        else{
            startList[l] = endList[l-1] + 1;
        }

        endList[l] = startList[l] + sliceList[l] -1; //3334+3333-1 -> 6666
    }

    range nums[thread];

    for(int k = 0; k< thread; k++){
        nums[k].start = startList[k];
        nums[k].end = endList[k];
    }

// create thread according to nummber of thread by user
    pthread_t threadIDs[thread];

    for(int n = 0; n<thread; n++){
        pthread_create(&threadIDs[n], NULL, prime, &nums[n]);
        
    }

     for(int n = 0; n<thread; n++){
        pthread_join(threadIDs[n],&pointer);
        printf("prime number thread %d = %d\n",n+1,*(int*)pointer);
    }
} 