#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>

void Swap(T &a,T&b){
    T temp(a);
    a = b;
    b = temp;
}

int main(int argc, const char *argv[])
{
    cout<<"Enter:";
    int a(8),b(9);
    cin>>a>>b;
   //:w
   int *i=&a,*j=&b;
//    &i = *a;
  //  &j = *b;
    cout<<"before swap: a = "<<i<<" b = "<<j<<endl;
    Swap<int>(i,j);
    cout<<"after swap: a = "<<i<<" b = "<<j<<endl;
    return 0;
}
