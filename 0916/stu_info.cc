/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: stu_info.cc
  > Author: Donald
  > Created Time: 2014/09/16/ 16:26:06
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef struct tag{
    int grade;
    string name;
}student;
void insert_sort(vector<student> &vec){
    int lindex,qindex;
    int num = vec.size();

    for(lindex = 0; lindex != num; ++ lindex){
        int key = vec[lindex].grade;
        for(qindex = lindex - 1; qindex >= 0; qindex --){
            if(vec[qindex].grade > key){
                break;
            }
            swap(vec[qindex],key);
        }
        vec[qindex + 1].grade = key;
    }
}
void init_stu(vector<student> &vec,int num){
    for(vector<student>::size_type ix = 0;
            ix != num;
            ++ ix) 
    {
        (vec->grade).push_back(rand()%101);
        vec->name.push_back(rand()%26 + 'A');
        vec->name.push_back(rand()%26 + 'a');
        vec->name.push_back(rand()%26 + 'a');
        vec->name.push_back(rand()%26 + 'a');
    }
}
void print_stu(vector<student> vec){
    cout << " 姓 名 " << " 成绩  " << endl;
    for(vector<student>::const_iterator citer = vec.begin();
            citer != vec.end();
            ++ citer)
    {
        cout << (*citer).name << "   " << (*citer).grade << endl;
    }
}
void total_info(vector<student> vec, vector<student> &ret){
     for(vector<student>::const_iterator citer = vec.begin();
            citer != vec.end();
            ++ citer)
    {
        if((*citer).grade >= 60){
            ret->name.push_back((*citer).name);
            ret->grade.push_back((*citer).grade);
        }
    }
}
int main(int argc, const char *argv[])
{
    srand(time(NULL));
    int num = 10;
    if(argc == 2){
        num = atoi(argv[1]);
    }

    vector<student> vec,ret;
    init_stu(vec,num);
    print_stu(vec);

    total_info(vec,ret);
    print_stu(ret); 

    insert_sort(vec);
    print_stu(vec);
    return 0;
}
