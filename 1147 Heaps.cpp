#include <iostream>
#include <vector>
using namespace std;

int M, N, numbers[1001], isHeap, flag;
vector<int> post;
void Postorder(int root)
{
	if(root*2 <= N){
		if((flag == 1 && numbers[root] < numbers[root*2]) || (flag == -1 && numbers[root] > numbers[root*2])) isHeap = 0;
		Postorder(root*2);
	}
	if(root*2+1 <= N){
		if((flag == 1 && numbers[root] < numbers[root*2+1]) || (flag == -1 && numbers[root] > numbers[root*2+1])) isHeap = 0;
		Postorder(root*2+1);
	}
	post.push_back(numbers[root]);
}

int main()
{
	scanf("%d %d", &M, &N);
	for(int i = 0; i < M; i++){
		for(int j = 1; j <= N; j++) scanf("%d", &numbers[j]);
		isHeap = 1, flag = numbers[1] > numbers[2] ? 1 : -1;
		post.clear();
		Postorder(1);
		if(!isHeap) printf("Not Heap\n");
		else printf("%s\n", flag == 1 ? "Max Heap" : "Min Heap");
		for(int j = 0; j < post.size(); j++){
			if(j != 0) printf(" ");
			printf("%d", post[j]);
		}
		printf("\n");
	}
	return 0;
 } 
