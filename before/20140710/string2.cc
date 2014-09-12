#include <iostream>
#include <string>
#include <vector>//cpp

using namespace std;//uss
int main(int argc, const char *argv[])
{
    string s = "Preservence";
   for(string::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<endl;
   } 
    return 0;
}
