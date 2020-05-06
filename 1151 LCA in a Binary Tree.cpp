#include <iostream>
#include <map>
using namespace std;

struct Node{
	int val, level;
	Node * parent, * left, * right;
};
int in[10001], pre[10001];
map<int, Node *> nodes;  //�洢ָ�����ĳ��ֵ�Ľ���ָ�� 
map<int, int> posAtIn;  //posAtIn�洢ĳ��ֵ��in�е�λ�� 

/* ��������ڵ�ֱ��ڸ��������������У�������������ǵ�����������ȣ������������ڸ�����һ�������У������ǵ�����������ȱ��ڸ������ǿ������С�
���Կ��Բ��������ҵ��������Ĺ������ȣ�������Ϊ��ÿ��case��Ҫ�ظ����Ҳ��������ҹ�����ʵ�ͽ����������ƣ�����˵�case������ʱ��ܺ�ʱ��������������Ƚ����ٲ��ҵķ�ʽ */ 
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
						node1 = node1->parent;  //���ѡ��һ��������ƻ�������㶼���ƾ��� 
					}
				}
			}
		}
	}
	return 0;
 } 
