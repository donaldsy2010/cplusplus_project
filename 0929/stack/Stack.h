/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: Stack.h
  > Author: Donald
  > Created Time: 2014/09/29/ 14:45:24
  > details:
=============================================*/
#ifndef __STACK_H_
#define __STACK_H_ 

#include <vector>
#include <stdexcept>
using std::vector;
template <typename T>
class Stack{
    std::vector<T> vec_;

    public:
        Stack();
        Stack(const Stack<T> &st);
        Stack(const T &st);
        ~Stack();

        Stack<T> &operator=(const std::vector<T> &st);
        T top() const;
        void push(const T &temp);
        void pop();//要对栈进行修改，左移不能为const
        bool isEmpty() const;
};

//特例化Stack
template<> 
class Stack<const char*>{
    Stack<std::string> real_stack;

    public:
    void pop(){ real_stack.pop(); }
    bool isEmpty() const{ return real_stack.isEmpty(); }
    const std::string  top() const{ return real_stack.top(); }
    void push(const char* str);

};

//template<>//在特例化外部成员时不能加该标记。
void Stack<const char*>::push(const char* str){
    return real_stack.push(str);
}

template<typename T> T Stack<T>::top() const{
    if(vec_.empty()){
        throw std::out_of_range("out of range");
    }
    return vec_.back();
}

template<typename T> void Stack<T>::push(const T &temp){
    vec_.push_back(temp);
}

template<typename T> void Stack<T>::pop(){
    if(vec_.empty()){
        throw std::out_of_range("out of range");
    }
    vec_.pop_back();
}

template<typename T> bool Stack<T>::isEmpty() const{
    return vec_.empty();
}

#if 1
template<typename T> Stack<T>::Stack()
{
}

template<typename T> Stack<T>::Stack(const Stack<T> &st)
{
    Stack<T> temp ;//由于不能改变st的值，就找一临时变量

    vector<T>::iterator it;
    for( it = st.vec_.begin(); it != st.vec_.end(); ++it){
        vec_.push_back(*it);
    }
}

template<typename T> Stack<T>::Stack(const T &st){
    vec_.push_back(st);
}

template<typename T> Stack::~Stack()
{
}
template<typename T> Stack<T> &Stack<T>::operator=(const std::vector<T> &st){

    for(vector<T>::iterator it = st.begin(); it != st.end(); ++it){
        vec_.push_back(*it);
    }
    return *this;
}
#endif

#endif  /*__STACK_H_*/
