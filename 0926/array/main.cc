/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: main.cc
  > Author: Donald
  > Created Time: 2014/09/27/ 13:28:34
  > details:
=============================================*/
#include "Array.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main(int aryc, const char *aryv[])
{
    srand(time(NULL));

    Array array1(4);
//    int a[9] = {1,2,3,9,4,5,6,7,8};
   // array1 = a;//如此方式如何赋值？在声明的时候指定array1的大小。
   
    for(size_t index = 0; index != 5; ++ index ){
        array1[index] = rand() % 100;
    }

    //以上两种赋值方式都需要指定类中元素的个数！
    cout << array1 << endl;
    cout << array1[5] << endl; 

    Array array2(4);
    int b[] = {3,5,3,4,5};
    array2 = b;
//    for(size_t index = 0; index != 5; ++ index ){
//        array1[index] = rand() % 100;
//    }
    cout << array2 << endl;

    cout << "<" << (array1 < array2) << endl;
    cout << "<="  << (array1 <= array2) << endl;
    cout << ">" << (array1 > array2) << endl;
    cout << ">=" << (array1 >= array2) << endl;
    cout << "!=" << (array1 != array2) << endl;
    cout << "==" << (array1 == array2) << endl;

    array1 += array2;
    cout << array1 << endl;
    cout << "---------------" << endl;
    Array array3;
    array3 = array1 + array2;
   cout << array3 << endl;
    return 0;
}
