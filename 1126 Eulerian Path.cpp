#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int connectedNum = 0, visited[501];
vector<int> road[501];

void DFS(int root)
{
	connectedNum++;
	visited[root] = 1;
	for(int i = 0; i < road[root].size(); i++){
		if(visited[road[root][i]] == 0)
			DFS(road[root][i]);
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int v1, v2;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &v1, &v2);
		road[v1].push_back(v2);
		road[v2].push_back(v1);
	} 
	int oddDegreeCount = 0;
	for(int i = 1; i <= N; i++){
		if(road[i].size() % 2)
			oddDegreeCount++;
		printf("%d", road[i].size());
		if(i != N)
			printf(" ");
		else
			printf("\n");
	} 
	DFS(1);
	if(connectedNum == N && oddDegreeCount == 0)
		printf("Eulerian");
	else if(connectedNum == N && oddDegreeCount == 2)
		printf("Semi-Eulerian");
	else
		printf("Non-Eulerian");
	return 0;
 } 
