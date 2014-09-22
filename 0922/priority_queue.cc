/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: priority_queue.cc
  > Author: Donald
  > Created Time: 2014/09/22/ 21:28:26
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
struct Stu{
    int id;
    int grade;
    string name;

    Stu(int id_, int grade_, string name_)
        :id(id_),grade(grade_),name(name_)
    {
    }
};
void print(const Stu  &stu){
    printf("%3d %7s %4d\n",stu.id,stu.name.c_str(),stu.grade);
}
class Cmp{
    public:
        bool operator()(const Stu &a, const Stu &b){
            if(a.grade > b.grade){
                return false;
            }else if(a.grade == b.grade && a.name< b.name){
                return false;
            }else if(a.grade == b.grade && a.name == b.name && a.id < b.id){
                return false;
            }else{
                return true;
            }
        }
};
int main(int argc, const char *argv[])
{
    priority_queue<Stu, vector<Stu>, Cmp> vec;

    vec.push(Stu(1,100,"chd"));
    vec.push(Stu(2,10,"xzy"));
    vec.push(Stu(7,60,"cssx"));
    vec.push(Stu(4,80,"ser"));
    vec.push(Stu(5,56,"sdw"));
    vec.push(Stu(6,97,"donald"));
    vec.push(Stu(6,99,"donald"));
    vec.push(Stu(5,99,"donald"));
    vec.push(Stu(5,98,"donald"));
    vec.push(Stu(0,100,"donald"));

    while(!vec.empty()){
        print(vec.top());
        vec.pop();
    }
    return 0;
}
