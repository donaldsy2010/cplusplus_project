/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: search.cc
  > Author: Donald
  > Created Time: 2014/09/20/ 15:33:09
  > details:
=============================================*/
#include "search.h"
using namespace std;
void readFile(ifstream &src, vector<string> &vec){
    string word;
    while(src >> word){
        vector<string> temp;

        erasePunct(word,temp);
        for(vector<string>::size_type index = 0; index < temp.size(); ++ index){
           // vec.push_back(temp[index]);
           //有可能是已经存在的单词，所以这里就需要进行判断
            add_to_vec(vec,temp[index]);
        }
    }
}
void searchWord(const vector<string> &vec, const string &str, vector<string> &ret){
    //这里不能用二分查找，只能用暴力法，因为查询的是字符或不完成的字符串
    //其实string自己有一个find函数
    for(vector<string>::const_iterator it = vec.begin(); it != vec.end(); ++it){
        //遍历一次容器，每次都在容器的一个元素（一个string）中查找，
        size_t found = (*it).find(str);
        if(found != string::npos){
            ret.push_back(*it);
        }               
    }
    if(ret.size() == 0){
        cout << "\033[1;36mNo found\033[0;m" << endl;

    }
}
void print(const vector<string> &vec){
    for(vector<string>::const_iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << endl;    
    }
}

void erasePunct(string &word, vector<string> &str){
    string temp;
    string::iterator it = word.begin(); 
    while(it != word.end()){
#if 1
        //采用这种方法能实现单词之间由标点来隔开的情况
        while(! ispunct(*it) && it != word.end()){
            temp += *it;
            ++ it;
        }

        str.push_back(temp);
        if(it != word.end()){
            it = word.erase(it);
            temp = "";
        }else{//这里可以省略了
            break;
        }
#endif
#if 0
        //这里只能只实现标点符号的替换，但还是没能换行存储
        if(ispunct(*it)){
            *it = ' ';
            str.push_back(temp);
            // break;//这里能返回，但后续单词就丢了
        }else{
            temp += *it;
            ++ it;
        }
#endif
    }
}
void add_to_vec(vector<string> &vec, string &word){
    vector<string>::iterator it = vec.begin() ;
    while(it != vec.end()){
        if(*it == word){
            break;
        }
        ++ it;
    }

    if(it == vec.end()){
        vec.push_back(word);
    }
}
