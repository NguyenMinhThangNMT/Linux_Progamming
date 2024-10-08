#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 2;

typedef struct{
    char name[30];
    char msg[30];
}thread_args_t;

static void *handle_th1(void *args){
    thread_args_t *thr = (thread_args_t*)args;

    pthread_mutex_lock(&lock1);
    printf("hello %s\n",thr->name);
    printf("thread1 handler,counter : %d\n",++counter);
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

static void *handle_th2(void *args){
    pthread_mutex_lock(&lock1);
    printf("thread2 handler,counter : %d\n",++counter);
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

int main(void){
    int ret;
    thread_args_t thr;
    pthread_t thread1,thread2;

    strncpy(thr.name,"NMT",sizeof(thr.name));
    if(ret = pthread_create(&thread1,NULL,&handle_th1,&thr)){
        printf("pthread_create() error\n");
        return -1;
    }
    if(ret = pthread_create(&thread2,NULL,&handle_th2,NULL)){
        printf("pthread_create() error\n");
        return -1;
    }

    //Đợi thread ngừng hoạt động
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    return 0;
}