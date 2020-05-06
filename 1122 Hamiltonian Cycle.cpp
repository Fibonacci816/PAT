#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int roadMap[201][201];

int main()
{
	int N, M, V1, V2;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++){
		scanf("%d %d", &V1, &V2);
		roadMap[V1][V2] = roadMap[V2][V1] = 1;
	}
	int K, n;
	scanf("%d", &K);
	for(int i = 0; i < K; i++){
		scanf("%d", &n);
		int v[n];
		set<int> vertexs;
		for(int i = 0; i < n; i++){
			scanf("%d", &v[i]);
			vertexs.insert(v[i]);
		}
		bool flag1 = true, flag2 = true;
		if(n!=N+1 || vertexs.size()!=N || v[0]!=v[n-1]){
			flag1 = false;
		} else {
			for(int i = 0; i < n-1; i++){
				if(roadMap[v[i]][v[i+1]] == 0){
					flag2 = false;
					break;
				}
			}
		}
		printf("%s\n", flag1&&flag2 ? "YES" : "NO");
	}
	return 0;
}
