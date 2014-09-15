#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void test(int a[10][6]))
void test(int (*a)[6])
{

}

int main(int argc, const char *argv[])
{
    int arr[10][6];
    test(arr);

    int arr2[9][7];
    test(arr);
    return 0;
}
