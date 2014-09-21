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
using std::string;
using std::vector;
class Record;
typedef vector<Record> VR;
class Record{
    string name_;
    string phone_;
    string addr_;
    public:
        Record();
        Record(string name,string phone,string addr);
        ~Record();

       void setRecord(string name,string phone,string addr);       
       const Record getRecord() const;

       const string getPhone() const;
       const string getName() const;
       const string getAddr() const;

       void   setPhone(string phone) ;
       void   setName(string name) ;
       void   setAddr(string addr) ;
        //自动生成
       string creatPhone();
       string creatName();
       const string creatAddr(const vector<string> &vec);

       static void delByPhone(const string &phone, vector<Record> &vec);
       static vector< VR > findByPhone(const string &phone,const vector<Record> &vec) ;
       static vector< VR > findByName(const string &name,const vector<Record> &vec) ;
       static vector< VR > findByAddr(const string &addr,const vector<Record> &vec) ;    

       static void printRecord(const vector<Record> &vec) ;

};

#endif  /*__MY_CONTACTS_*/
