#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<stdexcept>
using namespace std;

ifstream &open_file(ifstream &infile, const string &filename){
    infile.close();
    infile.clear();
    infile.open(filename.c_str());
    return infile;
}

class Query{
    public:
    vector<string> words;

    void readFile(const string &name){
        ifstream infile;
        if(!open_file(infile,name))
                throw std::runtime_error("open the file failed");
        words.clear();
        string word;
        while(infile>>word)
            words.push_back(word);
        infile.close();
        infile.clear();
    }

    vector<string>  queryWord(const string &word){
        vector<string> result;
        for(vector<string>::iterator it = words.begin(); it != words.end(); ++it){
            size_t pos = it->find(word);
            if(pos != string::npos)
                result.push_back(*it);
       }
        return result;
    }
};

int main(int argc, const char *argv[])
{
    string filename = "in.txt";
    Query Q;
    Q.readFile(filename);
    
    string word;
    while(cin>>word){

        vector<string> res = Q.queryWord(word);
        cout<<"size = "<<res.size()<<endl;
        for(vector<string>::iterator it  = res.begin();it!=res.end();it++)
            cout<<*it<<endl;
    }
    return 0;
}
