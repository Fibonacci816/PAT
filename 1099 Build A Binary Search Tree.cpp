#include <iostream>
#include <algorithm>
#include <map> 
#include <queue>
using namespace std;

struct Node{
	int left_index, right_index;
	int value;
};
Node nodes[100];
int keys[100], start = 0;

void Inorder(int root)
{
	if(nodes[root].left_index != -1)
		Inorder(nodes[root].left_index);
	nodes[root].value = keys[start++];
	if(nodes[root].right_index != -1)
		Inorder(nodes[root].right_index);
}
void Levelorder(int root)
{
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		if(node != root)
			printf(" ");
		printf("%d", nodes[node].value);
		if(nodes[node].left_index != -1){
			q.push(nodes[node].left_index);
		}
		if(nodes[node].right_index != -1){
			q.push(nodes[node].right_index);
		}
	}
}

int main()
{
	int N,left_index, right_index;
	
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &nodes[i].left_index, &nodes[i].right_index);
	}
	for(int i = 0; i < N; i++){
		scanf("%d", &keys[i]);
	}
	sort(keys, keys+N);
	Inorder(0);
	Levelorder(0);
	return 0;
}
