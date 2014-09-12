#include<iostream>
#include<string>
using namespace std;

int main(int argc, const char *argv[])
{
    int i(10);
    int &j = i;
    j = 8;
    cout << i<<endl;
    return 0;
}
