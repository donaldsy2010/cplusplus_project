#include <iostream>
#include <string>
#include <vector>//cpp

using namespace std;//uss
int main(int argc, const char *argv[])
{
    string s = "Preservence";
/*string::size_type*/size_t index = s.find("s",0);
    if(index != string::npos){
        cout<<"not find!!!"<<endl;
    }else{
        cout<<index<<s[index]<<endl;
    }
    return 0;
}
