#include <iostream>
using namespace std;

struct Node{
	int val, level;
	Node * parent, * left, * right;
};

Node * Create(Node * root, int val, int level)
{
	if(root == NULL){
		root = new Node();
		root->val = val;
		root->level = level;
		root->parent = root->left = root->right = NULL;
	} else if(val < root->val){
		root->left = Create(root->left, val, level+1);
		root->left->parent = root;
	} else {
		root->right = Create(root->right, val, level+1);
		root->right->parent = root;
	}
	return root;
}
Node * Find(Node * root, int val)
{
	if(root == NULL)
		return NULL;
	if(root->val == val){
		return root;
	} else if(root->val > val){
		return Find(root->left, val);
	} else {
		return Find(root->right, val);
	}
}

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);
	Node * root = NULL;
	int val;
	for(int i = 0; i < N; i++){
		scanf("%d", &val);
		root = Create(root, val, 0);
	}
	int val1, val2;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &val1, &val2);
		Node * node1 = Find(root, val1);
		Node * node2 = Find(root, val2);
		if(node1 == NULL && node2 == NULL){
			printf("ERROR: %d and %d are not found.\n", val1, val2);
		} else if(node1 == NULL){
			printf("ERROR: %d is not found.\n", val1);
		} else if(node2 == NULL){
			printf("ERROR: %d is not found.\n", val2);
		} else{
			while(true){
				if(node1->level > node2->level){
					node1 = node1->parent;
				} else if(node1->level < node2->level){
					node2 = node2->parent;
				} else {
					if(node1->val == node2->val){
						if(node1->val == val2){
							printf("%d is an ancestor of %d.\n", val2, val1);
						} else if(node2->val == val1){
							printf("%d is an ancestor of %d.\n", val1, val2);
						} else {
							printf("LCA of %d and %d is %d.\n", val1, val2, node1->val);
						}
						break;
					} else {
						node1 = node1->parent;
					}
				}
			}
		}
		
	}
	return 0;
 } 
