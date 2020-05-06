#include <iostream>
using namespace std;

int pre[50000], in[50000], firstNumberAtPostorder = -1;

void GetPostOrder(int root, int start, int end)
{
	if(start > end || firstNumberAtPostorder != -1)
		return;
	int i = start;
	for(; i < end && in[i] != pre[root]; i++);
	GetPostOrder(root+1, start, i-1);
	GetPostOrder(root+1+i-start, i+1, end);
	if(firstNumberAtPostorder == -1)
		firstNumberAtPostorder = pre[root];
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
        scanf("%d", &pre[i]);
	}
	for(int i = 0; i < N; i++){
        scanf("%d", &in[i]);
	}
	GetPostOrder(0, 0, N-1);
	printf("%d", firstNumberAtPostorder);
	return 0;
 } 
