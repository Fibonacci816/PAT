#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int nodes[100000000];  //采用数组方式存储二叉树节点 

void PostorderTravel(int root)
{
	if(nodes[root] == 0){
		return;
	}
	if(nodes[2*root] != 0){
		PostorderTravel(2*root);
	}
	if(nodes[2*root+1] != 0){
		PostorderTravel(2*root+1);
	}
	printf("%d", nodes[root]);
	if(root != 1){
		printf(" ");
	}
}

int main()
{
	int N, flag = 0, cur = 0;  //flag用来标记下一个节点在左子树还是在右子树插入，cur为当前节点的下标位置 
	scanf("%d\n", &N);
	stack<int> s;
	string operation;
	for(int i = 1; i <= 2*N; i++){
		getline(cin, operation);
		if(operation == "Pop"){
			cur = s.top();
			s.pop();
			flag = 1;
		} else {
			int arg = stoi(operation.substr(5));  //取出push节点的value值 
			if(cur == 0){
				cur = 1;
			} else {
				if(flag == 0){
					cur = 2 * cur;
				} else {
					cur = 2 * cur + 1;
				}
			}
			nodes[cur] = arg;
			s.push(cur);
			flag = 0;
		}
	}
	PostorderTravel(1);
	return 0;
}
