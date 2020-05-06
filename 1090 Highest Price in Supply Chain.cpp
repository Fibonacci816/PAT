#include <iostream>
#include <math.h>
#include <map>
#include <vector>
using namespace std;

map<int, vector<int>> Map;  //存放某节点的所有后继节点 
int maxDeep = 0, maxRetailerNum = 0;

void DFS(int root, int deep)
{
	if(maxDeep < deep){
		maxDeep = deep;
		maxRetailerNum = 1;
	} else if(maxDeep == deep){
		maxRetailerNum++;
	}
	for(int i = 0; i < Map[root].size(); i++){
		DFS(Map[root][i], deep+1);
	}
}

int main()
{
	int N, supplier, root;
	double P, r;
	scanf("%d %lf %lf", &N, &P, &r);
	for(int i = 0; i < N; i++){
		scanf("%d", &supplier);
		if(supplier == -1){
			root = i;
		} else {
			Map[supplier].push_back(i);
		}
	}
	DFS(root, 0);
	printf("%.2lf %d", P*pow(1+r/100, maxDeep), maxRetailerNum);
	return 0;
} 
