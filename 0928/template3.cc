/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: template3.cc
  > Author: Donald
  > Created Time: 2014/09/28/ 21:48:05
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdio> 
#include <cstdlib>
using namespace std;

template <typename T>
void init(T &vec, size_t num){
    for(size_t index = 0; index != num; ++ index){
        //这里就不能改。
        vec.push_back(rand()%100);
    }
}
int main(int argc, const char *argv[])
{
    vector<int> vec;
    init(vec,5);
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << endl;    
    }

    cout << "----------------------" << endl;
    vector<string> str;
    init(str,5);
    for(vector<string>::iterator it = str.begin(); it != str.end(); ++it){
        cout << *it << endl;    
    }

    return 0;
}
