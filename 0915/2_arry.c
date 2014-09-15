/*===========================================
  > Copyright (C)2014All rights reserved
  > File Name: 2_arry.c
  > Author: Donald
  > Created Time: 2014/09/15/ 15:09:38
  > details:
=============================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main(int argc, const char *argv[])
{
    srand(time(NULL));
    int **a = (int **)calloc(5,sizeof(int*));
    int index ,j;
    for(index = 0;index != 5;index ++){
        a[index] = (int*)calloc(3,sizeof(int));
        for(j = 0; j != 3;j ++){
            a[index][j] = rand()%100;
            printf("%4d",a[index][j]);        
        }
        printf("\n");
    }

    for(index = 0;index != 5;index ++){
        free(a[index]);
    }
    free(a);
    return 0;
}
