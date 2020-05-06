#include <iostream>
#include <algorithm>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;

int N, M, K, D;
int roadMap[1011][1011];

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
	for(int k = 1; k <= N+M; k++){
		for(int i = 1; i <= N+M; i++){
			for(int j = 1; j <= N+M; j++){
				if(roadMap[i][k] + roadMap[k][j] < roadMap[i][j]){
					roadMap[i][j] = roadMap[i][k] + roadMap[k][j];
				}
			}
		}
	}
	int id = 0;
	double globalMaxDistance = -1, globalTotalDistance = INF;
	for(int i = N+1; i <= N+M; i++){
		int flag = 1, totalDistance = 0;
		double minDistance = INF;
		for(int j = 1; j <= N; j++){
			if(roadMap[i][j] > D){
				flag = 0;
				break;
			}
			totalDistance += roadMap[i][j];
			if(roadMap[i][j] < minDistance){
				minDistance = roadMap[i][j];
			}
		}
		if(flag){
			if(globalMaxDistance < minDistance){
				globalMaxDistance = minDistance;
				globalTotalDistance = totalDistance;
				id = i - N;
			} else if(globalMaxDistance == minDistance){
				if(totalDistance < globalTotalDistance){
					globalTotalDistance = totalDistance;
					id = i - N;
				}
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
