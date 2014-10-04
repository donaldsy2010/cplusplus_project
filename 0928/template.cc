/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: templete.cc
  > Author: Donald
  > Created Time: 2014/09/28/ 21:27:05
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template<typename T>
T add(const T &a, const T &b){
    return a + b;
}
int main(int argc, const char *argv[])
{
    int a,b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << add(a, b) << endl;

    string c ,d;
    cin >> c >> d;
    cout << c << " + " << d << " = " << add(c, d) << endl;

    double e,f;
    cin >> e >> f;
    cout << e << " + " << f << " =  " << add(e,f) << endl;
    return 0;
}
