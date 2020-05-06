#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ori[100], partlySorted[100];

bool IsEqual(int a[], int b[])
{
	for(int i = 0; i < N; i++){
		if(a[i] != b[i])
			return false;
	}
	return true;
}
void Show(int a[])
{
	for(int i = 0; i < N; i++){
		printf("%d", a[i]);
		if(i != N-1)
			printf(" ");
	}
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &ori[i]);
	}
	for(int i = 0; i < N; i++){
		scanf("%d", &partlySorted[i]);
	}
	int i, j;
	for(i = 1; partlySorted[i-1] <= partlySorted[i]; i++);
	for(j = i; j < N && ori[j] == partlySorted[j]; j++);
	if(j == N){
		printf("Insertion Sort\n");
		sort(ori, ori+i+1);
	} else {
		printf("Heap Sort\n");
		make_heap(ori, ori+N);
		for(int i = N; i > 0; i--){
			pop_heap(ori, ori+i);
			if(IsEqual(ori, partlySorted)){
				pop_heap(ori, ori+i-1);
				break;
			}
		}
	}
	Show(ori);
	return 0;
}
