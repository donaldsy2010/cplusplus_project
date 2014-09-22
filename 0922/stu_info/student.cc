/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: student.cc
  > Author: Donald
  > Created Time: 2014/09/22/ 22:11:48
  > details:
=============================================*/
#include "student.h"
using namespace std;
//stu
Stu::Stu(){

}
Stu::Stu(int id,int grade,std::string name)
    :id_(id),name_(name),grade_(grade)
{        
}
~Stu(){}
void Stu::setId(int id){
    id_ = id;
}
void Stu::setName(string name){
    name_ = name;
}
void Stu::setGrade(int grade){
    grade_ = grade;
}
const int getId() const{
    return id_;
}
const int getGrade() const{
    return grade_;
}
const std::string getName() const{
    return name_;
}
//roster
void Roster::creatStu(int num){
    int grade;
    int id;
    string name;
    Stu temp;
    for(vector<Stu>::size_type ix = 0;
            ix != num;
            ++ ix) 
    {
        name = "";
        grade = rand()%101;
        name += rand()%26 + 'A';
        name += rand()%26 + 'a';
        name += rand()%26 + 'a';
        name += rand()%26 + 'a';
        name += rand()%26 + 'a';

        temp.setId(ix);
        temp.setGrade(grade);
        temp.setName(name);
        vec_.push(temp);
    }
}
void Roster::setStu(const Stu &stu){
    vec_.push(stu);
}
const void Roster::printStu() const{
    cout << "姓 名 " << " 成绩  " << endl;
    for(vector<Stu>::const_iterator citer = vec_.begin();
            citer != vec_.end();
            ++ citer)
    {
        cout << (*citer).getId() << "    " << (*citer).getName() << "   " << (*citer).getGrade() << endl;
    }
}
