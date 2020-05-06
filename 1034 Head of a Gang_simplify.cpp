#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int memberNum, totalWeight;
map<string, vector<string>> edges;
map<string, int> visited, memberWithWeight;
string head;

void DFS(string root)
{
	visited[root] = 1;
	totalWeight += memberWithWeight[root];
	memberNum++;
	if(memberWithWeight[head] < memberWithWeight[root])
		head = root;
	for(int i = 0; i < edges[root].size(); i++){
		if(visited[edges[root][i]] == 0)
			DFS(edges[root][i]);
	}
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	string name1, name2;
	int time;
	for(int i = 0; i < N; i++){
		cin >> name1 >> name2 >> time;
		edges[name1].push_back(name2);
		edges[name2].push_back(name1);
		memberWithWeight[name1] += time;
		memberWithWeight[name2] += time;
	}
	map<string, int> headMap;
	for(map<string, int>::iterator it = memberWithWeight.begin(); it != memberWithWeight.end(); it++){
		if(visited[it->first] == 0){
			memberNum = 0;
			totalWeight = 0;
			head = it->first;
			DFS(it->first);
			if(memberNum>2 && totalWeight/2>K)
				headMap[head] = memberNum;
		}
	}
	cout << headMap.size() << endl;
	for(map<string, int>::iterator it = headMap.begin(); it != headMap.end(); it++)
		cout << it->first << " " << it->second << endl;
	return 0;
}
