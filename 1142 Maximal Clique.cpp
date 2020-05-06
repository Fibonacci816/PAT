#include <iostream>
#define MAX 201
using namespace std;

int edges[MAX*MAX];

int main()
{
	int Nv, Ne, M, K;
	scanf("%d %d", &Nv, &Ne);
	int v1, v2;
	for(int i = 0; i < Ne; i++){
		scanf("%d %d", &v1, &v2);
		edges[v1*MAX+v2] = edges[v2*MAX+v1] = 1;
	}
	scanf("%d", &M);
	for(int i = 0; i < M; i++){
		scanf("%d", &K);
		int vertices[K], visited[MAX] = {0};
		for(int j = 0; j < K; j++){
			scanf("%d", &vertices[j]);
			visited[vertices[j]] = 1;
		}
		bool flag = true, flag2 = true;
		for(int p = 0; p < K; p++){
			for(int q = p+1; q < K; q++){
				if(edges[vertices[p]*MAX+vertices[q]] == 0){
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}
		if(flag){
			for(int j = 1; j <= Nv; j++){
				if(visited[j] == 1) continue;
				int k = 0;
				for(; k < K; k++){
					if(edges[j*MAX+vertices[k]] == 0) break;
				}
				if(k == K){
					flag2 = false;
					break;
				}
			}
			if(flag2) printf("Yes\n");
			else printf("Not Maximal\n");
		} else {
			printf("Not a Clique\n");
		}
	}
	return 0;
 } 
