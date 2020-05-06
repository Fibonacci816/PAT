#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M, K;
	scanf("%d %d", &N, &M);
	vector<int> inDegree(N+1);
	vector<int> edges[N+1];
	int v1, v2;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &v1, &v2);
		edges[v1].push_back(v2);
		inDegree[v2]++;
	}
	scanf("%d", &K);
	vector<int> ans;
	for(int i = 0; i < K; i++){
		bool isTopological = true;
		vector<int> tempInDegree = inDegree;
		for(int j = 0; j < N; j++){
			scanf("%d", &v1);
			if(tempInDegree[v1] != 0)
				isTopological = false;
			if(isTopological){
				for(int k = 0; k < edges[v1].size(); k++)
					tempInDegree[edges[v1][k]]--;
			}
		}
		if(!isTopological)
			ans.push_back(i);
	}
	for(int i = 0; i < ans.size(); i++){
		if(i !=0 ) printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
 } 
