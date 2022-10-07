/*
	当N很小的时候，两种方法都可以运行
	但是当N达到100000的时候，递归方法直接不运行了，这种方法空间使用率很大 
*/
#include<stdio.h> 
void printN_for(int N);
void printN_recursion(int N);

int main(){
	int N;
	scanf("%d", &N); 
	//printN_for(N); 
	printN_recursion(N);
}

void printN_for(int N){
	int i;
	for(i=1; i<=N; i++){
		printf("%d\n", i);
	}
}

void printN_recursion(int N){
	if(N){
		printN_recursion(N-1);//print 1 to N-1, the last number to print is N 
		printf("%d\n", N);
	}

}
