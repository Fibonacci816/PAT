#include <iostream>
using namespace std;

int M, N, numbers[1001];
void Postorder(int root)
{
	if(root*2 <= N) Postorder(root*2);
	if(root*2+1 <= N) Postorder(root*2+1);
	printf("%d%s", numbers[root], root == 1 ? "\n" : " ");
}

int main()
{
	scanf("%d %d", &M, &N);
	for(int i = 0; i < M; i++){
		for(int j = 1; j <= N; j++) scanf("%d", &numbers[j]);
		int isMaxHeap = 1, isMinHeap = 1;
		for(int j = 2; j <= N; j++){
			if(numbers[j/2] < numbers[j]) isMaxHeap = 0;
			if(numbers[j/2] > numbers[j]) isMinHeap = 0;
		}
		printf("%s\n", isMaxHeap ? "Max Heap" : isMinHeap ? "Min Heap" : "Not Heap");
		Postorder(1);
	}
	return 0;
 } 
