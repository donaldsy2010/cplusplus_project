/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: main.cc
  > Author: Donald
  > Created Time: 2014/09/20/ 15:22:35
  > details:
=============================================*/
#include "search.h"
using namespace std;
int main(int argc, const char *argv[])
{
    //打开文件，去除标点，读取到vec中
    //排序（用于二分）
    //查询
    //打印结果
    if(argc == 1){
        fprintf(stderr,"Please input:%s &  filename\n\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    ifstream src(argv[1]);
    if(!src){
        perror("open file");
        exit(EXIT_FAILURE);
    }

    vector<string> vec;//存储单词的容器
    vector<string> searchVec;//当用户输入多个单词时存储的容器
    readFile(src,vec);
   // print(vec);
    //sortWords(vec);没有必要了

    string word;
    cout << "\033[0;33mPlease input the string : \033[0;m" << endl;
    while(cin >> word){
        vector<string> temp;
        searchWord(vec,word,temp);
        print(temp);
        cout << "\033[0;33mPlease input the string : \033[0;m" << endl;
    }
    return 0;
}
