/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: system.cc
  > Author: Donald
  > Created Time: 2014/09/23/ 15:43:05
  > details:
  =============================================*/
#include "system.h"
using namespace std;

User::User()
    :flag_(true),grade_(0),passwd_("1234"){}
    User::~User(){}
    //set
    void User::setFlag(bool flag){
        flag_ = flag;
    }
void User::setGrade(int grade){
    grade_ = grade;
}
void User::setPasswd(string passwd){
    passwd_ = passwd;
}
void User::setUser(int id,string name,string passwd){
    id_ = id;
    name_ = name;
    passwd_ = passwd;
}
void User::setName(std::string name){
    name_ = name;
}
//get
string User::getName() const{
    return name_;
}
int User::getId() const {
    return id_;
}
bool User::getFlag() const{
    return flag_;
}
string User::getPasswd() const{
    return passwd_;
}
//Question vec_,
bool Question::isExist(const string &name){
    vector<User>::iterator it ;
    it = find(vec_.begin(),vec_.end(),name);
    //it = 0;

    if(it != vec_.end()){
        return true;
    }else{
        return false;
    }
}

void Question::readFile(ifstream &in){
    User temp;
    string line;
    while(getline(in,line)){//按行读取
        string name,passwd;
        istringstream stream(line); 
        stream >> name;
        stream >> passwd;

        temp.setName(name);
        temp.setPasswd(passwd);
        vec_.push_back(temp);
    }
}
bool Question::matchPasswd(const string &name, const string &passwd){
    vector<User>::iterator it ;
    it = find(vec_.begin(),vec_.end(),name);

    if((*it).getPasswd() == passwd){
        return true;
    }else{
        return false;
    }
}

void Question::readExam(ifstream &in){
    VR temp;
    string line;
    while(getline(in,line)){
        string question,A,B,C,D,answer;
        istringstream stream(line);
        stream >> question;
        stream >> A;
        stream >> B;
        stream >> C;
        stream >> D;
        stream >> answer;

        temp.push_back(question);
        temp.push_back(A);
        temp.push_back(B);
        temp.push_back(C);
        temp.push_back(D);
        temp.push_back(answer);

        exam_.push_back(temp);
    }
}
void Question::beginExam(){

}
void Question::history(){
    for(vector< VR >::iterator it = vec_.begin(); it != vec_.end(); ++it){
        cout << *it << endl;    
    }
}
void Question::printGrade(){

}   

void Question::login(){
    User user();
    string name,passwd;
    cout << "Please input the user' name"  << endl;
    cin >> name;

    if(isExist(name)){
        cout << "hello," << name << "! 请输入密码："  << endl;
        cin >> passwd;
        if(matchPasswd(name,passwd)){                         
            cout << name << ",欢饮来到作业部落" << endl;
            mainFace();
        } 
    }

}
//system
void Question::mainFace(){
    system("clear");
    cout << "   \033[1;34m欢迎来到作业部落\033[0m  " << endl;
    cout << "\033[1;36m1. 答题"  << endl;
    cout << "2.查看排行榜" << endl;
    cout << "0. 退出程序\033[0m" << endl;

    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            beginExam();
            break;
        case 2:
            history();
            break;
        case 0:
            cout << "Bye!..." << endl;
            sleep(1);
            exit(EXIT_SUCCESS);
            break;
        default:
            cout << "输入非法！" << endl;
            mainFace();
            break;
    }
}
