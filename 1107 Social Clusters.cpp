#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, visited[1000], clusterScale;
map<int, int> peopleWithHobbies[1000];

bool IsCommon(int p1, int p2)
{
	for(map<int, int>::iterator it = peopleWithHobbies[p1].begin(); it != peopleWithHobbies[p1].end(); it++){
		if(peopleWithHobbies[p2].count(it->first))
			return true;
	}
	return false;
}
void DFS(int root)
{
	visited[root] = 1;
	clusterScale++;
	for(int i = 0; i < N; i++){
		if(visited[i] == 0 && IsCommon(root, i))
			DFS(i);
	}
}

int main()
{
	scanf("%d", &N);
	int hobbyNum, hobby;
	for(int i = 0; i < N; i++){
		scanf("%d: ", &hobbyNum);
		for(int j = 0; j < hobbyNum; j++){
			scanf("%d", &hobby);
			peopleWithHobbies[i][hobby] = 1;
		}
	}
	vector<int> ans;
	for(int i = 0; i < N; i++){
		clusterScale = 0;
		if(visited[i] == 0){
			DFS(i);
			ans.push_back(clusterScale);
		}
	}
	sort(ans.begin(), ans.end(), greater<int>());
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++){
		if(i != 0)
			printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}
