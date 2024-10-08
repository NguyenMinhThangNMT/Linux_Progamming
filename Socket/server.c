#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<time.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(void){
    int listenfd = -1;
    int connfd = -1;
    struct sockaddr_in server_addr;// Dùng để chứa địa chỉ server
    char buffer[1024];
    time_t ticks;

    listenfd = socket(AF_INET,SOCK_STREAM,0);//Nhận bản tin yêu cầu kết nối
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("192.168.58.150");//Khởi tạo địa chỉ
    server_addr.sin_port = htons(5000);//Khởi tạo port

    //đính kèm ip vào socket
    bind(listenfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
    listen(listenfd,10);//Không quá 10 kết nối

    while(1){
        connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
        ticks = time(NULL);
        sprintf(buffer,"Time: %sHello client",ctime(&ticks));
        write(connfd,buffer,strlen(buffer));
        close(connfd);
    }
    close(listenfd);

    return 0;
}