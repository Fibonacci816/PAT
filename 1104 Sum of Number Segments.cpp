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
		sum += (N-i) * (i+1) * number;  //N为long类型，否则(N-i)*(i+1)会溢出；若N为int，这里需改为 sum += number * (N-i) * (i+1);
	} 
	printf("%.2lf", sum);
	return 0;
} 
