/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: read_print_blacklist.cc
  > Author: Donald
  > Created Time: 2014/09/17/ 22:07:30
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

int open_file(char* filename){
    int fd = open(filename,O_RDONLY);
    if(fd == -1){
        perror("open");
        exit(1);
    }
    return fd;
}
void get_vec(int fd,vector<string> &vec){
    char buf[512];
    while(bzero(buf,512),read(fd,buf,sizeof(buf)) > 0){
        vec.push_back(buf);
    }
}

void brute_force(int list,int wlist){
    vector<string> list_vec;
    vector<string> wlist_vec;
    get_vec(list,list_vec);
    get_vec(wlist,wlist_vec);

    for(size_t it = 0; it != list_vec.size(); it ++ ){
        int cnt = 0;
        int time = 0;
        for(size_t iw = 0; iw != wlist_vec.size(); ++ iw){
            if(list_vec[it] == wlist_vec[iw]){
                time ++;
            }            
            cnt ++;
        }
        if(time == 0){
            cout << list_vec[it] << endl;
            cout << "cnt = " << cnt << endl;
        }
    }
    
}
int main(int argc, char *argv[])
{
    long start_time = time(NULL);
    int list = open_file("largT.txt");
    int wlist = open_file("white_list.txt");
    
    brute_force(list,wlist);    
    long end_time = time(NULL);
    cout << "run time : " << end_time - start_time << endl;
    return 0;
}
