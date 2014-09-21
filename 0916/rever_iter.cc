/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: rever_iter.cc
  > Author: Donald
  > Created Time: 2014/09/16/ 21:43:11
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    string str = "hello,donald";
    for(string::reverse_iterator riter = str.rbegin();
            riter != str.rend(); )
    {
        if((*riter) == 'l'){
            riter = string::reverse_iterator(str.erase((++riter).base()));
        }else {
            ++ riter;
        }
    }
    cout << str << endl;
    return 0;
}
