#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int initial[N], partiallySorted[N];
	for(int i = 0; i < N; i++) {
		scanf("%d", &initial[i]);
	}
	for(int i = 0; i < N; i++) {
		scanf("%d", &partiallySorted[i]);
	}
	int i, j;
	for(i = 1; i < N && partiallySorted[i-1] <= partiallySorted[i]; i++);
	for(j = i; j < N && initial[j] == partiallySorted[j]; j++);
	if(j == N) {
		printf("Insertion Sort\n");
		sort(partiallySorted, partiallySorted+i+1);
	} else {
		printf("Heap Sort\n");
		int index;
		for(index = N-1; index > 0 && partiallySorted[index] > partiallySorted[0]; index--);
		swap(partiallySorted[index], partiallySorted[0]);
		make_heap(partiallySorted, partiallySorted+index);
	}
	for(int i = 0; i < N; i++) {
		if(i != 0) printf(" ");
		printf("%d", partiallySorted[i]);
	}
	return 0;
}
