#include <iostream>
using namespace std;

struct Node {
	int val;
	Node * left, * right;
};

int GetHeight(Node * root)
{
	return root ? max(GetHeight(root->left), GetHeight(root->right))+1 : 0;
}
void LeftRotate(Node * &root)
{
	Node * node = root->left;
	root->left = node->right;
	node->right = root;
	root = node;
}
void RightRotate(Node * &root)
{
	Node * node = root->right;
	root->right = node->left;
	node->left = root;
	root = node;
}
void LeftRightRotate(Node * &root)
{
	RightRotate(root->left);
	LeftRotate(root);
}
void RightLeftRotate(Node * &root)
{
	LeftRotate(root->right);
	RightRotate(root);
}
void Insert(Node * &root, int val)
{
	if(root == NULL) {
		root = new Node{val, NULL, NULL};
		return;
	}
	if(val < root->val) {
		Insert(root->left, val);
		if(GetHeight(root->left) - GetHeight(root->right) > 1) 
			val < root->left->val ? LeftRotate(root) : LeftRightRotate(root);
	} else {
		Insert(root->right, val);
		if(GetHeight(root->right) - GetHeight(root->left) > 1) 
			val > root->right->val ? RightRotate(root) : RightLeftRotate(root);
	}
}

int main()
{
	int N, val;
	scanf("%d", &N);
	Node * root = NULL;
	for(int i = 0; i < N; i++) {
		scanf("%d", &val);
		Insert(root, val);
	}
	printf("%d", root->val);
	return 0;
 } 
