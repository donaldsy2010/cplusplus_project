#ifndef __STRING_H_
#define __STRING_H_ 
#include <iostream>

class String{
    char* str_;
    friend std::ostream &operator<<(std::ostream &os, const String &s);

    public:
        String();
        String(const String &s);
        ~String();
        
        String(const char* s);
        String &operator+=(const String &s);
//        String &operator=();
};

//inline std::ostream &operator<<(const std::ostream &os, const String &s){
//输入输出流不能加const修饰符
inline std::ostream &operator<<( std::ostream &os, const String &s){
   return os << s.str_ ;
}
#endif  /*__STRING_H_*/
