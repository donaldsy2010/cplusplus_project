/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: main.cc
  > Author: Donald
  > Created Time: 2014/09/27/ 17:29:35
  > details:
=============================================*/
#include "Complex.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    Complex com1;
    cout << com1 << endl;

    Complex com2(1,23);
    cout << com2 << endl;

    Complex com3 = com2;
    cout << com3 << endl;

    com3 += com2;
    cout << com3 << endl;

    cout << "--------------------------------" << endl;
    
    Complex com4(5,56);
    com3 = com1 + com4;
    cout << com3 << endl;

    int a = 5;
    com3 = com4 + 5; 
    cout << com3 << endl;
    
    cout << (com3 - com4) << endl;
    cout << (com3 * com4) << endl;
    cout << (com3 / com4) << endl;


  //  int b = 10;
   // cout << (a + b) << endl;
    return 0;
}
