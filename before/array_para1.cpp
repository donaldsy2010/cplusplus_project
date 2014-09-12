#include<stdio.h>
#define N 3
#define M 4
void array(int A[3][M],int hang){
	int i,j;
	for(i=0;i!=3;i++){
		for(j=0;j!=M;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int A[3][M] = {1,2,2,1,23,123,3,2,2,3,4,5};
	array(A,3);
	return 0;
	
}

