/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: test1.cc
  > Author: Donald
  > Created Time: 2014/09/26/ 21:08:19
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdio> 
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<int> vec;
    int num = 5;
    if(argc == 2){
        num = atoi(argv[1]);
    }

    for(size_t index = 0;index < num; ++index){
        vec.push_back(rand() % 100);
    }

    cout << "num = " << num << endl;

    for_each(vec.begin(),vec.end(),[&num](int v){cout << v + num << " " ; ++ num;});
    cout << endl;
    
    cout << "num = " << num << endl;
    return 0;
}
