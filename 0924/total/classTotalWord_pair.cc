/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: classTotalWord_pair.cc
  > Author: Donald
  > Created Time: 2014/09/24/ 20:35:57
  > details:
=============================================*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;
//typedef map<string,int> Map;
//typedef set<string> Set;
typedef pair<string,int> Ret;
class Total{
    public:
        void readFileToMap( ifstream &in) ;
        void readFileToSet(ifstream &in) ;

        void find();
        void printSort();
        void saveToVec();
        
        static bool cmp(const Ret &left,const Ret &right );
        static void erasePunct(string &word);
    private:
        map<string,int> mymap_;
        set<string> myset_;
        vector< Ret> vec_;
};
int main(int argc, const char *argv[])
{
    if(argc == 1){
        fprintf(stderr, "please use %s filename frenqfile!\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    ifstream src(argv[1]);
    ifstream frenq(argv[2]);

    if(src == NULL || frenq == NULL){
        perror("open file");
        exit(EXIT_FAILURE);
    }

    Total total;
    total.readFileToMap(src);
    total.readFileToSet(frenq);
   // total.find();
    
    total.saveToVec();
    total.printSort();
    return 0;
}

void Total::readFileToMap( ifstream &in) {
    string word;
    while(in >> word){
        erasePunct(word);
        mymap_[word]++;
    }
}
void Total::readFileToSet(ifstream &in) {
    string word;
    while(in >> word){
        myset_.insert(word);
    }
}
void Total::erasePunct(string &word){
    string::iterator it = word.begin();
    while(it != word.end()){
        if(ispunct(*it)){
            it = word.erase(it);
        }else{
            ++ it;
        }
    }


}
void Total::find(){
    for(const pair<string,int> &p:mymap_){
        set<string>::const_iterator it;
        for( it = myset_.begin();
                it != myset_.end();
                ++ it)
        {
            if(p.first == *it){
                break;
            }
        }
        if(it == myset_.end()){
            cout << p.first << " : " << p.second << endl;
        }
    }

}

void Total::saveToVec(){
    for(const pair<string,int> &p:mymap_){
        Ret temp;
        set<string>::const_iterator it;
        for( it = myset_.begin();
                it != myset_.end();
                ++ it)
        {
            if(p.first == *it){
                break;
            }
        }
        if(it == myset_.end()){
            temp.first =  p.first;//string
            temp.second =  p.second ;
            vec_.push_back(temp);
        }
    }
}
void Total::printSort(){
    //sort(vec_.begin(),vec_.end(),greater<int>());
    sort(vec_.begin(),vec_.end(),cmp);
    for(vector<Ret>::iterator it = vec_.begin(); it != vec_.end(); ++it){
        cout << (*it).first << " : " << (*it).second << endl;    
    }
}
 bool Total::cmp(const Ret &left,const Ret &right ){
    return left.second < right.second;//这里就能实现map的另一中形式
 }
