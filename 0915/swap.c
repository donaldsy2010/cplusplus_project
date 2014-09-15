/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: swap.c
  > Author: Donald
  > Created Time: 2014/09/15/ 11:03:29
  > details:
=============================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

swap(int *left, int *right){
    int temp = *left;
    *left = *right;
    *right = temp;
}

int main(int argc, const char *argv[])
{
    int a, b;
    if(argc == 1){
     a = 10;
     b = 20;
    }else if(argc == 3){
        a = atoi(argv[1]);
        b = atoi(argv[2]);    
    }
    printf("after :");
    printf("a = %d, b = %d\n",a,b);
    swap(&a, &b);
    printf("before:");
    printf("a = %d, b = %d\n",a,b);
    return 0;
}
