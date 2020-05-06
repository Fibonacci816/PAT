#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int weights[100];
vector<int> WeightsAlongPath;
vector<int> nodes[100];
int N, M, S, pathWeight = 0;
void PrintWeightsAlongPath()
{
	for(int i = 0; i < WeightsAlongPath.size(); i++){
		printf("%d", WeightsAlongPath[i]);
		if(i != WeightsAlongPath.size()-1){
			printf(" ");
		}
	}
	printf("\n");
}
void DFS(int id)
{
	WeightsAlongPath.push_back(weights[id]);
	pathWeight += weights[id];
	if(pathWeight == S && nodes[id].empty()){
		PrintWeightsAlongPath();	
	} else if(pathWeight < S){
		for(int i = 0; i < nodes[id].size(); i++){
			DFS(nodes[id][i]);
		}
	}
	WeightsAlongPath.pop_back();
	pathWeight -= weights[id];
}
bool cmp(int id1, int id2)
{
	return weights[id1] > weights[id2];
}
int main()
{
	scanf("%d %d %d", &N, &M, &S);
	for(int i = 0; i < N; i++){
		scanf("%d", &weights[i]);
	}
	int id, childNum, childId;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &id, &childNum);
		for(int j = 0; j < childNum; j++){
			scanf("%d", &childId);
			nodes[id].push_back(childId);
		}
		sort(nodes[id].begin(), nodes[id].end(), cmp);
	}
	DFS(0);
	return 0;
}
