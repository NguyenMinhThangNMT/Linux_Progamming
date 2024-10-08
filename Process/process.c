#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void){
    pid_t child_pid; //Tạo tiến trình
    int counter = 2;

    printf("Gia tri khoi tao cua counter la : %d\n",counter);
    child_pid=fork(); // Tạo tiến trình con

    if(child_pid >= 0){// Khởi tạo thành công
        if(child_pid ==0 ){
            // Tiến trình con
            printf("\n I'm the child process,counter: %d\n",++counter);
            printf("My PID is : %d,my parent PID is : %d\n",getpid(),getppid());
        }
        else{
            //Tiến trình cha
            printf("\nI'm the parent process,counter: %d\n",++counter);
            printf("My PID is %d\n",getpid());
        }
    }
    else{//Khởi tạo không thành công
        printf("fork() unsuccessfully\n");
    }
    return 0;
}