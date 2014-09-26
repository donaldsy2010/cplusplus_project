/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: solve_system.h
  > Author: Donald
  > Created Time: 2014/09/23/ 11:32:10
  > details:
=============================================*/
#ifndef __SOLVE_SYSTEM_
#define __SOLVE_SYSTEM_ 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdio> 
#include <cstdlib>
#include <unistd.h>
struct User{
    private:
        int id_;
        std::string name_;
        bool flag_;//账户状态， 0 冻结        
        int grade_;
        std::string passwd_;
    public:
        User();
        ~User();

        void setFlag(bool flag);
        void setGrade(int grade);
        void setPasswd(std::string passwd);
        void setName(std::string name);
        void setUser(int id,std::string name,std::string passwd);
        
        std::string getName() const;
        int getId() const ;
        bool getFlag() const;
        std::string getPasswd() const;
};

typedef std::vector<std::string> VR;
struct Question{
    public:
        void readFile(std::ifstream &in);
        void readExam(std::ifstream &in);
        void beginExam();
        void printGrade();        
        bool isExist(const std::string &name);
        void login();
         bool matchPasswd(const std::string &name,const std::string &passwd);

        static void history();
        static void mainFace();
    private:
        std::vector<User> vec_;//存储用户的容器
        std::vector< VR > exam_;//容器的一个元素代表一道题目
};

#endif  /*__SOLVE_SYSTEM_*/
