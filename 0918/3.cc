#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void readFile(ifstream &in, vector<string> &words);
void erasePunct(string &s);

int main(int argc, const char *argv[])
{
    //打开文件
    //读取单词
    //打印个数

    if(argc < 2)
    {
        fprintf(stderr, "Usage:%s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ifstream infile(argv[1]);
    if(!infile)
        throw std::runtime_error("open file error");

    vector<string> words;
    readFile(infile, words);

    for(vector<string>::iterator it = words.begin(); it != words.end(); ++it){
        cout << *it << endl;    
    }
    cout << "单词个数: " << words.size() << endl;
    return 0;
}

void readFile(ifstream &in, vector<string> &words)
{
    words.clear();
    string word;
    while(in >> word)
    {
        erasePunct(word);
        words.push_back(word);
    }
}

void erasePunct(string &s)
{
    string::iterator it = s.begin();
    while(it != s.end())
    {
        if(ispunct(*it))
            //it = s.erase(it);
            *it = ' ';
        else
            ++it;
    }
}



