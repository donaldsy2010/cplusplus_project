/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: Complex.h
  > Author: Donald
  > Created Time: 2014/09/27/ 17:12:49
  > details:
=============================================*/
#ifndef __COMPLEX_H_
#define __COMPLEX_H_ 
#include <iostream>
class Complex{
    friend std::ostream &operator<<(std::ostream &os, const Complex &com);

    friend Complex operator+(const Complex &com1, const Complex &com2);
    friend Complex operator+(const Complex &com1, int a);//a为实部
    friend Complex operator-(const Complex &com1, const Complex &com2);
    friend Complex operator*(const Complex &com1, const Complex &com2);
    friend Complex operator/(const Complex &com1, const Complex &com2);
   // friend Complex operator+(int a, int b);
//    friend Complex operator+(const Complex &com1, const int &b) ;//b为虚部
    public:
        Complex();
        Complex(int real, int img);
        ~Complex();

        Complex &operator=(const Complex &com);
        Complex &operator+=(const Complex &com1);

    private:
        int real_;
        int img_;
};

inline std::ostream &operator<<(std::ostream &os, const Complex &com){
    return os << com.real_ << " + " << com.img_ << "i";
}
#endif  /*__COMPLEX_H_*/
