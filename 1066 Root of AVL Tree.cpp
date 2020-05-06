#include <iostream>
using namespace std;

struct Node{
	int val, height;
	Node * left, * right;
};

int GetHeight(Node * node)
{
	return node ? node->height : 0; 
	//不需要在插入时及时更新height，也不需要有height属性，需要时递归求 
    //return node ? max(GetHeight(node->left), GetHeight(node->right)) + 1 : 0;
}

Node * SingleLeftRotate(Node * root)
{
	Node * node = root->left;
	root->left = node->right;
	node->right = root;
	root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	node->height = max(GetHeight(node->left), GetHeight(root)) + 1;
	return node;
}

Node * SingleRightRotate(Node * root)
{
	Node * node = root->right;
	root->right = node->left;
	node->left = root;
	root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	node->height = max(GetHeight(root), GetHeight(node->right)) + 1;
	return node;
}

Node * DoubleLeftRightRotate(Node * root)
{
	root->left = SingleRightRotate(root->left);
	return SingleLeftRotate(root);
}

Node * DoubleRightLeftRotate(Node * root)
{
	root->right = SingleLeftRotate(root->right);
	return SingleRightRotate(root);
}

Node * Insert(Node * root, int val)
{
	if(root == NULL){
		root = new Node();
		root->val = val;
		root->height = 1;
		root->left = root->right = NULL;
	} else if (val < root->val){
		root->left = Insert(root->left, val);
		if(GetHeight(root->left) - GetHeight(root->right) == 2){
			root = val < root->left->val ? SingleLeftRotate(root) : DoubleLeftRightRotate(root);
		}
	} else {
		root->right = Insert(root->right, val);
		if(GetHeight(root->right) - GetHeight(root->left) == 2){
			root = val > root->right->val ? SingleRightRotate(root) : DoubleRightLeftRotate(root);
		}
	}
	root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	//printf("|%d %d|\n", root->val, root->height);
	return root;
}

int main()
{
	int N, val;
	Node * root = NULL;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &val);
		root = Insert(root, val);
	}
	printf("%d", root->val);
	return 0;
}
