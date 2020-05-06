#include <iostream>
#include <vector>
#define MAX 501
#define INF 0x3f3f3f3f
using namespace std;

int Cmax, N, Sp, M, currentNumber[MAX], roadMap[MAX][MAX], visited[MAX], dist[MAX], minTake = INF, minBack = INF;
vector<int> pre[MAX], path, ansPath;

int FindMin()
{
	int minIndex = -1, minDist = INF;
	for(int i = 0; i <= N; i++) {
		if(visited[i] == 0 && dist[i] < minDist) {
			minDist = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}
void Dijkstra(int root)
{
	fill(dist, dist+MAX, INF);
	dist[root] = 0;
	while(true) {
		int minIndex = FindMin();
		if(minIndex == -1 || minIndex == Sp) break;
		visited[minIndex] = 1;
		for(int i = 0; i <= N; i++) {
			if(visited[i] == 0) {
				if(dist[i] > dist[minIndex] + roadMap[minIndex][i]) {
					dist[i] = dist[minIndex] + roadMap[minIndex][i];
					pre[i].clear();
					pre[i].push_back(minIndex);
				} else if(dist[i] == dist[minIndex] + roadMap[minIndex][i]) {
					pre[i].push_back(minIndex);
				}
			}
		}
	}
}
void DFS(int node)
{
	path.push_back(node);
	if(node == 0) {
		int now = 0, take = 0;
		for(int i = path.size()-1; i >= 0; i--) {
			now += currentNumber[path[i]];
			if(now < 0) {
				take += -now;
				now = 0;
			}
		}
		if(take < minTake) {
			minTake = take;
			minBack = now;
			ansPath = path;
		} else if(take == minTake && now < minBack) {
			minBack = now;
			ansPath = path;
		}
	}
	for(int i = 0; i < pre[node].size(); i++) {
		DFS(pre[node][i]);
	}
	path.pop_back();
}

int main()
{
	scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &currentNumber[i]);
		currentNumber[i] -= Cmax/2;
	}
	int v1, v2, time;
	fill(roadMap[0], roadMap[0]+MAX*MAX, INF);
	for(int i = 1; i <= M; i++) {
		scanf("%d %d %d", &v1, &v2, &time);
		roadMap[v1][v2] = roadMap[v2][v1] = time;
	}
	Dijkstra(0);
	DFS(Sp);
	printf("%d %d", minTake, 0);
	for(int i = ansPath.size()-2; i >= 0; i--) {
		printf("->%d", ansPath[i]);
	}
	printf(" %d", minBack);
	return 0;
} 
