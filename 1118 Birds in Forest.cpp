#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int father[10001];

int FindFather(int node)
{
    int son = node;
	for(; father[node] != node; node = father[node]);
	//Â·¾¶Ñ¹Ëõ
    while(son != node) {
        int tmp = father[son];
        father[son] = node;
        son = tmp;
    }
	return node;
}
void Union(int node1, int node2)
{
	int f1 = FindFather(node1);
	int f2 = FindFather(node2);
	if(f1 != f2)
		father[f1] = f2;
}

int main()
{
	int N, Q;
	for(int i = 0; i <= 10000; i++)
		father[i] = i;
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
	cout << treeMap.size() << " " << birdMap.size() << endl;
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		scanf("%d %d", &firstBird, &bird);
		FindFather(firstBird) == FindFather(bird) ? cout << "Yes" << endl : cout << "No" << endl;
	}
	return 0;
}
