/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: ofstrem.cc
  > Author: Donald
  > Created Time: 2014/09/18/ 15:22:11
  > details:
=============================================*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
int main(int argc, const char *argv[])
{
#if 1
    string srcfile = "num.txt";
    string destfile = "cp.txt";
    ifstream src(srcfile.c_str());
    ofstream dest(destfile.c_str());
  //  ifstream src(srcfile);
//    ofstream dest(destfile);
#endif

//    ifstream src("num.txt");
  //  ofstream dest("cp.txt");
    if(!src || !dest){
        throw runtime_error("打开文件失败");
    }

    string line;
    while(getline(src,line)){//获取一行,
        dest << line << "  donald " << endl;
        cout << line << endl;
    }
    cout << "完成" << endl;

    //一定要记得关闭文件
    src.close();
    dest.close();
    return 0;
}
