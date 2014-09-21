/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: record.cc
  > Author: Donald
  > Created Time: 2014/09/21/ 22:10:53
  > details:
  =============================================*/
#include "contacts.h"

using namespace std;
Record::Record(){}
Record::Record(string name,string phone,string addr)
    :name_(name),phone_(phone),addr_(addr){}

    Record::~Record(){}

    void Record::setRecord(string name,string phone,string addr){
        name_ = name;
        phone_ = phone;
        addr_ = addr;
    }
const Record Record::getRecord() const{
    Record temp;
    temp.name_ = name_;
    temp.phone_ = phone_;
    temp.addr_ = addr_;

    return temp;
}
void   Record::setPhone(string phone) {
    phone_ = phone;
}
void  Record::setName(string name){
    name_ = name; 
}
void  Record::setAddr(string addr) {
    addr_ = addr;
}

const string  Record::getPhone() const{
    return phone_;
}
const string  Record::getName() const{
    return name_;
}
const string  Record::getAddr() const{
    return addr_;
}
string Record::creatPhone(){
    string str = "1";
    for(int index = 0; index != 10; ++ index){
        str += rand()%10 + '0';
    }
    return str;
}

string Record::creatName(){//5-9
    string str; 
    str += rand()%26 + 'A';

    int size = rand()%5 +5;
    for(int index = 0; index != size; ++ index){
        str += rand()%26 + 'a';
    }
    return str;
}

const string Record::creatAddr(const vector<string> &vec){//10
    size_t index = rand()%vec.size();
    string str = vec[index];

    return str;
}
void Record::delByPhone(const string &phone, vector<Record> &vec){
    for(vector<Record>::iterator it = vec.begin(); it != vec.end(); ++it){
        if(phone == (*it).getPhone()){
            vec.pop_back();//删除一条记录
        }
    }
}
vector<Record> Record::findByPhone(const string &phone,const vector<Record> &vec) {
    vector<Record> temp;
    for(vector<Record>::const_iterator it = vec.begin(); it != vec.end(); ++it){
        if(phone == (*it).getPhone()){
            temp.push_back(*it);//增加一条记录
        }
    }
    return temp;
}
vector<Record> Record::findByName(const string &name, const vector<Record> &vec) {
    vector<Record> temp;
    for(vector<Record>::const_iterator it = vec.begin(); it != vec.end(); ++it){
        if(name == (*it).getName()){
            temp.push_back(*it);//增加一条记录
        }
    }
    return temp;

}
vector<Record> Record::findByAddr(const string &addr,const vector<Record> &vec) {
    vector<Record> temp;

    for(vector<Record>::const_iterator it = vec.begin(); it != vec.end(); ++it){
        if(addr == (*it).getAddr()){
            temp.push_back(*it);//增加一条记录
        }
    }
    return temp;

}

void Record::printRecord(const vector<Record> &vec){
    for(vector<Record>::size_type ix = 0; ix != vec.size(); ++ ix){
        printf("\033[0;36m%13s   %-15s %-15s\n\033[0;m",
                vec[ix].getName().c_str(), 
                vec[ix].getPhone().c_str(),
                vec[ix].getAddr().c_str());
    }
}
