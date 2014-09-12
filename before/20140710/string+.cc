#include<iostream>
#include<string>
using namespace std;
int main(int argc, const char *argv[])
{
    string s1,s2,s;
    cout<<"Please input the string1:";
    cin>>s1;
    cout<<"Please input the string2:";
    cin>>s2;

    s = s2 + s1;
    cout<<s<<endl;

    string str;
    str = s1 +","+ s2;
    cout<<str<<endl;
    return 0;
}
