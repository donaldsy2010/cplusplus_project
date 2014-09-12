#include <iostream>
#include <string>
#include <vector>//cpp

using namespace std;//uss
int main(int argc, const char *argv[])
{
    string s = "Preservence";
    char c;
    while(cin>>c){
        size_t index = s.find(c);
        if(index == string::npos){
            cout<<"not find!!!"<<endl;
        }else{
            cout<<index+1<<" "<<s[index]<<endl;
        }
    }
    return 0;
}
