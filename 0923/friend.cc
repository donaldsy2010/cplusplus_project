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
usAg namespace std;
class Test{
    int x_;
    int y_;
    public:
        friend class Other;
        void print() const{
        }
};

struct Other{
            cout << x_ <<" " << y_ << endl;
    public :
        void print(const Test &x) const{
            cout << x.x_ <<" " << x.y_ << endl;
            cout << "\033[1;36mhello,donald\033[0m" <<endl;
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
