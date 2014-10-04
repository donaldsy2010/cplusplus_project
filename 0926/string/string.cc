#include "String.h"//不能和string.h重名
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

String::String()
    :str_(new char[1])
{    
    *str_ = 0;
}

String::String(const String &s)
    :str_(new char[strlen(s.str_) + 1])
{
    ::strcpy(str_,s.str_);
}

String::~String(){
    cout << "析构>>>>>>>" << *this << endl;
    delete[] str_;
}

String &String::operator+=(const String &s){
    char *temp = new char[strlen(str_) + strlen(s.str_) + 1];

    ::strcpy(temp,str_);
    ::strcat(temp,s.str_);    
    ::strcpy(str_,temp);
    return *this;
}

String::String(const char *s)
    :str_(new char[strlen(s) + 1])
{
    ::strcpy(str_,s);
}
