/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: itos.cc
  > Author: Donald
  > Created Time: 2014/09/16/ 15:35:00
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
//比较繁琐，可以通过设计标志位来实现
//int flag = (num < 0)? -1 : 1;
//num /= flag;  num *= flag;
string  myitoa(int num){
    string str = "";
    if(num < 0){
        str += '-';
        num = 0 - num;
    }
    while(num > 0){
        int temp ;//定义为char比较简单，这里是为了练习static_cast的用法
        temp = num % 10 + '0';
        num = num / 10;
        str += static_cast<char>(temp);
    }
   // cout << str << endl;
    string ret = "";
    if(str[0] != '-'){
        for(string::reverse_iterator riter = str.rbegin() ;
                riter != str.rend();
                ++ riter )
        {
            ret += *riter;//这种处理方式，负号将会出现在最后。
        }
    }else{
        ret += '-'; 
        for(string::reverse_iterator riter = str.rbegin();
                riter != str.rend() - 1;
                ++ riter )
        {
            ret += *riter;//这种处理方式，负号将会出现在最后。
        }

    }
    return ret;
}
//这是最简丹的方法
string my_itoa(int num){
    char str[512] = "";
    snprintf(str,sizeof str,"%d",num);
    return static_cast<string>(str);
}

string itos_vec(vector<int> arr){
    string str = ""; 
    for(string::size_type index = 0;
            index != arr.size();
            ++ index)
    {
        //str += myitoa(arr[index]) ;
        str += my_itoa(arr[index]);
        if(index < arr.size() -1)
        {
            str += " ";
        }
    }
    return str;
}
void init_arr(vector<int> &arr,size_t num){
    for(vector<int>::size_type index = 0;
            index != num;
            ++ index)
    {
        int num ;
        num = pow((-1),rand()%2) * (rand()%10000);
        arr.push_back(num);
    }
}
void print_arr(vector<int> arr){
    for(vector<int>::const_iterator citer = arr.begin();//注意这里要写上作用域，一定有::
            citer != arr.end();
            ++ citer )
    {
        cout << *citer << " ";
    }
    cout << endl;
}
int main(int argc, const char *argv[])
{
    srand(time(NULL));
    vector<int> arr;
    init_arr(arr,atoi(argv[1]));
    print_arr(arr);

    string str = itos_vec(arr);
    cout << str << endl;
    return 0;
}
