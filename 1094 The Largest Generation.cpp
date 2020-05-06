#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K, largestPopulationNumber = 1, correspondingLevel = 1;
vector<int> nodesWithChildren[100], nodesByLevel[100];

void DFS(int node, int level)
{
	nodesByLevel[level].push_back(node);
	if(largestPopulationNumber < nodesByLevel[level].size()){
		largestPopulationNumber = nodesByLevel[level].size();
		correspondingLevel = level;
	}
	for(int i = 0; i < nodesWithChildren[node].size(); i++){
		DFS(nodesWithChildren[node][i], level+1);
	}
}

int main()
{
	scanf("%d %d", &N, &K);
	int id, childNum, child;
	for(int i = 0; i < K; i++){
		scanf("%d %d", &id, &childNum);
		for(int j = 0; j < childNum; j++){
			scanf("%d", &child);
			nodesWithChildren[id].push_back(child);
		}
	} 
	DFS(1, 1);
	printf("%d %d", largestPopulationNumber, correspondingLevel); 
	return 0;
}
