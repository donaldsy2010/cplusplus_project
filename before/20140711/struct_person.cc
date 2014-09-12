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
    //vector<Person>  per;
    Person  per;
    cout<<endl<<"Please input id,name,age:";
    cin>>per._id>>per._name>>per._age;
     per._print(cout);
     cout<<endl;

     Person *pe = new Person;
     cout<<"Input another:";
     cin>>pe->_age>>pe->_name>>pe->_age;
     pe->_print(cout);
     cout<<endl;

    return 0;
}
