#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node{
	int val;
	Node * left, * right;
};

int pre[30], in[30], isRedBlack;
bool cmp(int node1, int node2)
{
	return abs(node1) < abs(node2);
}
Node * Create(int root, int start, int end)
{
	if(start > end)
		return NULL;
	Node * Root = new Node();
	Root->val = pre[root];
	int i = start;
	for(; i < end && in[i] != pre[root]; i++);
	Root->left = Create(root+1, start, i-1);
	Root->right = Create(root+1+i-start, i+1, end);
	return Root;
}
int DFS(Node * Root)
{
	if(Root->val < 0){
		if((Root->left!=NULL && Root->left->val<0) || (Root->right!=NULL && Root->right->val<0))  //if a red node contain red child
			isRedBlack = 0;
	}
	int blackNumL = 0, blackNumR = 0;
	if(isRedBlack && Root->left)
		blackNumL = DFS(Root->left);
	if(isRedBlack && Root->right)
		blackNumR = DFS(Root->right);
	if(blackNumL != blackNumR){  //if exist one node, the paths from the node to descendant leaves contain different number of black nodes 
		isRedBlack = 0;
	}
	return Root->val > 0 ? max(blackNumL, blackNumR)+1 : max(blackNumL, blackNumR);
}

int main()
{
	int K, N;
	scanf("%d", &K);
	for(int i = 0; i < K; i++){
		scanf("%d", &N);
		for(int j = 0; j < N; j++){
			scanf("%d", &pre[j]);
			in[j] = pre[j];
		}
		sort(in, in+N, cmp);
		Node * Root = Create(0, 0, N-1);  //这里根据先序和中序序列划分建树，也可以直接以先序序列为二叉排序树插入序列建树 
		isRedBlack = 1;
		if(Root->val > 0) DFS(Root);
		if(Root->val > 0 && isRedBlack)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
 } 
