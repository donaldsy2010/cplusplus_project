/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: data.cc
  > Author: Donald
  > Created Time: 2014/09/19/ 19:52:08
  > details:
=============================================*/
#include "date.h"
using namespace std;
Date::Date()
    :year_(1900), month_(1), day_(1)
{    
}

Date::Date(int year, int month, int day)
    :year_(year), month_(month), day_(day)
{
}

Date::~Date(){
//    cout << "destruct..." << endl;
}

void Date::setDate(int year,int month, int day){
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::getYear() const{
    return year_;
}
int Date::getMonth() const{
    return month_;
}
int Date::getDay() const{
    return day_;
}
bool Date::isLeapYear() const{//什么时候给参数
    int year = year_ ;
    if((year%400 == 0) || ((year%4 == 0) && (year%100 != 0))){
        return true;
    }else{
        return false;
    }
}

int Date::calDayOfYear() const{
    int year, month, day;

    int days = 0;
    year = year_;
    month = month_;
    day = day_;

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
                if(isLeapYear()){//闰年
                    days -= 1;
                }else{
                    days -= 2;
                }
                break;
            default:
                break;
        }
    }
    days += day;

//    cout << year << "/" << month << "/" << day << " 是 " 
  //      << year << " 的第" << days << " 天"  << endl;
    return days;
}

void Date::printDate() const{
    cout << year_<< "/" << month_ << "/" << day_ << endl;
}

void Date::setToday(){
    time_t temp = time(NULL);
    // time_t now;
    //time(&now);//这两句和以上的等价
    struct tm *localT = localtime(&temp);
    year_ = 1900 + localT->tm_year;
    month_ = 1 + localT->tm_mon;
    day_ = localT->tm_mday;
}
void Date::printEn() const {
    vector<string> month;
    month.push_back("January");
    month.push_back("February");
    month.push_back("March");
    month.push_back("April");
    month.push_back("May");
    month.push_back("June");
    month.push_back("July");
    month.push_back("August");
    month.push_back("September");
    month.push_back("October");
    month.push_back("November");
    month.push_back("December");

    cout << month[month_ - 1] << " " << day_ << " " << year_ << endl;
}
#if 1
Date Date::today(Date &date){

    date.setToday();
    return date;
}
Date Date::today(){
    Date date;
    date.setToday();
    //date.printDate();
    //    date.printEn();

    return date;
}


int Date::diffDate(const Date &date1, const Date &date2){
    int year1 = date1.year_;
    int year2 = date2.year_;
    int month1 = date1.month_;
    int month2 = date2.month_;

    int haveDays1 = date1.calDayOfYear();
    int haveDays2 = date2.calDayOfYear();

    int days = 0;

    int smallYear = year1 < year2 ? year1 : year2;//12 < 14 ? 12 : 14
    int bigYear   = year1 >= year2 ? year1 : year2;//12 >= 14 ? 12 : 14

    if(year1 < year2){
        for(int index = year1; index < year2; index ++){
            days += 365;
            if(!isLeapYear(index)){
                days ++;
            }
            days = -(days - haveDays1 + haveDays2) ;
        }
    }else {
        for(int index = year2; index < year1; index ++){
            days += 365;
            if(!isLeapYear(index)){
                days ++;
            }
        }
        if(year1 == year2 && month1 < month2 ){//同一年，月不同
            days = days + haveDays2 - haveDays1 ;
        }else{
            days = days + haveDays1 - haveDays2 ;
        }
    }
    cout << "相差 ："  << days << endl;
    return days;
}
#endif
bool Date::isLeapYear(int year){

    if((year%400 == 0) || ((year%4 == 0) && (year%100 != 0))){
        return true;
    }else{
        return false;
    }
}
