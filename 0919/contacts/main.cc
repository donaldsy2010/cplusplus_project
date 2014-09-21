/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: main.cc
  > Author: Donald
  > Created Time: 2014/09/19/ 23:58:36
  > details:
  =============================================*/
#include "contacts.h"
using namespace std;
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

    vector<Record> vec(num);
    //在输出时为什么会出现10行空白？==》以下采用了push_back的方法，而不是小标操作，so。。。
    for(vector<Record>::size_type ix = 0; ix != num; ++ ix){
        Record temp ;
        temp.setName( temp.creatName() );
        temp.setAddr( temp.creatAddr(addrVec) );
        temp.setPhone( temp.creatPhone() );

        vec[ix] = temp;
        //vec.push_back(temp);
    }

    Record record("donald","18613512343","shenzheng");
    vec.push_back(record.getRecord());
    Record record2("absde","18613312321","shenzheng");
    vec.push_back(record2.getRecord());
    Record record3("absde","18613312321","shenzheng");
    vec.push_back(record3.getRecord());
    Record record4("absde","18613312321","shenzheng");
    vec.push_back(record4.getRecord());

    cout << "after:" << endl;
    Record::printRecord(vec);
    Record::delByPhone("18613512343",vec);
    cout << "before:" << endl;
    Record::printRecord(vec);

    //    typedef vector<Record> VR;
    typedef Record VR;
    vector< VR > temp1;
    vector< VR > temp2;
    vector< VR > temp3;

#if 1
    cout << "find by name:" << endl;
    size_t count1  = (Record::findByName("donald",vec)).size();
    for (size_t i = 0; i < count1; i++) {
        temp1.push_back(((Record::findByName("donald",vec))[i]));
    }
    Record::printRecord(temp1);

    cout << "find by phone:" << endl;
    size_t count2  = (Record::findByPhone("18613312321",vec)).size();
    for (size_t i = 0; i < count2; i++) {
        temp2.push_back((Record::findByPhone("18613312321",vec)[i]));
    }
    Record::printRecord(temp2);

    cout << "find by addr:" << endl;
    size_t count3  = (Record::findByAddr("shenzheng",vec)).size();
    for (size_t i = 0; i < count3; i++) {
        temp3.push_back((Record::findByAddr("shenzheng",vec))[i]);
    }
    Record::printRecord(temp3);

#endif
    return 0;
}
