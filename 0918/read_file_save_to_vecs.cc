/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: read_file_save_to_vecs.cc
  > Author: Donald
  > Created Time: 2014/09/18/ 21:59:56
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdio> 
#include <cstdlib>
#include <stdexcept>
#include <fstream>

using namespace std;

typedef vector<string>  VEC;

void print_dprint_detail(strVV);
    return 0;
}

void print_detail(const vector<VEC> &strVV){
    int word_cnt = 0;
    int line_cnt = 0;
    for(vector< VEC >::const_iterator it = strVV.begin(); it != strVV.end(); ++it){
        for(vector<string>::const_iterator siter = (*it).begin(); siter != (*it).end(); ++ siter){
            cout << *siter ;
            //word_cnt += (*it).size();
            word_cnt ++;
        }
        cout << endl;
    }
    //cnt也可以通过各个数组的大小相加而得到
    line_cnt = strVV.size();
    cout << "共有单词：" << word_cnt << endl;
    cout << "共有行数：" << line_cnt << endl;
}
void read_File(const string &arg,vector< VEC > &strVV){
    ifstream src(arg.c_str());
    if(!src){
        throw runtime_error("打开文件失败");
    }

    string line;
   // vector<string> strV ;//放的位置不对
    while(getline(src,line)){
        vector<string> strV ;
        add_Words(strV , line);//把一行的单词放入到数组中
        strVV.push_back(strV);
    }
}
#if 1
void add_Words(vector<string> &strV, string &line){
    string::iterator it = line.begin(); 
//    string::iterator temp = it;本计划通过下标来进行操作的，后来通过其他方式实现了
    
    string buf ;
    bool flag = false;//代表单词有没有开始计数
    while(it != line.end()){
        if(ispunct(*it)){//为标点符号
            *it = ' ';//迭代器值的改变对容器有无影响???
            //line.replace(it,1,' ');
            flag = false;
        }else{
            buf += *it ;
            flag = true;
        }
        if(flag == true){
            strV.push_back(buf);                           
            buf = "";
        }
        ++ it;
    }
}
#endif
#if 0
void addWords(vector<string> &strV, string &line){
    string::size_type ix = 0; 
//    string::iterator temp = it;本计划通过下标来进行操作的，后来通过其他方式实现了
    
    string buf ;
    bool flag = false;//代表单词有没有开始计数
    while(ix != line.size()){
        if(ispunct(line[ix])){//为标点符号
            line[ix] = ' ';//迭代器值的改变对容器有无影响???
            //line.replace(ix,1,"1");
            flag = false;
        }else{
            buf += line[ix] ;
            flag = true;
        }
        if(flag == true){
            strV.push_back(buf);                           
            buf = "";
        }
        ++ ix;
    }
}
#endif
