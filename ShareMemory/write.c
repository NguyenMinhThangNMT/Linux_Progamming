#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void){
    int shm_fd;
    const char* message = "Hello world\n";
    void *ptr;

    shm_fd= shm_open("hello",O_CREAT|O_RDWR,0666);
    ftruncate(shm_fd,4096);
    ptr = mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
    strcpy(ptr,message);
    return 0;
}