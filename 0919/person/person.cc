/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: person.cc
  > Author: Donald
  > Created Time: 2014/09/19/ 22:33:18
  > details:
=============================================*/
#include "person.h"

void today(Date &date){
    time_t temp = time(NULL);
    struct tm *localT = localtime(&temp);
    date.year_ = 1900 + localT->tm_year;
    date.month_ = 1 + localT->tm_mon;
    date.day_ = localT->tm_mday;
}

bool isLeapYear(int year){
    if((year%400 == 0) || ((year%4 == 0) && (year%100 != 0))){
        return false;
    }else{
        return true;
    }
}

int calDayOfYear(Date date){
    int year, month, day;

    year = date.year_;
    month = date.month_;
    day = date.day_;

    int days = 0;
    for(int index = 1; index < month; ++ index){
        days += 30;
        switch(index){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                 days += 1;
                 break;
            case 2:
                if(isLeapYear(index)){
                    days -= 2;
                }else{
                    days -= 1;
                }
                break;
            default:
                break;
        }
    }
    days += day;
    return days;
}
int Person::aliveDays(){
    int brithYear = brith_.year_;
    int brithMonth = brith_.month_;
    int brithDay = brith_.day_;

    Date Today;
    today(Today);
    int toYear = Today.year_;
    int toMonth = Today.month_;
    int toDay = Today.day_;

    int today_is_days = calDayOfYear(Today);
    int brith_is_days = calDayOfYear(brith_);
    int days = 0;
    for(int index = brithYear; index < toYear; ++ index){
        days +=  365;
        if(isLeapYear(index)){
            days ++;
        }
    }
    days = days + today_is_days - brith_is_days;
    cout << endl << "已经沉默了" << days << "天了！！！" << endl;
    return days;
}
bool Person::brith_is_over(){
    Date Today;
    today(Today);
    int toMonth = Today.month_;
    int toDay = Today.day_;
   
    bool flag = true;
    if(toMonth < brith_.month_){
        flag = false;
    }else if(toMonth == brith_.month_ && toDay < brith_.day_){
        flag = false;
    }else if(toMonth == brith_.month_ && toDay == brith_.day_){
        cout << "少年，today is your birthday，祝你生日快乐！" << endl;
    }

    int today_is_days = calDayOfYear(Today);
    int brith_is_days = calDayOfYear(brith_);
    int toword_brith  = brith_is_days - today_is_days;
    flag == true 
        ? cout << "你的生日已经过去了" << endl 
        : cout << "你的生日还没过，还有" << toword_brith << " 天，到时候别忘记了额！奋斗的同时还是要记住自己的生日得" << endl;

    return flag;
}
void Person::print_brith(){
    cout << name_ << "的生日是 " << brith_.month_ << "/" << brith_.day_ << endl;
}
