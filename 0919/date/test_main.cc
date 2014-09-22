/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: test_main.cc
  > Author: Donald
  > Created Time: 2014/09/19/ 19:58:59
  > details:
=============================================*/
#include "date.h"
using namespace std;
int main(int argc, const char *argv[])
{
    Date date1 ;
    date1.printDate();
    date1.printEn();
    date1.calDayOfYear();

    cout << endl ; 
    
    Date date2;
    date2.setToday();
    date2.printDate();
    date2.printEn();
    date2.calDayOfYear();

    cout << endl ; 
    Date date3(2012,9,19);
    date3.printDate();
    date3.printEn();
    date3.calDayOfYear();

    cout << endl ; 
    Date date4(2012,9,17);
    date4.printDate();
    date4.printEn();
    date4.calDayOfYear();

    cout << endl ; 
    Date::today();    
    Date::diffDate(date2, date1);
    Date::diffDate(date1, date2);
    Date::diffDate(date2, date3);
    Date::diffDate(date3, date2);
    Date::diffDate(date3, date4);
    Date::diffDate(date4, date3);
    return 0;
}
