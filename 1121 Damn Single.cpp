#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int couple[100000];

int main()
{
	fill(couple, couple+100000, -1);
	int N, M, id1, id2;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &id1, &id2);
		couple[id1] = id2;
		couple[id2] = id1;
	}
	scanf("%d", &M);
	map<int, int> partyMap;
	for(int i = 0; i < M; i++){
		scanf("%d", &id1);
		partyMap[id1] = 1;
	}
	map<int, int> singleMap;
	for(map<int, int>::iterator it = partyMap.begin(); it != partyMap.end(); it++){
		if(couple[it->first]==-1 || partyMap.count(couple[it->first])==0)
			singleMap[it->first] = 1;
	}
	printf("%d\n", singleMap.size());
	for(map<int, int>::iterator it = singleMap.begin(); it != singleMap.end(); it++){
		if(it!=singleMap.begin())
			printf(" ");
		printf("%05d", it->first);
	}
	return 0;
}
