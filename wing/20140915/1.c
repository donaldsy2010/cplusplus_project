#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void test(char *s)
{
    s = (char*)malloc(100);
}


int main(int argc, const char *argv[])
{
    char *str = NULL;
    test(str);


    return 0;
}
