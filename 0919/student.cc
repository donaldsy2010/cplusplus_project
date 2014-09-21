nclude<string>
#include<iostream>
using namespace std;
class Student //声明Student类
{
   public :
   Student(int n,string nam,char s ) //定义构造函数
   {
      num_=n;
      name_=nam;
      sex_=s;
      cout<<"Constructor called."<<endl; //输出有关信息
   }
   ~Student( ) //定义析构函数
   {
      cout<<"Destructor called. The num is "<<num<<"."<<endl;
   } //输出有关信息
   void display( ) //定义成员函数
   {
      cout<<"num: "<<num_<<endl;
      cout<<"name: "<<name_<<endl;
      cout<<"sex: "<<sex_<<endl<<endl;
   }
   private :
   int num_;
   string name_;
   char sex_;
};

int main( )
{
   Student stud1(10010,"Wang_li",'f'); //建立对象stud1
   stud1.display( ); //输出学生1的数据
   Student stud2(10011,"Zhang_fun",'m'); //定义对象stud2
   stud2.display( ); //输出学生2的数据
   return 0;
}
