/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: Queue.h
  > Author: Donald
  > Created Time: 2014/09/19/ 15:09:38
  > details:本程序一点都不规范，改进！！！
=============================================*/
#ifndef __MY_QUEUE_
#define __MY_QUEUE_
#include <iostream>
#include <string>
#include <vector>
#include <cstdio> 
#include <cstdlib>
#include <ctime>
#include <assert.h>
using namespace std;
struct Node{
    int value_;
    struct Node *next;
};
class Queue{
    public:
        int count;
        Node *head, *tail;
    public:
        Queue(){//构造函数
            head = tail = NULL;
            count = 0;
            cout << "construct..." << endl;
        }

        int EnQueue(int value){
            Node *pnew = new Node;
            pnew -> value_ = value;
            pnew ->next = NULL;

            if(isEmpty()){
                head = tail = pnew;
            }else{
                tail ->next = pnew;
                tail = pnew; 
            }
            ++ count;
            return value;
        }
        int DeQueue(){
           if(isEmpty()){
                fprintf(stderr, "Queue is empty\n");
                assert(isEmpty() == false);
           }else{
                int value = head ->value_;
                Node *temp = head;
                head = temp ->next;
                delete temp;//因为之前是通过new来申请的空间

                -- count;
                return value;
           } 
        }

        bool isEmpty(){
            return count == 0;
        }
        int size(){
            return count;
        }
        void clear(){
            while(!isEmpty()){
                DeQueue();
            }
        }

        ~Queue(){
            cout << "destruct" << endl;
            clear();
            cout << "destruct" << endl;
        }

};
#endif
