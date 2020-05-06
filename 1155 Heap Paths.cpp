#include <iostream>
#include <vector>
using namespace std;

int N, levelOrder[1001], isMax = 1, isMin = 1;
vector<int> path;

void PrintPath(int root)
{
	path.push_back(levelOrder[root]);
	if(2*root+1 <= N){
		if(levelOrder[root] > levelOrder[2*root+1]) isMin = 0;
		if(levelOrder[root] < levelOrder[2*root+1]) isMax = 0;
		PrintPath(2*root+1);
	}
	if(2*root <= N){
		if(levelOrder[root] > levelOrder[2*root]) isMin = 0;
		if(levelOrder[root] < levelOrder[2*root]) isMax = 0;
		PrintPath(2*root);
	} else {
		for(int i = 0; i < path.size(); i++){
			if(i != 0) printf(" ");
			printf("%d", path[i]);
		}
		printf("\n");
	}
	path.pop_back();
}

int main()
{
	scanf("%d", &N);
	for(int i =1; i <= N; i++){
		scanf("%d", &levelOrder[i]);
	}
	PrintPath(1);
	printf("%s", isMax ? "Max Heap" : isMin ? "Min Heap" : "Not Heap");
	return 0;
 } 
