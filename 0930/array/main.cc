/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: main.cc
  > Author: Donald
  > Created Time: 2014/09/30/ 11:36:40
  > details:
=============================================*/
#include "Array.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    Array<int,20> arr;
    for(Array<int,20>::size_type ix = 0;
        ix != arr.size();
        ++ ix)
    {
        arr[ix] = ix + 1;
    }

    for(Array<int,20>::iterator it = arr.begin();
       it != arr.end();
       ++it)
    {
        cout << *it << " ";    
    }
    cout << endl;
    return 0;
}
