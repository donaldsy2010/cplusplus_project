/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: person.cc
  > Author: Donald
  > Created Time: 2014/09/19/ 22:33:18
  > details:
=============================================*/
#include "person.h"
using namespace std;
Person::Person(){}
Person::Person(string name, string addr, Date brith)
    :name_(name), addr_(addr), brith_(brith)
{}

Person::~Person(){
    cout << "destruction...." << name_  << endl;
}

int Person::aliveDays(){
    Date Today = Date::today();
    
    int today_is_days = Today.calDayOfYear();
    int brith_is_days = brith_.calDayOfYear();
    int days = 0;
    for(int index = brith_.getYear(); index < Today.getYear(); ++ index){
        days +=  365;
        if(Date::isLeapYear(index)){
            days ++;
        }
    }
    days = days + today_is_days - brith_is_days;
    cout << endl << "已经沉默了" << days << "天了！！！" << endl;
    return days;
}
bool Person::brith_is_over(){
    Date Today = Date::today();
   
    bool flag = true;
    if(Today.getMonth() < brith_.getMonth()){
        flag = false;
    }else if(Today.getMonth()  == brith_.getMonth() && Today.getDay() < brith_.getDay()){
        flag = false;
    }else if(Today.getMonth()  == brith_.getMonth() && Today.getDay() == brith_.getDay()){
        cout << "少年，today is your birthday，祝你生日快乐！" << endl;
    }

    int today_is_days = Today.calDayOfYear();
    int brith_is_days = brith_.calDayOfYear();
    int toword_brith  = brith_is_days - today_is_days;
    flag == true 
        ? cout << "你的生日已经过去了" << endl 
        : cout << "你的生日还没过，还有" << toword_brith << " 天，到时候别忘记了额！奋斗的同时还是要记住自己的生日得" << endl;

    return flag;
}
void Person::print_brith(){
    cout << name_ << "的生日是 " << brith_.getMonth() << "/" << brith_.getDay() << endl;
}
