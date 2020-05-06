#include <iostream>
#include <vector>
#include <unordered_map>
#define MAX 10000
using namespace std;

vector<int> road[MAX], path, ansPath;
unordered_map<int, int> line;
int visited[MAX], minStopNum, minTransforNum;

int CountTransforNum()
{
	int count = 0, curLine = 0;
	for(int i = 1; i < path.size(); i++) {
		if(line[path[i-1]*MAX+path[i]] != curLine) {
			count++;
			curLine = line[path[i-1]*MAX+path[i]];
		}
	} 
	return count-1;
}
void DFS(int starting, int ending)
{
	visited[starting] = 1;
	path.push_back(starting);
	if(starting == ending) {
		if(minStopNum > path.size() || (minStopNum == path.size() && minTransforNum > CountTransforNum())) {
			minStopNum = path.size();
			minTransforNum = CountTransforNum();
			ansPath = path;
		}
	} else {
		for(int i = 0; i < road[starting].size(); i++) {
			if(visited[road[starting][i]] == 0)
				DFS(road[starting][i], ending);
		}
	}
	path.pop_back();
	visited[starting] = 0;
}

int main()
{
	int N, M, K;
	scanf("%d", &N);
	int s1, s2;
	for(int i = 1; i <= N; i++) {
		scanf("%d %d", &M, &s1);
		for(int j = 1; j < M; j++) {
			scanf("%d", &s2);
			road[s1].push_back(s2);
			road[s2].push_back(s1);
			line[s1*MAX+s2] = line[s2*MAX+s1] = i;
			s1 = s2;
		}
	}
	scanf("%d", &K);
	for(int i = 1; i <= K; i++) {
		scanf("%d %d", &s1, &s2);
		minStopNum = minTransforNum = MAX;
		DFS(s1, s2);
		printf("%d\n", minStopNum-1);
		int starting = s1, curLine = line[s1*MAX+ansPath[1]];
		for(int j = 1; j < ansPath.size(); j++) {
			if(line[ansPath[j-1]*MAX+ansPath[j]] != curLine) {
				printf("Take Line#%d from %04d to %04d.\n", curLine, starting, ansPath[j-1]);
				starting = ansPath[j-1];
				curLine = line[ansPath[j-1]*MAX+ansPath[j]];
			}
		} 
		printf("Take Line#%d from %04d to %04d.\n", curLine, starting, s2);
	}
	return 0;
 } 
