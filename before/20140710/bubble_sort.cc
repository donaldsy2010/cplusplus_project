#include <iostream>
#include <string>
#include <vector>
#include<cstdlib>
using namespace std;
void init(vector<int> &vec){
   // srand(1000);
    int n = 10;
    int temp;
    cout<<"begin"<<endl;
    while(n--){
        temp = rand()%100;
        vec.push_back(temp);
        cout<<temp<<" ";
    }
 cout<<endl;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool cmp(int &a,int &b){
    return a>b;
}
void bubble_sort(vector<int> &vec){
    vector<int>::size_type len = vec.size();
    for(size_t i=0;i<vec.size()-1;i++)
        for(size_t j=0;j<vec.size()-1-i;j++)
            if(cmp(vec[j],vec[j+1]))
                    swap(vec[j],vec[j+1]);
}
void print(vector<int> &vec){
    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}
int main(int argc, const char *argv[])
{
    vector<int> bubb;
    init(bubb);
    bubble_sort(bubb);
    print(bubb);
    return 0;
}
