#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int father[10001];

int FindFather(int node)
{
	for(; father[node] >= 0; node = father[node]);
	return node;
}
void Union(int node1, int node2)
{
	int f1 = FindFather(node1);
	int f2 = FindFather(node2);
    if(f1 != f2){
    	//不在FindFather()进行路径压缩，合并时始终把小数合并在大树上，以限制树的高度过高 
        if(father[f1] > father[f2]){
            father[f2] += father[f1];
            father[f1] = f2;
        } else {
            father[f1] += father[f2];
            father[f2] = f1;
        }
    }	
}

int main()
{
	int N, Q;
    fill(father, father+10001, -1);
	scanf("%d", &N);
	int birdNum, bird, firstBird;
	unordered_map<int, int> birdMap;
	for(int i = 0; i < N; i++){
		scanf("%d %d", &birdNum, &firstBird);
		birdMap[firstBird] = 1;
		for(int j = 1; j < birdNum; j++){
			scanf("%d", &bird);
			birdMap[bird] = 1;
			Union(bird, firstBird);
		}
	}
	unordered_map<int, int> treeMap;
	for(unordered_map<int, int>::iterator it = birdMap.begin(); it != birdMap.end(); it++){
		int f = FindFather(it->first);
		treeMap[f]++;
	}
	printf("%d %d\n", treeMap.size(), birdMap.size());
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		scanf("%d %d", &firstBird, &bird);
		printf("%s\n", (FindFather(firstBird) == FindFather(bird)) ? "Yes" : "No");
	}
	return 0;
}
