#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int a[5][3];
//a[1][2]

int main(int argc, const char *argv[])
{

    int **a = (int **)malloc(sizeof(int *) * 5);
    int i;
    for(i = 0; i < 5; ++i)
    {
        a[i] = (int *)malloc(sizeof(int) * 3);
    }
    return 0;
}
