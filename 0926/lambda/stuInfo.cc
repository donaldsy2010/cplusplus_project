/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: sutInfo.cc
  > Author: Donald
  > Created Time: 2014/09/25/ 19:18:16
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <sstream>
using namespace std;
struct Info{
    int id_;
    int grade_;
    string name_;
};

bool maxCmp(const Info &left,const Info &right){
    return left.grade_ < right.grade_;
}
bool cntPred(const Info &stu){
    return (stu.grade_ >= 60 == 1);
}

int main(int argc, const char *argv[])
{
        
    if(argc != 2){
        throw runtime_error("argv is error!");
    }

    ifstream src(argv[1]);
    if(src == NULL){
        throw runtime_error("open file fail");
    }

    vector< Info > vec;
    string line;
    Info temp;
    while(getline(src,line)){
        istringstream is(line);
        is >> temp.id_;
        is >> temp.name_;
        is >> temp.grade_;
        
        vec.push_back(temp);
    }
    
    //int cnt = count_if(vec.begin(),vec.end(),cntPred);
    int cnt = count_if(vec.begin(),vec.end(),[](Info &temp){ return temp.grade_ >= 60;});
   // auto max = max_element(vec.begin(),vec.end(),maxCmp);
    vector<Info>::iterator max = max_element(vec.begin(),vec.end(),
            [](const Info &left,const Info &right){ return left.grade_ < right.grade_;});
    cout << "及格人数 : " << cnt << endl;
    cout << "最高分 ：  " << max->grade_ << endl;
    return 0;
}
