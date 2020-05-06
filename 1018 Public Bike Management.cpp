#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

int C_max, N, S_p, M, minNeed = INF, minBack = INF, currentNumber[501], roadMap[501][501], dist[501], visited[501];
vector<int> pre[501], path, temppath;

int FindMin()
{
	int minIndex = -1, minDist = INF;
	for(int i = 0; i <= N; i++){
		if(visited[i] == 0 && minDist > dist[i]){
			minDist = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}
void Dijkstra(int root)
{
	fill(dist, dist+501, INF);
	dist[root] = 0;
	while(true){
		int minIndex = FindMin();
		if(minIndex == -1 || minIndex == S_p)
			break;
		visited[minIndex] = 1;
		for(int i = 0; i <= N; i++){
			if(visited[i] == 0)
				if(dist[i] > dist[minIndex] + roadMap[minIndex][i]){
					dist[i] = dist[minIndex] + roadMap[minIndex][i];
					pre[i].clear();
					pre[i].push_back(minIndex);
				} else if(dist[i] == dist[minIndex] + roadMap[minIndex][i]){
					pre[i].push_back(minIndex);
				}
		}
	}
}
void DFS(int v)
{
	temppath.push_back(v);
    if(v == 0) {
        int need = 0, back = 0;
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            if(currentNumber[id] > 0) {
                back += currentNumber[id];
            } else {
                if(back > -currentNumber[id]) {
                    back += currentNumber[id];
                } else {
                    need += -currentNumber[id] - back;
                    back = 0;
                }
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++)
        DFS(pre[v][i]);
    temppath.pop_back();
}

int main()
{
	scanf("%d %d %d %d", &C_max, &N, &S_p, &M);
	for(int i = 1; i <= N; i++){
		scanf("%d", &currentNumber[i]);
		currentNumber[i] = currentNumber[i] - C_max / 2;
	}
	int i, j, time;
	fill(roadMap[0], roadMap[0]+501*501, INF);
	for(int m = 0; m < M; m++){
		scanf("%d %d %d", &i, &j, &time);
		roadMap[i][j] = roadMap[j][i] = time;
	}
	Dijkstra(0);
	DFS(S_p);
	printf("%d 0", minNeed);
	for(int i = path.size() - 2; i >= 0; i--)
    	printf("->%d", path[i]);
	printf(" %d", minBack);
	return 0;
}
