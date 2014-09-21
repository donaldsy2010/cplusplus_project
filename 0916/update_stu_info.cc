/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: update_stu_info.cc
  > Author: Donald
  > Created Time: 2014/09/16/ 16:50:43
  > details:
  =============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef struct tag{
    int grade;
    string name;
}student;

void swap(vector<student> &a, vector<student> &b){
//   以上函数中的 vector<student>就相当于swap 中的 T
    vector<student> temp = a;
    a = b;
    b = temp;
}
bool cmp_de(int left, int right){
    return left < right;
}

bool cmp_inc(int left, int right){
    return left > right;
}

//通过比较结构体里边的某一项，来实现对结构体的排序
//sort默认是递增的，也就是默认left 小于 right 
//如果条件不满足就递减了
bool cmp_stu(const student &left,const student &right){
        return (left.grade > right.grade);
}
void insert_sort(vector<student> &vec,bool (*cmp)(int, int)){
    int lindex,qindex;
    int num = vec.size();

    for(lindex = 0; lindex != num; ++ lindex){
        int key = vec[lindex].grade;
        for(qindex = lindex - 1; qindex >= 0; qindex --){
            //if(vec[qindex].grade > key){//采用最基本的比较方式
            if(!(cmp(vec[qindex].grade ,key))){
            //if(cmp(vec[qindex].grade ,key)){//
                break;
            }
            swap(vec[qindex],vec[qindex + 1]);
        }
        vec[qindex + 1].grade = key;
    }
}
void init_stu(vector<student> &vec,int num){
    int grade;
    string name;
    student temp;
    for(vector<student>::size_type ix = 0;
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

        temp.grade = grade;
        temp.name = name;
        vec.push_back(temp);
    }
}
void print_stu(const vector<student> &vec){
//void print_stu(vector<student> vec){
    //为了避免系统开销，这里应该采用引用的方式，加之容器的值不应该改变，将应该加上const
    cout << "姓 名 " << " 成绩  " << endl;
    for(vector<student>::const_iterator citer = vec.begin();
            citer != vec.end();
            ++ citer)
    {
        cout << (*citer).name << "   " << (*citer).grade << endl;
    }
}
void total_info(const vector<student> &vec, vector<student> &ret){
    student temp;
    for(vector<student>::const_iterator citer = vec.begin();
            citer != vec.end();
            ++ citer)
    {
        if((*citer).grade >= 60){
            temp.grade = (*citer).grade;
            temp.name = (*citer).name;

            ret.push_back((temp));
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
    cout << endl <<  "\033[1;31m 统计结果为：\033[0m" << endl;
    print_stu(ret); 

    cout << endl <<  "\033[1;36m*******************************英豪榜*************************\033[0m" << endl;
    //insert_sort(vec,cmp_de);
    //insert_sort(vec,cmp_inc);
    sort(vec.begin(),vec.end(),cmp_stu);//这里为一结构体,调用系统函数sort
    print_stu(vec);
    return 0;
}
