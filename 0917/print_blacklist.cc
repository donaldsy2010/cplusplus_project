/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: print_blacklist.cc
  > Author: Donald
  > Created Time: 2014/09/17/ 20:42:51
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
#include <algorithm>
#include <sys/time.h>
using namespace std;
//该函数实现打开文件，并返回文件描述符
FILE* fopen_file(char* filename){
    FILE* fd = fopen(filename,"r");
    if(fd == NULL){
        perror("open");
        exit(1);
    }
    return fd;
}

//将文件中的数字义字符的形式读出并放入vec容器中
//由于读取一行只能通过fopen的系列函数实现，所以这里采用了fopen，read读取的大小不确定
void get_vec(FILE* fd,vector<int> &vec){
    char buf[512];
    //while(bzero(buf,512),read(fd,buf,sizeof(buf)) > 0){
    while(bzero(buf,512),fscanf(fd, "%s",buf) != EOF){
        int num = atoi(buf);//转化为数字再进行存取。
        vec.push_back(num);
    }
}

//二分查找法
bool serch_bin( vector<int> &list_vec,  vector<int> &wlist_vec, int key){
    size_t first,  last,mid;
    first = 0;
    last = wlist_vec.size() - 1;
   
    while(first <= last){
        //      mid = (first + last)/2; //这里有可能溢出，
        mid = first  +  (last - first)/2; 
        if(list_vec[mid] < key){
            first = mid + 1;
        }else if(list_vec[mid] > key){// 100 > 10
            last = mid - 1;
        }else{
            return true;
        }
    }
    return false;
}

void print_binary(FILE* list,FILE* wlist){
    vector<int> list_vec;
    vector<int> wlist_vec;
    //将数字以字符串的形式放入容器中
    get_vec(list,list_vec);
    get_vec(wlist,wlist_vec);

    //将容器里的元素排序，只用对白名单里的数据进行排序就可以了，总的那个名单没必要排
    sort(list_vec.begin(),list_vec.end());


    int index = 0;
    for(size_t it = 0; it != list_vec.size(); it ++ ){
        bool flag;//用于表示是否存在

        //flag = serch_bin(wlist_vec,0,wlist_vec.size() - 1, list_vec[it]);
        flag = serch_bin(list_vec,wlist_vec , list_vec[it]);
        if(flag == false){
            cout << list_vec[it] << " ";
            index ++;
            if(index % 10 == 0){//控制换行以及刷新缓存
                cout << endl;
            }
        }
    }
}

//暴力法
void brute_force(FILE* list,FILE* wlist){
    vector<int> list_vec;
    vector<int> wlist_vec;

    get_vec(list,list_vec);
    get_vec(wlist,wlist_vec);

    int cnt = 0;
    int index = 0;
    for(size_t it = 0; it != list_vec.size(); it ++ ){
        int flag = 0;//1 same标记
        for(size_t iw = 0; iw != wlist_vec.size(); ++ iw){
            if(list_vec[it] == wlist_vec[iw]){
                flag = 1;
                break;
            }            
        }

        if(flag == 0){            
            cout << list_vec[it] << " ";
            cnt ++;
            index ++; 
            if(index % 10 == 0){
                cout << endl;
            }
        }
    }
    cout << "cnt = " << cnt << endl;
}
int64_t getTime(){
    int64_t time;
    struct timeval tm;
    memset(&tm,0,sizeof tm);
    if(gettimeofday(&tm, NULL) == -1){
        perror("gettimeofday");
        exit(1);
    }

    time = 0;
    time += tm.tv_usec;
    time += tm.tv_sec * CLOCKS_PER_SEC;
    return time;
}

int main(int argc, char *argv[])
{
    int64_t start_time = getTime();
    FILE* list = fopen_file("largT.txt");
    FILE* wlist = fopen_file("white_list.txt");

    brute_force(list,wlist);    
    //print_binary(list,wlist);
    int64_t end_time = getTime();
    cout << "run time : " << end_time - start_time << "m" << endl;
    return 0;
}
