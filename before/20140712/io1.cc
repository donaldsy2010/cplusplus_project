#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    cout<<"good = "<<cin.good()<<endl;
    int num;
    while(cin >> num){
        cout<<num<<endl;
    }
    cout<<"fail = "<<cin.fail()<<endl;
    cout<<"bad = "<<cin.bad()<<endl;
    cout<<"good = "<<cin.good()<<endl;
    cout<<"eof = "<<cin.eof()<<endl;


    string s;
    cin>>s;
    cout<<s<<endl;
    return 0;
}
