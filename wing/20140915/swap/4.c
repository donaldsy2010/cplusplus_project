#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int T;

void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}
