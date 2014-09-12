#include <iostream>
#include <string>
#include <vector>
#include<cstdlib>
using namespace std;
#define SWAP(a,b){\
    int temp(*a);\
    *a = *b;\
    *b = temp;\
}

int main(int argc, const char *argv[])
{
    int a = rand()%100;
    int b = rand()%100;

    cout<<"a = "<<a<<"b = "<<b<<endl;
    SWAP(&a,&b);
    cout<<"a = "<<a<<"b = "<<b<<endl;
    return 0;
}
