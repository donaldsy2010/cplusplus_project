/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: priority_queue.cc
  > Author: Donald
  > Created Time: 2014/09/22/ 21:17:08
  > details:
=============================================*/
#ifndef __STUDENT_H_
#define __STUDENT_H_ 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>
class Cmp;
struct Stu{
    public :
        Stu();
        Stu(int id,int grade,std::string name);
        ~Stu();

        void setId(int );
        void setName(std::string);
        void setGrade(int);
        
        const int getId() const;
        const int getGrade() const;
        const std::string getName() const;
    private:
        int id_;
        int grade_;
        std::string name_;

};

struct Roster{
    public:
        void creatStu(int num);
        void setStu(const Stu &stu);
        const void printStu() const;
    private:
        priority_queue<Stu,std::vector<Stu>,Cmp> vec_;
};
class Cmp{
    public:
        bool operator()(const Stu &a, const Stu &b){
            if(a.getGrade() > b.getGrade()){
                return false;
            }else if(a.getGrade() == b.getGrade() && a.getName() < b.getName()){
                return false;
            }else if(a.getGrade() == b.getGrade() && a.getName() == b.getName() && a.getId()< b.getId()){
                return false;
            }else{
                return true;
            }
        }
};

#endif  /*__STUDENT_H_*/
