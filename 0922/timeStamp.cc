/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: timeStamp.cc
  > Author: Donald
  > Created Time: 2014/09/22/ 22:56:17
  > details:
=============================================*/
#include "../0919/date/date.h"
using namespace std;
int main(int argc, const char *argv[])
{//实现time_t()
     Date now = Date::today();
     Date begin(1970,1,1);
    int  nowSec = now.getSec() + now.getMin()*60 + (now.getHour() - 8)*3600;
    //由于时区的问题，这里需要减去8个小时

     int dis;
     dis = now.diffDate(now,begin);

     int64_t secs = dis*24*3600 + nowSec;
   
     cout << secs << endl;
     cout << time(NULL) << endl;
    //时区问题
    return 0;
}
//运行时需运行的语句：  bin/timestamp  ../0919/date/date.cc  timeStamp.cc 

