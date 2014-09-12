#include"Queue.h"
#include<cstdlib>
#include<cassert>
using namespace std;

int main(int argc, const char *argv[])
{
    Queue Q;
    srand(9999);
    Q.EnQueue(rand()%100);
    cout<<Q.cout<<" "<<rand()%100<<endl;
    Q.EnQueue(rand()%100);
    cout<<Q.cout;
    Q.EnQueue(rand()%100);
    Q.EnQueue(rand()%100);
    Q.EnQueue(rand()%100);
    Q.EnQueue(rand()%100);
    
    cout<<Q.cout;
   cout<< Q.DeQueue()<<endl;
   cout<< Q.DeQueue()<<endl;
   cout<< Q.DeQueue()<<endl;
   cout<< Q.DeQueue()<<endl;
   cout<< Q.DeQueue()<<endl;
   cout<< Q.DeQueue()<<endl;

   assert(Q.IsEmpty() == true);
    return 0;
}
