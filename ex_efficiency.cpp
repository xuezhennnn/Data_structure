/*
1.	%6.2e 6������С������Ϊ6�� Ҳ����ʵ��λ������6��ʱ�򣬰���ʵ��λ�������С��6��ʱ����0����
	.2 ����С��λ�ľ��� 
	��e"�Ǹ�ʽ�ַ���������ָ�����������Դ�дE��ʾ
	
2.	MAXN = 10������õ�ʱ��Ϊ0���������ǿ��Լ���forѭ�����ó�����ܼ���
  	֮���ٲ��㵥��ʱ���ʱ��������ֵ�Ϳ��� 
*/

#include <stdio.h>
#include <time.h>
#include <math.h> 



clock_t start,stop; // clock_t ��clock()�������ص���������
double duration;  //secondes
#define MAXN 10
#define times 10000

//Ҫ���Ե���0-9��һ��10������ʽ 

double f1(int n, double a[], double x);
double f2(int n, double a[], double x);

int main(){
	
	double a[MAXN]; //�洢����ʽ��ϵ�� 
	for(int i = 0; i<MAXN; i++){
		a[i] = (double) i; //��forѭ����ÿһ��ϵ����ֵ 
	} 
	
	start = clock();
	for(int i = 0; i<times; i++) {
		f1(MAXN-1, a, 1.1);
	}
	stop = clock();
	duration = (double)(stop-start)/CLK_TCK/times; //һ������������ʱ��ÿ�����ߵ�ʱ�Ӵ���� 
	printf("ticks = %f\n", (double)(stop-start)); 
	printf("duration1 = %6.2e\n", duration);
	
	start = clock();
	for(int i = 0; i<times; i++) {
		f2(MAXN-1, a, 1.1);
	}
	stop = clock();
	duration = (double)(stop-start)/CLK_TCK/times; //һ������������ʱ��ÿ�����ߵ�ʱ�Ӵ���� 
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
