#include<stdio.h>
#include<signal.h>

int main(void){
    sigset_t my_set;
    sigemptyset(&my_set);// Bật tất cả các bit signal về 0

    sigaddset(&my_set,SIGINT);//bật giá trị SIGINT lên 1
    sigprocmask(SIG_BLOCK,&my_set,NULL);//Block giá trị được set ở dòng trên là SIGINT
    while(1);
    return 0;
}