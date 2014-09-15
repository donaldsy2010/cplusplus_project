#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}


int main(int argc, const char *argv[])
{
    int a = 10;
    int b = 9;
    swap(a, b);
    return 0;
}
