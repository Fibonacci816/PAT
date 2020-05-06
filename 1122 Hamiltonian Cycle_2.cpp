#include <iostream>
#include <set>
#define MAX 201
using namespace std;

int road[MAX][MAX];

int main()
{
	int N, M, K;
	scanf("%d %d", &N, &M);
	int v1, v2;
	for(int i = 0; i < M; i++) {
		scanf("%d %d", &v1, &v2);
		road[v1][v2] = road[v2][v1] = 1;
	}
	scanf("%d", &K);
	for(int i = 0; i < K; i++) {
		int n, start, flag = 1;  //flag标识是否相邻结点可达 
		scanf("%d %d", &n, &v1);
		start = v1;
		set<int> vertices;
		for(int j = 1; j < n; j++) {
			scanf("%d", &v2);
			vertices.insert(v2);
			if(road[v1][v2] == 0) flag = 0;
			v1 = v2;
		}
		if(n == N+1 && start == v1 && flag && vertices.size() == N)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
 } 
