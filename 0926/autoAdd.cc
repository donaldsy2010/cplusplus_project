/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: autoAdd.cc
  > Author: Donald
  > Created Time: 2014/09/26/ 15:55:22
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    int i = 5;
    int ret = (i++)*5 + i;
    cout << i << endl;
    cout << ret << endl;

    ++i = 5;
    cout << i << endl;
    return 0;
}
