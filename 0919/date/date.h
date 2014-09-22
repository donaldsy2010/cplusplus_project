/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: date.h
  > Author: Donald
  > Created Time: 2014/09/19/ 19:51:02
  > details:
=============================================*/
#ifndef __MY_DATE_
#define __MY_DATE_

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <sys/time.h>
#include <inttypes.h>//int64_t包含在该文件中

//using namespace std;
struct Date{
    public:     
        Date();
        Date(int year, int month, int day);
        ~Date();
//应该添加判断日期是否合法
        void setDate(int year,int month, int day);
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        int getHour() const;
        int getMin() const;
        int getSec() const;

        bool isLeapYear() const;
        int calDayOfYear() const;
        
        void printDate()const;
        void setToday();
        void printEn() const;
        
        static Date today();
        static Date today(Date &date);
        static int64_t toBeginDays(const Date &date1);
        static int diffDate(const Date &date1 ,const Date &date2);
        static bool isLeapYear(int year);
    private:
        int year_;
        int month_;
        int day_;
        int hour_;
        int min_;
        int sec_;
};
#endif /*__MY_DATE_*/
