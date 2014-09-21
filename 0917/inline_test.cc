/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: inline_test.cc
  > Author: Donald
  > Created Time: 2014/09/17/ 15:37:59
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
inline void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main(int argc, const char *argv[])
{
    int a = 10;
    int b = 15;
    cout << a << "  " << b << endl;
    swap(a,b);
    cout << a << "  " << b << endl;
    return 0;
}
