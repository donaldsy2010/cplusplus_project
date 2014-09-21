/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: total_word.cc
  > Author: Donald
  > Created Time: 2014/09/18/ 16:09:31
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <fstream>
#include <cstdlib>
using namespace std;

void get_vec(char* filename,vector<string> &vec);
int total(const vector<string> &vec);
void erasePuct(string &s);

int main(int argc, char *argv[])
{
    //打开文件
    //读取文件到vector中
    //计数
    if(argc < 2){
        fprintf(stderr, "Please input :%s filename\n",argv[0]);
        exit(1);
    }
    vector<string> words;
    get_vec(argv[1],words);
    int cnt =  total(words);
    cout << "单词个数为 ：" << cnt << endl;

    return 0;
}

void get_vec(char* filename,vector<string> &vec){
    ifstream src(filename);
    if(!src){
        throw runtime_error("打开文件失败");
    }

    string word;
    while(src >> word){
        erasePuct(word);
        vec.push_back(word);
    }
}

int  total(const vector<string> &vec){
    return vec.size();
}
void erasePuct(string &s){
    string::iterator it = s.begin();
    while(it != s.end()){
        if(ispunct(*it)){
            it = s.erase(it);
        }else{
            ++ it;
        }
    }
}
