#include <iostream>
#include <string>
#include <vector>
#include<cctype>
#include <cstdlib>
#include<iterator>
#include<cctype>

using namespace std;
void trans_string(string &word) ;
int main(int argc, const char *argv[])
{
    string str;
    while( cin>>str){
        trans_string(str);
//        cout<<str<<endl;    
    }
    return 0;
}
void trans_string(string &str){
    for(string::iterator it=str.begin();it!=str.end();it++){
        if(islower(*it)){
            *it = toupper(*it);
        }else if(isupper(*it)){
            *it = tolower(*it);
        }
        cout<<*it<<" ";
    }        
    cout<<endl;
}

