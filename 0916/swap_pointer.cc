/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: swap_pointer.cc
  > Author: Donald
  > Created Time: 2014/09/16/ 10:40:17
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void swap(int &left,int &right){
    int temp(left);
    left = right;
    right = temp;
}

//交换两个int*
void swap(int *&left,int *&right){
    int *temp(left);
    left = right;
    right = temp;
}

//更高级的用法
template <typename T>
void swap(T &left,T &right){
    T temp(left);
    left = right;
    right = temp;
}

int main(int argc, const char *po_argv[])
{

    int a = 10;
    int b = 56;

    int *po_a = &a;
    int *po_b = &b;
    cout << "*po_a = " << *po_a << ", *po_b = " << *po_b << endl;

    swap(*po_a,*po_b);
    cout << "*po_a = " << *po_a << ", *po_b = " << *po_b << endl;
    return 0;
}
