/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: search.h
  > Author: Donald
  > Created Time: 2014/09/20/ 15:13:24
  > details:
=============================================*/
#ifndef __MY_SEARCH_
#define __MY_SEARCH_ 

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

#include <unistd.h>
#include <cstdio> 
#include <cstdlib>
//using namespace std;//有可能会造成命名空间污染,所以在头文件中可以采用如下方法
using std::string;
using std::vector;
using std::ifstream;
void readFile(ifstream &src, vector<string> &vec);
void erasePunct(vector<string> &vec);//重载
 
void searchWord(const vector<string> &vec, const string &str, vector<string> &ret);
void print(const vector<string> &ret);

void erasePunct(string &word, vector<string> &str);
void add_to_vec(vector<string> &vec, string &word);
#endif  /*__MY_SEARCH_*/
