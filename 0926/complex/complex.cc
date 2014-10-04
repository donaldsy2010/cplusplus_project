/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: complex.cc
  > Author: Donald
  > Created Time: 2014/09/27/ 17:18:35
  > details:
=============================================*/
#include "Complex.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Complex::Complex()
    :real_(0),
    img_(0)   
{    
}

Complex::Complex(int real, int img)
    :real_(real),
    img_(img)
{}

Complex::~Complex()
{
}

Complex &Complex::operator=(const Complex &com){
    real_ = com.real_;
    img_  = com.img_;

    return *this;
}

Complex &Complex::operator+=(const Complex &com1){
    real_ += com1.real_;
    img_ += com1.img_;

    return *this;
}

Complex operator+(const Complex &com1, const Complex &com2){
    Complex temp;
    temp.real_ += com1.real_;
    temp.img_  += com1.img_;

    temp.real_ += com2.real_;
    temp.img_  += com2.img_;

    return temp;
}
Complex operator+(const Complex &com1, int a){//a为实部
    Complex temp;
    temp.real_ += com1.real_;
    temp.img_  += com1.img_;

    temp.real_ += a;

    return temp;
}
#if 0
Complex operator+(const Complex &com1, const int &b) {//b为虚部
    Complex temp;
    temp.real_ += com1.real_;
    temp.img_  += com1.img_;

    temp.img_  += b;

    return temp;
}
#endif
#if 0
Complex operator+(int a, const){
    Complex temp;
    temp.real_ += a;
    temp.real_ += b;

    return temp;
}
#endif
Complex operator-(const Complex &com1, const Complex &com2){
    Complex temp;
    temp.real_ = com1.real_ - com2.real_;
    temp.img_  = com1.img_ - com2.img_;

    return temp;
}

Complex operator*(const Complex &com1, const Complex &com2){
    Complex temp;
    temp.real_ = com1.real_ * com2.real_ - com1.img_ * com2.img_;
    temp.img_  = com1.img_ * com2.real_ +  com2.img_ * com1.real_;

    return temp;
}
Complex operator/(const Complex &com1, const Complex &com2){
    Complex temp;
    int tmp = (com1.img_*com1.img_) + com2.img_*com2.img_;
    temp.real_  = (com1.img_ * com2.real_ +  com2.img_ * com1.real_)/tmp;
    temp.img_  = (com1.img_ * com2.real_ - com2.img_ * com1.real_) / tmp;

    return temp;
}
