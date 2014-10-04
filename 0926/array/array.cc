/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: array.cc
  > Author: Donald
  > Created Time: 2014/09/27/ 11:38:46
  > details:
=============================================*/
#include "Array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;
Array::Array()
{
}

Array::Array(int num){
    size_ = num;
    ary_ = new int[size_] ;

    memset(ary_,0,size_ *(sizeof (int)));
}

Array::Array(const Array &ary){
    size_ = ary.size_;
    ary_ = new int[size_];
    memset(ary_,0,size_ *(sizeof (int)));

    for(size_t index = 0;index < size_ ;++ index){
        ary_[index] = ary.ary_[index];
    }
}
Array::~Array(){
 //   cout << "析构函数" << "size_ = " << size_ << *this<< endl;
    delete[] ary_;
}

int Array::operator[](int num) const{
    return ary_[num];
}

Array &Array::operator=(const Array &ary){
    size_ = ary.size_;
    ary_ = new int[size_];
    memset(ary_,0,size_ *(sizeof (int)));

    for(size_t index = 0;index < size_ ;++ index){
        ary_[index] = ary.ary_[index];
    }
}

Array &Array::operator=(int* ary){
    //sizeof(ary);不能用这种方式获取数组的长度,长度信息已经丢失。
    //为什么字符串可以获取长度信息？因为strlen的实现机制不一样，
    //是遍历字符串，通过判断字符不为'\0'来实现计数
    ary_ = new int[size_];

    memset(ary_,0,size_ *(sizeof (int)));

    for(size_t index = 0;index < size_;++ index){
        ary_[index] = ary[index];
    }

    return *this;
}

#if 0
Array &Array::operator+=(const Array &ary){
    size_t ta = size_;
    size_t tb = ary.size_;
    size_t num = ta + tb ;
    Array temp(num);
    temp.ary_ = new int[temp.size_];

    size_t index = 0;
    while(ta >0){
        temp.ary_[index]= ary_[index];
        ++ index;
        -- ta ;
    }
    while(tb > 0 ){
        temp.ary_[index] = ary.ary_[index - size_];
        ++ index;
        -- tb;
    }

  // cout << "temp " << temp << endl;

    delete[] ary_;
    ary_ = temp.ary_;//ary_指向的是temp.ary_，
    但是temp在离开该作用域后将会自动析构，所以这里不能用一个类来进行操作
    size_ = temp.size_;
    //cout << "this " << *this << endl;

    return *this;
}
#endif
Array &Array::operator+=(const Array &ary){
    size_t ta = size_;
    size_t tb = ary.size_;
    size_t num = ta + tb ;
    int *temp  = new int[num];

    size_t index = 0;
    while(ta >0){//有一个库函数memcpy（）可以实现这个功能
        temp[index]= ary_[index];
        ++ index;
        -- ta ;
    }
    while(tb > 0 ){
        temp[index] = ary.ary_[index - size_];
        ++ index;
        -- tb;
    }

    delete[] ary_;
    ary_ = temp;
    size_ = num;

    return *this;
}

#if 0
Array operator+(const Array &ary1,const Array &ary2){
    Array temp ;
        temp.ary_= new int[temp.size_];
    size_t ta = ary1.size_;
    size_t tb = ary2.size_;
    temp.size_ =  ta + tb;

    size_t index = 0;
    while(ta >0){
        temp.ary_[index]= ary1.ary_[index];
        ++ index;
        -- ta ;
    }
    while(tb > 0 ){
        temp.ary_[index] = ary2.ary_[index - ta];
        ++ index;
        -- tb;
    }
        
    return temp;
}
#endif
Array operator+(const Array &ary1,const Array &ary2){
    Array temp;
    temp = ary1;
    temp += ary1;
    return temp;
}

bool operator<(const Array &ary1,const Array &ary2){
    size_t ta = ary1.size_;
    size_t tb = ary2.size_;

    bool flag = true;
    size_t index = 0;
    while(ta !=0 && tb != 0){
        if(ary1.ary_[index]!= ary2.ary_[index]){
            index ++;
            flag = false;
            break;
        }
        -- ta ;
        -- tb;
    }

    return flag;

}
bool operator<=(const Array &ary1,const Array &ary2){
    size_t ta = ary1.size_;
    size_t tb = ary2.size_;

    bool flag = true;
    size_t index = 0;
    while(ta !=0 && tb != 0){
        if(ary1.ary_[index] > ary2.ary_[index]){
            ++ index ;
            flag = false;
            break;
        }
        -- ta ;
        -- tb;
    }

    return flag;

}
bool operator>(const Array &ary1,const Array &ary2){
    size_t ta = ary1.size_;
    size_t tb = ary2.size_;

    bool flag = true;
    size_t index = 0;
    while(ta !=0 && tb != 0){
        if(ary1.ary_[index] <= ary2.ary_[index]){
            ++ index;
            flag = false;
            break;
        }
        -- ta ;
        -- tb;
    }

    return flag;

}
bool operator>=(const Array &ary1,const Array &ary2){
    size_t ta = ary1.size_;
    size_t tb = ary2.size_;

    bool flag = true;
    size_t index = 0;
    while(ta !=0 && tb != 0){
        if(ary1.ary_[index] < ary2.ary_[index]){
            flag = false;
            ++ index;
            break;
        }
        -- ta ;
        -- tb;
    }

    return flag;

}
bool operator==(const Array &ary1,const Array &ary2){
    bool flag = true;

    size_t ta = ary1.size_;
    size_t tb = ary2.size_;
    if(ta != tb){
        flag = false;
    }
    size_t index = 0;
    while(ta !=0 && tb != 0 && flag == true){
        //if(ary1.ary_ ++ = ary2.ary_ ++){不能这么反访问
        if(ary1.ary_[index] = ary2.ary_[index]){
            ++ index ;
            flag = false;
            break;
        }
        -- ta ;
        -- tb;
    }

    return flag;

}
bool operator!=(const Array &ary1,const Array &ary2){
    bool flag = false;//默认为等，一下用于退翻番结论

    size_t ta = ary1.size_;
    size_t tb = ary2.size_;
    if(ta != tb){
        flag = true;
    }
    size_t index = 0;
    while(ta !=0 && tb != 0 && flag == false){
        if(ary1.ary_[index] = ary2.ary_[index]){
            flag = true;
            ++ index;
            break;
        }
        -- ta ;
        -- tb;
    }

    return flag;
}
