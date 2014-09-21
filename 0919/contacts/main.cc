/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: main.cc
  > Author: Donald
  > Created Time: 2014/09/19/ 23:58:36
  > details:
=============================================*/
#include "contacts.h"

int main(int argc, const char *argv[])
{
    srand(time(NULL));
    int num = 10;
    if(argc == 2){
        num = atoi(argv[1]);
    }

    vector<string> addrVec;
    addrVec.push_back("shenzheng");
    addrVec.push_back("hangzhou");
    addrVec.push_back("chengdu");
    addrVec.push_back("bazhong");
    addrVec.push_back("beijing");
    addrVec.push_back("tianjing");
    addrVec.push_back("shagnhai");

    vector<conts> vec(num);
    Contacts newRecord;
    for(vector<conts>::size_type ix = 0; ix != num; ++ ix){
        conts temp ;
        temp.name_ = creat_name();
        temp.addr_ = creat_addr(addrVec);
        temp.phone_ = creat_phone();

        newRecord.set(temp.phone_,temp.name_, temp.addr_);//可以被覆盖
        vec.push_back(temp);

        //cout << temp.name_ << "   " << temp.addr_ 
          //  <<"    " << "    "<< temp.phone_ <<endl;
        printf("\033[1;36m%13s   %-15s %-15s\n\033[0;m",temp.name_.c_str(), temp.addr_.c_str(),temp.phone_.c_str());
    }
    
    for(vector<conts>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << (*it).name_ << "   " << (*it).addr_ 
            <<"    " << "    "<< (*it).phone_ <<endl;
    }
    cout << vec[1].name_ << "   " << vec[1].addr_
         <<"    " << "    "<< vec[1].phone_ <<endl;
                    return 0;
                    }
