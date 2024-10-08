#include<stdio.h>
#include<signal.h>

void my_signal_handler(int signal){
    printf("My handler is called\n");
}

int main(void){
    signal(SIGINT,my_signal_handler);
    while(1);
    return 0;
}