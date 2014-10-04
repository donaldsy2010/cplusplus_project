/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: main.cc
  > Author: Donald
  > Created Time: 2014/09/29/ 15:49:26
  > details:
=============================================*/
#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
int main(int argc, const char *argv[])
{
    try{
        Stack<int> sta;
        sta.push(15);
        sta.push(20);
        cout << sta.top() << endl;
        sta.pop();

        cout << sta.top() << endl;
        sta.pop();


        Stack<string> sta1;
        sta1.push("hello");
        sta1.push("world");
        cout << sta1.top() << endl;
        sta1.pop();
        cout << sta1.top() << endl;
        sta1.pop();

        Stack<const char*>  sta2;
        char *p = "donald";
        char *q = "absde";
        sta2.push(p);
        sta2.push(q);
        cout << sta2.top() << endl;
        sta2.pop();
        cout << sta2.top() << endl;
        sta2.pop();

    }catch( const out_of_range &e){
        cout << e.what() << endl;
    }catch(const exception &e){
        cout << e.what() << endl;
    }
    return 0;
}
