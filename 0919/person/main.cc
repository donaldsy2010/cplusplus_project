/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: main.cc
  > Author: Donald
  > Created Time: 2014/09/19/ 23:07:13
  > details:
=============================================*/
#include "person.h"
int main(int argc, const char *argv[])
{
    Date date;
    date.year_ = 1991;
    date.month_ = 3;
    date.day_ = 14;

    Person person("donald","shenzheng",date);
    person.aliveDays();
    person.print_brith();
    person.brith_is_over();

    Date date2;
    date2.year_ = 1991;
    date2.month_ = 9;
    date2.day_ = 19;

    Person absde("absde","chendu",date2);
    absde.aliveDays();
    absde.print_brith();
    absde.brith_is_over();

    Date date3;
    date3.year_ = 1991;
    date3.month_ = 9;
    date3.day_ = 20;

    Person ben("ben","chendu",date3);
    ben.aliveDays();
    ben.print_brith();
    ben.brith_is_over();
    return 0;
}
