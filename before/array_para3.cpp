#include<stdio.h>
#include<stdlib.h>
int main(){
//	int *ptr = (int *)malloc(9*sizeof(int));
//	free(ptr);
//jiangli 
	int **arr = (int **)malloc(3*sizeof(int));
	int i;
	for(i=0;i<3;i++){
		arr[i] = (int*)malloc(4*sizeof(int));		
	}
	int num = 0;
	for(i=0;i!=3;i++)
		for(int j=0;j!=4;j++){
			arr[i][j] = ++num;
		}
	for(i=0;i!=3;i++){
                for(int j=0;j!=4;j++){
                        printf("%d ",arr[i][j]);
                }
	printf("\n");
	}
	
	for(i=0;i!=3;i++)
		free(arr[i]);

return 0;
}
