#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printPrimeNumbers() {
    int flag, i, j;

    for(i=1; i<=10000; i++) {
        flag = 1;

        if(i==1 || i==0) {
            continue;
        }

        for (j = 2; j <= i/2; j++) {
            if(i % j == 0) {
                flag = 0;
                break;
            }
        }

        if(flag == 1) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int n;
    pthread_t thread_id;
    printf("Enter the number of threads u want to use: ");
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++) {
        pthread_create(&thread_id, NULL, printPrimeNumbers, &thread_id);
        pthread_join(thread_id, NULL);
    }
    exit(0);
}