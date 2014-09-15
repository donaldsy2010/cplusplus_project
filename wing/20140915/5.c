#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void (*) (int, char)
void print(int a, char c)
{
    printf("hello world\n");
}

typedef void(*p_func) (int, char);

int main(int argc, const char *argv[])
{
    //1.声明一个空函数指针，他可以指向参数为int char，返回值为void的函数
    void (*ptr) (int, char) = NULL;
    // 使该指针指向函数print
    ptr = &print;
    // 使用函数指针调用函数
    ptr(123, 34);


    p_func ptr2 = &print;
    ptr2(123, 34);

    return 0;
}
