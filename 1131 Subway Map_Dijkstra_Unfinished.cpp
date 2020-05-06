#include <iostream>
#include <vector>
#include <unordered_map>
#define INF 0x3f3f3f3f
using namespace std;
vector<int> roads[10000];
int visited[10000], start, destination, dist[10000], pathV[10000];
unordered_map<int, int> line;
vector<int> path, tempPath;
int CountTransfer(vector<int> a) {
    int transferNum = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]*10000+a[i]] != preLine) transferNum++;
        preLine = line[a[i-1]*10000+a[i]];
    }
    return transferNum;
}
int FindMax()
{
	int index = -1, minDist = INF;
	for(int i = 0; i < 10000; i++){
		if(visited[i] == 0 && dist[i] < minDist){
			minDist = dist[i];
			index = i;
		}
	}
	return index;
}
void Dijkstra(int start, int destination)
{
	fill(visited, visited+10000, 0);
	fill(dist, dist+10000, INF);
	fill(pathV, pathV+10000, -1);
	dist[start] = 0;
	int minTransferNum = INF;
	while(true){
		int minIndex = FindMax();
		if(minIndex == -1 || minIndex == destination)
			break;
		visited[minIndex] = 1;
		for(int i = 0; i < roads[minIndex].size(); i++){
			if(visited[roads[minIndex][i]] == 0){
				if(dist[roads[minIndex][i]] > dist[minIndex]+1){
					dist[roads[minIndex][i]] = dist[minIndex]+1;
					pathV[roads[minIndex][i]] = minIndex;
				}
			}
		}
	}
}

int main() {
    int n, m, k, pre, cur;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &cur);
            roads[pre].push_back(cur);
            roads[cur].push_back(pre);
            line[pre*10000+cur] = line[cur*10000+pre] = i;
            pre = cur;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &start, &destination);
        Dijkstra(start, destination);
        printf("%d\n", dist[destination]);
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]*10000+path[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]*10000+path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, destination);
    }
    return 0;
}
