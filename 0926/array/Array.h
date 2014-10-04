/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: array.h
  > Author: Donald
  > Created Time: 2014/09/27/ 11:21:35
  > details:
=============================================*/
#ifndef __ARRAY_H_
#define __ARRAY_H_ 

#include <iostream>
#include <sstream>
class Array{
    int* ary_;
    size_t size_;//元素的数量
    size_t capacity;//数组容量
    private:
        friend std::ostream &operator<<(std::ostream &os, const Array &ary);

        //如果不写为友元的话，后边的参数就只能偶一个
        //以下的重载比较操作符中有很多重复代码，所以可以写一个cmp函数，以用于节省代码量
        friend bool operator<(const Array &ary1,const Array &ary2);
        friend bool operator<=(const Array &ary1,const Array &ary2);
        friend bool operator>(const Array &ary1,const Array &ary2);
        friend bool operator>=(const Array &ary1,const Array &ary2);
        friend bool operator==(const Array &ary1,const Array &ary2);
        friend bool operator!=(const Array &ary1,const Array &ary2);
        friend Array operator+(const Array &ary1,const Array &ary2);

    public:
        Array();
        Array(int num);
        Array(const Array &ary);
        ~Array();

        
        //Array operator[](int num);
        //下标操作符必须提供const和非const两个版本
        int operator[](int num) const;
        int &operator[](int num){//通过下标来访问，以及赋值。
            return ary_[num];
        }
        Array &operator=(const Array &ary);
        Array &operator=(int* ary);//需要传递长度信息
        //Array &operator=(int* ary, size_t num);
        Array &operator+=(const Array &ary);

};

//这里必须写为内联函数，作用域就只是类的类部了，
//如果不加，就将会和std中的构成重复定义
inline std::ostream &operator<<(std::ostream &os, const Array &ary){
    os << "[ " ;
    for(size_t index = 0;index < ary.size_ - 1;++ index){
        os <<  *(ary.ary_ + index) << " , ";
    }
    return os << *(ary.ary_ + ary.size_ - 1) << " ]" ;
}
#endif  /*__ARRAY_H_*/
