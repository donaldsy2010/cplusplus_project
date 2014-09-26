/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: queue.h
  > Author: Donald
  > Created Time: 2014/09/25/ 20:02:16
  > details:
=============================================*/
#ifndef __QUEUE_H_
#define __QUEUE_H_ 
 #include <cstdio> 
 #include <cstdlib>
struct Node{
    public :
        friend class Queue;
    private:
    int value_;
    Node *next_;
};
typedef  Node *pNode;
class Queue{
    pNode head_;
    pNode tail_;
    size_t size_;
    
    void copyElement(const Queue &queue);
    public:
        Queue();
        Queue(int value);
        Queue(const Queue &queue);
        Queue &operator=(const Queue &queue);
        ~Queue();

        bool isEmpty();
        void enQueue(int val);
        int delQueue();
        bool clear();
        size_t getSize();
};
#endif  /*__QUEUE_H_*/
