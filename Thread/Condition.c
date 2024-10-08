#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define THRESHOLD  5

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int counter = 0;

static void *handle_th1(void *args){
    pthread_mutex_lock(&lock);
    printf("Hello thread1\n");

    while(counter < THRESHOLD){
        counter += 1;
        printf("Counter = %d\n",counter);
        sleep(1);
    }
    pthread_cond_signal(&cond);
    printf("thread1 handler,counter = %d\n",counter);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main(void){
    int ret;
    pthread_t thread1;
    if(ret = pthread_create(&thread1,NULL,&handle_th1,NULL)){
        printf("pthread_create() error\n");
        return -1;
    }
    pthread_mutex_lock(&lock);
    while(1){
        while (counter < THRESHOLD) {
            pthread_cond_wait(&cond, &lock); // Chờ tín hiệu
        }
        if(counter == THRESHOLD){
            printf("Global variable counter = %d\n",counter);
            break;
        }
    }
    pthread_mutex_unlock(&lock);

    pthread_join(thread1,NULL);

    return 0;
}

