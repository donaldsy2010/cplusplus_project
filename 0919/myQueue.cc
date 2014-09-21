/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: myQueue.cc
  > Author: Donald
  > Created Time: 2014/09/19/ 15:43:17
  > details:
=============================================*/
#include "Queue.h"

int main(int argc, const char *argv[])
{
    int num = 10;
    if(argc == 2){
        num = atoi(argv[1]);
    }
   srand(time(NULL)) ;

   Queue my_queue;
   
   for(int index = 0; index < num; index ++){
        int temp = rand()%100;
        cout << temp << " ";
        my_queue.EnQueue(temp);
   }

    cout << endl << "该队列的大小 ：" << my_queue.size() << endl;
    cout << "该队列非空？" << my_queue.isEmpty() << endl;
    cout << my_queue.DeQueue() << endl;
    cout << my_queue.DeQueue() << endl;
    cout << my_queue.DeQueue() << endl;
    cout << my_queue.DeQueue() << endl;
    
    my_queue.clear();//由于这里已经释放???
    //其实是因为程序中使用了exit函数，使当前进程退出
    cout << my_queue.DeQueue() << endl;
    cout << "hello" << endl;
    return 0;
}
