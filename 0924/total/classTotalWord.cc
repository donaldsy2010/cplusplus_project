/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: classTotalWord.cc
  > Author: Donald
  > Created Time: 2014/09/24/ 19:40:36
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>
#include <sys/time.h>
using namespace std;
//typedef map<string,int> Map;
//typedef set<string> Set;
struct Ret{
    int cnt_;
    string word_;
};

class Total{
    public:
        void readFileToMap( ifstream &in) ;
        void readFileToSet(ifstream &in) ;

        void find();
        void printSort();
        void saveToVec();
        
        static bool cmp(const Ret &left,const Ret &right );
        static void erasePunct(string &word);
        static int64_t getTime();
    private:
        map<string,int> mymap_;
        set<string> myset_;
        vector<Ret> vec_;
};
int main(int argc, const char *argv[])
{
    int64_t proStart = Total::getTime();
    if(argc == 1){
        fprintf(stderr, "please use %s filename frenqfile!\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    ifstream src(argv[1]);
    ifstream frenq(argv[2]);

    if(src == NULL || frenq == NULL){
        perror("open file");
        exit(EXIT_FAILURE);
    }

    Total total;

    int64_t readStart = Total::getTime();
    total.readFileToMap(src);
    total.readFileToSet(frenq);

    int64_t readEnd = Total::getTime();
   // total.find();
    
    total.saveToVec();
    int64_t printStart = Total::getTime();
    total.printSort();
    int64_t printEnd = Total::getTime();


    int64_t print = printEnd - printStart;
    int64_t read = readEnd - readStart;
    int64_t pro = printEnd - proStart;

    cout << "程序运行时间   ：" << pro/1000 << "ms" << endl;
    cout << "读文件运行时间 ：" << read/1000 << "ms" << endl;
    cout << "打印运行时间   ：" << print/1000 << "ms" << endl;
    return 0;
}

void Total::readFileToMap( ifstream &in) {
    string word;
    while(in >> word){
        erasePunct(word);
        mymap_[word]++;
    }
}
void Total::readFileToSet(ifstream &in) {
    string word;
    while(in >> word){
        myset_.insert(word);
    }
}
void Total::erasePunct(string &word){
    string::iterator it = word.begin();
    while(it != word.end()){
        if(ispunct(*it)){
            it = word.erase(it);
        }else{
            ++ it;
        }
    }


}
void Total::find(){
    for(const pair<string,int> &p:mymap_){
        set<string>::const_iterator it;
        for( it = myset_.begin();
                it != myset_.end();
                ++ it)
        {
            if(p.first == *it){
                break;
            }
        }
        if(it == myset_.end()){
            cout << p.first << " : " << p.second << endl;
        }
    }

}

void Total::saveToVec(){
    for(const pair<string,int> &p:mymap_){
        Ret temp;
        set<string>::const_iterator it;
        for( it = myset_.begin();
                it != myset_.end();
                ++ it)
        {
            if(p.first == *it){
                break;
            }
        }
        if(it == myset_.end()){
            temp.word_ =  p.first;
            temp.cnt_ =  p.second ;
            vec_.push_back(temp);
        }
    }
}
void Total::printSort(){
    //sort(vec_.begin(),vec_.end(),greater<int>());//需给greater提供重载操作符
    
    sort(vec_.begin(),vec_.end(),cmp);
    for(vector<Ret>::iterator it = vec_.begin(); it != vec_.end(); ++it){
    //    cout << "word:  " (*it).word_ << " : " << (*it).cnt_ << endl;    
        printf("words：%-10s frenq: %-5d\n" , it->word_.c_str(), it->cnt_);        
    }
}
bool Total::cmp(const Ret &left,const Ret &right ){
    return left.cnt_ < right.cnt_;
}
int64_t Total::getTime(){
    struct timeval tm;
    if(gettimeofday(&tm,NULL)){
        perror("get time");
        exit(1);
    }
    int64_t mytime = 0;
    mytime += tm.tv_sec*CLOCKS_PER_SEC;
    mytime += tm.tv_usec;
    return mytime;
}
