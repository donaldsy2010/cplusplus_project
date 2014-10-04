/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: stack.cc
  > Author: Donald
  > Created Time: 2014/09/29/ 15:35:28
  > details:
=============================================*/
#if 0
#include "Stack.h"
using namespace std;
template<typename T> Stack<T>::Stack()
{
}

template<typename T> Stack<T>::Stack(const Stack &st)
{
    for(vector<T>::iterator it = st.begin(); it != st.end(); ++it){
        vec_.push_back(*it);
    }
}

template<typename T> Stack<T>::Stack(const T &st){
    vec_.push_back(st);
}

template<typename T> Stack::~Stack()
{
}

template<typename T> Stack<T> &Stack<T>::operator=(const Stack &st){
    for(vector<T>::iterator it = st.begin(); it != st.end(); ++it){
        vec_.push_back(*it);
    }
    return *this;
}

template<typename T> T Stack<T>top() const{
   if(vec_.empty()){
        throw std::out_of_range("out of range");
   }
    return vec_.back();
}

template<typename T> void Stack<T>push(T &temp){
    vec_.push_back(temp);
}

template<typename T> void Stack::pop() const{
   if(vec_.empty()){
        throw std::out_of_range("out of range");
   }
   vec_.pop_back();
}

template<typename T> bool Stack<T>::isEmpty() const{
    return vec_.empty();
}
#endif
