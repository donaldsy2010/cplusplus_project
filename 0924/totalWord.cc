/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: totalWord.cc
  > Author: Donald
  > Created Time: 2014/09/24/ 17:02:55
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, const char *argv[])
{
    
    map<string, int> words;
    string word;
    while(cin >> word){
        words[word]++;
    }

    //遍历map的方法之一
    for(const pair<string,int> &p: words){
        cout << p.first << " : " << p.second << endl; 
    }
    return 0;
}
