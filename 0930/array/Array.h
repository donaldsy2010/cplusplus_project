/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: Array.h
  > Author: Donald
  > Created Time: 2014/09/30/ 11:21:01
  > details:
=============================================*/
#ifndef __ARRAY_H_
#define __ARRAY_H_ 
#include <stddef.h>
template<typename T, size_t MAXSIZE>
class Array{
    T elem_[MAXSIZE];
    public:
        typedef T value_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef T *iterator;
        typedef const T *const_iterator;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

        iterator begin(){
            return elem_;
        }
        const_iterator begin() const{
            return elem_;
        }
        iterator end(){
            return elem_ + MAXSIZE;
        }
        const_iterator end() const{
            return elem_ + MAXSIZE;
        }

        reference operator[](size_t index){
            return elem_[index];
        }
        const_reference operator[](size_t index) const{
            return elem_[index];
        }

        size_type size()const{
            return MAXSIZE;
        }
};

#endif  /*__ARRAY_H_*/
