/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: iterator.cc
  > Author: Donald
  > Created Time: 2014/09/15/ 23:58:06
  > details:
  =============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
int swap(int &left,int & right){
    int temp(left);
    left = right;
    right = temp;
}
void init_arr(vector<int> &arr,int size){
    for(vector<int>::size_type index = 0;
            index != size; 
            index ++){
        //  arr[index] = rand()%100;//只有在arr中的元素已知的情况下才能这么用
        arr.push_back(rand()%100);
    }
}
#if 0
void init_arr_iter(vector<int> &arr, int size){
    for(vector<int>::iterator iter = 0;
            iter != size;
            iter ++){
        arr.push_back(rand()%100) ;
    }
}
#endif
void print_arr(vector<int> &arr){
    for(vector<int>::const_iterator iter = arr.begin();
            iter != arr.end();
            iter ++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void select_sort(vector<int> &arr){
    int index = 0;//必须赋初值
    for(vector<int>::iterator iter = arr.begin();
            iter != arr.end();
            iter ++)
    {
        index ++;
        for(vector<int>::iterator liter = arr.begin() + index;
                liter != arr.end();
                liter ++)
        {
            if(*iter > *liter){
                swap(*iter,*liter) ;
            }
        }
    }
}
bool cmp(int left, int right){
    return left < right;
}
int main(int argc, const char *argv[])
{
    srand(time(NULL));
    int num = 10;
    if(argc == 2){
        num = atoi(argv[1]);
    }


    vector<int> arr;
    init_arr(arr,num);
    //    init_arr_iter(arr,num);
    print_arr(arr);
//    select_sort(arr);
    sort(arr.begin(), arr.end(), cmp);
    print_arr(arr);
    return 0;
}
