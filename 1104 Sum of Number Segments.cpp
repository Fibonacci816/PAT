#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	double number;
    long long sum = 0;
	for(int i = 0; i < N; i++){
		scanf("%lf", &number);
		sum += (N-i)*(i+1) * (long long)(number * 1000);  // 解决double类型数值在大量累乘累加后造成的精度误差；若inputs的小数点位数大于3，那么当前代码不再保证能得到正确答案
	} 
	printf("%.2lf", sum/1000.0);
	return 0;
 } 