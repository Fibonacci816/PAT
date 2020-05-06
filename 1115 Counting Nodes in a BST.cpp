#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int value;
	Node * left, * right;
};
int maxLevel = 0, nodeNumAtLevel[1000];
void Insert(Node * &root, int value, int level)
{
	if(!root){
        if(level > maxLevel)
            maxLevel = level;
        nodeNumAtLevel[level]++;
		root = new Node();
		root->value = value;
		root->left = root->right = NULL;
		return;
	}
	if(value > root->value)
		Insert(root->right, value, level+1);
	else
		Insert(root->left, value, level+1);
}

int main()
{
	int N, value;
	scanf("%ld", &N);
	Node * root = NULL;
	for(int i = 0; i < N; i++){
		scanf("%d", &value);
		Insert(root, value, 0);
	}
	printf("%d + %d = %d", nodeNumAtLevel[maxLevel], nodeNumAtLevel[maxLevel-1], nodeNumAtLevel[maxLevel]+nodeNumAtLevel[maxLevel-1]);
	return 0;
}
