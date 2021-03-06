/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: del_often_word.cc
  > Author: Donald
  > Created Time: 2014/09/18/ 20:48:51
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Word{
    int cnt_;
    string word_;
};

void get_vec(char* filename,vector<Word> &vec);//获取结构体容器
void erasePuct(string &s);//擦除标点
void addFreaquency(vector<Word> &words, string &dict);//把单词增加到容器中
void print_ret(const vector<Word> &totalRetSet);//输出结果统计
bool cmp(const Word &left, const Word &right);//sort中需要用到的函数
void get_freq_vec(const string &freq_file, vector<string> &freqVec);//获取盛放经常使用的词汇--没有什么意义
void del_freq_word(vector<Word> &words, const vector<string> &freqVec);//把结构体容器中经常使用的词汇删除

int main(int argc, char *argv[])
{
    //打开文件
    //读取文件到vector中
    //计数
    //去重并计数，放入一个结构体容器中
    //获得常见词汇,从已经统计的结果中删除该词
    if(argc < 2){
        fprintf(stderr, "Please input :%s filename\n",argv[0]);
        exit(1);
    }
    vector<Word> words;
    get_vec(argv[1],words);

    //删除常见词汇
    string fileFreq = "frenq.txt";
    vector<string> freqVec;
    get_freq_vec(fileFreq, freqVec);
    del_freq_word(words, freqVec);

    sort(words.begin(), words.end(), cmp);
    print_ret(words);
    return 0;
}

void get_vec(char* filename,vector<Word> &vec){
    ifstream src(filename);
    if(!src){
        throw runtime_error("打开文件失败");
    }

    string word;
    while(src >> word){
        erasePuct(word);//直接把文件放入到由结构体构成的链表之中
        //vec.push_back(word);
        addFreaquency(vec, word);
    }
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
void addFreaquency(vector<Word> &words,string &dict){
    vector<Word>::iterator it = words.begin(); 
    while(it != words.end()){
        if(dict == it->word_)
        {
            ++ it->cnt_;
            break;
        }
        ++ it;
    }

    if(it == words.end())
    {
       Word temp ;
       //temp.word_ = it->word_;
       temp.word_ = dict;
       temp.cnt_ = 1;
       words.push_back(temp);
    }
}
void print_ret(const vector<Word> &words){
    for(vector<Word>::const_iterator it = words.begin(); 
        it != words.end(); 
        ++it)
    {
         printf("words：%-10s frenq: %-5d\n" , it->word_.c_str(), it->cnt_);        
    }   

}
bool cmp(const Word &left, const Word &right){
    return (left.cnt_ < right.cnt_);
}
void get_freq_vec(const string &fileFreq, vector<string> &freqVec){
    ifstream freq(fileFreq.c_str());

    string word;
    while(freq >> word){
        freqVec.push_back(word);
    }
}
void del_freq_word(vector<Word> &words, const vector<string> &freqVec)
{
    vector<Word>::iterator it = words.begin(); 
    
    while(it != words.end())    
    {
        for(vector<string>::const_iterator freq = freqVec.begin(); freq != freqVec.end(); ){
            if(it->word_ == *freq)            
            {
                it = words.erase(it);
                break;
            }else{
                ++ freq;
            }
        }
        ++ it;
    }
}
