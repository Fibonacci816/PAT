#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<string, string> children[20];
int N, lastNode;

bool IsComplete(int root)
{
	int visitedNum = 0;
	queue<int> q;
	q.push(root);
	visitedNum++;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		if(children[node].first != "-"){
			q.push(stoi(children[node].first));
			visitedNum++;
		} else break;
		if(children[node].second != "-"){
			q.push(stoi(children[node].second));
			visitedNum++;
		} else break;
	}
	lastNode = q.back();
	if(visitedNum == N)
		return true;
	else
		return false;
}

int main()
{
	scanf("%d", &N);
	int root = (N-1) * N / 2;
	string left, right;
	for(int i = 0; i < N; i++){
		cin >> left >> right;
		children[i] = make_pair(left, right);
		if(left != "-")
			root -= stoi(left);
		if(right != "-")
			root -= stoi(right);
	}
	if(IsComplete(root))
		printf("YES %d", lastNode);
	else
		printf("NO %d", root);
	return 0;
}
