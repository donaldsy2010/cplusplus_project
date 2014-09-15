/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: readn.c
  > Author: Donald
  > Created Time: 2014/09/15/ 16:02:53
  > details:
  =============================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
ssize_t readn(int rfd,void* buf,size_t size){
    ssize_t nleft = size;
    ssize_t nread = 0;
    while(nleft > 0){
        if((nread = read(rfd,buf,sizeof(buf))) == -1){
            perror("read");
            close(rfd);
            exit(EXIT_FAILURE);
        }else if(nread == 0){
            break;
        }
        nleft -= nread;
        buf += nread;
    }
    return size - nleft;//返回读取到的字节数
}

ssize_t writen(int rfd,void* buf,size_t size){
    ssize_t nleft = size;
    ssize_t nwrite = 0;
    while(nleft >  0){
        if((nwrite = write(rfd,buf,sizeof(buf))) == -1){
            perror("write");
            close(rfd);
            exit(1);
        }else if(nwrite == 0){
            break;
        }
        nleft -= nwrite;
        buf += nwrite;
    }
    return size - nleft;
}
int main(int argc, const char *argv[])
{

    char path[1024];
    strcpy(path,getcwd(NULL,0));
    strcat(path,"/");
    strcat(path,argv[1]);
    int rfd = open(path,O_RDONLY);
    int wfd = open("hello.c",O_WRONLY|O_CREAT);
    
    if(rfd == -1 || wfd == -1){
        perror("open") ;
        exit(1);
    }

    int size = atoi(argv[2]);
    char* buf = (char *)malloc(32);
    int nread;
    nread = readn(rfd,(void*)buf,size);
    int nwrite = writen(wfd,(void*)buf,strlen(buf));
    fprintf(stdout,"%s\n",buf);
    fprintf(stdout,"nread = %d,nwrite = %d\n",nread,nwrite);

    close(rfd);
    close(wfd);
    return 0;
}
