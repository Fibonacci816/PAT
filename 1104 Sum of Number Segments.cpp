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
		sum += (N-i)*(i+1) * (long long)(number * 1000);
	} 
	printf("%.2lf", sum/1000.0);
	return 0;
 } 