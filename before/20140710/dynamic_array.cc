#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    int** ptr = new int*[4];
    int num = 0;
    for(int i=0;i!=3;i++){
        ptr[i] = new int[3];
        for(int j=0;j!=4;j++){
            ptr[i][j] = ++num;
            cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //释放:
    for(int i=0;i!=3;i++)
        delete[] ptr[i];
    delete[] ptr;

    return 0;
}
