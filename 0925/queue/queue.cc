/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: queue.cc
  > Author: Donald
  > Created Time: 2014/09/25/ 20:27:49
  > details:
  =============================================*/
#include "queue.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
Queue::Queue()
    :head_(NULL),tail_(NULL),size_(0)
{
}
Queue::Queue(int value)
{
   pNode  pnew = new Node;
   pnew->next_ = NULL;
   pnew->value_ = value;
   head_ = pnew;
   tail_ = pnew;   
}
Queue::Queue(const Queue &queue)//拷贝函数
    :head_(NULL),
    tail_(NULL),
    size_(0)
{    
    clear();
    copyElement(queue);
}
#if 1
Queue &Queue::operator=(const Queue &queue){//赋值函数
    if(&queue == this){
        return *this;
    }
    
    clear();//释放掉以前占有的资源
    copyElement(queue);
    return *this;    
}
#endif
Queue::~Queue(){//析构函数
    clear();
}

void Queue::copyElement(const Queue &queue){
    pNode temp = queue.head_;

    while(temp != NULL){
        //ret.enQueue(queue.head_->value_);
        //++ret.size_;//要明白这里就是在对象中，所以就不用retle
        enQueue(temp->value_);//默认的*this
        temp = temp->next_;
    }
}
bool Queue::isEmpty(){

     return size_ == 0;

//    return head_ == NULL;
}
void Queue::enQueue(int val){
    pNode pnew = new Node;
    pnew->value_ = val;
    pnew->next_ = NULL;
    if(isEmpty()){
        head_ = tail_ = pnew;
    }else{
        tail_->next_ = pnew;
        tail_ = pnew;
    }
    ++ size_ ;
}
int Queue::delQueue(){
    if(!isEmpty()){
        int val = head_->value_;

        pNode temp = head_;
        head_ = head_->next_;
        -- size_ ;

        free(temp);//释放头结点
        return val;
    }else{
        return -1;
    }
}
bool Queue::clear(){
    while(!isEmpty()){
        delQueue();    
    }
    return true;
}
size_t Queue::getSize(){
    return size_;
}

