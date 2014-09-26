/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: totalWord.cc
  > Author: Donald
  > Created Time: 2014/09/24/ 17:40:03
  > details:一个小程序都要调试很久，要重视了，少年。
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <cstdio> 
#include <cstdlib>
using namespace std;
typedef map<string,int> Map;
typedef set<string> Set;

//void readFileToMap( string &filename,Map &mymap) ;//这里应该是一个文件流
void readFileToMap( ifstream &in,Map &mymap) ;
void readFileToSet(ifstream &in,Set &myset) ;
void erasePunct(string &word);

int main(int argc, const char *argv[])
{
    if(argc == 1){
        fprintf(stderr, "please use %s filename frenqfile!\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    ifstream src(argv[1]);
    ifstream frenq(argv[2]);
    
    if(src == NULL || frenq == NULL){
        perror("open file");
        exit(EXIT_FAILURE);
    }

    Map mymap;
    Set myset;
    readFileToMap(src,mymap);
    readFileToSet(frenq,myset);
    

    for(const pair<string,int> &p:mymap){
        set<string>::const_iterator it;
        for( it = myset.begin();
            it != myset.end();
            ++ it)
        {
            if(p.first == *it){
                break;
            }
        }
        if(it == myset.end()){
            cout << p.first << " : " << p.second << endl;
        }
    }
    return 0;
}
void readFileToMap( ifstream &in,Map &mymap) {
    string word;
    while(in >> word){
        erasePunct(word);
        mymap[word] ++;
    }
}
void readFileToSet(ifstream &in,Set &myset) {
   string word;
   while(in >> word){
       myset.insert(word);
   }
}
void erasePunct(string &word){
    string::iterator it = word.begin();
    while(it != word.end()){
        if(ispunct(*it)){
            it = word.erase(it);
        }else{
            ++ it;
        }
    }
}

