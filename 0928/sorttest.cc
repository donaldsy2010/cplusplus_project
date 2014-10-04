/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: sorttest.cc
  > Author: Donald
  > Created Time: 2014/09/28/ 01:05:31
  > details:
=============================================*/
#include <iostream>
using std::cout;using std::endl;

#include <vector>
using std::vector;

#include <algorithm>

int main(int argc, const char *argv[])
{
    vector<int> vec;
    for(size_t index = 0;index < 10;++ index){
        vec.push_back(rand()%100);
    }

    sort(vec.begin(),vec.end());
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";    
    }
    cout << endl;

    cout << "---------------------------" << endl;
    sort(vec.rbegin(),vec.rend());
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";    
    }
    cout << endl;

    return 0;
}
