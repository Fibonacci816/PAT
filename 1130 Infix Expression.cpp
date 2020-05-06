#include <iostream>
using namespace std;

struct Node{
	char data[11];
	int left, right;
};
Node nodes[21];
int N, Root = 0;

string GetExpression(int root)
{
	string left, right;
	if(nodes[root].left != -1)
		left = GetExpression(nodes[root].left);
	if(nodes[root].right != -1)
		right = GetExpression(nodes[root].right);
	if(root != Root && nodes[root].right != -1){
		left = "(" + left;
		right = right + ")";
	}
	return left + string(nodes[root].data) + right;
}

int main()
{
	scanf("%d", &N);
	Root = ((1+N) * N) / 2;
	for(int i = 1; i <= N; i++){
		scanf("%s %d %d", nodes[i].data, &nodes[i].left, &nodes[i].right);
		if(nodes[i].left != -1)
			Root -= nodes[i].left;
		if(nodes[i].right != -1)
			Root -= nodes[i].right;
	}
	cout << GetExpression(Root);
	return 0;
}
