#include <iostream>
#include <string>
#include <vector>
#include<fstream>

using namespace std;
int main(int argc, const char *argv[])
{   
     ifstream is;
    ofstream os;    
   // is("in.txt");
    
    os.open("out.txt");
    is.open("in.txt");
    string word;
//    vector<string> vec;

//    while(os>word){
  //      vec.push_back(word);
  //  }
    //到了这里就不知道该如何进行了
   while(getline(is,word))
        os<<word<<endl;
    is.close();

    return 0;
}
