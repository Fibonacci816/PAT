#include <iostream>
#include <algorithm>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;

int N, K;
map<string, int> cityToIndex;  //城市到位置下标的映射 
string cities[200];  //存储所有城市，可通过下标取得对应的城市 
int roadMap[200][200], happiness[200], cost[200], visited[200], totalHappiness[200], path[200], pathNum[200], roadNumAlongPath[200];

int FindMin()
{
	int minCost = INF, minIndex = -1;
	for(int i = 0; i < N; i++){
		if(visited[i] == 0 && minCost > cost[i]){
			minCost = cost[i];
			minIndex = i; 
		}
	}
	return minIndex;
}

void Dijkstra(int start, int end)
{
	fill(cost, cost+200, INF);
	cost[start] = 0;
	totalHappiness[start] = 0;
	pathNum[start] = 1;
	roadNumAlongPath[start] = 0;
	while(true){
		int minIndex = FindMin();
		if(minIndex == end || minIndex == -1){
			break;
		}	
		visited[minIndex] = 1;
		for(int i = 0; i < N; i++){
			if(visited[i] == 0){
				if(cost[i] > cost[minIndex] + roadMap[minIndex][i]){
					cost[i] = cost[minIndex] + roadMap[minIndex][i];
					totalHappiness[i] = totalHappiness[minIndex] + happiness[i];
					path[i] = minIndex;
					pathNum[i] = pathNum[minIndex];
					roadNumAlongPath[i] = roadNumAlongPath[minIndex] + 1;
				} else if(cost[i] == cost[minIndex] + roadMap[minIndex][i]){
					pathNum[i] += pathNum[minIndex];
					if(totalHappiness[i] < totalHappiness[minIndex] + happiness[i]){
						totalHappiness[i] = totalHappiness[minIndex] + happiness[i];
						path[i] = minIndex;
						roadNumAlongPath[i] = roadNumAlongPath[minIndex] + 1;
					} else if(totalHappiness[i] == totalHappiness[minIndex] + happiness[i] && totalHappiness[i] / roadNumAlongPath[i] < (totalHappiness[minIndex] + happiness[i]) / (roadNumAlongPath[minIndex] + 1)){
						path[i] = minIndex;
						roadNumAlongPath[i] = roadNumAlongPath[minIndex] + 1;
					}
				}
			}
		}
	}
}
void PrintPath(int end)
{
	if(path[end] != 0){
		PrintPath(path[end]);
	}
	cout << "->" << cities[end];
}

int main()
{
	int cityhappiness;
	char city[4];
	scanf("%d %d", &N, &K);
	scanf("%s", city);
	cities[0] = city;
	cityToIndex[city] = 0;
	for(int i = 1; i < N; i++){
		scanf("%s", city);
		scanf("%d", &cityhappiness);
		cities[i] = city;
		cityToIndex[city] = i;
		happiness[i] = cityhappiness;
	}
	fill(roadMap[0], roadMap[0]+200*200, INF);
	int city1, city2, intercost;
	for(int i = 0; i < K; i++){
		scanf("%s", city);
		city1= cityToIndex[city];
		scanf("%s", city);
		city2= cityToIndex[city];
		scanf("%d", &intercost);
		roadMap[city1][city2] = roadMap[city2][city1] = intercost;
	}
	int end = cityToIndex["ROM"]; 
	Dijkstra(0, end);
	printf("%d %d %d %d\n", pathNum[end], cost[end], totalHappiness[end], totalHappiness[end]/roadNumAlongPath[end]);
	cout << cities[0];
	PrintPath(end);
	return 0;
}
