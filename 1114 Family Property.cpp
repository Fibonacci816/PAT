#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

struct Person{
	int id, father, mother;
	int m_estate, area;
} people[10000];
struct Family{
	int memberNum;
	double aveEstate, aveArea;
};
int N, father[10000];

int FindFather(int node)
{
	for(; father[node] >= 0; node = father[node]);
	return node;
}
void Union(int node1, int node2)
{
	int f1 = FindFather(node1);
	int f2 = FindFather(node2);
	if(f1 < f2){
		father[f1] += father[f2];
		father[f2] = f1;
	} else if(f1 > f2){
		father[f2] += father[f1];
		father[f1] = f2;
	}
}
bool cmp(pair<int, Family> f1, pair<int, Family> f2)
{
	return f1.second.aveArea != f2.second.aveArea ? f1.second.aveArea > f2.second.aveArea : f1.first < f2.first;
}

int main()
{
	fill(father, father+10000, -1);
	scanf("%d", &N);
	int k, childId;
	for(int i = 0; i < N; i++){
		scanf("%d %d %d %d", &people[i].id, &people[i].father, &people[i].mother, &k);
		if(people[i].father != -1) Union(people[i].father, people[i].id);
		if(people[i].mother != -1) Union(people[i].mother, people[i].id);
		for(int j = 0; j < k; j++){
			scanf("%d", &childId);
			Union(childId, people[i].id);
		}
		scanf("%d %d", &people[i].m_estate, &people[i].area);
	}
	unordered_map<int, Family> familyMap;
	for(int i = 0; i < N; i++){
		int f = FindFather(people[i].id);
		familyMap[f].memberNum = -father[f];
		familyMap[f].aveArea += people[i].area;
		familyMap[f].aveEstate += people[i].m_estate;
	}
	for(auto it = familyMap.begin(); it != familyMap.end(); it++){
		it->second.aveEstate = it->second.aveEstate / it->second.memberNum;
		it->second.aveArea = it->second.aveArea / it->second.memberNum;
	}
	vector<pair<int, Family>> ans(familyMap.begin(), familyMap.end());
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++) {
		printf("%04d %d %.3lf %.3lf\n", ans[i].first, ans[i].second.memberNum, ans[i].second.aveEstate, ans[i].second.aveArea);
	}
	return 0;
}