//这里采用Floyd算法，本题也可采用BFS、DFS
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int network[1001][1001];

int main()
{
	int N, L;
	scanf("%d %d", &N, &L);
	fill(network[0], network[0] + 1001*1001, INF);
	int followNum, followed;
	for(int i = 1; i <= N; i++){
		scanf("%d", &followNum);
		for(int j = 0; j < followNum; j++){
			scanf("%d", &followed);
			network[i][followed] = 1;
		}
	}
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(network[i][j] > network[i][k]+network[k][j]){
					network[i][j] = network[i][k]+network[k][j];
				}
			}
		}
	}
	int queryNum, queried, potential;
	scanf("%d", &queryNum);
	for(int i = 1; i <= queryNum; i++){
		scanf("%d", &queried);
		potential = 0;
		for(int j = 1; j <= N; j++){
			if(j != queried && network[j][queried] <= L){
				potential++;
			}
		}
		printf("%d\n", potential);
	}
	return 0;
}
