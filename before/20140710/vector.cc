#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, const char *argv[])
{
    vector<string> str;
    str.push_back("Hello");
    str.push_back(",");
    str.push_back("world");
    str.pop_back();
    str.push_back("你好");
    for(size_t index = 0;index != str.size();index++){
        cout<<str[index]    ;
        cout<<" ";        
     }
    
    cout<<endl<<"size = "<<str.size()<<endl;
    return 0;
}

   
