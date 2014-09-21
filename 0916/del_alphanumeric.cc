/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: del_alphanumeric.cc
  > Author: Donald
  > Created Time: 2014/09/16/ 19:17:04
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
int main(int argc, const char *argv[])
{
    string str ;
    cin >> str;
    cout << "string is :" << str << endl;
#if 0 
    for(string::iterator iter = str.begin();
            iter != str.end();
            ++ iter)
       {
        if(ispunct(*iter)){//不为数字或空格，即为标点符号
#if 0
            12. 字符串string中不能移位，将会把string对象的内部机制打乱。
            for(int index = 0 ; index != (str.end() - iter) ; index ++){//difference_type为signed型
                *iter = *(iter ++);
            }
#endif
           iter =  str.erase(iter) - 1;//reverse??
           //cout << *iter;
        }
    }
#endif
    string::size_type ix = 0;
    while(ix != str.size()){
        if(ispunct(str[ix])){
            str= str.erase(ix,1);
            //str.erase(ix,1);这两种方法都可以，不过上边的更安全
        }else{
            ++ ix;
        }
    }
    cout << "result is :" << str << endl;
    return 0;
}
