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
    person.printBrith();
    person.brithIsOver();

    Date date2(1991,9,22);

    Person absde("absde","chendu",date2);
    absde.aliveDays();
    absde.printBrith();
    absde.brithIsOver();

    Date date3(1991,9,23);

    Person ben("ben","chendu",date3);
    ben.aliveDays();
    ben.printBrith();
    ben.brithIsOver();
    return 0;
}
