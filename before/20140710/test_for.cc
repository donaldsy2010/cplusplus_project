#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<int> score;
    int temp;
    while(cin>>temp)
        score.push_back(temp);
    for(auto s:score)
        cout<<s<<" ";
    cout<<endl;
    return 0;
}
