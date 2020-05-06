#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long N, S1 = 0, S2 = 0;
	scanf("%ld", &N);
	long numbers[N];
	for(int i = 0; i < N; i++){
		scanf("%ld", &numbers[i]);
	}
	sort(numbers, numbers+N);
	for(int i = 0; i < N; i++)
		(i < N/2 ? S1 : S2) += numbers[i];
	printf("%ld %ld", N%2, S2-S1);
	return 0;
}
