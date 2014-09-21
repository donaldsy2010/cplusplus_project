/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: create_list.cc
  > Author: Donald
  > Created Time: 2014/09/17/ 21:05:07
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

using namespace std;
int creat_list(char *filename,int cnt){
    int fd  = open(filename,O_WRONLY | O_CREAT | O_TRUNC,0777);
    if(fd == -1){
        perror("open");
        exit(1);
    }

    int num ; 
    while(cnt > 0){
        num = rand()% 1000000;
        char line[512] = {0};
        snprintf(line,sizeof line,"%d\n",num);
        
        if(write(fd, line, strlen(line)) == -1){
            perror("write");
            close(fd);
            exit(1);
        }
        -- cnt;
    }
    return fd;
}
int main(int argc, char *argv[])
{
    srand(time(NULL));
    creat_list(argv[1],atoi(argv[2]));
    return 0;
}
