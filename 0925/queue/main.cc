/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: main.cc
  > Author: Donald
  > Created Time: 2014/09/25/ 21:08:45
  > details:
=============================================*/
#include "queue.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
    srand(time(NULL));

    Queue queue;

    queue.enQueue(rand()%101);
    queue.enQueue(rand()%101);
    queue.enQueue(rand()%101);
    queue.enQueue(rand()%101);
    queue.enQueue(rand()%101);
    queue.enQueue(rand()%101);
    queue.enQueue(rand()%101);

    cout  << "queue : " << queue.getSize() << endl;       

    Queue que(queue);
    Queue the = queue;
    cout  << "que : " << que.getSize() << endl;       

    cout << "queue : " ;
    while(!queue.isEmpty()){
        cout << queue.delQueue() << " ";
    }

    cout << endl << "que : " << endl;
    while(!que.isEmpty()){
        cout << que.delQueue() << " ";
    }
    cout << endl;

    cout << endl << "the : " << endl;
    while(!the.isEmpty()){
        cout << the.delQueue() << " ";
    }
    cout << endl;

    return 0;
}
