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
    int sockfd = -1;//Dùng để connect đến server
    struct sockaddr_in server_addr;// Dùng để chứa địa chỉ server
    char buffer[1024];
    time_t ticks;

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("192.168.58.150");//Khởi tạo địa chỉ
    server_addr.sin_port = htons(5000);//Khởi tạo port

    // Conect đến server
    if(connect(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr))==0){
        read(sockfd,buffer,sizeof(buffer)-1);//đọc bản tin;
        printf("\n%s\n",buffer);//In ra màn hình
        close(sockfd);
    }
    close(sockfd);

    return 0;
}