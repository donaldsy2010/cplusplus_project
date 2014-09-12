 #include<iostream>
using namespace std;
void swap(int *x,int *y);
int main(){
	int a,b;
	cout<<"Please input two number:";
	cin>>a>>b;
//	swap(&a,&b);
	swap(a,b);
	cout<<a<<"\t"<<b<<endl;
		
}
void swap(int *x,int *y){
	int *temp;
	temp = x;
	x = y;
	y = temp;
}
