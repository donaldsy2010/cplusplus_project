/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: main.cc
  > Author: Donald
  > Created Time: 2014/09/22/ 22:49:42
  > details:
=============================================*/
#include "student.h"
using namespace std;
int main(int argc, const char *argv[])
{

    Roster roster;
    roster.creatStu(5);
    roster.setStu(Stu(1,100,"chd"));
    roster.setStu(Stu(2,10,"xzy"));
    roster.setStu(Stu(7,60,"cssx"));
    roster.setStu(Stu(4,80,"ser"));
    roster.setStu(Stu(5,56,"sdw"));
    roster.setStu(Stu(6,97,"donald"));
    roster.setStu(Stu(6,99,"donald"));
    roster.setStu(Stu(5,99,"donald"));
    roster.setStu(Stu(5,98,"donald"));
    roster.setStu(Stu(0,100,"donald"));

    roster.printStu();

    return 0;
}
