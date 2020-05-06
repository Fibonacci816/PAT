#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
	string left, right;
};

int N, Root = 0, flag = 0;
Node children[10];

void Levelorder(int root)
{
	queue<int> que;
	que.push(root);
	while(!que.empty()){
		int node = que.front();
		if(node != Root)
			printf(" ");
		printf("%d", node);
		que.pop();
		if(children[node].right != "-")
			que.push(stoi(children[node].right));
		if(children[node].left != "-")
			que.push(stoi(children[node].left));
	}
}
void Inorder(int root)
{
	if(children[root].right != "-")
		Inorder(stoi(children[root].right));
	if(flag != 0)
		printf(" ");
	else
		flag = 1;
	printf("%d", root);
	if(children[root].left != "-")
		Inorder(stoi(children[root].left));
	
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		Root += i;
	string left, right;
	for(int i = 0; i < N; i++){
		cin >> left >> right;
		children[i].left = left;
		children[i].right = right;
		if(left != "-")
			Root -= stoi(left);
		if(right != "-")
			Root -= stoi(right);
	} 
	Levelorder(Root);
	cout << endl;
	Inorder(Root);
	return 0;
 } 
