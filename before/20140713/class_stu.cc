#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student{
    private:
        string name_;
        int age_;
        int score_;

    public:
        void setName(string name){
            name_ = name;
        }
        string getName(){
            return name_;
        }

        void setAge(int age){
            age_ = age;
        }
        int getAge(){
            return age_;
        }

        void setScore(int score){
            score_ = score;
        }
        int getScore(){
            return score_;
        }
        void print(ostream &os){
            os<<name_<<" "<<age_<<" "<<score_<<" "<<endl;
        }
        
};
int main(int argc, const char *argv[])
{
    Student stu;
    stu.setName("donald");
    stu.setAge(12);
    stu.setScore(100);

    cout<<stu.getName()<<endl;
    cout<<stu.getAge()<<endl;
    cout<<stu.getScore()<<endl;


    stu.setName("su");
    stu.setAge(120);
    stu.setScore(400);
    stu.print(cout);
    return 0;
}
