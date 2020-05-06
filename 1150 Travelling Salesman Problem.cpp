#include <iostream>
#include <set>
#include <map>
using namespace std;
int roadMap[210][201];
int main()
{
	int N, M, K, n;
	scanf("%d %d", &N, &M);
	int city1, city2, dist;
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &city1, &city2, &dist);
		roadMap[city1][city2] = roadMap[city2][city1] = dist;
	}
	scanf("%d", &K);
	map<int, int> distances;
	for(int i = 1; i <= K; i++){
		set<int> cities;
		scanf("%d %d", &n, &city1);
		int start = city1;
		cities.insert(city1);
		int distance = 0, isExist = 1, isCycle = 1;  //isExist标识是否有相邻节点之间不可达，isCycle标识起点和终点是否相同 
		for(int j = 1; j < n; j++){
			scanf("%d", &city2);
			cities.insert(city2);
			distance += roadMap[city1][city2];
			if(roadMap[city1][city2] == 0) isExist = 0;
			city1 = city2;
		}
		if(start != city2) isCycle = 0;
		printf("Path %d: %s ", i, isExist ? to_string(distance).c_str() : "NA");
		if(isExist && isCycle && cities.size() == N){
			distances[distance] = i;
			if(n == N+1) printf("(TS simple cycle)\n");
			else printf("(TS cycle)\n");
		} else {
			printf("(Not a TS cycle)\n");
		}
	}
	auto it = distances.begin();
	printf("Shortest Dist(%d) = %d", it->second, it->first);
	return 0;
 } 
