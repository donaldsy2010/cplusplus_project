/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: reference_test.c
  > Author: Donald
  > Created Time: 2014/09/13/ 10:04:55
  > details:
=============================================*/
#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    int a = 30;
    int &ref = a;
    int &ref2 = ref;

    cout << "&a    = " << &a << endl;
    cout << "&ref  = " << &(ref)<<endl;
    cout << "&ref2 = " << &(ref2) << endl;

    cout << "a = "<< a << endl;
    cout << "ref = " << ref << endl;
    cout << "ref2 = " << ref2 <<endl;
    return 0;
}
