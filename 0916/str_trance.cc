/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: str_trance.cc
  > Author: Donald
  > Created Time: 2014/09/16/ 15:01:43
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void trance_fun(string &s){
    string::size_type index;
    for(index = 0; index < s.size(); index ++){
        if(islower(s[index])){
            s[index] = toupper(s[index]) ;
        }else if(isupper(s[index])){
            s[index] = tolower(s[index]);
        }
    }
}
int main(int argc, const char *argv[])
{
    string s = argv[0];
    trance_fun(s);
    cout << s << endl;
    return 0;
}
