/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: person.h
  > Author: Donald
  > Created Time: 2014/09/19/ 22:20:54
  > details:
  =============================================*/
#ifndef __MY_PERSON_
#define __MY_PERSON_ 
#include "../date/date.h"
using std::string;
class Person{
    public:
        Person();
        Person(string name, string addr, Date brith);

        ~Person();

        int aliveDays();
        bool brith_is_over();
        void print_brith();

    private:
        string name_;
        string addr_;
        Date brith_;
};
#endif  /*__MY_PERSON_*/
