#include <iostream>
#include <algorithm>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;

int N, M, K, D;
int roadMap[1011][1011];
int dist[1011], visited[1011];

int ChangeToNumber(char str[])
{
	int number = 0;
	if(str[0] == 'G'){
		number = atoi(str+1) + N;
	} else {
		number = atoi(str);
	}
	return number;
}

int FindMinDist()
{
	int minV = -1, minD = INF;
	for(int i = 1; i <= N+M; i++){
		if(visited[i] == 0 && dist[i] < minD){
			minD = dist[i];
			minV = i;
		}
	}
	return minV;
}

void Dijkstra(int V){
	dist[V] = 0;
	while(true){
		int minV = FindMinDist();
		if(minV == -1){
			break;
		}
		visited[minV] = 1;
		for(int i = 1; i <= N+M; i++){
			if(visited[i] == 0 && dist[i] > dist[minV] + roadMap[minV][i]){
				dist[i] = dist[minV] + roadMap[minV][i];
			}
		}
	}
}

int main()
{
	char P1[5], P2[5];
	int p1, p2;
	int distance;
	scanf("%d %d %d %d", &N, &M, &K, &D);
	fill(roadMap[0], roadMap[0]+1011*1011, INF);
	for(int i = 0; i < K; i++){
		scanf("%s %s %d", P1, P2, &distance);
		p1 = ChangeToNumber(P1);
		p2 = ChangeToNumber(P2);
		roadMap[p1][p2] = roadMap[p2][p1] = distance;
	}
	int id = 0;
	double globalMaxDistance = -1, globalTotalDistance = INF;
	for(int i = N+1; i <= N+M; i++){
		int flag = 1, totalDistance = 0;
		double minDistance = INF;
		fill(dist, dist+1011, INF);
		fill(visited, visited+1011, 0);
		Dijkstra(i);
		for(int j = 1; j <= N; j++){
			if(dist[j] > D){
				flag = 0;
				break;
			}
			totalDistance += dist[j];
			if(minDistance > dist[j]){
				minDistance = dist[j];
			}
		}
		if(flag){
			if(globalMaxDistance < minDistance){
				globalMaxDistance = minDistance;
				globalTotalDistance = totalDistance;
				id = i - N;
			} else if(globalMaxDistance == minDistance && totalDistance < globalTotalDistance){
				globalTotalDistance = totalDistance;
				id = i - N;
			}
		}
	}
	if(id != 0){
		printf("G%d\n", id);
		printf("%.1lf %.1lf", globalMaxDistance, globalTotalDistance/N);
	} else {
		printf("No Solution");
	}
	return 0;
}
