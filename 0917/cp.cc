/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: cp.cc
  > Author: Donald
  > Created Time: 2014/09/17/ 16:35:05
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
    int b = 20;
    cout << a << "  " << b << endl;
    swap(a,b);
    cout << "hello,donald" << endl;
    cout << a << "  " << b << endl;
    return 0;
}
