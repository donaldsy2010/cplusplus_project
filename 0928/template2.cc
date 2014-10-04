/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: template2.cc
  > Author: Donald
  > Created Time: 2014/09/28/ 21:40:26
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T1,typename T2>
T2 add(const T1 &a, const T2 &b){
    return a + b;
    //返回值将会根据类型而具体的转化。
    //这里转化为了T2，也可以转化为T1
}

int main(int argc, const char *argv[])
{
    int a = 12;
    double b = 12.4;
    cout << add(a,b) << endl;
    return 0;
}
