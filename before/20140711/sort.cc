#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
struct Student{
    string name_;
    int score_;
    int age_;
};

bool cmp(const Student &s1, const Student &s2){
    if(s1.score_ != s2.score_){
        return s1.score_ < s2.score_;
    }else if(s1.age_ != s2.age_){
        return s1.age_ < s2.age_;
    }else{
        return s1.name_ < s2.name_;
    }
}

int main(int argc, const char *argv[])
{
    Student stu[]={
        {"刘备",100,500},
        {"张飞",99,504},
        {"关羽",100,510}
    };
    std::sort(stu,stu+3,cmp);
    for(int i=0;i < 3;i++){
        cout<<" name = "<<stu[i].name_<<" score = "
            <<stu[i].score_<<" age = "<<stu[i].age_
            <<endl;
    }
    return 0;
}
