#include <iostream>
#include <map>
using namespace std;

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);
	map<int, int> nodeMap;
	int vals[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &vals[i]);
		nodeMap[vals[i]] = 1;
	}
	int val1, val2;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &val1, &val2);
		if(nodeMap.count(val1) == 0 && nodeMap.count(val2) == 0){
			printf("ERROR: %d and %d are not found.\n", val1, val2);
		} else if(nodeMap.count(val1) == 0 || nodeMap.count(val2) == 0){
			printf("ERROR: %d is not found.\n", nodeMap.count(val1) ? val2 : val1);
		} else{
			for(int j = 0; j < N; j++){
				if((vals[j] > val1 && vals[j] < val2) || (vals[j] > val2 && vals[j] < val1)){
					printf("LCA of %d and %d is %d.\n", val1, val2, vals[j]);
					break;
				} else if(vals[j] == val1 || vals[j] == val2){
					printf("%d is an ancestor of %d.\n", vals[j], vals[j] == val1 ? val2 : val1);
					break; 
				}
			}
		}
	}
	return 0;
 } 
