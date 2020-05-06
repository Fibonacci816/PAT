#include <iostream>
using namespace std;

struct Node {
	int val;
	Node * left, * right;
};
bool isRedBlack;

void Create(int val, Node * &root)
{
	if(root == NULL) {
		root = new Node();
		root->val = val;
		root->left = root->right = NULL;
	} else {
		if(abs(val) < abs(root->val)) Create(val, root->left);
		else Create(val, root->right);
	}
}
int DFS(Node * root)
{
	if(root->val < 0 && ((root->left && root->left->val < 0) || (root->right && root->right->val < 0))) 
		isRedBlack = false;
	int blackNumL = 0, blackNumR = 0;
	if(isRedBlack && root->left) 
		blackNumL = DFS(root->left);
	if(isRedBlack && root->right) 
		blackNumR = DFS(root->right);
	if(blackNumL != blackNumR) 
		isRedBlack = false;
	return root->val > 0 ? blackNumR+1 : blackNumR;
}

int main()
{
	int K, N;
	scanf("%d", &K);
	for(int i = 0; i < K; i++) {
		Node * root = NULL;
		int val;
		scanf("%d", &N);
		for(int j = 0; j < N; j++) {
			scanf("%d", &val);
			Create(val, root); 
		}
		isRedBlack = true;
		DFS(root);
		if(root->val > 0 && isRedBlack) 
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
