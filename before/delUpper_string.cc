#include <iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
    string str = "Hello World.";
    cout<<str<<endl;
    cout<<str.size()<<endl;
    int count = 0;
    for(string::iterator it = str.begin();it != str.end();++it){
            if(isupper(*it)){
                        count++;
                        str.erase(it);
                        --it;
                    }
            cout<<*it;
        }
    cout<<str.size()<<endl;
    cout<<"共有大写字母："<<count<<"个"<<endl;
    cout<<endl;
}
