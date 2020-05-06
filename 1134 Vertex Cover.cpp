#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N, M, K, Nv;
	scanf("%d %d", &N, &M);
	pair<int, int> edges[M];
	int v1, v2;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &v1, &v2);
		edges[i] = make_pair(v1, v2);
	}
	scanf("%d", &K);
	for(int i = 0; i < K; i++){
		map<int, int> vertices;
		scanf("%d", &Nv);
		for(int j = 0; j < Nv; j++){
			scanf("%d", &v1);
			vertices[v1] = 1;
		}
		bool flag = true;
		for(int j = 0; j < M; j++){
			if(vertices.count(edges[j].first) == 0 && vertices.count(edges[j].second) == 0){
				flag = false;
				break;
			}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
 } 
