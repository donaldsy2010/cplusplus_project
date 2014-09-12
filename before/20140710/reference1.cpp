#include<iostream>
#include<string>
using namespace std;

void swap_value(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main(int argc, const char *argv[])
{
    int a,b;
    cout<<"please input two number：";
    cin>>a>>b;
    swap_value(a,b);
    cout<<a<<endl<<b<<endl;
    return 0;
}
