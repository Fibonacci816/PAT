#include <iostream>
#include <map>
using namespace std;

struct Node{
	int val, level;
	Node * parent, * left, * right;
};
int in[10001], pre[10001];
map<int, Node *> nodes;  //存储指向具有某个值的结点的指针 
map<int, int> posAtIn;  //posAtIn存储某个值在in中的位置 

/* 如果两个节点分别在根结点的两棵子树中，则根结点就是他们的最近公共祖先；如果两个结点在根结点的一棵子树中，则他们的最近公共祖先必在根结点的那棵子树中。
所以可以不建树而找到两个结点的公共祖先，但是因为对每个case都要重复查找操作（查找过程其实和建树过程类似），因此当case数量多时会很耗时，所以这里采用先建树再查找的方式 */ 
Node * Create(int root, int start, int end, int level)
{
	if(start > end) return NULL;
	Node * Root = new Node{pre[root], level, NULL, NULL, NULL};
	int pos = posAtIn[pre[root]];
	Root->left = Create(root+1, start, pos-1, level+1);
	Root->right = Create(root+1+pos-start, pos+1, end, level+1);
	if(Root->left) Root->left->parent = Root;
	if(Root->right) Root->right->parent = Root;
	nodes[pre[root]] = Root;
	return Root;
}

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &in[i]);
		posAtIn[in[i]] = i; 
	}
	for(int i = 1; i <= N; i++){
		scanf("%d", &pre[i]);
	}
	Node * root = Create(1, 1, N, 0);
	int val1, val2;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &val1, &val2);
		if(nodes.count(val1) == 0 && nodes.count(val2) == 0){
			printf("ERROR: %d and %d are not found.\n", val1, val2);
		} else if(nodes.count(val1) == 0){
			printf("ERROR: %d is not found.\n", val1);
		} else if(nodes.count(val2) == 0){
			printf("ERROR: %d is not found.\n", val2);
		} else{
			Node * node1 = nodes[val1];
			Node * node2 = nodes[val2];
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
						node1 = node1->parent;  //随便选择一个结点上移或两个结点都上移均可 
					}
				}
			}
		}
	}
	return 0;
 } 
