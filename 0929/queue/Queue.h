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
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

//这是list版本
template<class T>
struct Node{
    public :
        friend class Queue;
    private:
        T info_;
        Node<T> *next_;
};

template<typename T>
class Queue{
    typedef Node<T> *pNode;
    pNode head_;
    pNode tail_;
    size_t size_;
    
    public:
        Queue();
        ~Queue();
        void delQueue(T &delElem);
        void enQueue(const T &t);
        bool isEmpty() const;
        size_t getSize();
        void clear() const;
};

template<typename T>
Queue<T>::Queue()
    :head_(NULL),
    tail_(NULL),
    size_(0)
{    
}

template<typename T>
Queue<T>::~Queue()
{
}

template<typename T>
void Queue<T>::delQueue(T &delElem){
    if(!isEmpty()){
        throw runtime_error("empty");
    }    
    pNode temp = head_;
    delElem = temp->info_;

    head_ = temp->next_;
    delete temp;
    -- size_;
}

template<typename T>
void Queue<T>::enQueue(const T &dt){
    pNode pNew = new Node<T>;
    pNew->info_ = dt;
    pNew->next_ = NULL;

    if(!isEmpty()){
        head_ = tail_ = pNew;
    }else{
        tail_->next_ = pNew;
        tail_ = tail_->next_;
    }
    ++ size_;
}

template<typename T>
bool Queue<T>::isEmpty() const{
    return size_ == 0;
}

template<typename T>
void Queue<T>::clear() const{
    T temp;
    while(head_ != NULL){
        delQueue(temp);
    }
}
template<typename T>
size_t Queue<T>::getSize(){
    return size_;
}

#endif  /*__QUEUE_H_*/
