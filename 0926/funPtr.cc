/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: funPtr.cc
  > Author: Donald
  > Created Time: 2014/09/27/ 01:45:28
  > details:
  =============================================*/
#include <cstdio> 
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int AddFunc(int left, int right){
    return left + right;
}
int main(int argc, const char *argv[])
{
//    typedef int (*Add) (int a, int b);
  //  Add add = &AddFunc;
    cout << AddFunc(3,2) << endl; // 5
    return 0;
}
