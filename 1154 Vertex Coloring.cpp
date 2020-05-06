#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N, M, K;
	scanf("%d %d", &N, &M);
	pair<int, int> edges[M];
	int v1, v2;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &v1, &v2);
		edges[i] = make_pair(v1, v2);
	}
	scanf("%d", &K);
	for(int i = 0; i < K; i++){
		int vertexColors[N], flag = 1;
		set<int> uniqueColors;
		for(int j = 0; j < N; j++){
			scanf("%d", &vertexColors[j]);
			uniqueColors.insert(vertexColors[j]);
		}
		for(int j = 0; j < M; j++){
			if(vertexColors[edges[j].first] == vertexColors[edges[j].second]){
				flag = 0;
				break;
			}
		}
		if(flag) printf("%d-coloring\n", uniqueColors.size());
		else printf("No\n");
	}
	return 0;
 } 
