/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: print_string.cc
  > Author: Donald
  > Created Time: 2014/09/16/ 11:02:13
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;
int main(int argc, const char *argv[])
{
    string str = "hello,donald";
   // int index;
    for(int index = 0; 
            index != str.size();
            index ++)
    {
        //cout << str[index] << endl;
        printf("%c\n",str[index]);
    }
    //printf("%s\n",str);//不对，向上兼容，而不会向下兼容,应该的处理反方式见下
    printf("%s\n",str.c_str());//不对，向上兼容，而不会向下兼容,应该的处理反方式见下
    return 0;
}
