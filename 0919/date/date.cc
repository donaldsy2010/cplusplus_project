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
    :year_(1900), month_(1), day_(1),
        hour_(0),min_(0),sec_(0)
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
int Date::getHour() const{
    return hour_;
}
int Date::getMin() const{
    return min_;
}
int Date::getSec() const{
    return sec_;
}
bool Date::isLeapYear() const{//什么时候给参数
    int year = year_ ;//可以直接return，不用这么麻烦。
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
    hour_ = localT->tm_hour;
    min_ = localT->tm_min;
    sec_ = localT->tm_sec;

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


#if 0
int Date::diffDate(const Date &date1, const Date &date2){
    //再次陷入了具体的细节中了，如果直接计算两个日期的差值，逻辑较复杂，可以通过第三方（公元元年）来计算。
    //或者这里交换一下次序
    int year1 = date1.year_;
    int year2 = date2.year_;

    int haveDays1 = date1.calDayOfYear();
    int haveDays2 = date2.calDayOfYear();

    int days = 0;

    //    int smallYear = year1 < year2 ? year1 : year2;//12 < 14 ? 12 : 14
    //    int bigYear   = year1 >= year2 ? year1 : year2;//12 >= 14 ? 12 : 14

    if(year1 < year2){// 2010 < 2014
        for(int index = year1; index < year2; index ++){
            days += 365;
            if(isLeapYear(index)){
                days ++;
            }
            days = (days - haveDays1 + haveDays2) ;
        }
    }else {
        for(int index = year2; index < year1; index ++){
            days += 365;
            if(isLeapYear(index)){
                days ++;
            }
        }
        if(year1 == year2 && haveDays1 < haveDays2 ){//同一年，月不同
            days =  haveDays2 - haveDays1  ;
        }else{
            days = days + haveDays1 - haveDays2 ;
        }
    }
    cout << "相差 ："  << days << endl;
    return days;
}
#endif
#if 1
int64_t Date::toBeginDays(const Date &date1){
    int year1 = date1.year_;
    int haveDays1 = date1.calDayOfYear();

    int64_t days = 0;
    for (int i = 0; i < year1; i++) {
        days += 365; 
        if(isLeapYear(i)){
            days ++ ;
        }
    }
    days += haveDays1;
    return days;
}
int Date::diffDate(const Date &date1, const Date &date2){
    int year1 = date1.year_;
    int year2 = date2.year_;

    int64_t days1 = toBeginDays(date1) ;
    int64_t days2 = toBeginDays(date2);
    cout << "相差" << (days1 < days2 ? (days2 - days1):(days1 - days2)) << endl;
    return days1 < days2 ? (days2 - days1):(days1 - days2);
}
#endif
bool Date::isLeapYear(int year){

    if((year%400 == 0) || ((year%4 == 0) && (year%100 != 0))){
        return true;
    }else{
        return false;
    }
}
