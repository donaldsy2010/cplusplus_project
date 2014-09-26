/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: searchWord.cc
  > Author: Donald
  > Created Time: 2014/09/24/ 20:51:16
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio> 
#include <cstdlib>
#include <cctype>
using namespace std;
typedef vector<string>  VEC;
class Search{
    public:
        void readFile(ifstream &in);
        void search(const string &word);

        static void addWord(VEC &strV,string &line);
    private:
        vector< VEC > strVV_;
};
int main(int argc, const char *argv[])
{
    //读文件到一个二维容器里
    //在二维容器里查询
    //打印结果
    if(argc == 1){
        fprintf(stderr, "please use %s filename frenqfile!\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    ifstream src(argv[1]);

    if(src == NULL ){
        perror("open file");
        exit(EXIT_FAILURE);
    }

    Search sea;
    sea.readFile(src);

    string word;
    cout << "please input the search word:" ;
    while(cin >>  word){
        sea.search(word);
        cout << "please input the search word:" ;
    }
    return 0;
}

void Search::readFile(ifstream &in){
    string line;
    while(getline(in,line)){
        VEC strV;
        addWord(strV,line);
        strVV_.push_back(strV);
    }
}
void Search::addWord(VEC &strV,string &line){
    string::iterator it = line.begin();
    string buf;
    bool flag = false;
    while(it != line.end()){
        if(ispunct(*it)){
            *it = ' ';
            flag = false;
        }else{
            buf += *it;
            flag = true;
        }

        if(flag == true){
            strV.push_back(buf);
            buf  = "";
        }
        ++ it;
    }
}
void Search::search(const string &word){
    int cnt = 0;
    int line = 0;
    for(vector<VEC>::const_iterator it = strVV_.begin(); it != strVV_.end(); ++it){
        line ++;//从第一行算起
        bool readed = false;//标记是否存在且已经读取一次了

        string lineword;
        vector<string>::const_iterator siter = (*it).begin(); 

        while(siter != (*it).end()){
            string buf;//存储单词
            while(*siter != " " && siter != (*it).end()){
                buf += *siter;    
                ++ siter;
            }

            lineword += buf;
            lineword += " ";
            if(buf == word ){
                ++ cnt;
                readed = true;
                cout << "hello1" << endl;
            } 

            if(siter != (*it).end()){
                ++ siter;
                cout << "hello2" << endl;
            }
            else break;
            cout << "hello3" << endl;
            cout << *siter << endl;
        }
        if(readed){
            cout << "(line " << line << ") " << lineword << endl;
        }
    }
    cout << word << " occurs " << cnt << " times" << endl;
}
