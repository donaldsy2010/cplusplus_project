#include<stdio.h>
typedef struct {
	int A[4][4];
	int m;
	int n;
}array;

void print(array a){
	int i,j;
	for(i=0;i<a.n;i++){
		for(j=0;j<a.m;j++){
			printf("%d ",a.A[i][j]);
		}
	printf("\n");
	}
}
int main(){
	int i,j;
	array B;
	B.m = 4;
	B.n = 3;
	int num = 0;
	for(i=0;i<B.n;i++){
                for(j=0;j<B.m;j++){
			B.A[i][j] = ++num;                    
		} 
        }
	print(B);
	return 0;
}


