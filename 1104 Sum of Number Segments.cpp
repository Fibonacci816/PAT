#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long N;
	scanf("%ld", &N);
	double number, sum = 0;
	for(int i = 0; i < N; i++){
		scanf("%lf", &number);
		sum += (N-i) * (i+1) * number;  //NΪlong���ͣ�����(N-i)*(i+1)���������NΪint���������Ϊ sum += number * (N-i) * (i+1);
	} 
	printf("%.2lf", sum);
	return 0;
} 
