#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include<semaphore.h>

char *messages[3] = {NULL, NULL, NULL};
int flag = 0;
sem_t lock;

void *messenger(void *p)
{
    long tid = (long)p;
    char tmpbuf[100];
        for(int i=0; i<10; i++)
        {
            sem_wait(&lock);
            /* Sending a message */
            long int dest = (tid + 1) % 3;
            sprintf(tmpbuf,"Hello from Thread %ld!", tid);
            char *msg = strdup(tmpbuf);
            messages[dest] = msg;
            printf("Thread %ld sent the message to Thread %ld\n",tid, dest);


            /* Receiving a message */
            printf("Thread %ld received the message '%s'\n",dest, messages[dest]);
            free(messages[dest]);
            messages[dest] = NULL;
            sem_post(&lock);
        }
    return NULL;
}


void main()
{
    pthread_t thrID1, thrID2, thrID3;
    sem_init(&lock, 1, 1);
    pthread_create(&thrID1, NULL, messenger, (void *)0);
    pthread_create(&thrID2, NULL, messenger, (void *)1);
    pthread_create(&thrID3, NULL, messenger, (void *)2);
    pthread_join(thrID1, NULL);
    pthread_join(thrID2, NULL);
    pthread_join(thrID3, NULL);
    sem_destroy(&lock);
}