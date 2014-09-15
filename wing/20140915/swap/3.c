#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int *a, *b
// int *
void swap(int **a, int **b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
}
