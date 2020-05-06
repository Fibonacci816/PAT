#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	double ropes[N];
	for(int i = 0; i < N; i++){
		scanf("%lf", &ropes[i]);
	} 
	sort(ropes, ropes+N);
	double length = ropes[0];
	for(int i = 1; i < N; i++){
		length = length / 2 + ropes[i] / 2;
	} 
	printf("%d", (int)length);
	return 0;
 } 
