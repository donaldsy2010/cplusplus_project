#include <iostream>
#include <string>
#include <vector>
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(int argc, const char *argv[])
{
    int i,j;
    cout<<"Enter:";
    cin>>i>>j;
    if(i<j)
        swap(i,j);
    cout<<"max = "<<i<<" min = "<<j<<endl;
    return 0;
}
