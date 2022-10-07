/*
1.	%6.2e 6代表最小输出宽度为6， 也就是实际位数多于6的时候，按照实际位数输出，小于6的时候用0补齐
	.2 代表小数位的精度 
	”e"是格式字符，代表以指数输出，输出以大写E表示
	
2.	MAXN = 10程序调用的时间为0，所以我们可以加入for循环，让程序多跑几次
  	之后再测算单次时间的时候除以这个值就可以 
*/

#include <stdio.h>
#include <time.h>
#include <math.h> 



clock_t start,stop; // clock_t 是clock()函数返回的数据类型
double duration;  //secondes
#define MAXN 10
#define times 10000

//要测试的是0-9的一共10个多项式 

double f1(int n, double a[], double x);
double f2(int n, double a[], double x);

int main(){
	
	double a[MAXN]; //存储多项式的系数 
	for(int i = 0; i<MAXN; i++){
		a[i] = (double) i; //由for循环给每一个系数赋值 
	} 
	
	start = clock();
	for(int i = 0; i<times; i++) {
		f1(MAXN-1, a, 1.1);
	}
	stop = clock();
	duration = (double)(stop-start)/CLK_TCK/times; //一个常数，机器时钟每秒所走的时钟打点数 
	printf("ticks = %f\n", (double)(stop-start)); 
	printf("duration1 = %6.2e\n", duration);
	
	start = clock();
	for(int i = 0; i<times; i++) {
		f2(MAXN-1, a, 1.1);
	}
	stop = clock();
	duration = (double)(stop-start)/CLK_TCK/times; //一个常数，机器时钟每秒所走的时钟打点数 
	printf("ticks = %f\n", (double)(stop-start)); 
	printf("duration2 = %6.2e\n", duration);

} 

double f1(int n, double a[], double x) {
	int i;
	double p = a[0];
	for(i=1; i<=n; i++){
		p+= a[i]*pow(x,i);
	}
	return p;
}


double f2(int n, double a[], double x) {
	int i;
	double p =a[n];
	for(i=n-1; i>=0; i--){
		p = a[i]  + x*p;
	}
	return p;
}
