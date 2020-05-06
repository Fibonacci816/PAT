#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;

int N, M, source, destination, lengthMap[500][500], timeMap[500][500], distL[500], distT[500], visited[500], pathL[500], pathT[500], intersections[500];

int FindMin(int dist[])
{
	int minIndex = -1, minDist = INF;
	for(int i = 0; i < N; i++) {
		if(visited[i] == 0 && minDist > dist[i]) {
			minDist = dist[i];
			minIndex = i;
		}
	} 
	return minIndex;
}
void DijkstraL(int source, int destination)
{
	fill(distL, distL+500, INF);
	fill(distT, distT+500, INF);
	fill(pathL, pathL+500, -1);
	distL[source] = 0;
	distT[source] = 0;
	while(true) {
		int minIndex = FindMin(distL);
		if(minIndex == destination || minIndex == -1) break;
		visited[minIndex] = 1;
		for(int i = 0; i < N; i++) {
			if(visited[i] == 0 && (distL[i] > distL[minIndex] + lengthMap[minIndex][i] || (distL[i] == distL[minIndex] + lengthMap[minIndex][i] && distT[i] > distT[minIndex] + timeMap[minIndex][i]))) {
				distL[i] = distL[minIndex] + lengthMap[minIndex][i];
				distT[i] = distT[minIndex] + timeMap[minIndex][i];
				pathL[i] = minIndex;
			}
		}
	}
}
void DijkstraT(int source, int destination)
{
	fill(visited, visited+500, 0);
	fill(distT, distT+500, INF);
	fill(intersections, intersections+500, INF);
	fill(pathT, pathT+500, -1);
	distT[source] = 0;
	intersections[source] = 0;
	while(true) {
		int minIndex = FindMin(distT);
		if(minIndex == destination || minIndex == -1) break;
		visited[minIndex] = 1;
		for(int i = 0; i < N; i++) {
			if(visited[i] == 0 && (distT[i] > distT[minIndex] + timeMap[minIndex][i] || (distT[i] == distT[minIndex] + timeMap[minIndex][i] && intersections[i] > intersections[minIndex] + 1))) {
				distT[i] = distT[minIndex] + timeMap[minIndex][i];
				intersections[i] = intersections[minIndex] + 1;
				pathT[i] = minIndex;
			}
		}
	}
}
bool IsEqual(int source, int destination) {
	if(pathL[destination] == pathT[destination])
		return pathL[destination] == source ? true : IsEqual(source, pathL[destination]);
	return false;
}
void PrintfPath(int path[], int source, int destination)
{
	if(path[destination] != -1)
		PrintfPath(path, source, path[destination]);
	if(destination != source) printf(" -> ");
	printf("%d", destination);
}

int main()
{
	scanf("%d %d", &N, &M);
	int v1, v2, oneWay, length, time;
	fill(lengthMap[0], lengthMap[0]+500*500, INF);
	fill(timeMap[0], timeMap[0]+500*500, INF);
	for(int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &v1, &v2, &oneWay, &length, &time);
		if(oneWay) {
			lengthMap[v1][v2] = length;
			timeMap[v1][v2] = time;
		} else {
			lengthMap[v1][v2] = lengthMap[v2][v1] = length;
			timeMap[v1][v2] = timeMap[v2][v1] = time;
		}
	}
	scanf("%d %d", &source, &destination);
	DijkstraL(source, destination);
	DijkstraT(source, destination);
	if(IsEqual(source, destination)) {
		printf("Distance = %d; Time = %d: ", distL[destination], distT[destination]);
		PrintfPath(pathL, source, destination);
	} else {
		printf("Distance = %d: ", distL[destination]);
		PrintfPath(pathL, source, destination);
		printf("\nTime = %d: ", distT[destination]);
		PrintfPath(pathT, source, destination);
	}
	return 0;
}
