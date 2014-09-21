/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: main.cc
  > Author: Donald
  > Created Time: 2014/09/19/ 23:07:13
  > details:
=============================================*/
#include "person.h"
using namespace std;
int main(int argc, const char *argv[])
{
    Date date;
    date.setDate(1991,3,14);

    Person person("donald","shenzheng",date);
    person.aliveDays();
    person.print_brith();
    person.brith_is_over();

    Date date2(1991,9,21);

    Person absde("absde","chendu",date2);
    absde.aliveDays();
    absde.print_brith();
    absde.brith_is_over();

    Date date3(1991,9,23);

    Person ben("ben","chendu",date3);
    ben.aliveDays();
    ben.print_brith();
    ben.brith_is_over();
    return 0;
}
