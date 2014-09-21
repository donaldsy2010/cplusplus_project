/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: contacts.h
  > Author: Donald
  > Created Time: 2014/09/19/ 23:35:28
  > details:
=============================================*/
#ifndef __MY_CONTACTS_
#define __MY_CONTACTS_ 

#include <iostream>
#include <string>
#include <vector>
#include <cstdio> 
#include <cstdlib>
#include <ctime>
using namespace std;
struct conts{
    string name_;
    string phone_;
    string addr_;
};
class Contacts{
    public:
        Contacts(){
            phone_ = "";
            name_ = "";
            addr_ = "";
        }
        
        Contacts(string phone, string name, string addr)
            :phone_(phone),name_(name), addr_(addr)
        {
        }
        
        ~Contacts(){
           cout << endl << "\033[1;33mdestruction.... " << name_ << "\033[0;m" <<  endl; 
        }
       void  set(string &phone,string &name, string &addr);
       const conts get();

       void del_conts(string phone);
       conts find_record(string phone);
       vector<string> find_record(string name,string phone);
       vector<string> ind_record(string addr,string phone, string name);    

    private:
        string name_;
        string addr_;
        string phone_;
};

string creat_phone();
string creat_name();
const string creat_addr(const vector<string> &vec);

#endif  /*__MY_CONTACTS_*/
