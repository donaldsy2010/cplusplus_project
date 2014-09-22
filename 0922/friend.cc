/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: friend.cc
  > Author: Donald
  > Created Time: 2014/09/22/ 10:23:16
  > details:
=============================================*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Test{
    int x_;
    int y_;
    public:
        friend class Other;
        void print() const{
            cout << x_ <<" " << y_ << endl;
        }
};

struct Other{
    public :
        void print(const Test &x) const{
            cout << x.x_ <<" " << x.y_ << endl;
        }
};
int main(int argc, const char *argv[])
{
    Test t;
    t.print();
    Other oth;
    oth.print(t);
    return 0;
}
