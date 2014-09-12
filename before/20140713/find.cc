#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using namespace std;

void find(string &str){
    ifstream is;
    ofstream os;
    
    os.open("out.txt");
       // cout<<str<<ebdl;
   
   string word;
   cout<<"Please input the string:"<<endl;
   cin>>word;
    size_t loc = str.find(word,0);
    if(loc == string::npos)
        cout<<"NOt exist"<<endl;
    else
        cout<<str;
    
}
int main(int argc, const char *argv[])
{
    string str;
    find(str);
    
    return 0;
}
