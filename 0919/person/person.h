/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: person.h
  > Author: Donald
  > Created Time: 2014/09/19/ 22:20:54
  > details:
  =============================================*/
#ifndef __MY_PERSON_
#define __MY_PERSON_ 
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Date{
    int year_;
    int month_;
    int day_;
};
class Person{
    public:
        Person(){}
        Person(string name, string addr, Date brith)
            :name_(name), addr_(addr), brith_(brith)
        {}

        ~Person(){
            cout << "destruction...." << name_  << endl;
        }

        int aliveDays();
        bool brith_is_over();
        void print_brith();

    private:
        string name_;
        string addr_;
        Date brith_;
};
#endif  /*__MY_PERSON_*/
