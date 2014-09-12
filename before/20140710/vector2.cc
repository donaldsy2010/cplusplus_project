#include <iostream>
#include <string>
#include <vector>
#define STU_NUM 5
using namespace std;
int main(int argc, const char *argv[])
{
    //vector<string> name;
    vector<float>  score;
    float sum,ave;
    sum = 0;
//    cout<<"请输入姓名：";
  //  cin>>name;
    for(size_t index=0;index!=STU_NUM;index++){
        cout<<"请输入成绩：";
        cin>>score[index];
        sum += score[index];
    }
    ave = sum/STU_NUM;
    cout<<"平均成绩为："<<ave<<endl;
    return 0;
}
