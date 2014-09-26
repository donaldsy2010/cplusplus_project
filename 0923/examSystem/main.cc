/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: main.cc
  > Author: Donald
  > Created Time: 2014/09/23/ 16:40:55
  > details:
=============================================*/
#include "system.h"
using namespace std;
int main(int argc, const char *argv[])
{
    ifstream user("user.txt");
    ifstream examFile("exam.txt");

    Question test;
    test.readFile(user);
    test.login();

    return 0;
}
