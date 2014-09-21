/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: contacts.cc
  > Author: Donald
  > Created Time: 2014/09/19/ 23:49:25
  > details:
=============================================*/
#include "contacts.h"
string creat_phone(){//11
    string str = "1";
    for(int index = 0; index != 10; ++ index){
        str += rand()%10 + '0';
    }
    return str;
}

string creat_name(){//5-9
    string str; 
    str += rand()%26 + 'A';

    int size = rand()%5 +5;
    for(int index = 0; index != size; ++ index){
        str += rand()%26 + 'a';
    }
    return str;
}

const string creat_addr(const vector<string> &vec){//10
    size_t index = rand()%6;
    string str = vec[index];

    return str;
}
void  Contacts::set(string &phone, string &name, string &addr){
    phone_ = phone;
    name_ = name;
    addr_ = addr;
}

const conts Contacts::get(){
    conts  temp;
    temp.phone_ = phone_;
    temp.addr_ = addr_;
    temp.name_ = name_;

    return temp;
}

void Contacts::del_conts(string phone){

}
conts Contacts::find_record(string phone){

}
vector<string> Contacts::find_record(string name,string phone){

}
vector<string> Contacts::ind_record(string addr ,string phone, string name){

}
