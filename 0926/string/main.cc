#include "String.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdio> 
#include <cstdlib>
#include <string.h>
#include <stdexcept>
using namespace std;
int main(int argc, const char *argv[])
{
    String s = "hello, ";
    String temp("absde");
    cout << s << temp << endl;


    try{
        String str;
        if("H" != "e"){
            throw runtime_error("空参数") ;
        }
        str += s;
        str += temp;
        cout << str << endl;
    }catch (const exception &e){
        cerr << e.what() << endl;
    }
    return 0;
}
