/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: throw.cc
  > Author: Donald
  > Created Time: 2014/09/17/ 20:04:23
  > details:
  =============================================*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
int main(int argc, const char *argv[])
{
    int a, b;
    char choice ;
    while( cout << "please input two number : " << endl , cin >> a >> b){
    
         try{
            if(b == 0){
                throw runtime_error("除数不能为零");
            }
            double ret = static_cast<double>(a) / b;
            cout << "\033[1;36mret is " << ret << "\033[0m" << endl;
        }catch(runtime_error err){
            cout << "异常信息 : " << err.what() << "continue ？y/n" << endl;
            //while( (ch = cin  >> choice ) != 'y' || ch != 'n');
            while( cin  >> choice ){
                if(choice == 'y' || choice == 'n'){
                    break;
                }else{
                    continue;
                }            
            }

        }catch(exception e){
            cout <<e.what() << endl;
            break;
        }
         if(choice == 'y'){
             continue;              
         }else if(choice == 'n'){
             break;
         }

    }
    cout << "程序运行结束" << endl;
    return 0;
}
