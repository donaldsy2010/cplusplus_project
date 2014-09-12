#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Person{
    int _id;
    string _name;
    int _age;

    void _print(std::ostream &os){
        os<<"id:"<<_id<<endl
           << "name:"<<_name<<endl
           <<"age:"<<_age<<endl;
    }
};

int main(int argc, const char *argv[])
{
    vector<Person>  per;
    cout<<endl<<"Please input id,name,age:";
//这里和string不同，所以以下语句错误。
    while(cin>>per)
       // per._id>>per._name>>per._age;
        //push_back(per._id);

         per._print(cout);
     cout<<endl;
    return 0;
}
