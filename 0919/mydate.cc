/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: mydata.cc
  > Author: Donald
  > Created Time: 2014/09/19/ 12:52:08
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <sys/time.h>
using namespace std;
struct Date{
    int year_;
    int month_;
    int day_;
    int hour_;
    int min_;
    int sec_;
//private:
    void print_date(){
        cout << year_<< "/" << month_ << "/" << day_ <<
            " " << hour_ << ":" << min_ << ":" << sec_ 
            << endl;
    }

    void setNow(){
        time_t temp = time(NULL);
        time_t now;
        time(&now);//这两句和以上的等价
        struct tm *localT = localtime(&temp);
        year_ = 1900 + localT->tm_year;
        month_ = 1 + localT->tm_mon;
        day_ = localT->tm_mday;
        hour_ = localT->tm_hour;
        min_ = localT->tm_min;
        sec_ = localT->tm_sec;
    }
    void print_en(){
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

        cout << month[month_ - 1] << " " << day_ << " " << year_ <<
            " " << hour_ << ":" << min_ << ":" << sec_ 
            << endl;
    }
};
int main(int argc, const char *argv[])
{
    Date date;
    date.month_ = 3;
    date.year_ = 2010;
    date.day_ = 28;
    date.sec_ = 12;
    date.hour_ = 12;
    date.min_ = 12;
    date.print_date();
    date.print_en();

    cout << endl ; 
    date.setNow();
    date.print_date();
    date.print_en();
    return 0;
}
