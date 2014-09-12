#include <iostream>
#include <string>
#include <vector>
#include<stdexcept>
using namespace std;
int main(int argc, const char *argv[])
{
    int i,j;
    cout<<"Please input two number";
    try{
        cin>>i>>j;
        if(i<j)
            throw exception();
       // cout<<i<<" "<<j<<endl;
    }catch(exception &e){
        cout<<i<<" < "<<j<<endl;
    }
    return 0;
}
