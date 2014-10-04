/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: main.cc
  > Author: Donald
  > Created Time: 2014/09/25/ 21:08:45
  > details:
=============================================*/
#include "Queue.h"
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

    Queue<int> queue;

    queue.enQueue(rand()%101);
    queue.enQueue(rand()%101);
    queue.enQueue(rand()%101);
    queue.enQueue(rand()%101);
    queue.enQueue(rand()%101);
    queue.enQueue(rand()%101);
    queue.enQueue(rand()%101);

    cout  << "queue : " << queue.getSize() << endl;       

    Queue<int> que(queue);
    Queue<int> the = queue;
    cout  << "que : " << que.getSize() << endl;       

    cout << "queue : " ;
    while(!queue.isEmpty()){
        int temp ;
        queue.delQueue(temp);
        cout << temp  << " ";
    }

    cout << endl << "que : " << endl;
    while(!que.isEmpty()){
        int temp ;
        que.delQueue(temp);
        cout << temp  << " ";
    }
    cout << endl;

    cout << endl << "the : " << endl;
    while(!the.isEmpty()){
        int temp ;
        the.delQueue(temp);
        cout << temp  << " ";
    }
    cout << endl;

    return 0;
}
